#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

string key = "1234567890";

//Command Interface
class Command
{
    public:
        virtual void execute() = 0;
};

//Reciever Class
// Alerts the Sirens on Hawaii and security Systems when on 
//Turns them off and alerts the public when turned off as the Output
class WarningSystem
{
    public:
        void on(){
            cout<<"Warning Systems are on! ALERT ALERT ALERT";
        }
        void off(){
            cout<<"Warning Systems are off. No more Danger";
        }
        void Warnme(){
            cout<< "This is a TEST of out emergency preparedness";
        }
};

// Command to turn on Official Alert
class Alertme : public Command
{
    private: 
        WarningSystem *mWarningSystem;
    
    public:
        Alertme(WarningSystem *system) : mWarningSystem(system) {

        }
            void execute()
            {
            mWarningSystem->on();
            }
        


};

//Command for turning the warning back to off
class TurnOff : public Command
{
private:
    WarningSystem *mWarningSystem;
public:
    TurnOff(WarningSystem *system) : mWarningSystem(system){}
    void execute(){
        mWarningSystem->on();
    }
};
//invoker
class Warn : public Command
{
    private:
        WarningSystem *mWarningSystem;

    public:
        Warn(WarningSystem *system) : mWarningSystem(system){}

        void execute()
        {
            mWarningSystem->Warnme();
        }
};

//Invoker
//Stores Concrete Command Object
class Remote
{
    private:
        Command *mCmd;
    public:
        void setcmd (Command *comm)
        {
            mCmd = comm;
        }
        void ButtPress()
        {
            mCmd->execute();
        }
};

// for security clientel 
int main()
{
// Read in keycode from input file
    string str1;
    ifstream inf;
    inf.open("input.txt");
    inf>>str1;
    int temp = 1;
//for Reciever
WarningSystem *system = new WarningSystem;

//Concrete Command Objects
Alertme *AlertOn = new Alertme(system);
TurnOff *TurnedOff = new TurnOff(system);
Warn *TestOn = new Warn(system);

//invoker
Remote *control = new Remote;

//executing...
if (str1 == key)
{
// only allows the alert to go on once the correct input keycode in
control->setcmd(AlertOn);
control->ButtPress();
}
else if (str1 != key)
{
control->setcmd(TestOn);
control->ButtPress();
}
else 
{
control->setcmd(TurnedOff);
control->ButtPress();
}

delete AlertOn, system, TurnedOff, TestOn, control;
return 0;
}
