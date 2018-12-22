#include "ctpch.h"
#include "GameEngine.h"
#include "Object/GameObject/GameObject.h"
#include "Rendering/Render/preset/RenderLight.h"
#include "openGL.h"

void CT_API GameEngine::init(unsigned int width, unsigned int height)
{
	GameEngine::ui_width = width;
	GameEngine::ui_height = height;
	background_red = 0.0;
	background_green = 0.0;
	background_blue = 0.0;
	background_alpha = 1.0;
	GameEngine::Log::Init();
	CT_CORE_INFO("Initialisation du moteur de jeu!");
	CT_CORE_TRACE("Initialisation SDL!...");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		CT_CORE_CRITICAL("Erreur lors de l'initialisation de la SDL\n");//, SDL_GetError());
		return;
	}
	CT_CORE_TRACE("Initialisation de la fentre!");
	sdl_window = SDL_CreateWindow(
		window_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		ui_width,
		ui_height,
		SDL_WINDOW_OPENGL
	);
	if (sdl_window == 0)
	{
		CT_CORE_CRITICAL("Erreur lors de l'initialisation de la fenetre\n");//, SDL_GetError());
		return;
	}

	CT_CORE_TRACE("Configuration OpenGL de la SDL!");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	sdl_context = SDL_GL_CreateContext(sdl_window);
	if (sdl_context == 0)
		CT_CORE_CRITICAL("Erreur de creation de context.");
	CT_CORE_TRACE("Initialisation de GLEW!");
	glewExperimental = GL_TRUE;

	GLenum glew_enum = glewInit();
	if (glew_enum != GLEW_OK)
	{
		CT_CORE_CRITICAL("Erreur lors de l'initialisation de GLEW\n");//, SDL_GetError());
		return;
	}
	glClearColor(background_red, background_green, background_blue, background_alpha);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(sdl_window);
	CT_CORE_INFO("Fin de l'initialisation!");
	m_perspective_matrice = glm::perspective(100.f, 1.0f, 0.1f, 100.0f);
	m_view_matrice = glm::lookAt(
		glm::vec3(0.0f,0.0f, 1.0f),
		glm::vec3(0.0f,0.0f, 1.0f),
		glm::vec3(0.0f,0.0f, 1.0f));
	list_render["light"] = new RenderLight();
}

void CT_API GameEngine::start(Scene* scn)
{
	current_scene = scn;
	CT_CORE_INFO("Lancement de la boucle principal du program");
	b_active = true;
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glm::mat4 model = glm::scale(
		glm::mat4(1.0f),
		glm::vec3(1.0, 1.0, 1.0));
	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0, 0.0, -4.0),  // eyes
		glm::vec3(0.0, 0.0, 0.0),  // center
		glm::vec3(0.0, 1.0, 0.0)); // up
	glm::mat4 projection = glm::perspective(glm::radians(100.0f),
		1.0f, 0.1f, 10.0f);
	while (b_active)
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		_event_manager();
		current_scene->draw();
		SDL_GL_SwapWindow(sdl_window);
		SDL_GL_SetSwapInterval(1);
	}
}

void CT_API GameEngine::quit()
{
	b_active = false;
	SDL_GL_DeleteContext(sdl_context);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}

void CT_API GameEngine::set_background(double red, double green, double blue, double alpha)
{
	background_red = red;
	background_green = green;
	background_blue = blue;
	background_alpha = alpha;
}

CT_API Scene* GameEngine::get_current_scene()
{
	return current_scene;
}

Shader* GameEngine::get_shader(const std::string& name)
{
	if (list_shaders.find(name) != list_shaders.end())
		return list_shaders[name];
	else
	{
		Shader* shader = new Shader(path_shader + name);
		list_shaders[name] = shader;
		return shader;
	}
}

Material* GameEngine::get_material(const std::string& name)
{
	if (list_material.find(name) != list_material.end())
		return list_material[name];
	else
	{
		Material* mat = new Material(name);
		list_material[name] = mat;
		return mat;
	}
}

Model* GameEngine::get_model(const std::string& name)
{
	if (list_model.find(name) != list_model.end())
		return list_model[name];
	else
	{
		Model* model = new Model(path_obj + name);
		list_model[name] = model;
		return model;
	}
}

IRender* GameEngine::get_render(const std::string& name)
{
	if (list_render.find(name) != list_render.end())
		return list_render[name];
	else
	{
		IRender* render = new IRender(name);
		list_render[name] = render;
		return render;
	}
}

Texture* GameEngine::get_texture(const std::string& name)
{
	if (list_textures.find(name) != list_textures.end())
		return list_textures[name];
	else
	{
		Texture* tex = new Texture(path_texture + name);
		list_textures[name] = tex;
		return tex;
	}
}


void GameEngine::_event_manager()
{

	while (SDL_PollEvent(&sdl_event))
	{


		if (sdl_event.type == SDL_QUIT)
		{
			b_active = false;
		}
		if (sdl_event.type == SDL_KEYDOWN)
		{
			switch (sdl_event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				b_active = false;
				break;
			}
		}
	}
}
