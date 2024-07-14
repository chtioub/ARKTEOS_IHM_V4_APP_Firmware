#ifndef INSTALLATION_CIRCUIT_CAPTAGEPRESENTER_HPP
#define INSTALLATION_CIRCUIT_CAPTAGEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_circuit_captageView;

class Installation_circuit_captagePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_circuit_captagePresenter(Installation_circuit_captageView& v);

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

    virtual ~Installation_circuit_captagePresenter() {}

private:
    Installation_circuit_captagePresenter();

    Installation_circuit_captageView& view;
};

#endif // INSTALLATION_CIRCUIT_CAPTAGEPRESENTER_HPP
