#include "Mesh.h"
#include "GL\glew.h"

/******************************************************************************/
/*!
\brief
Default constructor - generate VBO/IBO here

\param meshName - name of mesh
*/
/******************************************************************************/
Mesh::Mesh(const std::string &meshName) : name(meshName), mode(DRAW_TRIANGLES) {

	//Generate Buffers
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	//Default Texture ID
	textureID = 0;

}

/******************************************************************************/
/*!
\brief
Destructor - delete VBO/IBO here
*/
/******************************************************************************/
Mesh::~Mesh() {

	// Cleanup VBO here
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);

	if (textureID > 0) {

		glDeleteTextures(1, &textureID);

	}

}

/******************************************************************************/
/*!
\brief
OpenGL render code
*/
/******************************************************************************/
void Mesh::Render() {

	//Enable Vertex Array Atributes.
	glEnableVertexAttribArray(0); //1st attribute: positions.
	glEnableVertexAttribArray(1); //2nd attribute: colours.
	glEnableVertexAttribArray(2); //3rd attribute: normals.

	if (textureID > 0) {
		
		glEnableVertexAttribArray(3);

	}

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(Position));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Position) + sizeof(Colour)));
	
	if (textureID > 0) {
	
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Position) + sizeof(Colour) + sizeof(Vector3)));

	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	if (mode == DRAW_TRIANGLES) {
		glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, 0);
	} else if (mode == DRAW_TRIANGLE_STRIP) {
		glDrawElements(GL_TRIANGLE_STRIP, indexSize, GL_UNSIGNED_INT, 0);
	} else if (mode == DRAW_LINES) {
		glDrawElements(GL_LINES, indexSize, GL_UNSIGNED_INT, 0);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	if (textureID > 0) {
		
		glDisableVertexAttribArray(3);

	}

}

void Mesh::Render(unsigned int offset, unsigned int count) {

	//Enable Vertex Array Atributes.
	glEnableVertexAttribArray(0); //1st attribute: positions.
	glEnableVertexAttribArray(1); //2nd attribute: colours.
	glEnableVertexAttribArray(2); //3rd attribute: normals.

	if (textureID > 0) {
		
		glEnableVertexAttribArray(3);

	}

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(Position));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Position) + sizeof(Colour)));
	
	if (textureID > 0) {
	
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Position) + sizeof(Colour) + sizeof(Vector3)));

	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	if(mode == DRAW_LINES) {
		glDrawElements(GL_LINES, count, GL_UNSIGNED_INT, (void*)(offset * sizeof(GLuint)));
	} else if (mode == DRAW_TRIANGLE_STRIP) {
		glDrawElements(GL_TRIANGLE_STRIP, count, GL_UNSIGNED_INT, (void*)(offset * sizeof(GLuint)));
	} else {
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void*)(offset * sizeof(GLuint)));
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	if (textureID > 0) {
		
		glDisableVertexAttribArray(3);

	}

}