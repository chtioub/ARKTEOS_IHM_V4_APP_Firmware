#ifndef INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP

#include <gui_generated/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesViewBase.hpp>
#include <gui/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesPresenter.hpp>

class Installation_hydraulique_message_multizonesView : public Installation_hydraulique_message_multizonesViewBase
{
public:
    Installation_hydraulique_message_multizonesView();
    virtual ~Installation_hydraulique_message_multizonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP
