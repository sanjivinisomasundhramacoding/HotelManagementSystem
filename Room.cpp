#include "Room.h"
#include <iostream>

using namespace std;

Room::Room()
{
    roomNumber = 0;
    roomType = "";
    price = 0.0;
    available = true;
}

Room::Room(int number, string type, double price)
{
    roomNumber = number;
    roomType = type;
    this->price = price;
    available = true;
}

int Room::getRoomNumber() const
{
    return roomNumber;
}

string Room::getRoomType() const
{
    return roomType;
}

double Room::getPrice() const
{
    return price;
}

bool Room::isAvailable() const
{
    return available;
}

void Room::bookRoom()
{
    if (available)
    {
        available = false;
        cout << "Room booked successfully.\n";
    }
    else
    {
        cout << "Room is already booked.\n";
    }
}

void Room::checkoutRoom()
{
    available = true;
    cout << "Room is now available.\n";
}

void Room::displayRoom() const
{
    cout << "Room Number : " << roomNumber << endl;
    cout << "Room Type   : " << roomType << endl;
    cout << "Price       : Rs. " << price << endl;
    cout << "Status      : "
         << (available ? "Available" : "Booked") << endl;
}