// Modify the program of Exercise 6.3 to demonstrate the use of pointers to access the members
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STRING_LENGTH = 50;
int fail = 0;
int success = 0;

class books
{
    char *title;
    char *author;
    char *publisher;
    float price;
    int stock_position;

    void update(float newPrice)
    {
        price = newPrice;
        cout << "Price update internally to: $" << price << "\n";
    }

public:
    // Constructor: Uses 'new' operator to allocate memory
    books();

    // Update Price
    void priceUpdate(float price)
    {
        update(price);
    }

    // getTitle
    const char *getTitle() const
    {
        return title;
    }

    // Destructor: Uses 'Delete[]' operator to free dynamically allocated memory
    ~books();

    // Function to set initial data manually (use for pre-populating inventory)
    void set_initial_data(const char *t, const char *a, const char *p, float pr, int stock);

    // Funciton to input book details
    void enter_book_data();

    // Function to handle the book search and purchase logic
    bool search_and_buy(const char *search_title, const char *serach_author);

    // Function to display current stock details
    void display_details() const;
};

// Constructor Implementation: Allocate memory for strings
books ::books()
{
    title = new char[MAX_STRING_LENGTH];
    author = new char[MAX_STRING_LENGTH];
    publisher = new char[MAX_STRING_LENGTH];
    price = 0.0f;
    stock_position = 0;

    // Initialzie allocated memory to empty stirngs
    title[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
}

books ::~books()
{
    delete[] title;
    delete[] author;
    delete[] publisher;
}

// Function to enter the book details
void books ::enter_book_data()
{
    cout << "\nEnter Book Title: ";
    cin.ignore();

    cin.getline(title, MAX_STRING_LENGTH);

    cout << "Enter Author Name: ";
    cin.getline(author, MAX_STRING_LENGTH);

    cout << "Enter Publisher Name: ";
    cin.getline(publisher, MAX_STRING_LENGTH);

    cout << "Enter Price: $";
    cin >> price;

    cout << "Enter Stock Position (Copies): ";
    cin >> stock_position;

    cout << "Book details entered successfully.\n";
}

// Function to display book details
void books ::display_details() const
{
    cout << "\n--- Book Details ---\n";
    cout << "Title: " << title << "\n";
    cout << "Author: " << author << "\n";
    cout << "Publisher: " << publisher << "\n";
    cout << "Price: $" << price << "\n";
    cout << "Stock Available: " << stock_position << " copies\n";
    cout << "----------------------------------------\n";
}

bool books ::search_and_buy(const char *search_title, const char *search_author)
{
    if (strcmp(search_title, title) == 0 && strcmp(search_author, author) == 0)
    {
        cout << "\nBook Found in Inventory!\n";
        display_details();

        int required_copies;
        cout << "Enter number of copies required: ";
        cin >> required_copies;

        // Check availabilty
        if (required_copies <= stock_position)
        {
            float total_cost = required_copies * price;
            stock_position -= required_copies; // Update Stock

            cout << "\nTraansaction Successfully!\n";
            cout << "----------------------------------------\n";
            cout << "Required Copies: " << required_copies << "\n";
            cout << "Price per copy: $" << price << "\n";
            cout << "Total Cost: $" << total_cost << "\n";
            cout << "Remaining Stock: " << stock_position << " copies\n";
            cout << "------------------------------------------\n";
            // Successful Transaction Counter
            success++;
        }
        else
        {
            cout << "\nATTENTION: Required copies not in stock(" << stock_position << " available).\n";
            // Failed Transaction Counter
            fail++;
        }
        return true; // Book was found
    }
    return false; // Book not found
}

void books ::set_initial_data(const char *t, const char *a, const char *p, float pr, int stock)
{
    strcpy(title, t);
    strcpy(author, a);
    strcpy(publisher, p);
    price = pr;
    stock_position = stock;
}

int main()
{
    // Going to use pointer to access the members

    const int INVENTORY_SIZE = 3;
    books inventory[INVENTORY_SIZE];
    int current_books = 0;

    cout << "====== Book Shop Inventory System Demo =====\n";

    // Using pointer to accesss objects
    books *ptr = inventory; // pointer to first element (books[0])

    // Set initial data using pointer
    (ptr + 0)->set_initial_data("C++ Primer", "Lippman", "Pearson", 45.0f, 10);
    (ptr + 1)->set_initial_data("Data Sttuctures and Algorithms", "Cormen", "MIT Press", 78.5f, 5);
    current_books = 2;

    cout << "Initial inventory loaded with " << current_books << " books.\n";

    int choice;
    do
    {
        cout << "\n----------------------------------------------\n";
        cout << "1. Add New Book to Inventory\n";
        cout << "2. Search and Buy Book\n";
        cout << "3. Update Price\n";
        cout << "4. Transaction Summary\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            if (current_books < INVENTORY_SIZE)
            {
                (ptr + current_books)->enter_book_data(); // Using pointer
                current_books++;
            }
            else
            {
                cout << "\nInventory is full!\n";
            }
            break;

        case 2:
        {
            char search_t[MAX_STRING_LENGTH];
            char search_a[MAX_STRING_LENGTH];

            cout << "\n--- Customer Search ---\n";
            cout << "Enter title of the book: ";
            cin.ignore();
            cin.getline(search_a, MAX_STRING_LENGTH);

            cout << "Enter Author of the book: ";
            cin.getline(search_a, MAX_STRING_LENGTH);

            bool found = false;
            for (int i = 0; i < current_books; ++i)
            {
                if ((ptr + i)->search_and_buy(search_t, search_a))
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "\nBook (Title: " << search_t << ", Author: " << search_a << ") not found in the shop.\n";
            }
        
            break;
        }
        
        case 3:
        {
            if (current_books == 0)
            {
                cout << "\n No Books available to update.\n";
                break;
            }
            char search_title[MAX_STRING_LENGTH];
            float newPrice;
            cout << "\nEnter the Title of the Book to Update Price: ";
            cin.ignore();

            cin.getline(search_title, MAX_STRING_LENGTH);

            // Pointer to member function
            void (books::*priceFunc)(float) = &books::priceUpdate;

            bool found = false;
            for (int i = 0; i < current_books; ++i)
            {
                // compare title
                if (strcmp(search_title, (ptr + i)->getTitle()) == 0)
                {
                    cout << "Enter new Price: $";
                    cin >> newPrice;

                    // Using pointer-to-member-function syntax
                    ((ptr + i)->*priceFunc)(newPrice);

                     found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "\nBook Titled \"" << search_title << "\" not found in inventory.\n";
            }
            break;
        }

        case 4:
        {
            cout << "Failed Transactions: " << fail << "\n";
            cout << "Successful Transactions: " << success << "\n";
            break;
        }

        case 5:
        {
            cout << "\nExiting... Thank you!\n";
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
    }
        
    }while (choice != 5);
    return 0;
}

//TODO:PRACTICE (UNDERSTAND THE CONCEPT OF POINTER TO MEMBERS)