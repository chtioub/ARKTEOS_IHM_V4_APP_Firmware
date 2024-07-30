#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "IHM_V4.h"

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
  if(dataUpdated != 0)
  {
    modelListener->changeModePac(cosebe_test.bModePAC);
    dataUpdated = 0;
  }
}
