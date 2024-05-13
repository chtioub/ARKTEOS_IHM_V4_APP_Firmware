#ifndef INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP
#define INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP

#include <gui_generated/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurViewBase.hpp>
#include <gui/installation_ecs_puissance_echangeur_screen/Installation_ecs_puissance_echangeurPresenter.hpp>

class Installation_ecs_puissance_echangeurView : public Installation_ecs_puissance_echangeurViewBase
{
public:
    Installation_ecs_puissance_echangeurView();
    virtual ~Installation_ecs_puissance_echangeurView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_PUISSANCE_ECHANGEURVIEW_HPP
