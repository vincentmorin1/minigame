#include "Logger.h"
#include "TilePosition.h"
#include "CastUtils.h"

using namespace std;

int main()
{
  Logger(INFO) << "Beginning tests.";
  TilePosition pos;
  Logger(INFO) << "Tests completed.";
}