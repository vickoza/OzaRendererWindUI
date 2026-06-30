#include "Box.h"

Box::Box(double widthVal, double heightVal, double depthVal, std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl, std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec, double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal)
	:
	width{ widthVal },
	height{ heightVal },
	depth{ depthVal },
	RenderingShape{ rot, trans, scl, amb, diff, spec, shininessVal, alphaFuncVal, alphaValueVal, alphaTransparencyVal }
{
}
