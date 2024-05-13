#ifndef INSTALLATION_ECS_AVANCESPRESENTER_HPP
#define INSTALLATION_ECS_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_ecs_avancesView;

class Installation_ecs_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_ecs_avancesPresenter(Installation_ecs_avancesView& v);

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

    virtual ~Installation_ecs_avancesPresenter() {}

private:
    Installation_ecs_avancesPresenter();

    Installation_ecs_avancesView& view;
};

#endif // INSTALLATION_ECS_AVANCESPRESENTER_HPP
