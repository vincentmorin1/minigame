/*
 * Tile.h
 * 
 * @author Chocorean
 */

#ifndef TILE_ENTITY_H
#define TILE_ENTITY_H

#include "World.h"
#include "TilePosition.h"

enum TileType
{
  TILE_GRASS,
  TILE_SAND,
  TILE_ROCK
};

class TileEntity
{
  public:
  private:
  protected:
    World *world;
    TileType type;
} TileEntity, Tile;

#endif