#ifndef __VULKAN_FILLER_H__
#define __VULKAN_FILLER_H__

#ifndef VULKAN_H_
#include <vulkan/vulkan.h>
#endif //!VULKAN_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifdef VK_VERSION_1_0
       static inline VkApplicationInfo vkfApplicationInfo(const char *pApplicationName, uint32_t applicationVersion, const char *pEngineName, uint32_t engineVersion, uint32_t apiVersion)
       {
              VkApplicationInfo struct_to_fill;
              struct_to_fill.pApplicationName = pApplicationName;
              struct_to_fill.applicationVersion = applicationVersion;
              struct_to_fill.pEngineName = pEngineName;
              struct_to_fill.engineVersion = engineVersion;
              struct_to_fill.apiVersion = apiVersion;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkInstanceCreateInfo vkfInstanceCreateInfo(const VkApplicationInfo *pApplicationInfo, uint32_t enabledLayerCount, const char *const *ppEnabledLayerNames, uint32_t enabledExtensionCount, const char *const *ppEnabledExtensionNames)
       {
              VkInstanceCreateInfo struct_to_fill;
              struct_to_fill.pApplicationInfo = pApplicationInfo;
              struct_to_fill.enabledLayerCount = enabledLayerCount;
              struct_to_fill.ppEnabledLayerNames = ppEnabledLayerNames;
              struct_to_fill.enabledExtensionCount = enabledExtensionCount;
              struct_to_fill.ppEnabledExtensionNames = ppEnabledExtensionNames;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAllocationCallbacks vkfAllocationCallbacks(void *pUserData, PFN_vkAllocationFunction pfnAllocation, PFN_vkReallocationFunction pfnReallocation, PFN_vkFreeFunction pfnFree, PFN_vkInternalAllocationNotification pfnInternalAllocation, PFN_vkInternalFreeNotification pfnInternalFree)
       {
              VkAllocationCallbacks struct_to_fill;
              struct_to_fill.pUserData = pUserData;
              struct_to_fill.pfnAllocation = pfnAllocation;
              struct_to_fill.pfnReallocation = pfnReallocation;
              struct_to_fill.pfnFree = pfnFree;
              struct_to_fill.pfnInternalAllocation = pfnInternalAllocation;
              struct_to_fill.pfnInternalFree = pfnInternalFree;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceFeatures vkfPhysicalDeviceFeatures(VkBool32 robustBufferAccess, VkBool32 fullDrawIndexUint32, VkBool32 imageCubeArray, VkBool32 independentBlend, VkBool32 geometryShader, VkBool32 tessellationShader, VkBool32 sampleRateShading, VkBool32 dualSrcBlend, VkBool32 logicOp, VkBool32 multiDrawIndirect, VkBool32 drawIndirectFirstInstance, VkBool32 depthClamp, VkBool32 depthBiasClamp, VkBool32 fillModeNonSolid, VkBool32 depthBounds, VkBool32 wideLines, VkBool32 largePoints, VkBool32 alphaToOne, VkBool32 multiViewport, VkBool32 samplerAnisotropy, VkBool32 textureCompressionETC2, VkBool32 textureCompressionASTC_LDR, VkBool32 textureCompressionBC, VkBool32 occlusionQueryPrecise, VkBool32 pipelineStatisticsQuery, VkBool32 vertexPipelineStoresAndAtomics, VkBool32 fragmentStoresAndAtomics, VkBool32 shaderTessellationAndGeometryPointSize, VkBool32 shaderImageGatherExtended, VkBool32 shaderStorageImageExtendedFormats, VkBool32 shaderStorageImageMultisample, VkBool32 shaderStorageImageReadWithoutFormat, VkBool32 shaderStorageImageWriteWithoutFormat, VkBool32 shaderUniformBufferArrayDynamicIndexing, VkBool32 shaderSampledImageArrayDynamicIndexing, VkBool32 shaderStorageBufferArrayDynamicIndexing, VkBool32 shaderStorageImageArrayDynamicIndexing, VkBool32 shaderClipDistance, VkBool32 shaderCullDistance, VkBool32 shaderFloat64, VkBool32 shaderInt64, VkBool32 shaderInt16, VkBool32 shaderResourceResidency, VkBool32 shaderResourceMinLod, VkBool32 sparseBinding, VkBool32 sparseResidencyBuffer, VkBool32 sparseResidencyImage2D, VkBool32 sparseResidencyImage3D, VkBool32 sparseResidency2Samples, VkBool32 sparseResidency4Samples, VkBool32 sparseResidency8Samples, VkBool32 sparseResidency16Samples, VkBool32 sparseResidencyAliased, VkBool32 variableMultisampleRate, VkBool32 inheritedQueries)
       {
              VkPhysicalDeviceFeatures struct_to_fill;
              struct_to_fill.robustBufferAccess = robustBufferAccess;
              struct_to_fill.fullDrawIndexUint32 = fullDrawIndexUint32;
              struct_to_fill.imageCubeArray = imageCubeArray;
              struct_to_fill.independentBlend = independentBlend;
              struct_to_fill.geometryShader = geometryShader;
              struct_to_fill.tessellationShader = tessellationShader;
              struct_to_fill.sampleRateShading = sampleRateShading;
              struct_to_fill.dualSrcBlend = dualSrcBlend;
              struct_to_fill.logicOp = logicOp;
              struct_to_fill.multiDrawIndirect = multiDrawIndirect;
              struct_to_fill.drawIndirectFirstInstance = drawIndirectFirstInstance;
              struct_to_fill.depthClamp = depthClamp;
              struct_to_fill.depthBiasClamp = depthBiasClamp;
              struct_to_fill.fillModeNonSolid = fillModeNonSolid;
              struct_to_fill.depthBounds = depthBounds;
              struct_to_fill.wideLines = wideLines;
              struct_to_fill.largePoints = largePoints;
              struct_to_fill.alphaToOne = alphaToOne;
              struct_to_fill.multiViewport = multiViewport;
              struct_to_fill.samplerAnisotropy = samplerAnisotropy;
              struct_to_fill.textureCompressionETC2 = textureCompressionETC2;
              struct_to_fill.textureCompressionASTC_LDR = textureCompressionASTC_LDR;
              struct_to_fill.textureCompressionBC = textureCompressionBC;
              struct_to_fill.occlusionQueryPrecise = occlusionQueryPrecise;
              struct_to_fill.pipelineStatisticsQuery = pipelineStatisticsQuery;
              struct_to_fill.vertexPipelineStoresAndAtomics = vertexPipelineStoresAndAtomics;
              struct_to_fill.fragmentStoresAndAtomics = fragmentStoresAndAtomics;
              struct_to_fill.shaderTessellationAndGeometryPointSize = shaderTessellationAndGeometryPointSize;
              struct_to_fill.shaderImageGatherExtended = shaderImageGatherExtended;
              struct_to_fill.shaderStorageImageExtendedFormats = shaderStorageImageExtendedFormats;
              struct_to_fill.shaderStorageImageMultisample = shaderStorageImageMultisample;
              struct_to_fill.shaderStorageImageReadWithoutFormat = shaderStorageImageReadWithoutFormat;
              struct_to_fill.shaderStorageImageWriteWithoutFormat = shaderStorageImageWriteWithoutFormat;
              struct_to_fill.shaderUniformBufferArrayDynamicIndexing = shaderUniformBufferArrayDynamicIndexing;
              struct_to_fill.shaderSampledImageArrayDynamicIndexing = shaderSampledImageArrayDynamicIndexing;
              struct_to_fill.shaderStorageBufferArrayDynamicIndexing = shaderStorageBufferArrayDynamicIndexing;
              struct_to_fill.shaderStorageImageArrayDynamicIndexing = shaderStorageImageArrayDynamicIndexing;
              struct_to_fill.shaderClipDistance = shaderClipDistance;
              struct_to_fill.shaderCullDistance = shaderCullDistance;
              struct_to_fill.shaderFloat64 = shaderFloat64;
              struct_to_fill.shaderInt64 = shaderInt64;
              struct_to_fill.shaderInt16 = shaderInt16;
              struct_to_fill.shaderResourceResidency = shaderResourceResidency;
              struct_to_fill.shaderResourceMinLod = shaderResourceMinLod;
              struct_to_fill.sparseBinding = sparseBinding;
              struct_to_fill.sparseResidencyBuffer = sparseResidencyBuffer;
              struct_to_fill.sparseResidencyImage2D = sparseResidencyImage2D;
              struct_to_fill.sparseResidencyImage3D = sparseResidencyImage3D;
              struct_to_fill.sparseResidency2Samples = sparseResidency2Samples;
              struct_to_fill.sparseResidency4Samples = sparseResidency4Samples;
              struct_to_fill.sparseResidency8Samples = sparseResidency8Samples;
              struct_to_fill.sparseResidency16Samples = sparseResidency16Samples;
              struct_to_fill.sparseResidencyAliased = sparseResidencyAliased;
              struct_to_fill.variableMultisampleRate = variableMultisampleRate;
              struct_to_fill.inheritedQueries = inheritedQueries;
              return struct_to_fill;
       }
       static inline VkFormatProperties vkfFormatProperties(VkFormatFeatureFlags linearTilingFeatures, VkFormatFeatureFlags optimalTilingFeatures, VkFormatFeatureFlags bufferFeatures)
       {
              VkFormatProperties struct_to_fill;
              struct_to_fill.linearTilingFeatures = linearTilingFeatures;
              struct_to_fill.optimalTilingFeatures = optimalTilingFeatures;
              struct_to_fill.bufferFeatures = bufferFeatures;
              return struct_to_fill;
       }
       static inline VkExtent3D vkfExtent3D(uint32_t width, uint32_t height, uint32_t depth)
       {
              VkExtent3D struct_to_fill;
              struct_to_fill.width = width;
              struct_to_fill.height = height;
              struct_to_fill.depth = depth;
              return struct_to_fill;
       }
       static inline VkImageFormatProperties vkfImageFormatProperties(VkExtent3D maxExtent, uint32_t maxMipLevels, uint32_t maxArrayLayers, VkSampleCountFlags sampleCounts, VkDeviceSize maxResourceSize)
       {
              VkImageFormatProperties struct_to_fill;
              struct_to_fill.maxExtent = maxExtent;
              struct_to_fill.maxMipLevels = maxMipLevels;
              struct_to_fill.maxArrayLayers = maxArrayLayers;
              struct_to_fill.sampleCounts = sampleCounts;
              struct_to_fill.maxResourceSize = maxResourceSize;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceLimits vkfPhysicalDeviceLimits(uint32_t maxImageDimension1D, uint32_t maxImageDimension2D, uint32_t maxImageDimension3D, uint32_t maxImageDimensionCube, uint32_t maxImageArrayLayers, uint32_t maxTexelBufferElements, uint32_t maxUniformBufferRange, uint32_t maxStorageBufferRange, uint32_t maxPushConstantsSize, uint32_t maxMemoryAllocationCount, uint32_t maxSamplerAllocationCount, VkDeviceSize bufferImageGranularity, VkDeviceSize sparseAddressSpaceSize, uint32_t maxBoundDescriptorSets, uint32_t maxPerStageDescriptorSamplers, uint32_t maxPerStageDescriptorUniformBuffers, uint32_t maxPerStageDescriptorStorageBuffers, uint32_t maxPerStageDescriptorSampledImages, uint32_t maxPerStageDescriptorStorageImages, uint32_t maxPerStageDescriptorInputAttachments, uint32_t maxPerStageResources, uint32_t maxDescriptorSetSamplers, uint32_t maxDescriptorSetUniformBuffers, uint32_t maxDescriptorSetUniformBuffersDynamic, uint32_t maxDescriptorSetStorageBuffers, uint32_t maxDescriptorSetStorageBuffersDynamic, uint32_t maxDescriptorSetSampledImages, uint32_t maxDescriptorSetStorageImages, uint32_t maxDescriptorSetInputAttachments, uint32_t maxVertexInputAttributes, uint32_t maxVertexInputBindings, uint32_t maxVertexInputAttributeOffset, uint32_t maxVertexInputBindingStride, uint32_t maxVertexOutputComponents, uint32_t maxTessellationGenerationLevel, uint32_t maxTessellationPatchSize, uint32_t maxTessellationControlPerVertexInputComponents, uint32_t maxTessellationControlPerVertexOutputComponents, uint32_t maxTessellationControlPerPatchOutputComponents, uint32_t maxTessellationControlTotalOutputComponents, uint32_t maxTessellationEvaluationInputComponents, uint32_t maxTessellationEvaluationOutputComponents, uint32_t maxGeometryShaderInvocations, uint32_t maxGeometryInputComponents, uint32_t maxGeometryOutputComponents, uint32_t maxGeometryOutputVertices, uint32_t maxGeometryTotalOutputComponents, uint32_t maxFragmentInputComponents, uint32_t maxFragmentOutputAttachments, uint32_t maxFragmentDualSrcAttachments, uint32_t maxFragmentCombinedOutputResources, uint32_t maxComputeSharedMemorySize, uint32_t maxComputeWorkGroupInvocations, uint32_t subPixelPrecisionBits, uint32_t subTexelPrecisionBits, uint32_t mipmapPrecisionBits, uint32_t maxDrawIndexedIndexValue, uint32_t maxDrawIndirectCount, float maxSamplerLodBias, float maxSamplerAnisotropy, uint32_t maxViewports, uint32_t viewportSubPixelBits, size_t minMemoryMapAlignment, VkDeviceSize minTexelBufferOffsetAlignment, VkDeviceSize minUniformBufferOffsetAlignment, VkDeviceSize minStorageBufferOffsetAlignment, int32_t minTexelOffset, uint32_t maxTexelOffset, int32_t minTexelGatherOffset, uint32_t maxTexelGatherOffset, float minInterpolationOffset, float maxInterpolationOffset, uint32_t subPixelInterpolationOffsetBits, uint32_t maxFramebufferWidth, uint32_t maxFramebufferHeight, uint32_t maxFramebufferLayers, VkSampleCountFlags framebufferColorSampleCounts, VkSampleCountFlags framebufferDepthSampleCounts, VkSampleCountFlags framebufferStencilSampleCounts, VkSampleCountFlags framebufferNoAttachmentsSampleCounts, uint32_t maxColorAttachments, VkSampleCountFlags sampledImageColorSampleCounts, VkSampleCountFlags sampledImageIntegerSampleCounts, VkSampleCountFlags sampledImageDepthSampleCounts, VkSampleCountFlags sampledImageStencilSampleCounts, VkSampleCountFlags storageImageSampleCounts, uint32_t maxSampleMaskWords, VkBool32 timestampComputeAndGraphics, float timestampPeriod, uint32_t maxClipDistances, uint32_t maxCullDistances, uint32_t maxCombinedClipAndCullDistances, uint32_t discreteQueuePriorities, float pointSizeGranularity, float lineWidthGranularity, VkBool32 strictLines, VkBool32 standardSampleLocations, VkDeviceSize optimalBufferCopyOffsetAlignment, VkDeviceSize optimalBufferCopyRowPitchAlignment, VkDeviceSize nonCoherentAtomSize)
       {
              VkPhysicalDeviceLimits struct_to_fill;
              struct_to_fill.maxImageDimension1D = maxImageDimension1D;
              struct_to_fill.maxImageDimension2D = maxImageDimension2D;
              struct_to_fill.maxImageDimension3D = maxImageDimension3D;
              struct_to_fill.maxImageDimensionCube = maxImageDimensionCube;
              struct_to_fill.maxImageArrayLayers = maxImageArrayLayers;
              struct_to_fill.maxTexelBufferElements = maxTexelBufferElements;
              struct_to_fill.maxUniformBufferRange = maxUniformBufferRange;
              struct_to_fill.maxStorageBufferRange = maxStorageBufferRange;
              struct_to_fill.maxPushConstantsSize = maxPushConstantsSize;
              struct_to_fill.maxMemoryAllocationCount = maxMemoryAllocationCount;
              struct_to_fill.maxSamplerAllocationCount = maxSamplerAllocationCount;
              struct_to_fill.bufferImageGranularity = bufferImageGranularity;
              struct_to_fill.sparseAddressSpaceSize = sparseAddressSpaceSize;
              struct_to_fill.maxBoundDescriptorSets = maxBoundDescriptorSets;
              struct_to_fill.maxPerStageDescriptorSamplers = maxPerStageDescriptorSamplers;
              struct_to_fill.maxPerStageDescriptorUniformBuffers = maxPerStageDescriptorUniformBuffers;
              struct_to_fill.maxPerStageDescriptorStorageBuffers = maxPerStageDescriptorStorageBuffers;
              struct_to_fill.maxPerStageDescriptorSampledImages = maxPerStageDescriptorSampledImages;
              struct_to_fill.maxPerStageDescriptorStorageImages = maxPerStageDescriptorStorageImages;
              struct_to_fill.maxPerStageDescriptorInputAttachments = maxPerStageDescriptorInputAttachments;
              struct_to_fill.maxPerStageResources = maxPerStageResources;
              struct_to_fill.maxDescriptorSetSamplers = maxDescriptorSetSamplers;
              struct_to_fill.maxDescriptorSetUniformBuffers = maxDescriptorSetUniformBuffers;
              struct_to_fill.maxDescriptorSetUniformBuffersDynamic = maxDescriptorSetUniformBuffersDynamic;
              struct_to_fill.maxDescriptorSetStorageBuffers = maxDescriptorSetStorageBuffers;
              struct_to_fill.maxDescriptorSetStorageBuffersDynamic = maxDescriptorSetStorageBuffersDynamic;
              struct_to_fill.maxDescriptorSetSampledImages = maxDescriptorSetSampledImages;
              struct_to_fill.maxDescriptorSetStorageImages = maxDescriptorSetStorageImages;
              struct_to_fill.maxDescriptorSetInputAttachments = maxDescriptorSetInputAttachments;
              struct_to_fill.maxVertexInputAttributes = maxVertexInputAttributes;
              struct_to_fill.maxVertexInputBindings = maxVertexInputBindings;
              struct_to_fill.maxVertexInputAttributeOffset = maxVertexInputAttributeOffset;
              struct_to_fill.maxVertexInputBindingStride = maxVertexInputBindingStride;
              struct_to_fill.maxVertexOutputComponents = maxVertexOutputComponents;
              struct_to_fill.maxTessellationGenerationLevel = maxTessellationGenerationLevel;
              struct_to_fill.maxTessellationPatchSize = maxTessellationPatchSize;
              struct_to_fill.maxTessellationControlPerVertexInputComponents = maxTessellationControlPerVertexInputComponents;
              struct_to_fill.maxTessellationControlPerVertexOutputComponents = maxTessellationControlPerVertexOutputComponents;
              struct_to_fill.maxTessellationControlPerPatchOutputComponents = maxTessellationControlPerPatchOutputComponents;
              struct_to_fill.maxTessellationControlTotalOutputComponents = maxTessellationControlTotalOutputComponents;
              struct_to_fill.maxTessellationEvaluationInputComponents = maxTessellationEvaluationInputComponents;
              struct_to_fill.maxTessellationEvaluationOutputComponents = maxTessellationEvaluationOutputComponents;
              struct_to_fill.maxGeometryShaderInvocations = maxGeometryShaderInvocations;
              struct_to_fill.maxGeometryInputComponents = maxGeometryInputComponents;
              struct_to_fill.maxGeometryOutputComponents = maxGeometryOutputComponents;
              struct_to_fill.maxGeometryOutputVertices = maxGeometryOutputVertices;
              struct_to_fill.maxGeometryTotalOutputComponents = maxGeometryTotalOutputComponents;
              struct_to_fill.maxFragmentInputComponents = maxFragmentInputComponents;
              struct_to_fill.maxFragmentOutputAttachments = maxFragmentOutputAttachments;
              struct_to_fill.maxFragmentDualSrcAttachments = maxFragmentDualSrcAttachments;
              struct_to_fill.maxFragmentCombinedOutputResources = maxFragmentCombinedOutputResources;
              struct_to_fill.maxComputeSharedMemorySize = maxComputeSharedMemorySize;
              struct_to_fill.maxComputeWorkGroupInvocations = maxComputeWorkGroupInvocations;
              struct_to_fill.subPixelPrecisionBits = subPixelPrecisionBits;
              struct_to_fill.subTexelPrecisionBits = subTexelPrecisionBits;
              struct_to_fill.mipmapPrecisionBits = mipmapPrecisionBits;
              struct_to_fill.maxDrawIndexedIndexValue = maxDrawIndexedIndexValue;
              struct_to_fill.maxDrawIndirectCount = maxDrawIndirectCount;
              struct_to_fill.maxSamplerLodBias = maxSamplerLodBias;
              struct_to_fill.maxSamplerAnisotropy = maxSamplerAnisotropy;
              struct_to_fill.maxViewports = maxViewports;
              struct_to_fill.viewportSubPixelBits = viewportSubPixelBits;
              struct_to_fill.minMemoryMapAlignment = minMemoryMapAlignment;
              struct_to_fill.minTexelBufferOffsetAlignment = minTexelBufferOffsetAlignment;
              struct_to_fill.minUniformBufferOffsetAlignment = minUniformBufferOffsetAlignment;
              struct_to_fill.minStorageBufferOffsetAlignment = minStorageBufferOffsetAlignment;
              struct_to_fill.minTexelOffset = minTexelOffset;
              struct_to_fill.maxTexelOffset = maxTexelOffset;
              struct_to_fill.minTexelGatherOffset = minTexelGatherOffset;
              struct_to_fill.maxTexelGatherOffset = maxTexelGatherOffset;
              struct_to_fill.minInterpolationOffset = minInterpolationOffset;
              struct_to_fill.maxInterpolationOffset = maxInterpolationOffset;
              struct_to_fill.subPixelInterpolationOffsetBits = subPixelInterpolationOffsetBits;
              struct_to_fill.maxFramebufferWidth = maxFramebufferWidth;
              struct_to_fill.maxFramebufferHeight = maxFramebufferHeight;
              struct_to_fill.maxFramebufferLayers = maxFramebufferLayers;
              struct_to_fill.framebufferColorSampleCounts = framebufferColorSampleCounts;
              struct_to_fill.framebufferDepthSampleCounts = framebufferDepthSampleCounts;
              struct_to_fill.framebufferStencilSampleCounts = framebufferStencilSampleCounts;
              struct_to_fill.framebufferNoAttachmentsSampleCounts = framebufferNoAttachmentsSampleCounts;
              struct_to_fill.maxColorAttachments = maxColorAttachments;
              struct_to_fill.sampledImageColorSampleCounts = sampledImageColorSampleCounts;
              struct_to_fill.sampledImageIntegerSampleCounts = sampledImageIntegerSampleCounts;
              struct_to_fill.sampledImageDepthSampleCounts = sampledImageDepthSampleCounts;
              struct_to_fill.sampledImageStencilSampleCounts = sampledImageStencilSampleCounts;
              struct_to_fill.storageImageSampleCounts = storageImageSampleCounts;
              struct_to_fill.maxSampleMaskWords = maxSampleMaskWords;
              struct_to_fill.timestampComputeAndGraphics = timestampComputeAndGraphics;
              struct_to_fill.timestampPeriod = timestampPeriod;
              struct_to_fill.maxClipDistances = maxClipDistances;
              struct_to_fill.maxCullDistances = maxCullDistances;
              struct_to_fill.maxCombinedClipAndCullDistances = maxCombinedClipAndCullDistances;
              struct_to_fill.discreteQueuePriorities = discreteQueuePriorities;
              struct_to_fill.pointSizeGranularity = pointSizeGranularity;
              struct_to_fill.lineWidthGranularity = lineWidthGranularity;
              struct_to_fill.strictLines = strictLines;
              struct_to_fill.standardSampleLocations = standardSampleLocations;
              struct_to_fill.optimalBufferCopyOffsetAlignment = optimalBufferCopyOffsetAlignment;
              struct_to_fill.optimalBufferCopyRowPitchAlignment = optimalBufferCopyRowPitchAlignment;
              struct_to_fill.nonCoherentAtomSize = nonCoherentAtomSize;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSparseProperties vkfPhysicalDeviceSparseProperties(VkBool32 residencyStandard2DBlockShape, VkBool32 residencyStandard2DMultisampleBlockShape, VkBool32 residencyStandard3DBlockShape, VkBool32 residencyAlignedMipSize, VkBool32 residencyNonResidentStrict)
       {
              VkPhysicalDeviceSparseProperties struct_to_fill;
              struct_to_fill.residencyStandard2DBlockShape = residencyStandard2DBlockShape;
              struct_to_fill.residencyStandard2DMultisampleBlockShape = residencyStandard2DMultisampleBlockShape;
              struct_to_fill.residencyStandard3DBlockShape = residencyStandard3DBlockShape;
              struct_to_fill.residencyAlignedMipSize = residencyAlignedMipSize;
              struct_to_fill.residencyNonResidentStrict = residencyNonResidentStrict;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceProperties vkfPhysicalDeviceProperties(uint32_t apiVersion, uint32_t driverVersion, uint32_t vendorID, uint32_t deviceID, VkPhysicalDeviceType deviceType, VkPhysicalDeviceLimits limits, VkPhysicalDeviceSparseProperties sparseProperties)
       {
              VkPhysicalDeviceProperties struct_to_fill;
              struct_to_fill.apiVersion = apiVersion;
              struct_to_fill.driverVersion = driverVersion;
              struct_to_fill.vendorID = vendorID;
              struct_to_fill.deviceID = deviceID;
              struct_to_fill.deviceType = deviceType;
              struct_to_fill.limits = limits;
              struct_to_fill.sparseProperties = sparseProperties;
              return struct_to_fill;
       }
       static inline VkQueueFamilyProperties vkfQueueFamilyProperties(VkQueueFlags queueFlags, uint32_t queueCount, uint32_t timestampValidBits, VkExtent3D minImageTransferGranularity)
       {
              VkQueueFamilyProperties struct_to_fill;
              struct_to_fill.queueFlags = queueFlags;
              struct_to_fill.queueCount = queueCount;
              struct_to_fill.timestampValidBits = timestampValidBits;
              struct_to_fill.minImageTransferGranularity = minImageTransferGranularity;
              return struct_to_fill;
       }
       static inline VkMemoryType vkfMemoryType(VkMemoryPropertyFlags propertyFlags, uint32_t heapIndex)
       {
              VkMemoryType struct_to_fill;
              struct_to_fill.propertyFlags = propertyFlags;
              struct_to_fill.heapIndex = heapIndex;
              return struct_to_fill;
       }
       static inline VkMemoryHeap vkfMemoryHeap(VkDeviceSize size)
       {
              VkMemoryHeap struct_to_fill;
              struct_to_fill.size = size;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMemoryProperties vkfPhysicalDeviceMemoryProperties(uint32_t memoryTypeCount, uint32_t memoryHeapCount)
       {
              VkPhysicalDeviceMemoryProperties struct_to_fill;
              struct_to_fill.memoryTypeCount = memoryTypeCount;
              struct_to_fill.memoryHeapCount = memoryHeapCount;
              return struct_to_fill;
       }
       static inline VkDeviceQueueCreateInfo vkfDeviceQueueCreateInfo(uint32_t queueFamilyIndex, uint32_t queueCount, const float *pQueuePriorities)
       {
              VkDeviceQueueCreateInfo struct_to_fill;
              struct_to_fill.queueFamilyIndex = queueFamilyIndex;
              struct_to_fill.queueCount = queueCount;
              struct_to_fill.pQueuePriorities = pQueuePriorities;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDeviceCreateInfo vkfDeviceCreateInfo(uint32_t queueCreateInfoCount, const VkDeviceQueueCreateInfo *pQueueCreateInfos, uint32_t enabledLayerCount, const char *const *ppEnabledLayerNames, uint32_t enabledExtensionCount, const char *const *ppEnabledExtensionNames, const VkPhysicalDeviceFeatures *pEnabledFeatures)
       {
              VkDeviceCreateInfo struct_to_fill;
              struct_to_fill.queueCreateInfoCount = queueCreateInfoCount;
              struct_to_fill.pQueueCreateInfos = pQueueCreateInfos;
              struct_to_fill.enabledLayerCount = enabledLayerCount;
              struct_to_fill.ppEnabledLayerNames = ppEnabledLayerNames;
              struct_to_fill.enabledExtensionCount = enabledExtensionCount;
              struct_to_fill.ppEnabledExtensionNames = ppEnabledExtensionNames;
              struct_to_fill.pEnabledFeatures = pEnabledFeatures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkExtensionProperties vkfExtensionProperties(uint32_t specVersion)
       {
              VkExtensionProperties struct_to_fill;
              struct_to_fill.specVersion = specVersion;
              return struct_to_fill;
       }
       static inline VkLayerProperties vkfLayerProperties(uint32_t specVersion, uint32_t implementationVersion)
       {
              VkLayerProperties struct_to_fill;
              struct_to_fill.specVersion = specVersion;
              struct_to_fill.implementationVersion = implementationVersion;
              return struct_to_fill;
       }
       static inline VkSubmitInfo vkfSubmitInfo(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, const VkPipelineStageFlags *pWaitDstStageMask, uint32_t commandBufferCount, const VkCommandBuffer *pCommandBuffers, uint32_t signalSemaphoreCount, const VkSemaphore *pSignalSemaphores)
       {
              VkSubmitInfo struct_to_fill;
              struct_to_fill.waitSemaphoreCount = waitSemaphoreCount;
              struct_to_fill.pWaitSemaphores = pWaitSemaphores;
              struct_to_fill.pWaitDstStageMask = pWaitDstStageMask;
              struct_to_fill.commandBufferCount = commandBufferCount;
              struct_to_fill.pCommandBuffers = pCommandBuffers;
              struct_to_fill.signalSemaphoreCount = signalSemaphoreCount;
              struct_to_fill.pSignalSemaphores = pSignalSemaphores;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryAllocateInfo vkfMemoryAllocateInfo(VkDeviceSize allocationSize, uint32_t memoryTypeIndex)
       {
              VkMemoryAllocateInfo struct_to_fill;
              struct_to_fill.allocationSize = allocationSize;
              struct_to_fill.memoryTypeIndex = memoryTypeIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMappedMemoryRange vkfMappedMemoryRange(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size)
       {
              VkMappedMemoryRange struct_to_fill;
              struct_to_fill.memory = memory;
              struct_to_fill.offset = offset;
              struct_to_fill.size = size;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryRequirements vkfMemoryRequirements(VkDeviceSize size, VkDeviceSize alignment, uint32_t memoryTypeBits)
       {
              VkMemoryRequirements struct_to_fill;
              struct_to_fill.size = size;
              struct_to_fill.alignment = alignment;
              struct_to_fill.memoryTypeBits = memoryTypeBits;
              return struct_to_fill;
       }
       static inline VkSparseImageFormatProperties vkfSparseImageFormatProperties(VkImageAspectFlags aspectMask, VkExtent3D imageGranularity)
       {
              VkSparseImageFormatProperties struct_to_fill;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.imageGranularity = imageGranularity;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSparseImageMemoryRequirements vkfSparseImageMemoryRequirements(VkSparseImageFormatProperties formatProperties, uint32_t imageMipTailFirstLod, VkDeviceSize imageMipTailSize, VkDeviceSize imageMipTailOffset, VkDeviceSize imageMipTailStride)
       {
              VkSparseImageMemoryRequirements struct_to_fill;
              struct_to_fill.formatProperties = formatProperties;
              struct_to_fill.imageMipTailFirstLod = imageMipTailFirstLod;
              struct_to_fill.imageMipTailSize = imageMipTailSize;
              struct_to_fill.imageMipTailOffset = imageMipTailOffset;
              struct_to_fill.imageMipTailStride = imageMipTailStride;
              return struct_to_fill;
       }
       static inline VkSparseMemoryBind vkfSparseMemoryBind(VkDeviceSize resourceOffset, VkDeviceSize size, VkDeviceMemory memory, VkDeviceSize memoryOffset)
       {
              VkSparseMemoryBind struct_to_fill;
              struct_to_fill.resourceOffset = resourceOffset;
              struct_to_fill.size = size;
              struct_to_fill.memory = memory;
              struct_to_fill.memoryOffset = memoryOffset;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSparseBufferMemoryBindInfo vkfSparseBufferMemoryBindInfo(VkBuffer buffer, uint32_t bindCount, const VkSparseMemoryBind *pBinds)
       {
              VkSparseBufferMemoryBindInfo struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.bindCount = bindCount;
              struct_to_fill.pBinds = pBinds;
              return struct_to_fill;
       }
       static inline VkSparseImageOpaqueMemoryBindInfo vkfSparseImageOpaqueMemoryBindInfo(VkImage image, uint32_t bindCount, const VkSparseMemoryBind *pBinds)
       {
              VkSparseImageOpaqueMemoryBindInfo struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.bindCount = bindCount;
              struct_to_fill.pBinds = pBinds;
              return struct_to_fill;
       }
       static inline VkImageSubresource vkfImageSubresource(VkImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t arrayLayer)
       {
              VkImageSubresource struct_to_fill;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.mipLevel = mipLevel;
              struct_to_fill.arrayLayer = arrayLayer;
              return struct_to_fill;
       }
       static inline VkOffset3D vkfOffset3D(int32_t x, int32_t y, int32_t z)
       {
              VkOffset3D struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              struct_to_fill.z = z;
              return struct_to_fill;
       }
       static inline VkSparseImageMemoryBind vkfSparseImageMemoryBind(VkImageSubresource subresource, VkOffset3D offset, VkExtent3D extent, VkDeviceMemory memory, VkDeviceSize memoryOffset)
       {
              VkSparseImageMemoryBind struct_to_fill;
              struct_to_fill.subresource = subresource;
              struct_to_fill.offset = offset;
              struct_to_fill.extent = extent;
              struct_to_fill.memory = memory;
              struct_to_fill.memoryOffset = memoryOffset;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSparseImageMemoryBindInfo vkfSparseImageMemoryBindInfo(VkImage image, uint32_t bindCount, const VkSparseImageMemoryBind *pBinds)
       {
              VkSparseImageMemoryBindInfo struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.bindCount = bindCount;
              struct_to_fill.pBinds = pBinds;
              return struct_to_fill;
       }
       static inline VkBindSparseInfo vkfBindSparseInfo(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, uint32_t bufferBindCount, const VkSparseBufferMemoryBindInfo *pBufferBinds, uint32_t imageOpaqueBindCount, const VkSparseImageOpaqueMemoryBindInfo *pImageOpaqueBinds, uint32_t imageBindCount, const VkSparseImageMemoryBindInfo *pImageBinds, uint32_t signalSemaphoreCount, const VkSemaphore *pSignalSemaphores)
       {
              VkBindSparseInfo struct_to_fill;
              struct_to_fill.waitSemaphoreCount = waitSemaphoreCount;
              struct_to_fill.pWaitSemaphores = pWaitSemaphores;
              struct_to_fill.bufferBindCount = bufferBindCount;
              struct_to_fill.pBufferBinds = pBufferBinds;
              struct_to_fill.imageOpaqueBindCount = imageOpaqueBindCount;
              struct_to_fill.pImageOpaqueBinds = pImageOpaqueBinds;
              struct_to_fill.imageBindCount = imageBindCount;
              struct_to_fill.pImageBinds = pImageBinds;
              struct_to_fill.signalSemaphoreCount = signalSemaphoreCount;
              struct_to_fill.pSignalSemaphores = pSignalSemaphores;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkFenceCreateInfo vkfFenceCreateInfo()
       {
              VkFenceCreateInfo struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSemaphoreCreateInfo vkfSemaphoreCreateInfo()
       {
              VkSemaphoreCreateInfo struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkEventCreateInfo vkfEventCreateInfo()
       {
              VkEventCreateInfo struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EVENT_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkQueryPoolCreateInfo vkfQueryPoolCreateInfo(VkQueryType queryType, uint32_t queryCount, VkQueryPipelineStatisticFlags pipelineStatistics)
       {
              VkQueryPoolCreateInfo struct_to_fill;
              struct_to_fill.queryType = queryType;
              struct_to_fill.queryCount = queryCount;
              struct_to_fill.pipelineStatistics = pipelineStatistics;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkBufferCreateInfo vkfBufferCreateInfo(VkDeviceSize size, VkBufferUsageFlags usage, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices)
       {
              VkBufferCreateInfo struct_to_fill;
              struct_to_fill.size = size;
              struct_to_fill.usage = usage;
              struct_to_fill.sharingMode = sharingMode;
              struct_to_fill.queueFamilyIndexCount = queueFamilyIndexCount;
              struct_to_fill.pQueueFamilyIndices = pQueueFamilyIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkBufferViewCreateInfo vkfBufferViewCreateInfo(VkBuffer buffer, VkFormat format, VkDeviceSize offset, VkDeviceSize range)
       {
              VkBufferViewCreateInfo struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.format = format;
              struct_to_fill.offset = offset;
              struct_to_fill.range = range;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkImageCreateInfo vkfImageCreateInfo(VkImageType imageType, VkFormat format, VkExtent3D extent, uint32_t mipLevels, uint32_t arrayLayers, VkSampleCountFlagBits samples, VkImageTiling tiling, VkImageUsageFlags usage, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices, VkImageLayout initialLayout)
       {
              VkImageCreateInfo struct_to_fill;
              struct_to_fill.imageType = imageType;
              struct_to_fill.format = format;
              struct_to_fill.extent = extent;
              struct_to_fill.mipLevels = mipLevels;
              struct_to_fill.arrayLayers = arrayLayers;
              struct_to_fill.samples = samples;
              struct_to_fill.tiling = tiling;
              struct_to_fill.usage = usage;
              struct_to_fill.sharingMode = sharingMode;
              struct_to_fill.queueFamilyIndexCount = queueFamilyIndexCount;
              struct_to_fill.pQueueFamilyIndices = pQueueFamilyIndices;
              struct_to_fill.initialLayout = initialLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSubresourceLayout vkfSubresourceLayout(VkDeviceSize offset, VkDeviceSize size, VkDeviceSize rowPitch, VkDeviceSize arrayPitch, VkDeviceSize depthPitch)
       {
              VkSubresourceLayout struct_to_fill;
              struct_to_fill.offset = offset;
              struct_to_fill.size = size;
              struct_to_fill.rowPitch = rowPitch;
              struct_to_fill.arrayPitch = arrayPitch;
              struct_to_fill.depthPitch = depthPitch;
              return struct_to_fill;
       }
       static inline VkComponentMapping vkfComponentMapping(VkComponentSwizzle r, VkComponentSwizzle g, VkComponentSwizzle b, VkComponentSwizzle a)
       {
              VkComponentMapping struct_to_fill;
              struct_to_fill.r = r;
              struct_to_fill.g = g;
              struct_to_fill.b = b;
              struct_to_fill.a = a;
              return struct_to_fill;
       }
       static inline VkImageSubresourceRange vkfImageSubresourceRange(VkImageAspectFlags aspectMask, uint32_t baseMipLevel, uint32_t levelCount, uint32_t baseArrayLayer, uint32_t layerCount)
       {
              VkImageSubresourceRange struct_to_fill;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.baseMipLevel = baseMipLevel;
              struct_to_fill.levelCount = levelCount;
              struct_to_fill.baseArrayLayer = baseArrayLayer;
              struct_to_fill.layerCount = layerCount;
              return struct_to_fill;
       }
       static inline VkImageViewCreateInfo vkfImageViewCreateInfo(VkImage image, VkImageViewType viewType, VkFormat format, VkComponentMapping components, VkImageSubresourceRange subresourceRange)
       {
              VkImageViewCreateInfo struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.viewType = viewType;
              struct_to_fill.format = format;
              struct_to_fill.components = components;
              struct_to_fill.subresourceRange = subresourceRange;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkShaderModuleCreateInfo vkfShaderModuleCreateInfo(size_t codeSize, const uint32_t *pCode)
       {
              VkShaderModuleCreateInfo struct_to_fill;
              struct_to_fill.codeSize = codeSize;
              struct_to_fill.pCode = pCode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineCacheCreateInfo vkfPipelineCacheCreateInfo(size_t initialDataSize, const void *pInitialData)
       {
              VkPipelineCacheCreateInfo struct_to_fill;
              struct_to_fill.initialDataSize = initialDataSize;
              struct_to_fill.pInitialData = pInitialData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSpecializationMapEntry vkfSpecializationMapEntry(uint32_t constantID, uint32_t offset, size_t size)
       {
              VkSpecializationMapEntry struct_to_fill;
              struct_to_fill.constantID = constantID;
              struct_to_fill.offset = offset;
              struct_to_fill.size = size;
              return struct_to_fill;
       }
       static inline VkSpecializationInfo vkfSpecializationInfo(uint32_t mapEntryCount, const VkSpecializationMapEntry *pMapEntries, size_t dataSize, const void *pData)
       {
              VkSpecializationInfo struct_to_fill;
              struct_to_fill.mapEntryCount = mapEntryCount;
              struct_to_fill.pMapEntries = pMapEntries;
              struct_to_fill.dataSize = dataSize;
              struct_to_fill.pData = pData;
              return struct_to_fill;
       }
       static inline VkPipelineShaderStageCreateInfo vkfPipelineShaderStageCreateInfo(VkShaderStageFlagBits stage, VkShaderModule module, const char *pName, const VkSpecializationInfo *pSpecializationInfo)
       {
              VkPipelineShaderStageCreateInfo struct_to_fill;
              struct_to_fill.stage = stage;
              struct_to_fill.module = module;
              struct_to_fill.pName = pName;
              struct_to_fill.pSpecializationInfo = pSpecializationInfo;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkVertexInputBindingDescription vkfVertexInputBindingDescription(uint32_t binding, uint32_t stride, VkVertexInputRate inputRate)
       {
              VkVertexInputBindingDescription struct_to_fill;
              struct_to_fill.binding = binding;
              struct_to_fill.stride = stride;
              struct_to_fill.inputRate = inputRate;
              return struct_to_fill;
       }
       static inline VkVertexInputAttributeDescription vkfVertexInputAttributeDescription(uint32_t location, uint32_t binding, VkFormat format, uint32_t offset)
       {
              VkVertexInputAttributeDescription struct_to_fill;
              struct_to_fill.location = location;
              struct_to_fill.binding = binding;
              struct_to_fill.format = format;
              struct_to_fill.offset = offset;
              return struct_to_fill;
       }
       static inline VkPipelineVertexInputStateCreateInfo vkfPipelineVertexInputStateCreateInfo(uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription *pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription *pVertexAttributeDescriptions)
       {
              VkPipelineVertexInputStateCreateInfo struct_to_fill;
              struct_to_fill.vertexBindingDescriptionCount = vertexBindingDescriptionCount;
              struct_to_fill.pVertexBindingDescriptions = pVertexBindingDescriptions;
              struct_to_fill.vertexAttributeDescriptionCount = vertexAttributeDescriptionCount;
              struct_to_fill.pVertexAttributeDescriptions = pVertexAttributeDescriptions;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineInputAssemblyStateCreateInfo vkfPipelineInputAssemblyStateCreateInfo(VkPrimitiveTopology topology, VkBool32 primitiveRestartEnable)
       {
              VkPipelineInputAssemblyStateCreateInfo struct_to_fill;
              struct_to_fill.topology = topology;
              struct_to_fill.primitiveRestartEnable = primitiveRestartEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineTessellationStateCreateInfo vkfPipelineTessellationStateCreateInfo(uint32_t patchControlPoints)
       {
              VkPipelineTessellationStateCreateInfo struct_to_fill;
              struct_to_fill.patchControlPoints = patchControlPoints;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkViewport vkfViewport(float x, float y, float width, float height, float minDepth, float maxDepth)
       {
              VkViewport struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              struct_to_fill.width = width;
              struct_to_fill.height = height;
              struct_to_fill.minDepth = minDepth;
              struct_to_fill.maxDepth = maxDepth;
              return struct_to_fill;
       }
       static inline VkOffset2D vkfOffset2D(int32_t x, int32_t y)
       {
              VkOffset2D struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              return struct_to_fill;
       }
       static inline VkExtent2D vkfExtent2D(uint32_t width, uint32_t height)
       {
              VkExtent2D struct_to_fill;
              struct_to_fill.width = width;
              struct_to_fill.height = height;
              return struct_to_fill;
       }
       static inline VkRect2D vkfRect2D(VkOffset2D offset, VkExtent2D extent)
       {
              VkRect2D struct_to_fill;
              struct_to_fill.offset = offset;
              struct_to_fill.extent = extent;
              return struct_to_fill;
       }
       static inline VkPipelineViewportStateCreateInfo vkfPipelineViewportStateCreateInfo(uint32_t viewportCount, const VkViewport *pViewports, uint32_t scissorCount, const VkRect2D *pScissors)
       {
              VkPipelineViewportStateCreateInfo struct_to_fill;
              struct_to_fill.viewportCount = viewportCount;
              struct_to_fill.pViewports = pViewports;
              struct_to_fill.scissorCount = scissorCount;
              struct_to_fill.pScissors = pScissors;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineRasterizationStateCreateInfo vkfPipelineRasterizationStateCreateInfo(VkBool32 depthClampEnable, VkBool32 rasterizerDiscardEnable, VkPolygonMode polygonMode, VkCullModeFlags cullMode, VkFrontFace frontFace, VkBool32 depthBiasEnable, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor, float lineWidth)
       {
              VkPipelineRasterizationStateCreateInfo struct_to_fill;
              struct_to_fill.depthClampEnable = depthClampEnable;
              struct_to_fill.rasterizerDiscardEnable = rasterizerDiscardEnable;
              struct_to_fill.polygonMode = polygonMode;
              struct_to_fill.cullMode = cullMode;
              struct_to_fill.frontFace = frontFace;
              struct_to_fill.depthBiasEnable = depthBiasEnable;
              struct_to_fill.depthBiasConstantFactor = depthBiasConstantFactor;
              struct_to_fill.depthBiasClamp = depthBiasClamp;
              struct_to_fill.depthBiasSlopeFactor = depthBiasSlopeFactor;
              struct_to_fill.lineWidth = lineWidth;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineMultisampleStateCreateInfo vkfPipelineMultisampleStateCreateInfo(VkSampleCountFlagBits rasterizationSamples, VkBool32 sampleShadingEnable, float minSampleShading, const VkSampleMask *pSampleMask, VkBool32 alphaToCoverageEnable, VkBool32 alphaToOneEnable)
       {
              VkPipelineMultisampleStateCreateInfo struct_to_fill;
              struct_to_fill.rasterizationSamples = rasterizationSamples;
              struct_to_fill.sampleShadingEnable = sampleShadingEnable;
              struct_to_fill.minSampleShading = minSampleShading;
              struct_to_fill.pSampleMask = pSampleMask;
              struct_to_fill.alphaToCoverageEnable = alphaToCoverageEnable;
              struct_to_fill.alphaToOneEnable = alphaToOneEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkStencilOpState vkfStencilOpState(VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp, uint32_t compareMask, uint32_t writeMask, uint32_t reference)
       {
              VkStencilOpState struct_to_fill;
              struct_to_fill.failOp = failOp;
              struct_to_fill.passOp = passOp;
              struct_to_fill.depthFailOp = depthFailOp;
              struct_to_fill.compareOp = compareOp;
              struct_to_fill.compareMask = compareMask;
              struct_to_fill.writeMask = writeMask;
              struct_to_fill.reference = reference;
              return struct_to_fill;
       }
       static inline VkPipelineDepthStencilStateCreateInfo vkfPipelineDepthStencilStateCreateInfo(VkBool32 depthTestEnable, VkBool32 depthWriteEnable, VkCompareOp depthCompareOp, VkBool32 depthBoundsTestEnable, VkBool32 stencilTestEnable, VkStencilOpState front, VkStencilOpState back, float minDepthBounds, float maxDepthBounds)
       {
              VkPipelineDepthStencilStateCreateInfo struct_to_fill;
              struct_to_fill.depthTestEnable = depthTestEnable;
              struct_to_fill.depthWriteEnable = depthWriteEnable;
              struct_to_fill.depthCompareOp = depthCompareOp;
              struct_to_fill.depthBoundsTestEnable = depthBoundsTestEnable;
              struct_to_fill.stencilTestEnable = stencilTestEnable;
              struct_to_fill.front = front;
              struct_to_fill.back = back;
              struct_to_fill.minDepthBounds = minDepthBounds;
              struct_to_fill.maxDepthBounds = maxDepthBounds;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineColorBlendAttachmentState vkfPipelineColorBlendAttachmentState(VkBool32 blendEnable, VkBlendFactor srcColorBlendFactor, VkBlendFactor dstColorBlendFactor, VkBlendOp colorBlendOp, VkBlendFactor srcAlphaBlendFactor, VkBlendFactor dstAlphaBlendFactor, VkBlendOp alphaBlendOp, VkColorComponentFlags colorWriteMask)
       {
              VkPipelineColorBlendAttachmentState struct_to_fill;
              struct_to_fill.blendEnable = blendEnable;
              struct_to_fill.srcColorBlendFactor = srcColorBlendFactor;
              struct_to_fill.dstColorBlendFactor = dstColorBlendFactor;
              struct_to_fill.colorBlendOp = colorBlendOp;
              struct_to_fill.srcAlphaBlendFactor = srcAlphaBlendFactor;
              struct_to_fill.dstAlphaBlendFactor = dstAlphaBlendFactor;
              struct_to_fill.alphaBlendOp = alphaBlendOp;
              struct_to_fill.colorWriteMask = colorWriteMask;
              return struct_to_fill;
       }
       static inline VkPipelineColorBlendStateCreateInfo vkfPipelineColorBlendStateCreateInfo(VkBool32 logicOpEnable, VkLogicOp logicOp, uint32_t attachmentCount, const VkPipelineColorBlendAttachmentState *pAttachments)
       {
              VkPipelineColorBlendStateCreateInfo struct_to_fill;
              struct_to_fill.logicOpEnable = logicOpEnable;
              struct_to_fill.logicOp = logicOp;
              struct_to_fill.attachmentCount = attachmentCount;
              struct_to_fill.pAttachments = pAttachments;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineDynamicStateCreateInfo vkfPipelineDynamicStateCreateInfo(uint32_t dynamicStateCount, const VkDynamicState *pDynamicStates)
       {
              VkPipelineDynamicStateCreateInfo struct_to_fill;
              struct_to_fill.dynamicStateCount = dynamicStateCount;
              struct_to_fill.pDynamicStates = pDynamicStates;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkGraphicsPipelineCreateInfo vkfGraphicsPipelineCreateInfo(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, const VkPipelineVertexInputStateCreateInfo *pVertexInputState, const VkPipelineInputAssemblyStateCreateInfo *pInputAssemblyState, const VkPipelineTessellationStateCreateInfo *pTessellationState, const VkPipelineViewportStateCreateInfo *pViewportState, const VkPipelineRasterizationStateCreateInfo *pRasterizationState, const VkPipelineMultisampleStateCreateInfo *pMultisampleState, const VkPipelineDepthStencilStateCreateInfo *pDepthStencilState, const VkPipelineColorBlendStateCreateInfo *pColorBlendState, const VkPipelineDynamicStateCreateInfo *pDynamicState, VkPipelineLayout layout, VkRenderPass renderPass, uint32_t subpass, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
       {
              VkGraphicsPipelineCreateInfo struct_to_fill;
              struct_to_fill.stageCount = stageCount;
              struct_to_fill.pStages = pStages;
              struct_to_fill.pVertexInputState = pVertexInputState;
              struct_to_fill.pInputAssemblyState = pInputAssemblyState;
              struct_to_fill.pTessellationState = pTessellationState;
              struct_to_fill.pViewportState = pViewportState;
              struct_to_fill.pRasterizationState = pRasterizationState;
              struct_to_fill.pMultisampleState = pMultisampleState;
              struct_to_fill.pDepthStencilState = pDepthStencilState;
              struct_to_fill.pColorBlendState = pColorBlendState;
              struct_to_fill.pDynamicState = pDynamicState;
              struct_to_fill.layout = layout;
              struct_to_fill.renderPass = renderPass;
              struct_to_fill.subpass = subpass;
              struct_to_fill.basePipelineHandle = basePipelineHandle;
              struct_to_fill.basePipelineIndex = basePipelineIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkComputePipelineCreateInfo vkfComputePipelineCreateInfo(VkPipelineShaderStageCreateInfo stage, VkPipelineLayout layout, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
       {
              VkComputePipelineCreateInfo struct_to_fill;
              struct_to_fill.stage = stage;
              struct_to_fill.layout = layout;
              struct_to_fill.basePipelineHandle = basePipelineHandle;
              struct_to_fill.basePipelineIndex = basePipelineIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPushConstantRange vkfPushConstantRange(VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size)
       {
              VkPushConstantRange struct_to_fill;
              struct_to_fill.stageFlags = stageFlags;
              struct_to_fill.offset = offset;
              struct_to_fill.size = size;
              return struct_to_fill;
       }
       static inline VkPipelineLayoutCreateInfo vkfPipelineLayoutCreateInfo(uint32_t setLayoutCount, const VkDescriptorSetLayout *pSetLayouts, uint32_t pushConstantRangeCount, const VkPushConstantRange *pPushConstantRanges)
       {
              VkPipelineLayoutCreateInfo struct_to_fill;
              struct_to_fill.setLayoutCount = setLayoutCount;
              struct_to_fill.pSetLayouts = pSetLayouts;
              struct_to_fill.pushConstantRangeCount = pushConstantRangeCount;
              struct_to_fill.pPushConstantRanges = pPushConstantRanges;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSamplerCreateInfo vkfSamplerCreateInfo(VkFilter magFilter, VkFilter minFilter, VkSamplerMipmapMode mipmapMode, VkSamplerAddressMode addressModeU, VkSamplerAddressMode addressModeV, VkSamplerAddressMode addressModeW, float mipLodBias, VkBool32 anisotropyEnable, float maxAnisotropy, VkBool32 compareEnable, VkCompareOp compareOp, float minLod, float maxLod, VkBorderColor borderColor, VkBool32 unnormalizedCoordinates)
       {
              VkSamplerCreateInfo struct_to_fill;
              struct_to_fill.magFilter = magFilter;
              struct_to_fill.minFilter = minFilter;
              struct_to_fill.mipmapMode = mipmapMode;
              struct_to_fill.addressModeU = addressModeU;
              struct_to_fill.addressModeV = addressModeV;
              struct_to_fill.addressModeW = addressModeW;
              struct_to_fill.mipLodBias = mipLodBias;
              struct_to_fill.anisotropyEnable = anisotropyEnable;
              struct_to_fill.maxAnisotropy = maxAnisotropy;
              struct_to_fill.compareEnable = compareEnable;
              struct_to_fill.compareOp = compareOp;
              struct_to_fill.minLod = minLod;
              struct_to_fill.maxLod = maxLod;
              struct_to_fill.borderColor = borderColor;
              struct_to_fill.unnormalizedCoordinates = unnormalizedCoordinates;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDescriptorSetLayoutBinding vkfDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, uint32_t descriptorCount, VkShaderStageFlags stageFlags, const VkSampler *pImmutableSamplers)
       {
              VkDescriptorSetLayoutBinding struct_to_fill;
              struct_to_fill.binding = binding;
              struct_to_fill.descriptorType = descriptorType;
              struct_to_fill.descriptorCount = descriptorCount;
              struct_to_fill.stageFlags = stageFlags;
              struct_to_fill.pImmutableSamplers = pImmutableSamplers;
              return struct_to_fill;
       }
       static inline VkDescriptorSetLayoutCreateInfo vkfDescriptorSetLayoutCreateInfo(uint32_t bindingCount, const VkDescriptorSetLayoutBinding *pBindings)
       {
              VkDescriptorSetLayoutCreateInfo struct_to_fill;
              struct_to_fill.bindingCount = bindingCount;
              struct_to_fill.pBindings = pBindings;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDescriptorPoolSize vkfDescriptorPoolSize(VkDescriptorType type, uint32_t descriptorCount)
       {
              VkDescriptorPoolSize struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.descriptorCount = descriptorCount;
              return struct_to_fill;
       }
       static inline VkDescriptorPoolCreateInfo vkfDescriptorPoolCreateInfo(uint32_t maxSets, uint32_t poolSizeCount, const VkDescriptorPoolSize *pPoolSizes)
       {
              VkDescriptorPoolCreateInfo struct_to_fill;
              struct_to_fill.maxSets = maxSets;
              struct_to_fill.poolSizeCount = poolSizeCount;
              struct_to_fill.pPoolSizes = pPoolSizes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDescriptorSetAllocateInfo vkfDescriptorSetAllocateInfo(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSetLayout *pSetLayouts)
       {
              VkDescriptorSetAllocateInfo struct_to_fill;
              struct_to_fill.descriptorPool = descriptorPool;
              struct_to_fill.descriptorSetCount = descriptorSetCount;
              struct_to_fill.pSetLayouts = pSetLayouts;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorImageInfo vkfDescriptorImageInfo(VkSampler sampler, VkImageView imageView, VkImageLayout imageLayout)
       {
              VkDescriptorImageInfo struct_to_fill;
              struct_to_fill.sampler = sampler;
              struct_to_fill.imageView = imageView;
              struct_to_fill.imageLayout = imageLayout;
              return struct_to_fill;
       }
       static inline VkDescriptorBufferInfo vkfDescriptorBufferInfo(VkBuffer buffer, VkDeviceSize offset, VkDeviceSize range)
       {
              VkDescriptorBufferInfo struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.offset = offset;
              struct_to_fill.range = range;
              return struct_to_fill;
       }
       static inline VkWriteDescriptorSet vkfWriteDescriptorSet(VkDescriptorSet dstSet, uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount, VkDescriptorType descriptorType, const VkDescriptorImageInfo *pImageInfo, const VkDescriptorBufferInfo *pBufferInfo, const VkBufferView *pTexelBufferView)
       {
              VkWriteDescriptorSet struct_to_fill;
              struct_to_fill.dstSet = dstSet;
              struct_to_fill.dstBinding = dstBinding;
              struct_to_fill.dstArrayElement = dstArrayElement;
              struct_to_fill.descriptorCount = descriptorCount;
              struct_to_fill.descriptorType = descriptorType;
              struct_to_fill.pImageInfo = pImageInfo;
              struct_to_fill.pBufferInfo = pBufferInfo;
              struct_to_fill.pTexelBufferView = pTexelBufferView;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCopyDescriptorSet vkfCopyDescriptorSet(VkDescriptorSet srcSet, uint32_t srcBinding, uint32_t srcArrayElement, VkDescriptorSet dstSet, uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount)
       {
              VkCopyDescriptorSet struct_to_fill;
              struct_to_fill.srcSet = srcSet;
              struct_to_fill.srcBinding = srcBinding;
              struct_to_fill.srcArrayElement = srcArrayElement;
              struct_to_fill.dstSet = dstSet;
              struct_to_fill.dstBinding = dstBinding;
              struct_to_fill.dstArrayElement = dstArrayElement;
              struct_to_fill.descriptorCount = descriptorCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkFramebufferCreateInfo vkfFramebufferCreateInfo(VkRenderPass renderPass, uint32_t attachmentCount, const VkImageView *pAttachments, uint32_t width, uint32_t height, uint32_t layers)
       {
              VkFramebufferCreateInfo struct_to_fill;
              struct_to_fill.renderPass = renderPass;
              struct_to_fill.attachmentCount = attachmentCount;
              struct_to_fill.pAttachments = pAttachments;
              struct_to_fill.width = width;
              struct_to_fill.height = height;
              struct_to_fill.layers = layers;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAttachmentDescription vkfAttachmentDescription(VkFormat format, VkSampleCountFlagBits samples, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkAttachmentLoadOp stencilLoadOp, VkAttachmentStoreOp stencilStoreOp, VkImageLayout initialLayout, VkImageLayout finalLayout)
       {
              VkAttachmentDescription struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.samples = samples;
              struct_to_fill.loadOp = loadOp;
              struct_to_fill.storeOp = storeOp;
              struct_to_fill.stencilLoadOp = stencilLoadOp;
              struct_to_fill.stencilStoreOp = stencilStoreOp;
              struct_to_fill.initialLayout = initialLayout;
              struct_to_fill.finalLayout = finalLayout;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAttachmentReference vkfAttachmentReference(uint32_t attachment, VkImageLayout layout)
       {
              VkAttachmentReference struct_to_fill;
              struct_to_fill.attachment = attachment;
              struct_to_fill.layout = layout;
              return struct_to_fill;
       }
       static inline VkSubpassDescription vkfSubpassDescription(VkPipelineBindPoint pipelineBindPoint, uint32_t inputAttachmentCount, const VkAttachmentReference *pInputAttachments, uint32_t colorAttachmentCount, const VkAttachmentReference *pColorAttachments, const VkAttachmentReference *pResolveAttachments, const VkAttachmentReference *pDepthStencilAttachment, uint32_t preserveAttachmentCount, const uint32_t *pPreserveAttachments)
       {
              VkSubpassDescription struct_to_fill;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.inputAttachmentCount = inputAttachmentCount;
              struct_to_fill.pInputAttachments = pInputAttachments;
              struct_to_fill.colorAttachmentCount = colorAttachmentCount;
              struct_to_fill.pColorAttachments = pColorAttachments;
              struct_to_fill.pResolveAttachments = pResolveAttachments;
              struct_to_fill.pDepthStencilAttachment = pDepthStencilAttachment;
              struct_to_fill.preserveAttachmentCount = preserveAttachmentCount;
              struct_to_fill.pPreserveAttachments = pPreserveAttachments;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSubpassDependency vkfSubpassDependency(uint32_t srcSubpass, uint32_t dstSubpass, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkDependencyFlags dependencyFlags)
       {
              VkSubpassDependency struct_to_fill;
              struct_to_fill.srcSubpass = srcSubpass;
              struct_to_fill.dstSubpass = dstSubpass;
              struct_to_fill.srcStageMask = srcStageMask;
              struct_to_fill.dstStageMask = dstStageMask;
              struct_to_fill.srcAccessMask = srcAccessMask;
              struct_to_fill.dstAccessMask = dstAccessMask;
              struct_to_fill.dependencyFlags = dependencyFlags;
              return struct_to_fill;
       }
       static inline VkRenderPassCreateInfo vkfRenderPassCreateInfo(uint32_t attachmentCount, const VkAttachmentDescription *pAttachments, uint32_t subpassCount, const VkSubpassDescription *pSubpasses, uint32_t dependencyCount, const VkSubpassDependency *pDependencies)
       {
              VkRenderPassCreateInfo struct_to_fill;
              struct_to_fill.attachmentCount = attachmentCount;
              struct_to_fill.pAttachments = pAttachments;
              struct_to_fill.subpassCount = subpassCount;
              struct_to_fill.pSubpasses = pSubpasses;
              struct_to_fill.dependencyCount = dependencyCount;
              struct_to_fill.pDependencies = pDependencies;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkCommandPoolCreateInfo vkfCommandPoolCreateInfo(uint32_t queueFamilyIndex)
       {
              VkCommandPoolCreateInfo struct_to_fill;
              struct_to_fill.queueFamilyIndex = queueFamilyIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkCommandBufferAllocateInfo vkfCommandBufferAllocateInfo(VkCommandPool commandPool, VkCommandBufferLevel level, uint32_t commandBufferCount)
       {
              VkCommandBufferAllocateInfo struct_to_fill;
              struct_to_fill.commandPool = commandPool;
              struct_to_fill.level = level;
              struct_to_fill.commandBufferCount = commandBufferCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCommandBufferInheritanceInfo vkfCommandBufferInheritanceInfo(VkRenderPass renderPass, uint32_t subpass, VkFramebuffer framebuffer, VkBool32 occlusionQueryEnable, VkQueryControlFlags queryFlags, VkQueryPipelineStatisticFlags pipelineStatistics)
       {
              VkCommandBufferInheritanceInfo struct_to_fill;
              struct_to_fill.renderPass = renderPass;
              struct_to_fill.subpass = subpass;
              struct_to_fill.framebuffer = framebuffer;
              struct_to_fill.occlusionQueryEnable = occlusionQueryEnable;
              struct_to_fill.queryFlags = queryFlags;
              struct_to_fill.pipelineStatistics = pipelineStatistics;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCommandBufferBeginInfo vkfCommandBufferBeginInfo(const VkCommandBufferInheritanceInfo *pInheritanceInfo)
       {
              VkCommandBufferBeginInfo struct_to_fill;
              struct_to_fill.pInheritanceInfo = pInheritanceInfo;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkBufferCopy vkfBufferCopy(VkDeviceSize srcOffset, VkDeviceSize dstOffset, VkDeviceSize size)
       {
              VkBufferCopy struct_to_fill;
              struct_to_fill.srcOffset = srcOffset;
              struct_to_fill.dstOffset = dstOffset;
              struct_to_fill.size = size;
              return struct_to_fill;
       }
       static inline VkImageSubresourceLayers vkfImageSubresourceLayers(VkImageAspectFlags aspectMask, uint32_t mipLevel, uint32_t baseArrayLayer, uint32_t layerCount)
       {
              VkImageSubresourceLayers struct_to_fill;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.mipLevel = mipLevel;
              struct_to_fill.baseArrayLayer = baseArrayLayer;
              struct_to_fill.layerCount = layerCount;
              return struct_to_fill;
       }
       static inline VkImageCopy vkfImageCopy(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
       {
              VkImageCopy struct_to_fill;
              struct_to_fill.srcSubresource = srcSubresource;
              struct_to_fill.srcOffset = srcOffset;
              struct_to_fill.dstSubresource = dstSubresource;
              struct_to_fill.dstOffset = dstOffset;
              struct_to_fill.extent = extent;
              return struct_to_fill;
       }
       static inline VkImageBlit vkfImageBlit(VkImageSubresourceLayers srcSubresource, VkImageSubresourceLayers dstSubresource)
       {
              VkImageBlit struct_to_fill;
              struct_to_fill.srcSubresource = srcSubresource;
              struct_to_fill.dstSubresource = dstSubresource;
              return struct_to_fill;
       }
       static inline VkBufferImageCopy vkfBufferImageCopy(VkDeviceSize bufferOffset, uint32_t bufferRowLength, uint32_t bufferImageHeight, VkImageSubresourceLayers imageSubresource, VkOffset3D imageOffset, VkExtent3D imageExtent)
       {
              VkBufferImageCopy struct_to_fill;
              struct_to_fill.bufferOffset = bufferOffset;
              struct_to_fill.bufferRowLength = bufferRowLength;
              struct_to_fill.bufferImageHeight = bufferImageHeight;
              struct_to_fill.imageSubresource = imageSubresource;
              struct_to_fill.imageOffset = imageOffset;
              struct_to_fill.imageExtent = imageExtent;
              return struct_to_fill;
       }
       static inline VkClearDepthStencilValue vkfClearDepthStencilValue(float depth, uint32_t stencil)
       {
              VkClearDepthStencilValue struct_to_fill;
              struct_to_fill.depth = depth;
              struct_to_fill.stencil = stencil;
              return struct_to_fill;
       }
       static inline VkClearAttachment vkfClearAttachment(VkImageAspectFlags aspectMask, uint32_t colorAttachment, VkClearValue clearValue)
       {
              VkClearAttachment struct_to_fill;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.colorAttachment = colorAttachment;
              struct_to_fill.clearValue = clearValue;
              return struct_to_fill;
       }
       static inline VkClearRect vkfClearRect(VkRect2D rect, uint32_t baseArrayLayer, uint32_t layerCount)
       {
              VkClearRect struct_to_fill;
              struct_to_fill.rect = rect;
              struct_to_fill.baseArrayLayer = baseArrayLayer;
              struct_to_fill.layerCount = layerCount;
              return struct_to_fill;
       }
       static inline VkImageResolve vkfImageResolve(VkImageSubresourceLayers srcSubresource, VkOffset3D srcOffset, VkImageSubresourceLayers dstSubresource, VkOffset3D dstOffset, VkExtent3D extent)
       {
              VkImageResolve struct_to_fill;
              struct_to_fill.srcSubresource = srcSubresource;
              struct_to_fill.srcOffset = srcOffset;
              struct_to_fill.dstSubresource = dstSubresource;
              struct_to_fill.dstOffset = dstOffset;
              struct_to_fill.extent = extent;
              return struct_to_fill;
       }
       static inline VkMemoryBarrier vkfMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask)
       {
              VkMemoryBarrier struct_to_fill;
              struct_to_fill.srcAccessMask = srcAccessMask;
              struct_to_fill.dstAccessMask = dstAccessMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBufferMemoryBarrier vkfBufferMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size)
       {
              VkBufferMemoryBarrier struct_to_fill;
              struct_to_fill.srcAccessMask = srcAccessMask;
              struct_to_fill.dstAccessMask = dstAccessMask;
              struct_to_fill.srcQueueFamilyIndex = srcQueueFamilyIndex;
              struct_to_fill.dstQueueFamilyIndex = dstQueueFamilyIndex;
              struct_to_fill.buffer = buffer;
              struct_to_fill.offset = offset;
              struct_to_fill.size = size;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageMemoryBarrier vkfImageMemoryBarrier(VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t srcQueueFamilyIndex, uint32_t dstQueueFamilyIndex, VkImage image, VkImageSubresourceRange subresourceRange)
       {
              VkImageMemoryBarrier struct_to_fill;
              struct_to_fill.srcAccessMask = srcAccessMask;
              struct_to_fill.dstAccessMask = dstAccessMask;
              struct_to_fill.oldLayout = oldLayout;
              struct_to_fill.newLayout = newLayout;
              struct_to_fill.srcQueueFamilyIndex = srcQueueFamilyIndex;
              struct_to_fill.dstQueueFamilyIndex = dstQueueFamilyIndex;
              struct_to_fill.image = image;
              struct_to_fill.subresourceRange = subresourceRange;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRenderPassBeginInfo vkfRenderPassBeginInfo(VkRenderPass renderPass, VkFramebuffer framebuffer, VkRect2D renderArea, uint32_t clearValueCount, const VkClearValue *pClearValues)
       {
              VkRenderPassBeginInfo struct_to_fill;
              struct_to_fill.renderPass = renderPass;
              struct_to_fill.framebuffer = framebuffer;
              struct_to_fill.renderArea = renderArea;
              struct_to_fill.clearValueCount = clearValueCount;
              struct_to_fill.pClearValues = pClearValues;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDispatchIndirectCommand vkfDispatchIndirectCommand(uint32_t x, uint32_t y, uint32_t z)
       {
              VkDispatchIndirectCommand struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              struct_to_fill.z = z;
              return struct_to_fill;
       }
       static inline VkDrawIndexedIndirectCommand vkfDrawIndexedIndirectCommand(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
       {
              VkDrawIndexedIndirectCommand struct_to_fill;
              struct_to_fill.indexCount = indexCount;
              struct_to_fill.instanceCount = instanceCount;
              struct_to_fill.firstIndex = firstIndex;
              struct_to_fill.vertexOffset = vertexOffset;
              struct_to_fill.firstInstance = firstInstance;
              return struct_to_fill;
       }
       static inline VkDrawIndirectCommand vkfDrawIndirectCommand(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
       {
              VkDrawIndirectCommand struct_to_fill;
              struct_to_fill.vertexCount = vertexCount;
              struct_to_fill.instanceCount = instanceCount;
              struct_to_fill.firstVertex = firstVertex;
              struct_to_fill.firstInstance = firstInstance;
              return struct_to_fill;
       }
#endif //VK_VERSION_1_0
#ifdef VK_VERSION_1_1
       static inline VkPhysicalDeviceSubgroupProperties vkfPhysicalDeviceSubgroupProperties(uint32_t subgroupSize, VkShaderStageFlags supportedStages, VkSubgroupFeatureFlags supportedOperations, VkBool32 quadOperationsInAllStages)
       {
              VkPhysicalDeviceSubgroupProperties struct_to_fill;
              struct_to_fill.subgroupSize = subgroupSize;
              struct_to_fill.supportedStages = supportedStages;
              struct_to_fill.supportedOperations = supportedOperations;
              struct_to_fill.quadOperationsInAllStages = quadOperationsInAllStages;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindBufferMemoryInfo vkfBindBufferMemoryInfo(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
       {
              VkBindBufferMemoryInfo struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.memory = memory;
              struct_to_fill.memoryOffset = memoryOffset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindImageMemoryInfo vkfBindImageMemoryInfo(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
       {
              VkBindImageMemoryInfo struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.memory = memory;
              struct_to_fill.memoryOffset = memoryOffset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDevice16BitStorageFeatures vkfPhysicalDevice16BitStorageFeatures(VkBool32 storageBuffer16BitAccess, VkBool32 uniformAndStorageBuffer16BitAccess, VkBool32 storagePushConstant16, VkBool32 storageInputOutput16)
       {
              VkPhysicalDevice16BitStorageFeatures struct_to_fill;
              struct_to_fill.storageBuffer16BitAccess = storageBuffer16BitAccess;
              struct_to_fill.uniformAndStorageBuffer16BitAccess = uniformAndStorageBuffer16BitAccess;
              struct_to_fill.storagePushConstant16 = storagePushConstant16;
              struct_to_fill.storageInputOutput16 = storageInputOutput16;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryDedicatedRequirements vkfMemoryDedicatedRequirements(VkBool32 prefersDedicatedAllocation, VkBool32 requiresDedicatedAllocation)
       {
              VkMemoryDedicatedRequirements struct_to_fill;
              struct_to_fill.prefersDedicatedAllocation = prefersDedicatedAllocation;
              struct_to_fill.requiresDedicatedAllocation = requiresDedicatedAllocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryDedicatedAllocateInfo vkfMemoryDedicatedAllocateInfo(VkImage image, VkBuffer buffer)
       {
              VkMemoryDedicatedAllocateInfo struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.buffer = buffer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryAllocateFlagsInfo vkfMemoryAllocateFlagsInfo(uint32_t deviceMask)
       {
              VkMemoryAllocateFlagsInfo struct_to_fill;
              struct_to_fill.deviceMask = deviceMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDeviceGroupRenderPassBeginInfo vkfDeviceGroupRenderPassBeginInfo(uint32_t deviceMask, uint32_t deviceRenderAreaCount, const VkRect2D *pDeviceRenderAreas)
       {
              VkDeviceGroupRenderPassBeginInfo struct_to_fill;
              struct_to_fill.deviceMask = deviceMask;
              struct_to_fill.deviceRenderAreaCount = deviceRenderAreaCount;
              struct_to_fill.pDeviceRenderAreas = pDeviceRenderAreas;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupCommandBufferBeginInfo vkfDeviceGroupCommandBufferBeginInfo(uint32_t deviceMask)
       {
              VkDeviceGroupCommandBufferBeginInfo struct_to_fill;
              struct_to_fill.deviceMask = deviceMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupSubmitInfo vkfDeviceGroupSubmitInfo(uint32_t waitSemaphoreCount, const uint32_t *pWaitSemaphoreDeviceIndices, uint32_t commandBufferCount, const uint32_t *pCommandBufferDeviceMasks, uint32_t signalSemaphoreCount, const uint32_t *pSignalSemaphoreDeviceIndices)
       {
              VkDeviceGroupSubmitInfo struct_to_fill;
              struct_to_fill.waitSemaphoreCount = waitSemaphoreCount;
              struct_to_fill.pWaitSemaphoreDeviceIndices = pWaitSemaphoreDeviceIndices;
              struct_to_fill.commandBufferCount = commandBufferCount;
              struct_to_fill.pCommandBufferDeviceMasks = pCommandBufferDeviceMasks;
              struct_to_fill.signalSemaphoreCount = signalSemaphoreCount;
              struct_to_fill.pSignalSemaphoreDeviceIndices = pSignalSemaphoreDeviceIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupBindSparseInfo vkfDeviceGroupBindSparseInfo(uint32_t resourceDeviceIndex, uint32_t memoryDeviceIndex)
       {
              VkDeviceGroupBindSparseInfo struct_to_fill;
              struct_to_fill.resourceDeviceIndex = resourceDeviceIndex;
              struct_to_fill.memoryDeviceIndex = memoryDeviceIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindBufferMemoryDeviceGroupInfo vkfBindBufferMemoryDeviceGroupInfo(uint32_t deviceIndexCount, const uint32_t *pDeviceIndices)
       {
              VkBindBufferMemoryDeviceGroupInfo struct_to_fill;
              struct_to_fill.deviceIndexCount = deviceIndexCount;
              struct_to_fill.pDeviceIndices = pDeviceIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindImageMemoryDeviceGroupInfo vkfBindImageMemoryDeviceGroupInfo(uint32_t deviceIndexCount, const uint32_t *pDeviceIndices, uint32_t splitInstanceBindRegionCount, const VkRect2D *pSplitInstanceBindRegions)
       {
              VkBindImageMemoryDeviceGroupInfo struct_to_fill;
              struct_to_fill.deviceIndexCount = deviceIndexCount;
              struct_to_fill.pDeviceIndices = pDeviceIndices;
              struct_to_fill.splitInstanceBindRegionCount = splitInstanceBindRegionCount;
              struct_to_fill.pSplitInstanceBindRegions = pSplitInstanceBindRegions;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceGroupProperties vkfPhysicalDeviceGroupProperties(uint32_t physicalDeviceCount, VkBool32 subsetAllocation)
       {
              VkPhysicalDeviceGroupProperties struct_to_fill;
              struct_to_fill.physicalDeviceCount = physicalDeviceCount;
              struct_to_fill.subsetAllocation = subsetAllocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupDeviceCreateInfo vkfDeviceGroupDeviceCreateInfo(uint32_t physicalDeviceCount, const VkPhysicalDevice *pPhysicalDevices)
       {
              VkDeviceGroupDeviceCreateInfo struct_to_fill;
              struct_to_fill.physicalDeviceCount = physicalDeviceCount;
              struct_to_fill.pPhysicalDevices = pPhysicalDevices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBufferMemoryRequirementsInfo2 vkfBufferMemoryRequirementsInfo2(VkBuffer buffer)
       {
              VkBufferMemoryRequirementsInfo2 struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageMemoryRequirementsInfo2 vkfImageMemoryRequirementsInfo2(VkImage image)
       {
              VkImageMemoryRequirementsInfo2 struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageSparseMemoryRequirementsInfo2 vkfImageSparseMemoryRequirementsInfo2(VkImage image)
       {
              VkImageSparseMemoryRequirementsInfo2 struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryRequirements2 vkfMemoryRequirements2(VkMemoryRequirements memoryRequirements)
       {
              VkMemoryRequirements2 struct_to_fill;
              struct_to_fill.memoryRequirements = memoryRequirements;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSparseImageMemoryRequirements2 vkfSparseImageMemoryRequirements2(VkSparseImageMemoryRequirements memoryRequirements)
       {
              VkSparseImageMemoryRequirements2 struct_to_fill;
              struct_to_fill.memoryRequirements = memoryRequirements;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceFeatures2 vkfPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures features)
       {
              VkPhysicalDeviceFeatures2 struct_to_fill;
              struct_to_fill.features = features;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceProperties2 vkfPhysicalDeviceProperties2(VkPhysicalDeviceProperties properties)
       {
              VkPhysicalDeviceProperties2 struct_to_fill;
              struct_to_fill.properties = properties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkFormatProperties2 vkfFormatProperties2(VkFormatProperties formatProperties)
       {
              VkFormatProperties2 struct_to_fill;
              struct_to_fill.formatProperties = formatProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageFormatProperties2 vkfImageFormatProperties2(VkImageFormatProperties imageFormatProperties)
       {
              VkImageFormatProperties2 struct_to_fill;
              struct_to_fill.imageFormatProperties = imageFormatProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceImageFormatInfo2 vkfPhysicalDeviceImageFormatInfo2(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage)
       {
              VkPhysicalDeviceImageFormatInfo2 struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.type = type;
              struct_to_fill.tiling = tiling;
              struct_to_fill.usage = usage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkQueueFamilyProperties2 vkfQueueFamilyProperties2(VkQueueFamilyProperties queueFamilyProperties)
       {
              VkQueueFamilyProperties2 struct_to_fill;
              struct_to_fill.queueFamilyProperties = queueFamilyProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMemoryProperties2 vkfPhysicalDeviceMemoryProperties2(VkPhysicalDeviceMemoryProperties memoryProperties)
       {
              VkPhysicalDeviceMemoryProperties2 struct_to_fill;
              struct_to_fill.memoryProperties = memoryProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSparseImageFormatProperties2 vkfSparseImageFormatProperties2(VkSparseImageFormatProperties properties)
       {
              VkSparseImageFormatProperties2 struct_to_fill;
              struct_to_fill.properties = properties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSparseImageFormatInfo2 vkfPhysicalDeviceSparseImageFormatInfo2(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling)
       {
              VkPhysicalDeviceSparseImageFormatInfo2 struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.type = type;
              struct_to_fill.samples = samples;
              struct_to_fill.usage = usage;
              struct_to_fill.tiling = tiling;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDevicePointClippingProperties vkfPhysicalDevicePointClippingProperties(VkPointClippingBehavior pointClippingBehavior)
       {
              VkPhysicalDevicePointClippingProperties struct_to_fill;
              struct_to_fill.pointClippingBehavior = pointClippingBehavior;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkInputAttachmentAspectReference vkfInputAttachmentAspectReference(uint32_t subpass, uint32_t inputAttachmentIndex, VkImageAspectFlags aspectMask)
       {
              VkInputAttachmentAspectReference struct_to_fill;
              struct_to_fill.subpass = subpass;
              struct_to_fill.inputAttachmentIndex = inputAttachmentIndex;
              struct_to_fill.aspectMask = aspectMask;
              return struct_to_fill;
       }
       static inline VkRenderPassInputAttachmentAspectCreateInfo vkfRenderPassInputAttachmentAspectCreateInfo(uint32_t aspectReferenceCount, const VkInputAttachmentAspectReference *pAspectReferences)
       {
              VkRenderPassInputAttachmentAspectCreateInfo struct_to_fill;
              struct_to_fill.aspectReferenceCount = aspectReferenceCount;
              struct_to_fill.pAspectReferences = pAspectReferences;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageViewUsageCreateInfo vkfImageViewUsageCreateInfo(VkImageUsageFlags usage)
       {
              VkImageViewUsageCreateInfo struct_to_fill;
              struct_to_fill.usage = usage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineTessellationDomainOriginStateCreateInfo vkfPipelineTessellationDomainOriginStateCreateInfo(VkTessellationDomainOrigin domainOrigin)
       {
              VkPipelineTessellationDomainOriginStateCreateInfo struct_to_fill;
              struct_to_fill.domainOrigin = domainOrigin;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRenderPassMultiviewCreateInfo vkfRenderPassMultiviewCreateInfo(uint32_t subpassCount, const uint32_t *pViewMasks, uint32_t dependencyCount, const int32_t *pViewOffsets, uint32_t correlationMaskCount, const uint32_t *pCorrelationMasks)
       {
              VkRenderPassMultiviewCreateInfo struct_to_fill;
              struct_to_fill.subpassCount = subpassCount;
              struct_to_fill.pViewMasks = pViewMasks;
              struct_to_fill.dependencyCount = dependencyCount;
              struct_to_fill.pViewOffsets = pViewOffsets;
              struct_to_fill.correlationMaskCount = correlationMaskCount;
              struct_to_fill.pCorrelationMasks = pCorrelationMasks;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMultiviewFeatures vkfPhysicalDeviceMultiviewFeatures(VkBool32 multiview, VkBool32 multiviewGeometryShader, VkBool32 multiviewTessellationShader)
       {
              VkPhysicalDeviceMultiviewFeatures struct_to_fill;
              struct_to_fill.multiview = multiview;
              struct_to_fill.multiviewGeometryShader = multiviewGeometryShader;
              struct_to_fill.multiviewTessellationShader = multiviewTessellationShader;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMultiviewProperties vkfPhysicalDeviceMultiviewProperties(uint32_t maxMultiviewViewCount, uint32_t maxMultiviewInstanceIndex)
       {
              VkPhysicalDeviceMultiviewProperties struct_to_fill;
              struct_to_fill.maxMultiviewViewCount = maxMultiviewViewCount;
              struct_to_fill.maxMultiviewInstanceIndex = maxMultiviewInstanceIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVariablePointersFeatures vkfPhysicalDeviceVariablePointersFeatures(VkBool32 variablePointersStorageBuffer, VkBool32 variablePointers)
       {
              VkPhysicalDeviceVariablePointersFeatures struct_to_fill;
              struct_to_fill.variablePointersStorageBuffer = variablePointersStorageBuffer;
              struct_to_fill.variablePointers = variablePointers;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceProtectedMemoryFeatures vkfPhysicalDeviceProtectedMemoryFeatures(VkBool32 protectedMemory)
       {
              VkPhysicalDeviceProtectedMemoryFeatures struct_to_fill;
              struct_to_fill.protectedMemory = protectedMemory;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceProtectedMemoryProperties vkfPhysicalDeviceProtectedMemoryProperties(VkBool32 protectedNoFault)
       {
              VkPhysicalDeviceProtectedMemoryProperties struct_to_fill;
              struct_to_fill.protectedNoFault = protectedNoFault;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceQueueInfo2 vkfDeviceQueueInfo2(uint32_t queueFamilyIndex, uint32_t queueIndex)
       {
              VkDeviceQueueInfo2 struct_to_fill;
              struct_to_fill.queueFamilyIndex = queueFamilyIndex;
              struct_to_fill.queueIndex = queueIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkProtectedSubmitInfo vkfProtectedSubmitInfo(VkBool32 protectedSubmit)
       {
              VkProtectedSubmitInfo struct_to_fill;
              struct_to_fill.protectedSubmit = protectedSubmit;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSamplerYcbcrConversionCreateInfo vkfSamplerYcbcrConversionCreateInfo(VkFormat format, VkSamplerYcbcrModelConversion ycbcrModel, VkSamplerYcbcrRange ycbcrRange, VkComponentMapping components, VkChromaLocation xChromaOffset, VkChromaLocation yChromaOffset, VkFilter chromaFilter, VkBool32 forceExplicitReconstruction)
       {
              VkSamplerYcbcrConversionCreateInfo struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.ycbcrModel = ycbcrModel;
              struct_to_fill.ycbcrRange = ycbcrRange;
              struct_to_fill.components = components;
              struct_to_fill.xChromaOffset = xChromaOffset;
              struct_to_fill.yChromaOffset = yChromaOffset;
              struct_to_fill.chromaFilter = chromaFilter;
              struct_to_fill.forceExplicitReconstruction = forceExplicitReconstruction;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSamplerYcbcrConversionInfo vkfSamplerYcbcrConversionInfo(VkSamplerYcbcrConversion conversion)
       {
              VkSamplerYcbcrConversionInfo struct_to_fill;
              struct_to_fill.conversion = conversion;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindImagePlaneMemoryInfo vkfBindImagePlaneMemoryInfo(VkImageAspectFlagBits planeAspect)
       {
              VkBindImagePlaneMemoryInfo struct_to_fill;
              struct_to_fill.planeAspect = planeAspect;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImagePlaneMemoryRequirementsInfo vkfImagePlaneMemoryRequirementsInfo(VkImageAspectFlagBits planeAspect)
       {
              VkImagePlaneMemoryRequirementsInfo struct_to_fill;
              struct_to_fill.planeAspect = planeAspect;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSamplerYcbcrConversionFeatures vkfPhysicalDeviceSamplerYcbcrConversionFeatures(VkBool32 samplerYcbcrConversion)
       {
              VkPhysicalDeviceSamplerYcbcrConversionFeatures struct_to_fill;
              struct_to_fill.samplerYcbcrConversion = samplerYcbcrConversion;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSamplerYcbcrConversionImageFormatProperties vkfSamplerYcbcrConversionImageFormatProperties(uint32_t combinedImageSamplerDescriptorCount)
       {
              VkSamplerYcbcrConversionImageFormatProperties struct_to_fill;
              struct_to_fill.combinedImageSamplerDescriptorCount = combinedImageSamplerDescriptorCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorUpdateTemplateEntry vkfDescriptorUpdateTemplateEntry(uint32_t dstBinding, uint32_t dstArrayElement, uint32_t descriptorCount, VkDescriptorType descriptorType, size_t offset, size_t stride)
       {
              VkDescriptorUpdateTemplateEntry struct_to_fill;
              struct_to_fill.dstBinding = dstBinding;
              struct_to_fill.dstArrayElement = dstArrayElement;
              struct_to_fill.descriptorCount = descriptorCount;
              struct_to_fill.descriptorType = descriptorType;
              struct_to_fill.offset = offset;
              struct_to_fill.stride = stride;
              return struct_to_fill;
       }
       static inline VkDescriptorUpdateTemplateCreateInfo vkfDescriptorUpdateTemplateCreateInfo(uint32_t descriptorUpdateEntryCount, const VkDescriptorUpdateTemplateEntry *pDescriptorUpdateEntries, VkDescriptorUpdateTemplateType templateType, VkDescriptorSetLayout descriptorSetLayout, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout pipelineLayout, uint32_t set)
       {
              VkDescriptorUpdateTemplateCreateInfo struct_to_fill;
              struct_to_fill.descriptorUpdateEntryCount = descriptorUpdateEntryCount;
              struct_to_fill.pDescriptorUpdateEntries = pDescriptorUpdateEntries;
              struct_to_fill.templateType = templateType;
              struct_to_fill.descriptorSetLayout = descriptorSetLayout;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.pipelineLayout = pipelineLayout;
              struct_to_fill.set = set;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkExternalMemoryProperties vkfExternalMemoryProperties(VkExternalMemoryFeatureFlags externalMemoryFeatures, VkExternalMemoryHandleTypeFlags exportFromImportedHandleTypes, VkExternalMemoryHandleTypeFlags compatibleHandleTypes)
       {
              VkExternalMemoryProperties struct_to_fill;
              struct_to_fill.externalMemoryFeatures = externalMemoryFeatures;
              struct_to_fill.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
              struct_to_fill.compatibleHandleTypes = compatibleHandleTypes;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExternalImageFormatInfo vkfPhysicalDeviceExternalImageFormatInfo(VkExternalMemoryHandleTypeFlagBits handleType)
       {
              VkPhysicalDeviceExternalImageFormatInfo struct_to_fill;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExternalImageFormatProperties vkfExternalImageFormatProperties(VkExternalMemoryProperties externalMemoryProperties)
       {
              VkExternalImageFormatProperties struct_to_fill;
              struct_to_fill.externalMemoryProperties = externalMemoryProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExternalBufferInfo vkfPhysicalDeviceExternalBufferInfo(VkBufferUsageFlags usage, VkExternalMemoryHandleTypeFlagBits handleType)
       {
              VkPhysicalDeviceExternalBufferInfo struct_to_fill;
              struct_to_fill.usage = usage;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkExternalBufferProperties vkfExternalBufferProperties(VkExternalMemoryProperties externalMemoryProperties)
       {
              VkExternalBufferProperties struct_to_fill;
              struct_to_fill.externalMemoryProperties = externalMemoryProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceIDProperties vkfPhysicalDeviceIDProperties(uint32_t deviceNodeMask, VkBool32 deviceLUIDValid)
       {
              VkPhysicalDeviceIDProperties struct_to_fill;
              struct_to_fill.deviceNodeMask = deviceNodeMask;
              struct_to_fill.deviceLUIDValid = deviceLUIDValid;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExternalMemoryImageCreateInfo vkfExternalMemoryImageCreateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
       {
              VkExternalMemoryImageCreateInfo struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExternalMemoryBufferCreateInfo vkfExternalMemoryBufferCreateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
       {
              VkExternalMemoryBufferCreateInfo struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExportMemoryAllocateInfo vkfExportMemoryAllocateInfo(VkExternalMemoryHandleTypeFlags handleTypes)
       {
              VkExportMemoryAllocateInfo struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExternalFenceInfo vkfPhysicalDeviceExternalFenceInfo(VkExternalFenceHandleTypeFlagBits handleType)
       {
              VkPhysicalDeviceExternalFenceInfo struct_to_fill;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExternalFenceProperties vkfExternalFenceProperties(VkExternalFenceHandleTypeFlags exportFromImportedHandleTypes, VkExternalFenceHandleTypeFlags compatibleHandleTypes, VkExternalFenceFeatureFlags externalFenceFeatures)
       {
              VkExternalFenceProperties struct_to_fill;
              struct_to_fill.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
              struct_to_fill.compatibleHandleTypes = compatibleHandleTypes;
              struct_to_fill.externalFenceFeatures = externalFenceFeatures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExportFenceCreateInfo vkfExportFenceCreateInfo(VkExternalFenceHandleTypeFlags handleTypes)
       {
              VkExportFenceCreateInfo struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExportSemaphoreCreateInfo vkfExportSemaphoreCreateInfo(VkExternalSemaphoreHandleTypeFlags handleTypes)
       {
              VkExportSemaphoreCreateInfo struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExternalSemaphoreInfo vkfPhysicalDeviceExternalSemaphoreInfo(VkExternalSemaphoreHandleTypeFlagBits handleType)
       {
              VkPhysicalDeviceExternalSemaphoreInfo struct_to_fill;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExternalSemaphoreProperties vkfExternalSemaphoreProperties(VkExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes, VkExternalSemaphoreHandleTypeFlags compatibleHandleTypes, VkExternalSemaphoreFeatureFlags externalSemaphoreFeatures)
       {
              VkExternalSemaphoreProperties struct_to_fill;
              struct_to_fill.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
              struct_to_fill.compatibleHandleTypes = compatibleHandleTypes;
              struct_to_fill.externalSemaphoreFeatures = externalSemaphoreFeatures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMaintenance3Properties vkfPhysicalDeviceMaintenance3Properties(uint32_t maxPerSetDescriptors, VkDeviceSize maxMemoryAllocationSize)
       {
              VkPhysicalDeviceMaintenance3Properties struct_to_fill;
              struct_to_fill.maxPerSetDescriptors = maxPerSetDescriptors;
              struct_to_fill.maxMemoryAllocationSize = maxMemoryAllocationSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorSetLayoutSupport vkfDescriptorSetLayoutSupport(VkBool32 supported)
       {
              VkDescriptorSetLayoutSupport struct_to_fill;
              struct_to_fill.supported = supported;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShaderDrawParametersFeatures vkfPhysicalDeviceShaderDrawParametersFeatures(VkBool32 shaderDrawParameters)
       {
              VkPhysicalDeviceShaderDrawParametersFeatures struct_to_fill;
              struct_to_fill.shaderDrawParameters = shaderDrawParameters;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_VERSION_1_1
#ifdef VK_VERSION_1_2
       static inline VkPhysicalDeviceVulkan11Features vkfPhysicalDeviceVulkan11Features(VkBool32 storageBuffer16BitAccess, VkBool32 uniformAndStorageBuffer16BitAccess, VkBool32 storagePushConstant16, VkBool32 storageInputOutput16, VkBool32 multiview, VkBool32 multiviewGeometryShader, VkBool32 multiviewTessellationShader, VkBool32 variablePointersStorageBuffer, VkBool32 variablePointers, VkBool32 protectedMemory, VkBool32 samplerYcbcrConversion, VkBool32 shaderDrawParameters)
       {
              VkPhysicalDeviceVulkan11Features struct_to_fill;
              struct_to_fill.storageBuffer16BitAccess = storageBuffer16BitAccess;
              struct_to_fill.uniformAndStorageBuffer16BitAccess = uniformAndStorageBuffer16BitAccess;
              struct_to_fill.storagePushConstant16 = storagePushConstant16;
              struct_to_fill.storageInputOutput16 = storageInputOutput16;
              struct_to_fill.multiview = multiview;
              struct_to_fill.multiviewGeometryShader = multiviewGeometryShader;
              struct_to_fill.multiviewTessellationShader = multiviewTessellationShader;
              struct_to_fill.variablePointersStorageBuffer = variablePointersStorageBuffer;
              struct_to_fill.variablePointers = variablePointers;
              struct_to_fill.protectedMemory = protectedMemory;
              struct_to_fill.samplerYcbcrConversion = samplerYcbcrConversion;
              struct_to_fill.shaderDrawParameters = shaderDrawParameters;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVulkan11Properties vkfPhysicalDeviceVulkan11Properties(uint32_t deviceNodeMask, VkBool32 deviceLUIDValid, uint32_t subgroupSize, VkShaderStageFlags subgroupSupportedStages, VkSubgroupFeatureFlags subgroupSupportedOperations, VkBool32 subgroupQuadOperationsInAllStages, VkPointClippingBehavior pointClippingBehavior, uint32_t maxMultiviewViewCount, uint32_t maxMultiviewInstanceIndex, VkBool32 protectedNoFault, uint32_t maxPerSetDescriptors, VkDeviceSize maxMemoryAllocationSize)
       {
              VkPhysicalDeviceVulkan11Properties struct_to_fill;
              struct_to_fill.deviceNodeMask = deviceNodeMask;
              struct_to_fill.deviceLUIDValid = deviceLUIDValid;
              struct_to_fill.subgroupSize = subgroupSize;
              struct_to_fill.subgroupSupportedStages = subgroupSupportedStages;
              struct_to_fill.subgroupSupportedOperations = subgroupSupportedOperations;
              struct_to_fill.subgroupQuadOperationsInAllStages = subgroupQuadOperationsInAllStages;
              struct_to_fill.pointClippingBehavior = pointClippingBehavior;
              struct_to_fill.maxMultiviewViewCount = maxMultiviewViewCount;
              struct_to_fill.maxMultiviewInstanceIndex = maxMultiviewInstanceIndex;
              struct_to_fill.protectedNoFault = protectedNoFault;
              struct_to_fill.maxPerSetDescriptors = maxPerSetDescriptors;
              struct_to_fill.maxMemoryAllocationSize = maxMemoryAllocationSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVulkan12Features vkfPhysicalDeviceVulkan12Features(VkBool32 samplerMirrorClampToEdge, VkBool32 drawIndirectCount, VkBool32 storageBuffer8BitAccess, VkBool32 uniformAndStorageBuffer8BitAccess, VkBool32 storagePushConstant8, VkBool32 shaderBufferInt64Atomics, VkBool32 shaderSharedInt64Atomics, VkBool32 shaderFloat16, VkBool32 shaderInt8, VkBool32 descriptorIndexing, VkBool32 shaderInputAttachmentArrayDynamicIndexing, VkBool32 shaderUniformTexelBufferArrayDynamicIndexing, VkBool32 shaderStorageTexelBufferArrayDynamicIndexing, VkBool32 shaderUniformBufferArrayNonUniformIndexing, VkBool32 shaderSampledImageArrayNonUniformIndexing, VkBool32 shaderStorageBufferArrayNonUniformIndexing, VkBool32 shaderStorageImageArrayNonUniformIndexing, VkBool32 shaderInputAttachmentArrayNonUniformIndexing, VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing, VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing, VkBool32 descriptorBindingUniformBufferUpdateAfterBind, VkBool32 descriptorBindingSampledImageUpdateAfterBind, VkBool32 descriptorBindingStorageImageUpdateAfterBind, VkBool32 descriptorBindingStorageBufferUpdateAfterBind, VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind, VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind, VkBool32 descriptorBindingUpdateUnusedWhilePending, VkBool32 descriptorBindingPartiallyBound, VkBool32 descriptorBindingVariableDescriptorCount, VkBool32 runtimeDescriptorArray, VkBool32 samplerFilterMinmax, VkBool32 scalarBlockLayout, VkBool32 imagelessFramebuffer, VkBool32 uniformBufferStandardLayout, VkBool32 shaderSubgroupExtendedTypes, VkBool32 separateDepthStencilLayouts, VkBool32 hostQueryReset, VkBool32 timelineSemaphore, VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice, VkBool32 vulkanMemoryModel, VkBool32 vulkanMemoryModelDeviceScope, VkBool32 vulkanMemoryModelAvailabilityVisibilityChains, VkBool32 shaderOutputViewportIndex, VkBool32 shaderOutputLayer, VkBool32 subgroupBroadcastDynamicId)
       {
              VkPhysicalDeviceVulkan12Features struct_to_fill;
              struct_to_fill.samplerMirrorClampToEdge = samplerMirrorClampToEdge;
              struct_to_fill.drawIndirectCount = drawIndirectCount;
              struct_to_fill.storageBuffer8BitAccess = storageBuffer8BitAccess;
              struct_to_fill.uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
              struct_to_fill.storagePushConstant8 = storagePushConstant8;
              struct_to_fill.shaderBufferInt64Atomics = shaderBufferInt64Atomics;
              struct_to_fill.shaderSharedInt64Atomics = shaderSharedInt64Atomics;
              struct_to_fill.shaderFloat16 = shaderFloat16;
              struct_to_fill.shaderInt8 = shaderInt8;
              struct_to_fill.descriptorIndexing = descriptorIndexing;
              struct_to_fill.shaderInputAttachmentArrayDynamicIndexing = shaderInputAttachmentArrayDynamicIndexing;
              struct_to_fill.shaderUniformTexelBufferArrayDynamicIndexing = shaderUniformTexelBufferArrayDynamicIndexing;
              struct_to_fill.shaderStorageTexelBufferArrayDynamicIndexing = shaderStorageTexelBufferArrayDynamicIndexing;
              struct_to_fill.shaderUniformBufferArrayNonUniformIndexing = shaderUniformBufferArrayNonUniformIndexing;
              struct_to_fill.shaderSampledImageArrayNonUniformIndexing = shaderSampledImageArrayNonUniformIndexing;
              struct_to_fill.shaderStorageBufferArrayNonUniformIndexing = shaderStorageBufferArrayNonUniformIndexing;
              struct_to_fill.shaderStorageImageArrayNonUniformIndexing = shaderStorageImageArrayNonUniformIndexing;
              struct_to_fill.shaderInputAttachmentArrayNonUniformIndexing = shaderInputAttachmentArrayNonUniformIndexing;
              struct_to_fill.shaderUniformTexelBufferArrayNonUniformIndexing = shaderUniformTexelBufferArrayNonUniformIndexing;
              struct_to_fill.shaderStorageTexelBufferArrayNonUniformIndexing = shaderStorageTexelBufferArrayNonUniformIndexing;
              struct_to_fill.descriptorBindingUniformBufferUpdateAfterBind = descriptorBindingUniformBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingSampledImageUpdateAfterBind = descriptorBindingSampledImageUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageImageUpdateAfterBind = descriptorBindingStorageImageUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageBufferUpdateAfterBind = descriptorBindingStorageBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingUniformTexelBufferUpdateAfterBind = descriptorBindingUniformTexelBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageTexelBufferUpdateAfterBind = descriptorBindingStorageTexelBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingUpdateUnusedWhilePending = descriptorBindingUpdateUnusedWhilePending;
              struct_to_fill.descriptorBindingPartiallyBound = descriptorBindingPartiallyBound;
              struct_to_fill.descriptorBindingVariableDescriptorCount = descriptorBindingVariableDescriptorCount;
              struct_to_fill.runtimeDescriptorArray = runtimeDescriptorArray;
              struct_to_fill.samplerFilterMinmax = samplerFilterMinmax;
              struct_to_fill.scalarBlockLayout = scalarBlockLayout;
              struct_to_fill.imagelessFramebuffer = imagelessFramebuffer;
              struct_to_fill.uniformBufferStandardLayout = uniformBufferStandardLayout;
              struct_to_fill.shaderSubgroupExtendedTypes = shaderSubgroupExtendedTypes;
              struct_to_fill.separateDepthStencilLayouts = separateDepthStencilLayouts;
              struct_to_fill.hostQueryReset = hostQueryReset;
              struct_to_fill.timelineSemaphore = timelineSemaphore;
              struct_to_fill.bufferDeviceAddress = bufferDeviceAddress;
              struct_to_fill.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
              struct_to_fill.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
              struct_to_fill.vulkanMemoryModel = vulkanMemoryModel;
              struct_to_fill.vulkanMemoryModelDeviceScope = vulkanMemoryModelDeviceScope;
              struct_to_fill.vulkanMemoryModelAvailabilityVisibilityChains = vulkanMemoryModelAvailabilityVisibilityChains;
              struct_to_fill.shaderOutputViewportIndex = shaderOutputViewportIndex;
              struct_to_fill.shaderOutputLayer = shaderOutputLayer;
              struct_to_fill.subgroupBroadcastDynamicId = subgroupBroadcastDynamicId;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkConformanceVersion vkfConformanceVersion(uint8_t major, uint8_t minor, uint8_t subminor, uint8_t patch)
       {
              VkConformanceVersion struct_to_fill;
              struct_to_fill.major = major;
              struct_to_fill.minor = minor;
              struct_to_fill.subminor = subminor;
              struct_to_fill.patch = patch;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVulkan12Properties vkfPhysicalDeviceVulkan12Properties(VkDriverId driverID, VkConformanceVersion conformanceVersion, VkShaderFloatControlsIndependence denormBehaviorIndependence, VkShaderFloatControlsIndependence roundingModeIndependence, VkBool32 shaderSignedZeroInfNanPreserveFloat16, VkBool32 shaderSignedZeroInfNanPreserveFloat32, VkBool32 shaderSignedZeroInfNanPreserveFloat64, VkBool32 shaderDenormPreserveFloat16, VkBool32 shaderDenormPreserveFloat32, VkBool32 shaderDenormPreserveFloat64, VkBool32 shaderDenormFlushToZeroFloat16, VkBool32 shaderDenormFlushToZeroFloat32, VkBool32 shaderDenormFlushToZeroFloat64, VkBool32 shaderRoundingModeRTEFloat16, VkBool32 shaderRoundingModeRTEFloat32, VkBool32 shaderRoundingModeRTEFloat64, VkBool32 shaderRoundingModeRTZFloat16, VkBool32 shaderRoundingModeRTZFloat32, VkBool32 shaderRoundingModeRTZFloat64, uint32_t maxUpdateAfterBindDescriptorsInAllPools, VkBool32 shaderUniformBufferArrayNonUniformIndexingNative, VkBool32 shaderSampledImageArrayNonUniformIndexingNative, VkBool32 shaderStorageBufferArrayNonUniformIndexingNative, VkBool32 shaderStorageImageArrayNonUniformIndexingNative, VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative, VkBool32 robustBufferAccessUpdateAfterBind, VkBool32 quadDivergentImplicitLod, uint32_t maxPerStageDescriptorUpdateAfterBindSamplers, uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages, uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages, uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments, uint32_t maxPerStageUpdateAfterBindResources, uint32_t maxDescriptorSetUpdateAfterBindSamplers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindSampledImages, uint32_t maxDescriptorSetUpdateAfterBindStorageImages, uint32_t maxDescriptorSetUpdateAfterBindInputAttachments, VkResolveModeFlags supportedDepthResolveModes, VkResolveModeFlags supportedStencilResolveModes, VkBool32 independentResolveNone, VkBool32 independentResolve, VkBool32 filterMinmaxSingleComponentFormats, VkBool32 filterMinmaxImageComponentMapping, uint64_t maxTimelineSemaphoreValueDifference, VkSampleCountFlags framebufferIntegerColorSampleCounts)
       {
              VkPhysicalDeviceVulkan12Properties struct_to_fill;
              struct_to_fill.driverID = driverID;
              struct_to_fill.conformanceVersion = conformanceVersion;
              struct_to_fill.denormBehaviorIndependence = denormBehaviorIndependence;
              struct_to_fill.roundingModeIndependence = roundingModeIndependence;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat16 = shaderSignedZeroInfNanPreserveFloat16;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat32 = shaderSignedZeroInfNanPreserveFloat32;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat64 = shaderSignedZeroInfNanPreserveFloat64;
              struct_to_fill.shaderDenormPreserveFloat16 = shaderDenormPreserveFloat16;
              struct_to_fill.shaderDenormPreserveFloat32 = shaderDenormPreserveFloat32;
              struct_to_fill.shaderDenormPreserveFloat64 = shaderDenormPreserveFloat64;
              struct_to_fill.shaderDenormFlushToZeroFloat16 = shaderDenormFlushToZeroFloat16;
              struct_to_fill.shaderDenormFlushToZeroFloat32 = shaderDenormFlushToZeroFloat32;
              struct_to_fill.shaderDenormFlushToZeroFloat64 = shaderDenormFlushToZeroFloat64;
              struct_to_fill.shaderRoundingModeRTEFloat16 = shaderRoundingModeRTEFloat16;
              struct_to_fill.shaderRoundingModeRTEFloat32 = shaderRoundingModeRTEFloat32;
              struct_to_fill.shaderRoundingModeRTEFloat64 = shaderRoundingModeRTEFloat64;
              struct_to_fill.shaderRoundingModeRTZFloat16 = shaderRoundingModeRTZFloat16;
              struct_to_fill.shaderRoundingModeRTZFloat32 = shaderRoundingModeRTZFloat32;
              struct_to_fill.shaderRoundingModeRTZFloat64 = shaderRoundingModeRTZFloat64;
              struct_to_fill.maxUpdateAfterBindDescriptorsInAllPools = maxUpdateAfterBindDescriptorsInAllPools;
              struct_to_fill.shaderUniformBufferArrayNonUniformIndexingNative = shaderUniformBufferArrayNonUniformIndexingNative;
              struct_to_fill.shaderSampledImageArrayNonUniformIndexingNative = shaderSampledImageArrayNonUniformIndexingNative;
              struct_to_fill.shaderStorageBufferArrayNonUniformIndexingNative = shaderStorageBufferArrayNonUniformIndexingNative;
              struct_to_fill.shaderStorageImageArrayNonUniformIndexingNative = shaderStorageImageArrayNonUniformIndexingNative;
              struct_to_fill.shaderInputAttachmentArrayNonUniformIndexingNative = shaderInputAttachmentArrayNonUniformIndexingNative;
              struct_to_fill.robustBufferAccessUpdateAfterBind = robustBufferAccessUpdateAfterBind;
              struct_to_fill.quadDivergentImplicitLod = quadDivergentImplicitLod;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindSamplers = maxPerStageDescriptorUpdateAfterBindSamplers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindUniformBuffers = maxPerStageDescriptorUpdateAfterBindUniformBuffers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindStorageBuffers = maxPerStageDescriptorUpdateAfterBindStorageBuffers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindSampledImages = maxPerStageDescriptorUpdateAfterBindSampledImages;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindStorageImages = maxPerStageDescriptorUpdateAfterBindStorageImages;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindInputAttachments = maxPerStageDescriptorUpdateAfterBindInputAttachments;
              struct_to_fill.maxPerStageUpdateAfterBindResources = maxPerStageUpdateAfterBindResources;
              struct_to_fill.maxDescriptorSetUpdateAfterBindSamplers = maxDescriptorSetUpdateAfterBindSamplers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindUniformBuffers = maxDescriptorSetUpdateAfterBindUniformBuffers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageBuffers = maxDescriptorSetUpdateAfterBindStorageBuffers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
              struct_to_fill.maxDescriptorSetUpdateAfterBindSampledImages = maxDescriptorSetUpdateAfterBindSampledImages;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageImages = maxDescriptorSetUpdateAfterBindStorageImages;
              struct_to_fill.maxDescriptorSetUpdateAfterBindInputAttachments = maxDescriptorSetUpdateAfterBindInputAttachments;
              struct_to_fill.supportedDepthResolveModes = supportedDepthResolveModes;
              struct_to_fill.supportedStencilResolveModes = supportedStencilResolveModes;
              struct_to_fill.independentResolveNone = independentResolveNone;
              struct_to_fill.independentResolve = independentResolve;
              struct_to_fill.filterMinmaxSingleComponentFormats = filterMinmaxSingleComponentFormats;
              struct_to_fill.filterMinmaxImageComponentMapping = filterMinmaxImageComponentMapping;
              struct_to_fill.maxTimelineSemaphoreValueDifference = maxTimelineSemaphoreValueDifference;
              struct_to_fill.framebufferIntegerColorSampleCounts = framebufferIntegerColorSampleCounts;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageFormatListCreateInfo vkfImageFormatListCreateInfo(uint32_t viewFormatCount, const VkFormat *pViewFormats)
       {
              VkImageFormatListCreateInfo struct_to_fill;
              struct_to_fill.viewFormatCount = viewFormatCount;
              struct_to_fill.pViewFormats = pViewFormats;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAttachmentDescription2 vkfAttachmentDescription2(VkFormat format, VkSampleCountFlagBits samples, VkAttachmentLoadOp loadOp, VkAttachmentStoreOp storeOp, VkAttachmentLoadOp stencilLoadOp, VkAttachmentStoreOp stencilStoreOp, VkImageLayout initialLayout, VkImageLayout finalLayout)
       {
              VkAttachmentDescription2 struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.samples = samples;
              struct_to_fill.loadOp = loadOp;
              struct_to_fill.storeOp = storeOp;
              struct_to_fill.stencilLoadOp = stencilLoadOp;
              struct_to_fill.stencilStoreOp = stencilStoreOp;
              struct_to_fill.initialLayout = initialLayout;
              struct_to_fill.finalLayout = finalLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAttachmentReference2 vkfAttachmentReference2(uint32_t attachment, VkImageLayout layout, VkImageAspectFlags aspectMask)
       {
              VkAttachmentReference2 struct_to_fill;
              struct_to_fill.attachment = attachment;
              struct_to_fill.layout = layout;
              struct_to_fill.aspectMask = aspectMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSubpassDescription2 vkfSubpassDescription2(VkPipelineBindPoint pipelineBindPoint, uint32_t viewMask, uint32_t inputAttachmentCount, const VkAttachmentReference2 *pInputAttachments, uint32_t colorAttachmentCount, const VkAttachmentReference2 *pColorAttachments, const VkAttachmentReference2 *pResolveAttachments, const VkAttachmentReference2 *pDepthStencilAttachment, uint32_t preserveAttachmentCount, const uint32_t *pPreserveAttachments)
       {
              VkSubpassDescription2 struct_to_fill;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.viewMask = viewMask;
              struct_to_fill.inputAttachmentCount = inputAttachmentCount;
              struct_to_fill.pInputAttachments = pInputAttachments;
              struct_to_fill.colorAttachmentCount = colorAttachmentCount;
              struct_to_fill.pColorAttachments = pColorAttachments;
              struct_to_fill.pResolveAttachments = pResolveAttachments;
              struct_to_fill.pDepthStencilAttachment = pDepthStencilAttachment;
              struct_to_fill.preserveAttachmentCount = preserveAttachmentCount;
              struct_to_fill.pPreserveAttachments = pPreserveAttachments;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSubpassDependency2 vkfSubpassDependency2(uint32_t srcSubpass, uint32_t dstSubpass, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkDependencyFlags dependencyFlags, int32_t viewOffset)
       {
              VkSubpassDependency2 struct_to_fill;
              struct_to_fill.srcSubpass = srcSubpass;
              struct_to_fill.dstSubpass = dstSubpass;
              struct_to_fill.srcStageMask = srcStageMask;
              struct_to_fill.dstStageMask = dstStageMask;
              struct_to_fill.srcAccessMask = srcAccessMask;
              struct_to_fill.dstAccessMask = dstAccessMask;
              struct_to_fill.dependencyFlags = dependencyFlags;
              struct_to_fill.viewOffset = viewOffset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRenderPassCreateInfo2 vkfRenderPassCreateInfo2(uint32_t attachmentCount, const VkAttachmentDescription2 *pAttachments, uint32_t subpassCount, const VkSubpassDescription2 *pSubpasses, uint32_t dependencyCount, const VkSubpassDependency2 *pDependencies, uint32_t correlatedViewMaskCount, const uint32_t *pCorrelatedViewMasks)
       {
              VkRenderPassCreateInfo2 struct_to_fill;
              struct_to_fill.attachmentCount = attachmentCount;
              struct_to_fill.pAttachments = pAttachments;
              struct_to_fill.subpassCount = subpassCount;
              struct_to_fill.pSubpasses = pSubpasses;
              struct_to_fill.dependencyCount = dependencyCount;
              struct_to_fill.pDependencies = pDependencies;
              struct_to_fill.correlatedViewMaskCount = correlatedViewMaskCount;
              struct_to_fill.pCorrelatedViewMasks = pCorrelatedViewMasks;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSubpassBeginInfo vkfSubpassBeginInfo(VkSubpassContents contents)
       {
              VkSubpassBeginInfo struct_to_fill;
              struct_to_fill.contents = contents;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSubpassEndInfo vkfSubpassEndInfo()
       {
              VkSubpassEndInfo struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBPASS_END_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDevice8BitStorageFeatures vkfPhysicalDevice8BitStorageFeatures(VkBool32 storageBuffer8BitAccess, VkBool32 uniformAndStorageBuffer8BitAccess, VkBool32 storagePushConstant8)
       {
              VkPhysicalDevice8BitStorageFeatures struct_to_fill;
              struct_to_fill.storageBuffer8BitAccess = storageBuffer8BitAccess;
              struct_to_fill.uniformAndStorageBuffer8BitAccess = uniformAndStorageBuffer8BitAccess;
              struct_to_fill.storagePushConstant8 = storagePushConstant8;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceDriverProperties vkfPhysicalDeviceDriverProperties(VkDriverId driverID, VkConformanceVersion conformanceVersion)
       {
              VkPhysicalDeviceDriverProperties struct_to_fill;
              struct_to_fill.driverID = driverID;
              struct_to_fill.conformanceVersion = conformanceVersion;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShaderAtomicInt64Features vkfPhysicalDeviceShaderAtomicInt64Features(VkBool32 shaderBufferInt64Atomics, VkBool32 shaderSharedInt64Atomics)
       {
              VkPhysicalDeviceShaderAtomicInt64Features struct_to_fill;
              struct_to_fill.shaderBufferInt64Atomics = shaderBufferInt64Atomics;
              struct_to_fill.shaderSharedInt64Atomics = shaderSharedInt64Atomics;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShaderFloat16Int8Features vkfPhysicalDeviceShaderFloat16Int8Features(VkBool32 shaderFloat16, VkBool32 shaderInt8)
       {
              VkPhysicalDeviceShaderFloat16Int8Features struct_to_fill;
              struct_to_fill.shaderFloat16 = shaderFloat16;
              struct_to_fill.shaderInt8 = shaderInt8;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceFloatControlsProperties vkfPhysicalDeviceFloatControlsProperties(VkShaderFloatControlsIndependence denormBehaviorIndependence, VkShaderFloatControlsIndependence roundingModeIndependence, VkBool32 shaderSignedZeroInfNanPreserveFloat16, VkBool32 shaderSignedZeroInfNanPreserveFloat32, VkBool32 shaderSignedZeroInfNanPreserveFloat64, VkBool32 shaderDenormPreserveFloat16, VkBool32 shaderDenormPreserveFloat32, VkBool32 shaderDenormPreserveFloat64, VkBool32 shaderDenormFlushToZeroFloat16, VkBool32 shaderDenormFlushToZeroFloat32, VkBool32 shaderDenormFlushToZeroFloat64, VkBool32 shaderRoundingModeRTEFloat16, VkBool32 shaderRoundingModeRTEFloat32, VkBool32 shaderRoundingModeRTEFloat64, VkBool32 shaderRoundingModeRTZFloat16, VkBool32 shaderRoundingModeRTZFloat32, VkBool32 shaderRoundingModeRTZFloat64)
       {
              VkPhysicalDeviceFloatControlsProperties struct_to_fill;
              struct_to_fill.denormBehaviorIndependence = denormBehaviorIndependence;
              struct_to_fill.roundingModeIndependence = roundingModeIndependence;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat16 = shaderSignedZeroInfNanPreserveFloat16;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat32 = shaderSignedZeroInfNanPreserveFloat32;
              struct_to_fill.shaderSignedZeroInfNanPreserveFloat64 = shaderSignedZeroInfNanPreserveFloat64;
              struct_to_fill.shaderDenormPreserveFloat16 = shaderDenormPreserveFloat16;
              struct_to_fill.shaderDenormPreserveFloat32 = shaderDenormPreserveFloat32;
              struct_to_fill.shaderDenormPreserveFloat64 = shaderDenormPreserveFloat64;
              struct_to_fill.shaderDenormFlushToZeroFloat16 = shaderDenormFlushToZeroFloat16;
              struct_to_fill.shaderDenormFlushToZeroFloat32 = shaderDenormFlushToZeroFloat32;
              struct_to_fill.shaderDenormFlushToZeroFloat64 = shaderDenormFlushToZeroFloat64;
              struct_to_fill.shaderRoundingModeRTEFloat16 = shaderRoundingModeRTEFloat16;
              struct_to_fill.shaderRoundingModeRTEFloat32 = shaderRoundingModeRTEFloat32;
              struct_to_fill.shaderRoundingModeRTEFloat64 = shaderRoundingModeRTEFloat64;
              struct_to_fill.shaderRoundingModeRTZFloat16 = shaderRoundingModeRTZFloat16;
              struct_to_fill.shaderRoundingModeRTZFloat32 = shaderRoundingModeRTZFloat32;
              struct_to_fill.shaderRoundingModeRTZFloat64 = shaderRoundingModeRTZFloat64;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorSetLayoutBindingFlagsCreateInfo vkfDescriptorSetLayoutBindingFlagsCreateInfo(uint32_t bindingCount, const VkDescriptorBindingFlags *pBindingFlags)
       {
              VkDescriptorSetLayoutBindingFlagsCreateInfo struct_to_fill;
              struct_to_fill.bindingCount = bindingCount;
              struct_to_fill.pBindingFlags = pBindingFlags;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceDescriptorIndexingFeatures vkfPhysicalDeviceDescriptorIndexingFeatures(VkBool32 shaderInputAttachmentArrayDynamicIndexing, VkBool32 shaderUniformTexelBufferArrayDynamicIndexing, VkBool32 shaderStorageTexelBufferArrayDynamicIndexing, VkBool32 shaderUniformBufferArrayNonUniformIndexing, VkBool32 shaderSampledImageArrayNonUniformIndexing, VkBool32 shaderStorageBufferArrayNonUniformIndexing, VkBool32 shaderStorageImageArrayNonUniformIndexing, VkBool32 shaderInputAttachmentArrayNonUniformIndexing, VkBool32 shaderUniformTexelBufferArrayNonUniformIndexing, VkBool32 shaderStorageTexelBufferArrayNonUniformIndexing, VkBool32 descriptorBindingUniformBufferUpdateAfterBind, VkBool32 descriptorBindingSampledImageUpdateAfterBind, VkBool32 descriptorBindingStorageImageUpdateAfterBind, VkBool32 descriptorBindingStorageBufferUpdateAfterBind, VkBool32 descriptorBindingUniformTexelBufferUpdateAfterBind, VkBool32 descriptorBindingStorageTexelBufferUpdateAfterBind, VkBool32 descriptorBindingUpdateUnusedWhilePending, VkBool32 descriptorBindingPartiallyBound, VkBool32 descriptorBindingVariableDescriptorCount, VkBool32 runtimeDescriptorArray)
       {
              VkPhysicalDeviceDescriptorIndexingFeatures struct_to_fill;
              struct_to_fill.shaderInputAttachmentArrayDynamicIndexing = shaderInputAttachmentArrayDynamicIndexing;
              struct_to_fill.shaderUniformTexelBufferArrayDynamicIndexing = shaderUniformTexelBufferArrayDynamicIndexing;
              struct_to_fill.shaderStorageTexelBufferArrayDynamicIndexing = shaderStorageTexelBufferArrayDynamicIndexing;
              struct_to_fill.shaderUniformBufferArrayNonUniformIndexing = shaderUniformBufferArrayNonUniformIndexing;
              struct_to_fill.shaderSampledImageArrayNonUniformIndexing = shaderSampledImageArrayNonUniformIndexing;
              struct_to_fill.shaderStorageBufferArrayNonUniformIndexing = shaderStorageBufferArrayNonUniformIndexing;
              struct_to_fill.shaderStorageImageArrayNonUniformIndexing = shaderStorageImageArrayNonUniformIndexing;
              struct_to_fill.shaderInputAttachmentArrayNonUniformIndexing = shaderInputAttachmentArrayNonUniformIndexing;
              struct_to_fill.shaderUniformTexelBufferArrayNonUniformIndexing = shaderUniformTexelBufferArrayNonUniformIndexing;
              struct_to_fill.shaderStorageTexelBufferArrayNonUniformIndexing = shaderStorageTexelBufferArrayNonUniformIndexing;
              struct_to_fill.descriptorBindingUniformBufferUpdateAfterBind = descriptorBindingUniformBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingSampledImageUpdateAfterBind = descriptorBindingSampledImageUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageImageUpdateAfterBind = descriptorBindingStorageImageUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageBufferUpdateAfterBind = descriptorBindingStorageBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingUniformTexelBufferUpdateAfterBind = descriptorBindingUniformTexelBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingStorageTexelBufferUpdateAfterBind = descriptorBindingStorageTexelBufferUpdateAfterBind;
              struct_to_fill.descriptorBindingUpdateUnusedWhilePending = descriptorBindingUpdateUnusedWhilePending;
              struct_to_fill.descriptorBindingPartiallyBound = descriptorBindingPartiallyBound;
              struct_to_fill.descriptorBindingVariableDescriptorCount = descriptorBindingVariableDescriptorCount;
              struct_to_fill.runtimeDescriptorArray = runtimeDescriptorArray;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceDescriptorIndexingProperties vkfPhysicalDeviceDescriptorIndexingProperties(uint32_t maxUpdateAfterBindDescriptorsInAllPools, VkBool32 shaderUniformBufferArrayNonUniformIndexingNative, VkBool32 shaderSampledImageArrayNonUniformIndexingNative, VkBool32 shaderStorageBufferArrayNonUniformIndexingNative, VkBool32 shaderStorageImageArrayNonUniformIndexingNative, VkBool32 shaderInputAttachmentArrayNonUniformIndexingNative, VkBool32 robustBufferAccessUpdateAfterBind, VkBool32 quadDivergentImplicitLod, uint32_t maxPerStageDescriptorUpdateAfterBindSamplers, uint32_t maxPerStageDescriptorUpdateAfterBindUniformBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindStorageBuffers, uint32_t maxPerStageDescriptorUpdateAfterBindSampledImages, uint32_t maxPerStageDescriptorUpdateAfterBindStorageImages, uint32_t maxPerStageDescriptorUpdateAfterBindInputAttachments, uint32_t maxPerStageUpdateAfterBindResources, uint32_t maxDescriptorSetUpdateAfterBindSamplers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffers, uint32_t maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffers, uint32_t maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, uint32_t maxDescriptorSetUpdateAfterBindSampledImages, uint32_t maxDescriptorSetUpdateAfterBindStorageImages, uint32_t maxDescriptorSetUpdateAfterBindInputAttachments)
       {
              VkPhysicalDeviceDescriptorIndexingProperties struct_to_fill;
              struct_to_fill.maxUpdateAfterBindDescriptorsInAllPools = maxUpdateAfterBindDescriptorsInAllPools;
              struct_to_fill.shaderUniformBufferArrayNonUniformIndexingNative = shaderUniformBufferArrayNonUniformIndexingNative;
              struct_to_fill.shaderSampledImageArrayNonUniformIndexingNative = shaderSampledImageArrayNonUniformIndexingNative;
              struct_to_fill.shaderStorageBufferArrayNonUniformIndexingNative = shaderStorageBufferArrayNonUniformIndexingNative;
              struct_to_fill.shaderStorageImageArrayNonUniformIndexingNative = shaderStorageImageArrayNonUniformIndexingNative;
              struct_to_fill.shaderInputAttachmentArrayNonUniformIndexingNative = shaderInputAttachmentArrayNonUniformIndexingNative;
              struct_to_fill.robustBufferAccessUpdateAfterBind = robustBufferAccessUpdateAfterBind;
              struct_to_fill.quadDivergentImplicitLod = quadDivergentImplicitLod;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindSamplers = maxPerStageDescriptorUpdateAfterBindSamplers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindUniformBuffers = maxPerStageDescriptorUpdateAfterBindUniformBuffers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindStorageBuffers = maxPerStageDescriptorUpdateAfterBindStorageBuffers;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindSampledImages = maxPerStageDescriptorUpdateAfterBindSampledImages;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindStorageImages = maxPerStageDescriptorUpdateAfterBindStorageImages;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindInputAttachments = maxPerStageDescriptorUpdateAfterBindInputAttachments;
              struct_to_fill.maxPerStageUpdateAfterBindResources = maxPerStageUpdateAfterBindResources;
              struct_to_fill.maxDescriptorSetUpdateAfterBindSamplers = maxDescriptorSetUpdateAfterBindSamplers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindUniformBuffers = maxDescriptorSetUpdateAfterBindUniformBuffers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = maxDescriptorSetUpdateAfterBindUniformBuffersDynamic;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageBuffers = maxDescriptorSetUpdateAfterBindStorageBuffers;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = maxDescriptorSetUpdateAfterBindStorageBuffersDynamic;
              struct_to_fill.maxDescriptorSetUpdateAfterBindSampledImages = maxDescriptorSetUpdateAfterBindSampledImages;
              struct_to_fill.maxDescriptorSetUpdateAfterBindStorageImages = maxDescriptorSetUpdateAfterBindStorageImages;
              struct_to_fill.maxDescriptorSetUpdateAfterBindInputAttachments = maxDescriptorSetUpdateAfterBindInputAttachments;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorSetVariableDescriptorCountAllocateInfo vkfDescriptorSetVariableDescriptorCountAllocateInfo(uint32_t descriptorSetCount, const uint32_t *pDescriptorCounts)
       {
              VkDescriptorSetVariableDescriptorCountAllocateInfo struct_to_fill;
              struct_to_fill.descriptorSetCount = descriptorSetCount;
              struct_to_fill.pDescriptorCounts = pDescriptorCounts;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorSetVariableDescriptorCountLayoutSupport vkfDescriptorSetVariableDescriptorCountLayoutSupport(uint32_t maxVariableDescriptorCount)
       {
              VkDescriptorSetVariableDescriptorCountLayoutSupport struct_to_fill;
              struct_to_fill.maxVariableDescriptorCount = maxVariableDescriptorCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSubpassDescriptionDepthStencilResolve vkfSubpassDescriptionDepthStencilResolve(VkResolveModeFlagBits depthResolveMode, VkResolveModeFlagBits stencilResolveMode, const VkAttachmentReference2 *pDepthStencilResolveAttachment)
       {
              VkSubpassDescriptionDepthStencilResolve struct_to_fill;
              struct_to_fill.depthResolveMode = depthResolveMode;
              struct_to_fill.stencilResolveMode = stencilResolveMode;
              struct_to_fill.pDepthStencilResolveAttachment = pDepthStencilResolveAttachment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceDepthStencilResolveProperties vkfPhysicalDeviceDepthStencilResolveProperties(VkResolveModeFlags supportedDepthResolveModes, VkResolveModeFlags supportedStencilResolveModes, VkBool32 independentResolveNone, VkBool32 independentResolve)
       {
              VkPhysicalDeviceDepthStencilResolveProperties struct_to_fill;
              struct_to_fill.supportedDepthResolveModes = supportedDepthResolveModes;
              struct_to_fill.supportedStencilResolveModes = supportedStencilResolveModes;
              struct_to_fill.independentResolveNone = independentResolveNone;
              struct_to_fill.independentResolve = independentResolve;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceScalarBlockLayoutFeatures vkfPhysicalDeviceScalarBlockLayoutFeatures(VkBool32 scalarBlockLayout)
       {
              VkPhysicalDeviceScalarBlockLayoutFeatures struct_to_fill;
              struct_to_fill.scalarBlockLayout = scalarBlockLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageStencilUsageCreateInfo vkfImageStencilUsageCreateInfo(VkImageUsageFlags stencilUsage)
       {
              VkImageStencilUsageCreateInfo struct_to_fill;
              struct_to_fill.stencilUsage = stencilUsage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSamplerReductionModeCreateInfo vkfSamplerReductionModeCreateInfo(VkSamplerReductionMode reductionMode)
       {
              VkSamplerReductionModeCreateInfo struct_to_fill;
              struct_to_fill.reductionMode = reductionMode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSamplerFilterMinmaxProperties vkfPhysicalDeviceSamplerFilterMinmaxProperties(VkBool32 filterMinmaxSingleComponentFormats, VkBool32 filterMinmaxImageComponentMapping)
       {
              VkPhysicalDeviceSamplerFilterMinmaxProperties struct_to_fill;
              struct_to_fill.filterMinmaxSingleComponentFormats = filterMinmaxSingleComponentFormats;
              struct_to_fill.filterMinmaxImageComponentMapping = filterMinmaxImageComponentMapping;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVulkanMemoryModelFeatures vkfPhysicalDeviceVulkanMemoryModelFeatures(VkBool32 vulkanMemoryModel, VkBool32 vulkanMemoryModelDeviceScope, VkBool32 vulkanMemoryModelAvailabilityVisibilityChains)
       {
              VkPhysicalDeviceVulkanMemoryModelFeatures struct_to_fill;
              struct_to_fill.vulkanMemoryModel = vulkanMemoryModel;
              struct_to_fill.vulkanMemoryModelDeviceScope = vulkanMemoryModelDeviceScope;
              struct_to_fill.vulkanMemoryModelAvailabilityVisibilityChains = vulkanMemoryModelAvailabilityVisibilityChains;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceImagelessFramebufferFeatures vkfPhysicalDeviceImagelessFramebufferFeatures(VkBool32 imagelessFramebuffer)
       {
              VkPhysicalDeviceImagelessFramebufferFeatures struct_to_fill;
              struct_to_fill.imagelessFramebuffer = imagelessFramebuffer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkFramebufferAttachmentImageInfo vkfFramebufferAttachmentImageInfo(VkImageUsageFlags usage, uint32_t width, uint32_t height, uint32_t layerCount, uint32_t viewFormatCount, const VkFormat *pViewFormats)
       {
              VkFramebufferAttachmentImageInfo struct_to_fill;
              struct_to_fill.usage = usage;
              struct_to_fill.width = width;
              struct_to_fill.height = height;
              struct_to_fill.layerCount = layerCount;
              struct_to_fill.viewFormatCount = viewFormatCount;
              struct_to_fill.pViewFormats = pViewFormats;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkFramebufferAttachmentsCreateInfo vkfFramebufferAttachmentsCreateInfo(uint32_t attachmentImageInfoCount, const VkFramebufferAttachmentImageInfo *pAttachmentImageInfos)
       {
              VkFramebufferAttachmentsCreateInfo struct_to_fill;
              struct_to_fill.attachmentImageInfoCount = attachmentImageInfoCount;
              struct_to_fill.pAttachmentImageInfos = pAttachmentImageInfos;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRenderPassAttachmentBeginInfo vkfRenderPassAttachmentBeginInfo(uint32_t attachmentCount, const VkImageView *pAttachments)
       {
              VkRenderPassAttachmentBeginInfo struct_to_fill;
              struct_to_fill.attachmentCount = attachmentCount;
              struct_to_fill.pAttachments = pAttachments;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceUniformBufferStandardLayoutFeatures vkfPhysicalDeviceUniformBufferStandardLayoutFeatures(VkBool32 uniformBufferStandardLayout)
       {
              VkPhysicalDeviceUniformBufferStandardLayoutFeatures struct_to_fill;
              struct_to_fill.uniformBufferStandardLayout = uniformBufferStandardLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures vkfPhysicalDeviceShaderSubgroupExtendedTypesFeatures(VkBool32 shaderSubgroupExtendedTypes)
       {
              VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures struct_to_fill;
              struct_to_fill.shaderSubgroupExtendedTypes = shaderSubgroupExtendedTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures vkfPhysicalDeviceSeparateDepthStencilLayoutsFeatures(VkBool32 separateDepthStencilLayouts)
       {
              VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures struct_to_fill;
              struct_to_fill.separateDepthStencilLayouts = separateDepthStencilLayouts;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAttachmentReferenceStencilLayout vkfAttachmentReferenceStencilLayout(VkImageLayout stencilLayout)
       {
              VkAttachmentReferenceStencilLayout struct_to_fill;
              struct_to_fill.stencilLayout = stencilLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAttachmentDescriptionStencilLayout vkfAttachmentDescriptionStencilLayout(VkImageLayout stencilInitialLayout, VkImageLayout stencilFinalLayout)
       {
              VkAttachmentDescriptionStencilLayout struct_to_fill;
              struct_to_fill.stencilInitialLayout = stencilInitialLayout;
              struct_to_fill.stencilFinalLayout = stencilFinalLayout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceHostQueryResetFeatures vkfPhysicalDeviceHostQueryResetFeatures(VkBool32 hostQueryReset)
       {
              VkPhysicalDeviceHostQueryResetFeatures struct_to_fill;
              struct_to_fill.hostQueryReset = hostQueryReset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceTimelineSemaphoreFeatures vkfPhysicalDeviceTimelineSemaphoreFeatures(VkBool32 timelineSemaphore)
       {
              VkPhysicalDeviceTimelineSemaphoreFeatures struct_to_fill;
              struct_to_fill.timelineSemaphore = timelineSemaphore;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceTimelineSemaphoreProperties vkfPhysicalDeviceTimelineSemaphoreProperties(uint64_t maxTimelineSemaphoreValueDifference)
       {
              VkPhysicalDeviceTimelineSemaphoreProperties struct_to_fill;
              struct_to_fill.maxTimelineSemaphoreValueDifference = maxTimelineSemaphoreValueDifference;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSemaphoreTypeCreateInfo vkfSemaphoreTypeCreateInfo(VkSemaphoreType semaphoreType, uint64_t initialValue)
       {
              VkSemaphoreTypeCreateInfo struct_to_fill;
              struct_to_fill.semaphoreType = semaphoreType;
              struct_to_fill.initialValue = initialValue;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkTimelineSemaphoreSubmitInfo vkfTimelineSemaphoreSubmitInfo(uint32_t waitSemaphoreValueCount, const uint64_t *pWaitSemaphoreValues, uint32_t signalSemaphoreValueCount, const uint64_t *pSignalSemaphoreValues)
       {
              VkTimelineSemaphoreSubmitInfo struct_to_fill;
              struct_to_fill.waitSemaphoreValueCount = waitSemaphoreValueCount;
              struct_to_fill.pWaitSemaphoreValues = pWaitSemaphoreValues;
              struct_to_fill.signalSemaphoreValueCount = signalSemaphoreValueCount;
              struct_to_fill.pSignalSemaphoreValues = pSignalSemaphoreValues;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSemaphoreWaitInfo vkfSemaphoreWaitInfo(uint32_t semaphoreCount, const VkSemaphore *pSemaphores, const uint64_t *pValues)
       {
              VkSemaphoreWaitInfo struct_to_fill;
              struct_to_fill.semaphoreCount = semaphoreCount;
              struct_to_fill.pSemaphores = pSemaphores;
              struct_to_fill.pValues = pValues;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSemaphoreSignalInfo vkfSemaphoreSignalInfo(VkSemaphore semaphore, uint64_t value)
       {
              VkSemaphoreSignalInfo struct_to_fill;
              struct_to_fill.semaphore = semaphore;
              struct_to_fill.value = value;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceBufferDeviceAddressFeatures vkfPhysicalDeviceBufferDeviceAddressFeatures(VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice)
       {
              VkPhysicalDeviceBufferDeviceAddressFeatures struct_to_fill;
              struct_to_fill.bufferDeviceAddress = bufferDeviceAddress;
              struct_to_fill.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
              struct_to_fill.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBufferDeviceAddressInfo vkfBufferDeviceAddressInfo(VkBuffer buffer)
       {
              VkBufferDeviceAddressInfo struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBufferOpaqueCaptureAddressCreateInfo vkfBufferOpaqueCaptureAddressCreateInfo(uint64_t opaqueCaptureAddress)
       {
              VkBufferOpaqueCaptureAddressCreateInfo struct_to_fill;
              struct_to_fill.opaqueCaptureAddress = opaqueCaptureAddress;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryOpaqueCaptureAddressAllocateInfo vkfMemoryOpaqueCaptureAddressAllocateInfo(uint64_t opaqueCaptureAddress)
       {
              VkMemoryOpaqueCaptureAddressAllocateInfo struct_to_fill;
              struct_to_fill.opaqueCaptureAddress = opaqueCaptureAddress;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceMemoryOpaqueCaptureAddressInfo vkfDeviceMemoryOpaqueCaptureAddressInfo(VkDeviceMemory memory)
       {
              VkDeviceMemoryOpaqueCaptureAddressInfo struct_to_fill;
              struct_to_fill.memory = memory;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_VERSION_1_2
#ifdef VK_KHR_surface
       static inline VkSurfaceCapabilitiesKHR vkfSurfaceCapabilitiesKHR(uint32_t minImageCount, uint32_t maxImageCount, VkExtent2D currentExtent, VkExtent2D minImageExtent, VkExtent2D maxImageExtent, uint32_t maxImageArrayLayers, VkSurfaceTransformFlagsKHR supportedTransforms, VkSurfaceTransformFlagBitsKHR currentTransform, VkCompositeAlphaFlagsKHR supportedCompositeAlpha, VkImageUsageFlags supportedUsageFlags)
       {
              VkSurfaceCapabilitiesKHR struct_to_fill;
              struct_to_fill.minImageCount = minImageCount;
              struct_to_fill.maxImageCount = maxImageCount;
              struct_to_fill.currentExtent = currentExtent;
              struct_to_fill.minImageExtent = minImageExtent;
              struct_to_fill.maxImageExtent = maxImageExtent;
              struct_to_fill.maxImageArrayLayers = maxImageArrayLayers;
              struct_to_fill.supportedTransforms = supportedTransforms;
              struct_to_fill.currentTransform = currentTransform;
              struct_to_fill.supportedCompositeAlpha = supportedCompositeAlpha;
              struct_to_fill.supportedUsageFlags = supportedUsageFlags;
              return struct_to_fill;
       }
       static inline VkSurfaceFormatKHR vkfSurfaceFormatKHR(VkFormat format, VkColorSpaceKHR colorSpace)
       {
              VkSurfaceFormatKHR struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.colorSpace = colorSpace;
              return struct_to_fill;
       }
#endif //VK_KHR_surface
#ifdef VK_KHR_swapchain
       static inline VkSwapchainCreateInfoKHR vkfSwapchainCreateInfoKHR(VkSurfaceKHR surface, uint32_t minImageCount, VkFormat imageFormat, VkColorSpaceKHR imageColorSpace, VkExtent2D imageExtent, uint32_t imageArrayLayers, VkImageUsageFlags imageUsage, VkSharingMode imageSharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices, VkSurfaceTransformFlagBitsKHR preTransform, VkCompositeAlphaFlagBitsKHR compositeAlpha, VkPresentModeKHR presentMode, VkBool32 clipped, VkSwapchainKHR oldSwapchain)
       {
              VkSwapchainCreateInfoKHR struct_to_fill;
              struct_to_fill.surface = surface;
              struct_to_fill.minImageCount = minImageCount;
              struct_to_fill.imageFormat = imageFormat;
              struct_to_fill.imageColorSpace = imageColorSpace;
              struct_to_fill.imageExtent = imageExtent;
              struct_to_fill.imageArrayLayers = imageArrayLayers;
              struct_to_fill.imageUsage = imageUsage;
              struct_to_fill.imageSharingMode = imageSharingMode;
              struct_to_fill.queueFamilyIndexCount = queueFamilyIndexCount;
              struct_to_fill.pQueueFamilyIndices = pQueueFamilyIndices;
              struct_to_fill.preTransform = preTransform;
              struct_to_fill.compositeAlpha = compositeAlpha;
              struct_to_fill.presentMode = presentMode;
              struct_to_fill.clipped = clipped;
              struct_to_fill.oldSwapchain = oldSwapchain;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPresentInfoKHR vkfPresentInfoKHR(uint32_t waitSemaphoreCount, const VkSemaphore *pWaitSemaphores, uint32_t swapchainCount, const VkSwapchainKHR *pSwapchains, const uint32_t *pImageIndices, VkResult *pResults)
       {
              VkPresentInfoKHR struct_to_fill;
              struct_to_fill.waitSemaphoreCount = waitSemaphoreCount;
              struct_to_fill.pWaitSemaphores = pWaitSemaphores;
              struct_to_fill.swapchainCount = swapchainCount;
              struct_to_fill.pSwapchains = pSwapchains;
              struct_to_fill.pImageIndices = pImageIndices;
              struct_to_fill.pResults = pResults;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageSwapchainCreateInfoKHR vkfImageSwapchainCreateInfoKHR(VkSwapchainKHR swapchain)
       {
              VkImageSwapchainCreateInfoKHR struct_to_fill;
              struct_to_fill.swapchain = swapchain;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindImageMemorySwapchainInfoKHR vkfBindImageMemorySwapchainInfoKHR(VkSwapchainKHR swapchain, uint32_t imageIndex)
       {
              VkBindImageMemorySwapchainInfoKHR struct_to_fill;
              struct_to_fill.swapchain = swapchain;
              struct_to_fill.imageIndex = imageIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAcquireNextImageInfoKHR vkfAcquireNextImageInfoKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t deviceMask)
       {
              VkAcquireNextImageInfoKHR struct_to_fill;
              struct_to_fill.swapchain = swapchain;
              struct_to_fill.timeout = timeout;
              struct_to_fill.semaphore = semaphore;
              struct_to_fill.fence = fence;
              struct_to_fill.deviceMask = deviceMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupPresentCapabilitiesKHR vkfDeviceGroupPresentCapabilitiesKHR(VkDeviceGroupPresentModeFlagsKHR modes)
       {
              VkDeviceGroupPresentCapabilitiesKHR struct_to_fill;
              struct_to_fill.modes = modes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupPresentInfoKHR vkfDeviceGroupPresentInfoKHR(uint32_t swapchainCount, const uint32_t *pDeviceMasks, VkDeviceGroupPresentModeFlagBitsKHR mode)
       {
              VkDeviceGroupPresentInfoKHR struct_to_fill;
              struct_to_fill.swapchainCount = swapchainCount;
              struct_to_fill.pDeviceMasks = pDeviceMasks;
              struct_to_fill.mode = mode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceGroupSwapchainCreateInfoKHR vkfDeviceGroupSwapchainCreateInfoKHR(VkDeviceGroupPresentModeFlagsKHR modes)
       {
              VkDeviceGroupSwapchainCreateInfoKHR struct_to_fill;
              struct_to_fill.modes = modes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_swapchain
#ifdef VK_KHR_display
       static inline VkDisplayPropertiesKHR vkfDisplayPropertiesKHR(VkDisplayKHR display, const char *displayName, VkExtent2D physicalDimensions, VkExtent2D physicalResolution, VkSurfaceTransformFlagsKHR supportedTransforms, VkBool32 planeReorderPossible, VkBool32 persistentContent)
       {
              VkDisplayPropertiesKHR struct_to_fill;
              struct_to_fill.display = display;
              struct_to_fill.displayName = displayName;
              struct_to_fill.physicalDimensions = physicalDimensions;
              struct_to_fill.physicalResolution = physicalResolution;
              struct_to_fill.supportedTransforms = supportedTransforms;
              struct_to_fill.planeReorderPossible = planeReorderPossible;
              struct_to_fill.persistentContent = persistentContent;
              return struct_to_fill;
       }
       static inline VkDisplayModeParametersKHR vkfDisplayModeParametersKHR(VkExtent2D visibleRegion, uint32_t refreshRate)
       {
              VkDisplayModeParametersKHR struct_to_fill;
              struct_to_fill.visibleRegion = visibleRegion;
              struct_to_fill.refreshRate = refreshRate;
              return struct_to_fill;
       }
       static inline VkDisplayModePropertiesKHR vkfDisplayModePropertiesKHR(VkDisplayModeKHR displayMode, VkDisplayModeParametersKHR parameters)
       {
              VkDisplayModePropertiesKHR struct_to_fill;
              struct_to_fill.displayMode = displayMode;
              struct_to_fill.parameters = parameters;
              return struct_to_fill;
       }
       static inline VkDisplayModeCreateInfoKHR vkfDisplayModeCreateInfoKHR(VkDisplayModeParametersKHR parameters)
       {
              VkDisplayModeCreateInfoKHR struct_to_fill;
              struct_to_fill.parameters = parameters;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDisplayPlaneCapabilitiesKHR vkfDisplayPlaneCapabilitiesKHR(VkDisplayPlaneAlphaFlagsKHR supportedAlpha, VkOffset2D minSrcPosition, VkOffset2D maxSrcPosition, VkExtent2D minSrcExtent, VkExtent2D maxSrcExtent, VkOffset2D minDstPosition, VkOffset2D maxDstPosition, VkExtent2D minDstExtent, VkExtent2D maxDstExtent)
       {
              VkDisplayPlaneCapabilitiesKHR struct_to_fill;
              struct_to_fill.supportedAlpha = supportedAlpha;
              struct_to_fill.minSrcPosition = minSrcPosition;
              struct_to_fill.maxSrcPosition = maxSrcPosition;
              struct_to_fill.minSrcExtent = minSrcExtent;
              struct_to_fill.maxSrcExtent = maxSrcExtent;
              struct_to_fill.minDstPosition = minDstPosition;
              struct_to_fill.maxDstPosition = maxDstPosition;
              struct_to_fill.minDstExtent = minDstExtent;
              struct_to_fill.maxDstExtent = maxDstExtent;
              return struct_to_fill;
       }
       static inline VkDisplayPlanePropertiesKHR vkfDisplayPlanePropertiesKHR(VkDisplayKHR currentDisplay, uint32_t currentStackIndex)
       {
              VkDisplayPlanePropertiesKHR struct_to_fill;
              struct_to_fill.currentDisplay = currentDisplay;
              struct_to_fill.currentStackIndex = currentStackIndex;
              return struct_to_fill;
       }
       static inline VkDisplaySurfaceCreateInfoKHR vkfDisplaySurfaceCreateInfoKHR(VkDisplayModeKHR displayMode, uint32_t planeIndex, uint32_t planeStackIndex, VkSurfaceTransformFlagBitsKHR transform, float globalAlpha, VkDisplayPlaneAlphaFlagBitsKHR alphaMode, VkExtent2D imageExtent)
       {
              VkDisplaySurfaceCreateInfoKHR struct_to_fill;
              struct_to_fill.displayMode = displayMode;
              struct_to_fill.planeIndex = planeIndex;
              struct_to_fill.planeStackIndex = planeStackIndex;
              struct_to_fill.transform = transform;
              struct_to_fill.globalAlpha = globalAlpha;
              struct_to_fill.alphaMode = alphaMode;
              struct_to_fill.imageExtent = imageExtent;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_KHR_display
#ifdef VK_KHR_display_swapchain
       static inline VkDisplayPresentInfoKHR vkfDisplayPresentInfoKHR(VkRect2D srcRect, VkRect2D dstRect, VkBool32 persistent)
       {
              VkDisplayPresentInfoKHR struct_to_fill;
              struct_to_fill.srcRect = srcRect;
              struct_to_fill.dstRect = dstRect;
              struct_to_fill.persistent = persistent;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_display_swapchain
#ifdef VK_KHR_external_memory_fd
       static inline VkImportMemoryFdInfoKHR vkfImportMemoryFdInfoKHR(VkExternalMemoryHandleTypeFlagBits handleType, int fd)
       {
              VkImportMemoryFdInfoKHR struct_to_fill;
              struct_to_fill.handleType = handleType;
              struct_to_fill.fd = fd;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryFdPropertiesKHR vkfMemoryFdPropertiesKHR(uint32_t memoryTypeBits)
       {
              VkMemoryFdPropertiesKHR struct_to_fill;
              struct_to_fill.memoryTypeBits = memoryTypeBits;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryGetFdInfoKHR vkfMemoryGetFdInfoKHR(VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagBits handleType)
       {
              VkMemoryGetFdInfoKHR struct_to_fill;
              struct_to_fill.memory = memory;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_external_memory_fd
#ifdef VK_KHR_external_semaphore_fd
       static inline VkImportSemaphoreFdInfoKHR vkfImportSemaphoreFdInfoKHR(VkSemaphore semaphore, VkExternalSemaphoreHandleTypeFlagBits handleType, int fd)
       {
              VkImportSemaphoreFdInfoKHR struct_to_fill;
              struct_to_fill.semaphore = semaphore;
              struct_to_fill.handleType = handleType;
              struct_to_fill.fd = fd;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkSemaphoreGetFdInfoKHR vkfSemaphoreGetFdInfoKHR(VkSemaphore semaphore, VkExternalSemaphoreHandleTypeFlagBits handleType)
       {
              VkSemaphoreGetFdInfoKHR struct_to_fill;
              struct_to_fill.semaphore = semaphore;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_external_semaphore_fd
#ifdef VK_KHR_push_descriptor
       static inline VkPhysicalDevicePushDescriptorPropertiesKHR vkfPhysicalDevicePushDescriptorPropertiesKHR(uint32_t maxPushDescriptors)
       {
              VkPhysicalDevicePushDescriptorPropertiesKHR struct_to_fill;
              struct_to_fill.maxPushDescriptors = maxPushDescriptors;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_push_descriptor
#ifdef VK_KHR_incremental_present
       static inline VkRectLayerKHR vkfRectLayerKHR(VkOffset2D offset, VkExtent2D extent, uint32_t layer)
       {
              VkRectLayerKHR struct_to_fill;
              struct_to_fill.offset = offset;
              struct_to_fill.extent = extent;
              struct_to_fill.layer = layer;
              return struct_to_fill;
       }
       static inline VkPresentRegionKHR vkfPresentRegionKHR(uint32_t rectangleCount, const VkRectLayerKHR *pRectangles)
       {
              VkPresentRegionKHR struct_to_fill;
              struct_to_fill.rectangleCount = rectangleCount;
              struct_to_fill.pRectangles = pRectangles;
              return struct_to_fill;
       }
       static inline VkPresentRegionsKHR vkfPresentRegionsKHR(uint32_t swapchainCount, const VkPresentRegionKHR *pRegions)
       {
              VkPresentRegionsKHR struct_to_fill;
              struct_to_fill.swapchainCount = swapchainCount;
              struct_to_fill.pRegions = pRegions;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_incremental_present
#ifdef VK_KHR_shared_presentable_image
       static inline VkSharedPresentSurfaceCapabilitiesKHR vkfSharedPresentSurfaceCapabilitiesKHR(VkImageUsageFlags sharedPresentSupportedUsageFlags)
       {
              VkSharedPresentSurfaceCapabilitiesKHR struct_to_fill;
              struct_to_fill.sharedPresentSupportedUsageFlags = sharedPresentSupportedUsageFlags;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_shared_presentable_image
#ifdef VK_KHR_external_fence_fd
       static inline VkImportFenceFdInfoKHR vkfImportFenceFdInfoKHR(VkFence fence, VkExternalFenceHandleTypeFlagBits handleType, int fd)
       {
              VkImportFenceFdInfoKHR struct_to_fill;
              struct_to_fill.fence = fence;
              struct_to_fill.handleType = handleType;
              struct_to_fill.fd = fd;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkFenceGetFdInfoKHR vkfFenceGetFdInfoKHR(VkFence fence, VkExternalFenceHandleTypeFlagBits handleType)
       {
              VkFenceGetFdInfoKHR struct_to_fill;
              struct_to_fill.fence = fence;
              struct_to_fill.handleType = handleType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_external_fence_fd
#ifdef VK_KHR_performance_query
       static inline VkPhysicalDevicePerformanceQueryFeaturesKHR vkfPhysicalDevicePerformanceQueryFeaturesKHR(VkBool32 performanceCounterQueryPools, VkBool32 performanceCounterMultipleQueryPools)
       {
              VkPhysicalDevicePerformanceQueryFeaturesKHR struct_to_fill;
              struct_to_fill.performanceCounterQueryPools = performanceCounterQueryPools;
              struct_to_fill.performanceCounterMultipleQueryPools = performanceCounterMultipleQueryPools;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDevicePerformanceQueryPropertiesKHR vkfPhysicalDevicePerformanceQueryPropertiesKHR(VkBool32 allowCommandBufferQueryCopies)
       {
              VkPhysicalDevicePerformanceQueryPropertiesKHR struct_to_fill;
              struct_to_fill.allowCommandBufferQueryCopies = allowCommandBufferQueryCopies;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceCounterKHR vkfPerformanceCounterKHR(VkPerformanceCounterUnitKHR unit, VkPerformanceCounterScopeKHR scope, VkPerformanceCounterStorageKHR storage)
       {
              VkPerformanceCounterKHR struct_to_fill;
              struct_to_fill.unit = unit;
              struct_to_fill.scope = scope;
              struct_to_fill.storage = storage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceCounterDescriptionKHR vkfPerformanceCounterDescriptionKHR()
       {
              VkPerformanceCounterDescriptionKHR struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkQueryPoolPerformanceCreateInfoKHR vkfQueryPoolPerformanceCreateInfoKHR(uint32_t queueFamilyIndex, uint32_t counterIndexCount, const uint32_t *pCounterIndices)
       {
              VkQueryPoolPerformanceCreateInfoKHR struct_to_fill;
              struct_to_fill.queueFamilyIndex = queueFamilyIndex;
              struct_to_fill.counterIndexCount = counterIndexCount;
              struct_to_fill.pCounterIndices = pCounterIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAcquireProfilingLockInfoKHR vkfAcquireProfilingLockInfoKHR(uint64_t timeout)
       {
              VkAcquireProfilingLockInfoKHR struct_to_fill;
              struct_to_fill.timeout = timeout;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPerformanceQuerySubmitInfoKHR vkfPerformanceQuerySubmitInfoKHR(uint32_t counterPassIndex)
       {
              VkPerformanceQuerySubmitInfoKHR struct_to_fill;
              struct_to_fill.counterPassIndex = counterPassIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_performance_query
#ifdef VK_KHR_get_surface_capabilities2
       static inline VkPhysicalDeviceSurfaceInfo2KHR vkfPhysicalDeviceSurfaceInfo2KHR(VkSurfaceKHR surface)
       {
              VkPhysicalDeviceSurfaceInfo2KHR struct_to_fill;
              struct_to_fill.surface = surface;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSurfaceCapabilities2KHR vkfSurfaceCapabilities2KHR(VkSurfaceCapabilitiesKHR surfaceCapabilities)
       {
              VkSurfaceCapabilities2KHR struct_to_fill;
              struct_to_fill.surfaceCapabilities = surfaceCapabilities;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSurfaceFormat2KHR vkfSurfaceFormat2KHR(VkSurfaceFormatKHR surfaceFormat)
       {
              VkSurfaceFormat2KHR struct_to_fill;
              struct_to_fill.surfaceFormat = surfaceFormat;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_get_surface_capabilities2
#ifdef VK_KHR_get_display_properties2
       static inline VkDisplayProperties2KHR vkfDisplayProperties2KHR(VkDisplayPropertiesKHR displayProperties)
       {
              VkDisplayProperties2KHR struct_to_fill;
              struct_to_fill.displayProperties = displayProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDisplayPlaneProperties2KHR vkfDisplayPlaneProperties2KHR(VkDisplayPlanePropertiesKHR displayPlaneProperties)
       {
              VkDisplayPlaneProperties2KHR struct_to_fill;
              struct_to_fill.displayPlaneProperties = displayPlaneProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDisplayModeProperties2KHR vkfDisplayModeProperties2KHR(VkDisplayModePropertiesKHR displayModeProperties)
       {
              VkDisplayModeProperties2KHR struct_to_fill;
              struct_to_fill.displayModeProperties = displayModeProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDisplayPlaneInfo2KHR vkfDisplayPlaneInfo2KHR(VkDisplayModeKHR mode, uint32_t planeIndex)
       {
              VkDisplayPlaneInfo2KHR struct_to_fill;
              struct_to_fill.mode = mode;
              struct_to_fill.planeIndex = planeIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDisplayPlaneCapabilities2KHR vkfDisplayPlaneCapabilities2KHR(VkDisplayPlaneCapabilitiesKHR capabilities)
       {
              VkDisplayPlaneCapabilities2KHR struct_to_fill;
              struct_to_fill.capabilities = capabilities;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_get_display_properties2
#ifdef VK_KHR_shader_clock
       static inline VkPhysicalDeviceShaderClockFeaturesKHR vkfPhysicalDeviceShaderClockFeaturesKHR(VkBool32 shaderSubgroupClock, VkBool32 shaderDeviceClock)
       {
              VkPhysicalDeviceShaderClockFeaturesKHR struct_to_fill;
              struct_to_fill.shaderSubgroupClock = shaderSubgroupClock;
              struct_to_fill.shaderDeviceClock = shaderDeviceClock;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_shader_clock
#ifdef VK_KHR_surface_protected_capabilities
       static inline VkSurfaceProtectedCapabilitiesKHR vkfSurfaceProtectedCapabilitiesKHR(VkBool32 supportsProtected)
       {
              VkSurfaceProtectedCapabilitiesKHR struct_to_fill;
              struct_to_fill.supportsProtected = supportsProtected;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_surface_protected_capabilities
#ifdef VK_KHR_pipeline_executable_properties
       static inline VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR vkfPhysicalDevicePipelineExecutablePropertiesFeaturesKHR(VkBool32 pipelineExecutableInfo)
       {
              VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR struct_to_fill;
              struct_to_fill.pipelineExecutableInfo = pipelineExecutableInfo;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineInfoKHR vkfPipelineInfoKHR(VkPipeline pipeline)
       {
              VkPipelineInfoKHR struct_to_fill;
              struct_to_fill.pipeline = pipeline;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineExecutablePropertiesKHR vkfPipelineExecutablePropertiesKHR(VkShaderStageFlags stages, uint32_t subgroupSize)
       {
              VkPipelineExecutablePropertiesKHR struct_to_fill;
              struct_to_fill.stages = stages;
              struct_to_fill.subgroupSize = subgroupSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineExecutableInfoKHR vkfPipelineExecutableInfoKHR(VkPipeline pipeline, uint32_t executableIndex)
       {
              VkPipelineExecutableInfoKHR struct_to_fill;
              struct_to_fill.pipeline = pipeline;
              struct_to_fill.executableIndex = executableIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineExecutableStatisticKHR vkfPipelineExecutableStatisticKHR(VkPipelineExecutableStatisticFormatKHR format, VkPipelineExecutableStatisticValueKHR value)
       {
              VkPipelineExecutableStatisticKHR struct_to_fill;
              struct_to_fill.format = format;
              struct_to_fill.value = value;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineExecutableInternalRepresentationKHR vkfPipelineExecutableInternalRepresentationKHR(VkBool32 isText, size_t dataSize, void *pData)
       {
              VkPipelineExecutableInternalRepresentationKHR struct_to_fill;
              struct_to_fill.isText = isText;
              struct_to_fill.dataSize = dataSize;
              struct_to_fill.pData = pData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_KHR_pipeline_executable_properties
#ifdef VK_EXT_debug_report
       static inline VkDebugReportCallbackCreateInfoEXT vkfDebugReportCallbackCreateInfoEXT(PFN_vkDebugReportCallbackEXT pfnCallback, void *pUserData)
       {
              VkDebugReportCallbackCreateInfoEXT struct_to_fill;
              struct_to_fill.pfnCallback = pfnCallback;
              struct_to_fill.pUserData = pUserData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_debug_report
#ifdef VK_AMD_rasterization_order
       static inline VkPipelineRasterizationStateRasterizationOrderAMD vkfPipelineRasterizationStateRasterizationOrderAMD(VkRasterizationOrderAMD rasterizationOrder)
       {
              VkPipelineRasterizationStateRasterizationOrderAMD struct_to_fill;
              struct_to_fill.rasterizationOrder = rasterizationOrder;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_rasterization_order
#ifdef VK_EXT_debug_marker
       static inline VkDebugMarkerObjectNameInfoEXT vkfDebugMarkerObjectNameInfoEXT(VkDebugReportObjectTypeEXT objectType, uint64_t object, const char *pObjectName)
       {
              VkDebugMarkerObjectNameInfoEXT struct_to_fill;
              struct_to_fill.objectType = objectType;
              struct_to_fill.object = object;
              struct_to_fill.pObjectName = pObjectName;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDebugMarkerObjectTagInfoEXT vkfDebugMarkerObjectTagInfoEXT(VkDebugReportObjectTypeEXT objectType, uint64_t object, uint64_t tagName, size_t tagSize, const void *pTag)
       {
              VkDebugMarkerObjectTagInfoEXT struct_to_fill;
              struct_to_fill.objectType = objectType;
              struct_to_fill.object = object;
              struct_to_fill.tagName = tagName;
              struct_to_fill.tagSize = tagSize;
              struct_to_fill.pTag = pTag;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDebugMarkerMarkerInfoEXT vkfDebugMarkerMarkerInfoEXT(const char *pMarkerName)
       {
              VkDebugMarkerMarkerInfoEXT struct_to_fill;
              struct_to_fill.pMarkerName = pMarkerName;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_debug_marker
#ifdef VK_NV_dedicated_allocation
       static inline VkDedicatedAllocationImageCreateInfoNV vkfDedicatedAllocationImageCreateInfoNV(VkBool32 dedicatedAllocation)
       {
              VkDedicatedAllocationImageCreateInfoNV struct_to_fill;
              struct_to_fill.dedicatedAllocation = dedicatedAllocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDedicatedAllocationBufferCreateInfoNV vkfDedicatedAllocationBufferCreateInfoNV(VkBool32 dedicatedAllocation)
       {
              VkDedicatedAllocationBufferCreateInfoNV struct_to_fill;
              struct_to_fill.dedicatedAllocation = dedicatedAllocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDedicatedAllocationMemoryAllocateInfoNV vkfDedicatedAllocationMemoryAllocateInfoNV(VkImage image, VkBuffer buffer)
       {
              VkDedicatedAllocationMemoryAllocateInfoNV struct_to_fill;
              struct_to_fill.image = image;
              struct_to_fill.buffer = buffer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_dedicated_allocation
#ifdef VK_EXT_transform_feedback
       static inline VkPhysicalDeviceTransformFeedbackFeaturesEXT vkfPhysicalDeviceTransformFeedbackFeaturesEXT(VkBool32 transformFeedback, VkBool32 geometryStreams)
       {
              VkPhysicalDeviceTransformFeedbackFeaturesEXT struct_to_fill;
              struct_to_fill.transformFeedback = transformFeedback;
              struct_to_fill.geometryStreams = geometryStreams;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceTransformFeedbackPropertiesEXT vkfPhysicalDeviceTransformFeedbackPropertiesEXT(uint32_t maxTransformFeedbackStreams, uint32_t maxTransformFeedbackBuffers, VkDeviceSize maxTransformFeedbackBufferSize, uint32_t maxTransformFeedbackStreamDataSize, uint32_t maxTransformFeedbackBufferDataSize, uint32_t maxTransformFeedbackBufferDataStride, VkBool32 transformFeedbackQueries, VkBool32 transformFeedbackStreamsLinesTriangles, VkBool32 transformFeedbackRasterizationStreamSelect, VkBool32 transformFeedbackDraw)
       {
              VkPhysicalDeviceTransformFeedbackPropertiesEXT struct_to_fill;
              struct_to_fill.maxTransformFeedbackStreams = maxTransformFeedbackStreams;
              struct_to_fill.maxTransformFeedbackBuffers = maxTransformFeedbackBuffers;
              struct_to_fill.maxTransformFeedbackBufferSize = maxTransformFeedbackBufferSize;
              struct_to_fill.maxTransformFeedbackStreamDataSize = maxTransformFeedbackStreamDataSize;
              struct_to_fill.maxTransformFeedbackBufferDataSize = maxTransformFeedbackBufferDataSize;
              struct_to_fill.maxTransformFeedbackBufferDataStride = maxTransformFeedbackBufferDataStride;
              struct_to_fill.transformFeedbackQueries = transformFeedbackQueries;
              struct_to_fill.transformFeedbackStreamsLinesTriangles = transformFeedbackStreamsLinesTriangles;
              struct_to_fill.transformFeedbackRasterizationStreamSelect = transformFeedbackRasterizationStreamSelect;
              struct_to_fill.transformFeedbackDraw = transformFeedbackDraw;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineRasterizationStateStreamCreateInfoEXT vkfPipelineRasterizationStateStreamCreateInfoEXT(uint32_t rasterizationStream)
       {
              VkPipelineRasterizationStateStreamCreateInfoEXT struct_to_fill;
              struct_to_fill.rasterizationStream = rasterizationStream;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_transform_feedback
#ifdef VK_NVX_image_view_handle
       static inline VkImageViewHandleInfoNVX vkfImageViewHandleInfoNVX(VkImageView imageView, VkDescriptorType descriptorType, VkSampler sampler)
       {
              VkImageViewHandleInfoNVX struct_to_fill;
              struct_to_fill.imageView = imageView;
              struct_to_fill.descriptorType = descriptorType;
              struct_to_fill.sampler = sampler;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NVX_image_view_handle
#ifdef VK_AMD_texture_gather_bias_lod
       static inline VkTextureLODGatherFormatPropertiesAMD vkfTextureLODGatherFormatPropertiesAMD(VkBool32 supportsTextureGatherLODBiasAMD)
       {
              VkTextureLODGatherFormatPropertiesAMD struct_to_fill;
              struct_to_fill.supportsTextureGatherLODBiasAMD = supportsTextureGatherLODBiasAMD;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_texture_gather_bias_lod
#ifdef VK_AMD_shader_info
       static inline VkShaderResourceUsageAMD vkfShaderResourceUsageAMD(uint32_t numUsedVgprs, uint32_t numUsedSgprs, uint32_t ldsSizePerLocalWorkGroup, size_t ldsUsageSizeInBytes, size_t scratchMemUsageInBytes)
       {
              VkShaderResourceUsageAMD struct_to_fill;
              struct_to_fill.numUsedVgprs = numUsedVgprs;
              struct_to_fill.numUsedSgprs = numUsedSgprs;
              struct_to_fill.ldsSizePerLocalWorkGroup = ldsSizePerLocalWorkGroup;
              struct_to_fill.ldsUsageSizeInBytes = ldsUsageSizeInBytes;
              struct_to_fill.scratchMemUsageInBytes = scratchMemUsageInBytes;
              return struct_to_fill;
       }
       static inline VkShaderStatisticsInfoAMD vkfShaderStatisticsInfoAMD(VkShaderStageFlags shaderStageMask, VkShaderResourceUsageAMD resourceUsage, uint32_t numPhysicalVgprs, uint32_t numPhysicalSgprs, uint32_t numAvailableVgprs, uint32_t numAvailableSgprs)
       {
              VkShaderStatisticsInfoAMD struct_to_fill;
              struct_to_fill.shaderStageMask = shaderStageMask;
              struct_to_fill.resourceUsage = resourceUsage;
              struct_to_fill.numPhysicalVgprs = numPhysicalVgprs;
              struct_to_fill.numPhysicalSgprs = numPhysicalSgprs;
              struct_to_fill.numAvailableVgprs = numAvailableVgprs;
              struct_to_fill.numAvailableSgprs = numAvailableSgprs;
              return struct_to_fill;
       }
#endif //VK_AMD_shader_info
#ifdef VK_NV_corner_sampled_image
       static inline VkPhysicalDeviceCornerSampledImageFeaturesNV vkfPhysicalDeviceCornerSampledImageFeaturesNV(VkBool32 cornerSampledImage)
       {
              VkPhysicalDeviceCornerSampledImageFeaturesNV struct_to_fill;
              struct_to_fill.cornerSampledImage = cornerSampledImage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_corner_sampled_image
#ifdef VK_NV_external_memory_capabilities
       static inline VkExternalImageFormatPropertiesNV vkfExternalImageFormatPropertiesNV(VkImageFormatProperties imageFormatProperties, VkExternalMemoryFeatureFlagsNV externalMemoryFeatures, VkExternalMemoryHandleTypeFlagsNV exportFromImportedHandleTypes, VkExternalMemoryHandleTypeFlagsNV compatibleHandleTypes)
       {
              VkExternalImageFormatPropertiesNV struct_to_fill;
              struct_to_fill.imageFormatProperties = imageFormatProperties;
              struct_to_fill.externalMemoryFeatures = externalMemoryFeatures;
              struct_to_fill.exportFromImportedHandleTypes = exportFromImportedHandleTypes;
              struct_to_fill.compatibleHandleTypes = compatibleHandleTypes;
              return struct_to_fill;
       }
#endif //VK_NV_external_memory_capabilities
#ifdef VK_NV_external_memory
       static inline VkExternalMemoryImageCreateInfoNV vkfExternalMemoryImageCreateInfoNV(VkExternalMemoryHandleTypeFlagsNV handleTypes)
       {
              VkExternalMemoryImageCreateInfoNV struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkExportMemoryAllocateInfoNV vkfExportMemoryAllocateInfoNV(VkExternalMemoryHandleTypeFlagsNV handleTypes)
       {
              VkExportMemoryAllocateInfoNV struct_to_fill;
              struct_to_fill.handleTypes = handleTypes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_external_memory
#ifdef VK_EXT_validation_flags
       static inline VkValidationFlagsEXT vkfValidationFlagsEXT(uint32_t disabledValidationCheckCount, const VkValidationCheckEXT *pDisabledValidationChecks)
       {
              VkValidationFlagsEXT struct_to_fill;
              struct_to_fill.disabledValidationCheckCount = disabledValidationCheckCount;
              struct_to_fill.pDisabledValidationChecks = pDisabledValidationChecks;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_validation_flags
#ifdef VK_EXT_texture_compression_astc_hdr
       static inline VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT vkfPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT(VkBool32 textureCompressionASTC_HDR)
       {
              VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT struct_to_fill;
              struct_to_fill.textureCompressionASTC_HDR = textureCompressionASTC_HDR;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_texture_compression_astc_hdr
#ifdef VK_EXT_astc_decode_mode
       static inline VkImageViewASTCDecodeModeEXT vkfImageViewASTCDecodeModeEXT(VkFormat decodeMode)
       {
              VkImageViewASTCDecodeModeEXT struct_to_fill;
              struct_to_fill.decodeMode = decodeMode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceASTCDecodeFeaturesEXT vkfPhysicalDeviceASTCDecodeFeaturesEXT(VkBool32 decodeModeSharedExponent)
       {
              VkPhysicalDeviceASTCDecodeFeaturesEXT struct_to_fill;
              struct_to_fill.decodeModeSharedExponent = decodeModeSharedExponent;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_astc_decode_mode
#ifdef VK_EXT_conditional_rendering
       static inline VkConditionalRenderingBeginInfoEXT vkfConditionalRenderingBeginInfoEXT(VkBuffer buffer, VkDeviceSize offset)
       {
              VkConditionalRenderingBeginInfoEXT struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.offset = offset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceConditionalRenderingFeaturesEXT vkfPhysicalDeviceConditionalRenderingFeaturesEXT(VkBool32 conditionalRendering, VkBool32 inheritedConditionalRendering)
       {
              VkPhysicalDeviceConditionalRenderingFeaturesEXT struct_to_fill;
              struct_to_fill.conditionalRendering = conditionalRendering;
              struct_to_fill.inheritedConditionalRendering = inheritedConditionalRendering;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCommandBufferInheritanceConditionalRenderingInfoEXT vkfCommandBufferInheritanceConditionalRenderingInfoEXT(VkBool32 conditionalRenderingEnable)
       {
              VkCommandBufferInheritanceConditionalRenderingInfoEXT struct_to_fill;
              struct_to_fill.conditionalRenderingEnable = conditionalRenderingEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_conditional_rendering
#ifdef VK_NV_clip_space_w_scaling
       static inline VkViewportWScalingNV vkfViewportWScalingNV(float xcoeff, float ycoeff)
       {
              VkViewportWScalingNV struct_to_fill;
              struct_to_fill.xcoeff = xcoeff;
              struct_to_fill.ycoeff = ycoeff;
              return struct_to_fill;
       }
       static inline VkPipelineViewportWScalingStateCreateInfoNV vkfPipelineViewportWScalingStateCreateInfoNV(VkBool32 viewportWScalingEnable, uint32_t viewportCount, const VkViewportWScalingNV *pViewportWScalings)
       {
              VkPipelineViewportWScalingStateCreateInfoNV struct_to_fill;
              struct_to_fill.viewportWScalingEnable = viewportWScalingEnable;
              struct_to_fill.viewportCount = viewportCount;
              struct_to_fill.pViewportWScalings = pViewportWScalings;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_clip_space_w_scaling
#ifdef VK_EXT_display_surface_counter
       static inline VkSurfaceCapabilities2EXT vkfSurfaceCapabilities2EXT(uint32_t minImageCount, uint32_t maxImageCount, VkExtent2D currentExtent, VkExtent2D minImageExtent, VkExtent2D maxImageExtent, uint32_t maxImageArrayLayers, VkSurfaceTransformFlagsKHR supportedTransforms, VkSurfaceTransformFlagBitsKHR currentTransform, VkCompositeAlphaFlagsKHR supportedCompositeAlpha, VkImageUsageFlags supportedUsageFlags, VkSurfaceCounterFlagsEXT supportedSurfaceCounters)
       {
              VkSurfaceCapabilities2EXT struct_to_fill;
              struct_to_fill.minImageCount = minImageCount;
              struct_to_fill.maxImageCount = maxImageCount;
              struct_to_fill.currentExtent = currentExtent;
              struct_to_fill.minImageExtent = minImageExtent;
              struct_to_fill.maxImageExtent = maxImageExtent;
              struct_to_fill.maxImageArrayLayers = maxImageArrayLayers;
              struct_to_fill.supportedTransforms = supportedTransforms;
              struct_to_fill.currentTransform = currentTransform;
              struct_to_fill.supportedCompositeAlpha = supportedCompositeAlpha;
              struct_to_fill.supportedUsageFlags = supportedUsageFlags;
              struct_to_fill.supportedSurfaceCounters = supportedSurfaceCounters;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_display_surface_counter
#ifdef VK_EXT_display_control
       static inline VkDisplayPowerInfoEXT vkfDisplayPowerInfoEXT(VkDisplayPowerStateEXT powerState)
       {
              VkDisplayPowerInfoEXT struct_to_fill;
              struct_to_fill.powerState = powerState;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceEventInfoEXT vkfDeviceEventInfoEXT(VkDeviceEventTypeEXT deviceEvent)
       {
              VkDeviceEventInfoEXT struct_to_fill;
              struct_to_fill.deviceEvent = deviceEvent;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDisplayEventInfoEXT vkfDisplayEventInfoEXT(VkDisplayEventTypeEXT displayEvent)
       {
              VkDisplayEventInfoEXT struct_to_fill;
              struct_to_fill.displayEvent = displayEvent;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSwapchainCounterCreateInfoEXT vkfSwapchainCounterCreateInfoEXT(VkSurfaceCounterFlagsEXT surfaceCounters)
       {
              VkSwapchainCounterCreateInfoEXT struct_to_fill;
              struct_to_fill.surfaceCounters = surfaceCounters;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_display_control
#ifdef VK_GOOGLE_display_timing
       static inline VkRefreshCycleDurationGOOGLE vkfRefreshCycleDurationGOOGLE(uint64_t refreshDuration)
       {
              VkRefreshCycleDurationGOOGLE struct_to_fill;
              struct_to_fill.refreshDuration = refreshDuration;
              return struct_to_fill;
       }
       static inline VkPastPresentationTimingGOOGLE vkfPastPresentationTimingGOOGLE(uint32_t presentID, uint64_t desiredPresentTime, uint64_t actualPresentTime, uint64_t earliestPresentTime, uint64_t presentMargin)
       {
              VkPastPresentationTimingGOOGLE struct_to_fill;
              struct_to_fill.presentID = presentID;
              struct_to_fill.desiredPresentTime = desiredPresentTime;
              struct_to_fill.actualPresentTime = actualPresentTime;
              struct_to_fill.earliestPresentTime = earliestPresentTime;
              struct_to_fill.presentMargin = presentMargin;
              return struct_to_fill;
       }
       static inline VkPresentTimeGOOGLE vkfPresentTimeGOOGLE(uint32_t presentID, uint64_t desiredPresentTime)
       {
              VkPresentTimeGOOGLE struct_to_fill;
              struct_to_fill.presentID = presentID;
              struct_to_fill.desiredPresentTime = desiredPresentTime;
              return struct_to_fill;
       }
       static inline VkPresentTimesInfoGOOGLE vkfPresentTimesInfoGOOGLE(uint32_t swapchainCount, const VkPresentTimeGOOGLE *pTimes)
       {
              VkPresentTimesInfoGOOGLE struct_to_fill;
              struct_to_fill.swapchainCount = swapchainCount;
              struct_to_fill.pTimes = pTimes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_GOOGLE_display_timing
#ifdef VK_NVX_multiview_per_view_attributes
       static inline VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX vkfPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(VkBool32 perViewPositionAllComponents)
       {
              VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX struct_to_fill;
              struct_to_fill.perViewPositionAllComponents = perViewPositionAllComponents;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NVX_multiview_per_view_attributes
#ifdef VK_NV_viewport_swizzle
       static inline VkViewportSwizzleNV vkfViewportSwizzleNV(VkViewportCoordinateSwizzleNV x, VkViewportCoordinateSwizzleNV y, VkViewportCoordinateSwizzleNV z, VkViewportCoordinateSwizzleNV w)
       {
              VkViewportSwizzleNV struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              struct_to_fill.z = z;
              struct_to_fill.w = w;
              return struct_to_fill;
       }
       static inline VkPipelineViewportSwizzleStateCreateInfoNV vkfPipelineViewportSwizzleStateCreateInfoNV(uint32_t viewportCount, const VkViewportSwizzleNV *pViewportSwizzles)
       {
              VkPipelineViewportSwizzleStateCreateInfoNV struct_to_fill;
              struct_to_fill.viewportCount = viewportCount;
              struct_to_fill.pViewportSwizzles = pViewportSwizzles;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_NV_viewport_swizzle
#ifdef VK_EXT_discard_rectangles
       static inline VkPhysicalDeviceDiscardRectanglePropertiesEXT vkfPhysicalDeviceDiscardRectanglePropertiesEXT(uint32_t maxDiscardRectangles)
       {
              VkPhysicalDeviceDiscardRectanglePropertiesEXT struct_to_fill;
              struct_to_fill.maxDiscardRectangles = maxDiscardRectangles;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineDiscardRectangleStateCreateInfoEXT vkfPipelineDiscardRectangleStateCreateInfoEXT(VkDiscardRectangleModeEXT discardRectangleMode, uint32_t discardRectangleCount, const VkRect2D *pDiscardRectangles)
       {
              VkPipelineDiscardRectangleStateCreateInfoEXT struct_to_fill;
              struct_to_fill.discardRectangleMode = discardRectangleMode;
              struct_to_fill.discardRectangleCount = discardRectangleCount;
              struct_to_fill.pDiscardRectangles = pDiscardRectangles;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_discard_rectangles
#ifdef VK_EXT_conservative_rasterization
       static inline VkPhysicalDeviceConservativeRasterizationPropertiesEXT vkfPhysicalDeviceConservativeRasterizationPropertiesEXT(float primitiveOverestimationSize, float maxExtraPrimitiveOverestimationSize, float extraPrimitiveOverestimationSizeGranularity, VkBool32 primitiveUnderestimation, VkBool32 conservativePointAndLineRasterization, VkBool32 degenerateTrianglesRasterized, VkBool32 degenerateLinesRasterized, VkBool32 fullyCoveredFragmentShaderInputVariable, VkBool32 conservativeRasterizationPostDepthCoverage)
       {
              VkPhysicalDeviceConservativeRasterizationPropertiesEXT struct_to_fill;
              struct_to_fill.primitiveOverestimationSize = primitiveOverestimationSize;
              struct_to_fill.maxExtraPrimitiveOverestimationSize = maxExtraPrimitiveOverestimationSize;
              struct_to_fill.extraPrimitiveOverestimationSizeGranularity = extraPrimitiveOverestimationSizeGranularity;
              struct_to_fill.primitiveUnderestimation = primitiveUnderestimation;
              struct_to_fill.conservativePointAndLineRasterization = conservativePointAndLineRasterization;
              struct_to_fill.degenerateTrianglesRasterized = degenerateTrianglesRasterized;
              struct_to_fill.degenerateLinesRasterized = degenerateLinesRasterized;
              struct_to_fill.fullyCoveredFragmentShaderInputVariable = fullyCoveredFragmentShaderInputVariable;
              struct_to_fill.conservativeRasterizationPostDepthCoverage = conservativeRasterizationPostDepthCoverage;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineRasterizationConservativeStateCreateInfoEXT vkfPipelineRasterizationConservativeStateCreateInfoEXT(VkConservativeRasterizationModeEXT conservativeRasterizationMode, float extraPrimitiveOverestimationSize)
       {
              VkPipelineRasterizationConservativeStateCreateInfoEXT struct_to_fill;
              struct_to_fill.conservativeRasterizationMode = conservativeRasterizationMode;
              struct_to_fill.extraPrimitiveOverestimationSize = extraPrimitiveOverestimationSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_conservative_rasterization
#ifdef VK_EXT_depth_clip_enable
       static inline VkPhysicalDeviceDepthClipEnableFeaturesEXT vkfPhysicalDeviceDepthClipEnableFeaturesEXT(VkBool32 depthClipEnable)
       {
              VkPhysicalDeviceDepthClipEnableFeaturesEXT struct_to_fill;
              struct_to_fill.depthClipEnable = depthClipEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineRasterizationDepthClipStateCreateInfoEXT vkfPipelineRasterizationDepthClipStateCreateInfoEXT(VkBool32 depthClipEnable)
       {
              VkPipelineRasterizationDepthClipStateCreateInfoEXT struct_to_fill;
              struct_to_fill.depthClipEnable = depthClipEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_depth_clip_enable
#ifdef VK_EXT_hdr_metadata
       static inline VkXYColorEXT vkfXYColorEXT(float x, float y)
       {
              VkXYColorEXT struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              return struct_to_fill;
       }
       static inline VkHdrMetadataEXT vkfHdrMetadataEXT(VkXYColorEXT displayPrimaryRed, VkXYColorEXT displayPrimaryGreen, VkXYColorEXT displayPrimaryBlue, VkXYColorEXT whitePoint, float maxLuminance, float minLuminance, float maxContentLightLevel, float maxFrameAverageLightLevel)
       {
              VkHdrMetadataEXT struct_to_fill;
              struct_to_fill.displayPrimaryRed = displayPrimaryRed;
              struct_to_fill.displayPrimaryGreen = displayPrimaryGreen;
              struct_to_fill.displayPrimaryBlue = displayPrimaryBlue;
              struct_to_fill.whitePoint = whitePoint;
              struct_to_fill.maxLuminance = maxLuminance;
              struct_to_fill.minLuminance = minLuminance;
              struct_to_fill.maxContentLightLevel = maxContentLightLevel;
              struct_to_fill.maxFrameAverageLightLevel = maxFrameAverageLightLevel;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_HDR_METADATA_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_hdr_metadata
#ifdef VK_EXT_debug_utils
       static inline VkDebugUtilsObjectNameInfoEXT vkfDebugUtilsObjectNameInfoEXT(VkObjectType objectType, uint64_t objectHandle, const char *pObjectName)
       {
              VkDebugUtilsObjectNameInfoEXT struct_to_fill;
              struct_to_fill.objectType = objectType;
              struct_to_fill.objectHandle = objectHandle;
              struct_to_fill.pObjectName = pObjectName;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDebugUtilsObjectTagInfoEXT vkfDebugUtilsObjectTagInfoEXT(VkObjectType objectType, uint64_t objectHandle, uint64_t tagName, size_t tagSize, const void *pTag)
       {
              VkDebugUtilsObjectTagInfoEXT struct_to_fill;
              struct_to_fill.objectType = objectType;
              struct_to_fill.objectHandle = objectHandle;
              struct_to_fill.tagName = tagName;
              struct_to_fill.tagSize = tagSize;
              struct_to_fill.pTag = pTag;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDebugUtilsLabelEXT vkfDebugUtilsLabelEXT(const char *pLabelName)
       {
              VkDebugUtilsLabelEXT struct_to_fill;
              struct_to_fill.pLabelName = pLabelName;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDebugUtilsMessengerCallbackDataEXT vkfDebugUtilsMessengerCallbackDataEXT(const char *pMessageIdName, int32_t messageIdNumber, const char *pMessage, uint32_t queueLabelCount, const VkDebugUtilsLabelEXT *pQueueLabels, uint32_t cmdBufLabelCount, const VkDebugUtilsLabelEXT *pCmdBufLabels, uint32_t objectCount, const VkDebugUtilsObjectNameInfoEXT *pObjects)
       {
              VkDebugUtilsMessengerCallbackDataEXT struct_to_fill;
              struct_to_fill.pMessageIdName = pMessageIdName;
              struct_to_fill.messageIdNumber = messageIdNumber;
              struct_to_fill.pMessage = pMessage;
              struct_to_fill.queueLabelCount = queueLabelCount;
              struct_to_fill.pQueueLabels = pQueueLabels;
              struct_to_fill.cmdBufLabelCount = cmdBufLabelCount;
              struct_to_fill.pCmdBufLabels = pCmdBufLabels;
              struct_to_fill.objectCount = objectCount;
              struct_to_fill.pObjects = pObjects;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkDebugUtilsMessengerCreateInfoEXT vkfDebugUtilsMessengerCreateInfoEXT(VkDebugUtilsMessageSeverityFlagsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, PFN_vkDebugUtilsMessengerCallbackEXT pfnUserCallback, void *pUserData)
       {
              VkDebugUtilsMessengerCreateInfoEXT struct_to_fill;
              struct_to_fill.messageSeverity = messageSeverity;
              struct_to_fill.messageType = messageType;
              struct_to_fill.pfnUserCallback = pfnUserCallback;
              struct_to_fill.pUserData = pUserData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_debug_utils
#ifdef VK_EXT_inline_uniform_block
       static inline VkPhysicalDeviceInlineUniformBlockFeaturesEXT vkfPhysicalDeviceInlineUniformBlockFeaturesEXT(VkBool32 inlineUniformBlock, VkBool32 descriptorBindingInlineUniformBlockUpdateAfterBind)
       {
              VkPhysicalDeviceInlineUniformBlockFeaturesEXT struct_to_fill;
              struct_to_fill.inlineUniformBlock = inlineUniformBlock;
              struct_to_fill.descriptorBindingInlineUniformBlockUpdateAfterBind = descriptorBindingInlineUniformBlockUpdateAfterBind;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceInlineUniformBlockPropertiesEXT vkfPhysicalDeviceInlineUniformBlockPropertiesEXT(uint32_t maxInlineUniformBlockSize, uint32_t maxPerStageDescriptorInlineUniformBlocks, uint32_t maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, uint32_t maxDescriptorSetInlineUniformBlocks, uint32_t maxDescriptorSetUpdateAfterBindInlineUniformBlocks)
       {
              VkPhysicalDeviceInlineUniformBlockPropertiesEXT struct_to_fill;
              struct_to_fill.maxInlineUniformBlockSize = maxInlineUniformBlockSize;
              struct_to_fill.maxPerStageDescriptorInlineUniformBlocks = maxPerStageDescriptorInlineUniformBlocks;
              struct_to_fill.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks;
              struct_to_fill.maxDescriptorSetInlineUniformBlocks = maxDescriptorSetInlineUniformBlocks;
              struct_to_fill.maxDescriptorSetUpdateAfterBindInlineUniformBlocks = maxDescriptorSetUpdateAfterBindInlineUniformBlocks;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkWriteDescriptorSetInlineUniformBlockEXT vkfWriteDescriptorSetInlineUniformBlockEXT(uint32_t dataSize, const void *pData)
       {
              VkWriteDescriptorSetInlineUniformBlockEXT struct_to_fill;
              struct_to_fill.dataSize = dataSize;
              struct_to_fill.pData = pData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDescriptorPoolInlineUniformBlockCreateInfoEXT vkfDescriptorPoolInlineUniformBlockCreateInfoEXT(uint32_t maxInlineUniformBlockBindings)
       {
              VkDescriptorPoolInlineUniformBlockCreateInfoEXT struct_to_fill;
              struct_to_fill.maxInlineUniformBlockBindings = maxInlineUniformBlockBindings;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_inline_uniform_block
#ifdef VK_EXT_sample_locations
       static inline VkSampleLocationEXT vkfSampleLocationEXT(float x, float y)
       {
              VkSampleLocationEXT struct_to_fill;
              struct_to_fill.x = x;
              struct_to_fill.y = y;
              return struct_to_fill;
       }
       static inline VkSampleLocationsInfoEXT vkfSampleLocationsInfoEXT(VkSampleCountFlagBits sampleLocationsPerPixel, VkExtent2D sampleLocationGridSize, uint32_t sampleLocationsCount, const VkSampleLocationEXT *pSampleLocations)
       {
              VkSampleLocationsInfoEXT struct_to_fill;
              struct_to_fill.sampleLocationsPerPixel = sampleLocationsPerPixel;
              struct_to_fill.sampleLocationGridSize = sampleLocationGridSize;
              struct_to_fill.sampleLocationsCount = sampleLocationsCount;
              struct_to_fill.pSampleLocations = pSampleLocations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAttachmentSampleLocationsEXT vkfAttachmentSampleLocationsEXT(uint32_t attachmentIndex, VkSampleLocationsInfoEXT sampleLocationsInfo)
       {
              VkAttachmentSampleLocationsEXT struct_to_fill;
              struct_to_fill.attachmentIndex = attachmentIndex;
              struct_to_fill.sampleLocationsInfo = sampleLocationsInfo;
              return struct_to_fill;
       }
       static inline VkSubpassSampleLocationsEXT vkfSubpassSampleLocationsEXT(uint32_t subpassIndex, VkSampleLocationsInfoEXT sampleLocationsInfo)
       {
              VkSubpassSampleLocationsEXT struct_to_fill;
              struct_to_fill.subpassIndex = subpassIndex;
              struct_to_fill.sampleLocationsInfo = sampleLocationsInfo;
              return struct_to_fill;
       }
       static inline VkRenderPassSampleLocationsBeginInfoEXT vkfRenderPassSampleLocationsBeginInfoEXT(uint32_t attachmentInitialSampleLocationsCount, const VkAttachmentSampleLocationsEXT *pAttachmentInitialSampleLocations, uint32_t postSubpassSampleLocationsCount, const VkSubpassSampleLocationsEXT *pPostSubpassSampleLocations)
       {
              VkRenderPassSampleLocationsBeginInfoEXT struct_to_fill;
              struct_to_fill.attachmentInitialSampleLocationsCount = attachmentInitialSampleLocationsCount;
              struct_to_fill.pAttachmentInitialSampleLocations = pAttachmentInitialSampleLocations;
              struct_to_fill.postSubpassSampleLocationsCount = postSubpassSampleLocationsCount;
              struct_to_fill.pPostSubpassSampleLocations = pPostSubpassSampleLocations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineSampleLocationsStateCreateInfoEXT vkfPipelineSampleLocationsStateCreateInfoEXT(VkBool32 sampleLocationsEnable, VkSampleLocationsInfoEXT sampleLocationsInfo)
       {
              VkPipelineSampleLocationsStateCreateInfoEXT struct_to_fill;
              struct_to_fill.sampleLocationsEnable = sampleLocationsEnable;
              struct_to_fill.sampleLocationsInfo = sampleLocationsInfo;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSampleLocationsPropertiesEXT vkfPhysicalDeviceSampleLocationsPropertiesEXT(VkSampleCountFlags sampleLocationSampleCounts, VkExtent2D maxSampleLocationGridSize, uint32_t sampleLocationSubPixelBits, VkBool32 variableSampleLocations)
       {
              VkPhysicalDeviceSampleLocationsPropertiesEXT struct_to_fill;
              struct_to_fill.sampleLocationSampleCounts = sampleLocationSampleCounts;
              struct_to_fill.maxSampleLocationGridSize = maxSampleLocationGridSize;
              struct_to_fill.sampleLocationSubPixelBits = sampleLocationSubPixelBits;
              struct_to_fill.variableSampleLocations = variableSampleLocations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMultisamplePropertiesEXT vkfMultisamplePropertiesEXT(VkExtent2D maxSampleLocationGridSize)
       {
              VkMultisamplePropertiesEXT struct_to_fill;
              struct_to_fill.maxSampleLocationGridSize = maxSampleLocationGridSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_sample_locations
#ifdef VK_EXT_blend_operation_advanced
       static inline VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT vkfPhysicalDeviceBlendOperationAdvancedFeaturesEXT(VkBool32 advancedBlendCoherentOperations)
       {
              VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT struct_to_fill;
              struct_to_fill.advancedBlendCoherentOperations = advancedBlendCoherentOperations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT vkfPhysicalDeviceBlendOperationAdvancedPropertiesEXT(uint32_t advancedBlendMaxColorAttachments, VkBool32 advancedBlendIndependentBlend, VkBool32 advancedBlendNonPremultipliedSrcColor, VkBool32 advancedBlendNonPremultipliedDstColor, VkBool32 advancedBlendCorrelatedOverlap, VkBool32 advancedBlendAllOperations)
       {
              VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT struct_to_fill;
              struct_to_fill.advancedBlendMaxColorAttachments = advancedBlendMaxColorAttachments;
              struct_to_fill.advancedBlendIndependentBlend = advancedBlendIndependentBlend;
              struct_to_fill.advancedBlendNonPremultipliedSrcColor = advancedBlendNonPremultipliedSrcColor;
              struct_to_fill.advancedBlendNonPremultipliedDstColor = advancedBlendNonPremultipliedDstColor;
              struct_to_fill.advancedBlendCorrelatedOverlap = advancedBlendCorrelatedOverlap;
              struct_to_fill.advancedBlendAllOperations = advancedBlendAllOperations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineColorBlendAdvancedStateCreateInfoEXT vkfPipelineColorBlendAdvancedStateCreateInfoEXT(VkBool32 srcPremultiplied, VkBool32 dstPremultiplied, VkBlendOverlapEXT blendOverlap)
       {
              VkPipelineColorBlendAdvancedStateCreateInfoEXT struct_to_fill;
              struct_to_fill.srcPremultiplied = srcPremultiplied;
              struct_to_fill.dstPremultiplied = dstPremultiplied;
              struct_to_fill.blendOverlap = blendOverlap;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_blend_operation_advanced
#ifdef VK_NV_fragment_coverage_to_color
       static inline VkPipelineCoverageToColorStateCreateInfoNV vkfPipelineCoverageToColorStateCreateInfoNV(VkBool32 coverageToColorEnable, uint32_t coverageToColorLocation)
       {
              VkPipelineCoverageToColorStateCreateInfoNV struct_to_fill;
              struct_to_fill.coverageToColorEnable = coverageToColorEnable;
              struct_to_fill.coverageToColorLocation = coverageToColorLocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_NV_fragment_coverage_to_color
#ifdef VK_NV_framebuffer_mixed_samples
       static inline VkPipelineCoverageModulationStateCreateInfoNV vkfPipelineCoverageModulationStateCreateInfoNV(VkCoverageModulationModeNV coverageModulationMode, VkBool32 coverageModulationTableEnable, uint32_t coverageModulationTableCount, const float *pCoverageModulationTable)
       {
              VkPipelineCoverageModulationStateCreateInfoNV struct_to_fill;
              struct_to_fill.coverageModulationMode = coverageModulationMode;
              struct_to_fill.coverageModulationTableEnable = coverageModulationTableEnable;
              struct_to_fill.coverageModulationTableCount = coverageModulationTableCount;
              struct_to_fill.pCoverageModulationTable = pCoverageModulationTable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_NV_framebuffer_mixed_samples
#ifdef VK_NV_shader_sm_builtins
       static inline VkPhysicalDeviceShaderSMBuiltinsPropertiesNV vkfPhysicalDeviceShaderSMBuiltinsPropertiesNV(uint32_t shaderSMCount, uint32_t shaderWarpsPerSM)
       {
              VkPhysicalDeviceShaderSMBuiltinsPropertiesNV struct_to_fill;
              struct_to_fill.shaderSMCount = shaderSMCount;
              struct_to_fill.shaderWarpsPerSM = shaderWarpsPerSM;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShaderSMBuiltinsFeaturesNV vkfPhysicalDeviceShaderSMBuiltinsFeaturesNV(VkBool32 shaderSMBuiltins)
       {
              VkPhysicalDeviceShaderSMBuiltinsFeaturesNV struct_to_fill;
              struct_to_fill.shaderSMBuiltins = shaderSMBuiltins;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_shader_sm_builtins
#ifdef VK_EXT_image_drm_format_modifier
       static inline VkDrmFormatModifierPropertiesEXT vkfDrmFormatModifierPropertiesEXT(uint64_t drmFormatModifier, uint32_t drmFormatModifierPlaneCount, VkFormatFeatureFlags drmFormatModifierTilingFeatures)
       {
              VkDrmFormatModifierPropertiesEXT struct_to_fill;
              struct_to_fill.drmFormatModifier = drmFormatModifier;
              struct_to_fill.drmFormatModifierPlaneCount = drmFormatModifierPlaneCount;
              struct_to_fill.drmFormatModifierTilingFeatures = drmFormatModifierTilingFeatures;
              return struct_to_fill;
       }
       static inline VkDrmFormatModifierPropertiesListEXT vkfDrmFormatModifierPropertiesListEXT(uint32_t drmFormatModifierCount, VkDrmFormatModifierPropertiesEXT *pDrmFormatModifierProperties)
       {
              VkDrmFormatModifierPropertiesListEXT struct_to_fill;
              struct_to_fill.drmFormatModifierCount = drmFormatModifierCount;
              struct_to_fill.pDrmFormatModifierProperties = pDrmFormatModifierProperties;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceImageDrmFormatModifierInfoEXT vkfPhysicalDeviceImageDrmFormatModifierInfoEXT(uint64_t drmFormatModifier, VkSharingMode sharingMode, uint32_t queueFamilyIndexCount, const uint32_t *pQueueFamilyIndices)
       {
              VkPhysicalDeviceImageDrmFormatModifierInfoEXT struct_to_fill;
              struct_to_fill.drmFormatModifier = drmFormatModifier;
              struct_to_fill.sharingMode = sharingMode;
              struct_to_fill.queueFamilyIndexCount = queueFamilyIndexCount;
              struct_to_fill.pQueueFamilyIndices = pQueueFamilyIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageDrmFormatModifierListCreateInfoEXT vkfImageDrmFormatModifierListCreateInfoEXT(uint32_t drmFormatModifierCount, const uint64_t *pDrmFormatModifiers)
       {
              VkImageDrmFormatModifierListCreateInfoEXT struct_to_fill;
              struct_to_fill.drmFormatModifierCount = drmFormatModifierCount;
              struct_to_fill.pDrmFormatModifiers = pDrmFormatModifiers;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageDrmFormatModifierExplicitCreateInfoEXT vkfImageDrmFormatModifierExplicitCreateInfoEXT(uint64_t drmFormatModifier, uint32_t drmFormatModifierPlaneCount, const VkSubresourceLayout *pPlaneLayouts)
       {
              VkImageDrmFormatModifierExplicitCreateInfoEXT struct_to_fill;
              struct_to_fill.drmFormatModifier = drmFormatModifier;
              struct_to_fill.drmFormatModifierPlaneCount = drmFormatModifierPlaneCount;
              struct_to_fill.pPlaneLayouts = pPlaneLayouts;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkImageDrmFormatModifierPropertiesEXT vkfImageDrmFormatModifierPropertiesEXT(uint64_t drmFormatModifier)
       {
              VkImageDrmFormatModifierPropertiesEXT struct_to_fill;
              struct_to_fill.drmFormatModifier = drmFormatModifier;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_image_drm_format_modifier
#ifdef VK_EXT_validation_cache
       static inline VkValidationCacheCreateInfoEXT vkfValidationCacheCreateInfoEXT(size_t initialDataSize, const void *pInitialData)
       {
              VkValidationCacheCreateInfoEXT struct_to_fill;
              struct_to_fill.initialDataSize = initialDataSize;
              struct_to_fill.pInitialData = pInitialData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkShaderModuleValidationCacheCreateInfoEXT vkfShaderModuleValidationCacheCreateInfoEXT(VkValidationCacheEXT validationCache)
       {
              VkShaderModuleValidationCacheCreateInfoEXT struct_to_fill;
              struct_to_fill.validationCache = validationCache;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_validation_cache
#ifdef VK_NV_shading_rate_image
       static inline VkShadingRatePaletteNV vkfShadingRatePaletteNV(uint32_t shadingRatePaletteEntryCount, const VkShadingRatePaletteEntryNV *pShadingRatePaletteEntries)
       {
              VkShadingRatePaletteNV struct_to_fill;
              struct_to_fill.shadingRatePaletteEntryCount = shadingRatePaletteEntryCount;
              struct_to_fill.pShadingRatePaletteEntries = pShadingRatePaletteEntries;
              return struct_to_fill;
       }
       static inline VkPipelineViewportShadingRateImageStateCreateInfoNV vkfPipelineViewportShadingRateImageStateCreateInfoNV(VkBool32 shadingRateImageEnable, uint32_t viewportCount, const VkShadingRatePaletteNV *pShadingRatePalettes)
       {
              VkPipelineViewportShadingRateImageStateCreateInfoNV struct_to_fill;
              struct_to_fill.shadingRateImageEnable = shadingRateImageEnable;
              struct_to_fill.viewportCount = viewportCount;
              struct_to_fill.pShadingRatePalettes = pShadingRatePalettes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShadingRateImageFeaturesNV vkfPhysicalDeviceShadingRateImageFeaturesNV(VkBool32 shadingRateImage, VkBool32 shadingRateCoarseSampleOrder)
       {
              VkPhysicalDeviceShadingRateImageFeaturesNV struct_to_fill;
              struct_to_fill.shadingRateImage = shadingRateImage;
              struct_to_fill.shadingRateCoarseSampleOrder = shadingRateCoarseSampleOrder;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceShadingRateImagePropertiesNV vkfPhysicalDeviceShadingRateImagePropertiesNV(VkExtent2D shadingRateTexelSize, uint32_t shadingRatePaletteSize, uint32_t shadingRateMaxCoarseSamples)
       {
              VkPhysicalDeviceShadingRateImagePropertiesNV struct_to_fill;
              struct_to_fill.shadingRateTexelSize = shadingRateTexelSize;
              struct_to_fill.shadingRatePaletteSize = shadingRatePaletteSize;
              struct_to_fill.shadingRateMaxCoarseSamples = shadingRateMaxCoarseSamples;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCoarseSampleLocationNV vkfCoarseSampleLocationNV(uint32_t pixelX, uint32_t pixelY, uint32_t sample)
       {
              VkCoarseSampleLocationNV struct_to_fill;
              struct_to_fill.pixelX = pixelX;
              struct_to_fill.pixelY = pixelY;
              struct_to_fill.sample = sample;
              return struct_to_fill;
       }
       static inline VkCoarseSampleOrderCustomNV vkfCoarseSampleOrderCustomNV(VkShadingRatePaletteEntryNV shadingRate, uint32_t sampleCount, uint32_t sampleLocationCount, const VkCoarseSampleLocationNV *pSampleLocations)
       {
              VkCoarseSampleOrderCustomNV struct_to_fill;
              struct_to_fill.shadingRate = shadingRate;
              struct_to_fill.sampleCount = sampleCount;
              struct_to_fill.sampleLocationCount = sampleLocationCount;
              struct_to_fill.pSampleLocations = pSampleLocations;
              return struct_to_fill;
       }
       static inline VkPipelineViewportCoarseSampleOrderStateCreateInfoNV vkfPipelineViewportCoarseSampleOrderStateCreateInfoNV(VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV *pCustomSampleOrders)
       {
              VkPipelineViewportCoarseSampleOrderStateCreateInfoNV struct_to_fill;
              struct_to_fill.sampleOrderType = sampleOrderType;
              struct_to_fill.customSampleOrderCount = customSampleOrderCount;
              struct_to_fill.pCustomSampleOrders = pCustomSampleOrders;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_shading_rate_image
#ifdef VK_NV_ray_tracing
       static inline VkRayTracingShaderGroupCreateInfoNV vkfRayTracingShaderGroupCreateInfoNV(VkRayTracingShaderGroupTypeKHR type, uint32_t generalShader, uint32_t closestHitShader, uint32_t anyHitShader, uint32_t intersectionShader)
       {
              VkRayTracingShaderGroupCreateInfoNV struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.generalShader = generalShader;
              struct_to_fill.closestHitShader = closestHitShader;
              struct_to_fill.anyHitShader = anyHitShader;
              struct_to_fill.intersectionShader = intersectionShader;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRayTracingPipelineCreateInfoNV vkfRayTracingPipelineCreateInfoNV(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, uint32_t groupCount, const VkRayTracingShaderGroupCreateInfoNV *pGroups, uint32_t maxRecursionDepth, VkPipelineLayout layout, VkPipeline basePipelineHandle, int32_t basePipelineIndex)
       {
              VkRayTracingPipelineCreateInfoNV struct_to_fill;
              struct_to_fill.stageCount = stageCount;
              struct_to_fill.pStages = pStages;
              struct_to_fill.groupCount = groupCount;
              struct_to_fill.pGroups = pGroups;
              struct_to_fill.maxRecursionDepth = maxRecursionDepth;
              struct_to_fill.layout = layout;
              struct_to_fill.basePipelineHandle = basePipelineHandle;
              struct_to_fill.basePipelineIndex = basePipelineIndex;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkGeometryTrianglesNV vkfGeometryTrianglesNV(VkBuffer vertexData, VkDeviceSize vertexOffset, uint32_t vertexCount, VkDeviceSize vertexStride, VkFormat vertexFormat, VkBuffer indexData, VkDeviceSize indexOffset, uint32_t indexCount, VkIndexType indexType, VkBuffer transformData, VkDeviceSize transformOffset)
       {
              VkGeometryTrianglesNV struct_to_fill;
              struct_to_fill.vertexData = vertexData;
              struct_to_fill.vertexOffset = vertexOffset;
              struct_to_fill.vertexCount = vertexCount;
              struct_to_fill.vertexStride = vertexStride;
              struct_to_fill.vertexFormat = vertexFormat;
              struct_to_fill.indexData = indexData;
              struct_to_fill.indexOffset = indexOffset;
              struct_to_fill.indexCount = indexCount;
              struct_to_fill.indexType = indexType;
              struct_to_fill.transformData = transformData;
              struct_to_fill.transformOffset = transformOffset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkGeometryAABBNV vkfGeometryAABBNV(VkBuffer aabbData, uint32_t numAABBs, uint32_t stride, VkDeviceSize offset)
       {
              VkGeometryAABBNV struct_to_fill;
              struct_to_fill.aabbData = aabbData;
              struct_to_fill.numAABBs = numAABBs;
              struct_to_fill.stride = stride;
              struct_to_fill.offset = offset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkGeometryDataNV vkfGeometryDataNV(VkGeometryTrianglesNV triangles, VkGeometryAABBNV aabbs)
       {
              VkGeometryDataNV struct_to_fill;
              struct_to_fill.triangles = triangles;
              struct_to_fill.aabbs = aabbs;
              return struct_to_fill;
       }
       static inline VkGeometryNV vkfGeometryNV(VkGeometryTypeKHR geometryType, VkGeometryDataNV geometry)
       {
              VkGeometryNV struct_to_fill;
              struct_to_fill.geometryType = geometryType;
              struct_to_fill.geometry = geometry;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GEOMETRY_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAccelerationStructureInfoNV vkfAccelerationStructureInfoNV(VkAccelerationStructureTypeNV type, uint32_t instanceCount, uint32_t geometryCount, const VkGeometryNV *pGeometries)
       {
              VkAccelerationStructureInfoNV struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.instanceCount = instanceCount;
              struct_to_fill.geometryCount = geometryCount;
              struct_to_fill.pGeometries = pGeometries;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkAccelerationStructureCreateInfoNV vkfAccelerationStructureCreateInfoNV(VkDeviceSize compactedSize, VkAccelerationStructureInfoNV info)
       {
              VkAccelerationStructureCreateInfoNV struct_to_fill;
              struct_to_fill.compactedSize = compactedSize;
              struct_to_fill.info = info;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindAccelerationStructureMemoryInfoKHR vkfBindAccelerationStructureMemoryInfoKHR(VkAccelerationStructureKHR accelerationStructure, VkDeviceMemory memory, VkDeviceSize memoryOffset, uint32_t deviceIndexCount, const uint32_t *pDeviceIndices)
       {
              VkBindAccelerationStructureMemoryInfoKHR struct_to_fill;
              struct_to_fill.accelerationStructure = accelerationStructure;
              struct_to_fill.memory = memory;
              struct_to_fill.memoryOffset = memoryOffset;
              struct_to_fill.deviceIndexCount = deviceIndexCount;
              struct_to_fill.pDeviceIndices = pDeviceIndices;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkWriteDescriptorSetAccelerationStructureKHR vkfWriteDescriptorSetAccelerationStructureKHR(uint32_t accelerationStructureCount, const VkAccelerationStructureKHR *pAccelerationStructures)
       {
              VkWriteDescriptorSetAccelerationStructureKHR struct_to_fill;
              struct_to_fill.accelerationStructureCount = accelerationStructureCount;
              struct_to_fill.pAccelerationStructures = pAccelerationStructures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkAccelerationStructureMemoryRequirementsInfoNV vkfAccelerationStructureMemoryRequirementsInfoNV(VkAccelerationStructureMemoryRequirementsTypeNV type, VkAccelerationStructureNV accelerationStructure)
       {
              VkAccelerationStructureMemoryRequirementsInfoNV struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.accelerationStructure = accelerationStructure;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceRayTracingPropertiesNV vkfPhysicalDeviceRayTracingPropertiesNV(uint32_t shaderGroupHandleSize, uint32_t maxRecursionDepth, uint32_t maxShaderGroupStride, uint32_t shaderGroupBaseAlignment, uint64_t maxGeometryCount, uint64_t maxInstanceCount, uint64_t maxTriangleCount, uint32_t maxDescriptorSetAccelerationStructures)
       {
              VkPhysicalDeviceRayTracingPropertiesNV struct_to_fill;
              struct_to_fill.shaderGroupHandleSize = shaderGroupHandleSize;
              struct_to_fill.maxRecursionDepth = maxRecursionDepth;
              struct_to_fill.maxShaderGroupStride = maxShaderGroupStride;
              struct_to_fill.shaderGroupBaseAlignment = shaderGroupBaseAlignment;
              struct_to_fill.maxGeometryCount = maxGeometryCount;
              struct_to_fill.maxInstanceCount = maxInstanceCount;
              struct_to_fill.maxTriangleCount = maxTriangleCount;
              struct_to_fill.maxDescriptorSetAccelerationStructures = maxDescriptorSetAccelerationStructures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkTransformMatrixKHR vkfTransformMatrixKHR()
       {
              VkTransformMatrixKHR struct_to_fill;
              return struct_to_fill;
       }
       static inline VkAabbPositionsKHR vkfAabbPositionsKHR(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
       {
              VkAabbPositionsKHR struct_to_fill;
              struct_to_fill.minX = minX;
              struct_to_fill.minY = minY;
              struct_to_fill.minZ = minZ;
              struct_to_fill.maxX = maxX;
              struct_to_fill.maxY = maxY;
              struct_to_fill.maxZ = maxZ;
              return struct_to_fill;
       }
       static inline VkAccelerationStructureInstanceKHR vkfAccelerationStructureInstanceKHR(VkTransformMatrixKHR transform, uint32_t instanceCustomIndex, uint32_t mask, uint32_t instanceShaderBindingTableRecordOffset, VkGeometryInstanceFlagsKHR flags, uint64_t accelerationStructureReference)
       {
              VkAccelerationStructureInstanceKHR struct_to_fill;
              struct_to_fill.transform = transform;
              struct_to_fill.instanceCustomIndex = instanceCustomIndex;
              struct_to_fill.mask = mask;
              struct_to_fill.instanceShaderBindingTableRecordOffset = instanceShaderBindingTableRecordOffset;
              struct_to_fill.flags = flags;
              struct_to_fill.accelerationStructureReference = accelerationStructureReference;
              return struct_to_fill;
       }
#endif //VK_NV_ray_tracing
#ifdef VK_NV_representative_fragment_test
       static inline VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV vkfPhysicalDeviceRepresentativeFragmentTestFeaturesNV(VkBool32 representativeFragmentTest)
       {
              VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV struct_to_fill;
              struct_to_fill.representativeFragmentTest = representativeFragmentTest;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineRepresentativeFragmentTestStateCreateInfoNV vkfPipelineRepresentativeFragmentTestStateCreateInfoNV(VkBool32 representativeFragmentTestEnable)
       {
              VkPipelineRepresentativeFragmentTestStateCreateInfoNV struct_to_fill;
              struct_to_fill.representativeFragmentTestEnable = representativeFragmentTestEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_representative_fragment_test
#ifdef VK_EXT_filter_cubic
       static inline VkPhysicalDeviceImageViewImageFormatInfoEXT vkfPhysicalDeviceImageViewImageFormatInfoEXT(VkImageViewType imageViewType)
       {
              VkPhysicalDeviceImageViewImageFormatInfoEXT struct_to_fill;
              struct_to_fill.imageViewType = imageViewType;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkFilterCubicImageViewImageFormatPropertiesEXT vkfFilterCubicImageViewImageFormatPropertiesEXT(VkBool32 filterCubic, VkBool32 filterCubicMinmax)
       {
              VkFilterCubicImageViewImageFormatPropertiesEXT struct_to_fill;
              struct_to_fill.filterCubic = filterCubic;
              struct_to_fill.filterCubicMinmax = filterCubicMinmax;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_filter_cubic
#ifdef VK_EXT_global_priority
       static inline VkDeviceQueueGlobalPriorityCreateInfoEXT vkfDeviceQueueGlobalPriorityCreateInfoEXT(VkQueueGlobalPriorityEXT globalPriority)
       {
              VkDeviceQueueGlobalPriorityCreateInfoEXT struct_to_fill;
              struct_to_fill.globalPriority = globalPriority;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_global_priority
#ifdef VK_EXT_external_memory_host
       static inline VkImportMemoryHostPointerInfoEXT vkfImportMemoryHostPointerInfoEXT(VkExternalMemoryHandleTypeFlagBits handleType, void *pHostPointer)
       {
              VkImportMemoryHostPointerInfoEXT struct_to_fill;
              struct_to_fill.handleType = handleType;
              struct_to_fill.pHostPointer = pHostPointer;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryHostPointerPropertiesEXT vkfMemoryHostPointerPropertiesEXT(uint32_t memoryTypeBits)
       {
              VkMemoryHostPointerPropertiesEXT struct_to_fill;
              struct_to_fill.memoryTypeBits = memoryTypeBits;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExternalMemoryHostPropertiesEXT vkfPhysicalDeviceExternalMemoryHostPropertiesEXT(VkDeviceSize minImportedHostPointerAlignment)
       {
              VkPhysicalDeviceExternalMemoryHostPropertiesEXT struct_to_fill;
              struct_to_fill.minImportedHostPointerAlignment = minImportedHostPointerAlignment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_external_memory_host
#ifdef VK_AMD_pipeline_compiler_control
       static inline VkPipelineCompilerControlCreateInfoAMD vkfPipelineCompilerControlCreateInfoAMD(VkPipelineCompilerControlFlagsAMD compilerControlFlags)
       {
              VkPipelineCompilerControlCreateInfoAMD struct_to_fill;
              struct_to_fill.compilerControlFlags = compilerControlFlags;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_pipeline_compiler_control
#ifdef VK_EXT_calibrated_timestamps
       static inline VkCalibratedTimestampInfoEXT vkfCalibratedTimestampInfoEXT(VkTimeDomainEXT timeDomain)
       {
              VkCalibratedTimestampInfoEXT struct_to_fill;
              struct_to_fill.timeDomain = timeDomain;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_calibrated_timestamps
#ifdef VK_AMD_shader_core_properties
       static inline VkPhysicalDeviceShaderCorePropertiesAMD vkfPhysicalDeviceShaderCorePropertiesAMD(uint32_t shaderEngineCount, uint32_t shaderArraysPerEngineCount, uint32_t computeUnitsPerShaderArray, uint32_t simdPerComputeUnit, uint32_t wavefrontsPerSimd, uint32_t wavefrontSize, uint32_t sgprsPerSimd, uint32_t minSgprAllocation, uint32_t maxSgprAllocation, uint32_t sgprAllocationGranularity, uint32_t vgprsPerSimd, uint32_t minVgprAllocation, uint32_t maxVgprAllocation, uint32_t vgprAllocationGranularity)
       {
              VkPhysicalDeviceShaderCorePropertiesAMD struct_to_fill;
              struct_to_fill.shaderEngineCount = shaderEngineCount;
              struct_to_fill.shaderArraysPerEngineCount = shaderArraysPerEngineCount;
              struct_to_fill.computeUnitsPerShaderArray = computeUnitsPerShaderArray;
              struct_to_fill.simdPerComputeUnit = simdPerComputeUnit;
              struct_to_fill.wavefrontsPerSimd = wavefrontsPerSimd;
              struct_to_fill.wavefrontSize = wavefrontSize;
              struct_to_fill.sgprsPerSimd = sgprsPerSimd;
              struct_to_fill.minSgprAllocation = minSgprAllocation;
              struct_to_fill.maxSgprAllocation = maxSgprAllocation;
              struct_to_fill.sgprAllocationGranularity = sgprAllocationGranularity;
              struct_to_fill.vgprsPerSimd = vgprsPerSimd;
              struct_to_fill.minVgprAllocation = minVgprAllocation;
              struct_to_fill.maxVgprAllocation = maxVgprAllocation;
              struct_to_fill.vgprAllocationGranularity = vgprAllocationGranularity;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_shader_core_properties
#ifdef VK_AMD_memory_overallocation_behavior
       static inline VkDeviceMemoryOverallocationCreateInfoAMD vkfDeviceMemoryOverallocationCreateInfoAMD(VkMemoryOverallocationBehaviorAMD overallocationBehavior)
       {
              VkDeviceMemoryOverallocationCreateInfoAMD struct_to_fill;
              struct_to_fill.overallocationBehavior = overallocationBehavior;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_memory_overallocation_behavior
#ifdef VK_EXT_vertex_attribute_divisor
       static inline VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT vkfPhysicalDeviceVertexAttributeDivisorPropertiesEXT(uint32_t maxVertexAttribDivisor)
       {
              VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT struct_to_fill;
              struct_to_fill.maxVertexAttribDivisor = maxVertexAttribDivisor;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkVertexInputBindingDivisorDescriptionEXT vkfVertexInputBindingDivisorDescriptionEXT(uint32_t binding, uint32_t divisor)
       {
              VkVertexInputBindingDivisorDescriptionEXT struct_to_fill;
              struct_to_fill.binding = binding;
              struct_to_fill.divisor = divisor;
              return struct_to_fill;
       }
       static inline VkPipelineVertexInputDivisorStateCreateInfoEXT vkfPipelineVertexInputDivisorStateCreateInfoEXT(uint32_t vertexBindingDivisorCount, const VkVertexInputBindingDivisorDescriptionEXT *pVertexBindingDivisors)
       {
              VkPipelineVertexInputDivisorStateCreateInfoEXT struct_to_fill;
              struct_to_fill.vertexBindingDivisorCount = vertexBindingDivisorCount;
              struct_to_fill.pVertexBindingDivisors = pVertexBindingDivisors;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT vkfPhysicalDeviceVertexAttributeDivisorFeaturesEXT(VkBool32 vertexAttributeInstanceRateDivisor, VkBool32 vertexAttributeInstanceRateZeroDivisor)
       {
              VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT struct_to_fill;
              struct_to_fill.vertexAttributeInstanceRateDivisor = vertexAttributeInstanceRateDivisor;
              struct_to_fill.vertexAttributeInstanceRateZeroDivisor = vertexAttributeInstanceRateZeroDivisor;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_vertex_attribute_divisor
#ifdef VK_EXT_pipeline_creation_feedback
       static inline VkPipelineCreationFeedbackEXT vkfPipelineCreationFeedbackEXT(uint64_t duration)
       {
              VkPipelineCreationFeedbackEXT struct_to_fill;
              struct_to_fill.duration = duration;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkPipelineCreationFeedbackCreateInfoEXT vkfPipelineCreationFeedbackCreateInfoEXT(VkPipelineCreationFeedbackEXT *pPipelineCreationFeedback, uint32_t pipelineStageCreationFeedbackCount, VkPipelineCreationFeedbackEXT *pPipelineStageCreationFeedbacks)
       {
              VkPipelineCreationFeedbackCreateInfoEXT struct_to_fill;
              struct_to_fill.pPipelineCreationFeedback = pPipelineCreationFeedback;
              struct_to_fill.pipelineStageCreationFeedbackCount = pipelineStageCreationFeedbackCount;
              struct_to_fill.pPipelineStageCreationFeedbacks = pPipelineStageCreationFeedbacks;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_pipeline_creation_feedback
#ifdef VK_NV_compute_shader_derivatives
       static inline VkPhysicalDeviceComputeShaderDerivativesFeaturesNV vkfPhysicalDeviceComputeShaderDerivativesFeaturesNV(VkBool32 computeDerivativeGroupQuads, VkBool32 computeDerivativeGroupLinear)
       {
              VkPhysicalDeviceComputeShaderDerivativesFeaturesNV struct_to_fill;
              struct_to_fill.computeDerivativeGroupQuads = computeDerivativeGroupQuads;
              struct_to_fill.computeDerivativeGroupLinear = computeDerivativeGroupLinear;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_compute_shader_derivatives
#ifdef VK_NV_mesh_shader
       static inline VkPhysicalDeviceMeshShaderFeaturesNV vkfPhysicalDeviceMeshShaderFeaturesNV(VkBool32 taskShader, VkBool32 meshShader)
       {
              VkPhysicalDeviceMeshShaderFeaturesNV struct_to_fill;
              struct_to_fill.taskShader = taskShader;
              struct_to_fill.meshShader = meshShader;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceMeshShaderPropertiesNV vkfPhysicalDeviceMeshShaderPropertiesNV(uint32_t maxDrawMeshTasksCount, uint32_t maxTaskWorkGroupInvocations, uint32_t maxTaskTotalMemorySize, uint32_t maxTaskOutputCount, uint32_t maxMeshWorkGroupInvocations, uint32_t maxMeshTotalMemorySize, uint32_t maxMeshOutputVertices, uint32_t maxMeshOutputPrimitives, uint32_t maxMeshMultiviewViewCount, uint32_t meshOutputPerVertexGranularity, uint32_t meshOutputPerPrimitiveGranularity)
       {
              VkPhysicalDeviceMeshShaderPropertiesNV struct_to_fill;
              struct_to_fill.maxDrawMeshTasksCount = maxDrawMeshTasksCount;
              struct_to_fill.maxTaskWorkGroupInvocations = maxTaskWorkGroupInvocations;
              struct_to_fill.maxTaskTotalMemorySize = maxTaskTotalMemorySize;
              struct_to_fill.maxTaskOutputCount = maxTaskOutputCount;
              struct_to_fill.maxMeshWorkGroupInvocations = maxMeshWorkGroupInvocations;
              struct_to_fill.maxMeshTotalMemorySize = maxMeshTotalMemorySize;
              struct_to_fill.maxMeshOutputVertices = maxMeshOutputVertices;
              struct_to_fill.maxMeshOutputPrimitives = maxMeshOutputPrimitives;
              struct_to_fill.maxMeshMultiviewViewCount = maxMeshMultiviewViewCount;
              struct_to_fill.meshOutputPerVertexGranularity = meshOutputPerVertexGranularity;
              struct_to_fill.meshOutputPerPrimitiveGranularity = meshOutputPerPrimitiveGranularity;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDrawMeshTasksIndirectCommandNV vkfDrawMeshTasksIndirectCommandNV(uint32_t taskCount, uint32_t firstTask)
       {
              VkDrawMeshTasksIndirectCommandNV struct_to_fill;
              struct_to_fill.taskCount = taskCount;
              struct_to_fill.firstTask = firstTask;
              return struct_to_fill;
       }
#endif //VK_NV_mesh_shader
#ifdef VK_NV_fragment_shader_barycentric
       static inline VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV vkfPhysicalDeviceFragmentShaderBarycentricFeaturesNV(VkBool32 fragmentShaderBarycentric)
       {
              VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV struct_to_fill;
              struct_to_fill.fragmentShaderBarycentric = fragmentShaderBarycentric;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_fragment_shader_barycentric
#ifdef VK_NV_shader_image_footprint
       static inline VkPhysicalDeviceShaderImageFootprintFeaturesNV vkfPhysicalDeviceShaderImageFootprintFeaturesNV(VkBool32 imageFootprint)
       {
              VkPhysicalDeviceShaderImageFootprintFeaturesNV struct_to_fill;
              struct_to_fill.imageFootprint = imageFootprint;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_shader_image_footprint
#ifdef VK_NV_scissor_exclusive
       static inline VkPipelineViewportExclusiveScissorStateCreateInfoNV vkfPipelineViewportExclusiveScissorStateCreateInfoNV(uint32_t exclusiveScissorCount, const VkRect2D *pExclusiveScissors)
       {
              VkPipelineViewportExclusiveScissorStateCreateInfoNV struct_to_fill;
              struct_to_fill.exclusiveScissorCount = exclusiveScissorCount;
              struct_to_fill.pExclusiveScissors = pExclusiveScissors;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceExclusiveScissorFeaturesNV vkfPhysicalDeviceExclusiveScissorFeaturesNV(VkBool32 exclusiveScissor)
       {
              VkPhysicalDeviceExclusiveScissorFeaturesNV struct_to_fill;
              struct_to_fill.exclusiveScissor = exclusiveScissor;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_scissor_exclusive
#ifdef VK_NV_device_diagnostic_checkpoints
       static inline VkQueueFamilyCheckpointPropertiesNV vkfQueueFamilyCheckpointPropertiesNV(VkPipelineStageFlags checkpointExecutionStageMask)
       {
              VkQueueFamilyCheckpointPropertiesNV struct_to_fill;
              struct_to_fill.checkpointExecutionStageMask = checkpointExecutionStageMask;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCheckpointDataNV vkfCheckpointDataNV(VkPipelineStageFlagBits stage, void *pCheckpointMarker)
       {
              VkCheckpointDataNV struct_to_fill;
              struct_to_fill.stage = stage;
              struct_to_fill.pCheckpointMarker = pCheckpointMarker;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_device_diagnostic_checkpoints
#ifdef VK_INTEL_shader_integer_functions2
       static inline VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL vkfPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(VkBool32 shaderIntegerFunctions2)
       {
              VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL struct_to_fill;
              struct_to_fill.shaderIntegerFunctions2 = shaderIntegerFunctions2;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_INTEL_shader_integer_functions2
#ifdef VK_INTEL_performance_query
       static inline VkPerformanceValueINTEL vkfPerformanceValueINTEL(VkPerformanceValueTypeINTEL type, VkPerformanceValueDataINTEL data)
       {
              VkPerformanceValueINTEL struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.data = data;
              return struct_to_fill;
       }
       static inline VkInitializePerformanceApiInfoINTEL vkfInitializePerformanceApiInfoINTEL(void *pUserData)
       {
              VkInitializePerformanceApiInfoINTEL struct_to_fill;
              struct_to_fill.pUserData = pUserData;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkQueryPoolPerformanceQueryCreateInfoINTEL vkfQueryPoolPerformanceQueryCreateInfoINTEL(VkQueryPoolSamplingModeINTEL performanceCountersSampling)
       {
              VkQueryPoolPerformanceQueryCreateInfoINTEL struct_to_fill;
              struct_to_fill.performanceCountersSampling = performanceCountersSampling;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceMarkerInfoINTEL vkfPerformanceMarkerInfoINTEL(uint64_t marker)
       {
              VkPerformanceMarkerInfoINTEL struct_to_fill;
              struct_to_fill.marker = marker;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceStreamMarkerInfoINTEL vkfPerformanceStreamMarkerInfoINTEL(uint32_t marker)
       {
              VkPerformanceStreamMarkerInfoINTEL struct_to_fill;
              struct_to_fill.marker = marker;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceOverrideInfoINTEL vkfPerformanceOverrideInfoINTEL(VkPerformanceOverrideTypeINTEL type, VkBool32 enable, uint64_t parameter)
       {
              VkPerformanceOverrideInfoINTEL struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.enable = enable;
              struct_to_fill.parameter = parameter;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPerformanceConfigurationAcquireInfoINTEL vkfPerformanceConfigurationAcquireInfoINTEL(VkPerformanceConfigurationTypeINTEL type)
       {
              VkPerformanceConfigurationAcquireInfoINTEL struct_to_fill;
              struct_to_fill.type = type;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_INTEL_performance_query
#ifdef VK_EXT_pci_bus_info
       static inline VkPhysicalDevicePCIBusInfoPropertiesEXT vkfPhysicalDevicePCIBusInfoPropertiesEXT(uint32_t pciDomain, uint32_t pciBus, uint32_t pciDevice, uint32_t pciFunction)
       {
              VkPhysicalDevicePCIBusInfoPropertiesEXT struct_to_fill;
              struct_to_fill.pciDomain = pciDomain;
              struct_to_fill.pciBus = pciBus;
              struct_to_fill.pciDevice = pciDevice;
              struct_to_fill.pciFunction = pciFunction;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_pci_bus_info
#ifdef VK_AMD_display_native_hdr
       static inline VkDisplayNativeHdrSurfaceCapabilitiesAMD vkfDisplayNativeHdrSurfaceCapabilitiesAMD(VkBool32 localDimmingSupport)
       {
              VkDisplayNativeHdrSurfaceCapabilitiesAMD struct_to_fill;
              struct_to_fill.localDimmingSupport = localDimmingSupport;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkSwapchainDisplayNativeHdrCreateInfoAMD vkfSwapchainDisplayNativeHdrCreateInfoAMD(VkBool32 localDimmingEnable)
       {
              VkSwapchainDisplayNativeHdrCreateInfoAMD struct_to_fill;
              struct_to_fill.localDimmingEnable = localDimmingEnable;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_display_native_hdr
#ifdef VK_EXT_fragment_density_map
       static inline VkPhysicalDeviceFragmentDensityMapFeaturesEXT vkfPhysicalDeviceFragmentDensityMapFeaturesEXT(VkBool32 fragmentDensityMap, VkBool32 fragmentDensityMapDynamic, VkBool32 fragmentDensityMapNonSubsampledImages)
       {
              VkPhysicalDeviceFragmentDensityMapFeaturesEXT struct_to_fill;
              struct_to_fill.fragmentDensityMap = fragmentDensityMap;
              struct_to_fill.fragmentDensityMapDynamic = fragmentDensityMapDynamic;
              struct_to_fill.fragmentDensityMapNonSubsampledImages = fragmentDensityMapNonSubsampledImages;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceFragmentDensityMapPropertiesEXT vkfPhysicalDeviceFragmentDensityMapPropertiesEXT(VkExtent2D minFragmentDensityTexelSize, VkExtent2D maxFragmentDensityTexelSize, VkBool32 fragmentDensityInvocations)
       {
              VkPhysicalDeviceFragmentDensityMapPropertiesEXT struct_to_fill;
              struct_to_fill.minFragmentDensityTexelSize = minFragmentDensityTexelSize;
              struct_to_fill.maxFragmentDensityTexelSize = maxFragmentDensityTexelSize;
              struct_to_fill.fragmentDensityInvocations = fragmentDensityInvocations;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkRenderPassFragmentDensityMapCreateInfoEXT vkfRenderPassFragmentDensityMapCreateInfoEXT(VkAttachmentReference fragmentDensityMapAttachment)
       {
              VkRenderPassFragmentDensityMapCreateInfoEXT struct_to_fill;
              struct_to_fill.fragmentDensityMapAttachment = fragmentDensityMapAttachment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_fragment_density_map
#ifdef VK_EXT_subgroup_size_control
       static inline VkPhysicalDeviceSubgroupSizeControlFeaturesEXT vkfPhysicalDeviceSubgroupSizeControlFeaturesEXT(VkBool32 subgroupSizeControl, VkBool32 computeFullSubgroups)
       {
              VkPhysicalDeviceSubgroupSizeControlFeaturesEXT struct_to_fill;
              struct_to_fill.subgroupSizeControl = subgroupSizeControl;
              struct_to_fill.computeFullSubgroups = computeFullSubgroups;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceSubgroupSizeControlPropertiesEXT vkfPhysicalDeviceSubgroupSizeControlPropertiesEXT(uint32_t minSubgroupSize, uint32_t maxSubgroupSize, uint32_t maxComputeWorkgroupSubgroups, VkShaderStageFlags requiredSubgroupSizeStages)
       {
              VkPhysicalDeviceSubgroupSizeControlPropertiesEXT struct_to_fill;
              struct_to_fill.minSubgroupSize = minSubgroupSize;
              struct_to_fill.maxSubgroupSize = maxSubgroupSize;
              struct_to_fill.maxComputeWorkgroupSubgroups = maxComputeWorkgroupSubgroups;
              struct_to_fill.requiredSubgroupSizeStages = requiredSubgroupSizeStages;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT vkfPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT(uint32_t requiredSubgroupSize)
       {
              VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT struct_to_fill;
              struct_to_fill.requiredSubgroupSize = requiredSubgroupSize;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_subgroup_size_control
#ifdef VK_AMD_shader_core_properties2
       static inline VkPhysicalDeviceShaderCoreProperties2AMD vkfPhysicalDeviceShaderCoreProperties2AMD(VkShaderCorePropertiesFlagsAMD shaderCoreFeatures, uint32_t activeComputeUnitCount)
       {
              VkPhysicalDeviceShaderCoreProperties2AMD struct_to_fill;
              struct_to_fill.shaderCoreFeatures = shaderCoreFeatures;
              struct_to_fill.activeComputeUnitCount = activeComputeUnitCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_shader_core_properties2
#ifdef VK_AMD_device_coherent_memory
       static inline VkPhysicalDeviceCoherentMemoryFeaturesAMD vkfPhysicalDeviceCoherentMemoryFeaturesAMD(VkBool32 deviceCoherentMemory)
       {
              VkPhysicalDeviceCoherentMemoryFeaturesAMD struct_to_fill;
              struct_to_fill.deviceCoherentMemory = deviceCoherentMemory;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_AMD_device_coherent_memory
#ifdef VK_EXT_memory_budget
       static inline VkPhysicalDeviceMemoryBudgetPropertiesEXT vkfPhysicalDeviceMemoryBudgetPropertiesEXT()
       {
              VkPhysicalDeviceMemoryBudgetPropertiesEXT struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_memory_budget
#ifdef VK_EXT_memory_priority
       static inline VkPhysicalDeviceMemoryPriorityFeaturesEXT vkfPhysicalDeviceMemoryPriorityFeaturesEXT(VkBool32 memoryPriority)
       {
              VkPhysicalDeviceMemoryPriorityFeaturesEXT struct_to_fill;
              struct_to_fill.memoryPriority = memoryPriority;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkMemoryPriorityAllocateInfoEXT vkfMemoryPriorityAllocateInfoEXT(float priority)
       {
              VkMemoryPriorityAllocateInfoEXT struct_to_fill;
              struct_to_fill.priority = priority;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_memory_priority
#ifdef VK_NV_dedicated_allocation_image_aliasing
       static inline VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV vkfPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(VkBool32 dedicatedAllocationImageAliasing)
       {
              VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV struct_to_fill;
              struct_to_fill.dedicatedAllocationImageAliasing = dedicatedAllocationImageAliasing;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_dedicated_allocation_image_aliasing
#ifdef VK_EXT_buffer_device_address
       static inline VkPhysicalDeviceBufferDeviceAddressFeaturesEXT vkfPhysicalDeviceBufferDeviceAddressFeaturesEXT(VkBool32 bufferDeviceAddress, VkBool32 bufferDeviceAddressCaptureReplay, VkBool32 bufferDeviceAddressMultiDevice)
       {
              VkPhysicalDeviceBufferDeviceAddressFeaturesEXT struct_to_fill;
              struct_to_fill.bufferDeviceAddress = bufferDeviceAddress;
              struct_to_fill.bufferDeviceAddressCaptureReplay = bufferDeviceAddressCaptureReplay;
              struct_to_fill.bufferDeviceAddressMultiDevice = bufferDeviceAddressMultiDevice;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBufferDeviceAddressCreateInfoEXT vkfBufferDeviceAddressCreateInfoEXT(VkDeviceAddress deviceAddress)
       {
              VkBufferDeviceAddressCreateInfoEXT struct_to_fill;
              struct_to_fill.deviceAddress = deviceAddress;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_buffer_device_address
#ifdef VK_EXT_tooling_info
       static inline VkPhysicalDeviceToolPropertiesEXT vkfPhysicalDeviceToolPropertiesEXT(VkToolPurposeFlagsEXT purposes)
       {
              VkPhysicalDeviceToolPropertiesEXT struct_to_fill;
              struct_to_fill.purposes = purposes;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_tooling_info
#ifdef VK_EXT_validation_features
       static inline VkValidationFeaturesEXT vkfValidationFeaturesEXT(uint32_t enabledValidationFeatureCount, const VkValidationFeatureEnableEXT *pEnabledValidationFeatures, uint32_t disabledValidationFeatureCount, const VkValidationFeatureDisableEXT *pDisabledValidationFeatures)
       {
              VkValidationFeaturesEXT struct_to_fill;
              struct_to_fill.enabledValidationFeatureCount = enabledValidationFeatureCount;
              struct_to_fill.pEnabledValidationFeatures = pEnabledValidationFeatures;
              struct_to_fill.disabledValidationFeatureCount = disabledValidationFeatureCount;
              struct_to_fill.pDisabledValidationFeatures = pDisabledValidationFeatures;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_validation_features
#ifdef VK_NV_cooperative_matrix
       static inline VkCooperativeMatrixPropertiesNV vkfCooperativeMatrixPropertiesNV(uint32_t MSize, uint32_t NSize, uint32_t KSize, VkComponentTypeNV AType, VkComponentTypeNV BType, VkComponentTypeNV CType, VkComponentTypeNV DType, VkScopeNV scope)
       {
              VkCooperativeMatrixPropertiesNV struct_to_fill;
              struct_to_fill.MSize = MSize;
              struct_to_fill.NSize = NSize;
              struct_to_fill.KSize = KSize;
              struct_to_fill.AType = AType;
              struct_to_fill.BType = BType;
              struct_to_fill.CType = CType;
              struct_to_fill.DType = DType;
              struct_to_fill.scope = scope;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceCooperativeMatrixFeaturesNV vkfPhysicalDeviceCooperativeMatrixFeaturesNV(VkBool32 cooperativeMatrix, VkBool32 cooperativeMatrixRobustBufferAccess)
       {
              VkPhysicalDeviceCooperativeMatrixFeaturesNV struct_to_fill;
              struct_to_fill.cooperativeMatrix = cooperativeMatrix;
              struct_to_fill.cooperativeMatrixRobustBufferAccess = cooperativeMatrixRobustBufferAccess;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceCooperativeMatrixPropertiesNV vkfPhysicalDeviceCooperativeMatrixPropertiesNV(VkShaderStageFlags cooperativeMatrixSupportedStages)
       {
              VkPhysicalDeviceCooperativeMatrixPropertiesNV struct_to_fill;
              struct_to_fill.cooperativeMatrixSupportedStages = cooperativeMatrixSupportedStages;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_cooperative_matrix
#ifdef VK_NV_coverage_reduction_mode
       static inline VkPhysicalDeviceCoverageReductionModeFeaturesNV vkfPhysicalDeviceCoverageReductionModeFeaturesNV(VkBool32 coverageReductionMode)
       {
              VkPhysicalDeviceCoverageReductionModeFeaturesNV struct_to_fill;
              struct_to_fill.coverageReductionMode = coverageReductionMode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineCoverageReductionStateCreateInfoNV vkfPipelineCoverageReductionStateCreateInfoNV(VkCoverageReductionModeNV coverageReductionMode)
       {
              VkPipelineCoverageReductionStateCreateInfoNV struct_to_fill;
              struct_to_fill.coverageReductionMode = coverageReductionMode;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkFramebufferMixedSamplesCombinationNV vkfFramebufferMixedSamplesCombinationNV(VkCoverageReductionModeNV coverageReductionMode, VkSampleCountFlagBits rasterizationSamples, VkSampleCountFlags depthStencilSamples, VkSampleCountFlags colorSamples)
       {
              VkFramebufferMixedSamplesCombinationNV struct_to_fill;
              struct_to_fill.coverageReductionMode = coverageReductionMode;
              struct_to_fill.rasterizationSamples = rasterizationSamples;
              struct_to_fill.depthStencilSamples = depthStencilSamples;
              struct_to_fill.colorSamples = colorSamples;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_coverage_reduction_mode
#ifdef VK_EXT_fragment_shader_interlock
       static inline VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT vkfPhysicalDeviceFragmentShaderInterlockFeaturesEXT(VkBool32 fragmentShaderSampleInterlock, VkBool32 fragmentShaderPixelInterlock, VkBool32 fragmentShaderShadingRateInterlock)
       {
              VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT struct_to_fill;
              struct_to_fill.fragmentShaderSampleInterlock = fragmentShaderSampleInterlock;
              struct_to_fill.fragmentShaderPixelInterlock = fragmentShaderPixelInterlock;
              struct_to_fill.fragmentShaderShadingRateInterlock = fragmentShaderShadingRateInterlock;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_fragment_shader_interlock
#ifdef VK_EXT_ycbcr_image_arrays
       static inline VkPhysicalDeviceYcbcrImageArraysFeaturesEXT vkfPhysicalDeviceYcbcrImageArraysFeaturesEXT(VkBool32 ycbcrImageArrays)
       {
              VkPhysicalDeviceYcbcrImageArraysFeaturesEXT struct_to_fill;
              struct_to_fill.ycbcrImageArrays = ycbcrImageArrays;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_ycbcr_image_arrays
#ifdef VK_EXT_headless_surface
       static inline VkHeadlessSurfaceCreateInfoEXT vkfHeadlessSurfaceCreateInfoEXT()
       {
              VkHeadlessSurfaceCreateInfoEXT struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_EXT_headless_surface
#ifdef VK_EXT_line_rasterization
       static inline VkPhysicalDeviceLineRasterizationFeaturesEXT vkfPhysicalDeviceLineRasterizationFeaturesEXT(VkBool32 rectangularLines, VkBool32 bresenhamLines, VkBool32 smoothLines, VkBool32 stippledRectangularLines, VkBool32 stippledBresenhamLines, VkBool32 stippledSmoothLines)
       {
              VkPhysicalDeviceLineRasterizationFeaturesEXT struct_to_fill;
              struct_to_fill.rectangularLines = rectangularLines;
              struct_to_fill.bresenhamLines = bresenhamLines;
              struct_to_fill.smoothLines = smoothLines;
              struct_to_fill.stippledRectangularLines = stippledRectangularLines;
              struct_to_fill.stippledBresenhamLines = stippledBresenhamLines;
              struct_to_fill.stippledSmoothLines = stippledSmoothLines;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceLineRasterizationPropertiesEXT vkfPhysicalDeviceLineRasterizationPropertiesEXT(uint32_t lineSubPixelPrecisionBits)
       {
              VkPhysicalDeviceLineRasterizationPropertiesEXT struct_to_fill;
              struct_to_fill.lineSubPixelPrecisionBits = lineSubPixelPrecisionBits;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPipelineRasterizationLineStateCreateInfoEXT vkfPipelineRasterizationLineStateCreateInfoEXT(VkLineRasterizationModeEXT lineRasterizationMode, VkBool32 stippledLineEnable, uint32_t lineStippleFactor, uint16_t lineStipplePattern)
       {
              VkPipelineRasterizationLineStateCreateInfoEXT struct_to_fill;
              struct_to_fill.lineRasterizationMode = lineRasterizationMode;
              struct_to_fill.stippledLineEnable = stippledLineEnable;
              struct_to_fill.lineStippleFactor = lineStippleFactor;
              struct_to_fill.lineStipplePattern = lineStipplePattern;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_line_rasterization
#ifdef VK_EXT_index_type_uint8
       static inline VkPhysicalDeviceIndexTypeUint8FeaturesEXT vkfPhysicalDeviceIndexTypeUint8FeaturesEXT(VkBool32 indexTypeUint8)
       {
              VkPhysicalDeviceIndexTypeUint8FeaturesEXT struct_to_fill;
              struct_to_fill.indexTypeUint8 = indexTypeUint8;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_index_type_uint8
#ifdef VK_EXT_shader_demote_to_helper_invocation
       static inline VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT vkfPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT(VkBool32 shaderDemoteToHelperInvocation)
       {
              VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT struct_to_fill;
              struct_to_fill.shaderDemoteToHelperInvocation = shaderDemoteToHelperInvocation;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_shader_demote_to_helper_invocation
#ifdef VK_NV_device_generated_commands
       static inline VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV vkfPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(uint32_t maxGraphicsShaderGroupCount, uint32_t maxIndirectSequenceCount, uint32_t maxIndirectCommandsTokenCount, uint32_t maxIndirectCommandsStreamCount, uint32_t maxIndirectCommandsTokenOffset, uint32_t maxIndirectCommandsStreamStride, uint32_t minSequencesCountBufferOffsetAlignment, uint32_t minSequencesIndexBufferOffsetAlignment, uint32_t minIndirectCommandsBufferOffsetAlignment)
       {
              VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV struct_to_fill;
              struct_to_fill.maxGraphicsShaderGroupCount = maxGraphicsShaderGroupCount;
              struct_to_fill.maxIndirectSequenceCount = maxIndirectSequenceCount;
              struct_to_fill.maxIndirectCommandsTokenCount = maxIndirectCommandsTokenCount;
              struct_to_fill.maxIndirectCommandsStreamCount = maxIndirectCommandsStreamCount;
              struct_to_fill.maxIndirectCommandsTokenOffset = maxIndirectCommandsTokenOffset;
              struct_to_fill.maxIndirectCommandsStreamStride = maxIndirectCommandsStreamStride;
              struct_to_fill.minSequencesCountBufferOffsetAlignment = minSequencesCountBufferOffsetAlignment;
              struct_to_fill.minSequencesIndexBufferOffsetAlignment = minSequencesIndexBufferOffsetAlignment;
              struct_to_fill.minIndirectCommandsBufferOffsetAlignment = minIndirectCommandsBufferOffsetAlignment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV vkfPhysicalDeviceDeviceGeneratedCommandsFeaturesNV(VkBool32 deviceGeneratedCommands)
       {
              VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV struct_to_fill;
              struct_to_fill.deviceGeneratedCommands = deviceGeneratedCommands;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkGraphicsShaderGroupCreateInfoNV vkfGraphicsShaderGroupCreateInfoNV(uint32_t stageCount, const VkPipelineShaderStageCreateInfo *pStages, const VkPipelineVertexInputStateCreateInfo *pVertexInputState, const VkPipelineTessellationStateCreateInfo *pTessellationState)
       {
              VkGraphicsShaderGroupCreateInfoNV struct_to_fill;
              struct_to_fill.stageCount = stageCount;
              struct_to_fill.pStages = pStages;
              struct_to_fill.pVertexInputState = pVertexInputState;
              struct_to_fill.pTessellationState = pTessellationState;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkGraphicsPipelineShaderGroupsCreateInfoNV vkfGraphicsPipelineShaderGroupsCreateInfoNV(uint32_t groupCount, const VkGraphicsShaderGroupCreateInfoNV *pGroups, uint32_t pipelineCount, const VkPipeline *pPipelines)
       {
              VkGraphicsPipelineShaderGroupsCreateInfoNV struct_to_fill;
              struct_to_fill.groupCount = groupCount;
              struct_to_fill.pGroups = pGroups;
              struct_to_fill.pipelineCount = pipelineCount;
              struct_to_fill.pPipelines = pPipelines;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkBindShaderGroupIndirectCommandNV vkfBindShaderGroupIndirectCommandNV(uint32_t groupIndex)
       {
              VkBindShaderGroupIndirectCommandNV struct_to_fill;
              struct_to_fill.groupIndex = groupIndex;
              return struct_to_fill;
       }
       static inline VkBindIndexBufferIndirectCommandNV vkfBindIndexBufferIndirectCommandNV(VkDeviceAddress bufferAddress, uint32_t size, VkIndexType indexType)
       {
              VkBindIndexBufferIndirectCommandNV struct_to_fill;
              struct_to_fill.bufferAddress = bufferAddress;
              struct_to_fill.size = size;
              struct_to_fill.indexType = indexType;
              return struct_to_fill;
       }
       static inline VkBindVertexBufferIndirectCommandNV vkfBindVertexBufferIndirectCommandNV(VkDeviceAddress bufferAddress, uint32_t size, uint32_t stride)
       {
              VkBindVertexBufferIndirectCommandNV struct_to_fill;
              struct_to_fill.bufferAddress = bufferAddress;
              struct_to_fill.size = size;
              struct_to_fill.stride = stride;
              return struct_to_fill;
       }
       static inline VkSetStateFlagsIndirectCommandNV vkfSetStateFlagsIndirectCommandNV(uint32_t data)
       {
              VkSetStateFlagsIndirectCommandNV struct_to_fill;
              struct_to_fill.data = data;
              return struct_to_fill;
       }
       static inline VkIndirectCommandsStreamNV vkfIndirectCommandsStreamNV(VkBuffer buffer, VkDeviceSize offset)
       {
              VkIndirectCommandsStreamNV struct_to_fill;
              struct_to_fill.buffer = buffer;
              struct_to_fill.offset = offset;
              return struct_to_fill;
       }
       static inline VkIndirectCommandsLayoutTokenNV vkfIndirectCommandsLayoutTokenNV(VkIndirectCommandsTokenTypeNV tokenType, uint32_t stream, uint32_t offset, uint32_t vertexBindingUnit, VkBool32 vertexDynamicStride, VkPipelineLayout pushconstantPipelineLayout, VkShaderStageFlags pushconstantShaderStageFlags, uint32_t pushconstantOffset, uint32_t pushconstantSize, VkIndirectStateFlagsNV indirectStateFlags, uint32_t indexTypeCount, const VkIndexType *pIndexTypes, const uint32_t *pIndexTypeValues)
       {
              VkIndirectCommandsLayoutTokenNV struct_to_fill;
              struct_to_fill.tokenType = tokenType;
              struct_to_fill.stream = stream;
              struct_to_fill.offset = offset;
              struct_to_fill.vertexBindingUnit = vertexBindingUnit;
              struct_to_fill.vertexDynamicStride = vertexDynamicStride;
              struct_to_fill.pushconstantPipelineLayout = pushconstantPipelineLayout;
              struct_to_fill.pushconstantShaderStageFlags = pushconstantShaderStageFlags;
              struct_to_fill.pushconstantOffset = pushconstantOffset;
              struct_to_fill.pushconstantSize = pushconstantSize;
              struct_to_fill.indirectStateFlags = indirectStateFlags;
              struct_to_fill.indexTypeCount = indexTypeCount;
              struct_to_fill.pIndexTypes = pIndexTypes;
              struct_to_fill.pIndexTypeValues = pIndexTypeValues;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkIndirectCommandsLayoutCreateInfoNV vkfIndirectCommandsLayoutCreateInfoNV(VkPipelineBindPoint pipelineBindPoint, uint32_t tokenCount, const VkIndirectCommandsLayoutTokenNV *pTokens, uint32_t streamCount, const uint32_t *pStreamStrides)
       {
              VkIndirectCommandsLayoutCreateInfoNV struct_to_fill;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.tokenCount = tokenCount;
              struct_to_fill.pTokens = pTokens;
              struct_to_fill.streamCount = streamCount;
              struct_to_fill.pStreamStrides = pStreamStrides;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
       static inline VkGeneratedCommandsInfoNV vkfGeneratedCommandsInfoNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, VkIndirectCommandsLayoutNV indirectCommandsLayout, uint32_t streamCount, const VkIndirectCommandsStreamNV *pStreams, uint32_t sequencesCount, VkBuffer preprocessBuffer, VkDeviceSize preprocessOffset, VkDeviceSize preprocessSize, VkBuffer sequencesCountBuffer, VkDeviceSize sequencesCountOffset, VkBuffer sequencesIndexBuffer, VkDeviceSize sequencesIndexOffset)
       {
              VkGeneratedCommandsInfoNV struct_to_fill;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.pipeline = pipeline;
              struct_to_fill.indirectCommandsLayout = indirectCommandsLayout;
              struct_to_fill.streamCount = streamCount;
              struct_to_fill.pStreams = pStreams;
              struct_to_fill.sequencesCount = sequencesCount;
              struct_to_fill.preprocessBuffer = preprocessBuffer;
              struct_to_fill.preprocessOffset = preprocessOffset;
              struct_to_fill.preprocessSize = preprocessSize;
              struct_to_fill.sequencesCountBuffer = sequencesCountBuffer;
              struct_to_fill.sequencesCountOffset = sequencesCountOffset;
              struct_to_fill.sequencesIndexBuffer = sequencesIndexBuffer;
              struct_to_fill.sequencesIndexOffset = sequencesIndexOffset;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkGeneratedCommandsMemoryRequirementsInfoNV vkfGeneratedCommandsMemoryRequirementsInfoNV(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, VkIndirectCommandsLayoutNV indirectCommandsLayout, uint32_t maxSequencesCount)
       {
              VkGeneratedCommandsMemoryRequirementsInfoNV struct_to_fill;
              struct_to_fill.pipelineBindPoint = pipelineBindPoint;
              struct_to_fill.pipeline = pipeline;
              struct_to_fill.indirectCommandsLayout = indirectCommandsLayout;
              struct_to_fill.maxSequencesCount = maxSequencesCount;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_NV_device_generated_commands
#ifdef VK_EXT_texel_buffer_alignment
       static inline VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT vkfPhysicalDeviceTexelBufferAlignmentFeaturesEXT(VkBool32 texelBufferAlignment)
       {
              VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT struct_to_fill;
              struct_to_fill.texelBufferAlignment = texelBufferAlignment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT vkfPhysicalDeviceTexelBufferAlignmentPropertiesEXT(VkDeviceSize storageTexelBufferOffsetAlignmentBytes, VkBool32 storageTexelBufferOffsetSingleTexelAlignment, VkDeviceSize uniformTexelBufferOffsetAlignmentBytes, VkBool32 uniformTexelBufferOffsetSingleTexelAlignment)
       {
              VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT struct_to_fill;
              struct_to_fill.storageTexelBufferOffsetAlignmentBytes = storageTexelBufferOffsetAlignmentBytes;
              struct_to_fill.storageTexelBufferOffsetSingleTexelAlignment = storageTexelBufferOffsetSingleTexelAlignment;
              struct_to_fill.uniformTexelBufferOffsetAlignmentBytes = uniformTexelBufferOffsetAlignmentBytes;
              struct_to_fill.uniformTexelBufferOffsetSingleTexelAlignment = uniformTexelBufferOffsetSingleTexelAlignment;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_texel_buffer_alignment
#ifdef VK_QCOM_render_pass_transform
       static inline VkRenderPassTransformBeginInfoQCOM vkfRenderPassTransformBeginInfoQCOM(VkSurfaceTransformFlagBitsKHR transform)
       {
              VkRenderPassTransformBeginInfoQCOM struct_to_fill;
              struct_to_fill.transform = transform;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkCommandBufferInheritanceRenderPassTransformInfoQCOM vkfCommandBufferInheritanceRenderPassTransformInfoQCOM(VkSurfaceTransformFlagBitsKHR transform, VkRect2D renderArea)
       {
              VkCommandBufferInheritanceRenderPassTransformInfoQCOM struct_to_fill;
              struct_to_fill.transform = transform;
              struct_to_fill.renderArea = renderArea;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_QCOM_render_pass_transform
#ifdef VK_EXT_pipeline_creation_cache_control
       static inline VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT vkfPhysicalDevicePipelineCreationCacheControlFeaturesEXT(VkBool32 pipelineCreationCacheControl)
       {
              VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT struct_to_fill;
              struct_to_fill.pipelineCreationCacheControl = pipelineCreationCacheControl;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
#endif //VK_EXT_pipeline_creation_cache_control
#ifdef VK_NV_device_diagnostics_config
       static inline VkPhysicalDeviceDiagnosticsConfigFeaturesNV vkfPhysicalDeviceDiagnosticsConfigFeaturesNV(VkBool32 diagnosticsConfig)
       {
              VkPhysicalDeviceDiagnosticsConfigFeaturesNV struct_to_fill;
              struct_to_fill.diagnosticsConfig = diagnosticsConfig;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV;
              struct_to_fill.pNext = NULL;
              return struct_to_fill;
       }
       static inline VkDeviceDiagnosticsConfigCreateInfoNV vkfDeviceDiagnosticsConfigCreateInfoNV()
       {
              VkDeviceDiagnosticsConfigCreateInfoNV struct_to_fill;
              struct_to_fill.sType = VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV;
              struct_to_fill.pNext = NULL;
              struct_to_fill.flags = 0;
              return struct_to_fill;
       }
#endif //VK_NV_device_diagnostics_config

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__VULKAN_FILLER_H__