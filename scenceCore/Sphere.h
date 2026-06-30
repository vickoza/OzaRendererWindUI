#pragma once
#include "RenderingShape.h"
class Sphere : public RenderingShape
{
    Sphere() = delete;
	double radius;
public:
	Sphere(double radiusVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl,
		std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec,
		double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal);
};

