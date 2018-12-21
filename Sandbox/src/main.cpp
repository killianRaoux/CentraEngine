#include <Centra.h>


int main() {
	GameEngine::init(800, 800);
	IGameObject go("cube.obj", "basicRender", "basic2D.shader");
	//IGameObject go("sphere.obj", "light", "light.shader");
	//go.scale({ 1/10.0f,1 / 10.0f, 1 / 10.0f });
	ICamera cam(
		glm::vec3(0.0f,0.0f,-4.0f),
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,1.0f,0.0f)
		);//({ 0.0f,0.0f,-4.0f }, { 0.0f,0.0f,0.0f }, { 0.0f,1.0f,0.0f });
	Scene scn(&cam);
	scn.add_gameObject(&go);
	GameEngine::start(&scn);

	return 0;
}