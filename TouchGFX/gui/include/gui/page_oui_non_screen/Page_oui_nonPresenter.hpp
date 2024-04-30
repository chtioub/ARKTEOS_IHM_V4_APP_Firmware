#ifndef PAGE_OUI_NONPRESENTER_HPP
#define PAGE_OUI_NONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Page_oui_nonView;

class Page_oui_nonPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Page_oui_nonPresenter(Page_oui_nonView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Page_oui_nonPresenter() {}

private:
    Page_oui_nonPresenter();

    Page_oui_nonView& view;
};

#endif // PAGE_OUI_NONPRESENTER_HPP
