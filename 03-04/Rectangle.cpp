#include "Rectangle.h"
#include <iostream>

void Rectangle::Size() {
	area_ = width_ * height_;
}

void Rectangle::Draw() {
	printf("矩形 : %f\n", area_);
}
