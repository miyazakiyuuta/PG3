#pragma once
#include "IShape.h"
class Circle : public IShape {
public:
	Circle(float radius) : radius_(radius), area_(0.0f) {}
	void Size() override;
	void Draw() override;

private:
	float radius_;
	float area_;
};

