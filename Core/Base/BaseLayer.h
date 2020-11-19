﻿//
// BaseLayer.h
//

#pragma once

#include "Core/Common.h"

class BaseAllocator;
class LogicalDevice;
class Window;

class BaseLayer : public IResourceHandler
{
	// PD means Physical Device.
	// QF means Queue Family.
	_declare_create_interface(BaseLayer)

protected:

	// Physical device infos.
	std::vector<VkPhysicalDevice>                     m_physicalDevices;
	std::vector<VkPhysicalDeviceProperties>           m_physicalDevicesProps;
	std::vector<VkPhysicalDeviceFeatures2>            m_physicalDevicesFeatures;
	std::vector<VkPhysicalDeviceVulkan12Features>     m_PDVulkan12Features;
	std::vector<VkPhysicalDeviceMemoryProperties>     m_physicalDevicesMemProps;

	// Queue family props.
	std::vector<std::vector<VkQueueFamilyProperties>> m_queueFamilyProps;

	// Layers & Extensions.
	std::vector<VkLayerProperties>                    m_instanceLayerProps;
	std::vector<std::vector<VkLayerProperties>>       m_PDLayerProps;
	std::vector<VkExtensionProperties>                m_instanceExtProps;
	std::vector<std::vector<VkExtensionProperties>>   m_PDExtProps;

	// Support Extensions.
	std::vector<const char*>                          m_supportInsExts;
	std::vector<const char*>                          m_supportPDExts;

	// Support Layers.
	std::vector<const char*>                          m_supportInsLayers;
	std::vector<const char*>                          m_supportPDLayers;

	// Surface Support Format KHR.
	std::vector<VkSurfaceFormatKHR>                   m_surfaceFormats;

	// Required PD Features.
	VkPhysicalDeviceFeatures2                         m_requiredPDFeatures;
	VkPhysicalDeviceVulkan12Features                  m_requiredPDVk12Features;

	// Surface Capabilities KHR.
	VkSurfaceCapabilitiesKHR                          m_surfaceCapabilities;

	// Swapchain Create Info KHR.
	VkSwapchainCreateInfoKHR                          m_swapchainCreateInfo; // Cached for using when window resize.

	// std::vector<VkDisplayPropertiesKHR>            m_displayProps;  // No Display...

protected:

	BaseAllocator*                                    m_pAllocator;
	LogicalDevice*                                    m_pDevice;
	Window*                                           m_pWindow;

	int32                                             m_mainPDIndex;
	int32                                             m_mainQFIndex;

	// Swapchain Image.
	std::vector<VkImage>                              m_swapchainImages;

	_declare_vk_smart_ptr(VkSurfaceKHR,   m_pSurface);
	_declare_vk_smart_ptr(VkSwapchainKHR, m_pSwapchainKHR);

protected:

	BaseLayer();

	VkAllocationCallbacks* GetVkAllocator() const;
	void Free();

public:

	virtual ~BaseLayer();

	bool Init();
	void CachedModulePath();

	void SetBaseAllocator(BaseAllocator* InAllocator);

	uint32 GetHeapIndexFromMemPropFlags(
		const VkMemoryRequirements& InMemRequirements,
		VkMemoryPropertyFlags InPreferredFlags,
		VkMemoryPropertyFlags InRequiredFlags);

	LogicalDevice*                     GetLogicalDevice() const;
	const VkPhysicalDeviceLimits&      GetMainPDLimits () const;
	const VkPhysicalDeviceProperties&  GetMainPDProps  () const;

	// Query physical device supported buffer/image formats.
	void CheckFormatSupport(const std::vector<VkFormat>& InCheckFormats, std::vector<VkFormatProperties>& OutFormatProps);

	struct SCheckImage
	{
		VkFormat           format;
		VkImageType        type;
		VkImageTiling      tiling;
		VkImageUsageFlags  usage;
		VkImageCreateFlags flags;
	};

	void CheckImageFormatSupport(const std::vector<SCheckImage>& InCheckImages, std::vector<VkImageFormatProperties>& OutImageFormatProps);
};