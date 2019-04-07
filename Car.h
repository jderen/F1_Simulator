//
// Created by Kuba on 06.04.2019.
//

#ifndef AUTKABRUMBRUM_CAR_H
#define AUTKABRUMBRUM_CAR_H
#include <thread>

class Car {

private:
    int position;
    // ranking
    int place;
    int fuel;
    int lap;
    bool damaged;
    int speed;
    static bool runningFlag;

public:
    Car(int position, int place, int fuel, int lap, bool damaged,int speed);
    ~Car();
    int getPosition();
    void setPosition(int position);
    int getPlace();
    void setPlace(int place);
    int getFuel();
    void setFuel(int fuel);
    int getLap();
    void setLap(int lap);
    bool getDamaged();
    void setDamaged(bool damaged);
    int getSpeed();
    void setSpeed(int speed);
    static bool getRunningFlag();
    static void setRunningFlag(bool runningFlag);
    std::thread moveThread();
    void move();

};


#endif //AUTKABRUMBRUM_CAR_H
