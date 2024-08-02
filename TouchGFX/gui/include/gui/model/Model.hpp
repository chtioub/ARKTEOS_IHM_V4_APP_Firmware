#ifndef MODEL_HPP
#define MODEL_HPP

#include <touchgfx/hal/Types.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    void energieState(uint16_t state);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
