#include <gui/position_ecran_screen/Position_ecranView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Position_ecranView::Position_ecranView()
{

}

void Position_ecranView::setupScreen()
{
	// Affichage du titre
    Unicode::snprintf(textAreaBuffer_Titre, 25, touchgfx::TypedText(T_TEXT_PARAMETRES_POSITION_ECRAN_CENTRE_DEFAUT).getText());
    barre_titre.titre(textAreaBuffer_Titre);
    // Init des variables d'offset
    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
    textArea_position.setWildcard2(textAreaBuffer_OffsetY);

    Position_ecranViewBase::setupScreen();
}

void Position_ecranView::tearDownScreen()
{
    Position_ecranViewBase::tearDownScreen();
}

void Position_ecranView::bouton_valider()
{
	application().gotoParametresScreenNoTransition();
}

void Position_ecranView::bouton_droit()
{
	if(container.getX() < (1023 - container.getWidth()))
	{
		container.setX(container.getX() + 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de X
	    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
	    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_gauche()
{
	if(container.getX() > 0)
	{
		container.setX(container.getX() - 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de X
	    Unicode::snprintf(textAreaBuffer_OffsetX, 3, "%d", container.getX());
	    textArea_position.setWildcard1(textAreaBuffer_OffsetX);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_bas()
{
	if(container.getY() < (599 - container.getHeight()))
	{
		container.setY(container.getY() + 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de Y
	    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
	    textArea_position.setWildcard2(textAreaBuffer_OffsetY);
	    textArea_position.invalidate();
	}
}

void Position_ecranView::bouton_haut()
{
	if(container.getY() > 0)
	{
		container.setY(container.getY() - 1);
		Position_ecranView::invalidate();
		// MAJ de la valeur de Y
	    Unicode::snprintf(textAreaBuffer_OffsetY, 3, "%d", container.getY());
	    textArea_position.setWildcard2(textAreaBuffer_OffsetY);
	    textArea_position.invalidate();
	}
}
