#pragma once

#include "../../Rendering/Model/Model.h"
#include "../../Rendering/Render/IRender.h"

class CT_API IGameObject
{
public:
	IGameObject() {};
	virtual void draw(ICamera* cam) = 0;
};