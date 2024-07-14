#ifndef INSTALLATION_ECSVIEW_HPP
#define INSTALLATION_ECSVIEW_HPP

#include <gui_generated/installation_ecs_screen/Installation_ecsViewBase.hpp>
#include <gui/installation_ecs_screen/Installation_ecsPresenter.hpp>

class Installation_ecsView : public Installation_ecsViewBase
{
public:
    Installation_ecsView();
    virtual ~Installation_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_ECSVIEW_HPP
