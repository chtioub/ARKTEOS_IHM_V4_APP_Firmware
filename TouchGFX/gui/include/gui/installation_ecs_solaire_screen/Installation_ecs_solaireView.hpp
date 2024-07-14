#ifndef INSTALLATION_ECS_SOLAIREVIEW_HPP
#define INSTALLATION_ECS_SOLAIREVIEW_HPP

#include <gui_generated/installation_ecs_solaire_screen/Installation_ecs_solaireViewBase.hpp>
#include <gui/installation_ecs_solaire_screen/Installation_ecs_solairePresenter.hpp>

class Installation_ecs_solaireView : public Installation_ecs_solaireViewBase
{
public:
    Installation_ecs_solaireView();
    virtual ~Installation_ecs_solaireView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECS_SOLAIREVIEW_HPP
