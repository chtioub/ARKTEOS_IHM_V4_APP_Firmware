#ifndef INSTALLATION_CHAUFFE_DALLEVIEW_HPP
#define INSTALLATION_CHAUFFE_DALLEVIEW_HPP

#include <gui_generated/installation_chauffe_dalle_screen/Installation_chauffe_dalleViewBase.hpp>
#include <gui/installation_chauffe_dalle_screen/Installation_chauffe_dallePresenter.hpp>

class Installation_chauffe_dalleView : public Installation_chauffe_dalleViewBase
{
public:
    Installation_chauffe_dalleView();
    virtual ~Installation_chauffe_dalleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CHAUFFE_DALLEVIEW_HPP
