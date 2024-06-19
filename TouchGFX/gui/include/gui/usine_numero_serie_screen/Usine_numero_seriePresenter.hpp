#ifndef USINE_NUMERO_SERIEPRESENTER_HPP
#define USINE_NUMERO_SERIEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_numero_serieView;

class Usine_numero_seriePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_numero_seriePresenter(Usine_numero_serieView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Usine_numero_seriePresenter() {}

private:
    Usine_numero_seriePresenter();

    Usine_numero_serieView& view;
};

#endif // USINE_NUMERO_SERIEPRESENTER_HPP
