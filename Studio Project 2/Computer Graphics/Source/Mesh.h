#ifndef MESH_H
#define MESH_H
/****************************************************************************/
/*!
\file Mesh.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include <string>
#include "Vertex.h"
#include "Material.h"

/******************************************************************************/
/*!
		Class Mesh:
\brief	To store VBO (vertex & color buffer) and IBO (index buffer)
*/
/******************************************************************************/
class Mesh
{
public:
	enum DRAW_MODE
	{
		DRAW_TRIANGLES, //default mode
		DRAW_TRIANGLE_STRIP,
		DRAW_LINES,
		DRAW_MODE_LAST,
	};

	Mesh(const std::string &meshName);
	~Mesh();
	void Render();
	void Render(unsigned offset, unsigned count);

	const std::string name;
	DRAW_MODE mode;
	unsigned int vertexBuffer;
	unsigned int indexBuffer;
	unsigned int indexSize;

	Material material;

	unsigned textureID;

};

#endif