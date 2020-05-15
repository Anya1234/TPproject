#include "Game.h"
#include <memory>
#include <limits>
#include <cstdlib>

Game::Game() : greeting("Здравствуй странник, приветствуем тебя на просторах Средиземья\nНазови своё имя: "),
               player_team(std::make_shared<Team>()),
               gendalf(Gendalf::getInstance()), 
               Smaug(Dragon::getInstance()) {

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

    current_location = std::make_shared<Location>("Prancing_Pony", 
                                                   " мы в Горцующем Пони, это лучшее место, чтобы найти себе верных друзей ;)",
                                                   Prancing_Pony);
    locations.push_back(current_location);
    locations.push_back(std::make_shared<Location>("Shire", 
                                                   "мы в Шире, в пристанище Хоббитов",
                                                   Shire));
    locations.push_back(std::make_shared<Location>("Gondor", 
                                                   " мы в Гондоре, на улицах этого города можно встретить лучших воинов на всем Средиземье",
                                                   Gondor));
    locations.push_back(std::make_shared<Location>("Mordor", 
                                                   " Мордор... не лучшее место для прогулок, но чтобы победить Смауга, нашим бойцам нужно тренироваться.",
                                                   Mordor));
    locations[0]->AddRoad(locations[1]);
    locations[0]->AddRoad(locations[2]);
    locations[0]->AddRoad(locations[3]);
    locations[1]->AddRoad(locations[0]);
    locations[1]->AddRoad(locations[2]);
    locations[1]->AddRoad(locations[3]);
    locations[2]->AddRoad(locations[0]);
    locations[2]->AddRoad(locations[1]);
    locations[2]->AddRoad(locations[3]);
    locations[3]->AddRoad(locations[0]);
    locations[3]->AddRoad(locations[1]);
    locations[3]->AddRoad(locations[2]);
}

Game::~Game() {}

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
    return std::make_shared<Hobbit>(name);
}

void Game::NextLocation() {
    const std::vector< std::shared_ptr<Location> >& locations = current_location->GetRoads();

    std::cout << player_name << ", куда пожелаешь отправиться?\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        std::cout << i << " " << locations[i]->GetName() << "\n";
    }

    std::string location_num_s = "void";
    size_t location_num = std::numeric_limits<size_t>::max();
    while (true) {
        std::cin >> location_num_s;
        try{
            location_num = std::stoi(location_num_s);
        }
        catch(const std::invalid_argument& ex) {
            std::cout << "Такой локации нет)\n";
            continue;
        }
        if (location_num < locations.size()) {
            current_location = locations[location_num];
            std::shared_ptr<Creature> stranger = locations[location_num]->Get_Creature();
            std::cout << "На пути вам встретился " << stranger->Print_type() << " " << stranger->Get_name() << "\n";
            std::cout << player_name << ", будем сражаться или попробуем договориться?\n";
            std::cout << 0 << " - Сражаться; " << 1 << " - Договориться;" << "\n";
            std::string command_s = "void";
            size_t command = std::numeric_limits<size_t>::max();
            while (true) {
                std::cin >> command_s;
                try{
                    command = std::stoi(command_s);
                }
                catch(const std::invalid_argument& ex) {
                    std::cout << "Неверная команда\n";
                    continue;
                }
                if (command > 1) {
                    std::cout << "Неверная команда\n";
                }
                else {
                    player_team->PrintTeam();

                    std::string teammate_num_s = "void";
                    size_t teammate_num = std::numeric_limits<size_t>::max();
                    while (true) {
                        std::cin >> teammate_num_s;
                        try{
                            teammate_num = std::stoi(teammate_num_s);
                        }
                        catch(const std::invalid_argument& ex) {
                            std::cout << "Неверная команда\n";
                            continue;
                        }
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
                        if (!teammate->check_is_alive()) {
                            player_team->RemovePerson(teammate_num);
                            std::cout << teammate->Get_name() << " погиб...\n";
                        }
                        else {
                            std::cout << stranger->Get_name() << " повержен!\n";
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
                            if (!teammate->check_is_alive()) {
                                player_team->RemovePerson(teammate_num);
                                std::cout << teammate->Get_name() << " погиб...\n";
                            }
                            else {
                                std::cout << stranger->Get_name() << " повержен!\n";
                            } 
                        }
                    }

                    break;
                }
            }
            break;
        }
        std::cout << "Такой локации нет)\n";
    }
    
}

bool Game::CanCallGendalf() {
    if (player_team->Get_quantity() >= 6) {
        return true;
    }
    return false;
}

bool Game::GameProcess() {
    std::cout << player_name << " мы в Горцующем Пони, это лучшее место, чтобы найти себе верных друзей ;)\n";
    while (Smaug->get_HP() > 0 && player_team->Get_HP() > 0) {
        NextLocation();
        if (CanCallGendalf()) {
            std::cout << "Вы можете сразиться с Драконом!" << "\n";
            std::cout << 0 << " - Сражаться; " << 1 << " - Продолжить странствовать;" << "\n"; 
            std::string code_s = "void";
            size_t code = 401;
            while (true) {
                std::cin >> code_s;
                try{
                    code = std::stoi(code_s);
                }
                catch(const std::invalid_argument& ex) {
                    std::cout << "Неверная команда\n";
                    continue;
                }
                std::cin >> code;
                if (code == 1) {
                    break;
                }
                else if (code == 0) {
                        gendalf->attack(Smaug);
                        break;
                }
            }
            
        }
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

