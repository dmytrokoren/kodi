/*
 *      Copyright (C) 2005-2016 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "ProcessInfoIOS.h"
#include "threads/SingleLock.h"

// Override for platform ports
#if defined(TARGET_DARWIN_IOS)

CProcessInfo* CProcessInfo::CreateInstance()
{
  return new CProcessInfoIOS();
}


// base class definitions
CProcessInfoIOS::CProcessInfoIOS()
{

}

CProcessInfoIOS::~CProcessInfoIOS()
{

}

void CProcessInfoIOS::SetSwDeinterlacingMethods()
{
  // first populate with the defaults from base implementation
  CProcessInfo::SetSwDeinterlacingMethods();

  std::list<EINTERLACEMETHOD> methods;
  {
    // get the current methods
    CSingleLock lock(m_videoCodecSection);
    methods = m_deintMethods;
  }

#if defined(TARGET_DARWIN_TVOS)
  // add bob inverteddeinterlacer for tvos
  methods.push_back(EINTERLACEMETHOD::VS_INTERLACEMETHOD_RENDER_BOB_INVERTED);
#else // ios
  // add bob deinterlacer for ios
  methods.push_back(EINTERLACEMETHOD::VS_INTERLACEMETHOD_RENDER_BOB);
#endif

  // update with the new methods list
  UpdateDeinterlacingMethods(methods);
}

#endif

