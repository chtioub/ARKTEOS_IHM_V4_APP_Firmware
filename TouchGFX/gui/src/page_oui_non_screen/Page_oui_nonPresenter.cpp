#include <gui/page_oui_non_screen/Page_oui_nonView.hpp>
#include <gui/page_oui_non_screen/Page_oui_nonPresenter.hpp>

Page_oui_nonPresenter::Page_oui_nonPresenter(Page_oui_nonView& v)
    : view(v)
{

}

void Page_oui_nonPresenter::activate()
{

}

void Page_oui_nonPresenter::deactivate()
{

}

void Page_oui_nonPresenter::changeDate(S_DATE *sDate)
{
	view.changeDate(sDate);
}

void Page_oui_nonPresenter::changeErreur(uint16_t u16Erreur)
{
	view.changeErreur(u16Erreur);
}
