#ifndef ENGINE_IMAGE
#define ENGINE_IMAGE

#include <vulkan/vk_platform.h>
#include <vulkan/vulkan_core.h>

#include <string>
#include <memory>


namespace engine {

    struct EngineTexture {
        const VkDevice device;

        int32_t mipLevels = VK_SAMPLE_COUNT_1_BIT;
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        VkSampler textureSampler;

        EngineTexture(const VkDevice device): device(device){};
        ~EngineTexture();
    };

    std::unique_ptr<EngineTexture> loadTextureFromFile (const VkDevice device, const std::string texturePath);
}

#endif