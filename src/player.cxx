//  $Id: player.cxx,v 1.4 2003/06/04 13:10:09 grumbel Exp $
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

#include <assert.h>
#include "player.hxx"

Player::Player(Unit* arg_unit)
{
  set_current_unit(arg_unit);
}

void
Player::set_current_unit(Unit* arg_unit)
{
  unit = arg_unit;
}

Unit*
Player::get_current_unit()
{
  assert(unit);
  return unit;
}

/* EOF */
