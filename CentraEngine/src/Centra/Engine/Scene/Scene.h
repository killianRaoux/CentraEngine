#pragma once
#include "ctpch.h"
#include "../Object/GameObject/GameObject.h"
#include "../Object/Light/Light.h"
#include "../Object/Camera/ICamera.h"
#include "../Object/Drive/IDrive.h"

class CT_API Scene
{
public:
	Scene(ICamera* cam);
	~Scene();
	void update();
	void draw();
	void load();
	void unload();

	void add_gameObject(IGameObject* go);
	void remove_gameObject(IGameObject* go);

	void add_light(Light* light);
	void add_drive(IDrive* drive);
	void set_camera(ICamera* cam);
	void bind_light(Shader* shader);
	ICamera* get_camera();
protected:
	std::vector<IGameObject*> l_gameObject_active;
	std::vector<IDrive*> l_drives;
	ICamera* m_camera_current;
	Light* m_light;
};

