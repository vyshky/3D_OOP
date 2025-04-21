#ifndef SHADER_H // ���� ���� ����� ��� ������, �� �� ��������� ��� ���

#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>; // ���������� glew ��� ����, ����� �������� ��� ����������� ������������ ����� OpenGL



class Shader {
public:
	GLuint Program;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
		const GLchar* vertex_shader = R"(
				#version 330 core
				layout(location = 0) in vec3 position;
				layout(location = 1) in vec3 color;
				out vec3 ourColor;
				void main()
				{
				   gl_Position = vec4(position, 1.0);
				   ourColor = color;
				}
				)";
		const GLchar* fragment_shader = R"(
				#version 330 core
				in vec3 ourColor;  // �� ������������� �������� ���� ���������� � ���� OpenGL.
				out vec4 color;
				void main()
				{
					color = vec4(ourColor,1.0f);
				})";

		// 2 ������ ��������
		GLuint vertex, fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertex_shader, NULL);
		glCompileShader(vertex);

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragment_shader, NULL);
		glCompileShader(fragment);


		// 3 ��������� ���������
		this->Program = glCreateProgram();
		glAttachShader(this->Program, vertex);
		glAttachShader(this->Program, fragment);
		glLinkProgram(this->Program);

		// 4 ������� �������, ��������� ��� ��� � ��������� � ��� ������ �� �����
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	void Use() {
		glUseProgram(this->Program);
	}
};
#endif