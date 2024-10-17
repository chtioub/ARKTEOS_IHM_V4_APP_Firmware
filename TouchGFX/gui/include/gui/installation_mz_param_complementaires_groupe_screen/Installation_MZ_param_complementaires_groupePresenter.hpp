#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEPRESENTER_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_MZ_param_complementaires_groupeView;

class Installation_MZ_param_complementaires_groupePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_MZ_param_complementaires_groupePresenter(Installation_MZ_param_complementaires_groupeView& v);

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

    virtual ~Installation_MZ_param_complementaires_groupePresenter() {}

private:
    Installation_MZ_param_complementaires_groupePresenter();

    Installation_MZ_param_complementaires_groupeView& view;
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEPRESENTER_HPP
