#include "Logger.h"
#include "TilePosition.h"
#include "CastUtils.h"

using namespace std;

int testTilePosition();

int main()
{
  Logger(INFO) << "Beginning tests.";
  int err = 0;
  if ((err = testTilePosition()) < 0)
  {
    Logger(ERROR) << "Test for TilePosition failed. Error: " << err;
    return -1;
  }
  Logger(INFO) << "Tests completed.";
  return 0;
}

int testTilePosition()
{
  // testing constructors
  TilePosition pos;
  if (pos.getX() != 0 || pos.getY() != 0)
    return -1;
  TilePosition pos2(1, -2);
  if (pos2.getX() != 1 || pos2.getY() != 0)
    return -2;
  // testing adjacent positions
  TilePosition *posNorth = pos2.north();
  if (posNorth->getX() != 1 || posNorth->getY() != 0)
    return -3;
  TilePosition *posSouth = pos2.south();
  if (posSouth->getX() != 1 || posSouth->getY() != 1)
    return -4;
  TilePosition *posEast = pos2.east();
  if (posEast->getX() != 2 || posEast->getY() != 0)
    return -5;
  TilePosition *posWest = pos2.west();
  if (posWest->getX() != 0 || posWest->getY() != 0)
    return -6;
  return 0;
}