#pragma once
#include <array>
class RenderingShape
{

protected:


	bool dynamic;
	RenderingShape(std::array<double, 4> const& rot, std::array<double, 4> const& trans, std::array<double, 4> const& scl,
		std::array<double, 4> const& amb, std::array<double, 4> const& diff, std::array<double, 4> const& spec,
		double shininessVal, int alphaFuncVal, double alphaValueVal, bool alphaTransparencyVal)
		: 
			eulerRot{rot}, 
			translation{trans}, 
			scale{scl}, 
			ambient{amb},
			diffuse{diff},
			specular{spec},
			shininess{shininessVal}, 
			alphaFunc{alphaFuncVal}, 
			alphaValue{alphaValueVal}, 
			alphaTransparency{alphaTransparencyVal}
	{ 
	}

	std::array<double, 4> eulerRot;
	std::array<double, 4> translation;
	std::array<double, 4>	scale;

	std::array<double, 4> ambient;
	std::array<double, 4> diffuse;
	std::array<double, 4> specular;
	double		shininess;
	int		alphaFunc;		// Function and value for alpha testing
	double		alphaValue;
	bool		alphaTransparency;
	friend class Scene;
public:
	virtual ~RenderingShape() = default;
};