/*
 * parasweep.h - parameter sweep class definitions
 *
 * Copyright (C) 2004 Stefan Jahn <stefan@lkcc.org>
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
 * $Id: parasweep.h,v 1.2 2004/04/13 20:41:17 ela Exp $
 *
 */

#ifndef __PARASWEEP_H__
#define __PARASWEEP_H__

class analysis;
class variable;

class parasweep : public analysis
{
 public:
  parasweep ();
  parasweep (char *);
  parasweep (parasweep &);
  ~parasweep ();
  void solve (void);
  void saveResults (void);

 private:
  variable * var;
  int runs;
};

#endif /* __PARASWEEP_H__ */