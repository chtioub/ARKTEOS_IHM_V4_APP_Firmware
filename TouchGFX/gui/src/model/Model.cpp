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
    modelListener->changeModePac(cosebe_rx.bModePAC);
    dataUpdated = 0;
  }
}

void Model::energieState(uint16_t state)
{
  if(state != cosebe_tx.u16Data)
  {
    cosebe_tx.u16Data = state;
    sendData = 1;
  }
}
