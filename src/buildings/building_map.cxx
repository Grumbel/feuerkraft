//  $Id: building_map.cxx,v 1.7 2003/06/03 14:11:22 grumbel Exp $
//
//  Feuerkraft - A Tank Battle Game
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

#include <iostream>
#include "../view.hxx"
#include "building_data.hxx"
#include "building_map.hxx"
#include "building.hxx"

BuildingMap::BuildingMap(const BuildingMapData& data)
  : BuildingMapData (data)
{
  for (std::vector<BuildingData*>::iterator i = buildings_data.begin ();
       i != buildings_data.end ();
       ++i)
    {
      // FIXME: we need probally to pass the GameWorld pointer all
      // FIXME: around
      buildings.push_back((*i)->create ());
    }

  building_map.resize(width * height);
  
  // Clear all pointers in the building map
  for (std::vector<Building*>::iterator i = building_map.begin();
       i != building_map.end();
       ++i)
    {
      *i = NULL;
    }

  // 'Draw' the buildings onto the building_map
  for (std::vector<Building*>::iterator i = buildings.begin();
       i != buildings.end ();
       ++i)
    {
      Building* building = *i;
      
      for (int x = building->get_x_pos();
	   x < building->get_x_pos() + building->get_map_width();
	   ++x)
	{
	  for (int y = building->get_y_pos(); 
	       y < building->get_y_pos() + building->get_map_height();
	       ++y)
	    {
	      if (x >= 0 && x < width && y >= 0 && y < height)
		building_map[(y * width) + x] = building;
	      else
		std::cout << "BuildingMap: Error: building position out of range: " << x << ", " << y << std::endl;
	    }
	}
    }
}

// Draw the object onto the screen
void
BuildingMap::draw (View& view)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->draw (view);
    }
}

void
BuildingMap::draw_energie (View& view)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->draw_energie (view);
    }  
}

void
BuildingMap::draw_radar (Radar& radar)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->draw_radar (radar);
    }  
}
  
// Update the object once a game loop
void
BuildingMap::update (float delta)
{
  for (std::vector<Building*>::iterator i = buildings.begin ();
       i != buildings.end ();
       ++i)
    {
      (*i)->update (delta);
    }
}

Building*
BuildingMap::get_building (const FloatVector2d& pos)
{
  int x = int(pos.x)/40;
  int y = int(pos.y)/40;

  if (pos.x < 0)
    x -= 1;

  if (pos.y < 0)
    y -= 1;

  if (x >= 0 && x < width && y >=0 && y < height)
    {
      Building* b = building_map[(y * width) + x];
      if (b && b->alive () && b->is_active ())
	return b;
      else
	return NULL;
    }
  else
    return NULL;
}

GameObjData*
BuildingMap::get_data ()
{
  // FIXME: No Sync
  return this;
}

void
BuildingMap::add_building(Building* building, int x_pos, int y_pos)
{
  std::cout << "Adding building " << building << " at " << x_pos << ", " << y_pos << std::endl;

  for (int x = x_pos; x < x_pos + building->get_map_width(); ++x)
    {
      for (int y = y_pos; y < y_pos + building->get_map_height(); ++y)
        {
          if (x >= 0 && x < width && y >= 0 && y < height)
            building_map[(y * width) + x] = building;
          else
            std::cout << "BuildingMap: Error: building position out of range: " << x << ", " << y << std::endl;
        }
    }

  buildings.push_back(building);
}

/* EOF */
