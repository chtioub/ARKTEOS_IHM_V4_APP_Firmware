#ifndef INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP
#define INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP

#include <gui_generated/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelViewBase.hpp>
#include <gui/installation_ecs_cycle_legionel_screen/Installation_ecs_cycle_legionelPresenter.hpp>

class Installation_ecs_cycle_legionelView : public Installation_ecs_cycle_legionelViewBase
{
public:
    Installation_ecs_cycle_legionelView();
    virtual ~Installation_ecs_cycle_legionelView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_CYCLE_LEGIONELVIEW_HPP
