#ifndef ENGINE_RENDERER
#define ENGINE_RENDERER

#include "Resources.h"

#include <chrono>
#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>

#include <vulkan/vulkan_core.h>

namespace engine {

    extern const int MAX_FRAMES_IN_FLIGHT = 2;

    extern std::vector<VkBuffer> UNIFORM_BUFFERS;
    extern std::vector<VkDeviceMemory> UNIFORM_BUFFERS_MEMORY;
    extern std::vector<void*> UNIFORM_BUFFERS_MAPPED;

    extern VkDescriptorSetLayout DESCRIPTOR_SET_LAYOUT;
    extern VkDescriptorPool DESCRIPTOR_POOL;
    extern std::vector<VkDescriptorSet> DESCRIPTOR_SETS;

    struct UniformBufferObject {
        alignas(16) glm::mat4 model;
        alignas(16) glm::mat4 view;
        alignas(16) glm::mat4 proj;
    };

    struct RenderObject {
        Texture tex;
        Model model;
        glm::vec3 position = {0, 0, 0};
        glm::vec3 rotation = {0, 0, 0};
        glm::vec3 scale = {1, 1, 1};
    };

    extern std::vector<RenderObject> TO_RENDER;

    void createDescriptorPool();
    void createCommandBuffers();
    void createSyncObjects();
}

#endif