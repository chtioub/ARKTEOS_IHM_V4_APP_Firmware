#include <gui/accueil_screen/AccueilView.hpp>

AccueilView::AccueilView() :
        swipeCallback(this, &AccueilView::swipeCallbackHandler)
{
    swipeDetectContainerMainScreen.setAction(swipeCallback);
}

void AccueilView::setupScreen()
{
    AccueilViewBase::setupScreen();
}

void AccueilView::tearDownScreen()
{
    AccueilViewBase::tearDownScreen();
}

void AccueilView::swipeCallbackHandler(int16_t velocity)
{
    if(velocity < 0)
    {
        application().gotoConfigurationScreenNoTransition();
    }
}
