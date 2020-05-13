#include "Location.h"
#include "Locations.h"
#include <memory>

Shire::Shire() : Location("Shire", "мы в Шире, в пристанище Хоббитов") {}

Gondor::Gondor() : Location("Gondor", " мы в Гондоре, на улицах этого города можно встретить лучших воинов на всем Средиземье") {}

Prancing_Pony::Prancing_Pony() : Location("Prancing_Pony", " мы в Горцующем Пони, это лучшее место, чтобы найти себе верных друзей ;)") {}

Mordor::Mordor() : Location("Mordor", " Мордор... не лучшее место для прогулок, но чтобы победить Смауга, нашим бойцам нужно тренироваться.") {}

Erebor::Erebor() : Location("Erebor", " Эребор... именно тут тебе придется сразиться со Смаугом, удачи") {}
