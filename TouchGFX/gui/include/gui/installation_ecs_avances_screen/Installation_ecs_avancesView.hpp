#ifndef INSTALLATION_ECS_AVANCESVIEW_HPP
#define INSTALLATION_ECS_AVANCESVIEW_HPP

#include <gui_generated/installation_ecs_avances_screen/Installation_ecs_avancesViewBase.hpp>
#include <gui/installation_ecs_avances_screen/Installation_ecs_avancesPresenter.hpp>

class Installation_ecs_avancesView : public Installation_ecs_avancesViewBase
{
public:
    Installation_ecs_avancesView();
    virtual ~Installation_ecs_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_AVANCESVIEW_HPP
