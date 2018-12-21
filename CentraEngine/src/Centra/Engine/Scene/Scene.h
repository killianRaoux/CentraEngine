#pragma once
#include "ctpch.h"
#include "../GameObject/GameObject.h"
#include "ICamera.h"

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

	void set_camera(ICamera* cam);
	ICamera* get_camera();
protected:
	std::vector<IGameObject*> l_gameObject_active;
	ICamera* m_camera_current;
};

