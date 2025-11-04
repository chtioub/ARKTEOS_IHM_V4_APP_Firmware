#ifndef MESSAGE_GF_HPP
#define MESSAGE_GF_HPP

#include <gui_generated/containers/Message_GFBase.hpp>

class Message_GF : public Message_GFBase
{
public:
    Message_GF();
    virtual ~Message_GF() {}

    virtual void initialize();
    void titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
    void message(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
protected:
};

#endif // MESSAGE_GF_HPP
