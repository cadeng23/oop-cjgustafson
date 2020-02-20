
#include "Engine.h"
#include <stdexcept>

namespace go {
        const double Engine::Overheat = 230.0;
        const double Engine::DefOutside = 70.0;
        const double Engine::Default = 70.0;
         Engine::Engine(double _outside, double _default)
         : outside(_outside), Default(_default),Overheat(_default >= Overheat)
        {
                if (Default >= 215.0)
                {
                        throw std::invalid_argument("Warning! your engine is overheating!");
                }

        }

        double Engine::gettemp() const
        {
        return Default;
        }
        void Engine::settemp(double value)
        {
                if (value >= Engine::Overheat)
                {
                        throw std::invalid_argument("Pull over. Your car needs to cool down!");
                }
                if (value <= Engine::Overheat)
                {
                        Car::hasOverheated() = false;
                }
                if (Over)
                {
                        value = 230.0;
                }
                _currenttemp = value;
        }

        double Engine::gettemp() const
        {
                return _currenttemp;
        }
        bool Engine::isOverheating() const
        {
          return _currenttemp == 230.0;      
        }

        bool Engine::hasOverheated() const
        {
                return Over;
        }

        void Engine::forcetostop(double reduce)
        {
                settemp(gettemp() + reduce);
        }
}