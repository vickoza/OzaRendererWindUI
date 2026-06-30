#pragma once
#include "Renderer.h"
#include <vulkan/vulkan.hpp>
class OzaVulkanRender :
    public Renderer
{
	vk::Instance instance;
public:
	OzaVulkanRender() = delete;

	virtual ~OzaVulkanRender() = default;
	virtual void RenderScene(Scene& targetScene) override;
};

