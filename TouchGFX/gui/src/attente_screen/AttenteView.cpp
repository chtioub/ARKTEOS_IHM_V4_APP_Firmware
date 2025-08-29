#include <gui/attente_screen/AttenteView.hpp>

AttenteView::AttenteView()
{
//	u16CompteurDemarrageSysteme = 0;
	u16CompteurDemarrageSysteme = 40;
	textArea_attente_communication.setVisible(true);
	Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "%d", u16CompteurDemarrageSysteme);
	textArea_attente_communication.setWildcard(textAreaBuffer_RecupConfig);
	textArea_recup_config.setWildcard(textAreaBuffer_RecupConfig);
	textArea_recup_config.setVisible(false);
	//
#ifndef SIMULATOR
	presenter->editLuminosite(50);
#endif
}

void AttenteView::setupScreen()
{
    AttenteViewBase::setupScreen();
}

void AttenteView::tearDownScreen()
{
    AttenteViewBase::tearDownScreen();
}

void AttenteView::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	switch(sConfig_IHM->u16RecupConfig)
	{
		case 0:
			Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "0");
			break;
		case 1:
			Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "33");
			break;
		case 2:
			if(sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA)
			{
				Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "50");
			}
			else Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "66");
			break;
		case 3:
			if(sConfig_IHM->sModele_PAC.u8ModelePAC == INVERTERRA)
			{
				Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "75");
			}
			else
			{
				Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "100");
				bAutorisationCompteurVeille = true;
			}
			break;
		case 4:
			Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "100");
			bAutorisationCompteurVeille = true;
			break;
	}
	if(sConfig_IHM->u16RecupConfig != 0)
	{
		textArea_attente_communication.setVisible(false);
		textArea_recup_config.setVisible(true);
	}
	textArea_attente_communication.invalidate();
	textArea_recup_config.setWildcard(textAreaBuffer_RecupConfig);
	textArea_recup_config.invalidate();
}

void AttenteView::Timer_500ms()
{
	if(sConfig_IHM.u16RecupConfig == 0)
	{
		if(textArea_attente_communication.isVisible())
		{
			textArea_attente_communication.setVisible(false);
		}
		else
		{
//			if(++u16CompteurDemarrageSysteme == 1000)
//			{
//				u16CompteurDemarrageSysteme = 0;
//			}
			if(--u16CompteurDemarrageSysteme <= 0)
			{
				u16CompteurDemarrageSysteme = 0;
			}
			textArea_attente_communication.setVisible(true);
			Unicode::snprintf(textAreaBuffer_RecupConfig, 4, "%d", u16CompteurDemarrageSysteme);
			textArea_attente_communication.setWildcard(textAreaBuffer_RecupConfig);
		}
		textArea_attente_communication.invalidate();
	}

	switch(sConfig_IHM.u16RecupConfig)
	{
		case 0:
			if (u16CompteurDemarrageSysteme == 0)
			{
				presenter->c_recup_config(0);
			}
			break;
		case 1:
			presenter->c_recup_config(1);
			break;
		case 2:
			presenter->c_recup_config(2);
			u8TempoAttenteTrameInverterra = 10;
			break;
		case 3:
			if(sConfig_IHM.sModele_PAC.u8ModelePAC == INVERTERRA)
			{
				if (u8TempoAttenteTrameInverterra > 0) u8TempoAttenteTrameInverterra--;
				if(u8TempoAttenteTrameInverterra <= 0)
				{
					presenter->c_recup_config(3);
				}
			}
			else if(sConfig_IHM.u16NbCyclique == 6)
			{
				application().gotoAccueilScreenNoTransition();
			}
			break;
		case 4:
			if(sConfig_IHM.u16NbCyclique == 6)
			{
				application().gotoAccueilScreenNoTransition();
			}
			break;
	}
}
