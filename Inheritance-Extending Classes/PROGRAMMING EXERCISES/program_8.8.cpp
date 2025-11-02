/*
8.8 Question-> A shopkeeper wants to maintain the stock database category wise (electronics appliances, food items, clothing, milk product, kitchen product). Specify all the classes and functions as per the relationship between different products.
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Base class for all products
class Product
{
protected:
    string name;
    double price;
    int quantity;

public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q){}

    virtual void showDetails(){
        cout << "Name: " << name << ", Price: Rs." << price << ", Quantity: " << quantity << endl;
    }
};

// Derived class for Electronics
class Electronics : public Product{
    string brand;
public:
    Electronics(string n, double p, int q, string b): Product(n,p,q), brand(b){}

    void showDetails()override{
        cout << "[Electronics] ";
        Product::showDetails();
        cout << "Brand: " << brand << endl;
    }
};

// Derived class for Food Items
class FoodItem : public Product{
    string expiryDate;
public:
    FoodItem(string n, double p, int q, string expiry) : Product(n,p,q),expiryDate(expiry){}

    void showDetails()override{
        cout << "[Food Item] ";
        Product::showDetails();
        cout << "Expiry Date: " << expiryDate << endl;
    }
};


// Derived class for Clothing
class Clothing : public Product
{
    string size;
public:
    Clothing(string n, double p, int q, string s): Product(n,p,q),size(s){}

    void showDetails()override{
        cout <<"[Clothing]";
        Product::showDetails();
        cout << "Size: " << size << endl;
    }
};


// Derived class for Milk Product
class MilkProduct : public Product{
    double fatContent;
public:
    MilkProduct(string n, double p, int q, double f):Product(n,p,q), fatContent(f){}

    void showDetails()override{
        cout << "[Milk Product] ";
        Product::showDetails();
        cout << "Fat Content: " << fatContent << "%" << endl;
    }
};


// Derived class for Kitchen Product
class KitchenProduct : public Product{
    string material;
public:
    KitchenProduct(string n, double p, int q, string m): Product(n,p,q), material(m){}

    void showDetails()override{
        cout << "[Kitchen Product]";
        Product::showDetails();
        cout <<"Material: " << material << endl;
    }
};

// Shop class to store all products
class Shop{
    vector<Product*> stock;
public:
    void addProduct(Product* p){
        stock.push_back(p);
    }

    void displayStock(){
        cout << "\n===== SHOP STOCK DATABASE =====\n";
        for (auto p: stock){
            p->showDetails();
            cout << "-------------------------------------\n";
        }
    }
};

int main()
{
    Shop s;

    s.addProduct(new Electronics("led tv",45000,5,"Samsung"));
    s.addProduct(new Electronics("led tv",45000,5,"kodak"));

    s.displayStock();

    return 0;
}