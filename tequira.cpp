#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function to convert a string to lowercase
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to convert a string to Title Case
string toTitle(string str)
{
    if (!str.empty())
    {
        str = toLower(str);
        str[0] = toupper(str[0]);
    }
    return str;
}

int main()
{
    // Food menu
    map<string, double> knust_food_menu = {
        {"Banku", 30.00},
        {"Fufu", 80.00},
        {"Tz", 15.00},
        {"Jollof", 30.00}};

    double total = 0.0;
    string item;

    while (true)
    {
        cout << "What is your food choice? You can type 'done' if you are finished purchasing.\n";
        getline(cin, item);

        // Exit if Ctrl+D (Linux/macOS) or Ctrl+Z (Windows) is pressed
        if (cin.eof())
        {
            break;
        }

        item = toTitle(item);

        if (toLower(item) == "done" || toLower(item) == "exit")
        {
            break;
        }

        if (knust_food_menu.find(item) != knust_food_menu.end())
        {
            total += knust_food_menu[item];
            cout << fixed << setprecision(2);
            cout << "Total: $" << total << endl;
        }
        else
        {
            cout << "Sorry, " << item << " is not available." << endl;
        }
    }

    cout << "\nFinal total: $" << fixed << setprecision(2) << total << endl;

    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class FoodOrderingSystem
{
private:
    map<string, double> menu;
    double total;

    // Convert string to lowercase
    string toLower(string str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Convert string to Title Case
    string toTitle(string str)
    {
        if (!str.empty())
        {
            str = toLower(str);
            str[0] = toupper(str[0]);
        }
        return str;
    }

public:
    // Constructor
    FoodOrderingSystem()
    {
        menu["Banku"] = 30.00;
        menu["Fufu"] = 80.00;
        menu["Tz"] = 15.00;
        menu["Jollof"] = 30.00;

        total = 0.0;
    }

    // Display the menu
    void displayMenu()
    {
        cout << "\n===== KNUST FOOD MENU =====\n";
        for (auto item : menu)
        {
            cout << left << setw(10) << item.first
                 << " : GH₵" << fixed << setprecision(2)
                 << item.second << endl;
        }
        cout << endl;
    }

    // Take orders
    void takeOrder()
    {
        string choice;

        while (true)
        {
            cout << "Enter your food choice (type 'done' to finish): ";
            getline(cin, choice);

            if (cin.eof())
                break;

            choice = toTitle(choice);

            if (toLower(choice) == "done" || toLower(choice) == "exit")
                break;

            if (menu.find(choice) != menu.end())
            {
                total += menu[choice];
                cout << "Current Total: GH₵"
                     << fixed << setprecision(2)
                     << total << endl;
            }
            else
            {
                cout << "Sorry, " << choice
                     << " is not available.\n";
            }
        }
    }

    // Display final bill
    void displayBill()
    {
        cout << "\n=========================\n";
        cout << "Final Total: GH₵"
             << fixed << setprecision(2)
             << total << endl;
        cout << "Thank you for purchasing!\n";
    }
};

int main()
{
    FoodOrderingSystem customer;

    customer.displayMenu();
    customer.takeOrder();
    customer.displayBill();

    return 0;
}