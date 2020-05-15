#pragma once

#include "Creatures.h"
#include "creature_factory.h"
#include "Dragon.h"
#include "Gendalf.h"
#include "Team.h"
#include "Location.h"


class Game {
public:
    Game();
    ~Game();
    void Run();
    std::string GetComandFromConsole();
private:
    std::shared_ptr<Creature> Greeting();
    bool GameProcess();
    void NextLocation();
    bool CanCallGendalf();
    std::string greeting;
    std::string player_name;
    std::shared_ptr<Team> player_team;
    std::vector< std::shared_ptr<Location> > locations;
    std::shared_ptr<Location> current_location;
    Gendalf* gendalf;
    Dragon* Smaug;
};