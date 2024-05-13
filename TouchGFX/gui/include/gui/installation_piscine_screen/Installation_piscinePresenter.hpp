#ifndef INSTALLATION_PISCINEPRESENTER_HPP
#define INSTALLATION_PISCINEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_piscineView;

class Installation_piscinePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_piscinePresenter(Installation_piscineView& v);

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

    virtual ~Installation_piscinePresenter() {}

private:
    Installation_piscinePresenter();

    Installation_piscineView& view;
};

#endif // INSTALLATION_PISCINEPRESENTER_HPP
