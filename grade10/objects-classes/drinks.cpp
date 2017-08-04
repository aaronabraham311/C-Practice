#include <iostream>
using namespace std;

// Creating beverage class
class Beverage
{
private:
    void addColdWater() // Making function to add cold water and outputting
    {
        cout << "Adding cold water. " << endl;
        return;
    }
    
    void addHotWater()// Making function to add hot water and outputting
    {
        cout << "Adding hot water. " << endl;
        return;
    }
    
    void addMilk() // Making function to add milk and outputting
    {
        cout << "Adding milk. " << endl;
        return;
    }
public:
    void addHotItems() // Making function that calls functions in private which adds hot items to beverage
    {
        addHotWater();
        addMilk();
    }
    
    void addColdItems () // Making function that calls functions in private which adds cold items to beverage
    {
        addColdWater();
    }
    
    virtual void addSachets() = 0; // Creating pure virtual function
};

class Tea : public Beverage
{
public:
    void addHotWater () // Making function to add hot water to tea and outputting
    {
        cout << "Adding hot water to the tea. " << endl;
        return;
    }
    
    void addMilk () // Making function to add milk to tea and outputting
    {
        cout << "Adding milk to tea. " << endl;
        return;
    }
    
    Tea () // Constructor to tell user that it is preparing tea
    {
        cout << "Preparing tea. " << endl;
    }
    
    void addSachets() // Redefining pure virtual function to add tea sachets
    {
        cout << "Adding tea sachets. " << endl;
        return;
    }
};

class Coffee : public Beverage
{
public:
    void addHotWater () // Making function to add hot water to coffee and outputting
    {
        cout << "Adding hot water to the coffee. " << endl;
        return;
    }
    
    void addMilk () // Making function to add milk to coffee and outputting
    {
        cout << "Adding milk to coffee. " << endl;
        return;
    }
    
    Coffee () // Constructor to tell user that it is preparing coffee
    {
        cout << "Preparing coffee. " << endl;
    }
    
    void addSachets() // Redefining pure virtual function to add coffee sachets
    {
        cout << "Adding coffee sachets. " << endl;
        return;
    }
};

class Aerateddrink : public Beverage
{
public:
    void addColdWater() // Making function to add cold water to drink and outputting
    {
        cout << "Adding cold water to aerated drink. " << endl;
        return;
    }
    
    void CO2 () // Making function to add carbon dioxide to drink and outputting
    {
        cout << "Adding carbon dioxide to aerated drink. " << endl;
        return;
    }
    
    void addSachets () // Redefining pure virtual function to add flavour and outputting
    {
        cout << "Adding flavour to the drink. " << endl;
        return;
    }
};


int main()
{
    // Making tea object and declaring relevant functions
    Tea t;
    t.addHotItems();
    t.addSachets();
    
    cout << "****************" << endl;
    
    // Making coffee object and declaring relevant functions
    Coffee c;
    c.addHotItems();
    c.addSachets();
    
    cout << "****************" << endl;
    
    // Making aerated drink object and declaring relevant functions
    Aerateddrink ad;
    ad.addColdItems();
    ad.CO2();
    ad.addSachets();
    
    return 0;
}
