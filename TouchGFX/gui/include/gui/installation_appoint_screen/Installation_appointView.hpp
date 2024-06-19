#ifndef INSTALLATION_APPOINTVIEW_HPP
#define INSTALLATION_APPOINTVIEW_HPP

#include <gui_generated/installation_appoint_screen/Installation_appointViewBase.hpp>
#include <gui/installation_appoint_screen/Installation_appointPresenter.hpp>

class Installation_appointView : public Installation_appointViewBase
{
public:
    Installation_appointView();
    virtual ~Installation_appointView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_APPOINTVIEW_HPP
