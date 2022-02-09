#include "DrugsList.hpp"

class Player {

    string name;
    int maney;
    int capacity;
    int life;
    int domage;
    public:
    DrugsList playersDrugs;
    void set_name(string name_) {
        name = name_;
    }
    string get_name() const {
        return name;
    }

    int GetManey() const {
    return maney;
    }

    void SetManey(int maney_) {        
    maney = maney_;
    }

    int GetCapacity() const {
    return capacity;
    }

    void SetCapacity(int capacity_) {
    capacity = capacity_;
    }

    int GetLife() const {
    return life;
    }

    void SetLife(int life_) {
        life = life_;
    }

    int GetDomage() const {
    return domage;
    }

    void SetDomage(int domage_) {
    domage = domage_;
    }
    void add_capacity(int value) {
        capacity += value; 
    }
    void substract_capacity(int value) {
        capacity -= value;
    }
    void heal(int value) {
        life += value;
        if(life > 100)
            life = 100;
    }
    void add_maney(int value) {
        maney += value;
    }
    void substract_maney(int value) {
        maney -= value;
    }
};