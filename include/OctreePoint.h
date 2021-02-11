#ifndef OCTREEPOINT_H
#define OCTREEPOINT_H

#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

class OctreePoint {

public:

    OctreePoint() { }
    OctreePoint(const glm::vec4 &_data) : m_data(_data) { }

    inline const glm::vec4& getData() const
    {
        return m_data;
    }

    inline void setData(const glm::vec4 &_data)
    {
        m_data = _data;
    }
private:
    glm::vec4 m_data;
};

#endif // OCTREEPOINT_H
