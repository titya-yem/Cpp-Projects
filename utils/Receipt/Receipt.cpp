#include "Receipt.hpp"
#include <limits>

using namespace std;

Screen Receipt::receiptMenu()
{
    system("cls");
    cout << "============================================\n"
         << "|                  Receipt                 |\n"
         << "============================================\n";
    cout << "   Please select your options for receipt \n\n";
    cout << "\t1) Receipt" << "\t2) Go back \n"
         << "\t\t 3) Exit\n";
    cout << "\nEnter your choice: ";

    cin >> receiptOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (receiptOption)
    {
    case 1:
        system("cls");
        cout << "============================================\n"
             << "|                  Receipt                 |\n"
             << "============================================\n\n";

        if (history.empty())
        {
            cout << "No receipt available for this session.\n";
        }
        else
        {
            // Loop over vector array and print
            for (int i = 0; i < history.size(); i++)
            {
                cout << i << " ) "
                     << history[i].type
                     << " | USD: " << history[i].usd
                     << " | KHR: " << history[i].khr << endl;
            }
        }
        cout << "============================================\n";
        cout << "\t1) Go back " << "\t 2) Exit\n";
        cout << "\tEnter your choice: ";

        cin >> receiptSuccessfulOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (receiptSuccessfulOption)
        {
        case 1:
            cout << "Go back to Account Menu. \n";
            waitForUser();
            return Screen::ACCOUNT_Menu;

        case 2:
            system("cls");
            cout << "Thank you for using Le Fang ATM. Goodbye!\n";
            exit(0);

        default:
            cout << "Please select options 1-2 only.\n";
            waitForUser();
            return Screen::Receipt_Menu;
        }
        break;

    case 2:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_Menu;
        break;

    case 3:
        system("cls");
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;

    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::Receipt_Menu;
        break;
    }

    waitForUser();
    return Screen::Receipt_Menu;
}

void Receipt::action(const string &type, double usd, double khr)
{
    // remove oldest
    if (history.size() == 3)
        history.erase(history.begin());

    // create receipt class
    receiptType receipt;

    // assigned varaible
    receipt.type = type;
    receipt.usd = usd;
    receipt.khr = khr;

    // push to vector array
    history.push_back(receipt);
}
