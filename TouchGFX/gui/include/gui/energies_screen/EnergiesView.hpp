#ifndef ENERGIESVIEW_HPP
#define ENERGIESVIEW_HPP

#include <gui_generated/energies_screen/EnergiesViewBase.hpp>
#include <gui/energies_screen/EnergiesPresenter.hpp>

class EnergiesView : public EnergiesViewBase
{
public:
    EnergiesView();
    virtual ~EnergiesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[25];
};

#endif // ENERGIESVIEW_HPP
