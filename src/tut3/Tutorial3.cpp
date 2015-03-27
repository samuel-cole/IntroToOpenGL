#include "Tutorial3.h"
#include "glm\glm.hpp"
#include "glm\ext.hpp"
#include "gl_core_4_4.h"
#include "GLFW\glfw3.h"
#include "FlyCamera.h"
#include "Renderer.h"

using glm::mat4;
using glm::vec3;
using glm::vec4;

int Tutorial3::Init()
{
	int baseInit = Application::Init();
	if (baseInit != 0)
		return baseInit;

	m_camera = new FlyCamera(m_debugBar);
	m_camera->SetPerspective(glm::pi<float>() * 0.25f, 16.0f/9.0f, 0.1f, 1000.0f);
	m_camera->SetLookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));

	auto major = ogl_GetMajorVersion();
	auto minor = ogl_GetMinorVersion();
	printf("GL: %i.%i\n", major, minor);

	m_renderer = new Renderer(m_camera, m_debugBar);

	unsigned int location = m_renderer->GenerateGrid(10, 10, vec3(0, 0, 0));

	m_renderer->LoadTexture("../data/rock_diffuse.tga", location);

	return 0;
}

void Tutorial3::Update(float a_deltaTime)
{
	m_camera->Update(a_deltaTime);
}

void Tutorial3::Draw()
{
	m_renderer->Draw();
}

int Tutorial3::Deinit()
{

	delete m_camera;

	return Application::Deinit();
}