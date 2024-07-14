#ifndef INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP
#define INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP

#include <gui_generated/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointViewBase.hpp>
#include <gui/installation_ecs_puissance_appoint_screen/Installation_ecs_puissance_appointPresenter.hpp>

class Installation_ecs_puissance_appointView : public Installation_ecs_puissance_appointViewBase
{
public:
    Installation_ecs_puissance_appointView();
    virtual ~Installation_ecs_puissance_appointView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_PUISSANCE_APPOINTVIEW_HPP
