#ifndef WORLD_H
#define WORLD_H

#include <random>
#include <vector>
#include "Boid.h"
#include "Octree.h"

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
    std::random_device m_rd;

    //void addPredator(); //later

    //void removePredator(); //later

    //void setPrey() //could be set to leader boid

    //void createObstacles(); later, preset shapes

    //void addObstacle();   //later

    //void removeObstacle(); //later
private:



    //std::vector<Obstacle> m_obstacle; later



    Octree *m_octree;

    ngl::Vec3 m_centroid;

    //Predator *predator; later

    //std::vector<Obstacles> m_obstacles; later

};

#endif // WORLD_H
