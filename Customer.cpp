#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer()
{
    customerId = 0;
    name = "";
    phone = "";
    roomNumber = 0;
}

Customer::Customer(int id, string name, string phone, int roomNumber)
{
    customerId = id;
    this->name = name;
    this->phone = phone;
    this->roomNumber = roomNumber;
}

int Customer::getCustomerId() const
{
    return customerId;
}

string Customer::getName() const
{
    return name;
}

string Customer::getPhone() const
{
    return phone;
}

int Customer::getRoomNumber() const
{
    return roomNumber;
}

void Customer::displayCustomer() const
{
    cout << "Customer ID : " << customerId << endl;
    cout << "Name        : " << name << endl;
    cout << "Phone       : " << phone << endl;
    cout << "Room Number : " << roomNumber << endl;
}