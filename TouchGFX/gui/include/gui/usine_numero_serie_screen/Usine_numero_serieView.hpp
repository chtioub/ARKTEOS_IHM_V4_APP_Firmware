#ifndef USINE_NUMERO_SERIEVIEW_HPP
#define USINE_NUMERO_SERIEVIEW_HPP

#include <gui_generated/usine_numero_serie_screen/Usine_numero_serieViewBase.hpp>
#include <gui/usine_numero_serie_screen/Usine_numero_seriePresenter.hpp>

class Usine_numero_serieView : public Usine_numero_serieViewBase
{
public:
    Usine_numero_serieView();
    virtual ~Usine_numero_serieView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_NUMERO_SERIEVIEW_HPP
