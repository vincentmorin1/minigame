/*
 * TilePosition.h
 * 
 * @author Chocorean
 */

#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

class TilePosition
{
  public:
  /* Constructors */
    TilePosition();
    TilePosition(int x, int y);
    ~TilePosition();

    /* GETTERS */
    int getX();
    int getY();
    
    /* Adjacent positions */
    TilePosition *north();
    TilePosition *south();
    TilePosition *east();
    TilePosition *west();
  
  private:
    int m_x, m_y;
};

#endif