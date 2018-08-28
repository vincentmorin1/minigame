#include "CastUtils.h"

using namespace std;

string intToStr(int oldValue)
{
    stringstream ss;
    string newValue;
    ss << oldValue;
    ss >> newValue;
    return newValue;
}