#include <Player.hpp>
#include <Map.hpp>
#include <Enum.hpp>
#include <Instance.hpp>
#include <map>
#include "./Commands/FactoryCommand.hpp"
class Game
{
    Player player;
    Map game_map;
    Instance current_instance;
    Location current_location = Location::Ghetto;
    Location exit_game_location = Location::ExitGame;
    InstanceState current_state = InstanceState::ListDrugs;
    InstanceState exit_game_state = InstanceState::ExitGame;
    CommandFactory command_factory;
    map<Location, vector<pair<LocationTrigger, Location>>> map_rules;
    map<InstanceState, vector<pair<InstanceStateTrigger, InstanceState>>> instance_rules;
    void init_map_rules()
    {
        map_rules[Location::Bronx] = {
            {LocationTrigger::ToBrooklyn, Location::Brooklyn},
            {LocationTrigger::ToGhetto, Location::Ghetto},
            {LocationTrigger::ToManhatan, Location::Manhatan},
            {LocationTrigger::ToInstance, Location::Instance},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToPlayer, Location::Player}};
        map_rules[Location::Brooklyn] = {
            {LocationTrigger::ToGhetto, Location::Ghetto},
            {LocationTrigger::ToBronx, Location::Bronx},
            {LocationTrigger::ToManhatan, Location::Manhatan},
            {LocationTrigger::ToInstance, Location::Instance},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToPlayer, Location::Player}};
        map_rules[Location::Ghetto] = {
            {LocationTrigger::ToManhatan, Location::Manhatan},
            {LocationTrigger::ToBrooklyn, Location::Brooklyn},
            {LocationTrigger::ToBronx, Location::Bronx},
            {LocationTrigger::ToInstance, Location::Instance},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToPlayer, Location::Player}};
        map_rules[Location::Manhatan] = {
            {LocationTrigger::ToInstance, Location::Instance},
            {LocationTrigger::ToGhetto, Location::Ghetto},
            {LocationTrigger::ToBrooklyn, Location::Brooklyn},
            {LocationTrigger::ToBronx, Location::Bronx},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToPlayer, Location::Player}};
        map_rules[Location::Instance] = {
            {LocationTrigger::ToManhatan, Location::Manhatan},
            {LocationTrigger::ToGhetto, Location::Ghetto},
            {LocationTrigger::ToBrooklyn, Location::Brooklyn},
            {LocationTrigger::ToBronx, Location::Bronx},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToPlayer, Location::Player}};
        map_rules[Location::Player] = {
            {LocationTrigger::ToManhatan, Location::Manhatan},
            {LocationTrigger::ToGhetto, Location::Ghetto},
            {LocationTrigger::ToBrooklyn, Location::Brooklyn},
            {LocationTrigger::ToBronx, Location::Bronx},
            {LocationTrigger::ToExit, Location::ExitGame},
            {LocationTrigger::ToInstance, Location::Instance}};
    }
    void init_instance_rules()
    {
        instance_rules[InstanceState::ListDrugs] = {
            {InstanceStateTrigger::ToBuyDrug, InstanceState::BuyDrug},
            {InstanceStateTrigger::ToSellDrug, InstanceState::SellDrug},
            {InstanceStateTrigger::ToShowMap, InstanceState::ShowMap},
            {InstanceStateTrigger::ToShowPlayer, InstanceState::ShowPlayer}};
        instance_rules[InstanceState::BuyDrug] = {
            {InstanceStateTrigger::ToListDrug, InstanceState::ListDrugs},
            {InstanceStateTrigger::ToSellDrug, InstanceState::SellDrug},
            {InstanceStateTrigger::ToShowMap, InstanceState::ShowMap},
            {InstanceStateTrigger::ToShowPlayer, InstanceState::ShowPlayer}};
        instance_rules[InstanceState::SellDrug] = {
            {InstanceStateTrigger::ToBuyDrug, InstanceState::BuyDrug},
            {InstanceStateTrigger::ToListDrug, InstanceState::ListDrugs},
            {InstanceStateTrigger::ToShowMap, InstanceState::ShowMap},
            {InstanceStateTrigger::ToShowPlayer, InstanceState::ShowPlayer}};
        instance_rules[InstanceState::ShowMap] = {
            {InstanceStateTrigger::ToBuyDrug, InstanceState::BuyDrug},
            {InstanceStateTrigger::ToListDrug, InstanceState::ListDrugs},
            {InstanceStateTrigger::ToSellDrug, InstanceState::SellDrug},
            {InstanceStateTrigger::ToShowPlayer, InstanceState::ShowPlayer}};
        instance_rules[InstanceState::ShowPlayer] = {
            {InstanceStateTrigger::ToBuyDrug, InstanceState::BuyDrug},
            {InstanceStateTrigger::ToListDrug, InstanceState::ListDrugs},
            {InstanceStateTrigger::ToSellDrug, InstanceState::SellDrug},
            {InstanceStateTrigger::ToShowMap, InstanceState::ShowMap}};
    }

public:
    Game() : current_instance{Location::Ghetto} {};
    void play()
    {
        init_map_rules();
        while (true)
        {
            cout << "You are in" << current_location << endl;
        select_map_trigger:
            cout << "Wybierz wyzwalacz:"
                 << "\n";

            int i = 0;
            for (auto item : map_rules[current_location])
            {
                cout << i++ << ". " << item.first << "\n";
            }

            int input;
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
            }
            if (input < 0 || (input + 1) > map_rules[current_location].size())
            {
                cout << "Niepoprawna opcja. Spr¢buj jeszcze raz."
                     << "\n";
                goto select_map_trigger;
            }

            current_location = map_rules[current_location][input].second;
            if (current_location == exit_game_location)
                    exit(0);
            game_map.roll_instance(current_location);
            if (current_location == Location::Instance)
            {
                while (true)
                {
                    cout << "You are in" << current_state << endl;
                select_state_trigger:
                    cout << "Wybierz wyzwalacz:"
                         << "\n";

                    int i = 0;
                    for (auto item : instance_rules[current_state])
                    {
                        cout << i++ << ". " << item.first << "\n";
                    }

                    int input;
                    cin >> input;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                    }
                    if (input < 0 || (input + 1) > instance_rules[current_state].size())
                    {
                        cout << "Niepoprawna opcja. Spr¢buj jeszcze raz."
                             << "\n";
                        goto select_state_trigger;
                    }

                }
                if (current_location == exit_game_location)
                    exit(0);
            }
        }
    }
};