#include <gui/verification_annuelle_screen/Verification_annuelleView.hpp>
#include <gui/verification_annuelle_screen/Verification_annuellePresenter.hpp>

Verification_annuellePresenter::Verification_annuellePresenter(Verification_annuelleView& v)
    : view(v)
{

}

void Verification_annuellePresenter::activate()
{

}

void Verification_annuellePresenter::deactivate()
{

}

void Verification_annuellePresenter::c_install_install_pac()
{
	model->c_install_install_pac();
}
