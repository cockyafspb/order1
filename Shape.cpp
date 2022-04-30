#include "Shape.h"

Shape::Shape() : area(0) {}

Shape::Shape(double Area) : area(Area) {}

void Shape::draw() { std::cout << "Shape::draw" << std::endl; }

void Shape::print() { std::cout << "Shape::print" << std::endl; }

double Shape::GetArea() { return area; }

//Shape::~Shape() { std::cout << "~Shape()\n"; };

Shape::~Shape() = default;

Shape::Shape(const Shape &Other) = default;

