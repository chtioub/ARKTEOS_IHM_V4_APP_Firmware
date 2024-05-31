#ifndef CODE_WEBPRESENTER_HPP
#define CODE_WEBPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Code_webView;

class Code_webPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Code_webPresenter(Code_webView& v);

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

    virtual ~Code_webPresenter() {}

private:
    Code_webPresenter();

    Code_webView& view;
};

#endif // CODE_WEBPRESENTER_HPP
