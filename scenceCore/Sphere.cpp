#include "Sphere.h"

Sphere::Sphere(double radiusVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl, std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec, double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal)
	:
	radius{ radiusVal }, 
	RenderingShape{ rot, trans, scl, amb, diff, spec, shininessVal, alphaFuncVal, alphaValueVal, alphaTransparencyVal }
{
}
