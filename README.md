## 1. Problem Proposal
This project is designed to showcase an Object-Oriented Programming approach for managing a regional airline. The system establishes a class structure to handle the main entities involved in flight booking. OOP is essential here because the domain requires complex relationships (e.g., people making reservations for specific flights that contain a limited number of seats), which are best modeled using encapsulation, inheritance, and composition.

## 2. Build and Run Instructions
To compile the project, open your terminal and run the following command. Note that the C++14 standard and all warnings are explicitly enabled:

`g++ -std=c++14 -Wall main.cpp Person.cpp Passenger.cpp Employee.cpp Flight.cpp Seat.cpp Reservation.cpp`

**To run the program:**
* **Linux / macOS:** `./a.out`
* **Windows:** `a.exe`

## 3. Expected Sample Output
When running the program, a console-based menu will appear:
```text
--- Regional Airline Management System ---
1. Register Passenger
2. Register Employee
3. Create Flight
4. Make Reservation
5. Cancel Reservation
6. Exit
Select an option:
