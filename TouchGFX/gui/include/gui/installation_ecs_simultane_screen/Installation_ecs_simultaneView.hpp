#ifndef INSTALLATION_ECS_SIMULTANEVIEW_HPP
#define INSTALLATION_ECS_SIMULTANEVIEW_HPP

#include <gui_generated/installation_ecs_simultane_screen/Installation_ecs_simultaneViewBase.hpp>
#include <gui/installation_ecs_simultane_screen/Installation_ecs_simultanePresenter.hpp>

class Installation_ecs_simultaneView : public Installation_ecs_simultaneViewBase
{
public:
    Installation_ecs_simultaneView();
    virtual ~Installation_ecs_simultaneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_SIMULTANEVIEW_HPP
