//Charles Dodge
//CIST 2362 CRN 63228
//Lab 4 Circle Class

#ifndef LAB_4_CIRCLE_H
#define LAB_4_CIRCLE_H


class Circle {

private:
    double radius;
    const double PI = 3.14159;

public:
    Circle();
    Circle(double); //radius
    void setRadius(double);

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return PI * radius * radius;
    }

    double getDiameter() const {
        return radius * 2;
    }

    double getCircumference() const {
        return 2 * PI * radius;
    }
};


#endif //LAB_4_CIRCLE_H
