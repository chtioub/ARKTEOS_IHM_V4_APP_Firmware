#ifndef INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP
#define INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP

#include <gui_generated/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesViewBase.hpp>
#include <gui/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesPresenter.hpp>

class Installation_MZ_parametrage_groupesView : public Installation_MZ_parametrage_groupesViewBase
{
public:
    Installation_MZ_parametrage_groupesView();
    virtual ~Installation_MZ_parametrage_groupesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP
