#ifndef USINE_CHOIX_FLUIDEVIEW_HPP
#define USINE_CHOIX_FLUIDEVIEW_HPP

#include <gui_generated/usine_choix_fluide_screen/Usine_choix_fluideViewBase.hpp>
#include <gui/usine_choix_fluide_screen/Usine_choix_fluidePresenter.hpp>

class Usine_choix_fluideView : public Usine_choix_fluideViewBase
{
public:
    Usine_choix_fluideView();
    virtual ~Usine_choix_fluideView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CHOIX_FLUIDEVIEW_HPP
