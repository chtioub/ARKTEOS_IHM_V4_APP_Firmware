#ifndef CODE_NUMERIQUEPRESENTER_HPP
#define CODE_NUMERIQUEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Code_numeriqueView;

class Code_numeriquePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Code_numeriquePresenter(Code_numeriqueView& v);

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

    virtual ~Code_numeriquePresenter() {}

private:
    Code_numeriquePresenter();

    Code_numeriqueView& view;
};

#endif // CODE_NUMERIQUEPRESENTER_HPP
