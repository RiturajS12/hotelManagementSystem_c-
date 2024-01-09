#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Room {
public:
    int roomNumber;
    bool isOccupied;
    double rate;

    Room(int number, double rate) : roomNumber(number), rate(rate), isOccupied(false) {}

    void display() const {
        cout << "Room Number: " << roomNumber << "\tRate: $" << rate << "\tStatus: " << (isOccupied ? "Occupied" : "Available") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int numRooms, double rate) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i, rate));
        }
    }

    void displayRooms() const {
        cout << "Room List:" << endl;
        for (const Room& room : rooms) {
            room.display();
        }
    }

    bool reserveRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNumber && !room.isOccupied) {
                room.isOccupied = true;
                cout << "Room " << roomNumber << " reserved successfully." << endl;
                return true;
            }
        }
        cout << "Room " << roomNumber << " is not available." << endl;
        return false;
    }

    bool checkOut(int roomNumber) {
        for (Room& room : rooms) {
            if (room.roomNumber == roomNumber && room.isOccupied) {
                room.isOccupied = false;
                cout << "Checked out from Room " << roomNumber << ". Thank you for staying with us." << endl;
                return true;
            }
        }
        cout << "Room " << roomNumber << " is not occupied or does not exist." << endl;
        return false;
    }
};

int main() {
    Hotel myHotel(10, 100);

    int choice;
    do {
        cout << "\n1. Display Room List\n2. Reserve Room\n3. Check Out\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myHotel.displayRooms();
                break;

            case 2:
                int roomNumberToReserve;
                cout << "Enter room number to reserve: ";
                cin >> roomNumberToReserve;
                myHotel.reserveRoom(roomNumberToReserve);
                break;

            case 3:
                int roomNumberToCheckOut;
                cout << "Enter room number to check out: ";
                cin >> roomNumberToCheckOut;
                myHotel.checkOut(roomNumberToCheckOut);
                break;

            case 4:
                cout << "Exiting the Hotel Management System." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
