//------------------------------------------------------------------------
// Copyright(c) 2023 My Plug-in Company.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID kLearnVst3ProcessorUID (0xFE309CB9, 0xF8DD5735, 0x8469C147, 0x37E10FA5);
static const Steinberg::FUID kLearnVst3ControllerUID (0x30ACC3C4, 0x75D75F13, 0x82F1D117, 0xC54D9B2D);

#define LearnVst3VST3Category "Fx"

//------------------------------------------------------------------------
} // namespace MyCompanyName
