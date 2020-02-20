#pragma once

//#include <vector>
#include <memory>
#include "Engine.h"

namespace go {

    class Car{
        //private: std::vector < std::shared_ptr < Engine;
        private: std::string color;
        private: std::string color;
        private: bool started;

        public: Car(const std::string &_color, double _diameter = Engine::DefOutside);

        public: const std::string &getColor() const;
        public: void setColor(const std::string &value);
        public: Engine& gettemp();
        public: const Engine& gettemp() const;

        public: bool hasOverheated() const;

    public: void start();
    public: void stop();
    public: bool hasbegan() const;
    public: bool islooping() const;
    };

}