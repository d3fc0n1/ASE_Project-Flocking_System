#ifndef OCTREEPOINT_H
#define OCTREEPOINT_H

#include <ngl/Vec4.h>
#include <ngl/Vec3.h>

class OctreePoint {



public:

    OctreePoint() { }
    OctreePoint(const ngl::Vec4 &_data) : m_data(_data) { }

    inline const ngl::Vec4& getData() const
    {
        return m_data;
    }

    inline void setData(const ngl::Vec4 &_data)
    {
        m_data = _data;
    }
private:
    ngl::Vec4 m_data;
};

#endif // OCTREEPOINT_H
