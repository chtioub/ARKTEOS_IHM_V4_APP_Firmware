#ifndef COURBE_LOI_D_EAUVIEW_HPP
#define COURBE_LOI_D_EAUVIEW_HPP

#include <gui_generated/courbe_loi_d_eau_screen/Courbe_loi_d_eauViewBase.hpp>
#include <gui/courbe_loi_d_eau_screen/Courbe_loi_d_eauPresenter.hpp>

class Courbe_loi_d_eauView : public Courbe_loi_d_eauViewBase
{
public:
    Courbe_loi_d_eauView();
    virtual ~Courbe_loi_d_eauView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // COURBE_LOI_D_EAUVIEW_HPP
