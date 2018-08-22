#include "CastUtils.h"

using namespace std;

string intToStr(int oldValue)
{
    std::stringstream ss;
    ss << oldValue;
    string newValue;
    ss >> newValue;
    return newValue;
}