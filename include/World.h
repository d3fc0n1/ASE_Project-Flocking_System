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
    World(int _numBoids);
    World(int _numBoids, float _cohesion, float _separation, float _alignment);
    ~World();

    void addBoid(float _cohesionWeight, float _separationWeight, float _alignmentWeight, float _avoidWeight = 500);
    void removeBoid();
    int getSize();
    void setCentroid();
    void setNeighbours(int _id);
    void updateWorld();
    void setLeader(int _id);
    void clearLeader();
    void updateOctree();
    std::vector<Boid> m_flock;
    std::vector<Obstacle> m_obstacles;
    std::random_device m_rd;

    //void addPredator(); //later

    //void removePredator(); //later

    //void setPrey() //could be set to leader boid
    void addObstacle(std::string _obstacleShape);
    void removeObstacle();
    void updateObstacleSize(float _size);
    void avoidObstacles();

private:

    Octree *m_octree;
    OctreePoint *m_octreePoints;
    ngl::Vec3 m_centroid;
    //Predator *predator; later
};

#endif // WORLD_H
