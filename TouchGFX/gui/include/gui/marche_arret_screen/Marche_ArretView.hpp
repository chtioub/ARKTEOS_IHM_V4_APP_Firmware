#ifndef MARCHE_ARRETVIEW_HPP
#define MARCHE_ARRETVIEW_HPP

#include <gui_generated/marche_arret_screen/Marche_ArretViewBase.hpp>
#include <gui/marche_arret_screen/Marche_ArretPresenter.hpp>

class Marche_ArretView : public Marche_ArretViewBase
{
public:
    Marche_ArretView();
    virtual ~Marche_ArretView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MARCHE_ARRETVIEW_HPP
