#include "ctpch.h"
#include "RotationDrive.h"


RotationDrive::RotationDrive(IDrivable* target, float angle, float x, float y, float z):
	IDrive(target), angle(angle), m_rotation(x,y,z)
{

}

RotationDrive::~RotationDrive()
{
}

void RotationDrive::update(float dt)
{
	m_target->rotate(angle*dt, m_rotation.x, m_rotation.y, m_rotation.z);
}
