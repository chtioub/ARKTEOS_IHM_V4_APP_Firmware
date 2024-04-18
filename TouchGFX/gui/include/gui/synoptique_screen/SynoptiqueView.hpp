#ifndef SYNOPTIQUEVIEW_HPP
#define SYNOPTIQUEVIEW_HPP

#include <gui_generated/synoptique_screen/SynoptiqueViewBase.hpp>
#include <gui/synoptique_screen/SynoptiquePresenter.hpp>

class SynoptiqueView : public SynoptiqueViewBase
{
public:
    SynoptiqueView();
    virtual ~SynoptiqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SYNOPTIQUEVIEW_HPP
