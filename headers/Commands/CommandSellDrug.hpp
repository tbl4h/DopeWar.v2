#include "Command.hpp"
#include "./../Player.hpp"
#include "./../Instance.hpp"
#include "./../Drug.hpp"

class CommandSellDrug : public Command
{
    Player &player;
    Instance &instance;

public:
    CommandSellDrug(Player &player_, Instance &instance_) : player{player_}, instance{instance_}
    {
    }
    void call() override
    {
        Drug drug_to_sell;
        int current_amount = 0;
        int maney_for_drug = 0;
        string drug_name;
        cout << "What drug you want to sell? " << endl;
        cin >> drug_name;
        drug_to_sell = player.playersDrugs.get_drug(drug_name);
        if (drug_to_sell.get_name().c_str() != "empty")
        {
            cout << "How much you want to sell (max amount you can is " << drug_to_sell.get_amount() << "): ";
            while (cin >> current_amount)
            {
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                if(current_amount > drug_to_sell.get_amount()){
                    cin.clear(std::ios_base::failbit);
                }
            }
            drug_to_sell = player.playersDrugs.sell_drug(drug_to_sell);
            maney_for_drug = instance.buy_drug(drug_to_sell);
            player.playersDrugs.update_drug(drug_to_sell);
            player.add_maney(maney_for_drug);
        }
    }
};