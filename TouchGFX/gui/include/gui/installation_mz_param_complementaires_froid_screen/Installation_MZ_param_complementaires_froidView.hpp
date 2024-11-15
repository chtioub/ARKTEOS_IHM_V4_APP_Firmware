#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP

#include <gui_generated/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidViewBase.hpp>
#include <gui/installation_mz_param_complementaires_froid_screen/Installation_MZ_param_complementaires_froidPresenter.hpp>

class Installation_MZ_param_complementaires_froidView : public Installation_MZ_param_complementaires_froidViewBase
{
public:
    Installation_MZ_param_complementaires_froidView();
    virtual ~Installation_MZ_param_complementaires_froidView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDVIEW_HPP
