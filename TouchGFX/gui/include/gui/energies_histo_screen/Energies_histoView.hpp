#ifndef ENERGIES_HISTOVIEW_HPP
#define ENERGIES_HISTOVIEW_HPP

#include <gui_generated/energies_histo_screen/Energies_histoViewBase.hpp>
#include <gui/energies_histo_screen/Energies_histoPresenter.hpp>

class Energies_histoView : public Energies_histoViewBase
{
public:
    Energies_histoView();
    virtual ~Energies_histoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ENERGIES_HISTOVIEW_HPP
