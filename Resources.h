#ifndef ENGINE_RESOURCES
#define ENGINE_RESOURCES

#include "GraphicsPipelines.h"
#include "Renderer.h"

#include <cstdint>
#include <string>

#include <vulkan/vulkan_core.h>

namespace engine {

	struct Texture {
        uint32_t mipLevels;
        VkImage textureImage;
        VkDeviceMemory textureImageMemory;
        VkImageView textureImageView;
        VkSampler textureSampler;
	};

    struct Model {
        std::vector<Vertex> verticies;
        std::vector<uint32_t> indicies;

        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;

        VkBuffer indexBuffer;
        VkDeviceMemory indexBufferMemory;
    };

    void loadTexture(Texture &tex, std::string filepath);
    void loadModel(Model &model, std::string filepath);

    void unloadTexture(Texture &tex);
    void unloadModel(Model &model);
}

#endif // ENGINE_RESOURCES
