#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <gui_generated/containers/MessageBase.hpp>

class Message : public MessageBase
{
public:
    Message();
    virtual ~Message() {}

    virtual void initialize();
    void titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
    void message(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
protected:
};

#endif // MESSAGE_HPP
