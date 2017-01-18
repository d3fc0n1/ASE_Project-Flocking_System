#include "Octree.h"
#include <math.h>
#include <iostream>

Octree::Octree(ngl::Vec3 _origin, ngl::Vec3 _halfDimension) : m_origin(_origin), m_halfDimension(_halfDimension)
{
    m_children.clear();
}

Octree::Octree(const Octree &_octree)
{
    m_halfDimension = _octree.m_halfDimension;
    m_origin = _octree.m_origin;
    m_data = _octree.m_data;
}

Octree::~Octree()
{
    m_children.clear();
}

bool Octree::isLeafNode()
{
    return (m_children.size() == 0);
}

int Octree::getOctantContainingPoint(ngl::Vec3 _data)
{
    int octant = 0;
    if(_data.m_x >= m_origin.m_x) octant |= 4;
    if(_data.m_y >= m_origin.m_y) octant |= 2;
    if(_data.m_z >= m_origin.m_z) octant |= 1;
    return octant;
}
#include <iostream>
void Octree::insert(ngl::Vec4 _data)
{
    if (isLeafNode())
    {
        if (m_data.size() == 0)
        {
            m_data.push_back(_data);
            return;
        }
        else
        {
            ngl::Vec4 currentData = m_data[0];
            m_data.clear();

            for(int i=0; i<8; ++i)
            {
                ngl::Vec3 newOrigin = m_origin;
                newOrigin.m_x += m_halfDimension.m_x * (i&4 ? 0.5f : -0.5f);
                newOrigin.m_y += m_halfDimension.m_y * (i&2 ? 0.5f : -0.5f);
                newOrigin.m_z += m_halfDimension.m_z * (i&1 ? 0.5f : -0.5f);
                Octree child (newOrigin, m_halfDimension * 0.5f);
                m_children.push_back(child);
//                std::cout<<"child x : "<<child.m_origin.m_x<<'\n';
//                std::cout<<"child y : "<<child.m_origin.m_y<<'\n';
//                std::cout<<"child z : "<<child.m_origin.m_z<<'\n';
            }
            m_children[getOctantContainingPoint(currentData.toVec3())].insert(currentData);
            m_children[getOctantContainingPoint(_data.toVec3())].insert(_data);
        }
    }
    else
    {
        int octant = getOctantContainingPoint(_data.toVec3());
        m_children[octant].insert(_data);
    }
}

void Octree::getPointsInsideBox(ngl::Vec3 &_boxMin, ngl::Vec3 &_boxMax, std::vector<ngl::Vec4> &_results)
{
    if(isLeafNode())
    {
        if (m_data.size() != 0)
        {
            for (size_t i=0;i<m_data.size();++i)
            {
                if (m_data[i].m_x > _boxMax.m_x || m_data[i].m_y > _boxMax.m_y || m_data[i].m_z > _boxMax.m_z) return;
                if (m_data[i].m_x < _boxMin.m_x || m_data[i].m_y < _boxMin.m_y || m_data[i].m_z < _boxMin.m_z) return;
                _results.push_back(m_data[i]);
            }
        }
    }
    else
    {
        for(int i=0;i<8;++i)
        {
            ngl::Vec3 max = m_children[i].m_origin + m_children[i].m_halfDimension;
            ngl::Vec3 min = m_children[i].m_origin - m_children[i].m_halfDimension;


            if (max.m_x < _boxMin.m_x || max.m_y < _boxMin.m_y || max.m_z < _boxMin.m_z) continue;
            if (min.m_x > _boxMax.m_x || min.m_y > _boxMax.m_y || min.m_z > _boxMax.m_z) continue;

            m_children[i].getPointsInsideBox(_boxMin, _boxMax, _results);
        }
    }
}

void Octree::clearData()
{
    if (!m_isLeaf)
    {
        for(int i=0;i<8;++i)
        {
            m_children[i].clearData();
        }
    }
    m_data.clear();
}
