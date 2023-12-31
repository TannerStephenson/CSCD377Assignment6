#include "Plane.h"

unsigned int plane_vao;

void createPlane()
{
	float side = 40.0f;
	GLfloat plane_vertices[] = { -side, 0.0, side, 1.0, //0
								 side, 0.0, side, 1.0,  //1
								side, 0.0, -side, 1.0,//2
								-side, 0.0, -side, 1.0,//3
	};

	GLushort plane_indices[] = { 0, 1, 2,
													2, 3, 0
	};

	glGenVertexArrays(1, &plane_vao);
	glBindVertexArray(plane_vao);

	unsigned int handle[2];
	glGenBuffers(2, handle);

	glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(plane_vertices), plane_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);  // Vertex position

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(plane_indices), plane_indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

}

void drawPlane() {
	glBindVertexArray(plane_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}
