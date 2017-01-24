#include "Obstacle.h"

Obstacle::Obstacle(ngl::Vec3 _position, float _size, std::string _shape)
{
    m_position = _position;
    m_size = _size;
    m_shape = _shape;
}
float Obstacle::getSize()
{
    return m_size;
}

void Obstacle::setSize(float _size)
{
    m_size = _size;
}

void Obstacle::setPosition(ngl::Vec3 _position)
{
    m_position = _position;
}

ngl::Vec3 Obstacle::getPosition()
{
    return m_position;
}

std::string Obstacle::getShape()
{
    return m_shape;
}
