#pragma once
#include "IShape.h"
class Rectangle : public IShape {
public:
	Rectangle(float width, float height) : width_(width), height_(height), area_(0.0f) {}
	void Size() override;
	void Draw() override;

private:
	float width_;
	float height_;
	float area_;
};

