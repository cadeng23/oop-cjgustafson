#include <stdexcept>
#include "Car.h"

    namespace go{
        Car::Car(const std:: string &_color, double _outside)
            : color(_color), hasbegan(false)

        {
            engine = std::shared_ptr<Engine>(new Engine(_outside))

        }

        const std::string &Car::getColor() const { return color; }
        void Car::setColor(const std::string &value) { color = value; }
        Engine& Car::gettemp(){return *engine}
        const Engine& Car::gettemp() const { return *engine; }

        bool Car::hasOverheated() const { return gettemp().hasOverheated();}
        void Car::start() {started = true;}
        void Car::stop() {started = false;}

        bool Car::hasbegan() const {return started;}
        bool Car::islooping() const {return hasbegan() && ! hasOverheated();}

    }