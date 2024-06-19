#ifndef USINE_CHOIX_MODELE_PACVIEW_HPP
#define USINE_CHOIX_MODELE_PACVIEW_HPP

#include <gui_generated/usine_choix_modele_pac_screen/Usine_choix_modele_pacViewBase.hpp>
#include <gui/usine_choix_modele_pac_screen/Usine_choix_modele_pacPresenter.hpp>

class Usine_choix_modele_pacView : public Usine_choix_modele_pacViewBase
{
public:
    Usine_choix_modele_pacView();
    virtual ~Usine_choix_modele_pacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CHOIX_MODELE_PACVIEW_HPP
