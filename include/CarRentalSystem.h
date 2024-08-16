#pragma once
#include "Invoice.h"
class CarRentalSystem 
{
private:


	//array of cars that are in the system
	int count;
	int Size;
	Car* carList;

	//array of rented cars
	int reservationCount;
	int reservationSize;
	Invoice* reservationList;


	//array of reservation without deleting any returned car
	int CopyReservationCount;
	int CopyReservationSize;
	Invoice* CopyReservationList;

public:
	//initalize three dynamic arrays
	CarRentalSystem();
	//delete
	virtual ~CarRentalSystem();



	//for system cars
	void addCar();
	void editCar();
	void searchCar();
	void deleteCar();
	void printAllCars();
	//for rental system
	void rentAcar();
	void returnAcar();
	void availableCars() const;
	void rentalHistory() const;
	void ReportingAllCars() const;
	void pay();
};


