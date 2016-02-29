#include "MeshBuilder.h"
#include <GL\glew.h>
#include "MyMath.h"
#include "Mtx44.h"

using Math::DegreeToRadian;

/******************************************************************************/
/*!
\brief
Generate the vertices of a reference Axes; Use red for x-axis, green for y-axis, blue for z-axis
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - x-axis should start at -lengthX / 2 and end at lengthX / 2
\param lengthY - y-axis should start at -lengthY / 2 and end at lengthY / 2
\param lengthZ - z-axis should start at -lengthZ / 2 and end at lengthZ / 2

\return Pointer to mesh storing VBO/IBO of reference axes
*/
/******************************************************************************/

Mesh* MeshBuilder::GenerateAxes(const std::string &meshName, float size)
{

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	v.position.Set(0, 0, 0);
	//v.position.Set(-size * 0.5, 0, 0);
	v.colour.Set(1.0f, 0.0f, 0.0f);
	vertex_buffer_data.push_back(v);

	v.position.Set(size * 0.5, 0, 0);
	v.colour.Set(1.0f, 0.0f, 0.0f);
	vertex_buffer_data.push_back(v);

	v.position.Set(0, 0, 0);
	//v.position.Set(0, -size * 0.5, 0);
	v.colour.Set(0.0f, 1.0f, 0.0f);
	vertex_buffer_data.push_back(v);

	v.position.Set(0, size * 0.5, 0);
	v.colour.Set(0.0f, 1.0f, 0.0f);
	vertex_buffer_data.push_back(v);

	v.position.Set(0, 0, 0);
	//v.position.Set(0, 0, -size * 0.5);
	v.colour.Set(0.0f, 0.0f, 1.0f);
	vertex_buffer_data.push_back(v);

	v.position.Set(0, 0, size * 0.5);
	v.colour.Set(0.0f, 0.0f, 1.0f);
	vertex_buffer_data.push_back(v);

	index_buffer_data.push_back(0);
	index_buffer_data.push_back(1);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(3);
	index_buffer_data.push_back(4);
	index_buffer_data.push_back(5);

	Mesh *mesh = new Mesh(meshName);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_LINES;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a quad; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of quad
\param lengthY - height of quad

\return Pointer to mesh storing VBO/IBO of quad
*/
/******************************************************************************/

Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Colour color, float lengthX, float lengthY)
{
	std::vector<Vertex> vertex_buffer_data;
	std::vector<GLuint> index_buffer_data;
	Vertex v;
	
	v.position.Set(-0.5f *lengthX, 0.5f*lengthY, 0);
	v.colour.Set(color.r, color.g, color.b);
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(1, 1);
	vertex_buffer_data.push_back(v);

	v.position.Set(0.5f*lengthX, 0.5f*lengthY, 0);
	v.colour.Set(color.r, color.g, color.b);
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(0, 1);
	vertex_buffer_data.push_back(v);

	v.position.Set(-0.5f*lengthX, -0.5f*lengthY, 0);
	v.colour.Set(color.r, color.g, color.b);
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(0.5f*lengthX, -0.5f*lengthY, 0);
	v.colour.Set(color.r, color.g, color.b);
	v.normal.Set(0, 0, 1);
	v.texCoord.Set(0, 0);
	vertex_buffer_data.push_back(v);

	for (int i = 0; i < 4; ++i)
	{
		index_buffer_data.push_back(i);
	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);

	mesh->indexSize = 4;
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

Mesh* MeshBuilder::GenerateQuad(const std::string &meshName, Colour colour, float size	) {
	
	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	v.position.Set(size * 0.5, 0, size * 0.5);
	v.colour.Set(colour.r, colour.g, colour.b);
	v.normal.Set(0, 1, 0);
	v.texCoord.Set(0, 1);
	vertex_buffer_data.push_back(v);

	v.position.Set(size * 0.5, 0, -size * 0.5);
	v.colour.Set(colour.r, colour.g, colour.b);
	v.normal.Set(0, 1, 0);
	v.texCoord.Set(0, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-size * 0.5, 0, size * 0.5);
	v.colour.Set(colour.r, colour.g, colour.b);
	v.normal.Set(0, 1, 0);
	v.texCoord.Set(1, 1);
	vertex_buffer_data.push_back(v);

	v.position.Set(-size * 0.5, 0, -size * 0.5);
	v.colour.Set(colour.r, colour.g, colour.b);
	v.normal.Set(0, 1, 0);
	v.texCoord.Set(1, 0);
	vertex_buffer_data.push_back(v);

	index_buffer_data.push_back(0);
	index_buffer_data.push_back(1);
	index_buffer_data.push_back(2);
	index_buffer_data.push_back(3);

	Mesh *mesh = new Mesh(meshName);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;
}

/******************************************************************************/
/*!
\brief
Generate the vertices of a cube; Use random color for each vertex
Then generate the VBO/IBO and store them in Mesh object

\param meshName - name of mesh
\param lengthX - width of cube
\param lengthY - height of cube
\param lengthZ - depth of cube

\return Pointer to mesh storing VBO/IBO of cube
*/
/******************************************************************************/
Mesh* MeshBuilder::GenerateCube(const std::string &meshName, Colour colour, float size)
{

	return GenerateSquarePyramidFrustum(meshName, colour, size, size, size, size, size);
	
}

float MeshBuilder::CircleX(float theta) {

	return cos(Math::DegreeToRadian(theta));

}

float MeshBuilder::CircleZ(float theta) {

	return sin(Math::DegreeToRadian(theta));

}

Mesh* MeshBuilder::GenerateCircle(const std::string &meshName, Colour colour, unsigned int numSlices, float diameter) {

	return GenerateRing(meshName, colour, numSlices, 0.0f, diameter);

}

Mesh* MeshBuilder::GenerateRing(const std::string &meshName, Colour colour, unsigned int numSlices, float innerDiameter, float outerDiameter) {

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	float angleBetweenSlices = 360.0f/numSlices;

	for (unsigned int slices = 0; slices <= numSlices; ++slices) {
	
		float theta = slices * angleBetweenSlices;

		v.position.Set(CircleX(theta) * outerDiameter/2.0f, 0, CircleZ(theta) * outerDiameter/2.0f);
		v.colour = colour;
		v.normal.Set(0, 1, 0);
		v.normal.Normalize();
		vertex_buffer_data.push_back(v);

		v.position.Set(CircleX(theta) * innerDiameter/2.0f, 0, CircleZ(theta) * innerDiameter/2.0f);
		v.colour = colour;
		v.normal.Set(0, 1, 0);
		v.normal.Normalize();
		vertex_buffer_data.push_back(v);

	}

	for (unsigned int i = 0; i <= numSlices * 2 + 1; ++i) {
	
		index_buffer_data.push_back(i);

	}

	Mesh *mesh = new Mesh(meshName);
	
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;

}

float MeshBuilder::SphereX(float phi, float theta) {

	return cos(Math::DegreeToRadian(phi)) * cos(Math::DegreeToRadian(theta));

}

float MeshBuilder::SphereY(float phi) {

	return sin(Math::DegreeToRadian(phi));

}

float MeshBuilder::SphereZ(float phi, float theta) {

	return cos(Math::DegreeToRadian(phi)) * sin(Math::DegreeToRadian(theta));

}

Mesh* MeshBuilder::GenerateSphere(const std::string &meshName, Colour colour, unsigned int numStacks, unsigned int numSlices, float diameter) {

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	float anglePerSlice = 360.0f/numSlices;
	float anglePerStack = 180.f/numStacks;

	for (unsigned int stack = 0; stack < numStacks + 1; ++stack) {
	
		float phi = -90 + stack * anglePerStack;

		for (unsigned int slice = 0; slice < numSlices + 1; ++slice) {

			float theta = slice * anglePerSlice;
			v.position.Set(SphereX(phi, theta) * diameter/2, SphereY(phi) * diameter/2.0f, SphereZ(phi, theta) * diameter/2.0f);
			v.colour = colour;
			v.normal.Set(v.position.x, v.position.y, v.position.z); //Normal of a sphere is the same as the position of the vectices.
			v.normal.Normalize();
			vertex_buffer_data.push_back(v);

		}
		
	}

	for (unsigned int stack = 0; stack < numStacks + 1; ++stack) {
	
		for (unsigned slice = 0; slice < numSlices + 1; ++slice) {
		
			index_buffer_data.push_back(stack * (numSlices + 1) + slice);
			index_buffer_data.push_back((stack + 1) * (numSlices + 1) + slice);

		}

	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;

}

Mesh* MeshBuilder::GenerateTorus(const std::string &meshName, Colour colour, unsigned int numStacks, unsigned int numSlices, float outerR, float innerR) {

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	float degreePerStack = 360.0f/numStacks;
	float degreePerSlice = 360.0f/numSlices;
	float x1, z1;
	float x2, y2, z2;

	for (unsigned stack = 0; stack <= numStacks; ++stack) {
	
		for (unsigned slice = 0; slice <= numSlices; ++slice) {
		
			z1 = outerR * cos(DegreeToRadian(stack * degreePerStack));
			x1 = outerR * sin(DegreeToRadian(stack * degreePerStack));
			z2 = (outerR + innerR * cos(DegreeToRadian(slice * degreePerSlice))) * cos(DegreeToRadian(stack * degreePerStack));
			y2 = innerR * sin(DegreeToRadian(slice * degreePerSlice));
			x2 = (outerR + innerR * cos(DegreeToRadian(slice * degreePerSlice))) * sin(DegreeToRadian(stack * degreePerStack));
			
			v.position.Set(x2, y2, z2);
			v.colour = colour;
			v.normal.Set(x2 - x1, y2, z2 - z1);
			v.normal.Normalize();

			vertex_buffer_data.push_back(v);

			if (stack < numStacks) {

				index_buffer_data.push_back((numSlices + 1) * stack + slice);
				index_buffer_data.push_back((numSlices + 1) * (stack + 1) + slice);

			}

		}

	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;

}

Mesh* MeshBuilder::GenerateTube(const std::string &meshName, Colour colour, unsigned int numSlices, float height, float topOuterRadius, float topInnerRadius, float bottomOuterRadius, float bottomInnerRadius) {

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;
	Vertex v;

	float degreePerSlice = 360.0f/numSlices;

	//Top Ring
	for (unsigned int slice = 0; slice <= numSlices; ++slice) {
	
		float theta = slice * degreePerSlice;

		v.position.Set(CircleX(theta) * topOuterRadius, height/2, CircleZ(theta) * topOuterRadius);
		v.colour = colour;
		v.normal.Set(0, 1, 0);

		vertex_buffer_data.push_back(v);

		v.position.Set(CircleX(theta) * topInnerRadius, height/2, CircleZ(theta) * topInnerRadius);
		v.colour = colour;
		v.normal.Set(0, 1, 0);

		vertex_buffer_data.push_back(v);

	}

	//Inner Side
	if (topInnerRadius > 0.0f && bottomInnerRadius > 0.0f) {
	
		for (unsigned int slice = 0; slice <= numSlices; ++slice) {
			
			float normalYLength = 0;
			float theta = slice * degreePerSlice;

			//Top Vertex
			v.position.Set(CircleX(theta) * topInnerRadius, height/2, CircleZ(theta) * topInnerRadius);
			v.colour = colour;
	
			if (bottomInnerRadius != topInnerRadius) {
	
				float x = sqrt(((bottomInnerRadius-topInnerRadius) * (bottomInnerRadius-topInnerRadius)) + (height * height));
				float normalAngle = 90 - Math::RadianToDegree(acos(height/x));
				normalYLength = sin(Math::DegreeToRadian(normalAngle));
	
				if (topInnerRadius > bottomInnerRadius) {
	
					normalYLength = -normalYLength;
	
				}
	
				v.normal.Set(-CircleX(theta), normalYLength * bottomInnerRadius, -CircleZ(theta));
	
			} else {
			
				v.normal.Set(-v.position.x, 0, -v.position.z);
	
			}

			v.normal.Normalize();

			//Bottom Vertex
			vertex_buffer_data.push_back(v);

			v.position.Set(CircleX(theta) * bottomInnerRadius, -height/2, CircleZ(theta) * bottomInnerRadius);
			v.colour = colour;

			if (bottomInnerRadius != topInnerRadius) {
				
				v.normal.Set(-CircleX(theta), normalYLength * bottomInnerRadius, -CircleZ(theta));

			} else {
			
				v.normal.Set(-v.position.x, 0, -v.position.z);

			}

			v.normal.Normalize();

			vertex_buffer_data.push_back(v);

		}

	}

	//Bottom Ring
	for (unsigned int slice = 0; slice <= numSlices; ++slice) {
	
		float theta = slice * degreePerSlice;

		v.position.Set(CircleX(theta) * bottomInnerRadius, -height/2, CircleZ(theta) * bottomInnerRadius);
		v.colour = colour;
		v.normal.Set(0, -1, 0);

		vertex_buffer_data.push_back(v);

		v.position.Set(CircleX(theta) * bottomOuterRadius, -height/2, CircleZ(theta) * bottomOuterRadius);
		v.colour = colour;
		v.normal.Set(0, -1, 0);

		vertex_buffer_data.push_back(v);

	}
	
	//Outer Side
	for (unsigned int slice = 0; slice <= numSlices; ++slice) {
	
		float theta = slice * degreePerSlice;
		float normalYLength = 0;

		//Bottom Vertex
		v.position.Set(CircleX(theta) * bottomOuterRadius, -height/2, CircleZ(theta) * bottomOuterRadius);
		v.colour = colour;

		if (bottomOuterRadius != topOuterRadius) {

			float x = sqrt(((bottomOuterRadius-topOuterRadius) * (bottomOuterRadius-topOuterRadius)) + (height * height));
			float normalAngle = 90 - Math::RadianToDegree(acos(height/x));
			normalYLength = sin(Math::DegreeToRadian(normalAngle));

			if (topOuterRadius > bottomOuterRadius) {

				normalYLength = -normalYLength;

			}

			v.normal.Set(CircleX(theta), normalYLength * bottomOuterRadius, CircleZ(theta));

		} else {
		
			v.normal.Set(v.position.x, 0, v.position.z);

		}

		v.normal.Normalize();
		vertex_buffer_data.push_back(v);

		//Top Vertex
		v.position.Set(CircleX(theta) * topOuterRadius, height/2, CircleZ(theta) * topOuterRadius);
		v.colour = colour;

		if (topOuterRadius != bottomOuterRadius) {
			
			v.normal.Set(CircleX(theta), normalYLength * bottomOuterRadius, CircleZ(theta));

		} else {
			
			v.normal.Set(v.position.x, 0, v.position.z);

		}

		v.normal.Normalize();
		vertex_buffer_data.push_back(v);

	}

	for (unsigned int i = 0; i < (numSlices + 1) * 8; ++i) {
	
		index_buffer_data.push_back(i);

	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLE_STRIP;

	return mesh;

}

Mesh* MeshBuilder::GenerateSquarePyramidFrustum(const std::string &meshName, Colour colour, float topWidth, float topLength, float bottomWidth, float bottomLength, float height) {

	vector<Vertex> vertex_buffer_data;
	Vertex v;
	vector<GLuint> index_buffer_data;

	//Top
	v.position.Set(-topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(0, 1, 0);
	vertex_buffer_data.push_back(v);

	//Bottom
	v.position.Set(bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(0, -1, 0);
	vertex_buffer_data.push_back(v);

	//Right
	float vector1Right[3] = {bottomLength/2 - bottomLength/2, -height/2 - (-height/2), bottomWidth/2 - (-bottomWidth/2)};
	float vector2Right[3] = {topLength/2 - bottomLength/2, height/2 - (-height/2), (-topWidth/2) - (-bottomWidth/2)};
	float crossProductRight[3] = {(vector1Right[1]*vector2Right[2] - vector1Right[2]*vector2Right[1]), (vector1Right[2]*vector2Right[0] - vector1Right[0]*vector2Right[2]), (vector1Right[0]*vector2Right[1] - vector1Right[1]*vector2Right[0])};

	v.position.Set(bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductRight[0], crossProductRight[1], crossProductRight[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	//Front
	float vector1Front[3] = {topLength/2 - bottomLength/2, height/2 - (-height/2), (-topWidth/2) - (-bottomWidth/2)};
	float vector2Front[3] = {-bottomLength/2 - bottomLength/2, -height/2 - (-height/2), -bottomWidth/2 - (-bottomWidth/2)};
	float crossProductFront[3] = {(vector1Front[1]*vector2Front[2] - vector1Front[2]*vector2Front[1]), (vector1Front[2]*vector2Front[0] - vector1Front[0]*vector2Front[2]), (vector1Front[0]*vector2Front[1] - vector1Front[1]*vector2Front[0])};
	
	v.position.Set(bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductFront[0], crossProductFront[1], crossProductFront[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	//Left
	float vector1Left[3] = {-topLength/2 - (-bottomLength/2), height/2 - (-height/2), -topWidth/2 - (-bottomWidth)};
	float vector2Left[3] = {-bottomLength/2 - (-bottomLength/2), -height/2 - (-height/2), bottomWidth/2 - (-bottomWidth/2)};
	float crossProductLeft[3] = {(vector1Left[1]*vector2Left[2] - vector1Left[2]*vector2Left[1]), (vector1Left[2]*vector2Left[0] - vector1Left[0]*vector2Left[2]), (vector1Left[0]*vector2Left[1] - vector1Left[1]*vector2Left[0])};

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-topLength/2, height/2, topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductLeft[0], crossProductLeft[1], crossProductLeft[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	//Back
	float vector1Back[3] = {-topLength/2 - (-bottomLength/2), height/2 - (-height/2), topWidth/2 - (bottomWidth/2)};
	float vector2Back[3] = {bottomLength/2 - (-bottomLength/2), -height/2 - (-height/2), bottomWidth/2 - (bottomWidth/2)};
	float crossProductBack[3] = {(vector1Back[1]*vector2Back[2] - vector1Back[2]*vector2Back[1]), (vector1Back[2]*vector2Back[0] - vector1Back[0]*vector2Back[2]), (vector1Back[0]*vector2Back[1] - vector1Back[1]*vector2Back[0])};

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);
		
	v.position.Set(-topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(-bottomLength/2, -height/2, -bottomWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	v.position.Set(topLength/2, height/2, -topWidth/2);
	v.colour = colour;
	v.normal.Set(crossProductBack[0], crossProductBack[1], crossProductBack[2]);
	v.normal.Normalize();
	vertex_buffer_data.push_back(v);

	for (unsigned int i = 0; i < vertex_buffer_data.size(); ++i) {
	
		index_buffer_data.push_back(i);

	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;

}

Mesh* MeshBuilder::GenerateCylinder(const std::string &meshName, Colour colour, unsigned int numSlices, float height, float radius) {

	return GenerateTube(meshName, colour, numSlices, height, radius, 0.0f, radius, 0.0f);

}

Mesh* MeshBuilder::GenerateCone(const std::string &meshName, Colour colour, unsigned int numSlices, float radius, float height) {

	return 0;

}

Mesh* MeshBuilder::GenerateOBJ(const std::string &meshName, const std::string &filePath) {

	vector<Position> vertices;
	vector<TexCoord> texCoords;
	vector<Vector3> normals;

	if (LoadOBJ(filePath.c_str(), vertices, texCoords, normals) == true) {
	
		vector<Vertex> vertex_buffer_data;
		vector<GLuint> index_buffer_data;

		for (unsigned int i = 0; i < vertices.size(); ++i) {
		
			Vertex v;

			v.colour.Set(0.0f, 0.0f, 0.0f);
			v.position.Set(vertices[i].x, vertices[i].y, vertices[i].z);
			v.normal.Set(normals[i].x, normals[i].y, normals[i].z);
			v.texCoord.Set(texCoords[i].u, texCoords[i].v);

			vertex_buffer_data.push_back(v);
			index_buffer_data.push_back(i);

		}

		IndexVBO(vertices, texCoords, normals, index_buffer_data, vertex_buffer_data);

		Mesh *mesh = new Mesh(meshName);

		glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
		glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
		mesh->indexSize = index_buffer_data.size();
		mesh->mode = Mesh::DRAW_TRIANGLES;

		return mesh;

	} else {
		
		return NULL;

	}

}

Mesh* MeshBuilder::GenerateText(const std::string &meshName, unsigned int numRow, unsigned int numCol) {

	float width = 1.f/numCol;
	float height = 1.f/numRow;
	
	int offset = 0;

	vector<Vertex> vertex_buffer_data;
	vector<GLuint> index_buffer_data;

	for (unsigned i = 0; i < numRow; ++i) {
		
		for(unsigned j = 0; j < numCol; ++j) {
			
			//Add 4 vertices into vertex_buffer_data

			Vertex v;
			
			v.colour.Set(0.0f, 0.0f, 0.0f);
			v.normal.Set(0, 0, 1);
			
			v.position.Set(0.5f, 0.5f, 0.0f);
			v.texCoord.Set(j*width + width, ((numRow - 1) - i)*height + height);
			vertex_buffer_data.push_back(v);

			v.position.Set(0.0f, 0.5f, 0.0f);
			v.texCoord.Set(j*width, ((numRow - 1) - i)*height + height);
			vertex_buffer_data.push_back(v);

			v.position.Set(0.0f, 0.0f, 0.0f);
			v.texCoord.Set(j*width, ((numRow - 1) - i)*height);
			vertex_buffer_data.push_back(v);

			v.position.Set(0.5f, 0.0f, 0.0f);
			v.texCoord.Set(j*width + width, ((numRow - 1) - i)*height);
			vertex_buffer_data.push_back(v);

			//Add 6 indices into index_buffer_data

			index_buffer_data.push_back(offset + 0);
			index_buffer_data.push_back(offset + 1);
			index_buffer_data.push_back(offset + 2);
			index_buffer_data.push_back(offset + 0);
			index_buffer_data.push_back(offset + 2);
			index_buffer_data.push_back(offset + 3);

			offset += 4;

		}

	}

	Mesh *mesh = new Mesh(meshName);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size() * sizeof(Vertex), &vertex_buffer_data[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, index_buffer_data.size() * sizeof(GLuint), &index_buffer_data[0], GL_STATIC_DRAW);
	
	mesh->indexSize = index_buffer_data.size();
	mesh->mode = Mesh::DRAW_TRIANGLES;

	return mesh;

}