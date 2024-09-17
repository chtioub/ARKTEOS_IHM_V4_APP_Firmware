#include <gui/veille_screen/VeilleView.hpp>

VeilleView::VeilleView() :
    BackgroundClickedCallback(this, &VeilleView::BackgroundClickHandler)
{

}

void VeilleView::setupScreen()
{
  VeilleViewBase::setupScreen();
  Background.setClickAction(BackgroundClickedCallback);
  presenter->enterVeille();
//    box.setClickAction(boxClickedCallback);
}

void VeilleView::tearDownScreen()
{
  VeilleViewBase::tearDownScreen();
  presenter->exitVeille();
}

void VeilleView::BackgroundClickHandler(const Box &b, const ClickEvent &evt)
{
  if(&b == &Background)
  {
    application().gotoAccueilScreenNoTransition();
  }
}
