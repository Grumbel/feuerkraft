//  $Id: TileMap.hxx,v 1.1 2002/03/06 21:50:39 grumbel Exp $
// 
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef TILEMAP_HXX
#define TILEMAP_HXX

#include <vector>
#include "GroundMap.hxx"

class Tile;

class TileMap : public GroundMap
{
private:
  int width;
  int height;

  std::vector<Tile*> tiles;
public:
  /** arg_width and arg_height give the number of tiles in each
      direction, they give *not* the width and height in world
      coordinates. tile_size must be the size of the tiles. */
  TileMap (int arg_width, int arg_height, int tile_size);

  ~TileMap ();

  GroundType get_groundtype (float x, float y);
};

#endif

/* EOF */
