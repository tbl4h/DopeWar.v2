#include "./Instance.hpp"

class Map {
    private:
    public:
        vector<Instance> allInstance;
        Map() {
            allInstance.push_back(Location::Bronx);
            allInstance.push_back(Location::Brooklyn);
            allInstance.push_back(Location::Manhatan);
            allInstance.push_back(Location::Ghetto);
        }
};