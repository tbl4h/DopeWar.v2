    #pragma once
    #include <iostream>
    using namespace std;
    enum class Drugs
    {
        Cocaine,
        Heroine,
        Speed,
        Weed,
        count
    };
    enum class InstanceState {
        ListDrugs,
        BuyDrug,
        SellDrug,
        ShowPlayer,
        ShowMap,
        ExitGame
    };

    inline ostream& operator<<(ostream& os, const InstanceState& state){
        switch (state){
            case InstanceState::ListDrugs:
                os << "List drugs: ";
                break;
            case InstanceState::BuyDrug:
                os << "Buy drugs: ";
                break;
            case InstanceState::SellDrug:
                os << "Sell drugs: ";
                break;
            case InstanceState::ShowPlayer:
                os << "Show player stuff: ";
                break;
            case InstanceState::ShowMap:
                os << "Show map location: ";
                break;
            case InstanceState::ExitGame:
                os << "Exit game.";
                break;
        }
    }

    enum class InstanceStateTrigger {
        ToListDrug,
        ToBuyDrug,
        ToSellDrug,
        ToShowPlayer,
        ToShowMap,
        ToExit
    };

    inline ostream& operator<<(ostream& os, const InstanceStateTrigger& state_trigger){
        switch (state_trigger) {
            case InstanceStateTrigger::ToListDrug:
                os << "List drugs.";
                break;
            case InstanceStateTrigger::ToBuyDrug:
                os << "To buy.";
                break;
            case InstanceStateTrigger::ToSellDrug:
                os << "To sell.";
                break;
            case InstanceStateTrigger::ToShowPlayer:
                os << "To show player stuff.";
                break;
            case InstanceStateTrigger::ToShowMap:
                os << "To show map locations.";
                break;
            case InstanceStateTrigger::ToExit:
                os << "To exit game.";
                break;
        }
        return os;
    }

    enum class Location {
        Bronx,
        Brooklyn,
        Manhatan,
        Ghetto,
        Instance,
        Player,
        ExitGame,
        count
    };

    inline ostream& operator<<(ostream& os, const Location& location) {
        switch (location) {
            case Location::Bronx:
                os << "Bronx";
                break;
            case Location::Brooklyn:
                os << "Brooklyn";
                break;
            case Location::Ghetto: 
                os << "Ghetto";
                break;
            case Location::Manhatan:
                os << "Manhatan";
                break;
            case Location::Instance:
                os << "You are in location.";
                break;
            case Location::Player:
                os << "You are look at yourself.";
                break;
            case Location::ExitGame:
                os << "Exit Game.";
                break;
        }
        return os;
    }

    enum class LocationTrigger {
        ToBronx,
        ToBrooklyn,
        ToManhatan,
        ToGhetto,
        ToInstance,
        ToPlayer,
        ToExit
    };

inline ostream& operator<<(ostream& os , const LocationTrigger& trigger){
    switch (trigger){
        case LocationTrigger::ToBronx:
            os << "To Bronx.";
            break;
        case LocationTrigger::ToBrooklyn:
            os << "To Brooklyn.";
            break;
        case LocationTrigger::ToGhetto:
            os << "To Ghetto.";
            break;
        case LocationTrigger::ToManhatan:
            os << "To Manhatan.";
            break;
        case LocationTrigger::ToInstance:
            os << "To instance menu.";
            break;
        case LocationTrigger::ToPlayer:
            os << "To player menu.";
            break;
        case LocationTrigger::ToExit:
            os << "To exit.";
            break;
    }
    return os;
}