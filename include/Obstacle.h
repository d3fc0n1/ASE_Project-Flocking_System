#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <ngl/Vec3.h>
#include <string>

class Obstacle
{
public:
    Obstacle(ngl::Vec3 _position, float _size, std::string _shape);

    void setPosition(ngl::Vec3 _position);
    ngl::Vec3 getPosition();
    float getSize();
    void setSize(float _size);
    std::string getShape();

private:
    std::string m_shape;
    ngl::Vec3 m_position;
    float m_size;
};

#endif // OBSTACLE_H
