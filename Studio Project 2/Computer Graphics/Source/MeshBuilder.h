#ifndef MESH_BUILDER_H
#define MESH_BUILDER_H

#include "Mesh.h"
#include "LoadOBJ.h"

/******************************************************************************/
/*!
		Class MeshBuilder:
\brief	Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder {

private:
	static float SphereX(float phi, float theta);
	static float SphereY(float phi);
	static float SphereZ(float phi, float theta);
	static float CircleX(float theta);
	static float CircleZ(float theta);

public:
	static Mesh* GenerateAxes(const std::string &meshName = "Reference Axes", float size = 1000.0f);
	static Mesh* GenerateQuad(const std::string &meshName = "Quad", Colour colour = Colour(1.0f, 1.0f, 1.0f), float size = 1.0f);
	static Mesh* GenerateCube(const std::string &meshName = "Cube", Colour colour = Colour(1.0f, 1.0f, 1.0f), float size = 1.0f);
	static Mesh* GenerateCircle(const std::string &meshName = "Circle", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numSlices = 36, float diameter = 1.0f);
	static Mesh* GenerateRing(const std::string &meshName = "Ring", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numSlices = 36, float innerDiameter = 0.8f, float outerDiameter = 1.0f);
	static Mesh* GenerateSphere(const std::string &meshName = "Sphere", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numStacks = 18, unsigned int numSlices = 36, float Diameter = 1.0f);
	static Mesh* GenerateTorus(const std::string &meshName = "Torus", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numStacks = 36, unsigned int numSlices = 36, float outerR = 1.0f, float innerR = 0.2f);
	static Mesh* GenerateTube(const std::string &meshName = "Tube", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numSlices = 36, float height = 1.0f, float topOuterRadius = 0.5f, float topInnerRadius = 0.3f, float bottomOuterRadius = 0.5f, float bottomInnerRadius = 0.3f);
	static Mesh* GenerateCylinder(const std::string &meshName = "Cylinder", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numSlices = 36, float height = 1.0f, float radius = 0.5f);
	static Mesh* GenerateSquarePyramidFrustum(const std::string &meshName = "Square Pyramid Frustum", Colour colour = Colour(1.0f, 1.0f, 1.0f), float topWidth = 1.0f, float topLength = 1.0f, float bottomWidth = 1.0f, float bottomLength = 1.0f, float height = 1.0f);
	static Mesh* GenerateCone(const std::string &meshName = "Cone", Colour colour = Colour(1.0f, 1.0f, 1.0f), unsigned int numSlice = 36, float radius = 1.0f, float height = 1.0f);
	static Mesh* GenerateOBJ(const std::string &meshName, const std::string &filePath);
	static Mesh* GenerateText(const std::string &meshName, unsigned int numRow, unsigned int numCol);

};

#endif