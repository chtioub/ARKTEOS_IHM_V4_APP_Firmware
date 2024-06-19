#ifndef INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
#define INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP

#include <gui_generated/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauViewBase.hpp>
#include <gui/installation_courbe_loi_d_eau_screen/Installation_courbe_loi_d_eauPresenter.hpp>

class Installation_courbe_loi_d_eauView : public Installation_courbe_loi_d_eauViewBase
{
public:
    Installation_courbe_loi_d_eauView();
    virtual ~Installation_courbe_loi_d_eauView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_COURBE_LOI_D_EAUVIEW_HPP
