#include <gui/containers/DualSlider.hpp>
#include <touchgfx/Color.hpp>
#include <cmath>

using namespace touchgfx;

DualSlider::DualSlider() :
    minLimit(0), maxLimit(100),
    leftValue(20), rightValue(80),
    draggingLeft(false), draggingRight(false)
{
    // Taille du container
    setWidth(500);
    setHeight(40);

    // Barre centrale
    track.setPosition(10, getHeight()/2 - 2, getWidth()-20, 4);
    track.setColor(Color::getColorFromRGB(150,150,150));
    add(track);

    // Poignée gauche
    leftHandle.setPosition(40, getHeight()/2 - 10, 20, 20);
    leftHandle.setColor(Color::getColorFromRGB(255, 0, 0));
    add(leftHandle);

    // Poignée droite
    rightHandle.setPosition(200, getHeight()/2 - 10, 20, 20);
    rightHandle.setColor(Color::getColorFromRGB(0, 0, 255));
    add(rightHandle);

    leftHandle.setTouchable(true);
    rightHandle.setTouchable(true);
    setTouchable(true);   // important aussi pour le container
}

void DualSlider::setLimits(int minVal, int maxVal)
{
    minLimit = minVal;
    maxLimit = maxVal;
}

void DualSlider::handleDragEvent(const DragEvent& evt)
{
    int x = evt.getNewX();

    // Si on a déjà choisi une poignée
    if (draggingLeft)
    {
        int newX = x - leftHandle.getWidth()/2;
        if (newX < 10) newX = 10;
        if (newX > rightHandle.getX() - leftHandle.getWidth()) newX = rightHandle.getX() - leftHandle.getWidth();

        leftHandle.invalidate();
        leftHandle.setX(newX);
        leftHandle.invalidate();

        leftValue = minLimit + (newX * (maxLimit-minLimit)) / (getWidth()-leftHandle.getWidth());
    }
    else if (draggingRight)
    {
        int newX = x - rightHandle.getWidth()/2;
        if (newX < leftHandle.getX() + leftHandle.getWidth()) newX = leftHandle.getX() + leftHandle.getWidth();
        if (newX > getWidth()-10-rightHandle.getWidth()) newX = getWidth()-10-rightHandle.getWidth();

        rightHandle.invalidate();
        rightHandle.setX(newX);
        rightHandle.invalidate();

        rightValue = minLimit + (newX * (maxLimit-minLimit)) / (getWidth()-rightHandle.getWidth());
    }
    else
    {
        // Première sélection : choisir la poignée la plus proche
        int distLeft = std::abs(x - (leftHandle.getX() + leftHandle.getWidth()/2));
        int distRight = std::abs(x - (rightHandle.getX() + rightHandle.getWidth()/2));
        if (distLeft < distRight)
            draggingLeft = true;
        else
            draggingRight = true;
    }
}

void DualSlider::handleClickEvent(const ClickEvent& evt)
{
    if (evt.getType() == ClickEvent::RELEASED)
    {
        draggingLeft = false;
        draggingRight = false;
    }
}

