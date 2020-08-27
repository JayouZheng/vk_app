﻿//
// LogicalDevice.h
//

#pragma once

#include "Common.h"
#include "VkSmartPtr.h"
#include "BaseAllocator.h"

namespace GConfig
{
	namespace Sampler
	{
		static float SamplerMaxLod = 16.0f;
		static float MaxAnisotropy = 8.0f;
	}

	namespace Pipeline
	{
		static const VkPipelineInputAssemblyStateCreateInfo DefaultInputAssemblyStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO, // sType
			nullptr,                                                     // pNext
			_flag_none,                                                  // flags
			VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,                         // topology
			VK_FALSE                                                     // primitiveRestartEnable
		};

		static const VkPipelineTessellationStateCreateInfo  DefaultTessellationStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO,   // sType
			nullptr,                                                     // pNext
			_flag_none,                                                  // flags
			0u                                                           // patchControlPoints
		};

		static const VkViewport                             DefaultViewport = 
		{
			0.0f,                                                        // x
			0.0f,                                                        // y
			1280.0f,                                                     // width
			720.0f,                                                      // height
			0.0f,                                                        // minDepth
			1.0f                                                         // maxDepth
		};

		static const VkRect2D                               DefaultScissor =
		{
			{ 0, 0 },                                                    // offset
			{ 1280u, 720u }                                              // extent
		};

		static const VkPipelineViewportStateCreateInfo      DefaultViewportStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,       // sType
			nullptr,                                                     // pNext
			_flag_none,                                                  // flags
			_count_1,                                                    // viewportCount
			&DefaultViewport,                                            // pViewports
			_count_1,                                                    // scissorCount
			&DefaultScissor                                              // pScissors
		};

		static const VkPipelineRasterizationStateCreateInfo DefaultRasterizationStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,  // sType
			nullptr,                                                     // pNext
			_flag_none,                                                  // flags
			VK_FALSE,                                                    // depthClampEnable
			VK_TRUE,                                                     // rasterizerDiscardEnable
			VK_POLYGON_MODE_FILL,                                        // polygonMode
			VK_CULL_MODE_NONE,                                           // cullMode
			VK_FRONT_FACE_COUNTER_CLOCKWISE,                             // frontFace
			VK_FALSE,                                                    // depthBiasEnable
			0.0f,                                                        // depthBiasConstantFactor
			0.0f,                                                        // depthBiasClamp
			0.0f,                                                        // depthBiasSlopeFactor
			0.0f                                                         // lineWidth
		};

		static const VkPipelineMultisampleStateCreateInfo   DefaultMultisampleStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,   // sType
			nullptr,												    // pNext
			_flag_none,												    // flags
			VK_SAMPLE_COUNT_1_BIT,									    // rasterizationSamples
			VK_FALSE,												    // sampleShadingEnable
			0.0f,													    // minSampleShading
			nullptr,												    // pSampleMask
			VK_FALSE,												    // alphaToCoverageEnable
			VK_FALSE												    // alphaToOneEnable
		};

		static const VkStencilOpState                       DefaultStencilOpState =
		{
			VK_STENCIL_OP_KEEP,										    // failOp
			VK_STENCIL_OP_KEEP,										    // passOp
			VK_STENCIL_OP_KEEP,										    // depthFailOp
			VK_COMPARE_OP_ALWAYS,									    // compareOp
			0x00,													    // compareMask
			0x00,													    // writeMask
			0u														    // reference
		};

		static const VkPipelineDepthStencilStateCreateInfo  DefaultDepthStencilStateInfo = 
		{
			VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO, // sType
			nullptr,													// pNext
			_flag_none,													// flags
			VK_TRUE,													// depthTestEnable
			VK_TRUE,													// depthWriteEnable
			VK_COMPARE_OP_LESS_OR_EQUAL,								// depthCompareOp
			VK_FALSE,													// depthBoundsTestEnable
			VK_FALSE,													// stencilTestEnable
			DefaultStencilOpState,										// front
			DefaultStencilOpState,										// back
			0.0f,														// minDepthBounds
			0.0f														// maxDepthBounds
		};

		static const VkPipelineColorBlendAttachmentState    DefaultColorBlendAttachmentState =
		{
			VK_TRUE,                                                    // blendEnable
			VK_BLEND_FACTOR_SRC_ALPHA,                                  // srcColorBlendFactor
			VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,                        // dstColorBlendFactor
			VK_BLEND_OP_ADD,                                            // colorBlendOp
			VK_BLEND_FACTOR_ONE,                                        // srcAlphaBlendFactor
			VK_BLEND_FACTOR_ZERO,                                       // dstAlphaBlendFactor
			VK_BLEND_OP_ADD,                                            // alphaBlendOp
			VK_COLOR_COMPONENT_R_BIT |                                  // colorWriteMask
			VK_COLOR_COMPONENT_G_BIT | 
			VK_COLOR_COMPONENT_B_BIT | 
			VK_COLOR_COMPONENT_A_BIT
		};

		static const VkPipelineColorBlendStateCreateInfo    DefaultColorBlendStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,   // sType
			nullptr,                                                    // pNext
			_flag_none,                                                 // flags
			VK_FALSE,                                                   // logicOpEnable
			VK_LOGIC_OP_CLEAR,                                          // logicOp
			_count_1,                                                   // attachmentCount
			&DefaultColorBlendAttachmentState,                          // pAttachments
			{ 0.0f, 0.0f, 0.0f, 0.0f }                                  // blendConstants[4]
		};

		static const std::array<VkDynamicState, 2>          DefaultDynamicState =
		{
			VK_DYNAMIC_STATE_VIEWPORT,
			VK_DYNAMIC_STATE_SCISSOR
		};

		static const VkPipelineDynamicStateCreateInfo       DefaultDynamicStateInfo =
		{
			VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,       // sType
			nullptr,                                                    // pNext
			_flag_none,                                                 // flags
			static_cast<uint32>(DefaultDynamicState.size()),            // dynamicStateCount
			DefaultDynamicState.data(),                                 // pDynamicStates
		};
	}
}

class BaseLayer;
class CommandQueue;

class LogicalDevice
{

protected:

	VkDevice        m_device    = VK_NULL_HANDLE;
	BaseLayer*      m_baseLayer = nullptr;
	BaseAllocator*  m_allocator = nullptr;
	Window*         m_window    = nullptr;

	VkSmartPtr<VkCommandPool>    m_pCmdPool  = nullptr;
	VkSmartPtr<VkDescriptorPool> m_pDescPool = nullptr;

public:

	LogicalDevice() = delete;
	LogicalDevice(const VkDevice& InDevice);
	LogicalDevice(const void* Null);
	LogicalDevice& operator=(const VkDevice& InDevice);

	virtual ~LogicalDevice() {}

public:

	operator VkDevice() const;

	bool operator==(const VkDevice& InDevice) const;

	VkDevice  GetVkDevice() const;
	VkDevice* GetAddressOfVkDevice();

public:

	void SetVkDevice  (const VkDevice& InDevice   );
	void SetBaseLayer (BaseLayer*      InBaseLayer);
	void SetAllocator (BaseAllocator*  InAllocator);
	void SetWindow    (Window*         InWindow   );

	bool IsNoneAllocator() const;

	VkCommandPool GetCmdPool();

	void SetViewport(VkViewport& OutViewport, VkRect2D& OutScissor, uint32 InWidth, uint32 InHeight);

public:

	struct SPipelineComputeDesc
	{
		std::string           EntryPoint;
		VkShaderModule        ShaderModule;
		VkPipelineLayout      PipLayout;	
		VkSpecializationInfo* pSpecialConstInfo;

		// Pipeline Derivatives.
		VkPipeline            BasePipelineHandle;
		int32                 BasePipelineIndex;

		SPipelineComputeDesc()
		{
			EntryPoint         = "main";
			ShaderModule       = VK_NULL_HANDLE;
			PipLayout          = VK_NULL_HANDLE;
			pSpecialConstInfo  = nullptr;

			BasePipelineHandle = VK_NULL_HANDLE;
			BasePipelineIndex  = -1;
		}
	};

	struct SPipelineGraphicDesc
	{
		VkRenderPass          RenderPass;

		std::string           EntryPoint;
		VkShaderModule        ShaderModule;
		VkPipelineLayout      PipLayout;
		VkSpecializationInfo* pSpecialConstInfo;

		// Pipeline Derivatives.
		VkPipeline            BasePipelineHandle;
		int32                 BasePipelineIndex;

		SPipelineGraphicDesc()
		{
			RenderPass = VK_NULL_HANDLE;

			EntryPoint = "main";
			ShaderModule = VK_NULL_HANDLE;
			PipLayout = VK_NULL_HANDLE;
			pSpecialConstInfo = nullptr;

			BasePipelineHandle = VK_NULL_HANDLE;
			BasePipelineIndex = -1;
		}
	};

	struct SPipelineCacheHeader
	{
		uint32 Length;
		uint32 Version;
		uint32 VendorID;
		uint32 DeviceID;
		uint8  UUID[VK_UUID_SIZE];

		SPipelineCacheHeader(const VkPhysicalDeviceProperties& InPDProp)
		{
			Length   = 32;
			Version  = VK_PIPELINE_CACHE_HEADER_VERSION_ONE;
			VendorID = InPDProp.vendorID;
			DeviceID = InPDProp.deviceID;
			std::memcpy(UUID, InPDProp.pipelineCacheUUID, VK_UUID_SIZE);
		}

		size_t GetDataSize() const
		{
			return 32;
		}

		void* GetData() const
		{
			return (void*)this;
		}
	};

	CommandQueue   GetQueue                      (uint32 InQueueFamilyIndex, uint32 InQueueIndex = _index_0);
	void           GetSwapchainImagesKHR         (VkSwapchainKHR InSwapchain, uint32* InOutImageCount, VkImage* OutImages);
	uint32         GetSwapchainNextImageKHR      (VkSwapchainKHR InSwapchain, uint64 InTimeout, VkSemaphore InSemaphore, VkFence InFence);


	// Simple Stupid API (In fact, for all create funs, we need to gather all create infos first, do creating next!).
	void           CreateCommandPool             (const VkCommandPoolCreateInfo& InCreateInfo);
	void           CreateCommandPool             (uint32 InQueueFamilyIndex, VkCommandPoolCreateFlags InFlags = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);

	void           CreateSwapchainKHR            (VkSwapchainKHR* OutSwapchain, const VkSwapchainCreateInfoKHR& InCreateInfo);

	void           CreateShaderModule            (VkShaderModule* OutShaderModule, const VkShaderModuleCreateInfo& InCreateInfo);
	void           CreateShaderModule            (VkShaderModule* OutShaderModule, const uint32* InCodes, size_t InCodeSize);
	void           CreateShaderModule            (VkShaderModule* OutShaderModule, const char* InShaderPath);

	void           CreateComputePipelines        (VkPipeline* OutPipeline, const VkComputePipelineCreateInfo* InCreateInfos, uint32 InCreateInfoCount = _count_1, VkPipelineCache InPipCache = VK_NULL_HANDLE);
	void           CreateComputePipeline         (VkPipeline* OutPipeline, VkPipelineLayout InPipLayout, VkShaderModule InShaderModule, const char* InShaderEntryName = "main", const VkSpecializationInfo* InSpecialConstInfo = nullptr, VkPipelineCache InPipCache = VK_NULL_HANDLE);
	void           CreateComputePipelines        (VkPipeline* OutPipeline, const SPipelineComputeDesc* InDescs, uint32 InDescCount = _count_1, VkPipelineCache InPipCache = VK_NULL_HANDLE);

	void           CreatePipelineCache           (VkPipelineCache* OutPipCache, const VkPipelineCacheCreateInfo& InCreateInfo);
	void           CreatePipelineCache           (VkPipelineCache* OutPipCache, const VkPhysicalDeviceProperties& InPDProp);
	size_t         GetPipelineCacheDataSize      (VkPipelineCache  InPipCache);
	void           GetPipelineCacheData          (VkPipelineCache  InPipCache, size_t InDataSize, void* OutData);
	bool           SavePipelineCacheToFile       (VkPipelineCache  InPipCache, const char* InPath);
	void           MergePipelineCaches           (VkPipelineCache  OutMergedPipCache, const VkPipelineCache* InPipCaches, uint32 InSrcPipCacheCount);

	void           CreateDescriptorSetLayout     (VkDescriptorSetLayout* OutLayout, const VkDescriptorSetLayoutCreateInfo& InCreateInfo);
	void           CreateDescriptorSetLayout     (VkDescriptorSetLayout* OutLayout, const VkDescriptorSetLayoutBinding* InBindings, uint32 InBindingCount);
	void           CreateSingleDescriptorLayout  (VkDescriptorSetLayout* OutLayout, VkDescriptorType InDescType, VkShaderStageFlags InShaderStage, const VkSampler* InImmutableSamplers = nullptr);

	void           CreatePipelineLayout          (VkPipelineLayout* OutLayout, const VkPipelineLayoutCreateInfo& InCreateInfo);
	void           CreatePipelineLayout          (VkPipelineLayout* OutLayout, const VkDescriptorSetLayout* InDescSetLayouts, uint32 InSetCount = _count_1, const VkPushConstantRange* InPushConstants = nullptr, uint32 InConstCount = _count_0);

	void           CreateDescriptorPool          (const VkDescriptorPoolCreateInfo& InCreateInfo);
	void           CreateDescriptorPool          (uint32 InMaxSets, const VkDescriptorPoolSize* InPerDescTypeCounts, uint32 InDescTypeCount);

	void           AllocatorDescriptorSets       (VkDescriptorSet* OutDescSet, const VkDescriptorSetAllocateInfo& InAllocateInfo);
	void           AllocatorDescriptorSets       (VkDescriptorSet* OutDescSet, const VkDescriptorSetLayout* InSetLayouts, uint32 InSetCount = _count_1);
	void           FreeDescriptorSets            (const VkDescriptorSet* InDescSets, uint32 InSetCount = _count_1);
	void           ResetDescriptorPool           (VkDescriptorPoolResetFlags InFlags = _flag_none);

	void           UpdateDescriptorSets          (const VkWriteDescriptorSet* InDescWrites, uint32 InWriteSetCount = _count_1, const VkCopyDescriptorSet* InDescCopies = nullptr, uint32 InCopySetCount = _count_0);
	void           UpdateImageOfDescSet			 (VkDescriptorSet InDescSet, uint32 InBindingIndex, VkDescriptorType InImageDescType, const VkDescriptorImageInfo* InImageInfos, uint32 InImageCount = _count_1, uint32 InSetOffset = _offset_0);
	void           UpdateBufferOfDescSet		 (VkDescriptorSet InDescSet, uint32 InBindingIndex, VkDescriptorType InBufferDescType, const VkDescriptorBufferInfo* InBufferInfos, uint32 InBufferCount = _count_1, uint32 InSetOffset = _offset_0);
	void           UpdateTexelBufferOfDescSet    (VkDescriptorSet InDescSet, uint32 InBindingIndex, VkDescriptorType InTBufferDescType, const VkBufferView* InTBufferViews, uint32 InTBufferCount = _count_1, uint32 InSetOffset = _offset_0);
	void           CopyDescriptorSets            (const VkCopyDescriptorSet* InDescCopies, uint32 InCopySetCount = _count_1);
	void           CopyDescriptorSet             (VkDescriptorSet InSrcSet, uint32 InSrcBindingIndex, VkDescriptorSet InDstSet, uint32 InDstBindingIndex, uint32 InCopyDescCount, uint32 InSrcSetOffset = _offset_0, uint32 InDstSetOffset = _offset_0);

	void           CreateSampler                 (VkSampler* OutSampler, const VkSamplerCreateInfo& InCreateInfo);
	void           CreatePointWrapSampler        (VkSampler* OutSampler);
	void           CreatePointClampSampler       (VkSampler* OutSampler);
	void           CreateLinearWrapSampler       (VkSampler* OutSampler);
	void           CreateLinearClampSampler      (VkSampler* OutSampler);
	void           CreateAnisotropicWrapSampler  (VkSampler* OutSampler);
	void           CreateAnisotropicClampSampler (VkSampler* OutSampler);
	void           CreatePCFSampler              (VkSampler* OutSampler);

	void           CreateRenderPass              (VkRenderPass* OutRenderPass, const VkRenderPassCreateInfo& InCreateInfo);
	void           CreateSingleRenderPass        (VkRenderPass* OutRenderPass, VkFormat InColorFormat, VkFormat InDepthFormat);

	void           CreateFrameBuffer             (VkFramebuffer* OutFrameBuffer, const VkFramebufferCreateInfo& InCreateInfo);
	void           CreateFrameBuffer             (VkFramebuffer* OutFrameBuffer, VkRenderPass InRenderPass, const VkImageView* InImageViews, uint32 InViewCount, VkExtent3D InSize);

	void           CreateGraphicPipelines        (VkPipeline* OutPipeline, const VkGraphicsPipelineCreateInfo* InCreateInfos, uint32 InCreateInfoCount = _count_1, VkPipelineCache InPipCache = VK_NULL_HANDLE);
	void           CreateGraphicPipelines        (VkPipeline* OutPipeline, const SPipelineGraphicDesc* InDescs, uint32 InDescCount = _count_1, VkPipelineCache InPipCache = VK_NULL_HANDLE);
	void           CreateGraphicPipelines        (VkPipeline* OutPipeline, const std::string& InJsonPath, VkPipelineCache InPipCache = VK_NULL_HANDLE);


	template<typename VkType>
	void DestroyVkObject(VkType InObject);
	void FlushAllQueue();
	void ResetCmdPool();

};


// This is an alternative vkDestroy Solution/Version to VkSmartPtr.
template<typename VkType>
void LogicalDevice::DestroyVkObject(VkType InObject)
{
#ifdef _vk_destroy
#undef _vk_destroy
#endif
#define _vk_destroy(object) if (std::is_same<Vk##object, VkType>::value) vkDestroy##object(m_device, (Vk##object)InObject, m_allocator->GetVkAllocator())
	
	_vk_destroy(Fence);
	_vk_destroy(Semaphore); // Should Wait for all reference Object freed...
	_vk_destroy(Event);
	_vk_destroy(QueryPool);
	_vk_destroy(Buffer);
	_vk_destroy(BufferView);
	_vk_destroy(Image);
	_vk_destroy(ImageView);
	_vk_destroy(ShaderModule);
	_vk_destroy(PipelineCache);
	_vk_destroy(Pipeline);
	_vk_destroy(PipelineLayout);
	_vk_destroy(Sampler);
	_vk_destroy(DescriptorSetLayout);
	_vk_destroy(DescriptorPool);
	_vk_destroy(Framebuffer);
	_vk_destroy(RenderPass);
	_vk_destroy(CommandPool);

	// Using Semaphore...
	_vk_destroy(SwapchainKHR);
}

#define CreateRenderTarget    CreateFrameBuffer
typedef VkFramebuffer         VkRenderTarget;
