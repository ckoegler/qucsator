/*
 * isolator.cpp - isolator class implementation
 *
 * Copyright (C) 2003, 2004 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.  
 *
 * $Id: isolator.cpp,v 1.5 2004-04-04 09:11:06 ela Exp $
 *
 */

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "object.h"
#include "node.h"
#include "circuit.h"
#include "component_id.h"
#include "isolator.h"

isolator::isolator () : circuit (2) {
  setS (1, 2, 0.0);
  type = CIR_ISOLATOR;
  setVoltageSources (2);
}

void isolator::calcSP (nr_double_t) {
  nr_double_t z1 = getPropertyDouble ("Z1");
  nr_double_t z2 = getPropertyDouble ("Z2");
  nr_double_t s1 = (z1 - z0) / (z1 + z0);
  nr_double_t s2 = (z2 - z0) / (z2 + z0);
  setS (1, 1, s1);
  setS (2, 2, s2);
  setS (2, 1, sqrt (1 - s1 * s1) * sqrt (1 - s2 * s2));
}

void isolator::calcDC (void) {
  nr_double_t z1 = getPropertyDouble ("Z1");
  nr_double_t z2 = getPropertyDouble ("Z2");
  nr_double_t z21 = 2 * sqrt (z1 * z2);
  setB (1, 1, +1.0); setB (1, 2, +0.0); setB (2, 1, +0.0); setB (2, 2, +1.0);
  setC (1, 1, -1.0); setC (1, 2, +0.0); setC (2, 1, +0.0); setC (2, 2, -1.0); 
  setD (1, 1,  +z1); setD (2, 2,  +z2); setD (1, 2, +0.0); setD (2, 1, +z21);
  setE (1, +0.0); setE (2, +0.0);
}
