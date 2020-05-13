#pragma once
#include "interface_factory.h"
#include "creature_factory.h"
#include "Creatures.h"
#include <memory>
#include <vector>
#include <utility>

class Location {
protected:
    static std::shared_ptr<Creatures_Factory> orc_factory;
    static std::shared_ptr<Creatures_Factory> hobbit_factory;
    static std::shared_ptr<Creatures_Factory> human_factory;
    std::vector< std::shared_ptr<Location> > roads_to;
    std::vector< std::pair< CREATURE_TYPE,std::shared_ptr<Creatures_Factory> > > population_types;
    std::string location_name; 
    std::string message;
public:
    Location(std::string& location_name, std::string& message, std::vector<CREATURE_TYPE>& types);
    ~Location();
    std::shared_ptr<Creature> Get_Creature();
    const std::vector<std::shared_ptr<Location> >& GetRoads();
    std::string GetMessage();
    std::string GetName();
    void AddRoad(std::shared_ptr<Location> location);
};