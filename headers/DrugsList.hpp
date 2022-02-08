#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Drug.hpp"

using namespace std;

class DrugsList
{
public:
    using Drugs_list = vector<Drug>;
    typedef std::vector<Drug> node_list;
    typedef node_list::const_iterator const_iterator;

private:
    Drugs_list drugsList;
    bool is_drug_exist(Drug &obj)
    {
        auto res = find_if(drugsList.begin(), drugsList.end(), [&obj](Drug &current)
                           {
                if(obj.get_name() == current.get_name() && 
                   obj.get_amount() == current.get_amount() &&
                   obj.get_price() == current.get_price())
                   return true;
                return false; });
        if (res != drugsList.end())
            return true;
        else
            return false;
    }

public:
    DrugsList() = default;
    DrugsList(DrugsList &cpy) = default;
    DrugsList(DrugsList &&rvr) : drugsList{move(rvr.drugsList)} {}

    void add_drug(Drug &obj)
    {
        if (!is_drug_exist(obj))
            drugsList.push_back(move(obj));
    }
    void add_drug(Drug &&obj)
    {
        if (!is_drug_exist(obj))
            drugsList.push_back(move(obj));
    }
    void update_drug(Drug &obj)
    {
        auto res = find_if(drugsList.begin(), drugsList.end(), [&obj](Drug &current)
                           {
                if(obj.get_name() == current.get_name())
                   return true;
                else
                   return false; });
        if (res != drugsList.end())
        {
            res->update_drug(obj);
        }
        else
            throw runtime_error("There no drug to update, try add.");
    }
    void remove_drug(Drug &obj)
    {
        auto res = find_if(drugsList.begin(), drugsList.end(), [&obj](Drug &current)
                           {
                if(obj.get_name() == current.get_name() && 
                   obj.get_amount() == current.get_amount() &&
                   obj.get_price() == current.get_price())
                   return true;
                return false; });
        if (res != drugsList.end())
        {
            Drugs_list tmp;
            for (auto o : drugsList)
            {
                if (o.get_name() == res->get_name())
                    continue;
                else
                    tmp.push_back(move(o));
            }
            drugsList.clear();
            for (auto o : tmp)
            {
                drugsList.push_back(move(o));
            }
        }
        else
            throw runtime_error("Can not remove drug.");
    }
    void update_drug_price(Drug &obj)
    {
        if (is_drug_exist(obj))
        {
            for (auto &o : drugsList)
            {
                if (obj.get_name() == o.get_name())
                {
                    o.set_price(obj.get_price());
                }
            }
        }
        else
            throw runtime_error("Can not update drug price");
    }
    void update_drug_amount(Drug &obj)
    {
        if (is_drug_exist(obj))
        {
            for (auto &o : drugsList)
            {
                if (obj.get_name() == o.get_name())
                {
                    o.set_amount(obj.get_amount());
                }
            }
        }
        else
            throw runtime_error("Can not update drug amount");
    }
    long unsigned int size() const
    {
        return drugsList.size();
    }
    const_iterator begin() const { return drugsList.begin(); }
    const_iterator end() const { return drugsList.end(); }

    Drug sell_drug(Drug &obj)
    {
        for (const auto o : drugsList)
        {
            if (o.get_name() == obj.get_name())
            {
                Drug tmp = o;
                tmp.set_amount(obj.get_amount());
                return tmp;
            }
        }
    }
    int buy_drug(Drug &obj)
    {
        for (const auto o : drugsList)
        {
            if (o.get_name() == obj.get_name())
            {
                int maney = obj.get_amount() * o.get_price();
                return maney;
            }
        }
    }
    void list_drugs(){
        for(const auto o : drugsList){
            cout << o.get_name() << " price: " << o.get_price() << " amount " << o.get_amount() << endl; 
        }
    }
};

/* To do refactor find if method */
