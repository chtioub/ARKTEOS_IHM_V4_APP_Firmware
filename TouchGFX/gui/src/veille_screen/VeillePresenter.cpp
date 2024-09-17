#include <gui/veille_screen/VeilleView.hpp>
#include <gui/veille_screen/VeillePresenter.hpp>

VeillePresenter::VeillePresenter(VeilleView& v)
    : view(v)
{

}

void VeillePresenter::activate()
{

}

void VeillePresenter::deactivate()
{

}

void VeillePresenter::enterVeille()
{
  model->enterVeille();
}

void VeillePresenter::exitVeille()
{
  model->exitVeille();
}
