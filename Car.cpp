//
// Created by Kuba on 06.04.2019.
//

#include "Car.h"
#include <thread>
#include <iostream>


bool Car::runningFlag;

Car::Car(int position, int place, int fuel, int lap, bool damaged, int speed ){
    this->position=position;
    this->place=place;
    this->fuel=fuel;
    this->lap=lap;
    this->damaged=damaged;
    this->speed=speed;
}
Car::~Car(){
}


int Car::getPosition() {
    return this->position;
}
int Car::getPlace() {
    return this->place;
}
int Car::getFuel() {
    return this->fuel;
}
int Car::getLap() {
    return this->lap;
}
bool Car::getDamaged() {
    return this->damaged;
}

int Car::getSpeed() {
    return this->speed;
}
bool Car::getRunningFlag() {
    return runningFlag;
}

void Car::setPosition(int position) {
    this->position=position;
}
void Car::setPlace(int place) {
    this->place=place;
}
void Car::setFuel(int fuel) {
    this->fuel=fuel;
}
void  Car::setLap(int lap) {
    this->lap=lap;
}

void Car::setDamaged(bool damaged) {
    this->damaged=damaged;
}
void Car::setSpeed(int speed) {
    this->speed=speed;
}
void Car::setRunningFlag(bool flag) {
    runningFlag=flag;
}



std::thread Car::moveThread()
{
    return std::thread(&Car::move, this);
}


void Car::move()
{
    while(runningFlag) {

        this->position+=this->speed;
        if(this->position==100){
            this->lap+=1;
            this->position=0;
        }
        if(this->lap==5){
            this->position=1;
            std::cout<<"wygrana";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));


    }
}
