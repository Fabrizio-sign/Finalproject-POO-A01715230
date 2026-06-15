#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "Passenger.hpp"
#include "Employee.hpp"
#include "Flight.hpp"
#include "Reservation.hpp"

using namespace std;

// Global data storage (simplified)
vector<Passenger> passengers;
vector<Employee> employees;
vector<Flight> flights;
vector<Reservation> reservations;

int nextPassengerId = 1;
int nextEmployeeId = 1000;
int nextFlightNumber = 101;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void registerPassenger() {
    string name;
    cout << "Enter passenger name: ";
    cin.ignore();
    getline(cin, name);
    passengers.emplace_back(name, nextPassengerId++);
    cout << "Passenger registered with ID: " << nextPassengerId - 1 << endl;
}

void registerEmployee() {
    string name;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, name);
    employees.emplace_back(name, nextEmployeeId++);
    cout << "Employee registered with ID: " << nextEmployeeId - 1 << endl;
}

void createFlight() {
    string dest;
    int seats;
    cout << "Enter destination: ";
    cin.ignore();
    getline(cin, dest);
    cout << "Enter number of seats: ";
    cin >> seats;
    flights.emplace_back(nextFlightNumber++, dest, seats);
    cout << "Flight " << nextFlightNumber - 1 << " created to " << dest << " with " << seats << " seats.\n";
}

void makeReservation() {
    if (passengers.empty()) {
        cout << "No passengers registered. Please register a passenger first.\n";
        return;
    }
    if (flights.empty()) {
        cout << "No flights available. Create a flight first.\n";
        return;
    }

    cout << "Available passengers:\n";
    for (size_t i = 0; i < passengers.size(); ++i) {
        cout << i+1 << ". " << passengers[i].getName() << " (ID: " << passengers[i].getId() << ")\n";
    }
    int pChoice;
    cout << "Select passenger number: ";
    cin >> pChoice;
    if (pChoice < 1 || pChoice > (int)passengers.size()) {
        cout << "Invalid choice.\n";
        return;
    }
    Passenger* selectedPassenger = &passengers[pChoice-1];

    cout << "Available flights:\n";
    for (size_t i = 0; i < flights.size(); ++i) {
        cout << i+1 << ". Flight " << flights[i].getFlightNumber() << " to " << flights[i].getDestination() << "\n";
    }
    int fChoice;
    cout << "Select flight number: ";
    cin >> fChoice;
    if (fChoice < 1 || fChoice > (int)flights.size()) {
        cout << "Invalid choice.\n";
        return;
    }
    Flight* selectedFlight = &flights[fChoice-1];

    selectedFlight->displaySeats();
    int seatNum;
    cout << "Enter seat number to reserve: ";
    cin >> seatNum;
    if (selectedFlight->reserveSeat(seatNum)) {
        reservations.emplace_back(selectedPassenger, selectedFlight, seatNum);
        cout << "Reservation confirmed for " << selectedPassenger->getName()
             << " on flight " << selectedFlight->getFlightNumber() << " seat " << seatNum << endl;
    } else {
        cout << "Seat not available or invalid.\n";
    }
}

void cancelReservation() {
    if (reservations.empty()) {
        cout << "No reservations to cancel.\n";
        return;
    }
    cout << "Current reservations:\n";
    for (size_t i = 0; i < reservations.size(); ++i) {
        cout << i+1 << ". " << reservations[i].getPassenger()->getName()
             << " - Flight " << reservations[i].getFlight()->getFlightNumber()
             << " - Seat " << reservations[i].getSeatNumber() << endl;
    }
    int choice;
    cout << "Select reservation to cancel: ";
    cin >> choice;
    if (choice < 1 || choice > (int)reservations.size()) {
        cout << "Invalid.\n";
        return;
    }
    auto& res = reservations[choice-1];
    Flight* flight = res.getFlight();
    int seat = res.getSeatNumber();
    if (flight->cancelSeat(seat)) {
        cout << "Reservation cancelled.\n";
        reservations.erase(reservations.begin() + choice - 1);
    } else {
        cout << "Error cancelling seat.\n";
    }
}

int main() {
    int option;
    do {
        cout << "\n--- Regional Airline Management System ---\n";
        cout << "1. Register Passenger\n";
        cout << "2. Register Employee\n";
        cout << "3. Create Flight\n";
        cout << "4. Make Reservation\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1: registerPassenger(); break;
            case 2: registerEmployee(); break;
            case 3: createFlight(); break;
            case 4: makeReservation(); break;
            case 5: cancelReservation(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n"; break;
        }
    } while (option != 6);

    return 0;
}
