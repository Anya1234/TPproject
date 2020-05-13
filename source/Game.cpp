#include "Game.h"
#include <memory>
#include <limits>
#include <cstdlib>

Game::Game() : greeting("Здравствуй странник, приветствуем тебя на просторах Средиземья\nНазови своё имя:\n"), Smaug(Dragon::getInstance()) {
    std::vector<CREATURE_TYPE> Prancing_Pony;
    std::vector<CREATURE_TYPE> Shire;
    std::vector<CREATURE_TYPE> Gondor;
    std::vector<CREATURE_TYPE> Mordor;
    Prancing_Pony.push_back(ORC);
    Prancing_Pony.push_back(HUMAN);
    Prancing_Pony.push_back(HOBBIT);
    Shire.push_back(HOBBIT);
    Gondor.push_back(HUMAN);
    Mordor.push_back(ORC);

    locations.push_back(std::make_shared<Location>("Prancing_Pony", 
                                                   " мы в Горцующем Пони, это лучшее место, чтобы найти себе верных друзей ;)",
                                                   Prancing_Pony));
    locations.push_back(std::make_shared<Location>("Shire", 
                                                   "мы в Шире, в пристанище Хоббитов",
                                                   Shire));
    locations.push_back(std::make_shared<Location>("Gondor", 
                                                   " мы в Гондоре, на улицах этого города можно встретить лучших воинов на всем Средиземье",
                                                   Gondor));
    locations.push_back(std::make_shared<Location>("Mordor", 
                                                   " Мордор... не лучшее место для прогулок, но чтобы победить Смауга, нашим бойцам нужно тренироваться.",
                                                   Mordor));
}

Game::~Game() {}

// std::string Game::GetComandFromConsole() {
//     std::string user_input;
//     while (true) {
//         std::cin >> user_input;  
//     }
// }

std::shared_ptr<Creature> Game::Greeting() {
    std::cout << greeting;
    std::string name;
        
    while (true) {
        std::cin >> name;
        if (name == "") {
            std::cout << "Ну же, не стесняйся, представься)\n";
        }
        else {
            player_name = name;
            break;
        }
    }
    
    return std::make_shared<Hobbit>(player_name);
}

void Game::NextLocation() {
    const std::vector< std::shared_ptr<Location> >& locations = current_location->GetRoads();
    for (size_t i = 0; i < locations.size(); ++i) {
        std::cout << i << " " << locations[i]->GetName() << "\n";
    }

    size_t location_num = std::numeric_limits<size_t>::max();
    while (true) {
        std::cout << player_name << ", куда пожелаешь отправиться?\n";
        std::cin >> location_num;
        if (location_num < locations.size()) {
            std::shared_ptr<Creature> stranger = locations[location_num]->Get_Creature();
            std::cout << "На пути вам встретился " << stranger->Print_type() << " " << stranger->Get_name() << "\n";
            std::cout << player_name << ", будем сражаться или попробуем договориться?\n";
            size_t command = std::numeric_limits<size_t>::max();
            while (true) {
                std::cin >> command;
                if (command > 1) continue;
                player_team->PrintTeam();
                size_t teammate_num = std::numeric_limits<size_t>::max();
                while (true) {
                    std::cin >> teammate_num;
                    if (teammate_num >= player_team->Get_quantity()) {
                        std::cout << "Попробуй снова: ";
                        continue;
                    }
                    else {
                        break;
                    }
                }
                
                std::shared_ptr<Creature> teammate = player_team->GetPerson(teammate_num);
                
                // Сражаемся
                if (command == 0) {
                    while (teammate->check_is_alive() && stranger->check_is_alive()) {
                        teammate->attack(stranger);
                    }
                }
                // Договариваемся
                else if (command == 1) {
                    if (teammate->negotiate(stranger)) {
                        player_team->AddPerson(stranger);
                    }
                    else {
                        while (teammate->check_is_alive() && stranger->check_is_alive()) {
                            teammate->attack(stranger);
                        }
                    }
                }
                
            }
            break;
        }
        std::cout << "Такой локации нет)\n";
    }
    
}

bool Game::GameProcess() {
    std::cout << player_name << " мы в Горцующем Пони, это лучшее место, чтобы найти себе верных друзей ;)\n";
    while (Smaug->get_HP() > 0 && player_team->Get_HP() > 0) {
        NextLocation();
    }

    return Smaug->get_HP() > 0 ? false : true;
}

void Game::Run() {

    player_team->AddPerson( Greeting() );

    if (GameProcess()) {
        std::cout << "Поздравляю тебя, " << player_name << ", ты побеил дракона!\n";
    }
    else {
        std::cout << "К сожалению, " << player_name << ", тебе не удалось одолеть дракона!\n";
    }
     
}

