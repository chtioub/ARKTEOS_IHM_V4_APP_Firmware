#ifndef HISTO_FONCTIONNEMENTVIEW_HPP
#define HISTO_FONCTIONNEMENTVIEW_HPP

#include <gui_generated/histo_fonctionnement_screen/Histo_fonctionnementViewBase.hpp>
#include <gui/histo_fonctionnement_screen/Histo_fonctionnementPresenter.hpp>
#include <touchgfx/Color.hpp>

class Histo_fonctionnementView : public Histo_fonctionnementViewBase
{
public:
    Histo_fonctionnementView();
    virtual ~Histo_fonctionnementView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void update_graph_histo(DATA_HISTO *data_histo);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);

    void clear_graph();
    void bouton_droit();
    void bouton_gauche();
    void update_container();


protected:
    bool bConnexionDistance;
	uint8_t u8Copie;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
    touchgfx::Unicode::UnicodeChar textArea_Buffer_temp_gauche_max[7], textArea_Buffer_temp_gauche_min[7], textArea_Buffer_temp_droite_max[7], textArea_Buffer_temp_droite_min[7];
//    uint16_t u16TempBallon_Z1[360],u16Temp_Z2[360], u16TempDepart[360],u16TempRetour[360], u16PointeurTableau;//, u16StartIndex;
//    uint16_t u16ValmaxAmbBall, u16ValminAmbBall,  u16ValmaxTeau,u16ValminTeau;
//    int16_t i16ValmaxText, i16ValminText, i16TempExt[360];
    bool  bGraphPage1, bAffichageTempBallon, bPremierPassage;//bTableauPlein
    touchgfx::Box box_etat_pac[360], box_etat_app_chauf[360], box_etat_app_ecs[360];
    const touchgfx::colortype RED = touchgfx::Color::getColorFromRGB(229, 38, 32);
	const touchgfx::colortype GREEN = touchgfx::Color::getColorFromRGB(179, 193, 14);
	const touchgfx::colortype BLUE = touchgfx::Color::getColorFromRGB(58, 176, 200);
	const touchgfx::colortype PINK = touchgfx::Color::getColorFromRGB(231, 0, 148);
	const touchgfx::colortype WHITE = touchgfx::Color::getColorFromRGB(255, 255, 255);
	const touchgfx::colortype ORANGE = touchgfx::Color::getColorFromRGB(226, 126, 7);

    //BarGraphWidget barGraph;
};

#endif // HISTO_FONCTIONNEMENTVIEW_HPP
