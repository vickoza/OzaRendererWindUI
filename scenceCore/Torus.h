#pragma once
#include "RenderingShape.h"
class Torus :
    public RenderingShape
{
	Torus() = delete;
	double innerRadius;
	double outerRadius;
public:
	Torus(double innerRadiusVal, double outerRadiusVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl,
		std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec,
		double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal);
};

