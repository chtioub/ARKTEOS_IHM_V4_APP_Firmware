#include <gui/energies_histo_screen/Energies_histoView.hpp>
#include <gui/energies_histo_screen/Energies_histoPresenter.hpp>

Energies_histoPresenter::Energies_histoPresenter(Energies_histoView& v)
    : view(v)
{

}

void Energies_histoPresenter::activate()
{

}

void Energies_histoPresenter::deactivate()
{

}

void Energies_histoPresenter::energieState(uint16_t state)
{
  model->energieState(state);
}

