#pragma once
#include <array>
class RenderingShape
{

protected:


	bool dynamic;

	std::array<double, 4> eulerRot;
	std::array<double, 4> translation;
	std::array<double, 4>	scale;

	std::array<double, 4> ambient;
	bool		ambientSet;
	std::array<double, 4> diffuse;
	bool		diffuseSet;
	std::array<double, 4> specular;
	bool		specularSet;
	double		shininess;
	bool		shininessSet;
	int		alphaFunc;		// Function and value for alpha testing
	double		alphaValue;
	bool		alphaDataSet;
	bool		alphaTransparency;
	bool		transparencySet;
	friend class Scene;
public:
	virtual ~RenderingShape() = default;
};