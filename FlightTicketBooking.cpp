#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
        if (availableSeats > 0 && availableSeats >= count) {
            availableSeats -= count;
            cout << "Seat booked successfully." << endl;
            cout << "Remaining seats: " << availableSeats << endl;
        }
        else {
            cout << "Sorry, no seats available on that flight." << endl;
            cout << "Remaining seats: " << availableSeats << endl;
        }
    }
};

class Node {
public:
    Flight* flight;
    Node* left;
    Node* right;

    Node(Flight* flight)
        : flight(flight), left(nullptr), right(nullptr) {}
};

class SplayTree {
private:
    Node* root;

    Node* splay(Node* root, const string& flightNumber) {
        if (root == nullptr || root->flight->getFlightNumber() == flightNumber)
            return root;

        if (flightNumber < root->flight->getFlightNumber()) {
            if (root->left == nullptr)
                return root;
            
            if (flightNumber < root->left->flight->getFlightNumber()) {
                root->left->left = splay(root->left->left, flightNumber);
                root = rotateRight(root);
            }
            else if (flightNumber > root->left->flight->getFlightNumber()) {
                root->left->right = splay(root->left->right, flightNumber);
                if (root->left->right != nullptr)
                    root->left = rotateLeft(root->left);
            }

            if (root->left == nullptr)
                return root;
            else
                return rotateRight(root);
        }
        else {
            if (root->right == nullptr)
                return root;

            if (flightNumber < root->right->flight->getFlightNumber()) {
                root->right->left = splay(root->right->left, flightNumber);
                if (root->right->left != nullptr)
                    root->right = rotateRight(root->right);
            }
            else if (flightNumber > root->right->flight->getFlightNumber()) {
                root->right->right = splay(root->right->right, flightNumber);
                root = rotateLeft(root);
            }

            if (root->right == nullptr)
                return root;
            else
                return rotateLeft(root);
        }
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }

    Node* findNode(Node* root, const string& flightNumber) {
        root = splay(root, flightNumber);
        if (root == nullptr || root->flight->getFlightNumber() != flightNumber)
            return nullptr;

        return root;
    }

public:
    SplayTree() : root(nullptr) {}

    void insertFlight(const Flight& flight) {
        Flight* newFlight = new Flight(flight);
        Node* newNode = new Node(newFlight);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        root = splay(root, flight.getFlightNumber());

        if (flight.getFlightNumber() < root->flight->getFlightNumber()) {
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
            root = newNode;
        }
        else if (flight.getFlightNumber() > root->flight->getFlightNumber()) {
            newNode->right = root->right;
            newNode->left = root;
            root->right = nullptr;
            root = newNode;
        }
        else {
            delete newFlight;
            delete newNode;
        }
    }

    Flight* findFlight(const string& flightNumber) {
        root = splay(root, flightNumber);
        if (root == nullptr || root->flight->getFlightNumber() != flightNumber)
            return nullptr;

        return root->flight;
    }

    void displayFlights() const {
        inorderTraversal(root);
    }

    void inorderTraversal(Node* root) const {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << "Flight Number: " << root->flight->getFlightNumber() << endl;
            cout << "Source: " << root->flight->getSource() << endl;
            cout << "Destination: " << root->flight->getDestination() << endl;
            cout << "Available Seats: " << root->flight->getAvailableSeats() << endl;
            cout << "--------------------------------------" << endl;
            inorderTraversal(root->right);
        }
    }
};

int main() {
    SplayTree reservationSystem;

    // Adding sample flights to the system
    reservationSystem.insertFlight(Flight("ABC123", "Chennai", "Goa", 10));
    reservationSystem.insertFlight(Flight("DEF456", "Chennai", "Coimbatore", 10));
    reservationSystem.insertFlight(Flight("GHI789", "Chennai", "Delhi", 20));

    // Display available flights
    reservationSystem.displayFlights();

    // Perform a reservation
    string a = "yes";
    while (a == "yes") {
        string flightNumber;
        int ticketCount, b = 1;
        cout << "Enter the flight number for reservation: ";
        cin >> flightNumber;
        while (b == 1) {
            cout << "How many tickets do you want to book: ";
            cin >> ticketCount;

            if (ticketCount <= 5) {
                Flight* flight = reservationSystem.findFlight(flightNumber);
                if (flight != nullptr) {
                    flight->bookSeat(ticketCount);
                }
                else {
                    cout << "Flight not found." << endl;
                }
            }
            else {
                cout << "Sorry! You can't book more than 5 tickets." << endl;
            }
            
            cout << "Do you want to continue booking from the same flight (press 1): ";
            cin >> b;
        }
        
        cout << "Do you want to book a ticket from another flight (press 'yes'): ";
        cin >> a;
    }
    cout<<"\nAVAILABILITY : \n";
    reservationSystem.displayFlights();
    return 0;
}
