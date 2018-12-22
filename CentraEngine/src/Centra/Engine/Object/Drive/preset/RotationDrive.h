#pragma once
#include "../IDrive.h"
class CT_API RotationDrive:
	public IDrive
{
public:
	RotationDrive(IDrivable* target, float angle, float x, float y, float z);
	~RotationDrive();
	virtual void update(float dt) override;
protected:
	float angle;
	glm::vec3 m_rotation;

};

