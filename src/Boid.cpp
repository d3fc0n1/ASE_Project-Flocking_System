#include "Boid.h"
#include <math.h>
#include <iostream>
//-------------------------------CTOR----------------------------------
Boid::Boid(int _id)
{
    m_id=_id;
    m_flee.set(ngl::Vec3(0.0f, 0.0f, 0.0f));
    m_centroid.set(ngl::Vec3(0.0f, 0.0f, 0.0f));
    m_hasLeader=false;
    m_isLeader=false;
    m_slowingRadius = 10.0f;
    m_viewRadius = 30.0f;
}

//---------------------------GET ATTRIBUTES-----------------------------
int Boid::getId()
{
    return m_id;
}
ngl::Vec3 Boid::getPosition()
{
    return m_position;
}
ngl::Vec3 Boid::getRotation()
{
    return ngl::Vec3(m_pitch, m_yaw ,m_roll);
}
ngl::Vec3 Boid::getVelocity()
{
    return m_velocity;
}
bool Boid::isLeader()
{
    return m_isLeader;
}
int Boid::getNeighbourSize()
{
    return m_neighbours.size();
}
float Boid::getViewRadius()
{
    return m_viewRadius;
}
float Boid::getAvoidRadius()
{
    return m_avoidRadius;
}

//---------------------------SET ATTRIBUTES-----------------------------
void Boid::setAlignmentWeight(float _alignmentWeight)
{
    m_alignmentWeight = _alignmentWeight;
}
void Boid::setCohesionWeight(float _cohesionWeight)
{
    m_cohesionWeight = _cohesionWeight;
}
void Boid::setSeparationWeight(float _separationWeight)
{
    m_separationWeight = _separationWeight;
}
void Boid::setAvoidWeight(float _avoidWeight)
{
    m_avoidWeight = _avoidWeight;
}
void Boid::setPosition(ngl::Vec3 _position)
{
    m_position.set(_position);
}
void Boid::setVelocity(ngl::Vec3 _velocity)
{
    m_velocity.set(_velocity);
}
void Boid::setLeader(Boid *_leader)
{
    m_leader = _leader;
    m_hasLeader = true;
}
void Boid::setNeighbours(Boid *_boid)
{
    m_neighbours.push_back(_boid);
}
void Boid::setCentroid()
{
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            m_centroid += m_neighbours[i]->getPosition();
        }
        m_centroid /= (m_neighbours.size() + 1);
    }
}

//-----------------------------ROLE MODS--------------------------------
void Boid::clearNeighbours()
{
    m_neighbours.clear();
}
void Boid::clearLeader()
{
    if (m_isLeader == true)
        m_isLeader = false;
    else
    {
        m_hasLeader = false;
        m_leader = 0;
    }
}
void Boid::makeLeader()
{
  m_isLeader = true;
  m_hasLeader = false;
  m_leader = 0; //has no leader, clear pointer
}

//---------------------------FLOCKING RULES-----------------------------
void Boid::setCohesion()
{
    setCentroid();
    if (m_neighbours.size() > 0)
    {
        m_cohesion = m_centroid - m_position;
        if(m_cohesion.length()!=0) m_cohesion.normalize();
    }
    else
    {
        m_cohesion.set(0.0f, 0.0f, 0.0f);

    }
}
void Boid::setAlignment()
{
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            m_alignment += m_neighbours[i]->getVelocity();
        }
        m_alignment /= m_neighbours.size();
        if (m_alignment.length() !=0) m_alignment.normalize();
    }
    else
        m_alignment.set(0.0f, 0.0f, 0.0f);
}
void Boid::setSeparation()
{
    m_separation.set(0.0f,0.0f,0.0f);
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            if ((m_neighbours[i]->getPosition() - m_position).length() > m_separationRadius)
            {
                ngl::Vec3 pos(m_neighbours[i]->getPosition());
                ngl::Vec3 target = m_position - pos;
                m_separation += target;
            }
        }
        if(m_neighbours.size()>0) m_separation /= m_neighbours.size();
        if(m_separation.length()!=0) m_separation.normalize();
    }
}

//-------------------------STEERING BEHVIOURS---------------------------
void Boid::setSeek() //needs m_target to function
{
    ngl::Vec3 desiredVelocity = m_target - m_position;
    float distance = desiredVelocity.length();
    if (distance != 0) desiredVelocity.normalize();

    if (distance <= m_slowingRadius)
    {
        desiredVelocity *= (m_maxVelocity * distance/m_slowingRadius);
    }
    else
    {
        desiredVelocity *= m_maxVelocity;
    }

    m_seek = desiredVelocity - m_velocity;
}
void Boid::pursue(Boid *_boid) //sets a target to seek
{
    ngl::Vec3 distance = _boid->getPosition() - m_position;
    int frames = distance.length() / m_maxVelocity;
    m_target = _boid->getPosition() + _boid->getVelocity() * frames;
    setSeek();
}

void Boid::setFlee(ngl::Vec3 _fleePosition) //needs m_target to function
{
    ngl::Vec3 desiredVelocity = m_position - _fleePosition;
    desiredVelocity.normalize();
    desiredVelocity *= m_maxVelocity;
    m_flee = desiredVelocity - m_velocity;
}
void Boid::evade(Boid *_boid) //sets a target for fleeing
{
    ngl::Vec3 distance = _boid->getPosition() - m_position;
    int frames = distance.length() / m_maxVelocity;
    m_target = _boid->getPosition() + _boid->getVelocity() * frames;
    setFlee(_boid->getPosition());
}

void Boid::setWander() //sets m_wander
{
    ngl::Vec3 sphereCenter = m_velocity;
    if (sphereCenter.length() !=0)
    {
        sphereCenter.normalize();
    }
    sphereCenter *= m_wanderSphereDistance;

    ngl::Vec3 displacement;

    displacement.m_x = m_wanderSphereRadius * cos(m_wanderAngle) * sin(m_wanderAzimuth);
    displacement.m_y = m_wanderSphereRadius * sin(m_wanderAngle) * sin(m_wanderAzimuth);
    displacement.m_z = m_wanderSphereRadius * tan(m_wanderAngle);

    m_wanderAngle += ngl::Random::instance()->randomNumber() * m_wanderAngleChange - m_wanderAngleChange * 0.5f;
    m_wanderAzimuth += ngl::Random::instance()->randomNumber() * m_wanderAzimuthChange - m_wanderAzimuthChange * 1.0f;

    m_wander = sphereCenter + displacement;
}
void Boid::setAvoid(ngl::Vec3 _obstaclePosition, float _obstacleRadius) //call for every neighbour, pass in position and avoidradius
{
    ngl::Vec3 ahead = m_position + (m_velocity / m_velocity.length()) * m_maxSeeAhead;
    ngl::Vec3 halfAhead = ahead * 0.5;
    m_threatPosition.set(0.0f,0.0f,0.0f);

    bool collision = pathInterectsSphere(ahead, halfAhead, _obstaclePosition, _obstacleRadius);
    if (collision && (m_threatPosition == ngl::Vec3(0.0f,0.0f,0.0f) || ((_obstaclePosition - m_position).length() <  (m_threatPosition - m_position).length())))
    {
        m_threatPosition = _obstaclePosition;
    }

    m_avoid.set(0.0f,0.0f,0.0f);
    if (m_threatPosition != ngl::Vec3(0.0f,0.0f,0.0f))
    {
        m_avoid = ahead - m_threatPosition;
        if (m_avoid.length() != 0)
        {
                m_avoid.normalize();
        }
        m_avoid *= m_avoidWeight;
    }
}
void Boid::setFollow() //sets m_follow
{
    ngl::Vec3 leaderVelocity = m_leader->getVelocity();
    leaderVelocity.normalize();
    ngl::Vec3 ahead = m_leader->getPosition() + leaderVelocity * m_leaderFollowDistance;
    ngl::Vec3 behind = m_leader->getPosition() - leaderVelocity * m_leaderFollowDistance;

    if ((m_position - ahead).length() <= m_viewRadius || (m_leader->getPosition() - m_position).length() <= m_viewRadius)
    {
        evade(m_leader);
        m_follow += m_flee;
    }

    ngl::Vec3 desiredVelocity = behind - m_position;
    float distance = desiredVelocity.length();
    if (distance <= m_slowingRadius)
    {
        desiredVelocity *= (m_maxVelocity * distance/m_slowingRadius);
    }
    else
    {
        desiredVelocity *= m_maxVelocity;
    }

    m_follow += desiredVelocity;
    m_follow += m_separation;
}


void Boid::setSteering()
{
    //std::cout<<"Neighbour size : "<<m_neighbours.size()<<'\n';
    m_flee.set(0,0,0);
    setCohesion();
    setAlignment();
    setSeparation();
    fleeWalls();

    if (m_neighbours.size() > 0)
    {
        for (size_t i=0 ; i<m_neighbours.size();++i)
        {
            setAvoid(m_neighbours[i]->getPosition(), m_neighbours[i]->getAvoidRadius());
        }
    }

    m_steering = m_cohesion + m_alignment + m_separation + m_avoid + m_flee; //basic rules, common for all.

    if(m_isLeader)
    {
        setWander();
        m_steering +=  m_wander;
    }
    else //not leader
    {
        if(m_hasLeader)
        {
            setFollow();
            m_steering += m_follow;
        }
        else //not leader, no leader
        {
            setWander();
            m_steering += m_wander;
        }
    }

    if (m_steering.length() != 0)
        m_steering.normalize();

    //if predator exists, Evade
    //if moving target exists, pursue
}
//-------------------------------MOVEMENT----------------------------------
void Boid::move()
{
    setSteering();
    m_velocity += m_steering;
    m_velocity.normalize();
//    std::cout<<"cohesion :"<<m_cohesion.m_x<<'\n';
//    std::cout<<"separation :"<<m_separation.m_x<<'\n';
//    std::cout<<"alignment :"<<m_alignment.m_x<<'\n';

    m_position += m_velocity;
    rotate();
}
void Boid::rotate()
{
    m_roll = atan2(m_velocity.m_y, m_velocity.m_z) * 180/M_PI;
    m_pitch = atan2(m_velocity.m_x, sqrt(m_velocity.m_y * m_velocity.m_y + m_velocity.m_z * m_velocity.m_z)) * 180/M_PI + 180;
    m_yaw = atan2(m_velocity.m_x, m_velocity.m_z) * 180/M_PI;
}

//--------------------------------OTHERS------------------------------------
void Boid::fleeWalls()
{
    if (m_position.m_x <= -100 || m_position.m_x >= 100)
    {
        m_flee.m_x -= (m_position.m_x/2);
    }
    if (m_position.m_y <= -100 || m_position.m_y >= 100)
    {
        m_flee.m_y -= (m_position.m_y/2);
    }
    if (m_position.m_z <= -100 || m_position.m_z >= 100)
    {
        m_flee.m_z -= (m_position.m_z/2);
    }
}
bool Boid::pathInterectsSphere(ngl::Vec3 ahead, ngl::Vec3 halfAhead, ngl::Vec3 _threatPosition, float _radius)
//threat could be boid or obstacle
// _radius should be bounding sphere of boid (boid->getAvoidRadius()) or obstacle (size);
{
    return ((ahead - _threatPosition).length() <= _radius || (halfAhead - _threatPosition).length() <= _radius);
}
