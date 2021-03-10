//
// Created by mihai on 10/03/2021.
//

#include <thread>
#include <chrono>
#include "utils.h"

void sleep(int miliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}
