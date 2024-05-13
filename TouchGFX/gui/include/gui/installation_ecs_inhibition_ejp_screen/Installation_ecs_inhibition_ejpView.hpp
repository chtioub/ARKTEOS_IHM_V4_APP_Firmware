#ifndef INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP
#define INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP

#include <gui_generated/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpViewBase.hpp>
#include <gui/installation_ecs_inhibition_ejp_screen/Installation_ecs_inhibition_ejpPresenter.hpp>

class Installation_ecs_inhibition_ejpView : public Installation_ecs_inhibition_ejpViewBase
{
public:
    Installation_ecs_inhibition_ejpView();
    virtual ~Installation_ecs_inhibition_ejpView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_INHIBITION_EJPVIEW_HPP
