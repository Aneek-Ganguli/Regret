#pragma once
#include <iostream>

struct vec2
{
	vec2()
	:x(0.0f),y(0.0f)
	{}

	vec2(float p_x, float p_y)
	:x(p_x),y(p_y)
	{}

	void print()
	{
		std::cout << x << " , " << y << std::endl;		
	}

	float x,y;

};