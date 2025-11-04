#ifndef VERIFICATION_ANNUELLEPRESENTER_HPP
#define VERIFICATION_ANNUELLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Verification_annuelleView;

class Verification_annuellePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Verification_annuellePresenter(Verification_annuelleView& v);

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

    virtual ~Verification_annuellePresenter() {}
    void c_install_install_pac();

private:
    Verification_annuellePresenter();

    Verification_annuelleView& view;
};

#endif // VERIFICATION_ANNUELLEPRESENTER_HPP
