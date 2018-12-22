/*
Header contenant les fonctions et variable general du moteur de jeu.
*/
#pragma once

#include "ctpch.h"
#include "Object/GameObject/IGameObject.h"
#include "Rendering/Render/Shader.h"
#include "Scene/Scene.h"
#undef main
// TEST
/* 
namespace GameEngine contient tout les elements generaux du Moteur de jeu.
*/
namespace GameEngine
{
	static Scene* current_scene;
	//Definition des chemins d'acces.
	static std::string path_shader = "res/shaders/";
	static std::string path_texture = "res/texture/";
	static std::string path_obj = "res/obj/";
	static std::string path_mtl = "res/texture/";

	// Conteneur
	static std::unordered_map<std::string, Shader*>   list_shaders;
	static std::unordered_map<std::string, Texture*>  list_textures;
	static std::unordered_map<std::string, Material*> list_material;
	static std::unordered_map<std::string, Model*>    list_model;
	static std::unordered_map<std::string, IRender*>  list_render;
	

	// Variable de la fenetre.
	static unsigned int ui_width, ui_height; // taille hauteur largeur de la fentre.
	static double background_red, background_green, background_blue, background_alpha; // TODO
	static bool b_active; // activité de la fentre.

	// Variable SDL.
	static SDL_Window* sdl_window;
	static SDL_GLContext sdl_context;
	static SDL_Event sdl_event;

	//static Window current_window;
	static std::string version = "0.0.0";
	static std::string window_title = std::string("GameEngine v")+version;

	// Camera
	static glm::mat4 m_MVP;
	static glm::mat4 m_perspective_matrice;
	static glm::mat4 m_view_matrice;
	
	// Fonction General:
	void CT_API init(unsigned int width, unsigned int height);
	void CT_API start(Scene* scn);
	void CT_API quit();

	// Fonction de configuration:
	void CT_API set_background(double red, double green, double blue, double alpha);
	CT_API Scene* get_current_scene();
	//Fonction de fonctionnement
	Shader*   get_shader(const std::string& name);
	Texture*  get_texture(const std::string& name);
	Material* get_material(const std::string& name);
	Model*    get_model(const std::string& name);
	IRender*  get_render(const std::string& name);

	void _event_manager();


	
};

