#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Car.h"
#include <vector>
#include <thread>
#include <conio.h>


std::vector<Car*> cars;
std::vector<std::thread> carsThreads;
static bool running = true;

void generateCars(){

    while(running){


        cars.push_back(new Car(0, 0, 100, 0,false,10));
        carsThreads.push_back(cars.back()->moveThread());
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    }

}

void terminateThreadsOfCars()
{
    for (int i = 0; i < carsThreads.size(); ++i)
    {
        carsThreads[i].join();
    }
}

void checkIfRunning()
{
    while('x' != getch())
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    running = false;
    Car::setRunningFlag(false);
}

int main() {

    srand(time(NULL));
    Car::setRunningFlag(true);
    std::thread generateCarsThread(generateCars);
    std::thread checkIfRunningThread(checkIfRunning);
    generateCarsThread.join();
    terminateThreadsOfCars();
    checkIfRunningThread.join();
    return 0;

}

