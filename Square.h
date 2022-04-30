#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square();

    explicit Square(double C);

    Square(const Square &Other);

    ~Square();

    void draw();

    void print();
};

#endif //SQUARE_H
