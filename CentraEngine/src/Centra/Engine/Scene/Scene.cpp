#include "ctpch.h"
#include "Scene.h"


Scene::Scene(ICamera* cam):
	m_camera_current(cam), m_light(0)
{
	
}


Scene::~Scene()
{
}

void Scene::update()
{

}

void Scene::draw()
{
	//m_camera_current->rotate(1.0f, glm::vec3(0.0f, -1.0f, 0.0f));
	for (IDrive* drive: l_drives)
	{
		drive->update(0.5f);
	}
	for (IGameObject* go: l_gameObject_active)
	{
		go->draw(m_camera_current);
	}
}

void Scene::load()
{

}

void Scene::unload()
{

}

void Scene::add_gameObject(IGameObject* go)
{
	l_gameObject_active.push_back(go);
}

void Scene::remove_gameObject(IGameObject* go)
{
	//l_gameObject_active.erase(l_gameObject_active.)
}

void Scene::add_light(Light* light)
{
	m_light = light;
}

void Scene::add_drive(IDrive* drive)
{
	l_drives.push_back(drive);
}

void Scene::set_camera(ICamera* cam)
{

}

void Scene::bind_light(Shader* shader)
{
	if (m_light != 0)
	{
		m_light->bind(shader);
	}
}

ICamera* Scene::get_camera()
{
	return m_camera_current;
}
