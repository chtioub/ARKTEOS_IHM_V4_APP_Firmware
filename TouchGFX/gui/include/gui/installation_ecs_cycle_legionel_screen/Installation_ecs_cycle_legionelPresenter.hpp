#ifndef INSTALLATION_ECS_CYCLE_LEGIONELPRESENTER_HPP
#define INSTALLATION_ECS_CYCLE_LEGIONELPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_ecs_cycle_legionelView;

class Installation_ecs_cycle_legionelPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_ecs_cycle_legionelPresenter(Installation_ecs_cycle_legionelView& v);

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

    virtual ~Installation_ecs_cycle_legionelPresenter() {}

private:
    Installation_ecs_cycle_legionelPresenter();

    Installation_ecs_cycle_legionelView& view;
};

#endif // INSTALLATION_ECS_CYCLE_LEGIONELPRESENTER_HPP
