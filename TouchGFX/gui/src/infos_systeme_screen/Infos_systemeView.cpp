#include <gui/infos_systeme_screen/Infos_systemeView.hpp>

Infos_systemeView::Infos_systemeView()
{
	u32IP = 0xffffffff;
	u32WIP = 0xffffffff;
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
	Unicode::snprintf(textAreaBuffer_Titre, 40, touchgfx::TypedText(T_TEXT_INFOS_SYSTEME_CENTRE_DEFAUT).getText());
	barre_titre.titre(textAreaBuffer_Titre);
}

void Infos_systemeView::setupScreen()
{
    Infos_systemeViewBase::setupScreen();
}

void Infos_systemeView::tearDownScreen()
{
    Infos_systemeViewBase::tearDownScreen();
}

void Infos_systemeView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	uint16_t u16TmpBuffer[2];
	// Type gamme
	if(sConfig_IHM_old.sModele_PAC.u8ModelePAC != sConfig_IHM->sModele_PAC.u8ModelePAC)
	{
		switch(sConfig_IHM->sModele_PAC.u8ModelePAC)
		{
			case AJPAC_III:
				if(memcmp(sConfig_IHM->sInstall_PAC.CodeLogoClient, "CLIMDIFF3597", 12) == 0)
				{
					Unicode::snprintf(textAreaBuffer_Gamme, 13, "alpCIMES III");
				}
				else Unicode::snprintf(textAreaBuffer_Gamme, 10, "AJPAC III");
				textArea_capteur_val.setVisible(false);
				textArea_type_capteur.setVisible(false);
				break;
			case BAGUIO_ZURAN_IV:
				if(memcmp(sConfig_IHM->sInstall_PAC.CodeLogoClient, "CLIMDIFF3597", 12) == 0)
				{
					Unicode::snprintf(textAreaBuffer_Gamme, 20, "alpAZUR / alpVAL IV");
				}
				else Unicode::snprintf(textAreaBuffer_Gamme, 18, "ZURAN / BAGUIO IV");
				textArea_capteur_val.setVisible(false);
				textArea_type_capteur.setVisible(false);
				break;
			case TIMAX_III:
				if(memcmp(sConfig_IHM->sInstall_PAC.CodeLogoClient, "CLIMDIFF3597", 12) == 0)
				{
					Unicode::snprintf(textAreaBuffer_Gamme, 12, "alpMVAL III");
				}
				else Unicode::snprintf(textAreaBuffer_Gamme, 9, "TIMAX III");
				textArea_capteur_val.setVisible(false);
				textArea_type_capteur.setVisible(false);
				break;
			case GEOTWIN_IV:
				if(memcmp(sConfig_IHM->sInstall_PAC.CodeLogoClient, "CLIMDIFF3597", 12) == 0)
				{
					Unicode::snprintf(textAreaBuffer_Gamme, 10, "alpGEO IV");
				}
				else Unicode::snprintf(textAreaBuffer_Gamme, 11, "GEOTWIN IV");
				textArea_capteur_val.setVisible(true);
				textArea_type_capteur.setVisible(true);
				break;
			case CAIROX:
				Unicode::snprintf(textAreaBuffer_Gamme, 9, "CAIROX");
				textArea_capteur_val.setVisible(false);
				textArea_type_capteur.setVisible(false);
				break;
			case PHOENIX:
				Unicode::snprintf(textAreaBuffer_Gamme, 9, "PHOENIX");
				textArea_capteur_val.setVisible(false);
				textArea_type_capteur.setVisible(false);
				break;
			case ARKTEA:
				Unicode::snprintf(textAreaBuffer_Gamme, 7, "ARKTEA");
				textArea_capteur_val.setVisible(true);
				textArea_type_capteur.setVisible(true);
				break;
			case INVERTERRA:
				Unicode::snprintf(textAreaBuffer_Gamme, 9, "INVERTERRA");
				textArea_capteur_val.setVisible(true);
				textArea_type_capteur.setVisible(true);
				break;
		}
		textArea_gamme_val.setWildcard(textAreaBuffer_Gamme);
		textArea_gamme_val.invalidate();
		textArea_capteur_val.invalidate();
		textArea_type_capteur.invalidate();
	}
	// Modele PAC
	if(memcmp(&sConfig_IHM_old.sModele_PAC, &sConfig_IHM->sModele_PAC, sizeof(sConfig_IHM->sModele_PAC)))
	{
		switch(sConfig_IHM->sModele_PAC.u8ModelePAC)
		{
			case AJPAC_III:
				Unicode::snprintf(textAreaBuffer_Modele, 6, "%d Kw", sConfig_IHM->sModele_PAC.u8PwPac);
				if(sConfig_IHM->sModele_PAC.bSupply)
				{
					Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
				}
				else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
				break;
			case BAGUIO_ZURAN_IV:
				switch(sConfig_IHM->sModele_PAC.u3SousTypePAC)
				{
					case SOUS_TYPE_BAGUIO_PP:
						Unicode::snprintf(textAreaBuffer_Modele, 20, "SUZ-S(H)WM40/75 - 1~");
						break;
					case SOUS_TYPE_BAGUIO:
						switch(sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 2:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW45");
								break;
							case 9:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "RP35");
								break;
							case 10:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW50");
								break;
							case 11:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "RP60");
								break;
							case 14:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW75");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SWM80");
								break;
							case 20:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW100");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SWM100");
								break;
							case 25:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW120");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "RP140");
								break;
							case 40:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW160");
								break;
							case 50:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SW200");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx ");
								break;
						}
						if(sConfig_IHM->sModele_PAC.bSupply)
						{
							Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
						}
						else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
						break;
					case SOUS_TYPE_ZURAN:
						switch(sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 14:
								if (sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SHW80");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SHWM80");
								break;
							case 20:
								if (sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SHW112");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SHWM100");
								break;
							case 25:
								if (sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SHW140");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SHWM120");
								break;
							case 28:
								if (sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "140");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUD-SHWM140");
								break;
							case 40:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-SHW230");
								break;
							case 50:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "250");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx");
								break;
						}
						if(sConfig_IHM->sModele_PAC.bSupply)
						{
							Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
						}
						else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
						break;
					case SOUS_TYPE_BAGUIO_PUZ:
						switch(sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 14:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SWM80");
								break;
							case 20:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SWM100");
								break;
							case 25:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx");
								break;
						}
						if(sConfig_IHM->sModele_PAC.bSupply)
						{
							Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
						}
						else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
						break;
					case SOUS_TYPE_ZURAN_PUZ:
						switch(sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 14:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SHWM80");
								break;
							case 20:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SHWM100");
								break;
							case 25:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SHWM120");
								break;
							case 28:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-SHWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx");
								break;
						}
						if(sConfig_IHM->sModele_PAC.bSupply)
						{
							Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
						}
						else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
						break;
				}
				break;
			case TIMAX_III:
				switch(sConfig_IHM->sModele_PAC.u3SousTypePAC)
				{
					case SOUS_TYPE_BAGUIO:
						switch(sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 10:
							case 9:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-W50");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-WM50");
								break;
							case 11:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-WM60");
								break;
							case 14:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-W85");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-WM85");
								break;
							case 20:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-W112");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-WM112");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx ");
								break;
						}
						break;
					default:
						switch (sConfig_IHM->sModele_PAC.u8PwPac)
						{
							case 20:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-HW112");
								break;
							case 25:
								if(sConfig_IHM->sModele_PAC.Gaz_C1 == GAZ_R410)
								{
									Unicode::snprintf(textAreaBuffer_Modele, 11, "PUHZ-HW140");
								}
								else Unicode::snprintf(textAreaBuffer_Modele, 11, "PUZ-HWM140");
								break;
							default:
								Unicode::snprintf(textAreaBuffer_Modele, 11, "xxx");
								break;
						}
						break;
				}
				if(sConfig_IHM->sModele_PAC.bSupply)
				{
					Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 3~");
				}
				else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 6, " - 1~");
				break;
			case GEOTWIN_IV:
				if(sConfig_IHM->sModele_PAC.nbCompresseur == 0)
				{
					Unicode::snprintf(textAreaBuffer_Modele, 8, "Mo %d ", sConfig_IHM->sModele_PAC.u8PwPac);
				} else Unicode::snprintf(textAreaBuffer_Modele, 8, "Bi %d ",sConfig_IHM->sModele_PAC.u8PwPac);
				if(sConfig_IHM->sModele_PAC.bSupply)
				{
					Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 3, "3~");
				}
				else Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 3, "1~");
				if(sConfig_IHM->sModele_PAC.bDemarreurProgressif != 0)
				{
					Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 3, " D");
				}
				if(sConfig_IHM->sModele_PAC.bReversible != 0)
				{
					Unicode::snprintf(&textAreaBuffer_Modele[Unicode::strlen(textAreaBuffer_Modele)], 3, " R");
				}
				break;
			case CAIROX:
				Unicode::snprintf(textAreaBuffer_Modele, 9, "CAIROX");
				break;
			case PHOENIX:
				Unicode::snprintf(textAreaBuffer_Modele, 9, "PHOENIX");
				break;
			case ARKTEA:
				Unicode::snprintf(textAreaBuffer_Modele, 11, "%d Kw - 1~", sConfig_IHM->sModele_PAC.u8PwPac);
				break;
			case INVERTERRA:
				Unicode::snprintf(textAreaBuffer_Modele, 15, "HT - %dKW - ~%c", sConfig_IHM->sModele_PAC.u8PwPac, sConfig_IHM->sModele_PAC.bSupply == 0 ? '1' : '3');
				break;
		}
		textArea_model.setWildcard(textAreaBuffer_Modele);
		textArea_model.invalidate();
		if(sConfig_IHM->sModele_PAC.nbCompresseur == 0)
		{
			textArea_fluide_c1.setTypedText(T_TEXT_CHOIX_FLUIDE_C1_GAUCHE_DEFAUT);
		}
		else textArea_fluide_c1.setTypedText(T_TEXT_CHOIX_FLUIDE_C1_C2_GAUCHE_DEFAUT);
		textArea_fluide_c1.invalidate();
	}
	// Type emetteur
	if((sConfig_IHM_old.sParam_PAC.TypeRegul != sConfig_IHM->sParam_PAC.TypeRegul) || (sConfig_IHM_old.sOption_PAC.sZone.bZone1 != sConfig_IHM->sOption_PAC.sZone.bZone1) || (sConfig_IHM_old.sOption_PAC.sZone.bZone2 != sConfig_IHM->sOption_PAC.sZone.bZone2))
	{
		switch(sConfig_IHM->sParam_PAC.TypeRegul)
		{
			case REGUL_DIRECTE:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_DIRECTE_CENTRE_DEFAUT));
				break;
			case REGUL_BCP_INTERNE:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_BCP_INTERNE_CENTRE_DEFAUT));
				break;
			case REGUL_BAL_TAMPON_2_ZONES:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_2_ZONES_CENTRE_DEFAUT));
				break;
			case REGUL_BAL_TAMPON_MULTI_ZONE:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_MULTI_ZONES_CENTRE_DEFAUT));
				break;
			case REGUL_EXTERNE:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_EXTERNE_CENTRE_DEFAUT));
				break;
			case REGUL_ESCLAVE:
				textArea_regul.setTypedText(touchgfx::TypedText(T_TEXT_REGUL_ESCLAVE_CENTRE_DEFAUT));
				break;
		}
		textArea_regul.invalidate();

		if(sConfig_IHM->sParam_PAC.TypeRegul >= REGUL_BAL_TAMPON_MULTI_ZONE)
		{
			textArea_emetteur_zone_1.setVisible(false);
			textArea_emetteur_zone_2.setVisible(false);
			textArea_emet_1.setVisible(false);
			textArea_emet_2.setVisible(false);
		}
		else
		{
			if(sConfig_IHM->sOption_PAC.sZone.bZone1)
			{
				textArea_emetteur_zone_1.setVisible(true);
				textArea_emet_1.setVisible(true);
			}
			else
			{
				textArea_emetteur_zone_1.setVisible(false);
				textArea_emet_1.setVisible(false);
			}
			textArea_emetteur_zone_1.invalidate();
			textArea_emet_1.invalidate();

			if(sConfig_IHM->sOption_PAC.sZone.bZone2)
			{
				textArea_emetteur_zone_2.setVisible(true);
				textArea_emet_2.setVisible(true);
			}
			else
			{
				textArea_emetteur_zone_2.setVisible(false);
				textArea_emet_2.setVisible(false);
			}
			textArea_emetteur_zone_2.invalidate();
			textArea_emet_2.invalidate();
		}
	}

	if(sConfig_IHM_old.sParam_Zx[0].TypeEmmetteur != sConfig_IHM->sParam_Zx[0].TypeEmmetteur)
	{
		switch(sConfig_IHM->sParam_Zx[0].TypeEmmetteur)
		{
			case PLANCHER:
				textArea_emet_1.setTypedText(touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT));
				break;
			case RADIATEUR:
				textArea_emet_1.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
				break;
			case VENTILO:
				textArea_emet_1.setTypedText(touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT));
				break;
		}
		textArea_emetteur_zone_1.invalidate();
		textArea_emet_1.invalidate();
	}

	if(sConfig_IHM_old.sParam_Zx[1].TypeEmmetteur != sConfig_IHM->sParam_Zx[1].TypeEmmetteur)
	{
		switch(sConfig_IHM->sParam_Zx[1].TypeEmmetteur)
		{
			case PLANCHER:
				textArea_emet_2.setTypedText(touchgfx::TypedText(T_TEXT_PLANCHER_CENTRE_DEFAUT));
				break;
			case RADIATEUR:
				textArea_emet_2.setTypedText(touchgfx::TypedText(T_TEXT_RADIATEUR_CENTRE_DEFAUT));
				break;
			case VENTILO:
				textArea_emet_2.setTypedText(touchgfx::TypedText(T_TEXT_VENTILO_CENTRE_DEFAUT));
				break;
		}
		textArea_emetteur_zone_2.invalidate();
		textArea_emet_2.invalidate();
	}
	// Mise en service
	if(memcmp(&sConfig_IHM->sInstall_PAC.sDateMiseEnService, &sConfig_IHM_old.sInstall_PAC.sDateMiseEnService, sizeof(sConfig_IHM_old.sInstall_PAC.sDateMiseEnService)))
	{
		Unicode::snprintf(textAreaBuffer_MiseService, 9, "%02d/%02d/%02d", sConfig_IHM->sInstall_PAC.sDateMiseEnService.Date, sConfig_IHM->sInstall_PAC.sDateMiseEnService.Month, sConfig_IHM->sInstall_PAC.sDateMiseEnService.Year);
		textArea_mise_serv.setWildcard(textAreaBuffer_MiseService);
		textArea_mise_serv.invalidate();
	}
	// Nuémro de série
	if(memcmp(&sConfig_IHM->sInstall_PAC.auc8Serial_Number_PAC, &sConfig_IHM_old.sInstall_PAC.auc8Serial_Number_PAC, sizeof(sConfig_IHM_old.sInstall_PAC.auc8Serial_Number_PAC)))
	{
		Unicode::fromUTF8(sConfig_IHM->sInstall_PAC.auc8Serial_Number_PAC, textAreaBuffer_NumeroSerie, 12);
		textArea_numserie.setWildcard(textAreaBuffer_NumeroSerie);
		textArea_numserie.invalidate();
	}
	// Type capteur
	if(sConfig_IHM->sModele_PAC.u8ModelePAC == GEOTWIN_IV && sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeDeCaptage != sConfig_IHM_old.sConfig_PAC.ConfigGeo.eTypeDeCaptage)
	{
		switch(sConfig_IHM->sConfig_PAC.ConfigGeo.eTypeDeCaptage)
		{
			case E_TYPE_CAPTAGE_CAPTEUR:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
				break;
			case E_TYPE_CAPTAGE_NAPPE_DIRECTE:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_DIRECTE_CENTRE_DEFAUT));
				break;
			case E_TYPE_CAPTAGE_NAPPE_BARRAGE:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
				break;
		}
		textArea_capteur_val.invalidate();
	}
	else if(sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA && sConfig_IHM->sConfig_PAC.ConfigGeoInverter.eTypeDeCaptage != sConfig_IHM_old.sConfig_PAC.ConfigGeoInverter.eTypeDeCaptage)
	{
		switch(sConfig_IHM->sConfig_PAC.ConfigGeoInverter.eTypeDeCaptage)
		{
			case E_TYPE_CAPTAGE_CAPTEUR:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_CAPTEUR_CENTRE_DEFAUT));
				break;
			case E_TYPE_CAPTAGE_NAPPE_DIRECTE:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_DIRECTE_CENTRE_DEFAUT));
				break;
			case E_TYPE_CAPTAGE_NAPPE_BARRAGE:
			    textArea_capteur_val.setTypedText(touchgfx::TypedText(T_TEXT_VALEUR_TYPE_CAPTEUR_NAPPE_BARRAGE_CENTRE_DEFAUT));
				break;
		}
		textArea_capteur_val.invalidate();
	}
	// Communication Modbus
	if(memcmp(&sConfig_IHM->sParamModbus, &sConfig_IHM_old.sParamModbus, sizeof(sConfig_IHM->sParamModbus)))
	{
		switch(sConfig_IHM->sParamModbus.speed)
		{
			case 0:
				u16TmpBuffer[0] = 4800;
				break;
			case 1:
				u16TmpBuffer[0] = 9600;
				break;
			case 2:
				u16TmpBuffer[0] = 19200;
				break;
			case 3:
				u16TmpBuffer[0] = 38400;
				break;
		}
		switch(sConfig_IHM->sParamModbus.u2Parite)
		{
			default:
				u16TmpBuffer[1] = 'n';
				break;
			case 1:
				u16TmpBuffer[1] = 'e';
				break;
			case 2:
				u16TmpBuffer[1] = 'o';
				break;
		}
		Unicode::snprintf(textAreaBuffer_Modbus, 15, "%d %d 8,%d,%c", sConfig_IHM->sParamModbus.adresse, u16TmpBuffer[0], sConfig_IHM->sParamModbus.u1NbStopBit + 1, u16TmpBuffer[1]);
		textArea_mod.setWildcard(textAreaBuffer_Modbus);
		textArea_mod.invalidate();
	}
	// Type de fluides
	if((sConfig_IHM->sModele_PAC.Gaz_C1 != sConfig_IHM_old.sModele_PAC.Gaz_C1) || (sConfig_IHM->sModele_PAC.Gaz_C2 != sConfig_IHM_old.sModele_PAC.Gaz_C2))
	{
		switch(sConfig_IHM->sModele_PAC.Gaz_C1)
		{
			case GAZ_NONE:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "NA");
				break;
			case GAZ_R410:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R410A");
				break;
			case GAZ_R134:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R134a");
				break;
			case GAZ_R407:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R407C");
				break;
			case GAZ_R32:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R32");
				break;
			case GAZ_HELIUM:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "He");
				break;
			case GAZ_R513:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R513");
				break;
			case GAZ_R454C:
				Unicode::snprintf(textAreaBuffer_Fluide, 6, "R454C");
				break;
		}
		if(sConfig_IHM->sModele_PAC.nbCompresseur != 0)
		{
			switch(sConfig_IHM->sModele_PAC.Gaz_C2)
			{
				case GAZ_NONE:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / NA");
					break;
				case GAZ_R410:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R410A");
					break;
				case GAZ_R134:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R134a");
					break;
				case GAZ_R407:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R407C");
					break;
				case GAZ_R32:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R32");
					break;
				case GAZ_HELIUM:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / He");
					break;
				case GAZ_R513:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R513");
					break;
				case GAZ_R454C:
					Unicode::snprintf(&textAreaBuffer_Fluide[Unicode::strlen(textAreaBuffer_Fluide)], 9, " / R454C");
					break;
			}
		}
		textArea_fluide.setWildcard(textAreaBuffer_Fluide);
		textArea_fluide.invalidate();
	}
	// Soft ETHER
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_ETH, &sConfig_IHM_old.sParamSoft.Soft_ETH, sizeof(sConfig_IHM_old.sParamSoft.Soft_ETH)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_ETH, textAreaBuffer_SoftETHER, 7);
		textArea_ether.setWildcard(textAreaBuffer_SoftETHER);
		textArea_ether.invalidate();
	}
	// Soft REG
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_REG, &sConfig_IHM_old.sParamSoft.Soft_REG, sizeof(sConfig_IHM_old.sParamSoft.Soft_REG)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_REG, textAreaBuffer_SoftREG, 7);
		textArea_reg.setWildcard(textAreaBuffer_SoftREG);
		textArea_reg.invalidate();
	}
	// Soft FRIGO
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_FRI, &sConfig_IHM_old.sParamSoft.Soft_FRI, sizeof(sConfig_IHM_old.sParamSoft.Soft_FRI)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_FRI, textAreaBuffer_SoftFRIGO, 7);
		textArea_frigo.setWildcard(textAreaBuffer_SoftFRIGO);
		textArea_frigo.invalidate();
	}
	// Soft FAN
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_FAN, &sConfig_IHM_old.sParamSoft.Soft_FAN, sizeof(sConfig_IHM_old.sParamSoft.Soft_FAN)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_FAN, textAreaBuffer_SoftFAN, 7);
		textArea_fan.setWildcard(textAreaBuffer_SoftFAN);
		textArea_fan.invalidate();
	}
	// Soft MZ
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_MZ, &sConfig_IHM_old.sParamSoft.Soft_MZ, sizeof(sConfig_IHM_old.sParamSoft.Soft_MZ)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_MZ, textAreaBuffer_SoftMZ, 7);
		textArea_mz.setWildcard(textAreaBuffer_SoftMZ);
		textArea_mz.invalidate();
	}
	// Soft ECS
	if(memcmp(&sConfig_IHM->sParamSoft.Soft_ECS, &sConfig_IHM_old.sParamSoft.Soft_ECS, sizeof(sConfig_IHM_old.sParamSoft.Soft_ECS)))
	{
		Unicode::fromUTF8(sConfig_IHM->sParamSoft.Soft_ECS, textAreaBuffer_SoftECS, 7);
		textArea_ecs.setWildcard(textAreaBuffer_SoftECS);
		textArea_ecs.invalidate();
	}
	// Mac adresse
	if(memcmp(&sConfig_IHM->sParamSoft.MacAdress, &sConfig_IHM_old.sParamSoft.MacAdress, sizeof(sConfig_IHM_old.sParamSoft.MacAdress)))
	{
		Unicode::snprintf(textAreaBuffer_Mac, 18, "%02x:%02x:%02x:%02x:%02x:%02x", sConfig_IHM->sParamSoft.MacAdress[0], sConfig_IHM->sParamSoft.MacAdress[1], sConfig_IHM->sParamSoft.MacAdress[2], sConfig_IHM->sParamSoft.MacAdress[3], sConfig_IHM->sParamSoft.MacAdress[4], sConfig_IHM->sParamSoft.MacAdress[5]);
		textArea_mac.setWildcard(textAreaBuffer_Mac);
		textArea_mac.invalidate();
	}

	memcpy(&sConfig_IHM_old, sConfig_IHM, sizeof(S_CONFIG_IHM));
}

void Infos_systemeView::changeStatutPAC(S_STATUT_PAC *sStatut_PAC)
{
	// Recup config
	if((sStatut_PAC_old.ModifConfig | sStatut_PAC_old.ModifConfigSimple) != (sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple))
	{
		barre_titre.recupConfig((sStatut_PAC->ModifConfig | sStatut_PAC->ModifConfigSimple));
		barre_titre.invalidate();
	}
	memcpy(&sStatut_PAC_old, sStatut_PAC, sizeof(S_STATUT_PAC));
}

void Infos_systemeView::changeStatutEther(S_CYC_ETHER_III *sCycEther)
{
	if(bConnexionDistance != sCycEther->bAppletConnect)
	{
		bConnexionDistance = sCycEther->bAppletConnect;
		barre_titre.connexionDistante(bConnexionDistance);
		barre_titre.invalidate();
	}
	if(memcmp(&u32WIP, &sCycEther->WIP, sizeof(u32WIP)))
	{
		memcpy(&u32WIP, &sCycEther->WIP, sizeof(u32WIP));
		Unicode::snprintf(textAreaBuffer_WIP, 16, "%d.%d.%d.%d", u32WIP & 0xff, (u32WIP >> 8) & 0xff, (u32WIP >> 16) & 0xff, (u32WIP >> 24) & 0xff);
		textArea_wip.setWildcard(textAreaBuffer_WIP);
		textArea_wip.invalidate();
	}
	if(memcmp(&u32IP, &sCycEther->IP, sizeof(u32IP)))
	{
		memcpy(&u32IP, &sCycEther->IP, sizeof(u32IP));
		Unicode::snprintf(textAreaBuffer_IP, 16, "%d.%d.%d.%d", u32IP & 0xff, (u32IP >> 8) & 0xff, (u32IP >> 16) & 0xff, (u32IP >> 24) & 0xff);
		textArea_ip.setWildcard(textAreaBuffer_IP);
		textArea_wip.invalidate();
	}
}

void Infos_systemeView::changeErreur(uint16_t u16Erreur)
{
	if(u16ErreurAffichee != u16Erreur)
	{
		u16ErreurAffichee = u16Erreur;
		barre_titre.erreur(u16Erreur);
		barre_titre.invalidate();
	}
}

void Infos_systemeView::changeDate(S_DATE *sDate)
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
