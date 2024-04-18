#ifndef ENERGIES_CUMULVIEW_HPP
#define ENERGIES_CUMULVIEW_HPP

#include <gui_generated/energies_cumul_screen/Energies_cumulViewBase.hpp>
#include <gui/energies_cumul_screen/Energies_cumulPresenter.hpp>

class Energies_cumulView : public Energies_cumulViewBase
{
public:
    Energies_cumulView();
    virtual ~Energies_cumulView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ENERGIES_CUMULVIEW_HPP
