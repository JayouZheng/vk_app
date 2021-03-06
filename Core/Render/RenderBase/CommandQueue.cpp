﻿/*********************************************************************
 *  CommandQueue.cpp
 *  Copyright (C) 2020 Jayou. All Rights Reserved.
 *********************************************************************/

#include "CommandQueue.h"
#include "CommandList.h"

_impl_create_interface(CommandQueue)

CommandQueue::CommandQueue() : 
	m_queue (VK_NULL_HANDLE)
{

}

CommandQueue::~CommandQueue()
{
}

CommandQueue& CommandQueue::operator=(const VkQueue& InQueue)
{
	m_queue = InQueue;
	return *this;
}

CommandQueue::operator VkQueue()
{
	return m_queue;
}

CommandQueue::operator VkQueue*()
{
	return &m_queue;
}

bool CommandQueue::operator==(const VkQueue& InQueue) const
{
	return m_queue == InQueue;
}

void CommandQueue::Execute(const CommandList* InCmdList)
{
	VkCommandBuffer cmdBuffer = InCmdList->GetCmdBuffer();

	VkSubmitInfo submitInfo = {};
	submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submitInfo.commandBufferCount = _count_1;
	submitInfo.pCommandBuffers = &cmdBuffer;

	_vk_try(vkQueueSubmit(m_queue, _count_1, &submitInfo, VK_NULL_HANDLE));
}

void CommandQueue::Flush()
{
	_vk_try(vkQueueWaitIdle(m_queue));
}

void CommandQueue::Present(const VkPresentInfoKHR& InPresentInfo)
{
	_vk_try(vkQueuePresentKHR(m_queue, &InPresentInfo));
}
