#ifndef DUALSLIDER_HPP
#define DUALSLIDER_HPP

#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/events/DragEvent.hpp>

class DualSlider : public touchgfx::Container
{
public:
    DualSlider();

    void setLimits(int minVal, int maxVal);
    int getLeftValue() const { return leftValue; }
    int getRightValue() const { return rightValue; }

    virtual void handleDragEvent(const touchgfx::DragEvent& evt);
    virtual void handleClickEvent(const touchgfx::ClickEvent& evt);

private:
    touchgfx::Box track;
    touchgfx::Box leftHandle;
    touchgfx::Box rightHandle;


    int minLimit;
    int maxLimit;
    int leftValue;
    int rightValue;
    bool draggingLeft;
    bool draggingRight;
};

#endif // DUALSLIDER_HPP
