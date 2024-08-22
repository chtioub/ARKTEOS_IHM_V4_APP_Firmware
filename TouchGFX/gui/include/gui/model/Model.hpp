#ifndef MODEL_HPP
#define MODEL_HPP

#include <texts/TextKeysAndLanguages.hpp>
#include "arkteos_var_commune.h"
#include "arkteos_defauts.h"
#include "IHM_V4.h"

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
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
