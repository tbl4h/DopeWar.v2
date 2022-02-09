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
        void roll_instance(const Location& current_location){
            for(auto instance : allInstance){
                if(instance.get_name() == current_location)
                    instance.init_or_update();
            }
        }
};