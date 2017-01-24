#ifndef BOID_H
#define BOID_H

#include <ngl/Vec3.h>
#include <vector>
#include <ngl/Random.h>

class Boid
{
public:
    Boid(int _id);

    int getId();
    ngl::Vec3 getVelocity();
    ngl::Vec3 getPosition();
    ngl::Vec3 getRotation();
    float getViewRadius();
    float getAvoidRadius();
    bool isLeader();
    int getNeighbourSize();

    //void setSpeed(int _speed);
    void setAlignmentWeight(float _alignmentWeight);
    void setCohesionWeight(float _cohesionWeight);
    void setSeparationWeight(float _separationWeight);
    void setAvoidWeight(float _avoidWeight);
    void setPosition(ngl::Vec3 _position);
    void setVelocity(ngl::Vec3 _velocity);
    void setLeader(Boid *_leader);
    void setNeighbours(Boid *_boid);
    void setCentroid();
    void clearNeighbours();
    void clearLeader();
    void makeLeader();

    void setCohesion();
    void setAlignment();
    void setSeparation();

    void setSeek();
    void pursue(Boid *_boid);

    void setFlee(ngl::Vec3 _fleePosition);
    void evade(Boid *_boid);

    void setWander();
    void setAvoid();
    void setFollow();

    void setSteering();

    void move();
    void rotate();

    void fleeWalls();

    bool pathInterectsSphere(ngl::Vec3 ahead, ngl::Vec3 halfAhead, ngl::Vec3 _threatPosition, float _radius);

private:

    //--------------------ATTRIBUTES--------------------
    int m_id; //ID of boid
    ngl::Vec3 m_position; //position vector
    ngl::Vec3 m_velocity; //velocity vector
    ngl::Vec3 m_centroid; //local flock center
    ngl::Vec3 m_target; // target vector
    float m_slowingRadius = 10.0f; //slowing radius
    float m_maxVelocity = 5.0f; //multiplier for maximum velocity
    float m_wanderSphereDistance = 5.0f;
    float m_wanderSphereRadius = 2.0f;
    float m_wanderAngle = ngl::Random::instance()->randomNumber() * 10;
    float m_wanderAzimuth = ngl::Random::instance()->randomNumber() * 5;
    float m_wanderAngleChange = 2.0f;
    float m_wanderAzimuthChange = 4.0f;
    //int m_wanderIteration = 0;
    float m_avoidRadius = 10.0f; // radius of avoidance sphere of the boid
    float m_avoidWeight; //avoidance force weight
    float m_cohesionWeight; //cohesion weight
    float m_alignmentWeight; //alignment weight
    float m_separationWeight; //separation weight
    float m_maxSeeAhead = 20.0f;// maximum see-ahead distance
    float m_leaderFollowDistance = 10.0f; //leader follow distance
    float m_viewRadius = 30.0f;//view to find leader
    float m_separationRadius = 20.f;//separation radius

    float m_roll; //rotation about x axis -180 to 180
    float m_pitch; //rotation about y axis -90 to 90
    float m_yaw; //rotation about z axis -180 to 180

    ngl::Vec3 m_separation; //separation force vector
    ngl::Vec3 m_alignment; //alignment force vector
    ngl::Vec3 m_cohesion; //cohesion force vector
    ngl::Vec3 m_seek; //seek vector
    ngl::Vec3 m_flee; //flee vector
    ngl::Vec3 m_wander; //wander vector
    ngl::Vec3 m_avoid;//collision avoidance vector;
    ngl::Vec3 m_follow;//leader following vector
    ngl::Vec3 m_threatPosition;//position vector of the most threatening object in path- obstacle or other boids.
    ngl::Vec3 m_steering; //sum of all steering vectors

    bool m_isLeader; // flag for leader boid
    bool m_hasLeader;

    Boid *m_leader; //leader boid to follow
    Boid *m_predator; //predator boid to flee;

    std::vector<Boid *> m_neighbours; //vector for storing all neighbours
};

#endif // BOID_H
