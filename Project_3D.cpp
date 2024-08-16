// prj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cstdlib>///system
#include <windows.h>///sleep,color
#include <iostream>

using namespace std;

///color
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);


#include "CarRentalSystem.h"



struct MyStruct
{
  

    CarRentalSystem c;


    void print(string text, bool newLine = true)
    {
        cout << text << (newLine ? "\n" : " ");
    }

    void separator(int color)
    {
        int x = 80;
        SetConsoleTextAttribute(cout_handle, color);
        for (auto i = 0; i < x; ++i)
        {
            cout << "_";
        }
        SetConsoleTextAttribute(cout_handle, 15);
        cout << endl;
    }

    void Back(int x = 3)
    {
        for (auto i = 0; i < x; ++i)
        {
            cout << ".";
            Sleep(400);
        }
    }
    /// main
    void Cars_system()
    {
        system("cls");
        SetConsoleTextAttribute(cout_handle, 13);
        print("\t\tWelcome to Cars system");
        print("\t\t______________________\n");
        SetConsoleTextAttribute(cout_handle, 15);
        print("How can we help you \x03 ....");
        print("1) Car Modification System ");
        print("2) Car Reservation System ");
        print("0) close ");
        print("Your choice! ", false);
    }
    /// Modification
    void Modification()
    {
        int ch;
        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(cout_handle, 9);
            print("\t\tWelcome in \'Car Modification System\' ");
            print("\t\t____________________________________\n");
            SetConsoleTextAttribute(cout_handle, 15);
            print("-> Enter a service ... ");
            print("1) Add a car ");
            print("2) Search for a car ");
            print("3) Delete a car ");
            print("4) Edit a car ");
            print("5) Show all cars ");
            print("0) Back to Main page ");
            print("Your choice!  ", false);

            cin >> ch;
            separator(9);
            switch (ch)
            {
            case 1:
                //Add a car
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tAdd a car");
                print("\t\t_________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.addCar();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 2:
                //Search for a car
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tSearch for a car");
                print("\t\t________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.searchCar();

                separator(9);
                system("pause");
                break;
            case 3:
                //Delete a car
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tDelete a car");
                print("\t\t_____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.deleteCar();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 4:
                //Edit a car
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tEdit a car");
                print("\t\t__________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.editCar();

                separator(9);
                print("\t\t<- Back ", false);
                Back();
                break;
            case 5:
                //Show all cars
                system("cls");
                SetConsoleTextAttribute(cout_handle, 9);
                print("\t\tShow all cars");
                print("\t\t_____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.printAllCars();

                separator(9);
                system("pause");
                break;
            case 0:
                //out
                print("\t\t\tBack to Main page ", false);
                Back();
                return;
            default:
                //invalid
                print("\t\t\tInvalid choice, Try again ", false);
                Back();
                break;
            }
        }
    }
    /// resrvation
    void Reservation()
    {
        int ch;
        while (true)
        {
            system("cls");
            SetConsoleTextAttribute(cout_handle, 11);
            print("\t\tWelcome in \'Car Reservation System\' ");
            print("\t\t___________________________________\n");
            SetConsoleTextAttribute(cout_handle, 15);
            print("-> Enter a service ... ");
            print("1) Rent a car ");
            print("2) Return a car ");
            print("3) View available cars ");
            print("4) View rental history ");
            print("5) Reporting ");
            print("6) pay an invoice");
            print("0) Back to Main page ");
            print("Your choice!  ", false);

            cin >> ch;
            separator(11);
            switch (ch)
            {
            case 1:
                //rent
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tRent A Car");
                print("\t\t__________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.rentAcar();

                separator(11);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 2:
                //return
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tReturn A Car");
                print("\t\t____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.returnAcar();

                separator(11);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 3:
                //available cars
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tShow Available Cars");
                print("\t\t___________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.availableCars();

                separator(11);
                system("pause");
                break;
            case 4:
                //rental history
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tShow Rental History");
                print("\t\t___________________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.rentalHistory();

                separator(11);
                system("pause");
                break;
            case 5:
                //Reporting
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tReporting");
                print("\t\t_________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.ReportingAllCars();

                separator(11);
                system("pause");
                break;
            case 6:
                //return
                system("cls");
                SetConsoleTextAttribute(cout_handle, 11);
                print("\t\tPay An Invoice");
                print("\t\t_____________\n");
                SetConsoleTextAttribute(cout_handle, 15);

                c.pay();

                separator(11);
                print("\t\t<- Back ", false);
                Back(4);
                break;
            case 0:
                //out
                print("\t\t\tBack to Main page ", false);
                Back();
                return;
            default:
                //invalid
                print("\t\t\tInvalid choice, Try again ", false);
                Back();
                break;
            }
        }
    }
}E;



int main()
{
    int choice;
    while (true)
    {
        E.Cars_system();
        cin >> choice;
        E.separator(13);
        switch (choice)
        {
        case 1:
            //Modification 
            E.Modification();
            break;
        case 2:
            //Reservation
            E.Reservation();
            break;
        case 0:
            //out
            E.print("\t\t\tThanks \x03");
            return 0;
            break;
        default:
            E.print("\t   Invalid Choice, Try again ", false);
            E.Back();
            break;
        }

    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu