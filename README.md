# Car-Rental-System

## OOP Practical Project

### Overview 
The Car Rental System is a software application that allows users to rent cars from a rental company. 
Customers can reserve a car for a specific period of hours, and return the car 

  ### Classes 
  The Car Rental System project consists of five classes: Car, Customer, Reservation, Rental Agreement, 
  and Invoice. Each class has its own set of attributes and behaviors, and they work together to manage 
  the rental process. & the main class is Car rental system class that brings the project together 
  
    #### Car  
    The Car class represents a car and contains attributes such as make, model, year, and availability. The 
    class also has methods to set and retrieve these attributes. 
    
    #### Customer 
    The Customer class represents a customer and contains attributes such as name, address, and phone 
    number. The class also has methods to set and retrieve these attributes. 
    
    #### Reservation 
    The Reservation class represents a reservation and contains attributes such as start date, end date. The 
    class also has methods to set and retrieve these attributes. Additionally, there is a composition 
    relationship between the Car and Reservation classes, as a car can have multiple reservations, but a 
    reservation is associated with only one car. 
    
    #### Rental Agreement 
    The Rental Agreement class represents a rental agreement and contains attributes such as the rental 
    period, rental rate, and insurance charges. The class also has methods to set and retrieve these 
    attributes. There is a composition relationship between the Reservation and Rental Agreement classes, 
    as a reservation is associated with only one rental agreement. 
    
    #### Invoice 
    The Invoice class represents an invoice and contains attributes such as rental charges, taxes, and the 
    total amount due. The class also has methods to set and retrieve these attributes. There is a 
    composition relationship between the Rental Agreement and Invoice classes, as a rental agreement is 
    associated with only one invoice. 
    
    #### CarRentalSystem 
    The CarRentalSystem class serves as the main class for the program and manages the car rental process. 
    It stores an array of Car objects and an array of rented cars. The main functions of this class include 
    adding new cars to the system, reserving cars for customers, generating rental agreements and invoices, 
    and tracking the availability of cars. There is a composition relationship between the Invoice and 
    CarRentalSystem classes, as the CarRentalSystem class needs to access the invoice information. 

### Relationships 
There are two main relationships between the classes in the Car Rental System project: a one-to-many 
relationship between cars and reservations, and a many-to-one relationship between customers and 
reservations. In addition, there are composition relationships between the Car and Reservation classes, 
the Reservation and Rental Agreement classes, the Rental Agreement and Invoice classes, and the 
Invoice and CarRentalSystem classes.
