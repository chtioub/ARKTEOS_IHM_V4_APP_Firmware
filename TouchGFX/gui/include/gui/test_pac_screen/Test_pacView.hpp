#ifndef TEST_PACVIEW_HPP
#define TEST_PACVIEW_HPP

#include <gui_generated/test_pac_screen/Test_pacViewBase.hpp>
#include <gui/test_pac_screen/Test_pacPresenter.hpp>

class Test_pacView : public Test_pacViewBase
{
public:
    Test_pacView();
    virtual ~Test_pacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TEST_PACVIEW_HPP
