#include <iostream>
#include <vector>
#include <fstream>
#include "Room.h"
#include "Customer.h"

using namespace std;

vector<Room> rooms;
vector<Customer> customers;

void initializeRooms()
{
    rooms.push_back(Room(101, "Single", 1500));
    rooms.push_back(Room(102, "Single", 1500));
    rooms.push_back(Room(201, "Double", 2500));
    rooms.push_back(Room(202, "Double", 2500));
    rooms.push_back(Room(301, "Deluxe", 4000));
}

void displayRooms()
{
    cout << "\n===== ROOM DETAILS =====\n";

    for (const Room& room : rooms)
    {
        room.displayRoom();
        cout << "------------------------\n";
    }
}

void bookRoom()
{
    int roomNumber;

    cout << "\nEnter Room Number: ";
    cin >> roomNumber;

    for (Room& room : rooms)
    {
        if (room.getRoomNumber() == roomNumber)
        {
            if (!room.isAvailable())
            {
                cout << "Room is already booked!\n";
                return;
            }

            int customerId;
            string name;
            string phone;

            cout << "Enter Customer ID: ";
            cin >> customerId;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, name);

            cout << "Enter Phone Number: ";
            getline(cin, phone);

            room.bookRoom();

            customers.push_back(
                Customer(customerId, name, phone, roomNumber)
            );

            cout << "Booking completed successfully!\n";
            return;
        }
    }

    cout << "Room not found!\n";
}

void checkoutRoom()
{
    int roomNumber;

    cout << "\nEnter Room Number for Checkout: ";
    cin >> roomNumber;

    for (Room& room : rooms)
    {
        if (room.getRoomNumber() == roomNumber)
        {
            if (room.isAvailable())
            {
                cout << "Room is not currently booked.\n";
                return;
            }

            room.checkoutRoom();

            cout << "Checkout completed successfully!\n";
            return;
        }
    }

    cout << "Room not found!\n";
}

void searchCustomer()
{
    int customerId;

    cout << "\nEnter Customer ID: ";
    cin >> customerId;

    for (const Customer& customer : customers)
    {
        if (customer.getCustomerId() == customerId)
        {
            cout << "\n===== CUSTOMER DETAILS =====\n";
            customer.displayCustomer();
            return;
        }
    }

    cout << "Customer not found!\n";
}

void displayCustomers()
{
    cout << "\n===== CUSTOMER RECORDS =====\n";

    if (customers.empty())
    {
        cout << "No customer records found.\n";
        return;
    }

    for (const Customer& customer : customers)
    {
        customer.displayCustomer();
        cout << "----------------------------\n";
    }
}

void saveData()
{
    ofstream roomFile("rooms.txt");
    ofstream customerFile("customers.txt");

    if (!roomFile || !customerFile)
    {
        cout << "Error opening files!\n";
        return;
    }

    for (const Room& room : rooms)
    {
        roomFile << room.getRoomNumber() << "|"
                 << room.getRoomType() << "|"
                 << room.getPrice() << "|"
                 << room.isAvailable() << "\n";
    }

    for (const Customer& customer : customers)
    {
        customerFile << customer.getCustomerId() << "|"
                     << customer.getName() << "|"
                     << customer.getPhone() << "|"
                     << customer.getRoomNumber() << "\n";
    }

    roomFile.close();
    customerFile.close();

    cout << "Data saved successfully!\n";
}

int main()
{
    initializeRooms();

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "      HOTEL MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout\n";
        cout << "4. Search Customer\n";
        cout << "5. Display Customers\n";
        cout << "6. Save Data\n";
        cout << "7. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayRooms();
            break;

        case 2:
            bookRoom();
            break;

        case 3:
            checkoutRoom();
            break;

        case 4:
            searchCustomer();
            break;

        case 5:
            displayCustomers();
            break;

        case 6:
            saveData();
            break;

        case 7:
            saveData();
            cout << "Thank you for using Hotel Management System!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}