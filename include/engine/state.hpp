#include "IDtypes.hpp"
#include "governments.hpp"
#include <vector>
#include <string>

#ifndef STATE_HPP
#define STATE_HPP

class state{

    private:

    public:
        //Variables
        
        char name[16] = "default";
        std::string info = "default";
        stateID ID = 0;

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


#endif