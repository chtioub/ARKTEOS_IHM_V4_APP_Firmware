#include <gui/containers/Message.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Message::Message()
{

}

void Message::initialize()
{
    MessageBase::initialize();
}

void Message::titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_titre_message.setWildcard(textArea_Buffer);
	textArea_titre_message.setTypedText(touchgfx::TypedText(T_TEXT_MESSAGE_TITRE));
	textArea_titre_message.invalidate();
}

void Message::message(touchgfx::Unicode::UnicodeChar *textArea_Buffer)
{
	textArea_message_info.setWildcard(textArea_Buffer);
	textArea_message_info.setTypedText(touchgfx::TypedText(T_TEXT_MESSAGE_MESSAGE));
	textArea_message_info.invalidate();
}


