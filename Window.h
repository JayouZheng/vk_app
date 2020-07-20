﻿//
// Window.h
//

#pragma once

#include "Platform.h"
#include <cstdint>

#if VK_USE_PLATFORM_WIN32_KHR

class Window
{

public:

	struct WindowDesc
	{		
		uint32_t Width;
		uint32_t Height;
	};

public:

	Window();
	Window(const WindowDesc& InWindoWDesc);
	~Window();

public:

	void* GetHinstance() const;
	void* GetHwnd() const;

	WindowDesc GetWindowDesc() const;
	void SetWindowDesc(const WindowDesc& InWindoWDesc);

	void Show();

protected:

	void* m_hinstance = nullptr;
	void* m_hwnd = nullptr;

	WindowDesc m_defaultDesc = 
	{
		1280,
		720
	};
};

#endif