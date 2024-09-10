#ifndef ATTENTEVIEW_HPP
#define ATTENTEVIEW_HPP

#include <gui_generated/attente_screen/AttenteViewBase.hpp>
#include <gui/attente_screen/AttentePresenter.hpp>

class AttenteView : public AttenteViewBase
{
public:
    AttenteView();
    virtual ~AttenteView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    void Timer_500ms();
protected:
    uint16_t u16CompteurDemarrageSysteme;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_RecupConfig[5];
};

#endif // ATTENTEVIEW_HPP
