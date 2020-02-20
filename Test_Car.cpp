#include "Engine.h"
#include "Car.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Car, Defaults) 
{
    Car Car("blue");
    ASSERT_EQ(Car.getColor(),"blue");
    ASSERT_EQ(Car.gettemp(),Engine::Default);
}

TEST (Car, Specific)
{
    double testTemperature = 70.0;
    Car Car("blue",testTemperature);
    ASSERT_EQ(Car.getColor(),"blue");
    ASSERT_EQ(Car.gettemp(),testTemperature);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
