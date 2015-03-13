#ifndef TUTORIAL_10
#define TUTORIAL_10

#include "Application.h"


class FlyCamera;
class Renderer;

class Tutorial10 : public Application
{
private:
	int Init();
	int Deinit();
	void Update(float a_deltaTime);
	void Draw();

	float m_timer;

	FlyCamera* m_camera;
	Renderer* m_renderer;
};

#endif