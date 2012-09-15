/*
 *      Copyright (C) 2010-2012 Hendrik Leppkes
 *      http://www.1f0.de
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include "DeCSS/DeCSSInputPin.h"
#include "SubRenderIntf.h"

#include "LAVSubtitleProvider.h"

class CLAVVideoSubtitleInputPin : public CBaseInputPin, public CDeCSSPinHelper
{
public:
  CLAVVideoSubtitleInputPin(TCHAR* pObjectName, CBaseFilter* pFilter, CCritSec *pcsFilter, HRESULT* phr, LPWSTR pName);
  ~CLAVVideoSubtitleInputPin(void);

  DECLARE_IUNKNOWN
  STDMETHODIMP NonDelegatingQueryInterface(REFIID riid, void** ppv);

  // IMemInputPin
  STDMETHODIMP Receive(IMediaSample* pSample);

  // CBasePin
  HRESULT CheckMediaType(const CMediaType *mtIn);

  HRESULT CreateSubtitleProvider(ISubRenderConsumer *pConsumer);

protected:
  CCritSec m_csReceive;

  CLAVSubtitleProvider *m_pProvider;
};