#ifndef INSTALLATION_ECS_INHIBITION_EJPPRESENTER_HPP
#define INSTALLATION_ECS_INHIBITION_EJPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_ecs_inhibition_ejpView;

class Installation_ecs_inhibition_ejpPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_ecs_inhibition_ejpPresenter(Installation_ecs_inhibition_ejpView& v);

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

    virtual ~Installation_ecs_inhibition_ejpPresenter() {}

private:
    Installation_ecs_inhibition_ejpPresenter();

    Installation_ecs_inhibition_ejpView& view;
};

#endif // INSTALLATION_ECS_INHIBITION_EJPPRESENTER_HPP
