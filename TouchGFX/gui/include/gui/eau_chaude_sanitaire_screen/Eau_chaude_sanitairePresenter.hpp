#ifndef EAU_CHAUDE_SANITAIREPRESENTER_HPP
#define EAU_CHAUDE_SANITAIREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Eau_chaude_sanitaireView;

class Eau_chaude_sanitairePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Eau_chaude_sanitairePresenter(Eau_chaude_sanitaireView& v);

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

    virtual ~Eau_chaude_sanitairePresenter() {}

private:
    Eau_chaude_sanitairePresenter();

    Eau_chaude_sanitaireView& view;
};

#endif // EAU_CHAUDE_SANITAIREPRESENTER_HPP
