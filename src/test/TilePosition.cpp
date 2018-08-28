/*
 * TilePosition.cpp
 * 
 * @author Chocorean
 */

#include "TilePosition.h"

using namespace std;

TilePosition::TilePosition() : m_x(0), m_y(0)
{
  
}

TilePosition::TilePosition(int x, int y)
{
  m_x = x >= 0 ? x : 0;
  m_y = y >= 0 ? y : 0;
}

TilePosition::~TilePosition()
{

}

/* Getters */
int TilePosition::getX()
{
  return m_x;
}

int TilePosition::getY()
{
  return m_y;
}

/* Adjacent positions */
TilePosition *TilePosition::north()
{
  return new TilePosition(m_x, m_y-1);
}
TilePosition *TilePosition::south()
{
  return new TilePosition(m_x, m_y+1);
}
TilePosition *TilePosition::east()
{
  return new TilePosition(m_x+1, m_y);
}
TilePosition *TilePosition::west()
{
  return new TilePosition(m_x-1, m_y);
}
