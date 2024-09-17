#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/hal/Types.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <string.h>
#include "arkteos_var_commune.h"
#include "arkteos_defauts.h"
#include "IHM_V4.h"

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    uint16_t computeCRC(uint8_t *data, uint16_t size);

//    void energieState(uint16_t state);
    void c_ener_raz();
    void c_ener_cumul_prod();
    void c_ener_cumul_conso();
    void c_ener_histo_12m_conso();
    void c_ener_histo_24j_conso();
    void c_ener_histo_24h_conso();
    void c_ener_histo_12m_prod();
    void c_ener_histo_24j_prod();
    void c_ener_histo_24h_prod();

    void c_user_param();
    void c_user_vacances();
    void c_user_ecs();
    void c_user_piscine();
    void c_user_date();
    void c_user_zx(uint8_t u8Zone);
    void c_user_zx_all();
    void c_user_reg_ext();

    void c_recup_config(uint8_t u8RecupConfig);

    void c_prog_ecs(bool bEnvoi);
    void c_prog_option(bool bEnvoi);
    void c_prog_piscine(bool bEnvoi);
    void c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi);
    void c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi);
    void c_prog_reg_ext_chaud(bool bEnvoi);
    void c_prog_reg_ext_froid(bool bEnvoi);

    void c_install_raz_config();
    void c_install_config_pac();
    void c_install_ecs();
    void c_install_param();
    void c_install_piscine();
    void c_install_raz_histo_err();
    void c_install_reg_ext();
    void c_install_zx(uint8_t u8Zone);

    void c_install_th_association(uint8_t u8NumZone);
    void c_install_th_dissociation(uint8_t u8NumZone);

    void c_usine_param();
    void c_usine_password();
    void c_usine_phoenix(int u8Esclave);
    void c_usine_raz_energie();
    void c_usine_raz_config();

    void c_sav_histo_err();
    void c_sav_param();
    void c_sav_shunt_tempo();
    void c_sav_raz_tps_fonct(uint8_t u8Esclave);
    void c_sav_raz_soft_flash();
    void c_sav_raz_log();

    void c_restart();

protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
