#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "IHM_V4.h"

Model::Model() : modelListener(0)
{
#ifdef SIMULATOR
	sDate.Date = 12;
	sDate.Month = 9;
	sDate.Year = 24;
	sDate.Hours = 12;
	sDate.Minutes = 55;
	sDate.WeekDay = 5;
	u16ErreurEncours = 51;
#endif
}

void Model::tick()
{
	if(dataUpdated != 0)
	{
		modelListener->changeModePac(cosebe_test.bModePAC);
		dataUpdated = 0;
	}
	if(arkteos_update.date_update)
	{
		modelListener->changeDate(&sDate);
		arkteos_update.date_update = false;
	}
	if(arkteos_update.erreur_update)
	{
		modelListener->changeErreur(u16ErreurEncours);
		arkteos_update.erreur_update = false;
	}
	if(arkteos_update.statut_primaire_update)
	{
		modelListener->changeStatutPrimaire(&sStatut_Primaire);
		arkteos_update.statut_primaire_update = false;
	}
	if(arkteos_update.statut_zx_update[0])
	{
		modelListener->changeStatutZx(0, &sStatut_Zx[0]);
		arkteos_update.statut_zx_update[0] = false;
	}
	if(arkteos_update.statut_zx_update[1])
	{
		modelListener->changeStatutZx(1, &sStatut_Zx[1]);
		arkteos_update.statut_zx_update[1] = false;
	}
	if(arkteos_update.statut_zx_update[2])
	{
		modelListener->changeStatutZx(2, &sStatut_Zx[2]);
		arkteos_update.statut_zx_update[2] = false;
	}
	if(arkteos_update.statut_zx_update[3])
	{
		modelListener->changeStatutZx(3, &sStatut_Zx[3]);
		arkteos_update.statut_zx_update[3] = false;
	}
	if(arkteos_update.statut_zx_update[4])
	{
		modelListener->changeStatutZx(4, &sStatut_Zx[4]);
		arkteos_update.statut_zx_update[4] = false;
	}
	if(arkteos_update.statut_zx_update[5])
	{
		modelListener->changeStatutZx(5, &sStatut_Zx[5]);
		arkteos_update.statut_zx_update[5] = false;
	}
	if(arkteos_update.statut_zx_update[6])
	{
		modelListener->changeStatutZx(6, &sStatut_Zx[6]);
		arkteos_update.statut_zx_update[6] = false;
	}
	if(arkteos_update.statut_zx_update[7])
	{
		modelListener->changeStatutZx(7, &sStatut_Zx[7]);
		arkteos_update.statut_zx_update[7] = false;
	}
	if(arkteos_update.statut_pac_update)
	{
		modelListener->changeStatutPAC(&sStatut_PAC);
		arkteos_update.statut_pac_update = false;
	}
	if(arkteos_update.statut_ether_update)
	{
		modelListener->changeStatutEther(&sCycEther);
		arkteos_update.statut_ether_update = false;
	}
	if(arkteos_update.statut_ecs_update)
	{
		modelListener->changeStatutECS(&sStatut_ECS);
		arkteos_update.statut_ecs_update = false;
	}
	if(arkteos_update.statut_piscine_update)
	{
		modelListener->changeStatutPiscine(&sStatut_Piscine);
		arkteos_update.statut_piscine_update = false;
	}
	if(arkteos_update.statut_regul_ext_update)
	{
		modelListener->changeStatutRegulExt(&sStatut_RegulExt);
		arkteos_update.statut_regul_ext_update = false;
	}
	if(arkteos_update.cycl_frigo_update)
	{
		modelListener->changeStatutCyclFrigo(&sCyclRegFrigo[0]);
		arkteos_update.cycl_frigo_update = false;
	}
	if(arkteos_update.config_update)
	{
		modelListener->changeConfig(&sConfig_IHM);
		arkteos_update.config_update = false;
	}
}

void Model::energieState(uint16_t state)
{
  if(state != cosebe_tx.u16Data)
  {
    cosebe_tx.u16Data = state;
    sendData = 1;
  }
}
