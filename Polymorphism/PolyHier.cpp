#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape
{
    protected:
        double height, width;
    public:
    //Using a single value (length) to define height and width
        Shape(double length){
            height = length;
            width = length;
        }
        Shape (double h, double w)
        {
            width = w;
            height = h;
        }
    virtual double Area(){
        return height * width;
    }
};

class Triangle : public Shape
{
public:
        Triangle(double length) : 
        Shape(length)
        {

        }

        double Area()
        {
            return width * height /2;
        }
        
};

class Circle :public Shape
{
public:
        Circle(double width) :
        Shape(width)
        {

        }

        double Area()
        {
            return 3.14159 * std::pow((width/2),2);
        }
};

void ShowArea(Shape& shape)
{
    std::cout<<"Area : " << shape.Area() << "\n"; 
}

int main()
{
    Shape square(10,5);
    Circle circle(10);
    Triangle triangle(15);
    ShowArea(square);
    ShowArea(triangle);
    ShowArea(circle);
    
    return 0;
}

