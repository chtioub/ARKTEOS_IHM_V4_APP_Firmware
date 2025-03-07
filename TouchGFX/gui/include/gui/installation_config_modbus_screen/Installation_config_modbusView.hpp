#ifndef INSTALLATION_CONFIG_MODBUSVIEW_HPP
#define INSTALLATION_CONFIG_MODBUSVIEW_HPP

#include <gui_generated/installation_config_modbus_screen/Installation_config_modbusViewBase.hpp>
#include <gui/installation_config_modbus_screen/Installation_config_modbusPresenter.hpp>

class Installation_config_modbusView : public Installation_config_modbusViewBase
{
public:
    Installation_config_modbusView();
    virtual ~Installation_config_modbusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_temp_zones();
    void bouton_activer_resistance_oui();
    void bouton_activer_resistance_non();
    void bouton_arret_pac_oui();
    void bouton_arret_pac_non();
    void bouton_gauche_parite();
    void bouton_droite_parite();
    void bouton_gauche_nb();
    void bouton_droite_nb();
    void bouton_gauche_vitesse();
    void bouton_droite_vitesse();
    void bouton_gauche_adresse();
    void bouton_droite_adresse();
    void bouton_valider();
    void update_temp_zones();
    void update_parite();
    void update_stopbit();
    void update_vitesse();
    void update_adresse();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	uint8_t bConfigThermostats120R, bGestionTimeOut, adresse, speed, u1NbStopBit, u2Parite, bThermostatModbusExterne;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Parite[5], textAreaBuffer_StopBit[2], textAreaBuffer_Speed[6], textAreaBuffer_Adresse[3];
};

#endif // INSTALLATION_CONFIG_MODBUSVIEW_HPP
