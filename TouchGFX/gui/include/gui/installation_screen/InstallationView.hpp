#ifndef INSTALLATIONVIEW_HPP
#define INSTALLATIONVIEW_HPP

#include <gui_generated/installation_screen/InstallationViewBase.hpp>
#include <gui/installation_screen/InstallationPresenter.hpp>

class InstallationView : public InstallationViewBase
{
public:
    InstallationView();
    virtual ~InstallationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATIONVIEW_HPP
