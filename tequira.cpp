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