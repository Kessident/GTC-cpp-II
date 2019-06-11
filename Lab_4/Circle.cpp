//Charles Dodge
//CIST 2362 CRN 63228
//Lab 4 Circle Class

#include "Circle.h"

Circle::Circle() {
    radius = 0.0;
}

Circle::Circle(double r) {
    radius = r;
}

void Circle::setRadius(double r) {
    radius = r;
}