#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Flight class represents a single flight
class Flight {
private:
    string flightNumber;
    string source;
    string destination;
    int availableSeats;

public:
    Flight(string flightNumber, string source, string destination, int availableSeats)
        : flightNumber(flightNumber), source(source), destination(destination), availableSeats(availableSeats) {}

    string getFlightNumber() const {
        return flightNumber;
    }

    string getSource() const {
        return source;
    }

    string getDestination() const {
        return destination;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void bookSeat(int count) {
        if (availableSeats > 0) {
            if(availableSeats-count>=0){
                availableSeats-=count;
                cout << "Seat booked successfully." << endl;
                cout << "Remaining seats:" << availableSeats << endl;
            }
            else{
                    cout<< "Sorry you ticket can't book . you ticket count is more than the avilable ticket!!!\n";
                    cout << "Remaining seats:" <<availableSeats <<endl;
                }
        }
            
        else {
            cout << "No seats available on that flight." << endl;
            cout << "Remaining seats:" <<availableSeats <<endl;
        }
    }
};

// ReservationSystem class manages multiple flights and reservations
class ReservationSystem {
private:
    vector<Flight> flights;

public:
    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    void displayFlights() const {
        cout << "Available Flights:" << endl;
        for (const Flight& flight : flights) {
            cout << "Flight Number: " << flight.getFlightNumber() << endl;
            cout << "Source: " << flight.getSource() << endl;
            cout << "Destination: " << flight.getDestination() << endl;
            cout << "Available Seats: " << flight.getAvailableSeats() << endl;
            cout << "--------------------------------------" << endl;
        }
    }

    Flight* findFlight(const string& flightNumber) {
        for (Flight& flight : flights) {
            if (flight.getFlightNumber() == flightNumber) {
                return &flight;
            }
        }
        return nullptr;
    }
};

int main() {
    ReservationSystem reservationSystem;

    // Adding sample flights to the system
    reservationSystem.addFlight(Flight("ABC123", "New York", "Los Angeles", 10));
    reservationSystem.addFlight(Flight("DEF456", "Chicago", "Houston", 10));
    reservationSystem.addFlight(Flight("GHI789", "Seattle", "Denver", 20));

    // Display available flights
    reservationSystem.displayFlights();

    // Perform a reservation
    string a="yes";
    while(a=="yes"){
        string flightNumber;
        int ticket_count,b=1;
        cout << "Enter the flight number for reservation: ";
        cin >> flightNumber;
        while(b==1){
            cout << "How many tickets do you want to book :";
            cin >> ticket_count;

            if(ticket_count<=5){
                Flight* flight = reservationSystem.findFlight(flightNumber);
                if (flight != nullptr) {
                flight->bookSeat(ticket_count);
                } else {
                    cout << "Flight not found." << endl;
                }
            }
            else{
                cout<<"Sorry!!!you can't book more than 5 ticket \n";
            }
            cout << "do you want to continue the book from the same flight:\npress 1:";
            cin >> b;
        }
        
        cout << "Do you want to book the ticket from other flight:\npress yes :";
        cin >> a;
    }
    

    return 0;
}
