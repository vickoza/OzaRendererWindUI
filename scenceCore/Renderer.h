#pragma once
#include "Scene.h"

class Renderer
{
public:
	virtual ~Renderer() = 0;
	virtual void RenderScene(Scene& targetScene) = 0;
};

