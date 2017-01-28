#ifndef WORLD_H
#define WORLD_H

#include <random>
#include <vector>
#include "Boid.h"
#include "Octree.h"
#include "Obstacle.h"
#include <string>

class World
{
public:
    World(int _numBoids, bool _randomizeInitialPosition);
    World(int _numBoids, float _cohesion, float _separation, float _alignment);
    ~World();

    void addBoid(bool _randomizeInitialPosition);
    void removeBoid();
    void dropBoid(int _id);
    void addObstacle(std::string _obstacleShape);
    void removeObstacle();
    void updateObstacleSize(float _size);

    int getSize();
    void setCentroid();
    void avoidObstacles();
    void setNeighbours(int _id);
    void updateWorld();
    void setLeader(int _id);
    void clearLeader();
    void updateOctree();
    std::vector<Boid> m_flock;
    std::vector<Obstacle> m_obstacles;
    std::vector<Obstacle> m_food;
    void setPredator();
    void removePredator();
    void addFood();
    void removeFood();
    bool foodEaten(ngl::Vec3 _foodPosition);
    //void setPrey() //could be set to leader boid


private:
    Octree *m_octree;
    OctreePoint *m_octreePoints;
    ngl::Vec3 m_centroid;
    //Predator *predator; later
};

#endif // WORLD_H
