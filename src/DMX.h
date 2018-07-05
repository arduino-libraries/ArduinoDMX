/*
  This file is part of the DMX library.
  Copyright (C) 2018  Arduino AG (http://www.arduino.cc/)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _DMX_H_INCLUDED
#define _DMX_H_INCLUDED

#include <Arduino.h>

#define DMX_MAX_SLOTS 512

class DMXClass {
  public:
    DMXClass();

    int begin(int universeSize = DMX_MAX_SLOTS);
    void end();

    int beginTransmission();
    int write(int address, byte value);
    int write(byte value);
    int writeAll(byte value);
    int endTransmission();

  private:
    int _universeSize;
    byte _values[1 + DMX_MAX_SLOTS];
    int _address;
    bool _transmissionBegin;
};

extern DMXClass DMX;

#endif
