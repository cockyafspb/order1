#include "Rectangle.h"

Rectangle::Rectangle() : Shape(), a(0), b(0) {}

Rectangle::Rectangle(double A, double B) : Shape(A * B), a(A), b(B) {}

void Rectangle::draw() { std::cout << "Rectangle::draw" << std::endl; }

void Rectangle::print() { std::cout << "Rectangle::print" << std::endl; }

//Rectangle::~Rectangle() { std::cout << "~Rectangle()\n"; };

Rectangle::~Rectangle() = default;

Rectangle::Rectangle(const Rectangle &Other) = default;


