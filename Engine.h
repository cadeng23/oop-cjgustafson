#pragma once

#include <stdexcept>

namespace go {

        class Engine{
             public: static const double Overheat;
             public: static const double DefOutside; 
             public: static const double Default;  //Default Engine temp will be equal to outside temp
             public: double Outside;   // Current temperature of Outside
             private: double currenttemp;  // current temperature of engine
             private: bool Over; // bool on whether it is overheating or not
             public: Engine(double _Outside = DefOutside, double _currenttemp = Default)

             public: double getOutside();   // had const after func in example code but its a variable not a constant
             public: void setCurrent(double value);
             public: double getCurrent() const;
             public: bool isOverheating() const;
             public: bool hasOverheated() const;
             public: void forcetostop(double reduce);
             
        }

}