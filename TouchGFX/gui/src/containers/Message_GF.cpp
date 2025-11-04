#include <gui/containers/Message_GF.hpp>

Message_GF::Message_GF()
{

}

void Message_GF::initialize()
{
    Message_GFBase::initialize();
}

void Message_GF::titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_titre_message.setWildcard(textArea_Buffer);
	textArea_titre_message.setTypedText(touchgfx::TypedText(T_TEXT_MESSAGE_TITRE));
	textArea_titre_message.invalidate();
}

void Message_GF::message(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_message_info.setWildcard(textArea_Buffer);
	textArea_message_info.setTypedText(touchgfx::TypedText(T_TEXT_MESSAGE_MESSAGE));
	textArea_message_info.invalidate();
}
