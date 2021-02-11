#include "Boid.h"
#include <math.h>
#include <iostream>
#include <ngl/Random.h>
//-------------------------------CTOR----------------------------------
Boid::Boid(int _id)
    :
    m_id(_id),
    m_flee(glm::vec3(0.0f, 0.0f, 0.0f),
    m_centroid(glm::vec3(0.0f, 0.0f, 0.0f),
    m_threatPosition(glm::vec3(0.0f, 0.0f, 0.0f),
    m_hasLeader(false),
    m_isLeader(false),
    m_isPredator(false),
    m_hasPredator(false),
    m_slowingRadius(10.0f),
    m_viewRadius(50.0f),
    m_separationRadius(20.f),
    m_leaderFollowDistance(5.0f),
    m_maxSeeAhead(30.0f),
    m_avoidRadius(10.0f),
    m_wanderAzimuthChange(4.0f),
    m_wanderAngleChange(2.0f),
    m_wanderAzimuth(ngl::Random::instance()->randomNumber() * 5),
    m_wanderAngle(ngl::Random::instance()->randomNumber() * 10),
    m_wanderSphereRadius(2.0f),
    m_wanderSphereDistance(50.0f),
    m_maxVelocity(5.0f),
    m_avoidWeight(10.0f), //avoidance force weight
    m_cohesionWeight(4.0f), //cohesion weight
    m_alignmentWeight(3.0f), //alignment weight
    m_separationWeight(1.0f),
    m_leader(nullptr),
    m_predator(nullptr)
{}

Boid::~Boid()
{
    delete m_leader;
    delete m_predator;
}

//---------------------------SET ATTRIBUTES-----------------------------
void Boid::setId(int _id)
{
    m_id = _id;
}
void Boid::setSpeed(float _speed)
{
    //m_speed = _speed;
}
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
void Boid::setPosition(glm::vec3 _position)
{
    m_position.set(_position);
}
void Boid::setVelocity(glm::vec3 _velocity)
{
    m_velocity.set(_velocity);
}
void Boid::setLeader(Boid *_leader)
{
    m_leader = _leader;
    m_hasLeader = true;
}
void Boid::setPredator(Boid *_predator)
{
    m_predator = _predator;
    m_hasLeader = false;
    m_hasPredator = true;
    m_isLeader = false;
}
void Boid::setNeighbours(Boid *_boid)
{
    if (_boid->getId() > 0) m_neighbours.push_back(_boid); //dont consider dead ones.
}
void Boid::setCentroid()
{
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            m_centroid += m_neighbours[i]->getPosition();
        }
        m_centroid /= (m_neighbours.size());
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
void Boid::makePredator()
{
  m_isPredator = true;
  m_hasLeader = false;
  m_leader = 0;
}

//---------------------------FLOCKING RULES----------------------------------
void Boid::setCohesion() //push to flock center using average flock position
{
    setCentroid();
    if (m_neighbours.size() > 0)
    {
        m_cohesion = m_centroid - m_position;
        if(m_cohesion.length()!=0)
        {
            m_cohesion.normalize();
        }
    }
    else
    {
        m_cohesion.set(0.0f, 0.0f, 0.0f);
    }
}
void Boid::setAlignment() //align velocity using average flock velocity
{
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            m_alignment += m_neighbours[i]->getVelocity();
        }
        m_alignment /= m_neighbours.size();
        if (m_alignment.length() !=0)
        {
            m_alignment.normalize();
        }
    }
    else
        m_alignment.set(0.0f, 0.0f, 0.0f);
}
void Boid::setSeparation() //check for distance from neighbour and move away if too close
{
    if (m_neighbours.size() > 0)
    {
        for (size_t i = 0; i < m_neighbours.size(); ++i)
        {
            if ((m_neighbours[i]->getPosition() - m_position).length() > m_separationRadius)
            {
                glm::vec3 neighbourPosition(m_neighbours[i]->getPosition());
                glm::vec3 targetPosition = m_position - neighbourPosition;
                m_separation += targetPosition;
            }
        }
        m_separation /= m_neighbours.size();
        if(m_separation.length()!=0)
        {
            m_separation.normalize();
        }
    }
    else
    {
        m_separation.set(0.0f,0.0f,0.0f);
    }
}

//-------------------------STEERING BEHVIOURS---------------------------
void Boid::setPursuit(glm::vec3 _pursuePosition, glm::vec3 _pursueVelocity)
//sets a target to seek - pass food position zero velocity
//or flock centroid and average flock velocity for predator
{
    m_pursuit = glm::vec3(0,0,0);
    glm::vec3 pursuitVector = _pursuePosition - m_position;
    int frames = pursuitVector.length() / m_maxVelocity;
    m_target = _pursuePosition + _pursueVelocity * frames;

    //apply smooth arrival
    glm::vec3 desiredVelocity = m_target - m_position;
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
    m_pursuit = desiredVelocity - m_velocity;
}

void Boid::resetPursuit()
{
    m_pursuit = glm::vec3::zero();
}

void Boid::setFlee(glm::vec3 _fleePosition) //needs m_target to function
{
    if ((m_position - _fleePosition).length() < 30)
    {
        m_flee = m_position - _fleePosition;
        if (m_flee.length() != 0) m_flee.normalize();
    }
}
void Boid::evade(Boid *_boid) //sets a target for fleeing- pass predator boid
{
    glm::vec3 distance = _boid->getPosition() - m_position;
    int frames = distance.length() / m_maxVelocity;
    m_target = _boid->getPosition() + _boid->getVelocity() * frames;
    setFlee(_boid->getPosition());
}
void Boid::setWander() //sets m_wander
{
    glm::vec3 sphereCenter = m_velocity;
    if (sphereCenter.length() !=0)
    {
        sphereCenter.normalize();
    }
    sphereCenter *= m_wanderSphereDistance;

    glm::vec3 displacement;

    displacement.m_x = m_wanderSphereRadius * cos(m_wanderAngle) * sin(m_wanderAzimuth);
    displacement.m_y = m_wanderSphereRadius * sin(m_wanderAngle) * sin(m_wanderAzimuth);
    displacement.m_z = m_wanderSphereRadius * tan(m_wanderAngle);

    m_wanderAngle += ngl::Random::instance()->randomNumber() * m_wanderAngleChange - m_wanderAngleChange * 0.5f;
    m_wanderAzimuth += ngl::Random::instance()->randomNumber() * m_wanderAzimuthChange - m_wanderAzimuthChange * 1.0f;

    m_wander = sphereCenter + displacement;
}
void Boid::setAvoid() //call for every neighbour
{
    for(size_t i=0; i<m_neighbours.size();++i)
    {
        pathIntersectsSphere(m_neighbours[i]->getPosition(), m_neighbours[i]->getViewRadius());
    }

    if(m_velocity.length()!=0)
    {
        m_velocity.normalize();
    }
    m_avoid=glm::vec3(0,0,0);
    glm::vec3 ahead = m_position + m_velocity * m_maxSeeAhead;


    if (m_threatPosition != glm::vec3(0.0f,0.0f,0.0f))
    {
        m_avoid = ahead - m_threatPosition;
        if (m_avoid.length() != 0)
        {
                m_avoid.normalize();
        }
    }
    else
    {
        m_avoid.set(0.0f,0.0f,0.0f);
    }
    m_threatPosition.set(0.0f,0.0f,0.0f); //reset threat position every iternation
}
void Boid::pathIntersectsSphere(glm::vec3 _obstaclePosition, float _obstacleSize)
{

    glm::vec3 ahead(m_position + m_velocity * m_maxSeeAhead);
    glm::vec3 halfAhead = ahead * 0.5;

    bool collision = ((ahead - _obstaclePosition).length() <= _obstacleSize || (halfAhead - _obstaclePosition).length() <= _obstacleSize || (_obstaclePosition - m_position).length() <= _obstacleSize);
    if (collision && (m_threatPosition == glm::vec3(0.0f,0.0f,0.0f) || ((_obstaclePosition - m_position).length() <  (m_threatPosition - m_position).length())))
    {
        m_threatPosition = _obstaclePosition;
    }
}
void Boid::setFollow() //sets m_follow
{
    glm::vec3 leaderVelocity = m_leader->getVelocity();
    leaderVelocity.normalize();
    glm::vec3 ahead = m_leader->getPosition() + leaderVelocity * m_leaderFollowDistance;
    glm::vec3 behind = m_leader->getPosition() - leaderVelocity * m_leaderFollowDistance;

    if ((m_position - ahead).length() <= m_viewRadius || (m_leader->getPosition() - m_position).length() <= m_viewRadius)
    {
        evade(m_leader);
        m_follow += m_flee;
    }

    // apply smooth arrival
    glm::vec3 desiredVelocity = behind - m_position;
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
    m_flee.set(0,0,0);
    setCohesion();
    setAlignment();
    setSeparation();
    fleeWalls();

    m_alignment *= m_alignmentWeight;
    m_separation *= m_separationWeight;
    m_cohesion *= m_cohesionWeight;

    setAvoid();

    m_avoid *= m_avoidWeight;

    //if (m_predator != 0) evade(m_predator);
    m_steering = m_flee + m_avoid; //basic rules, common for all.

    if(m_isLeader)
    {
        setWander();
        m_steering +=  m_wander;
    }
    else //not leader
    {
        m_steering += m_cohesion + m_alignment + m_separation;

        if(m_hasLeader)
        {
            setFollow();
            m_steering += m_follow;
        }
        else //not leader, no leader
        {
            if(m_isPredator)
            {
                if (m_neighbours.size() > 0)
                {
                    glm::vec3 flockVelocity;
                    for (size_t i = 0; i < m_neighbours.size(); ++i)
                    {
                        flockVelocity += m_neighbours[i]->getVelocity();
                    }
                    flockVelocity /= (m_neighbours.size() + 1);
                    setPursuit(m_centroid, flockVelocity);
                }
            }
            else
            {
                if (m_hasPredator)
                {
                    evade(m_predator);
                    m_steering += m_flee;
                }
                else
                {
                    setWander();
                    m_steering += m_wander + m_pursuit;
                }
            }
        }

    }

    if (m_steering.length() != 0)
        m_steering.normalize();
}
//-------------------------------MOVEMENT----------------------------------
void Boid::move()
{
    if (m_id > 0)
    {
        setSteering();
        m_velocity += m_steering;
        m_velocity.normalize();
        m_position += m_velocity;
        rotate();
    }
    else
    {
        m_velocity -= glm::vec3(0.0f,0.1f, 0.0f);
        if (m_position.m_y >= -100)
        {
            m_position += m_velocity;
            //rotate(); //nose-down
        }
        else
        {
            m_id = -1;
        }
    }
}
void Boid::rotate()
{
    m_roll = atan2(m_velocity.m_x, m_velocity.m_y) * 180/M_PI;
    m_yaw = atan2(m_velocity.m_x, m_velocity.m_z) * 180/M_PI + 180;
    m_pitch = atan2(m_velocity.m_y,sqrt(m_velocity.m_x*m_velocity.m_x+m_velocity.m_z*m_velocity.m_z))*180/M_PI;
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
