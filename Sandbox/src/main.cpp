#include <Centra.h>


int main() {
	GameEngine::init(800, 800);
	Light* light = new Light(
		glm::vec3(0.0f, 0.0f,-4.0f), 
		glm::vec3( 0.5f, 0.0f, 0.5f));
	DynamicObject* go = new DynamicObject("cube.obj", "light", "light.shader");
	//IGameObject go("sphere.obj", "light", "light.shader");
	//go.scale({ 1/10.0f,1 / 10.0f, 1 / 10.0f });
	ICamera cam(
		glm::vec3(0.0f,0.0f,-4.0f),
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(0.0f,1.0f,0.0f)
		);
	RotationDrive* rd = new RotationDrive(go, 1.0f, 1.0f, 1.0f, 1.0f);
	Scene scn(&cam);
	scn.add_drive(rd);
	scn.add_light(light);
	scn.add_gameObject(go);
	GameEngine::start(&scn);

	return 0;
}