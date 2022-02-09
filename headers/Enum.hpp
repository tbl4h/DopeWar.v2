    #pragma once
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
        ShowMap
    };
    enum class InstanceStateTrigger {
        ToListDrug,
        ToBuyDrug,
        ToSellDrug,
        ToShowPlayer,
        ToShowMap,
    };
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
    }
    return os;
}