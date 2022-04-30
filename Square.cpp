#include "Square.h"

Square::Square() : Rectangle() {}

Square::Square(double C) : Rectangle(C, C) {}

Square::Square(const Square &Other) = default;

//Square::~Square() { std::cout << "~Square()\n"; };

Square::~Square() = default;

void Square::draw() { std::cout << "Square::draw" << std::endl; }

void Square::print() { std::cout << "Square::print" << std::endl; }