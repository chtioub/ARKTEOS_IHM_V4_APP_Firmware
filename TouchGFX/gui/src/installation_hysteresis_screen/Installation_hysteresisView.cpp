#include <gui/installation_hysteresis_screen/Installation_hysteresisView.hpp>

Installation_hysteresisView::Installation_hysteresisView()
{

}

void Installation_hysteresisView::setupScreen()
{
    Installation_hysteresisViewBase::setupScreen();
}

void Installation_hysteresisView::tearDownScreen()
{
    Installation_hysteresisViewBase::tearDownScreen();
}

void Installation_hysteresisView::Red_Butt()
{

	red_butt.setVisible(false);
	red_butt.invalidate();
	red_butt.setY(350);


	if (red_butt.getX()<= (blue_butt.getX()+200))
	{
		red_butt.setX(blue_butt.getX()+200);
	}
	else if (red_butt.getX() >= 800)
	{
		red_butt.setX(800);
	}

	red_butt.setVisible(true);
	red_butt.invalidate();
	red_butt.setY(350);
}

void Installation_hysteresisView::Blue_Butt()
{

	blue_butt.setVisible(false);
	blue_butt.invalidate();
	blue_butt.setY(350);
	if ((red_butt.getX()-200) <= blue_butt.getX())
	{
		blue_butt.setX(red_butt.getX()-200);
	}
	else if (blue_butt.getX() <= 100)
	{
		blue_butt.setX(100);
	}

	blue_butt.setVisible(true);
	blue_butt.invalidate();
	blue_butt.setY(350);


//	red_butt.setVisible(false);
//	red_butt.invalidate();
//	if (red_butt.getX() > 800)
//	{
//		red_butt.setX(800);
//	}
//	red_butt.setVisible(true);
//	red_butt.invalidate();
}
