#pragma once
#include <string>
using namespace std;

class Customer
{
private:
    int customerId;
    string name;
    string phone;
    int roomNumber;

public:
    Customer();
    Customer(int id, string name, string phone, int roomNumber);

    int getCustomerId() const;
    string getName() const;
    string getPhone() const;
    int getRoomNumber() const;

    void displayCustomer() const;
};