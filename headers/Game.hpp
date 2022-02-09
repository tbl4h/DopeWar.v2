#include <Player.hpp>
#include <Map.hpp>
#include <Enum.hpp>
#include <Instance.hpp>
#include <map>

class Game {
    Player player;
    Map game_map;
    Instance current_instance;
    map<Location, vector<pair<LocationTrigger, Location>>> map_rules;
};