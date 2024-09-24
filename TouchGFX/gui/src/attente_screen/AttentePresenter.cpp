#include <gui/attente_screen/AttenteView.hpp>
#include <gui/attente_screen/AttentePresenter.hpp>

AttentePresenter::AttentePresenter(AttenteView& v)
    : view(v)
{

}

void AttentePresenter::activate()
{

}

void AttentePresenter::deactivate()
{

}

void AttentePresenter::changeConfig(S_CONFIG_IHM *sConfig_IHM)
{
	view.changeConfig(sConfig_IHM);
}

void AttentePresenter::c_recup_config(uint8_t u8RecupConfig)
{
	model->c_recup_config(u8RecupConfig);
}

void AttentePresenter::editLuminosite(uint8_t u8Luminosite)
{
	model->editLuminosite(u8Luminosite);
}
