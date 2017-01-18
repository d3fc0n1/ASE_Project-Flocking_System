#include "Boid.h"
#include <random>
#include <math.h>

//-------------------------------CTOR----------------------------------
Boid::Boid(int _id)
{
    m_id=_id;

    setPosition(ngl::Vec3(0.0f, 0.0f, 0.0f));
    setVelocity(ngl::Vec3(1.0f, 0.0f, 0.0f));
    m_flee.set(ngl::Vec3(0.0f, 0.0f, 0.0f));
    m_centroid.set(ngl::Vec3(0.0f, 0.0f, 0.0f));
    m_hasLeader=false;
    m_isLeader=false;
    m_slowingRadius = 10.0f;

    //m_maxSpeed=2.0f;
    //m_speed=0.5f;
    //m_senseRadius = 50.0f;
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
ngl::Vec3 Boid::getVelocity()
{
    return m_velocity;
}
bool Boid::isLeader()
{
    return m_isLeader;
}
//float Boid::getSenseRadius()
//{
//    return m_senseRadius;
//}
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
  //m_senseRadius = 8;
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
            if (m_position.distanceTo(m_neighbours[i]->getPosition()) > m_separationRadius)
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

void Boid::setFlee() //needs m_target to function
{
    ngl::Vec3 desiredVelocity = m_position - m_target;
    desiredVelocity.normalize();
    desiredVelocity *= m_maxVelocity;
    m_flee = desiredVelocity - m_velocity;
}
void Boid::evade(Boid *_boid) //sets a target for fleeing
{
    ngl::Vec3 distance = _boid->getPosition() - m_position;
    int frames = distance.length() / m_maxVelocity;
    m_target = _boid->getPosition() + _boid->getVelocity() * frames;
    setFlee();
}

void Boid::setWander() //sets m_wander
{
    ngl::Vec3 circleCenter = m_velocity;
    if (circleCenter.length() !=0)
    {
        circleCenter.normalize();
    }
    circleCenter *= m_wanderCircleDistance;
    ngl::Vec3 displacement(0,0,-1);
    displacement.m_x = cos(m_wanderAngle) * displacement.length();
    displacement.m_y = sin(m_wanderAngle) * displacement.length();
    m_wanderAngle += rand() * m_wanderAngleChange - m_wanderAngleChange * 0.5f;

    m_wander = circleCenter + displacement;
}
void Boid::setAvoid() //sets m_threat, m_avoid
{
    ngl::Vec3 ahead = m_position + (m_velocity / m_velocity.length()) * m_maxSeeAhead;
    ngl::Vec3 halfAhead = ahead * 0.5;
    m_threat = 0;
    for (size_t i = 0; i<= m_neighbours.size(); ++i)
    {
        bool collision = pathInterectsSphere(ahead, halfAhead, m_neighbours[i]);
        if (collision && (m_threat == 0 || (m_position.distanceTo(m_neighbours[i]->getPosition()) <  m_position.distanceTo(m_threat->getPosition()))))
        {
            m_threat = m_neighbours[i];
        }
    }
    m_avoid.set(0.0f,0.0f,0.0f);
    if (m_threat != 0)
    {
        m_avoid = ahead - m_threat->getPosition();
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

    if (ahead.distanceTo(m_position) <= m_viewRadius || m_leader->getPosition().distanceTo(m_position) <= m_viewRadius)
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
    setCohesion();
    setAlignment();
    setSeparation();
    m_steering + m_cohesion + m_alignment + m_separation; //basic rules, common for all.
    if(m_isLeader)
    {
        setWander();
        setAvoid();
        m_steering +=  m_wander + m_avoid;
    }
    else //not leader
    {
        if(m_hasLeader)
        {
            setFollow();
            setAvoid();
            m_steering += m_follow + m_avoid;
        }
        else //not leader, no leader
        {
            setWander();
            m_steering += m_wander;
        }
    }
    //if predator exists, Evade
    //if moving target exists, pursue
}
//-------------------------------MOVEMENT----------------------------------
void Boid::move()
{
    m_velocity += m_steering;
    m_velocity.limit(m_maxVelocity);
    m_position += m_velocity;
}

//--------------------------------OTHERS------------------------------------
void Boid::fleeWalls()
{
    if (m_position.m_x <= -25 || m_position.m_x >= 25)
    {
        m_flee.m_x -= (m_position.m_x / 2);
    }
    if (m_position.m_y <= -25 || m_position.m_y >= 25)
    {
        m_flee.m_y -= (m_position.m_y / 2);
    }
    if (m_position.m_z <= -25 || m_position.m_z >= 25)
    {
        m_flee.m_z -= (m_position.m_z / 2);
    }
}
bool Boid::pathInterectsSphere(ngl::Vec3 ahead, ngl::Vec3 halfAhead, Boid *_boid)
{
    return (_boid->getPosition().distanceTo(ahead) <= m_avoidRadius || _boid->getPosition().distanceTo(halfAhead) <= m_avoidRadius);
}
