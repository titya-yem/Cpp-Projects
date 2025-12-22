#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    system("cls");

    cout << "==========> 肉店 <==========" << endl;
    cout << "\t1. 牛肉 (Beef)\n"
         << "\t2. 猪肉 (Pork)\n"
         << "\t3. 鸡肉 (Chicken meat)\n"
         << "\t4. 鸭肉 (Duck)\n";

    float totalBeef;
    float totalPork;
    float totalChicken;
    float totalDuck;
    int pricePerKiloGram;

    float paymentInUSD;
    float paymentInKHR;
    float exchangeRate = 4100;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "==========> 😉贝夫😊 <==========" << endl;
        cout << "你买了多少公斤肉？";
        cin >> totalBeef;

        if (totalBeef < 0)
            cout << "\t 输入值必须大于 0。😒🥱";
        else if (totalBeef >= 50)
            pricePerKiloGram = 15;
        else if (totalBeef >= 30)
            pricePerKiloGram = 17;
        else
            pricePerKiloGram = 20;

        paymentInUSD = totalBeef * pricePerKiloGram;
        paymentInKHR = paymentInUSD * exchangeRate;
        system("cls");
        cout << "==========> 您的收据 <==========" << endl;
        cout << "您的订单总重量（公斤）：公斤" << totalBeef << endl;
        cout << fixed << setprecision(2);
        cout << "总付款额为：$" << paymentInUSD << endl;
        cout << "总付款额为：៛" << paymentInKHR;
        break;

    case 2:
        cout << "==========> 😉猪肉😊 <==========" << endl;
        cout << "你买了多少公斤肉？";
        cin >> totalPork;

        if (totalPork < 0)
            cout << "\t 输入值必须大于 0。😒🥱";
        else if (totalPork <= 25)
            pricePerKiloGram = 35000;
        else if (totalPork <= 50)
            pricePerKiloGram = 32000;
        else
            pricePerKiloGram = 30000;

        paymentInKHR = totalPork * pricePerKiloGram;
        paymentInUSD = paymentInKHR / exchangeRate;
        system("cls");
        cout << "==========> 您的收据 <==========" << endl;
        cout << "您的订单总重量（公斤）：公斤" << totalPork << endl;
        cout << fixed << setprecision(2);
        cout << "总付款额为：$" << paymentInUSD << endl;
        cout << "总付款额为：៛" << paymentInKHR;
        break;

    case 3:
        cout << "==========> 😉鸡肉😊 <==========" << endl;
        cout << "你买了多少公斤肉？";
        cin >> totalChicken;

        if (totalChicken < 0)
            cout << "\t 输入值必须大于 0。😒🥱";
        else if (totalChicken <= 10)
            pricePerKiloGram = 30000;
        else if (totalChicken <= 30)
            pricePerKiloGram = 25000;
        else
            pricePerKiloGram = 35000;

        paymentInKHR = totalChicken * pricePerKiloGram;
        paymentInUSD = paymentInKHR / exchangeRate;
        system("cls");
        cout << "==========> 您的收据 <==========" << endl;
        cout << "您的订单总重量（公斤）：公斤" << totalChicken << endl;
        cout << fixed << setprecision(2);
        cout << "总付款额为：$" << paymentInUSD << endl;
        cout << "总付款额为：៛" << paymentInKHR;
        break;

    case 4:
        cout << "==========> 😳选择鸭子的种类🤤 <==========" << endl;
        cout << "\t1. 白鸭 (white duck)\n"
             << "\t2. 黑鸭 (black duck)\n";

        short duckOptions;
        cin >> duckOptions;

        switch (duckOptions)
        {
        case 1:
            cout << "==========> 😉鸭肉😊 <==========" << endl;
            cout << "你买了多少公斤肉？" << endl;
            cin >> totalDuck;

            if (totalDuck < 0)
                cout << "\t 输入值必须大于 0。😒🥱";
            else if (totalDuck <= 10)
                pricePerKiloGram = 15;
            else if (totalDuck <= 50)
                pricePerKiloGram = 22;
            else
                pricePerKiloGram = 22;

            paymentInUSD = totalDuck * pricePerKiloGram;
            paymentInKHR = paymentInUSD * exchangeRate;
            system("cls");
            cout << "==========> 您的收据 <==========" << endl;
            cout << "您的订单总重量（公斤）：公斤" << totalDuck << endl;
            cout << fixed << setprecision(2);
            cout << "总付款额为：$" << paymentInUSD << endl;
            cout << "总付款额为：៛" << paymentInKHR;
            break;

        case 2:
            cout << "==========> 😉鸭肉😊 <==========" << endl;
            cout << "你买了多少公斤肉？" << endl;
            cin >> totalDuck;

            if (totalDuck < 0)
                cout << "\t 输入值必须大于 0。😒🥱";
            else if (totalDuck <= 10)
                pricePerKiloGram = 25;
            else if (totalDuck <= 20)
                pricePerKiloGram = 20;
            else
                pricePerKiloGram = 30;

            paymentInUSD = totalDuck * pricePerKiloGram;
            paymentInKHR = paymentInUSD * exchangeRate;
            system("cls");
            cout << "==========> 您的收据 <==========" << endl;
            cout << "您的订单总重量（公斤）：公斤" << totalDuck << endl;
            cout << fixed << setprecision(2);
            cout << "总付款额为：$" << paymentInUSD << endl;
            cout << "总付款额为：៛" << paymentInKHR;
            break;
        }
        break;

    default:
        cout << "请仅选择 1 到 4 之间的数字 🙄😶‍🌫️";
    }

    return 0;
}