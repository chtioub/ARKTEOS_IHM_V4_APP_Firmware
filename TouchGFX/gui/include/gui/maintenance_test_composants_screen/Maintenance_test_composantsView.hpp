#ifndef MAINTENANCE_TEST_COMPOSANTSVIEW_HPP
#define MAINTENANCE_TEST_COMPOSANTSVIEW_HPP

#include <gui_generated/maintenance_test_composants_screen/Maintenance_test_composantsViewBase.hpp>
#include <gui/maintenance_test_composants_screen/Maintenance_test_composantsPresenter.hpp>

class Maintenance_test_composantsView : public Maintenance_test_composantsViewBase
{
public:
    Maintenance_test_composantsView();
    virtual ~Maintenance_test_composantsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCE_TEST_COMPOSANTSVIEW_HPP
