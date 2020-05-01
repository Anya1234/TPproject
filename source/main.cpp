#include <iostream>
#include "Dragon.h"
#include "Gendalf.h"
#include "interface_factory.h"
#include "Gendalf_types.h"
#include "creature_factory.h"
#include "Creatures.h"
#include "Team.h"

int main() {
    Team orcs_team = Team(ORC, 10);
    Team hobbits_team = Team(HOBBIT, 15);
    Team humans_team = Team(HUMAN, 20);
    orcs_team.Print();
    hobbits_team.Print();
    humans_team.Print();
    return 0;
}