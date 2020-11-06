#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec2 inTexcoords;

layout(location = 0) out vec2 fragTexcoords;

layout(binding = 0, set = 0) uniform Camera
{
    mat4 projection;
    mat4 view;
} camera;

void main() 
{
    gl_Position = camera.projection * camera.view * vec4(inPosition, 1.0);
    fragTexcoords = inTexcoords;
}