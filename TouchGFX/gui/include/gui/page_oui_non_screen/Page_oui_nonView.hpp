#ifndef PAGE_OUI_NONVIEW_HPP
#define PAGE_OUI_NONVIEW_HPP

#include <gui_generated/page_oui_non_screen/Page_oui_nonViewBase.hpp>
#include <gui/page_oui_non_screen/Page_oui_nonPresenter.hpp>

class Page_oui_nonView : public Page_oui_nonViewBase
{
public:
    Page_oui_nonView();
    virtual ~Page_oui_nonView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_non_page_oui_non();
    void bouton_oui_page_oui_non();
    void bouton_valider();
protected:
};

#endif // PAGE_OUI_NONVIEW_HPP
