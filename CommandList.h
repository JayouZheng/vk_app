﻿//
// CommandList.h
//

#pragma once

#include "vk_util.h"
#include "Global.h"

class CommandList
{

protected:

	VkCommandBuffer m_cmdBuffer = VK_NULL_HANDLE;

	VkDevice        m_device  = VK_NULL_HANDLE;
	VkCommandPool   m_cmdPool = VK_NULL_HANDLE;

public:

	CommandList(VkDevice InDevice, VkCommandPool InCmdPool);
	virtual ~CommandList();

public:

	VkCommandBuffer GetCmdBuffer() const;

public:

	void Reset();
	void Reset(VkCommandBufferResetFlags InFlags);

	// This func is beyond responsibility of cmdList.
	void ResetPool();

	void Free();

	void Close();

public:

	void CopyBuffer(VkBuffer InSrcBuffer, VkBuffer InDstBuffer);
	void CopyBuffer(VkBuffer InSrcBuffer, VkBuffer InDstBuffer, const VkBufferCopy& InRegions);	
	void CopyBuffer(VkBuffer InSrcBuffer, VkBuffer InDstBuffer, uint32_t InRegionCount, const VkBufferCopy* InRegions);

	void ClearBufferUint32(VkBuffer InBuffer, const uint32_t InValue);
	void ClearBufferFloat (VkBuffer InBuffer, const float    InValue);
	void ClearBufferUint32(VkBuffer InBuffer, VkDeviceSize InOffset, VkDeviceSize InSize, const uint32_t InValue);
	void ClearBufferFloat (VkBuffer InBuffer, VkDeviceSize InOffset, VkDeviceSize InSize, const float    InValue);

	void UpdateBuffer(VkBuffer InBuffer, VkDeviceSize InOffset, VkDeviceSize InSize, const void* InData);


	void 

	void ClearColorImage(VkImage InImage, const float* InClearColor);
	void ClearColorImage(VkImage InImage, const VkClearColorValue* InClearColor);
	void ClearColorImage(VkImage InImage, const VkClearColorValue* InClearColor, const VkImageSubresourceRange& InSubresRange);
	void ClearColorImage(VkImage InImage, const VkClearColorValue* InClearColor, uint32_t InRangeCount, const VkImageSubresourceRange* InSubresRanges);

	void ClearDepthStencilImage(VkImage InImage, float InClearDepthValue, uint32_t InClearStencilValue);
	void ClearDepthStencilImage(VkImage InImage, const VkClearDepthStencilValue* InClearValue);

#pragma region PiplineBarrier

public:

	struct SBufferBarrier
	{
		VkPipelineStageFlags srcStageMask;
		VkPipelineStageFlags dstStageMask;
		VkAccessFlags        srcAccessMask;
		VkAccessFlags        dstAccessMask;
		VkBuffer             buffer;
		VkDeviceSize         offset;
		VkDeviceSize         size;
	};

	struct SImageBarrier
	{
		VkPipelineStageFlags srcStageMask;
		VkPipelineStageFlags dstStageMask;
		VkAccessFlags        srcAccessMask;
		VkAccessFlags        dstAccessMask;
		VkImageLayout        oldLayout;
		VkImageLayout        newLayout;
		VkImage              image;
		VkImageSubresourceRange subresourceRange = Util::ColorSubresRange;
	};

	void ResourceBarriers(
		VkPipelineStageFlags InSrcStageMask,
		VkPipelineStageFlags InDstStageMask,		
		// Memory Barrier.
		uint32_t               InMemBarrierCount,
		const VkMemoryBarrier* InMemBarriers,
		// Buffer Memory Barrier.
		uint32_t                     InBufferMemBarrierCount,
		const VkBufferMemoryBarrier* InBufferMemBarriers,
		// Image Memory Barrier.
		uint32_t                    InImageMemBarrierCount,
		const VkImageMemoryBarrier* InImageMemoryBarriers,
		// Dependency Flags
		VkDependencyFlags           InDependencyFlags = 0);

	void MemoryBarrier(
		VkPipelineStageFlags   InSrcStageMask,
		VkPipelineStageFlags   InDstStageMask,
		const VkMemoryBarrier& InMemBarrier,
		VkDependencyFlags      InDependencyFlags = 0);

	void MemoryBarrier(
		VkPipelineStageFlags   InSrcStageMask,
		VkPipelineStageFlags   InDstStageMask,
		VkAccessFlags          InSrcAccessMask,
		VkAccessFlags          InDstAccessMask,
		VkDependencyFlags      InDependencyFlags = 0);

	void MemoryBarriers(
		VkPipelineStageFlags   InSrcStageMask,
		VkPipelineStageFlags   InDstStageMask,
		uint32_t               InMemBarrierCount,
		const VkMemoryBarrier* InMemBarriers,
		VkDependencyFlags      InDependencyFlags = 0);

	void BufferBarrier(
		VkPipelineStageFlags         InSrcStageMask,
		VkPipelineStageFlags         InDstStageMask,
		const VkBufferMemoryBarrier& InBufferMemBarrier,
		VkDependencyFlags            InDependencyFlags = 0);

	void BufferBarrier(const SBufferBarrier& InSBufferBarrier, VkDependencyFlags InDependencyFlags = 0);

	void BufferBarriers(
		VkPipelineStageFlags         InSrcStageMask,
		VkPipelineStageFlags         InDstStageMask,
		uint32_t                     InBufferMemBarrierCount,
		const VkBufferMemoryBarrier* InBufferMemBarriers,
		VkDependencyFlags            InDependencyFlags = 0);

	void ImageBarrier(
		VkPipelineStageFlags        InSrcStageMask,
		VkPipelineStageFlags        InDstStageMask,
		const VkImageMemoryBarrier& InImageMemBarrier,
		VkDependencyFlags           InDependencyFlags = 0);

	void ImageBarrier(const SImageBarrier& InSImageBarrier, VkDependencyFlags InDependencyFlags = 0);

	void ImageBarriers(
		VkPipelineStageFlags        InSrcStageMask,
		VkPipelineStageFlags        InDstStageMask,
		uint32_t                    InImageMemBarrierCount,
		const VkImageMemoryBarrier* InImageMemBarriers,
		VkDependencyFlags           InDependencyFlags = 0);

#pragma endregion

};