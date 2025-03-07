#include <gui/installation_mz_param_ou_regroupement_zones_screen/Installation_MZ_param_ou_regroupement_zonesView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>


Installation_MZ_param_ou_regroupement_zonesView::Installation_MZ_param_ou_regroupement_zonesView()
{
	memset(&sConfig_IHM_old, 0, sizeof(sConfig_IHM_old));
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeConfig(&sConfig_IHM);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	// Titre
	barre_titre.recupConfig(false);
	barre_titre.connexionDistante(false);
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_PARAMETRAGE_ZONES_CENTRE).getText());
	barre_titre.titre(textAreaBuffer_Titre);

	Unicode::snprintf(textAreaBuffer_MessTitre, 40, touchgfx::TypedText(T_TEXT_MESSAGE_ATTENTION_TITRE).getText());
	message_information.titre(textAreaBuffer_MessTitre);
	Unicode::snprintf(textAreaBuffer_MessMess, 500, touchgfx::TypedText(T_TEXT_MESSAGE_V3V_REG).getText());
	message_information.message(textAreaBuffer_MessMess);
	modalWindow_information.hide();
	modalWindow_information.invalidate();

	bMessageAttentionVu = false;
	u8LigneZone = 0; //Pour définir quelle ligne et contrôle on vient de changer

	//Initialisation des variables temporaires des zones
	for (int i = 0; i<8; i++)
	{
		u2Rattachement[i] = sParamZxMZtemp[i].u2RattachementGroupe;
		u8CarteMZ[i] = sParamZxMZtemp[i].NumCarteMZ;
		u8NumVoie[i] = sParamZxMZtemp[i].NumVoieMZ;
		for (int j = 0; j<10; j++)
		{
			textAreaBuffer_NomZone[i][j] = sParamZxMZtemp[i].u8NomZone[j];
		}
		u8LigneZone = i;
		RefreshRattachement();
		RefreshNomZone();
		RefreshTypeCarte();
		RefreshVoieZone();
		RefreshZoneActive();
	}
	//Affichage/Masquage du rattachement a un Groupe
	if (sParamZxMZtemp[8].type_zone.GroupeEau.bGroupeActif || sParamZxMZtemp[9].type_zone.GroupeEau.bGroupeActif)
	{
		button_rattachement_Z1.setVisible(true);
		button_rattachement_Z2.setVisible(true);
		button_rattachement_Z3.setVisible(true);
		button_rattachement_Z4.setVisible(true);
		button_rattachement_Z5.setVisible(true);
		button_rattachement_Z6.setVisible(true);
		button_rattachement_Z7.setVisible(true);
		button_rattachement_Z8.setVisible(true);
		textArea_bouton_rattachement_Z1.setX(0);
		textArea_bouton_rattachement_Z2.setX(0);
		textArea_bouton_rattachement_Z3.setX(0);
		textArea_bouton_rattachement_Z4.setX(0);
		textArea_bouton_rattachement_Z5.setX(0);
		textArea_bouton_rattachement_Z6.setX(0);
		textArea_bouton_rattachement_Z7.setX(0);
		textArea_bouton_rattachement_Z8.setX(0);
	}
	else
	{
		button_rattachement_Z1.setVisible(false);
		button_rattachement_Z2.setVisible(false);
		button_rattachement_Z3.setVisible(false);
		button_rattachement_Z4.setVisible(false);
		button_rattachement_Z5.setVisible(false);
		button_rattachement_Z6.setVisible(false);
		button_rattachement_Z7.setVisible(false);
		button_rattachement_Z8.setVisible(false);
		textArea_bouton_rattachement_Z1.setX(26);
		textArea_bouton_rattachement_Z2.setX(26);
		textArea_bouton_rattachement_Z3.setX(26);
		textArea_bouton_rattachement_Z4.setX(26);
		textArea_bouton_rattachement_Z5.setX(26);
		textArea_bouton_rattachement_Z6.setX(26);
		textArea_bouton_rattachement_Z7.setX(26);
		textArea_bouton_rattachement_Z8.setX(26);
	}
	button_rattachement_Z1.invalidate();
	button_rattachement_Z2.invalidate();
	button_rattachement_Z3.invalidate();
	button_rattachement_Z4.invalidate();
	button_rattachement_Z5.invalidate();
	button_rattachement_Z6.invalidate();
	button_rattachement_Z7.invalidate();
	button_rattachement_Z8.invalidate();
	textArea_bouton_rattachement_Z1.invalidate();
	textArea_bouton_rattachement_Z2.invalidate();
	textArea_bouton_rattachement_Z3.invalidate();
	textArea_bouton_rattachement_Z4.invalidate();
	textArea_bouton_rattachement_Z5.invalidate();
	textArea_bouton_rattachement_Z6.invalidate();
	textArea_bouton_rattachement_Z7.invalidate();
	textArea_bouton_rattachement_Z8.invalidate();
}

void Installation_MZ_param_ou_regroupement_zonesView::RefreshRattachement()
{
	switch (u8LigneZone)
	{
		case 0:
			if (u2Rattachement[0] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ1, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z1.setWildcard(textAreaBuffer_NomGroupeZ1);
			}
			else if (u2Rattachement[0]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ1, 10);
				textArea_bouton_rattachement_Z1.setWildcard(textAreaBuffer_NomGroupeZ1);
			}
			else if (u2Rattachement[0] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ1, 10);
				textArea_bouton_rattachement_Z1.setWildcard(textAreaBuffer_NomGroupeZ1);
			}
			textArea_bouton_rattachement_Z1.invalidate();
			break;
		case 1:
			if (u2Rattachement[1] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ2, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z2.setWildcard(textAreaBuffer_NomGroupeZ2);
			}
			else if (u2Rattachement[1]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ2, 10);
				textArea_bouton_rattachement_Z2.setWildcard(textAreaBuffer_NomGroupeZ2);
			}
			else if (u2Rattachement[1] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ2, 10);
				textArea_bouton_rattachement_Z2.setWildcard(textAreaBuffer_NomGroupeZ2);
			}
			textArea_bouton_rattachement_Z2.invalidate();
			break;
		case 2:
			if (u2Rattachement[2] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ3, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z3.setWildcard(textAreaBuffer_NomGroupeZ3);
			}
			else if (u2Rattachement[2]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ3, 10);
				textArea_bouton_rattachement_Z3.setWildcard(textAreaBuffer_NomGroupeZ3);
			}
			else if (u2Rattachement[2] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ3, 10);
				textArea_bouton_rattachement_Z3.setWildcard(textAreaBuffer_NomGroupeZ3);
			}
			textArea_bouton_rattachement_Z3.invalidate();
			break;
		case 3:
			if (u2Rattachement[3] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ4, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z4.setWildcard(textAreaBuffer_NomGroupeZ4);
			}
			else if (u2Rattachement[3]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ4, 10);
				textArea_bouton_rattachement_Z4.setWildcard(textAreaBuffer_NomGroupeZ4);
			}
			else if (u2Rattachement[3] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ4, 10);
				textArea_bouton_rattachement_Z4.setWildcard(textAreaBuffer_NomGroupeZ4);
			}
			textArea_bouton_rattachement_Z4.invalidate();
			break;
		case 4:
			if (u2Rattachement[4] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ5, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z5.setWildcard(textAreaBuffer_NomGroupeZ5);
			}
			else if (u2Rattachement[4]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ5, 10);
				textArea_bouton_rattachement_Z5.setWildcard(textAreaBuffer_NomGroupeZ5);
			}
			else if (u2Rattachement[4] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ5, 10);
				textArea_bouton_rattachement_Z5.setWildcard(textAreaBuffer_NomGroupeZ5);
			}
			textArea_bouton_rattachement_Z5.invalidate();
			break;
		case 5:
			if (u2Rattachement[5] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ6, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z6.setWildcard(textAreaBuffer_NomGroupeZ6);
			}
			else if (u2Rattachement[5]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ6, 10);
				textArea_bouton_rattachement_Z6.setWildcard(textAreaBuffer_NomGroupeZ6);
			}
			else if (u2Rattachement[5] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ6, 10);
				textArea_bouton_rattachement_Z6.setWildcard(textAreaBuffer_NomGroupeZ6);
			}
			textArea_bouton_rattachement_Z6.invalidate();
			break;
		case 6:
			if (u2Rattachement[6] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ7, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z7.setWildcard(textAreaBuffer_NomGroupeZ7);
			}
			else if (u2Rattachement[6]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ7, 10);
				textArea_bouton_rattachement_Z7.setWildcard(textAreaBuffer_NomGroupeZ7);
			}
			else if (u2Rattachement[6] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ7, 10);
				textArea_bouton_rattachement_Z7.setWildcard(textAreaBuffer_NomGroupeZ7);
			}
			textArea_bouton_rattachement_Z7.invalidate();
			break;
		case 7:
			if (u2Rattachement[7] == AUTONOME)
			{
				Unicode::snprintf(textAreaBuffer_NomGroupeZ8, 10, touchgfx::TypedText(T_TEXT_AUTONOME).getText());
				textArea_bouton_rattachement_Z8.setWildcard(textAreaBuffer_NomGroupeZ8);
			}
			else if (u2Rattachement[7]== GROUPE_A)
			{
				Unicode::fromUTF8(sParamZxMZtemp[8].u8NomZone, textAreaBuffer_NomGroupeZ8, 10);
				textArea_bouton_rattachement_Z8.setWildcard(textAreaBuffer_NomGroupeZ8);
			}
			else if (u2Rattachement[7] == GROUPE_B)
			{
				Unicode::fromUTF8(sParamZxMZtemp[9].u8NomZone, textAreaBuffer_NomGroupeZ8, 10);
				textArea_bouton_rattachement_Z8.setWildcard(textAreaBuffer_NomGroupeZ8);
			}
			textArea_bouton_rattachement_Z8.invalidate();
			break;

		default:
			break;
	}
	sParamZxMZtemp[u8LigneZone].u2RattachementGroupe = u2Rattachement[u8LigneZone];
}


void Installation_MZ_param_ou_regroupement_zonesView::RefreshNomZone()
{
	switch (u8LigneZone)
	{
		case 0:
			Unicode::fromUTF8(sParamZxMZtemp[0].u8NomZone, textAreaBuffer_NomZ1, 10);
			textArea_bouton_cfg_Z1.setWildcard(textAreaBuffer_NomZ1);
			textArea_bouton_cfg_Z1.invalidate();
			break;
		case 1:
			Unicode::fromUTF8(sParamZxMZtemp[1].u8NomZone, textAreaBuffer_NomZ2, 10);
			textArea_bouton_cfg_Z2.setWildcard(textAreaBuffer_NomZ2);
			textArea_bouton_cfg_Z2.invalidate();
			break;
		case 2:
			Unicode::fromUTF8(sParamZxMZtemp[2].u8NomZone, textAreaBuffer_NomZ3, 10);
			textArea_bouton_cfg_Z3.setWildcard(textAreaBuffer_NomZ3);
			textArea_bouton_cfg_Z3.invalidate();
			break;
		case 3:
			Unicode::fromUTF8(sParamZxMZtemp[3].u8NomZone, textAreaBuffer_NomZ4, 10);
			textArea_bouton_cfg_Z4.setWildcard(textAreaBuffer_NomZ4);
			textArea_bouton_cfg_Z4.invalidate();
			break;
		case 4:
			Unicode::fromUTF8(sParamZxMZtemp[4].u8NomZone, textAreaBuffer_NomZ5, 10);
			textArea_bouton_cfg_Z5.setWildcard(textAreaBuffer_NomZ5);
			textArea_bouton_cfg_Z5.invalidate();
			break;
		case 5:
			Unicode::fromUTF8(sParamZxMZtemp[5].u8NomZone, textAreaBuffer_NomZ6, 10);
			textArea_bouton_cfg_Z6.setWildcard(textAreaBuffer_NomZ6);
			textArea_bouton_cfg_Z6.invalidate();
			break;
		case 6:
			Unicode::fromUTF8(sParamZxMZtemp[6].u8NomZone, textAreaBuffer_NomZ7, 10);
			textArea_bouton_cfg_Z7.setWildcard(textAreaBuffer_NomZ7);
			textArea_bouton_cfg_Z7.invalidate();
			break;
		case 7:
			Unicode::fromUTF8(sParamZxMZtemp[7].u8NomZone, textAreaBuffer_NomZ8, 10);
			textArea_bouton_cfg_Z8.setWildcard(textAreaBuffer_NomZ8);
			textArea_bouton_cfg_Z8.invalidate();
			break;

		default:
			break;
	}
}


void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z1()
{
	u8LigneZone = 0;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z2()
{
	u8LigneZone = 1;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z3()
{
	u8LigneZone = 2;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z4()
{
	u8LigneZone = 3;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z5()
{
	u8LigneZone = 4;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z6()
{
	u8LigneZone = 5;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z7()
{
	u8LigneZone = 6;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::Button_Rattachement_Z8()
{
	u8LigneZone = 7;
	MAJRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView::MAJRattachement()
{
	switch (u2Rattachement[u8LigneZone] & 3)
	{
		case AUTONOME:
			if (sParamZxMZtemp[8].type_zone.GroupeEau.bGroupeActif == 1)
			{
				u2Rattachement[u8LigneZone] = GROUPE_A;
			}
			else if (sParamZxMZtemp[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				u2Rattachement[u8LigneZone] = GROUPE_B;
			}
			break;
		case GROUPE_A:
			if (sParamZxMZtemp[9].type_zone.GroupeEau.bGroupeActif == 1)
			{
				u2Rattachement[u8LigneZone] = GROUPE_B;
			}
			else
			{
				u2Rattachement[u8LigneZone] = AUTONOME;
			}
			break;
		case GROUPE_B:
			u2Rattachement[u8LigneZone] = AUTONOME;
			break;
		default:
			break;
	}
	RefreshRattachement();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z1()
{
	u8LigneZone = 0;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z2()
{
	u8LigneZone = 1;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z3()
{
	u8LigneZone = 2;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z4()
{
	u8LigneZone = 3;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z5()
{
	u8LigneZone = 4;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z6()
{
	u8LigneZone = 5;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z7()
{
	u8LigneZone = 6;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Carte_MZ_Z8()
{
	u8LigneZone = 7;
	MAJType_Carte();
}

void Installation_MZ_param_ou_regroupement_zonesView::MAJType_Carte()
{
	switch (u8CarteMZ[u8LigneZone])
	{
		default:
		case CARTE_MZ1:
			u8CarteMZ[u8LigneZone] = CARTE_MZ2;
			break;
		case CARTE_MZ2:
			u8CarteMZ[u8LigneZone] = CARTE_REG;
			if (bMessageAttentionVu == false)
			{
				affichage_information();
			}
			break;
		case CARTE_REG:
			u8CarteMZ[u8LigneZone] = CARTE_MZ1;
			break;
	}
	RefreshTypeCarte();
}

void Installation_MZ_param_ou_regroupement_zonesView:: RefreshTypeCarte()
{
	switch (u8LigneZone)
	{
		case 0:
			if (u8CarteMZ[0] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z1.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[0]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z1.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[0] == CARTE_REG)
			{
				if (u8NumVoie[0] > VOIE_2)
				{
					u8NumVoie[0] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z1.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z1.invalidate();
			break;
		case 1:
			if (u8CarteMZ[1] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z2.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[1]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z2.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[1] == CARTE_REG)
			{
				if (u8NumVoie[1] > VOIE_2)
				{
					u8NumVoie[1] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z2.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z2.invalidate();
			break;
		case 2:
			if (u8CarteMZ[2] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z3.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[2]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z3.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[2] == CARTE_REG)
			{
				if (u8NumVoie[2] > VOIE_2)
				{
					u8NumVoie[2] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z3.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z3.invalidate();
			break;
		case 3:
			if (u8CarteMZ[3] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z4.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[3]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z4.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[3] == CARTE_REG)
			{
				if (u8NumVoie[3] > VOIE_2)
				{
					u8NumVoie[3] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z4.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z4.invalidate();
			break;
		case 4:
			if (u8CarteMZ[4] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z5.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[4]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z5.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[4] == CARTE_REG)
			{
				if (u8NumVoie[4] > VOIE_2)
				{
					u8NumVoie[4] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z5.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z5.invalidate();
			break;
		case 5:
			if (u8CarteMZ[5] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z6.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[5]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z6.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[5] == CARTE_REG)
			{
				if (u8NumVoie[5] > VOIE_2)
				{
					u8NumVoie[5] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z6.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z6.invalidate();
			break;
		case 6:
			if (u8CarteMZ[6] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z7.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[6]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z7.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[6] == CARTE_REG)
			{
				if (u8NumVoie[6] > VOIE_2)
				{
					u8NumVoie[6] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z7.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z7.invalidate();
			break;
		case 7:
			if (u8CarteMZ[7] == CARTE_MZ1)
			{
				textArea_bouton_carte_MZ_Z8.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ1_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[7]== CARTE_MZ2)
			{
				textArea_bouton_carte_MZ_Z8.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_MZ2_CENTRE_DEFAUT));
			}
			else if (u8CarteMZ[7] == CARTE_REG)
			{
				if (u8NumVoie[7] > VOIE_2)
				{
					u8NumVoie[7] = VOIE_2;
					RefreshVoieZone();
				}
				textArea_bouton_carte_MZ_Z8.setTypedText(touchgfx::TypedText(T_TEXT_MZ_CARTE_REG_CENTRE_DEFAUT));
			}
			textArea_bouton_carte_MZ_Z8.invalidate();
			break;
		default:
			break;
	}
	sParamZxMZtemp[u8LigneZone].NumCarteMZ = u8CarteMZ[u8LigneZone];
}

void Installation_MZ_param_ou_regroupement_zonesView:: affichage_information()
{
	modalWindow_information.show();
	modalWindow_information.invalidate();
}

void Installation_MZ_param_ou_regroupement_zonesView:: bouton_valider_information()
{
	modalWindow_information.hide();
	modalWindow_information.invalidate();
	bMessageAttentionVu = true;
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z1()
{
	u8LigneZone = 0;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z2()
{
	u8LigneZone = 1;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z3()
{
	u8LigneZone = 2;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z4()
{
	u8LigneZone = 3;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z5()
{
	u8LigneZone = 4;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z6()
{
	u8LigneZone = 5;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z7()
{
	u8LigneZone = 6;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView:: Button_Voie_Z8()
{
	u8LigneZone = 7;
	MAJVoie_Zone();
}

void Installation_MZ_param_ou_regroupement_zonesView::MAJVoie_Zone()
{
	switch (u8LigneZone)
	{
		case 0:
			if (u8CarteMZ[0] == CARTE_REG)
			{
				if (u8NumVoie[0] == VOIE_1) u8NumVoie[0] = VOIE_2;
				else u8NumVoie[0] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[0] < VOIE_4) u8NumVoie[0]++;
				else u8NumVoie[0] = VOIE_1;
			}
			break;
		case 1 :
			if (u8CarteMZ[1] == CARTE_REG)
			{
				if (u8NumVoie[1] == VOIE_1) u8NumVoie[1] = VOIE_2;
				else u8NumVoie[1] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[1] < VOIE_4) u8NumVoie[1]++;
				else u8NumVoie[1] = VOIE_1;
			}
			break;
		case 2:
			if (u8CarteMZ[2] == CARTE_REG)
			{
				if (u8NumVoie[2] == VOIE_1) u8NumVoie[2] = VOIE_2;
				else u8NumVoie[2] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[2] < VOIE_4) u8NumVoie[2]++;
				else u8NumVoie[2] = VOIE_1;
			}
			break;
		case 3 :
			if (u8CarteMZ[3] == CARTE_REG)
			{
				if (u8NumVoie[3] == VOIE_1) u8NumVoie[3] = VOIE_2;
				else u8NumVoie[3] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[3] < VOIE_4) u8NumVoie[3]++;
				else u8NumVoie[3] = VOIE_1;
			}
			break;
		case 4:
			if (u8CarteMZ[4] == CARTE_REG)
			{
				if (u8NumVoie[4] == VOIE_1) u8NumVoie[4] = VOIE_2;
				else u8NumVoie[4] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[4] < VOIE_4) u8NumVoie[4]++;
				else u8NumVoie[4] = VOIE_1;
			}
			break;
		case 5 :
			if (u8CarteMZ[5] == CARTE_REG)
			{
				if (u8NumVoie[5] == VOIE_1) u8NumVoie[5] = VOIE_2;
				else u8NumVoie[5] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[5] < VOIE_4) u8NumVoie[5]++;
				else u8NumVoie[5] = VOIE_1;
			}
			break;
		case 6:
			if (u8CarteMZ[6] == CARTE_REG)
			{
				if (u8NumVoie[6] == VOIE_1) u8NumVoie[6] = VOIE_2;
				else u8NumVoie[6] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[6] < VOIE_4) u8NumVoie[6]++;
				else u8NumVoie[6] = VOIE_1;
			}
			break;
		case 7 :
			if (u8CarteMZ[7] == CARTE_REG)
			{
				if (u8NumVoie[7] == VOIE_1) u8NumVoie[7] = VOIE_2;
				else u8NumVoie[7] = VOIE_1;
			}
			else
			{
				if (u8NumVoie[7] < VOIE_4) u8NumVoie[7]++;
				else u8NumVoie[7] = VOIE_1;
			}
			break;
		default:
			break;
	}
	RefreshVoieZone();
}


void Installation_MZ_param_ou_regroupement_zonesView:: RefreshVoieZone()
{
	switch (u8LigneZone)
	{
		case 0:
			Unicode::snprintf(textAreaBuffer_Voie_Z1, 2, "%d", u8NumVoie[0] + 1);
			textArea_sortie_voie_Z1.setWildcard(textAreaBuffer_Voie_Z1);
			textArea_sortie_voie_Z1.invalidate();
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_Voie_Z2, 2, "%d", u8NumVoie[1] + 1);
			textArea_sortie_voie_Z2.setWildcard(textAreaBuffer_Voie_Z2);
			textArea_sortie_voie_Z2.invalidate();
			break;
		case 2:
			Unicode::snprintf(textAreaBuffer_Voie_Z3, 2, "%d", u8NumVoie[2] + 1);
			textArea_sortie_voie_Z3.setWildcard(textAreaBuffer_Voie_Z3);
			textArea_sortie_voie_Z3.invalidate();
			break;
		case 3:
			Unicode::snprintf(textAreaBuffer_Voie_Z4, 2, "%d", u8NumVoie[3] + 1);
			textArea_sortie_voie_Z4.setWildcard(textAreaBuffer_Voie_Z4);
			textArea_sortie_voie_Z4.invalidate();
			break;
		case 4:
			Unicode::snprintf(textAreaBuffer_Voie_Z5, 2, "%d", u8NumVoie[4] + 1);
			textArea_sortie_voie_Z5.setWildcard(textAreaBuffer_Voie_Z5);
			textArea_sortie_voie_Z5.invalidate();
			break;
		case 5:
			Unicode::snprintf(textAreaBuffer_Voie_Z6, 2, "%d", u8NumVoie[5] + 1);
			textArea_sortie_voie_Z6.setWildcard(textAreaBuffer_Voie_Z6);
			textArea_sortie_voie_Z6.invalidate();
			break;
		case 6:
			Unicode::snprintf(textAreaBuffer_Voie_Z7, 2, "%d", u8NumVoie[6] + 1);
			textArea_sortie_voie_Z7.setWildcard(textAreaBuffer_Voie_Z7);
			textArea_sortie_voie_Z7.invalidate();
			break;
		case 7:
			Unicode::snprintf(textAreaBuffer_Voie_Z8, 2, "%d", u8NumVoie[7] + 1);
			textArea_sortie_voie_Z8.setWildcard(textAreaBuffer_Voie_Z8);
			textArea_sortie_voie_Z8.invalidate();
			break;
		default:
			break;
	}
	sParamZxMZtemp[u8LigneZone].NumVoieMZ = u8NumVoie[u8LigneZone];
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_1()
{
	sConfig_Hydrau_temp.u8NumZone = 0;
//	sParamZxMZtemp[u8NumZone]
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[0], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_2()
{
	sConfig_Hydrau_temp.u8NumZone = 1;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[1], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_3()
{
	sConfig_Hydrau_temp.u8NumZone = 2;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[2], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_4()
{
	sConfig_Hydrau_temp.u8NumZone = 3;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[3], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_5()
{
	sConfig_Hydrau_temp.u8NumZone = 4;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[4], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_6()
{
	sConfig_Hydrau_temp.u8NumZone = 5;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[5], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_7()
{
	sConfig_Hydrau_temp.u8NumZone = 6;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[6], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_param_zone_8()
{
	sConfig_Hydrau_temp.u8NumZone = 7;
	memcpy(&sConfig_Hydrau_temp.sParamZx, &sConfig_IHM.sParam_Zx[7], sizeof(S_PARAM_ZX));
}

void Installation_MZ_param_ou_regroupement_zonesView::RefreshZoneActive()
{
	switch (u8LigneZone)
	{
		case 0:
			if(sConfig_Hydrau_temp.sZones.bZone1 != 0)
			{
				image_on_off_cfg_Z1.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z1.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z1.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z1.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z1.invalidate();
			textArea_on_off_cfg_Z1.invalidate();
			break;

		case 1:
			if(sConfig_Hydrau_temp.sZones.bZone2 != 0)
			{
				image_on_off_cfg_Z2.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z2.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z2.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z2.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z2.invalidate();
			textArea_on_off_cfg_Z2.invalidate();
			break;
		case 2:
			if(sConfig_Hydrau_temp.sZones.bZone3 != 0)
			{
				image_on_off_cfg_Z3.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z3.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z3.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z3.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z3.invalidate();
			textArea_on_off_cfg_Z3.invalidate();
			break;
		case 3:
			if(sConfig_Hydrau_temp.sZones.bZone4 != 0)
			{
				image_on_off_cfg_Z4.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z4.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z4.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z4.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z4.invalidate();
			textArea_on_off_cfg_Z4.invalidate();
			break;
		case 4:
			if(sConfig_Hydrau_temp.sZones.bZone5 != 0)
			{
				image_on_off_cfg_Z5.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z5.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z5.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z5.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z5.invalidate();
			textArea_on_off_cfg_Z5.invalidate();
			break;
		case 5:
			if(sConfig_Hydrau_temp.sZones.bZone6 != 0)
			{
				image_on_off_cfg_Z6.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z6.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z6.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z6.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z6.invalidate();
			textArea_on_off_cfg_Z6.invalidate();
			break;
		case 6:
			if(sConfig_Hydrau_temp.sZones.bZone7 != 0)
			{
				image_on_off_cfg_Z7.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z7.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z7.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z7.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z7.invalidate();
			textArea_on_off_cfg_Z7.invalidate();
			break;
		case 7:
			if(sConfig_Hydrau_temp.sZones.bZone8 != 0)
			{
				image_on_off_cfg_Z8.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z8.setTypedText(touchgfx::TypedText(T_TEXT_ON_CENTRE_DEFAUT));
			}
			else
			{
				image_on_off_cfg_Z8.setBitmap(touchgfx::Bitmap(BITMAP_BOUTON_ON_OFF_BEIGE_UNCLICKED_L53XH53_ID));
				textArea_on_off_cfg_Z8.setTypedText(touchgfx::TypedText(T_TEXT_OFF_CENTRE_DEFAUT));
			}
			image_on_off_cfg_Z8.invalidate();
			textArea_on_off_cfg_Z8.invalidate();
			break;
	}
}

void Installation_MZ_param_ou_regroupement_zonesView::bouton_retour()
{
	if (bRegroupementZoneTemp)
	{
		application().gotoInstallation_MZ_parametrage_groupesScreenNoTransition();
	}
	else
	{
		application().gotoInstallation_hydrauliqueScreenNoTransition();
	}
}

void Installation_MZ_param_ou_regroupement_zonesView::setupScreen()
{
    Installation_MZ_param_ou_regroupement_zonesViewBase::setupScreen();
}

void Installation_MZ_param_ou_regroupement_zonesView::tearDownScreen()
{
    Installation_MZ_param_ou_regroupement_zonesViewBase::tearDownScreen();
}

void Installation_MZ_param_ou_regroupement_zonesView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{

}

void Installation_MZ_param_ou_regroupement_zonesView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}

	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Installation_MZ_param_ou_regroupement_zonesView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_ou_regroupement_zonesView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Installation_MZ_param_ou_regroupement_zonesView::changeDate(S_DATE *sDate)
{
	if(sDate_old.Date != sDate->Date)
	{
		// Affichage de la date
	    Unicode::snprintf(textAreaBuffer_Date, 9, "%02d/%02d/%02d", sDate->Date, sDate->Month, sDate->Year);
	    barre_titre.date(textAreaBuffer_Date);
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
	else if(sDate_old.Minutes != sDate->Minutes)
	{
		// Affichage de l'heure
	    Unicode::snprintf(textAreaBuffer_Heure, 6, "%02d:%02d", sDate->Hours, sDate->Minutes);
	    barre_titre.heure(textAreaBuffer_Heure);
	}
    barre_titre.invalidate();
	memcpy(&sDate_old, sDate, sizeof(S_DATE));
}
