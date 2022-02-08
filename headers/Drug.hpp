#pragma once
#include <string>
#include <iostream>
#include "Enum.hpp"

using namespace std;
class Drug
{
    string name;
    int price;
    int amount;

public:
    Drug() : name{"default"}, price{0}, amount{0} {};
    Drug(string name_, int price_, int amount_) : name{name_}, price{price_}, amount{amount_} {};
    Drug(string name_) : name{name_}, price{0}, amount{0} {};
    Drug(const Drug &rhs) : name{rhs.get_name()}, price{rhs.get_price()}, amount{rhs.get_amount()} {}
    Drug &operator=(Drug &rhs) = default;
    Drug(Drug &&rhs) : name{move(rhs.get_name())}, price{move(rhs.get_price())}, amount{move(rhs.get_amount())} {}
    Drug &operator=(Drug &&rhs)
    {
        if (this != addressof(rhs))
        {
            name = move(rhs.get_name());
            price = move(rhs.get_price());
            amount = move(rhs.get_amount());
        }
        return *this;
    }
    void set_price(int value)
    {
        if (value < 0)
            throw runtime_error("Value is less than zero.");
        else
            price = value;
    }
    int get_price() const
    {
        return price;
    }
    void set_amount(int value)
    {
        if (value < 0)
            throw runtime_error("Value is less than zero.");
        else
            amount = value;
    }
    int get_amount() const
    {
        return amount;
    }
    void set_name(const string &value)
    {
        name = value;
    }
    string get_name() const
    {
        return name;
    }

    friend ostream &operator<<(ostream &os, const Drug &obj)
    {
        return os << obj.name << " ilość: " << obj.amount << " wartość: " << obj.price;
    }
    friend istream &operator>>(istream &is, Drug &obj)
    {
        cout << "Podaj nazwę: ";
        is >> obj.name;
        cout << "\nPodaj ilość: ";
        is >> obj.amount;
        cout << "\nPodaj cenę: ";
        is >> obj.price;
        return is;
    }
    void update_drug(Drug &obj)
    {
        if (obj.name == this->name)
        {
            int current_price = this->amount * this->price;
            int add_price = obj.amount * obj.price;
            int total_amount = this->amount + obj.amount;
            this->amount = total_amount;
            this->price = (current_price + add_price) / total_amount;
        }
        else throw runtime_error("Can't update drug.");
    }
};