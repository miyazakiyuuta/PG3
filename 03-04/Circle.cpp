#include "Circle.h"
#include <iostream>
#include <numbers>

void Circle::Size() {
	area_ = 3.14159265358979323846f * radius_ * radius_;
}

void Circle::Draw() {
	printf("円 : %f\n", area_);
}
