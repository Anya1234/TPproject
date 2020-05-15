#include "Team.h"

size_t Team::Get_quantity() {
    return creatures.size();
}

void Team::Print() {
        for (size_t i = 0; i < quantity; ++i) {
            std::cout << i << " " << creatures[i]->Get_name() << "\n";
        }
}

void Team::AddPerson(std::shared_ptr<Creature> person) {
    creatures.push_back(person);
}

std::shared_ptr<Creature> Team::GetPerson(int number) {
    return creatures[number];
}

void Team::RemovePerson(int number) {
    creatures.erase(creatures.begin() + number);
}

int Team::Get_HP() {
    int team_HP = 0;
    for (auto teammate : creatures) {
        team_HP += teammate->Get_HP();
    }
    return team_HP;
}


void Team::PrintTeam() {
    std::cout << "Выбери члена команды";
    for (size_t i = 0; i < creatures.size(); ++i) {
        if (i % 5 == 0) {
            std::cout << "\n";
        }
        std::cout << i << " " << creatures[i]->Print_type() << " - " <<creatures[i]->Get_name() << "; ";
    }
    std::cout << "\nВведи номер: ";
}