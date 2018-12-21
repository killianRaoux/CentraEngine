#pragma once

#include "Centra/Engine/GameEngine.h"

/*
TO EXPORT:
	-General function for engine:
		* void init(unsigned int width, unsigned int height)    
			: Engine initialization.
		* void start()   
			: strat mainloop.
		* void stop()    
			: Engine stop.
	-Class for custum:
		* <<interface>> IGameObject     : objet a afficher dans le jeu.
		* <<interface>> IRender         : objet de rendu du jeu.
		* <<interface>> ICamera         : objet pour la camera en jeu.
	-Function for seting.
		* set_fullscreen(bool)   : set the window fullscreen.
		* set_with(unsigned int with);
		
*/