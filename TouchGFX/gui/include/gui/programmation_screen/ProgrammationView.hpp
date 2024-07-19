#ifndef PROGRAMMATIONVIEW_HPP
#define PROGRAMMATIONVIEW_HPP

#include <gui_generated/programmation_screen/ProgrammationViewBase.hpp>
#include <gui/programmation_screen/ProgrammationPresenter.hpp>

class ProgrammationView : public ProgrammationViewBase
{
public:
    ProgrammationView();
    virtual ~ProgrammationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_copier();
    void bouton_coller();
    void barre_lundi();
    void barre_mardi();
    void barre_mercredi();
    void barre_jeudi();
    void barre_vendredi();
    void barre_samedi();
    void barre_dimanche();
protected:
};

#endif // PROGRAMMATIONVIEW_HPP
