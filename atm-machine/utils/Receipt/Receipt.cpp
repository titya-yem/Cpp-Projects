#include "Receipt.hpp"

using namespace std;

Screen Receipt::receiptMenu()
{
    system("cls");
    cout << "============================================\n";
    cout << "|                  Receipt                 |\n";
    cout << "============================================\n\n";
    cout << "   Please select your options for receipt \n";
    cout << " 1) Print receipt" << "\t2)Go back" << "\t3) Exit";
    cout << "\nEnter your choice: ";

    cin >> receiptOption;
    switch (receiptOption)
    {
    case 1:
        // it will ask users what date or how many history when user wants
        // the receipt it should be but it should not be more than 3 history
        cout << "Print receipt\n";
        waitForUser();
        break;
    case 2:
        cout << "Go back to Account Menu\n";
        waitForUser();
        return Screen::ACCOUNT_MENU;
        break;
    case 3:
        cout << "Thank you for using Le Fang ATM. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Please Select options 1-3 only.\n";
        waitForUser();
        return Screen::Payment_MENU;
        break;
    }

    waitForUser();
    return Screen::Receipt_MENU;
}