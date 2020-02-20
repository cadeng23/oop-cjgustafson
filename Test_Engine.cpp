#include "Engine.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

TEST(Engine, Defaults)
{
    Engine Engine;
    ASSERT_EQ(Engine.gettemp(),Engine::Default);
    ASSERT_EQ(Engine.getCurrent, Engine::Default);
    ASSERT_EQ(Engine.hasOverheated(), false);
    ASSERT_EQ(Engine.isOverheatig(),Engine::Deffault == 0.0);
}

TEST (Engine, Specific)
{
    double testTemperature = 150.0;
    double testOutside = Engine::Outside;
    Engine Engine(testTemperature,testOutside);

    ASSERT_EQ(Engine.gettemp(),testTemperature);
    ASSERT_EQ(Engine.Outside(),testOutside);
    ASSERT_EQ(Engine.Over(),false);
    ASERT_EQ(Engine.isOverheating(),false);
}
TEST(Engine, OVERHEATED)
{
    double testTemperature = Engine::Overheat;
    Engine Engine;
    Engine.setCurrent(testTemperature);
    ASSERT_EQ(Engine.gettemp(),TestTemperature);
    ASSERT_EQ(Engine.isOverheating(),false);
    Engine.setTemp(0.0);
    ASSERT_EQ(Engine.isOverheating(),true);
}

TEST(Engine,Overheat)
{
    Engine Engine;
    Engine.setCurrent(Engine::Overheat);
    ASSERT_EQ(Engine.isOverheating(),false);
    ASERT_EQ(Engine.hasOverheated(),false);
    Engine.getCurrent(Engine::Overheat);
    ASSERT_EQ(Engine.getcurrent(),0.0);
    ASSERT_EQ(Engine.hasOverheated(),true);
    ASERT_EQ(Engine.hasOverheated(),true);
    Engine.getcurrent(Engine::Overheat);
    ASSERT_EQ(Engine.getcurrent(),0.0);
    ASSERT_EQ(Engine.hasOverheated(),true);
    ASERT_EQ(Engine.hasOverheated(),true);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}