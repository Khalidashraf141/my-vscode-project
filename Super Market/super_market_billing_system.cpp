#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
//TODO:Need improvement
struct Item{
    std::string name;
    int rate;
    int quantity;
};

class BillingSystem{
    private:
        std::vector<Item> items;
        const std::string filename = "bill.txt";
    public:
        BillingSystem(){
            loadFromFile();
        }

        void addItem(){
            Item item;
            std::cout << "\nEnter Item Name: ";
            std::cin >> item.name;
            std::cout << "\nEnter Rate: ";
            std::cin >> item.rate;
            std::cout << "\nEnter Quantity: ";
            std::cin >> item.quantity;

            items.push_back(item);
            saveToFile();
            std::cout << "Item added successfully\n";
            pause();
        }

        void generateBill(){
            int total = 0;
            std::string name;
            int qty;

            std::cout << "\nEnter Item Name: ";
            std::cin >> name;
            std::cout << "Enter Quantity: ";
            std::cin >> qty;

            bool found = false;

            for(auto& item: items){
                if(item.name == name && qty <= item.quantity){
                    found = true;
                    int amount = item.rate * qty;
                    item.quantity -= qty;
                    total += amount;

                    std::cout << "\nItem  Rate  Qty(kg)  Amount(rs)\n";
                    std::cout << item.name << "  "
                         << item.rate << "    "
                         << qty << "      "
                         << amount << "\n";
                    break;
                }
            }

            if(!found){
                std::cout << "Item not available\n";
            }else{
                saveToFile();
                std::cout << "\nTotal Bill: " << total << "\n";
            }


        }



    private:
        void loadFromFile(){
            std::ifstream in(filename);
            if(!in) return;

            Item item;
            while(in >> item.name >> item.rate >> item.quantity){
                items.push_back(item);
            }
        }


        void saveToFile(){
            std::ofstream out(filename);
            for(const auto& item : items){
                out << item.name << " "
                    << item.rate << " "
                    << item.quantity << "\n";
            }
        }


        void pause(){
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
};


int main()
{
    BillingSystem system;
    bool running = true;

    while(running){
        std::cout << "\n===== Super Market Billing System =====\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Generate Bill\n";
        std::cout << "3. Exit\n";

        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;

        switch(choice){
            case 1:
                system.addItem();
                break;
            case 2:
                system.generateBill();
                break;
            case 3:
                running = false;
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}