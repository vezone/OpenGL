#shader vertex
#version 330 core

layout(location = 0) in vec2 position;

void main() {
	gl_Position = position;
}


#shader fragment
#version 330 core

layout(location = 0) out vec2 color;

uniform vec2 u_Color;

void main() {
	color = u_Color;
}