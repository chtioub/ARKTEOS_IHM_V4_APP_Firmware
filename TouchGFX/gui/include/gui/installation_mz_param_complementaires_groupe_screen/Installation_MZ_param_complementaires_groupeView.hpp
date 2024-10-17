#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP

#include <gui_generated/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupeViewBase.hpp>
#include <gui/installation_mz_param_complementaires_groupe_screen/Installation_MZ_param_complementaires_groupePresenter.hpp>

class Installation_MZ_param_complementaires_groupeView : public Installation_MZ_param_complementaires_groupeViewBase
{
public:
    Installation_MZ_param_complementaires_groupeView();
    virtual ~Installation_MZ_param_complementaires_groupeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_GROUPEVIEW_HPP
