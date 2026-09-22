#pragma once
#include <string>
using namespace std;

class Room
{
private:
    int roomNumber;
    string roomType;
    double price;
    bool available;

public:
    Room();
    Room(int number, string type, double price);

    int getRoomNumber() const;
    string getRoomType() const;
    double getPrice() const;
    bool isAvailable() const;

    void bookRoom();
    void checkoutRoom();

    void displayRoom() const;
};