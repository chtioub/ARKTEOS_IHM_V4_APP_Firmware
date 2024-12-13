#include <gui/installation_hysteresis_screen/Installation_hysteresisView.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <math.h>

Installation_hysteresisView::Installation_hysteresisView()
{
	u16ValMin = 0;
	u16ValMax = 100;
	i16OffsetFleGau = -4;
	i16OffsetFleDro = -6;
	i16OffsetLblMoins = 14;
	i16OffsetLblPlus = 11;
}

void Installation_hysteresisView::setupScreen()
{
    Installation_hysteresisViewBase::setupScreen();
}

void Installation_hysteresisView::tearDownScreen()
{
    Installation_hysteresisViewBase::tearDownScreen();
}

void Installation_hysteresisView::Slider_Plus(int valSlid)
{
	if (slider_hyst_moins.getValue() > valSlid - 2)
	{
		slider_hyst_moins.setValue(valSlid - 2);
	}
//	slider_hyst_plus.setValue(slider_hyst_plus.getValue());
//	slider_hyst_plus.invalidate();

	lineV_hyst_plus.setVisible(false);
	lineV_hyst_plus.invalidate();
	lineV_hyst_plus.setStart(((valSlid + 40) *10)+2, 0);//+2 ajouté
	lineV_hyst_plus.setEnd(((valSlid + 40) *10)+2, 186);//+2 ajouté
	lineV_hyst_plus.setVisible(true);
	lineV_hyst_plus.invalidate();

	lineH_hyst_haute.setVisible(false);
	lineH_hyst_basse.setVisible(false);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	int xval = 0;
	int yval = 0;
	lineV_hyst_moins.getStart(xval,yval);
	lineH_hyst_haute.setStart(xval, 0);
	lineH_hyst_haute.setEnd(((valSlid + 40) *10) + 0/*3*/, 0);
	lineH_hyst_basse.setStart(xval, 0);
	lineH_hyst_basse.setEnd(((valSlid + 40) *10) + 3, 0);

	lineH_hyst_haute.setVisible(true);
	lineH_hyst_basse.setVisible(true);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	textArea_hyst_plus.setVisible(false);
	fleche_droite.setVisible(false);
	textArea_hyst_plus.invalidate();
	fleche_droite.invalidate();

	Unicode::snprintfFloat(textAreaBuffer_hyst_plus, 5, "%.1f", ((float)(valSlid))/10);
	textArea_hyst_plus.setWildcard(textAreaBuffer_hyst_plus);
	textArea_hyst_plus.setX(((valSlid + 40) *10 )+ 35 + 3);
	fleche_droite.setX(((valSlid + 40)* 10)- 5);//-6

	textArea_hyst_plus.setVisible(true);
	fleche_droite.setVisible(true);
	textArea_hyst_plus.invalidate();
	fleche_droite.invalidate();
}

void Installation_hysteresisView::Slider_Moins(int valSlid)
{
	if (slider_hyst_plus.getValue() < valSlid + 2)
	{
		slider_hyst_plus.setValue(valSlid + 2);
	}

	lineV_hyst_moins.setVisible(false);
	lineV_hyst_moins.invalidate();
	//lineV_hyst_moins.setPosition((valSlid * 8) + 21, 26, (valSlid * 8) + 21,186);
	lineV_hyst_moins.setStart(((valSlid +40) * 10) + 3, 0);//, 26);//, (valSlid * 8) + 21,186);
	lineV_hyst_moins.setEnd(((valSlid +40) * 10) + 3, 186);
	lineV_hyst_moins.setVisible(true);
	lineV_hyst_moins.invalidate();

	lineH_hyst_haute.setVisible(false);
	lineH_hyst_basse.setVisible(false);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	int xval = 0;
	int yval = 0;
	lineV_hyst_plus.getStart(xval,yval);
	lineH_hyst_haute.setEnd(xval, 0);
	lineH_hyst_haute.setStart(((valSlid +40) * 10) + 0/*3*/, 0);
	lineH_hyst_basse.setEnd(xval, 0);
	lineH_hyst_basse.setStart(((valSlid +40) * 10) + 4, 0);

	lineH_hyst_haute.setVisible(true);
	lineH_hyst_basse.setVisible(true);
	lineH_hyst_haute.invalidate();
	lineH_hyst_basse.invalidate();
	textArea_hyst_moins.setVisible(false);
	fleche_gauche.setVisible(false);
	textArea_hyst_moins.invalidate();
	fleche_gauche.invalidate();

//	textArea_hyst_plus.setVisible(false);
//	fleche_droite.setVisible(false);
//	textArea_hyst_plus.invalidate();
//	fleche_droite.invalidate();

	Unicode::snprintfFloat(textAreaBuffer_hyst_moins, 5, "%.1f", ((float)(valSlid))/10);
	textArea_hyst_moins.setWildcard(textAreaBuffer_hyst_moins);
	textArea_hyst_moins.setX(((valSlid + 40) *10 )+ 35 + 3);
	fleche_gauche.setX(((valSlid + 40)* 10)- 4/*6*/);//+ 6);-3

	textArea_hyst_moins.setVisible(true);
	fleche_gauche.setVisible(true);
	textArea_hyst_moins.invalidate();
	fleche_gauche.invalidate();

//	textArea_hyst_plus.setVisible(true);
//	fleche_droite.setVisible(true);
//	textArea_hyst_plus.invalidate();
//	fleche_droite.invalidate();

}



//void Installation_hysteresisView::Slid_Plus_Show()
//{
//	slider_hysteresis_moins.setVisible(false);
//	slider_hysteresis_plus.setVisible(true);
//	slider_hysteresis_moins.invalidate();
//	slider_hysteresis_plus.invalidate();
//}
//
//void Installation_hysteresisView::Slid_Moins_Show()
//{
//	slider_hysteresis_plus.setVisible(false);
//	slider_hysteresis_moins.setVisible(true);
//	slider_hysteresis_moins.invalidate();
//	slider_hysteresis_plus.invalidate();
//}
//
//void Installation_hysteresisView::Red_Butt()
//{
//
//	red_butt.setVisible(false);
//	red_butt.invalidate();
//	red_butt.setY(350);
//
//
//	if (red_butt.getX()<= (blue_butt.getX()+200))
//	{
//		red_butt.setX(blue_butt.getX()+200);
//	}
//	else if (red_butt.getX() >= 800)
//	{
//		red_butt.setX(800);
//	}
//
//	red_butt.setVisible(true);
//	red_butt.invalidate();
//	red_butt.setY(350);
//}
//
//void Installation_hysteresisView::Blue_Butt()
//{
//
//	blue_butt.setVisible(false);
//	blue_butt.invalidate();
//	blue_butt.setY(350);
//	if ((red_butt.getX()-200) <= blue_butt.getX())
//	{
//		blue_butt.setX(red_butt.getX()-200);
//	}
//	else if (blue_butt.getX() <= 100)
//	{
//		blue_butt.setX(100);
//	}
//
//	blue_butt.setVisible(true);
//	blue_butt.invalidate();
//	blue_butt.setY(350);
//
//
////	red_butt.setVisible(false);
////	red_butt.invalidate();
////	if (red_butt.getX() > 800)
////	{
////		red_butt.setX(800);
////	}
////	red_butt.setVisible(true);
////	red_butt.invalidate();
//}
