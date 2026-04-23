#pragma once
#include <array>
struct Camera
{
	std::array<double, 4> position;
	std::array<double, 4> upVector;
	std::array<double, 4> lookAt;
};

