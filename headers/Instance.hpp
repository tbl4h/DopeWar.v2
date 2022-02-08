#pragma once
#include "DrugsList.hpp"
#include <random>
#include <array>
class Instance
{
private:
    Location location_name = Location::Ghetto;
    int roll_number(int start, int end)
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(start, end);
        return dist(rng);
    }
    int roll_price(Drugs drug_name)
    {
        switch (drug_name)
        {
        case Drugs::Cocaine:
            return roll_number(500, 3000);
        case Drugs::Heroine:
            return roll_number(300, 2500);
        case Drugs::Speed:
            return roll_number(150, 1500);
        case Drugs::Weed:
            return roll_number(30, 150);
        }
    }
    float apply_instatnion_bonus(Location location)
    {
        switch (location)
        {
        case Location::Bronx:
            return 1.1;
        case Location::Brooklyn:
            return 1.15;
        case Location::Ghetto:
            return 1.0;
        case Location::Manhatan:
            return 1.3;
        }
    }
    string named_drugs(Drugs drug_name)
    {
        switch (drug_name)
        {
        case Drugs::Cocaine:
            return "Cocaine";
        case Drugs::Heroine:
            return "Heroine";
        case Drugs::Speed:
            return "Speed";
        case Drugs::Weed:
            return "Weed";
        }
    }
    Drugs name_to_enum(const string &drug_name)
    {
        if (drug_name == "Cocaine")
            return Drugs::Cocaine;
        if (drug_name == "Heroine")
            return Drugs::Heroine;
        if (drug_name == "Speed")
            return Drugs::Speed;
        if (drug_name == "Weed")
            return Drugs::Weed;
    }

public:
    DrugsList drugList;
    void init_or_update()
    {
        while (drugList.size() <= 2)
        {
            Drugs tmp = static_cast<Drugs>(roll_number(0, Drugs::count - 1));
            drugList.add_drug(named_drugs(tmp));
        }
        for (auto o : drugList)
        {
            int price = roll_price(name_to_enum(o.get_name())) * apply_instatnion_bonus(this->location_name);
            o.set_price(price);
            o.set_amount(1000);
        }
    }
    void set_name(Location name_)
    {
        location_name = name_;
    }
    Location get_name() const
    {
        return location_name;
    }
    Drug sell_drug(Drug &obj)
    {
        return drugList.sell_drug(obj);
    }
    int buy_drug(Drug &obj)
    {
        return drugList.buy_drug(obj);
    }
    void list_drugs()
    {
        drugList.list_drugs();
    }
};
