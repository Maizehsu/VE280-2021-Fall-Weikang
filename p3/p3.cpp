/*
 * @Author: Mai Xu
 * @Date: 2021-10-30 14:36:16
 * @LastEditTime: 2021-11-11 18:00:19
 * @Description: 2021 Fall VE280 Project 3
 * @FilePath: \p3\p3.cpp
 */

#include <iostream>
#include "world_type.h"
#include "simulation.h"

using namespace std;

int main(int argc, char *argv[]) {
    Simulation mySimulation(argc, argv);
    mySimulation.simulate();
    return 0;
}