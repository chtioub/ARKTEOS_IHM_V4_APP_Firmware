#ifndef DEROGATION_ECSVIEW_HPP
#define DEROGATION_ECSVIEW_HPP

#include <gui_generated/derogation_ecs_screen/Derogation_ecsViewBase.hpp>
#include <gui/derogation_ecs_screen/Derogation_ecsPresenter.hpp>

class Derogation_ecsView : public Derogation_ecsViewBase
{
public:
    Derogation_ecsView();
    virtual ~Derogation_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEROGATION_ECSVIEW_HPP
