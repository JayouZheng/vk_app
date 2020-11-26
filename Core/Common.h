﻿/*********************************************************************
 *  Common.h
 *  Copyright (C) 2020 Jayou. All Rights Reserved.
 * 
 *  .
 *********************************************************************/

#pragma once

#include "Core/Platform/Platform.h"

#include "vulkan/vulkan.hpp"
#pragma comment(lib, "vulkan-1.lib")

#include "Core/TypeDef.h"
#include "Core/Exception.h"
#include "Core/Utility/LogSystem.h"
#include "Core/SmartPtr/SmartPtr.h"
#include "Core/SmartPtr/VkSmartPtr.h"
#include "Core/Utility/Parser/PathParser.h"
#include "Core/Base/Interface/IResourceHandler.h"
#include "Core/Utility/MemoryLeakCheck.h"
