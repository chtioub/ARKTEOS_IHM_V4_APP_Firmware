#ifndef PARAMETRESVIEW_HPP
#define PARAMETRESVIEW_HPP

#include <gui_generated/parametres_screen/ParametresViewBase.hpp>
#include <gui/parametres_screen/ParametresPresenter.hpp>

class ParametresView : public ParametresViewBase
{
public:
    ParametresView();
    virtual ~ParametresView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PARAMETRESVIEW_HPP
