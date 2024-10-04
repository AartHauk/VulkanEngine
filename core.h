#ifndef ENGINE_CORE
#define ENGINE_CORE

#include <string>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vulkan/vk_platform.h>
#include <vulkan/vulkan_core.h>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else 
const bool enableValidationLayers = true;
#endif

namespace engine {

    extern VkInstance INSTANCE;
    extern VkDevice DEVICE;
    extern VkPhysicalDevice PHYSICAL_DEVICE;

    extern GLFWwindow* WINDOW;
    extern VkSurfaceKHR SURFACE;

    extern VkQueue GRAPHICS_QUEUE;
    extern VkQueue PRESENT_QUEUE;

    extern VkDescriptorSetLayout DESCRIPTOR_SET_LAYOUT;
    extern VkExtent2D SWAP_CHAIN_EXTENT;

    extern VkSwapchainKHR SWAP_CHAIN;
    extern VkRenderPass RENDER_PASS;

    extern VkDebugUtilsMessengerEXT DEBUG_MESSENGER;
    extern VkCommandPool COMMAND_POOL;

    extern VkSampleCountFlagBits MSAA_SAMPLES = VK_SAMPLE_COUNT_1_BIT;



    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    static std::vector<char> readFile(const std::string& filename);
    void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);

}

#endif // ENGINE_CORE