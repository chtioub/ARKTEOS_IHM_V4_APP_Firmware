#ifndef INFOS_SYSTEMEVIEW_HPP
#define INFOS_SYSTEMEVIEW_HPP

#include <gui_generated/infos_systeme_screen/Infos_systemeViewBase.hpp>
#include <gui/infos_systeme_screen/Infos_systemePresenter.hpp>

class Infos_systemeView : public Infos_systemeViewBase
{
public:
    Infos_systemeView();
    virtual ~Infos_systemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint32_t u32WIP, u32IP;
    uint16_t u16ErreurAffichee;
    S_CONFIG_IHM sConfig_IHM_old;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Gamme[20], textAreaBuffer_Modele[20], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_SoftIHM[7], textAreaBuffer_SoftETHER[7], textAreaBuffer_SoftREG[7], textAreaBuffer_SoftFRIGO[7], textAreaBuffer_SoftFAN[7], textAreaBuffer_SoftMZ[7], textAreaBuffer_SoftPW[9], textAreaBuffer_SoftECS[7], textAreaBuffer_WIP[16], textAreaBuffer_IP[16], textAreaBuffer_Mac[18], textAreaBuffer_MiseService[9], textAreaBuffer_NumeroSerie[13], textAreaBuffer_Modbus[16], textAreaBuffer_Fluide[15];
};

#endif // INFOS_SYSTEMEVIEW_HPP
