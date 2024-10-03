#include <gui/installation_hysteresis_screen/Installation_hysteresisView.hpp>
#include <gui/installation_hysteresis_screen/Installation_hysteresisPresenter.hpp>

Installation_hysteresisPresenter::Installation_hysteresisPresenter(Installation_hysteresisView& v)
    : view(v)
{

}

void Installation_hysteresisPresenter::activate()
{

}

void Installation_hysteresisPresenter::deactivate()
{

}

void Installation_hysteresisPresenter::Red_Butt()
{
	view.Red_Butt();
}

void Installation_hysteresisPresenter::Blue_Butt()
{
	view.Blue_Butt();
}
