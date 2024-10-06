#include "core.h"
#include "GraphicsPipelines.h"
#include "Resources.h"
#include "Renderer.h"

namespace engine {

    RenderObject object;
	
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

    void initVulkan() {
        createInstance();
        setupDebugMessenger();
        createSurface();
        pickPhysicalDevice();
        createLogicalDevice();
        createSwapChain();
        createImageViews();
        createRenderPass();
        createDescriptorSetLayout();

        createGraphicsPipeline();

        createCommandPool();
        createColorResources();
        createDepthResources();
        createFramebuffers();

        loadTexture(object.tex, "textures/texture.png");
        loadModel(object.model, "models/susan.obj");

        createDescriptorPool();
        createCommandBuffers();
        createSyncObjects();

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(WINDOW)) {
            glfwPollEvents();
            drawFrame();
        }

        vkDeviceWaitIdle(DEVICE);
    }

    
}

int main() {

    engine::run();

	return 0;
}