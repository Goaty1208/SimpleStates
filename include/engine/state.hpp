#include "IDtypes.hpp"
#include "governments.hpp"
#include <vector>
#include <string>

#ifndef STATE_HPP
#define STATE_HPP

static stateID lastID = 0;

typedef char nationality[32];

class state{

    private:

    public:
        //Variables
        
        char name[32] = "Land of the Debugging";
        std::string info = "default";
        nationality nationalityName = "Debuggian";
        stateID ID = lastID++;

        humanID leaderID;
        ideologyGradient ideology = {0, 0, 0, 0};

        int population;
        uint16_t age;

        std::vector<regionID>* regions = nullptr;
        std::vector<humanID>* inhabitants = nullptr;

        //Functions
        state(/* args */);
        ~state();
};

state::state(){

}

state::~state(){

}

std::vector<state> nations;

#endif