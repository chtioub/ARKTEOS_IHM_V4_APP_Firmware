#ifndef ACCUEILVIEW_HPP
#define ACCUEILVIEW_HPP

#include <gui_generated/accueil_screen/AccueilViewBase.hpp>
#include <gui/accueil_screen/AccueilPresenter.hpp>

class AccueilView : public AccueilViewBase
{
public:
    AccueilView();
    virtual ~AccueilView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void Timer_500ms();
    void bouton_marche_arret();
    virtual void changeModePac(bool marche);
protected:

private:
    touchgfx::Callback<AccueilView, int16_t> swipeCallback;

    void swipeCallbackHandler(int16_t);

};

#endif // ACCUEILVIEW_HPP
