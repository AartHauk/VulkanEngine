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

    extern bool FRAME_BUFFER_RESIZED = false;

    extern VkQueue GRAPHICS_QUEUE;
    extern VkQueue PRESENT_QUEUE;

    extern VkExtent2D SWAP_CHAIN_EXTENT;

    extern VkSwapchainKHR SWAP_CHAIN;
    extern std::vector<VkFramebuffer> SWAP_CHAIN_FRAME_BUFFERS;

    extern VkRenderPass RENDER_PASS;

    extern VkDebugUtilsMessengerEXT DEBUG_MESSENGER;
    extern VkCommandPool COMMAND_POOL;
    extern std::vector<VkCommandBuffer> COMMAND_BUFFERS;

    extern VkSampleCountFlagBits MSAA_SAMPLES = VK_SAMPLE_COUNT_1_BIT;

    extern std::vector<VkImage> swapChainImages;
    extern VkFormat swapChainImageFormat;
    extern std::vector<VkImageView> swapChainImageViews;

    extern VkImage colorImage;
    extern VkDeviceMemory colorImageMemory;
    extern VkImageView colorImageView;

    extern VkImage depthImage;
    extern VkDeviceMemory depthImageMemory;
    extern VkImageView depthImageView;

    void initWindow();

    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createDescriptorSetLayout();
    void createCommandPool();
    void createColorResources();
    void createDepthResources();
    void createFramebuffers();

    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    static std::vector<char> readFile(const std::string& filename);
    void createImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
    VkCommandBuffer begineSigleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);

}

#endif // ENGINE_CORE