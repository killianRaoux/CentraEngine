#pragma once
#include "ctpch.h"

class CT_API IDrivable
{
public:
	virtual void rotate(float angle, float x, float y, float z) = 0;
	virtual void translate(float x, float y, float z) = 0;
	virtual void scale(float x, float y, float z) = 0;

	virtual void set_rotation(float x, float y, float z) = 0;
	virtual void set_position(float x, float y, float z) = 0;
	virtual void set_scale(float x, float y, float z) = 0;

	
};

class CT_API IDrive
{
public:
	IDrive(IDrivable* target) : m_target(target) {};
	~IDrive() {};
	virtual void update(float dt) =0;
protected:
	IDrivable* m_target;
};