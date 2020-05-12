#include <iostream>
#include <list>
#include <string>
#include <random>
#include <vector>
using namespace std;

class InputStock;

class Client
{
    public:
    virtual ~Client() = default;
    virtual void Updateme(InputStock&) = 0;
};

class InputStock
{
    private:
        std::vector<Client*> clients;
    public:
        virtual ~InputStock() = default;
        void Attach(Client& client) 
        {
            clients.push_back(&client);
        }
        void Detach(Client& client)
        {
            clients.erase(std::remove(clients.begin(),clients.end(), &client));
        }
        void Notify()
        {
            for (auto* client : clients)
            {
                client->Updateme(*this);
            }
        }


};

//random number for the simulation of a sudden stock change
double getrand()
{
    double a = -10.0;
    double b = 10.0;

    return a +(rand()/ (RAND_MAX / (a - b)));
}

class Stock : public InputStock
{
private:

    double baseline;
    double current = 310.13;
    string StockName;
    double base = 310.13;


public: 
    void SetStock(double baseline, double current,string StockName)
    {
        this -> baseline = baseline;
        this -> current = current;
        this -> StockName = StockName;

        Notify();
    }
    double getBaseline(double c)
     {
         baseline = c;
         return baseline;
    }
    // was having a tough time figuring out how to use this function that will get the 
    // current stock price and also update it with the random
    //integer to simulate a price change
    double getCurrent(double b)
     {
         current = b;
         current += getrand();
         return current;
     }
    string getStockName(string a)
    {
        StockName = a;
        return StockName;
    }
};

class apple: public Client
{
private:
    Stock& APPL;
    int shares = 10;
    double wallet = 2000;
public:
    explicit apple(Stock& a) : APPL(a) 
    {
        APPL.Attach(*this);
    }

    ~apple() 
    {
        APPL.Detach(*this);
    }

    void Updateme(Stock& ChangedValue) override
    {
        if (&ChangedValue == &APPL)
        {
            Draw();
        }
    }
    void Draw()
    {
        double baseline = APPL.getBaseline(310.13);
        double current = APPL.getCurrent(current);
        string StockName = AAPL.getStockName("AAPL");

// starting with 10 shares and $2000 to play with
        if (current > baseline * 1.3 && shares != 0)
        {
        std::cout<< "SELL 1 share"<<std::endl;
        shares = shares - 1;
        wallet = wallet + current;
        }

        else if(current > baseline * 1.8&& shares != 0)
        {
        std::cout<< "SELL ALL SHARES" << std::endl;
        double temp;
        temp = current * shares;
        shares = 0;
        wallet = wallet + temp;
        }
        else if (current < baseline * 0.7 && wallet >= current)
        {
        std::cout<<"BUY 1 share"<< std::endl;
        shares = shares + 1;
        wallet = wallet - current;
        }
        else if(current < baseline * 0.4 && wallet >= current)
        {
        std::cout<< "BUY AS MUCH AS POSSIBLE" << std::endl;
        double temp;
        temp = wallet / current;
        shares = temp + shares;
        wallet = wallet - (current * temp); 
        }
        else 
        {
        double temp;
        temp = baseline - current * -1;
        std::cout<< "current Apple differential from initial value = "
        << temp << std::endl<< "current wallet  = "<< wallet<<std::endl
        <<"current shares of Apple = "<< shares<<std::endl; 
        }
    }
};

void main()
{
    Stock set;

    apple applestock(set);

    set.SetStock(310.13,310.13,"AAPL");
}