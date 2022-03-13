#include<iostream>
#include<string>

using namespace std;

class Pizza {
    private:
        string topping;
        int diameter;
        double price;
        const static string STTOP;
        const static int STSIZE;
        const static double STPRICE;
    public:
        Pizza();
        Pizza(string topping);
        Pizza(string topping, int diameter);
        Pizza(string topping, int diameter, double price);
        void setValues(string topping);
        void displayValues();
};

const string Pizza::STTOP = "cheese";
const int Pizza::STSIZE = 12;
const double Pizza::STPRICE = 8.99;

Pizza::Pizza(){
    this->topping = STTOP;
    this->diameter = STSIZE;
    this->price = STPRICE;
}

Pizza::Pizza(string topping){
    this->topping = topping;
}

Pizza::Pizza(string topping, int diameter){
    this->topping = topping;
    this->diameter = diameter;
}

Pizza::Pizza(string topping, int diameter, double price){
    this->topping = topping;
    this->diameter = diameter;
    this->price = price;
}

void Pizza::setValues(string topping){
    this->topping = topping;
}

void Pizza::displayValues(){
    cout << this->diameter << " " << this->topping << " " << this->price << endl;
}

int main() {
    Pizza stdPizza;
    Pizza special("pineapple");
    Pizza deluxeSpecial("sausage", 16);
    Pizza veryDeluxeSpecial("lobster", 20, 17.99);
    cout << "Standard "; stdPizza.displayValues();
    cout << "Special "; special.displayValues();
    cout << "Deluxe "; deluxeSpecial.displayValues();
    cout << "Very Deluxe "; veryDeluxeSpecial.displayValues();
    stdPizza.setValues("cheese"); cout << "New "; stdPizza.displayValues();
    return 0;
}