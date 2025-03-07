#include <gui/renommer_screen/RenommerView.hpp>
#include <images/BitmapDatabase.hpp>
#include <touchgfx/Utils.hpp>

RenommerView::RenommerView()
{
	memset(&sStatut_PAC_old, 0, sizeof(sStatut_PAC_old));
	sDate_old.Date = 0;
	u16ErreurAffichee = 0;
	changeDate(&sDate);
	bConnexionDistance = false;
	changeErreur(u16ErreurEncours);
	changeStatutPAC(&sStatut_PAC);
	changeStatutEther(&sCycEther);
	container.setXY(u8PositionX, u8PositionY);
	u8IndexCurseur = 9;



	if (eTypeClavierAlpha == RENOMMER_ZONE_GROUPE)
	{
		Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_RENOMMER_CENTRE_DEFAUT).getText());
		Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 4, " - ");

		if (sConfig_Hydrau_temp.u8TypeRegul == REGUL_BAL_TAMPON_MULTI_ZONE)
		{
			bMultizone = true;
		}
		else
		{
			bMultizone = false;
		}


		if (bMultizone)
		{
			Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 11);
			if (sConfig_Hydrau_temp.u8NumZone == 8 || sConfig_Hydrau_temp.u8NumZone == 9)
			{
				Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, (sConfig_Hydrau_temp.u8NumZone == 8) ? " (A)" : " (B)");
			}
			else
			{
				Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)",sConfig_Hydrau_temp.u8NumZone + 1);

			}
			barre_titre.titre(textAreaBuffer_Titre);
		}
		else
		{
			Unicode::fromUTF8(sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 10);
			Unicode::snprintf(&textAreaBuffer_Titre[Unicode::strlen(textAreaBuffer_Titre)], 5, " (%d)",sConfig_Hydrau_temp.u8NumZone);
			barre_titre.titre(textAreaBuffer_Titre);
		}
	}
	else //Code Logo
	{

	}

	barre_titre.titre(textAreaBuffer_Titre);
	barre_titre.invalidate();

	if (bMultizone)
	{
		for (int i = 0; i < 10; i++)
		{
			u8NomTemp[i] = sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone[i];
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			u8NomTemp[i] = sConfig_Hydrau_temp.sParamZx.u8NomZone[i];
		}
	}
	affichageTexte();

	for (int i = 0; i < 10; i++)
	{
		if (u8NomTemp[i] == 0)
		{
			u8IndexCurseur = i;
			break;
		}
		if (i == 9)
		{
			u8IndexCurseur = i;
		}
	}
	bMajActif = false;
}

void RenommerView::bouton_maj()
{
	if (bMajActif == false)
	{

		Unicode::snprintf(textAreaBuffer_a, 2, "A");
	    textArea_a.setWildcard(textAreaBuffer_a);
	    Unicode::snprintf(textAreaBuffer_z, 2, "Z");
		textArea_z.setWildcard(textAreaBuffer_z);
		Unicode::snprintf(textAreaBuffer_e, 2, "E");
		textArea_e.setWildcard(textAreaBuffer_e);
		Unicode::snprintf(textAreaBuffer_r, 2, "R");
		textArea_r.setWildcard(textAreaBuffer_r);
		Unicode::snprintf(textAreaBuffer_t, 2, "T");
		textArea_t.setWildcard(textAreaBuffer_t);
		Unicode::snprintf(textAreaBuffer_y, 2, "Y");
		textArea_y.setWildcard(textAreaBuffer_y);
		Unicode::snprintf(textAreaBuffer_u, 2, "U");
		textArea_u.setWildcard(textAreaBuffer_u);
		Unicode::snprintf(textAreaBuffer_i, 2, "I");
		textArea_i.setWildcard(textAreaBuffer_i);
		Unicode::snprintf(textAreaBuffer_o, 2, "O");
		textArea_o.setWildcard(textAreaBuffer_o);
		Unicode::snprintf(textAreaBuffer_p, 2, "P");
		textArea_p.setWildcard(textAreaBuffer_p);

		Unicode::snprintf(textAreaBuffer_q, 2, "Q");
		textArea_q.setWildcard(textAreaBuffer_q);
		Unicode::snprintf(textAreaBuffer_s, 2, "S");
		textArea_s.setWildcard(textAreaBuffer_s);
		Unicode::snprintf(textAreaBuffer_d, 2, "D");
		textArea_d.setWildcard(textAreaBuffer_d);
		Unicode::snprintf(textAreaBuffer_f, 2, "F");
		textArea_f.setWildcard(textAreaBuffer_f);
		Unicode::snprintf(textAreaBuffer_g, 2, "G");
		textArea_g.setWildcard(textAreaBuffer_g);
		Unicode::snprintf(textAreaBuffer_h, 2, "H");
		textArea_h.setWildcard(textAreaBuffer_h);
		Unicode::snprintf(textAreaBuffer_j, 2, "J");
		textArea_j.setWildcard(textAreaBuffer_j);
		Unicode::snprintf(textAreaBuffer_k, 2, "K");
		textArea_k.setWildcard(textAreaBuffer_k);
		Unicode::snprintf(textAreaBuffer_l, 2, "L");
		textArea_l.setWildcard(textAreaBuffer_l);
		Unicode::snprintf(textAreaBuffer_m, 2, "M");
		textArea_m.setWildcard(textAreaBuffer_m);

		Unicode::snprintf(textAreaBuffer_w, 2, "W");
		textArea_w.setWildcard(textAreaBuffer_w);
		Unicode::snprintf(textAreaBuffer_x, 2, "X");
		textArea_x.setWildcard(textAreaBuffer_x);
		Unicode::snprintf(textAreaBuffer_c, 2, "C");
		textArea_c.setWildcard(textAreaBuffer_c);
		Unicode::snprintf(textAreaBuffer_v, 2, "V");
		textArea_v.setWildcard(textAreaBuffer_v);
		Unicode::snprintf(textAreaBuffer_b, 2, "B");
		textArea_b.setWildcard(textAreaBuffer_b);
		Unicode::snprintf(textAreaBuffer_n, 2, "N");
		textArea_n.setWildcard(textAreaBuffer_n);
		bMajActif = true;
	}
	else
	{
		Unicode::snprintf(textAreaBuffer_a, 2, "a");
		textArea_a.setWildcard(textAreaBuffer_a);
		Unicode::snprintf(textAreaBuffer_z, 2, "z");
		textArea_z.setWildcard(textAreaBuffer_z);
		Unicode::snprintf(textAreaBuffer_e, 2, "e");
		textArea_e.setWildcard(textAreaBuffer_e);
		Unicode::snprintf(textAreaBuffer_r, 2, "r");
		textArea_r.setWildcard(textAreaBuffer_r);
		Unicode::snprintf(textAreaBuffer_t, 2, "t");
		textArea_t.setWildcard(textAreaBuffer_t);
		Unicode::snprintf(textAreaBuffer_y, 2, "y");
		textArea_y.setWildcard(textAreaBuffer_y);
		Unicode::snprintf(textAreaBuffer_u, 2, "u");
		textArea_u.setWildcard(textAreaBuffer_u);
		Unicode::snprintf(textAreaBuffer_i, 2, "i");
		textArea_i.setWildcard(textAreaBuffer_i);
		Unicode::snprintf(textAreaBuffer_o, 2, "o");
		textArea_o.setWildcard(textAreaBuffer_o);
		Unicode::snprintf(textAreaBuffer_p, 2, "p");
		textArea_p.setWildcard(textAreaBuffer_p);

		Unicode::snprintf(textAreaBuffer_q, 2, "q");
		textArea_q.setWildcard(textAreaBuffer_q);
		Unicode::snprintf(textAreaBuffer_s, 2, "s");
		textArea_s.setWildcard(textAreaBuffer_s);
		Unicode::snprintf(textAreaBuffer_d, 2, "d");
		textArea_d.setWildcard(textAreaBuffer_d);
		Unicode::snprintf(textAreaBuffer_f, 2, "f");
		textArea_f.setWildcard(textAreaBuffer_f);
		Unicode::snprintf(textAreaBuffer_g, 2, "g");
		textArea_g.setWildcard(textAreaBuffer_g);
		Unicode::snprintf(textAreaBuffer_h, 2, "h");
		textArea_h.setWildcard(textAreaBuffer_h);
		Unicode::snprintf(textAreaBuffer_j, 2, "j");
		textArea_j.setWildcard(textAreaBuffer_j);
		Unicode::snprintf(textAreaBuffer_k, 2, "k");
		textArea_k.setWildcard(textAreaBuffer_k);
		Unicode::snprintf(textAreaBuffer_l, 2, "l");
		textArea_l.setWildcard(textAreaBuffer_l);
		Unicode::snprintf(textAreaBuffer_m, 2, "m");
		textArea_m.setWildcard(textAreaBuffer_m);

		Unicode::snprintf(textAreaBuffer_w, 2, "w");
		textArea_w.setWildcard(textAreaBuffer_w);
		Unicode::snprintf(textAreaBuffer_x, 2, "x");
		textArea_x.setWildcard(textAreaBuffer_x);
		Unicode::snprintf(textAreaBuffer_c, 2, "c");
		textArea_c.setWildcard(textAreaBuffer_c);
		Unicode::snprintf(textAreaBuffer_v, 2, "v");
		textArea_v.setWildcard(textAreaBuffer_v);
		Unicode::snprintf(textAreaBuffer_b, 2, "b");
		textArea_b.setWildcard(textAreaBuffer_b);
		Unicode::snprintf(textAreaBuffer_n, 2, "n");
		textArea_n.setWildcard(textAreaBuffer_n);
		bMajActif = false;
	}
	textArea_a.invalidate();
	textArea_z.invalidate();
	textArea_e.invalidate();
	textArea_r.invalidate();
	textArea_t.invalidate();
	textArea_y.invalidate();
	textArea_u.invalidate();
	textArea_i.invalidate();
	textArea_o.invalidate();
	textArea_p.invalidate();
	textArea_q.invalidate();
	textArea_s.invalidate();
	textArea_d.invalidate();
	textArea_f.invalidate();
	textArea_g.invalidate();
	textArea_h.invalidate();
	textArea_j.invalidate();
	textArea_k.invalidate();
	textArea_l.invalidate();
	textArea_m.invalidate();
	textArea_w.invalidate();
	textArea_x.invalidate();
	textArea_c.invalidate();
	textArea_v.invalidate();
	textArea_b.invalidate();
	textArea_n.invalidate();
}

void RenommerView::bouton_retour()
{
	if (bMultizone)
	{
//		u8NomTemp[i]
		if (sConfig_Hydrau_temp.u8NumZone == 8 || sConfig_Hydrau_temp.u8NumZone == 9)
		{
			application().gotoInstallation_MZ_param_complementaires_groupeScreenNoTransition();
		}
		else
		{
			application().gotoInstallation_MZ_config_zoneScreenNoTransition();
		}
	}
	else
	{
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}

void RenommerView::bouton_valider()
{
	if (bMultizone)
	{
		memcpy(&sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].u8NomZone, &u8NomTemp, sizeof(u8NomTemp));
		//memcpy(&sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone], &sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone], sizeof(S_PARAM_ZX));
		if (sConfig_Hydrau_temp.u8NumZone == 8 || sConfig_Hydrau_temp.u8NumZone == 9)
		{
			if (sParamZxMZtemp[sConfig_Hydrau_temp.u8NumZone].TypeEmmetteur == SOUS_STATION)
			{
				application().gotoInstallation_MZ_config_groupeScreenNoTransition();
			}
			else
			{
				application().gotoInstallation_MZ_param_complementaires_groupeScreenNoTransition();
			}
		}
		else
		{
			application().gotoInstallation_MZ_config_zoneScreenNoTransition();
		}
	}
	else
	{
		memcpy(&sConfig_Hydrau_temp.sParamZx.u8NomZone, &u8NomTemp, sizeof(u8NomTemp));
		//memcpy(&sConfig_IHM.sParam_Zx[sConfig_Hydrau_temp.u8NumZone], &sConfig_Hydrau_temp.sParamZx, sizeof(S_PARAM_ZX));
		//presenter->c_install_zx(sConfig_Hydrau_temp.u8NumZone);
		application().gotoInstallation_hydraulique_config_zoneScreenNoTransition();
	}
}


void RenommerView::bouton_1()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '1';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_2()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '2';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_3()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '3';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_4()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '4';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_5()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '5';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_6()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '6';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_7()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '7';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_8()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '8';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_9()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '9';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_0()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '0';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_point()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '.';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton__()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '_';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_aro()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '@';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_tiret()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = '-';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_space()
{
	if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		u8Caractere = ' ';
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_supprimer()
{
	if (u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur]!= 0)
	{
		u8NomTemp[u8IndexCurseur] = 0;
		affichageTexte();
	}
	else if (u8IndexCurseur > 0)
	{
		u8NomTemp[u8IndexCurseur - 1] = 0;
		u8IndexCurseur--;
		affichageTexte();
	}
}

void RenommerView::bouton_a()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'A';}
		else {u8Caractere = 'a';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_b()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'B';}
		else {u8Caractere = 'b';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_c()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'C';}
		else {u8Caractere = 'c';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_d()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'D';}
		else {u8Caractere = 'd';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_e()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'E';}
		else {u8Caractere = 'e';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_f()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'F';}
		else {u8Caractere = 'f';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_g()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'G';}
		else {u8Caractere = 'g';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_h()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'H';}
		else {u8Caractere = 'h';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_i()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'I';}
		else {u8Caractere = 'i';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_j()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'J';}
		else {u8Caractere = 'j';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_k()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'K';}
		else {u8Caractere = 'k';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_l()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'L';}
		else {u8Caractere = 'l';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_m()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'M';}
		else {u8Caractere = 'm';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_n()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'N';}
		else {u8Caractere = 'n';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_o()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'O';}
		else {u8Caractere = 'o';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_p()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'P';}
		else {u8Caractere = 'p';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_q()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'Q';}
		else {u8Caractere = 'q';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_r()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'R';}
		else {u8Caractere = 'r';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_s()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'S';}
		else {u8Caractere = 's';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_t()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'T';}
		else {u8Caractere = 't';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_u()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'U';}
		else {u8Caractere = 'u';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_v()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'V';}
		else {u8Caractere = 'v';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_w()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'W';}
		else {u8Caractere = 'w';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_x()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'X';}
		else {u8Caractere = 'x';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_y()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'Y';}
		else {u8Caractere = 'y';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::bouton_z()
{
    if ((u8IndexCurseur < 10) && (!(u8IndexCurseur == 9 && u8NomTemp[u8IndexCurseur] != 0)))
	{
		if (bMajActif){u8Caractere = 'Z';}
		else {u8Caractere = 'z';}
		u8NomTemp[u8IndexCurseur] = u8Caractere;
		if (u8IndexCurseur < 9) u8IndexCurseur++;
		affichageTexte();
	}
}

void RenommerView::affichageTexte()
{
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Nom_tmp[11];

	int longueur = 10;

	for(int i = 0; i < 10; i++)
	{
		textAreaBuffer_Nom_tmp[i] =  u8NomTemp[i];
	}
	textAreaBuffer_Nom_tmp[10] = 0;
	Unicode::strncpy(textAreaBuffer_Nom, textAreaBuffer_Nom_tmp, longueur+1 );
	textArea_value.setWildcard(textAreaBuffer_Nom);
	textArea_value.invalidate();
}

void RenommerView::setupScreen()
{
    RenommerViewBase::setupScreen();
}

void RenommerView::tearDownScreen()
{
    RenommerViewBase::tearDownScreen();
}

void RenommerView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void RenommerView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
}

void RenommerView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void RenommerView::changeDate(S_DATE *sDate)
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
