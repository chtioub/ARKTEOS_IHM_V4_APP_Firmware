#ifndef INSTALLATION_MZ_PARAMETRAGE_GROUPESPRESENTER_HPP
#define INSTALLATION_MZ_PARAMETRAGE_GROUPESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_MZ_parametrage_groupesView;

class Installation_MZ_parametrage_groupesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_MZ_parametrage_groupesPresenter(Installation_MZ_parametrage_groupesView& v);

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

    virtual ~Installation_MZ_parametrage_groupesPresenter() {}

private:
    Installation_MZ_parametrage_groupesPresenter();

    Installation_MZ_parametrage_groupesView& view;
};

#endif // INSTALLATION_MZ_PARAMETRAGE_GROUPESPRESENTER_HPP
