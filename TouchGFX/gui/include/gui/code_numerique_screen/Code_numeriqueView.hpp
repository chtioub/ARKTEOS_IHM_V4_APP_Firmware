#ifndef CODE_NUMERIQUEVIEW_HPP
#define CODE_NUMERIQUEVIEW_HPP

#include <gui_generated/code_numerique_screen/Code_numeriqueViewBase.hpp>
#include <gui/code_numerique_screen/Code_numeriquePresenter.hpp>

class Code_numeriqueView : public Code_numeriqueViewBase
{
public:
    Code_numeriqueView();
    virtual ~Code_numeriqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CODE_NUMERIQUEVIEW_HPP
