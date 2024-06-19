#ifndef INSTALLATION_HYDRAULIQUEVIEW_HPP
#define INSTALLATION_HYDRAULIQUEVIEW_HPP

#include <gui_generated/installation_hydraulique_screen/Installation_hydrauliqueViewBase.hpp>
#include <gui/installation_hydraulique_screen/Installation_hydrauliquePresenter.hpp>

class Installation_hydrauliqueView : public Installation_hydrauliqueViewBase
{
public:
    Installation_hydrauliqueView();
    virtual ~Installation_hydrauliqueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_HYDRAULIQUEVIEW_HPP
