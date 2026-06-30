#pragma once
#include "RenderingShape.h"
#include "Lighting.h"
#include "Camera.h"
#include <memory>
#include <istream>
#include <vector>
class Scene
{
	std::vector<std::unique_ptr<RenderingShape>> shapes;
	std::vector<std::unique_ptr<Lighting>> lightings;
	Camera camera;
public:
	void loadScene(std::istream& input);
};

