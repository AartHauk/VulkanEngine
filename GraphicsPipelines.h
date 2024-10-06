#ifndef ENGINE_PIPELINES
#define ENGINE_PIPELINES

#include <array>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>

#include <vulkan/vulkan_core.h>

namespace engine {
	extern VkPipeline GRAPHICS_PIPELINE;
    extern VkPipelineLayout PIPELINE_LAYOUT;

    struct Vertex {
        glm::vec3 pos;
        glm::vec3 color;
        glm::vec2 texCoord;

        static VkVertexInputBindingDescription getBindingDescription();
        static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();
        bool operator== (const Vertex& other) const;
    };

	void createGraphicsPipeline();
}

#endif // ENGINE_PIPELINES