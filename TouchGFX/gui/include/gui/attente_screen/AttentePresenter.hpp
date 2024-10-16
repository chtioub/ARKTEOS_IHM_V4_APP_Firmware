#ifndef ATTENTEPRESENTER_HPP
#define ATTENTEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AttenteView;

class AttentePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AttentePresenter(AttenteView& v);

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

    virtual ~AttentePresenter() {}

    void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    void c_recup_config(uint8_t u8RecupConfig);

    void editLuminosite(uint8_t u8Luminosite);
private:
    AttentePresenter();

    AttenteView& view;
};

#endif // ATTENTEPRESENTER_HPP
