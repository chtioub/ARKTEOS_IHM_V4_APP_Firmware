#ifndef INSTALLATIONPRESENTER_HPP
#define INSTALLATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class InstallationView;

class InstallationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    InstallationPresenter(InstallationView& v);

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

    virtual ~InstallationPresenter() {}

private:
    InstallationPresenter();

    InstallationView& view;
};

#endif // INSTALLATIONPRESENTER_HPP
