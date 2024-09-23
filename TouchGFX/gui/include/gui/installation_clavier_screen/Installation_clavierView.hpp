#ifndef INSTALLATION_CLAVIERVIEW_HPP
#define INSTALLATION_CLAVIERVIEW_HPP

#include <gui_generated/installation_clavier_screen/Installation_clavierViewBase.hpp>
#include <gui/installation_clavier_screen/Installation_clavierPresenter.hpp>

class Installation_clavierView : public Installation_clavierViewBase
{
public:
    Installation_clavierView();
    virtual ~Installation_clavierView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CLAVIERVIEW_HPP
