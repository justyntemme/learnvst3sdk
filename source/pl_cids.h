//------------------------------------------------------------------------
// Copyright(c) 2023 My Plug-in Company.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID klearnVST3ProcessorUID (0xCA217282, 0xF4315EE3, 0x943633B4, 0x67AF7A92);
static const Steinberg::FUID klearnVST3ControllerUID (0xF32AAED8, 0xD4175A48, 0x805B78C4, 0x09DD51D5);

#define learnVST3VST3Category "Fx"

//------------------------------------------------------------------------
} // namespace MyCompanyName
