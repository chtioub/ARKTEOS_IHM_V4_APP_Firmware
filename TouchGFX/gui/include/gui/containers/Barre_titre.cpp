#include <gui/containers/Barre_titre.hpp>

Barre_titre::Barre_titre()
{

}

void Barre_titre::initialize()
{
    Barre_titreBase::initialize();
}

void Barre_titre::connexionDistante(bool bConnexionDistante)
{
	Image_conn_distant.setVisible(bConnexionDistante);
	Image_conn_distant.invalidate();
}

void Barre_titre::recupConfig(bool bRecupConfig)
{
	Image_recup_config.setVisible(bRecupConfig);
	Image_recup_config.invalidate();
}

void Barre_titre::titre(uint32_t u32NumeroTitre)
{
	textArea_titre.setTypedText(touchgfx::TypedText(u32NumeroTitre));
	textArea_titre.invalidate();
}

void Barre_titre::sansRetour()
{
	button_retour.setVisible(false);
	button_retour.invalidate();
}

void Barre_titre::sansAccueil()
{
	button_accueil.setVisible(false);
	button_accueil.invalidate();
}

//void Barre_titre::fonctionRetour(void (*funct)())
//{
//	funct();
//}
