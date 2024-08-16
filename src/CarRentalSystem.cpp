#include "CarRentalSystem.h"

CarRentalSystem::CarRentalSystem() :reservationCount(0), reservationSize(100), CopyReservationCount(0), CopyReservationSize(100),Size(100), count(0)
{
    carList = new Car[Size];//first in 
    reservationList = new Invoice[reservationSize];
    CopyReservationList = new Invoice[CopyReservationSize];
}

CarRentalSystem::~CarRentalSystem()
{
    delete[] CopyReservationList;
    delete[] reservationList;
    delete[] carList;//last out
}



void CarRentalSystem::addCar()
{
    char ch;
    do
    {
        if (count >= Size)
        {
            cout << "Sorry, yoy can\'t add any more \n";
            return;
        }

        cin >> carList[count++];
        cout << "Car added successfully \n";
        cout << "\nDo Another ? (y/n) : ";
        cin >> ch;
    } while (ch != 'n');

}

void CarRentalSystem::editCar()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, Try to add cars first \n";
        return;
    }
    int id;
    cout << "Enter car ID to Edit : ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getCarId() == id)
        {
            found = true;
            cout << "You are about to enter the new data ... \n";
            cin >> carList[i];
            cout << "\nCar modified successfully \n";
            return;
        }

    }
    if (!found)
    {
        cout << "search failed \n";
    }
}

void CarRentalSystem::searchCar()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first\n";
        return;
    }
    int id;
    cout << "Enter car ID to search : ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getCarId() == id)
        {
            found = true;
            cout << "\nCar has been found successfully \n";
            cout << carList[i];
            break;
        }
        else
            found = false;
    }
    if (!found)
        cout << "Car couldn\'t be found \n";
}

void CarRentalSystem::deleteCar()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first\n";
        return;
    }
    int id;
    cout << "Enter car ID to delete : ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getCarId() == id)
        {
            found = true;
            carList[i] = carList[count - 1];
            --count;
            cout << "\nCar deleted successfully \n";
            return;;
        }
        else
            found = false;
    }
    if (!found)
        cout << "Car couldn\'t be found \n";
}

void CarRentalSystem::printAllCars()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first\n";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << "(" << i + 1 << ")  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << carList[i];
    }
}





void CarRentalSystem::rentAcar()
{
    //if car list is empty
    if (count == 0)
    {
        cout << "There isn\'t any car yet, Try to add cars first \n";
        return;
    }

    Car c1;
    Customer c2;

    float rental_rate;
    double insurance, taxes;
    int id, start, end;
    bool found = false;
    bool flag = false;
    cout << "Enter car id to rent : ";
    cin >> id;
    //for loop to check for the wanted car is in carList array 
    for (auto i = 0; i < count; ++i)
    {
        //if car found
        if (carList[i].getCarId() == id)
        {
            found = true;

            cout << "Please enter the following required data .... \n";
            cout << "start date (in hours): ";
            cin >> start;
            (start == 12 ? start = 0 : start = start);
            cout << "End date (in hours): ";
            cin >> end;
            //check the availability
            if (carList[i].getAvailability() == true)//avaliable
            {
                carList[i].setAvailability(false);
                c1 = carList[i];
                cout << endl;
                cout << "Renatl Rate : ";
                cin >> rental_rate;
                cout << "Insurance Charges : ";
                cin >> insurance;
                cout << "Taxes : ";
                cin >> taxes;
                cout << endl;
                cin >> c2;
                reservationList[reservationCount++] = Invoice(c1,c2,taxes, rental_rate, insurance, (start == 0 ? start = 12 : start = start), end);
                cout << "Car rented successfully \n";

                CopyReservationList[CopyReservationCount++] = reservationList[reservationCount - 1];
                return;
            }
            else
            {
                

                //if car is rented
                //car can be rented more than one time  -> So we will do ...
                //for loop of all cars that is rented to make sure that new period does not intersect with any rented one
                for (int j = 0; j < reservationCount; ++j)
                {
                    //check the car
                    if (reservationList[j].getReservationID() == carList[i].getCarId())
                    {
                        //check period
                        if  (!(
                            (start >= reservationList[j].getRESstart() && start <= reservationList[j].getRESend())
                            || (end >= reservationList[j].getRESstart() && end <= reservationList[j].getRESend())
                            || (start <= reservationList[j].getRESstart() && end >= reservationList[j].getRESend())
                            ))
                        {
                            flag = true;
                            c1 = carList[i];
                            cout << endl;
                            cout << "Renatl Rate : ";
                            cin >> rental_rate;
                            cout << "Insurance Charges : ";
                            cin >> insurance;
                            cout << "Taxes : ";
                            cin >> taxes;
                            cout << endl;
                            cin >> c2;
                            reservationList[reservationCount++] = Invoice(c1,c2,taxes, rental_rate, insurance, (start==0?start=12:start=start), end);
                            cout << "Car rented successfully \n";
                            CopyReservationList[CopyReservationCount++] = reservationList[reservationCount - 1];
                            return;
                            
                        }

                    }
                }
                
            }
        }
    }
    if (!found)
    {
        cout << "Sorry, the car couldn\'t be rented \n";
        return;
    }
    if (!flag)
    {
        cout << "Sorry, The car is not availabile in that period \n";
    }
}

void CarRentalSystem::returnAcar()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first \n";
        return;
    }
    if (reservationCount == 0)
    {
        cout << "There isn\'t any rented car to return \n";
        return;
    }
    int id, start, end;
    cout << "Enter car ID to return : ";
    cin >> id;
    cout << "Enter recived date : ";
    cin >> start;
    cout << "Enter return date : ";
    cin >> end;
    bool found = false;
    for (auto i = 0; i < reservationCount; ++i)
    {
        if ((reservationList[i].getReservationID() == id)
            && (reservationList[i].getRESstart() == start)
            && (reservationList[i].getRESend() == end))
        {
            found = true;
            //delete car from reservation list
            reservationList[i] = reservationList[reservationCount - 1];
            --reservationCount;
            cout << "Car returned successfully \n";
            //if car no longer exists in reservaion list  -> then it will be available  
            bool flag = false;
            for (auto j = 0; j < reservationCount; ++j)
            {
                //if car found again then it is still rented in another period
                if (reservationList[j].getReservationID() == id)
                {
                    flag = true;
                    break;
                }
                
            }
            if(!flag)
                carList[i].setAvailability(true);


            break;

        }
        
    }
    if (!found)
        cout << "Return Faild \n";

}

void CarRentalSystem::availableCars() const
{
    //if car list is empty
    if (count == 0)
    {
        cout << "There isn\'t any car yet \n";
        return;
    }
    //print available cars
    int x = 0;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getAvailability())
        {
            cout << "(" << ++x << ")  " << "^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << carList[i] << endl;

        }
    }
    //if all cars are rented
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getAvailability())
        {
            found = true;
            break;
        }

    }
    if (!found)
        cout << "Sorry, All cars are rented .. try to find a free period of the wanted car \n";
}

void CarRentalSystem::rentalHistory() const
{
    //if there isn't any car in car list
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first \n";
        return;
    }
    //if resrevation list is empty & copy is empty -> that means car does not rent or return
    if (reservationCount == 0 && CopyReservationCount == 0)
    {
        cout << "There isn\'t any car that rented now or before \n";
        return;
    }
    int id;
    cout << "Enter car id to view its Rental history : ";
    cin >> id;
    int rentCount = 0;//represent count of car from copy
    int returnCount = 0;//repersent count of car 
    //actual return = rent from copy - rent from original 
    //not check the availabilty thats why the car could be taken and returned make it availavle => not helpful in rentel history
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getCarId() == id)
        {
            found = true;
            for (int i = 0; i < CopyReservationCount; ++i)
            {
                if (id == CopyReservationList[i].getReservationID())
                    ++rentCount;
                else
                    continue;
            }
            for (int i = 0; i < reservationCount; ++i)
            {
                if (id == CopyReservationList[i].getReservationID())
                    ++returnCount;
                else
                    continue;
            }
            break;
        }
    }
    if (found)
    {
        cout << "\nThat car was -> Rented for (" << rentCount << ") Times \n"
            << "             -> Returned for (" << rentCount - returnCount << ") Times \n";
    }

}

void CarRentalSystem::ReportingAllCars() const
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet, try to add cars first \n";
        return;
    }
    cout << "\tAvailable Cars ... \n"
        << "\t__________________\n\n";

    bool flag = false;
    for (int i = 0; i < count; ++i)
    {
        if (carList[i].getAvailability())
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        int x = 0;
        for (int i = 0; i < count; ++i)
        {
            if (carList[i].getAvailability()) 
            {
                cout << "(" << ++x << ") ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                cout << carList[i] << endl;
            }
        }
    }
    else
        cout << "Empty\n";

    cout << "\tRented Cars ... \n"
        << "\t________________\n\n";
    if (reservationCount > 0)
    {
        for (int i = 0; i < reservationCount; ++i)
        {
            cout << "(" << i + 1 << ") ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
            cout << reservationList[i] << endl;
        }
    }
    else
        cout << "Empty\n";
}

void CarRentalSystem::pay()
{
    if (count == 0)
    {
        cout << "There isn\'t any car yet \n";
        return;
    }
    if (reservationCount == 0)
    {
        cout << "There isn\'t any rented car yet \n";
        return;
    }
    bool found = false;
    int id,start,end;
    cout << "Enter car id that is rented to pay the invoice : ";
    cin >> id;
    cout << "Enter recived date : ";
    cin >> start;
    cout << "Enter return date : ";
    cin >> end;

    for (int i = 0; i < reservationCount; ++i)
    {
        if ((reservationList[i].getReservationID() == id)
            && (reservationList[i].getRESstart() == start)
            && (reservationList[i].getRESend() == end))
        {
            if (reservationList[i].getTotalamount() == 0)
            {
                cout << "You have paied the invoice \x03\n";
                return;
            }
            cout << "You have to pay : " << reservationList[i].getTotalamount() << "$\n";
            found = true;
            double x;
            cout << "Enter amount of payment : ";
            cin >> x;
            if (x < reservationList[i].getTotalamount()) {
                reservationList[i] -= x;
                cout << "You still have to pay : " << reservationList[i].getTotalamount()<<"$\n";
            }
            else if (x > reservationList[i].getTotalamount())
            {
                double s = x - reservationList[i].getTotalamount();
                x -= s;
                reservationList[i] -= x;
                cout << "You have psied the dues and rest for you : " << s << "$\n";
            }
            else
            {
                reservationList[i] -= x;
                cout << "You have psied all the dues" << endl;

            }
            break;
        }
    }
    if (!found)
    {
        cout << "Failed to pay\n";
    }
}


