#ifndef INSTALLATION_CHAUFFE_DALLEPRESENTER_HPP
#define INSTALLATION_CHAUFFE_DALLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_chauffe_dalleView;

class Installation_chauffe_dallePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_chauffe_dallePresenter(Installation_chauffe_dalleView& v);

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

    virtual ~Installation_chauffe_dallePresenter() {}

private:
    Installation_chauffe_dallePresenter();

    Installation_chauffe_dalleView& view;
};

#endif // INSTALLATION_CHAUFFE_DALLEPRESENTER_HPP
