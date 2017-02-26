#ifndef WORLD_H
#define WORLD_H
#include "CommonIncludes.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include "Cell.h"
#include "Creature.h"

class World
{
public:
    World();
    ~World();
    cv::Mat matrix;
    int getHeight() const;
    int getWidth() const;
    void init();
    int const mapHeight = 10;
    int const mapWidth = 10;
    std::vector<std::vector<Cell> > map;
    std::vector<Creature> worm_map {2};
};

#endif // WORLD_H
