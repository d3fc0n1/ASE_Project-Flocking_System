#include "World.h"
#include <ngl/Random.h>
#include <iostream>

World::World(int _numBoids, bool _randomizeInitialPosition)
{
    for(int i=0; i < _numBoids; i++)
    {
      addBoid(_randomizeInitialPosition);
    }
    m_octree = new Octree(ngl::Vec3::zero(), 100, 4);
    m_obstacles.clear();
    m_food.clear();
}

World::~World()
{
    delete m_octree;
    m_flock.clear();
}

void World::addBoid(bool _randomizeInitialPosition)
{
    Boid boid(m_flock.size() + 1);
    ngl::Vec3 randomVelocity = ngl::Random::instance()->getRandomVec3();

    if (_randomizeInitialPosition)
    {
        boid.setPosition(ngl::Random::instance()->getRandomVec3() * 100);
    }
    else
    {
        boid.setPosition(ngl::Vec3::zero());
    }

    boid.setVelocity(randomVelocity);
    //boid.setCohesionWeight(_cohesionWeight);
    //boid.setSeparationWeight(_separationWeight);
    //boid.setAlignmentWeight(_alignmentWeight);
    //boid.setAvoidWeight(_avoidWeight);
    m_flock.push_back(boid);
}

void World::dropBoid(int _id)
{
    m_flock[_id - 1].setId(0);
}

void World::addFood()
{
    Obstacle food(ngl::Random::instance()->getRandomVec3() * 100, 5.0f, "football");
    m_food.push_back(food);
}

void World::removeFood()
{
    if (m_food.size() > 0)
    {
        m_food.pop_back();
    }
}

bool World::foodEaten(ngl::Vec3 _foodPosition)
{
    for (size_t i = 0; i<m_flock.size() ; ++i)
    {
        if ((m_flock[i].getPosition() - _foodPosition).length() <= 2)
        {
            return true;
            break;
        }
    }
}

void World::updateWorld()
{
    updateOctree();
    for(size_t i = 0; i < m_flock.size(); ++i)
    {
        setNeighbours(i);

        for (size_t j = 0; j < m_obstacles.size(); ++j)
        {
            m_flock[i].pathIntersectsSphere(m_obstacles[j].getPosition(), m_obstacles[j].getSize() + 50);
        }


        if (m_food.size() > 0)
        {
            m_flock[i].setPursuit(m_food[0].getPosition(), ngl::Vec3(0,0,0));
            if (foodEaten(m_food[0].getPosition()))
            {
                m_food.erase(m_food.begin());
            }
        }

        m_flock[i].move();
    }
}

void World::setNeighbours(int _id)
{
    m_flock[_id].clearNeighbours();
    ngl::Vec3 boxMin(m_flock[_id].getPosition() - ngl::Vec3(m_flock[_id].getViewRadius(), m_flock[_id].getViewRadius(), m_flock[_id].getViewRadius()));
    ngl::Vec3 boxMax(m_flock[_id].getPosition() + ngl::Vec3(m_flock[_id].getViewRadius(), m_flock[_id].getViewRadius(), m_flock[_id].getViewRadius()));
    std::vector<OctreePoint*> results;
    m_octree->getPointsInsideBox(boxMin, boxMax, results);
    for(size_t i=0;i<results.size();++i)
    {
        int neighbourId = static_cast<int>(results[i]->getData().m_w);
        // neighbours shoud not affect the leader's path.
        if (neighbourId != _id && m_flock[_id].isLeader() != true)
        {
            m_flock[_id].setNeighbours(&m_flock[neighbourId]);
        }
    }

}

void World::updateOctree()
{
    delete m_octree;
    m_octree=new Octree(ngl::Vec3::zero(), 100, 4);
    m_octreePoints = new OctreePoint[m_flock.size()];
    for(size_t i=0; i < m_flock.size(); ++i)
    {
        m_octreePoints[i].setData(ngl::Vec4(m_flock[i].getPosition().m_x, m_flock[i].getPosition().m_y,  m_flock[i].getPosition().m_z, m_flock[i].getId()));
        m_octree->insert(m_octreePoints + i);
    }
}

void World::addObstacle(std::string _obstacleShape)
{
    Obstacle obstacle(ngl::Random::instance()->getRandomVec3() * 100, 40.0f, _obstacleShape);
    m_obstacles.push_back(obstacle);
}

void World::removeObstacle()
{
    if (m_obstacles.size() > 0)
    {
        m_obstacles.pop_back();
    }
}

void World::updateObstacleSize(float _size)
{
    for (auto obstacle: m_obstacles)
    {
        obstacle.setSize(_size * 10);
    }
}

void World::removeBoid()
{
    if(m_flock.size() > 0)
    {
        m_flock.erase(m_flock.end()-1);
    }
}

//centroid for whole flock
void World::setCentroid()
{
    for (size_t i = 0; i < m_flock.size(); ++i)
    {
        m_centroid += m_flock[i].getPosition();
    }
    m_centroid /= m_flock.size();
}

int World::getSize()
{
    return m_flock.size();
}

void World::setLeader(int _id)
{
    for(size_t i=0;i<m_flock.size();++i)
    {
        m_flock[i].setLeader(&m_flock[_id]);
    }
    m_flock[_id].makeLeader();
}

void World::setPredator()
{
    for(size_t i=0;i<m_flock.size() - 1;++i)//all except last ID
    {
        m_flock[i].setPredator(&m_flock[m_flock.size() - 1]);//set last ID as predator
    }
    m_flock[m_flock.size() - 1].makePredator();
}

void World::clearLeader()
{
    for(size_t i=0;i<m_flock.size();++i)
    {
        m_flock[i].clearLeader();
    }
}
