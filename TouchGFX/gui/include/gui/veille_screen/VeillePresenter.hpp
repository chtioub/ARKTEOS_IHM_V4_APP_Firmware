#ifndef VEILLEPRESENTER_HPP
#define VEILLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VeilleView;

class VeillePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VeillePresenter(VeilleView& v);

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

    virtual ~VeillePresenter() {}

    void enterVeille();
    void exitVeille();

private:
    VeillePresenter();

    VeilleView& view;
};

#endif // VEILLEPRESENTER_HPP
