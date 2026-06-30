#pragma once
#include "RenderingShape.h"
class Box :
    public RenderingShape
{
    Box() = delete;
    double width;
	double height;
	double depth;
public:
	Box(double widthVal, double heightVal, double depthVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl,
		std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec,
		double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal);
};

