#include "Command.hpp"
#include "./../Player.hpp"
#include "./../Instance.hpp"
#include "./../Drug.hpp"

class CommandBuyDrug : public Command
{
    Player &player;
    Instance &instance;

public:
    CommandBuyDrug(Player &player_, Instance &instance_) : player{player_}, instance{instance_}
    {
    }
    void call() override
    {
        Drug drug_to_buy;
        int current_amount = 0;
        int max_amount_to_buy = 0;
        int actualy_max_amount = 0;
        string drug_name;
        cout << "What drug you want to buy: ";
        cin >> drug_name;
        drug_to_buy = instance.drugList.get_drug(drug_name);
        max_amount_to_buy = player.GetManey() / drug_to_buy.get_price();
        if (max_amount_to_buy > player.GetCapacity())
            actualy_max_amount = player.GetCapacity();
        else
            actualy_max_amount = max_amount_to_buy;
        cout << "How much you want to buy: (you can max buy: " << actualy_max_amount << "): " << endl;
        while (cin >> current_amount)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
            }
            if (current_amount > drug_to_buy.get_amount())
            {
                cin.clear(std::ios_base::failbit);
            }
            if
        }
        drug_to_buy.set_amount(current_amount);
        drug_to_buy = instance.sell_drug(drug_to_buy);
        player.playersDrugs.add_or_update_drug(drug_to_buy);
        player.substract_maney(drug_to_buy.get_amount() * drug_to_buy.get_price());         
    }
};

