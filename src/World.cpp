#include "World.h"
#include <ngl/Random.h>

World::World(int _numBoids)
{
    for(int i=0; i < _numBoids; i++)
    {
      addBoid(80, 40, 50, 500);
    }
    m_octree = new Octree(ngl::Vec3::zero(), ngl::Vec3(1.0f, 1.0f, 1.0f));
}

World::World(int _numBoids, float _cohesion, float _separation, float _alignment)
{
    for(int i=0; i < _numBoids; i++)
    {
      addBoid(_cohesion, _separation, _alignment);
    }
    m_octree = new Octree(ngl::Vec3::zero(), ngl::Vec3(0.5f, 0.5f, 0.5f));
}

World::~World()
{
    delete m_octree;
    m_flock.clear();
}

void World::addBoid(float _cohesionWeight, float _separationWeight, float _alignmentWeight, float _avoidWeight)
{
    Boid boid(m_flock.size() + 1);
    ngl::Vec3 position = ngl::Random::instance()->getRandomVec3();
    ngl::Vec3 velocity = ngl::Random::instance()->getRandomVec3();
    boid.setPosition(position);
    boid.setVelocity(velocity);
    boid.setCohesionWeight(_cohesionWeight);
    boid.setSeparationWeight(_separationWeight);
    boid.setAlignmentWeight(_alignmentWeight);
    boid.setAvoidWeight(_avoidWeight);
    m_flock.push_back(boid);
}

void World::removeBoid()
{
    if(m_flock.size() > 0)
    {
        m_flock.erase(m_flock.end()-1);
    }
}

void World::updateOctree()
{
    delete m_octree;
    m_octree=new Octree(ngl::Vec3::zero(), ngl::Vec3(0.5f, 0.5f, 0.5f));
    ngl::Vec4 data;//boid x, y, z, ID
    for(size_t i=0; i < m_flock.size(); ++i)
    {
      data.set(m_flock[i].getPosition().m_x, m_flock[i].getPosition().m_y,  m_flock[i].getPosition().m_z, m_flock[i].getId());
      m_octree->insert(data);
    }
}

void World::setNeighbours(int _id)
{
    m_flock[_id].clearNeighbours();
    ngl::Vec3 boxMin(-1.0f, -1.0f, -1.0f);
    ngl::Vec3 boxMax(1.0f, 1.0f, 1.0f);
    m_octree->getPointsInsideBox(boxMin, boxMax, m_octree->m_data);
    for(size_t i=0;i<m_octree->m_data.size();++i)
    {
        // the neighbour id is the 4th element of the m_data vector
        int neighbourId = static_cast<int>(m_octree->m_data[i].m_w);
        // set the boid to be a neighbour only if it is not the boid
        // being queried and it is not a leader. Leader only wanders
        // neighbours shoud not affect the leader's path.
        if (neighbourId != _id && m_flock[_id].isLeader() != true)
        {
            m_flock[_id].setNeighbours(&m_flock[neighbourId - 1]);//ID starts with 1
        }
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

void World::updateWorld()
{
    updateOctree();
    for(size_t i = 0; i < m_flock.size(); ++i)
    {
      m_octree->clearData();
      setNeighbours(i);
      m_flock[i].move();
    }
}

void World::setLeader(int _id)
{
    for(size_t i=0;i<m_flock.size();++i)
    {
        m_flock[i].setLeader(&m_flock[_id]);
    }
    m_flock[_id].makeLeader();
}

void World::clearLeader()
{
    for(size_t i=0;i<m_flock.size();++i)
    {
        m_flock[i].clearLeader();
    }
}
