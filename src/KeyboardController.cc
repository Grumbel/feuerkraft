//  $Id: KeyboardController.cc,v 1.4 2001/02/21 07:54:33 grumbel Exp $
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

#include <ClanLib/core.h>
#include "Tank.hh"
#include "Turret.hh"
#include "KeyboardController.hh"

void
KeyboardController::update (float delta)
{
  if (CL_Keyboard::get_keycode (CL_KEY_F))
    controllable->turn_left2 (delta);
  else if (CL_Keyboard::get_keycode (CL_KEY_S))
    controllable->turn_right2 (delta);
  
  if (CL_Keyboard::get_keycode (CL_KEY_RIGHT))
    controllable->turn_left (delta);
  else if (CL_Keyboard::get_keycode (CL_KEY_LEFT))
    controllable->turn_right (delta);
        
  if (CL_Keyboard::get_keycode (CL_KEY_UP))
    controllable->increase_velocity (delta);
  else if (CL_Keyboard::get_keycode (CL_KEY_DOWN))
    controllable->decrease_velocity (delta);

  if (CL_Keyboard::get_keycode (CL_KEY_E))
    controllable->drop_mine ();

  if (CL_Keyboard::get_keycode (CL_KEY_D))
    controllable->start_fire ();
  else
    controllable->stop_fire ();
}

/* EOF */
