#include "Location.h"
#include <cstdlib>

std::shared_ptr<Creatures_Factory> Location::orc_factory = std::make_shared<Orcs_Factory>();
std::shared_ptr<Creatures_Factory> Location::hobbit_factory = std::make_shared<Hobbit_Factory>();
std::shared_ptr<Creatures_Factory> Location::human_factory = std::make_shared<Human_Factory>();

Location::Location(std::string location_name, 
                   std::string message, 
                   std::vector<CREATURE_TYPE>& types) : 
    location_name(location_name),
    message(message) {
        for (CREATURE_TYPE type : types) {
            if (type == ORC) {
                population_types.push_back(std::make_pair(type, orc_factory));
            }
            else if (type == HUMAN) {
                population_types.push_back(std::make_pair(type, human_factory));
            }
            else if (type == HOBBIT) {
                population_types.push_back(std::make_pair(type, hobbit_factory));
            }
        }
    }

std::shared_ptr<Creature> Location::Get_Creature() {
    if (population_types.size() == 1) {
        return population_types[0].second->Create_Creature();
    }
    srand(time(NULL));
    size_t type_index = rand() % population_types.size();
    return population_types[type_index].second->Create_Creature();
}

std::string Location::GetMessage() {
    return message;
}


std::string Location::GetName() {
    return location_name;
}


void Location::AddRoad(std::shared_ptr<Location> location) {
    roads_to.push_back(location);
}


const std::vector<std::shared_ptr<Location> >& Location::GetRoads() {
    return roads_to;
}