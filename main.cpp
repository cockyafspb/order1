#include "Square.h"

void Draw1(Shape S) {
    S.draw();
    S.print();
};

void Draw2(Shape* S) {
    S->draw();
    S->print();
}

void Draw3(Shape& S) {
    S.draw();
    S.print();
}

int main() {

    std::cout << "Functions for object of \"Shape\" class" << std::endl;
    Shape shape;
    Draw1(shape);
    Draw2(&shape);
    Draw3(shape);
    std::cout << std::endl;

    Rectangle r1(1,2);
    std::cout << "Functions for object of \"Rectangle\" class" << std::endl;
    Draw1(r1);
    Draw2(&r1);
    Draw3(r1);
    std::cout << std::endl;

    Square square(Square(5));
    std::cout << "Functions for object of \"Square\" class" << std::endl;
    Draw1(square);
    Draw2(&square);
    Draw3(square);
    std::cout << std::endl;

    Shape *ptr1 = new Rectangle(5,2);
    std::cout << "Rectangle's area with sides 5 and 2 is " << ptr1->GetArea() << std::endl;
    Shape *ptr2 = new Square(3);
    std::cout << "Square's area with sides equals 3 is " << ptr2->GetArea() << std::endl;

    delete ptr1;
    delete ptr2;

    return 0;
}
