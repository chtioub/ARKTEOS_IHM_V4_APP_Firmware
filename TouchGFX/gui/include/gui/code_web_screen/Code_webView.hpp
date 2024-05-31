#ifndef CODE_WEBVIEW_HPP
#define CODE_WEBVIEW_HPP

#include <gui_generated/code_web_screen/Code_webViewBase.hpp>
#include <gui/code_web_screen/Code_webPresenter.hpp>

class Code_webView : public Code_webViewBase
{
public:
    Code_webView();
    virtual ~Code_webView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CODE_WEBVIEW_HPP
