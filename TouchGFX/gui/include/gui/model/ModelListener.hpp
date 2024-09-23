#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void enterVeille() {};
    virtual void exitVeille() {};
    virtual void changeModePac(bool marche) {};
    virtual void changeDate(S_DATE *sDate) {};
    virtual void changeErreur(uint16_t u16Erreur) {};
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire) {};
    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx) {};
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC) {};
    virtual void changeStatutECS(S_STATUT_ECS *sStatut_ECS) {};
    virtual void changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine) {};
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther) {};
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo) {};
    virtual void changeStatutRegulExt(S_STATUT_REG_EXT *sStatut_RegulExt) {};
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM) {};
    virtual void changeDemandeFrigo(S_DEMANDE_FRIGO *sDemandeFrigo) {};
    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF) {};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
