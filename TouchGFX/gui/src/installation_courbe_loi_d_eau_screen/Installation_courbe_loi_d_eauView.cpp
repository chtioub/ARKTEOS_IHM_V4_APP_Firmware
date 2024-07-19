#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauView.hpp>

Installation_courbe_loi_d_eauView::Installation_courbe_loi_d_eauView()
{
	u16TermoMAX = 800;
	u16LoiDeau[0] = 400;
	u16LoiDeau[1] = 500;
	u16LoiDeau[2] = 550;
	u16LoiDeau[3] = 600;
	u16LoiDeau[4] = 650;
	u16LoiDeau[5] = 750;
	for(int i = 0; i < 6; i++)
	{
		if(u16LoiDeau[i] > u16TermoMAX)
		{
			u16LoiDeau[i] = (uint16_t) u16TermoMAX;
		}
	}
	slider_20((int) u16LoiDeau[0]);
	slider_text_20_deg.setValue((int) u16LoiDeau[0]);
	slider_15((int) u16LoiDeau[1]);
	slider_text_15_deg.setValue((int) u16LoiDeau[1]);
	slider_10((int) u16LoiDeau[2]);
	slider_text_10_deg.setValue((int) u16LoiDeau[2]);
	slider_0((int) u16LoiDeau[3]);
	slider_text_0_deg.setValue((int) u16LoiDeau[3]);
	slider_m10((int) u16LoiDeau[4]);
	slider_text_m10_deg.setValue((int) u16LoiDeau[4]);
	slider_m25((int) u16LoiDeau[5]);
	slider_text_m25_deg.setValue((int) u16LoiDeau[5]);
}

void Installation_courbe_loi_d_eauView::setupScreen()
{
    Installation_courbe_loi_d_eauViewBase::setupScreen();
}

void Installation_courbe_loi_d_eauView::tearDownScreen()
{
    Installation_courbe_loi_d_eauViewBase::tearDownScreen();
}

void Installation_courbe_loi_d_eauView::slider_20(int sliderValue)
{
	u16LoiDeau[0] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[1])
	{
		slider_text_20_deg.setValue((int) u16LoiDeau[1]);
		slider_text_20_deg.invalidate();
		sliderValue = u16LoiDeau[1];
		u16LoiDeau[0] = u16LoiDeau[1];
	}
	Unicode::snprintf(textAreaBuffer_20, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_1.setWildcard(textAreaBuffer_20);
	textArea_temp_loi_eau_1.invalidate();
	line_loi_eau_1.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));// slider_text_20_deg.getX() + 15.0 + (float) sliderValue * 5.46);
	line_loi_eau_1.invalidate();
}

void Installation_courbe_loi_d_eauView::slider_15(int sliderValue)
{
	u16LoiDeau[1] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[2])
	{
		slider_text_15_deg.setValue((int) u16LoiDeau[2]);
		slider_text_15_deg.invalidate();
		sliderValue = u16LoiDeau[2];
		u16LoiDeau[1] = u16LoiDeau[2];
	}
	// Verif pour éviter le dépassement négatif
	if(sliderValue < u16LoiDeau[0])
	{
		slider_text_15_deg.setValue((int) u16LoiDeau[0]);
		slider_text_15_deg.invalidate();
		sliderValue = u16LoiDeau[0];
		u16LoiDeau[1] = u16LoiDeau[0];
	}
	Unicode::snprintf(textAreaBuffer_15, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_2.setWildcard(textAreaBuffer_15);
	textArea_temp_loi_eau_2.invalidate();
	line_loi_eau_1.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_1.invalidate();
	line_loi_eau_2.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_2.invalidate();
}

void Installation_courbe_loi_d_eauView::slider_10(int sliderValue)
{
	u16LoiDeau[2] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[3])
	{
		slider_text_10_deg.setValue((int) u16LoiDeau[3]);
		slider_text_10_deg.invalidate();
		sliderValue = u16LoiDeau[3];
		u16LoiDeau[2] = u16LoiDeau[3];
	}
	// Verif pour éviter le dépassement négatif
	if(sliderValue < u16LoiDeau[1])
	{
		slider_text_10_deg.setValue((int) u16LoiDeau[1]);
		slider_text_10_deg.invalidate();
		sliderValue = u16LoiDeau[1];
		u16LoiDeau[2] = u16LoiDeau[1];
	}
	Unicode::snprintf(textAreaBuffer_10, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_3.setWildcard(textAreaBuffer_10);
	textArea_temp_loi_eau_3.invalidate();
	line_loi_eau_2.setEnd(89, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_2.invalidate();
	line_loi_eau_3.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_3.invalidate();
}

void Installation_courbe_loi_d_eauView::slider_0(int sliderValue)
{
	u16LoiDeau[3] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[4])
	{
		slider_text_0_deg.setValue((int) u16LoiDeau[4]);
		slider_text_0_deg.invalidate();
		sliderValue = u16LoiDeau[4];
		u16LoiDeau[3] = u16LoiDeau[4];
	}
	// Verif pour éviter le dépassement négatif
	if(sliderValue < u16LoiDeau[2])
	{
		slider_text_0_deg.setValue((int) u16LoiDeau[2]);
		slider_text_0_deg.invalidate();
		sliderValue = u16LoiDeau[2];
		u16LoiDeau[3] = u16LoiDeau[2];
	}
	Unicode::snprintf(textAreaBuffer_0, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_4.setWildcard(textAreaBuffer_0);
	textArea_temp_loi_eau_4.invalidate();
	line_loi_eau_3.setEnd(178, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_3.invalidate();
	line_loi_eau_4.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_4.invalidate();
}

void Installation_courbe_loi_d_eauView::slider_m10(int sliderValue)
{
	u16LoiDeau[4] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16LoiDeau[5])
	{
		slider_text_m10_deg.setValue((int) u16LoiDeau[5]);
		slider_text_m10_deg.invalidate();
		sliderValue = u16LoiDeau[5];
		u16LoiDeau[4] = u16LoiDeau[5];
	}
	// Verif pour éviter le dépassement négatif
	if(sliderValue < u16LoiDeau[3])
	{
		slider_text_m10_deg.setValue((int) u16LoiDeau[3]);
		slider_text_m10_deg.invalidate();
		sliderValue = u16LoiDeau[3];
		u16LoiDeau[4] = u16LoiDeau[3];
	}
	Unicode::snprintf(textAreaBuffer_m10, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_5.setWildcard(textAreaBuffer_m10);
	textArea_temp_loi_eau_5.invalidate();
	line_loi_eau_4.setEnd(178, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_4.invalidate();
	line_loi_eau_5.setStart(0, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_5.invalidate();
}

void Installation_courbe_loi_d_eauView::slider_m25(int sliderValue)
{
	u16LoiDeau[5] = sliderValue;
	// Verif pour éviter le dépassement positif
	if(sliderValue > u16TermoMAX)
	{
		slider_text_m25_deg.setValue((int) u16TermoMAX);
		slider_text_m25_deg.invalidate();
		sliderValue = u16TermoMAX;
		u16LoiDeau[5] = u16TermoMAX;
	}
	// Verif pour éviter le dépassement négatif
	if(sliderValue < u16LoiDeau[4])
	{
		slider_text_m25_deg.setValue((int) u16LoiDeau[4]);
		slider_text_m25_deg.invalidate();
		sliderValue = u16LoiDeau[4];
		u16LoiDeau[5] = u16LoiDeau[4];
	}
	Unicode::snprintf(textAreaBuffer_m25, 3, "%d", (sliderValue / 10));
	textArea_temp_loi_eau_6.setWildcard(textAreaBuffer_m25);
	textArea_temp_loi_eau_6.invalidate();
	line_loi_eau_5.setEnd(272, (int) ((float)328 + 15 - ((float)(sliderValue - 200) *  0.546)));
	line_loi_eau_5.invalidate();
}
