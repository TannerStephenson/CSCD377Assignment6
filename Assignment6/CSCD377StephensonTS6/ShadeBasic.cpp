#include "ShadeBasic.h"

unsigned int shade_vao;

void createShade()
{
	float side = 0.5f;

	GLfloat shade_vertices[] = { 
		-side, 0.0, side, 1.0f,
		side,  0.0, side, 1.0f,
		-side, 0.0, -side, 1.0f,
		side, 0.0, -side, 1.0f,

		-side, 0.0, side, 1.0f,
		 side, 0.0, side, 1.0f,
		 0.0,  side * 3, 0.0, 1.0f,

		side, 0.0, side, 1.0f,
		side, 0.0, -side, 1.0f,
		0.0,  side * 3, 0.0, 1.0f,

		-side, 0.0, -side, 1.0f,
		-side, 0.0, side, 1.0f,
		 0.0,  side * 3, 0.0, 1.0f,

		side, 0.0, -side, 1.0f,
		-side, 0.0, -side, 1.0f,
		0.0,  side * 3, 0.0, 1.0f,
	};

	GLushort shade_indices[] = {
		0, 1, 2, 2, 1, 3,
		4, 5, 6,
		7, 8, 9,
		10, 11, 12,
		13, 14, 15
	};

	glGenVertexArrays(1, &shade_vao);
	glBindVertexArray(shade_vao);

	unsigned int handle[2];
	glGenBuffers(2, handle);

	glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(shade_vertices), shade_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(shade_indices), shade_indices, GL_STATIC_DRAW);


	glBindVertexArray(0);
}

void drawShade() {
	glBindVertexArray(shade_vao);
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0);
}