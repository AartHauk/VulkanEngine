TARGET = HelloTriangle

VULKAN_SDK_PATH = /usr/include/vulkan
STB_INCLUDE_PATH = /usr/include/stb
TINYOBJ_INCLUDE_PATH = /usr/include/tinyobjloader

CFLAGS = -std=c++23 -O3 -I$(STB_INCLUDE_PATH) -I$(VULKAN_SDK_PATH) -I$(TINYOBJ_INCLUDE_PATH) 
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

all: engine shaders

run: engine shaders test

engine: main.cpp
	g++ $(CFLAGS) -o $(TARGET) main.cpp $(LDFLAGS)

.PHONY: test clean

test: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

shaders: vertex fragment

vertex:
	glslc shaders/shader.vert -o shaders/vert.spv 

fragment:
	glslc shaders/shader.frag -o shaders/frag.spv