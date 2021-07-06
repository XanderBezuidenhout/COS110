#include <iostream>

#include "dieselLocomotive.h"
#include "electricLocomotive.h"
#include "locomotive.h"
#include "vehicle.h"

using namespace std;

int main() {
    cout << "\n-----Locomotive testing-----\n\n";
    locomotive* lcm;
    lcm = new locomotive();
    lcm->setName("Test Locomotive");
    lcm->setSupplyRange(2);
    lcm->determineRouteStatistics();
    lcm->setMap("map1.txt");
    lcm->determineRouteStatistics();
    cout << lcm->getSize() << endl;
    --*lcm;
    cout << lcm->getSize() << endl;
    delete lcm;

    cout << "\n-----dieselLocomotive testing-----\n\n";
    vehicle* dcm = new dieselLocomotive();
    dcm->setName("Test DieselLocomotive");
    dcm->setMap("map2.txt");
    //dcm->setPassengerLimit(75);
    dcm->determineRouteStatistics();
    cout << endl;
    //dcm->setPassengerLimit(50);
    dcm->determineRouteStatistics();
    cout << endl;
    dcm->operator--();
    delete dcm;

    cout << "\n-----electricLocomotive testing-----\n\n";
    electricLocomotive* ecm = new electricLocomotive();
    ecm->setName("Test ElectricLocomotive");
    ecm->setMap("map3.txt");
    ecm->setUnitCost(15.93);
    ecm->determineRouteStatistics();
    delete ecm;

    return 0;
}