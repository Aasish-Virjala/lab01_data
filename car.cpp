// name(s) and Perm 
// Aasish Virjala 5409776
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>

// #include .......

Car::Car() {
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}

Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) {
    manufacturer = strdup(manufacturerName);
    model = strdup(modelName);
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;
    backseatDoors = backseatDoorDesign;
}

Car::Car(Car const& o) {
    this->manufacturer = strdup(o.getManufacturer());
    this->model = strdup(o.getModel());
    this->zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    this->headonDragCoeff = o.getStats().headonDragCoeff;
    this->horsepower = o.getStats().horsepower;
    this->seatCount = o.getSeatCount();
    this->backseatDoors = o.getBackseatDoors();
}

Car::~Car() {
    free(manufacturer);
    free(model);
}

Car& Car::operator=(Car const& o) {
    if(this==&o) {
        return *this;
    }
    manufacturer = strdup(o.getManufacturer());
    model = strdup(o.getModel());
    zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    headonDragCoeff = o.getStats().headonDragCoeff;
    horsepower = o.getStats().horsepower;
    return *this;
}

char const* Car::getManufacturer() const {
    return manufacturer;
}
char const* Car::getModel() const {
    return model;
}

PerformanceStats Car::getStats() const {
    PerformanceStats stats = {horsepower,zeroToSixtyNs,headonDragCoeff};
    return stats;
}

uint8_t Car::getSeatCount() const {
    return seatCount;
}

DoorKind Car::getBackseatDoors() const {
    return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer) {
    manufacturer = strdup(newManufacturer);
}

void Car::modelNameChange(char const* const newModelName) {
    model = strdup(newModelName);
}

void Car::reevaluateStats(PerformanceStats newStats) {
    horsepower = newStats.horsepower;
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
}

void Car::recountSeats(uint8_t newSeatCount) {
    seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind) {
    backseatDoors = newDoorKind;
}