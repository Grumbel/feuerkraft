//  $Id: custom_building.cxx,v 1.7 2003/06/03 14:11:22 grumbel Exp $
//
//  Feuerkraft - A Tank Battle Game
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
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

#include "../alist.hxx"
#include "../resource_manager.hxx"
#include "custom_building.hxx"

CustomBuilding::CustomBuilding(const AList& type, const AList& lst)
{
  std::string sprite_str = "feuerkraft/nobuilding";
  int         i_energie = 100;
  width   = 2;
  height  = 2;

  type.get_string("sprite", sprite_str);
  type.get_int("energie", i_energie);
  type.get_int("width", width);
  type.get_int("height", height);

  energie.set_max_energie(i_energie);

  sprite = resources->get_sprite(sprite_str);

  lst.get_int("x-pos", x_pos);
  lst.get_int("y-pos", y_pos);
}

void
CustomBuilding::draw(View& view)
{
  view.draw(sprite, FloatVector2d(x_pos * 40 + get_map_width()*20, 
                                  y_pos * 40 + get_map_height()*20)); // FIXME: Hardcoded tilesize
}

void
CustomBuilding::draw_energie(View& view)
{
  energie.draw(view, x_pos*40 + get_map_width()*20, (y_pos*40));
}

void
CustomBuilding::update(float)
{
}

void
CustomBuilding::collide (Projectile*)
{
  energie -= 5;
}

/* EOF */
