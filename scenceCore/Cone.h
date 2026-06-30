#pragma once
#include "RenderingShape.h"
class Cone :
    public RenderingShape
{
    Cone() = delete;
    double radius;
	double height;
public:
	Cone(double radiusVal, double heightVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl,
		std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec,
		double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal);
};

