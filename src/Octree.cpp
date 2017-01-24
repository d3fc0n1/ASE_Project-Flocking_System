#include "Octree.h"
#include <math.h>
#include <iostream>

Octree::Octree(ngl::Vec3 _origin, float _halfDimension, int _height)
{
    m_origin = _origin;
    m_halfDimension = _halfDimension;
    m_children.clear();
    m_height = _height;
}

Octree::Octree(const Octree &_octree)
{
    m_halfDimension = _octree.m_halfDimension;
    m_origin = _octree.m_origin;
    m_data = _octree.m_data;
    m_height = _octree.m_height;
}

Octree::~Octree()
{
    m_children.clear();
}

bool Octree::isLeafNode()
{
    return (m_height == 1 || m_children.size() == 0);
}

int Octree::getOctantContainingPoint(ngl::Vec3 _data)
{
    int octant = 0;
    if(_data.m_x >= m_origin.m_x) octant |= 4;//bitwise in
    if(_data.m_y >= m_origin.m_y) octant |= 2;
    if(_data.m_z >= m_origin.m_z) octant |= 1;
    return octant;
}

void Octree::insert(OctreePoint *_point)
{
    if (isLeafNode())
    {
        if (!m_data || m_height == 1)
        {
            m_data = _point;
            return;
        }
        else
        {
            OctreePoint *oldPoint = m_data;
            m_data = 0;

            for(int i=0; i<8; ++i)
            {
                ngl::Vec3 newOrigin = m_origin;
                newOrigin.m_x += m_halfDimension * (i&4 ? 0.5f : -0.5f);
                newOrigin.m_y += m_halfDimension * (i&2 ? 0.5f : -0.5f);
                newOrigin.m_z += m_halfDimension * (i&1 ? 0.5f : -0.5f);
                Octree * child  = new Octree (newOrigin, m_halfDimension * 0.5f, m_height - 1);
                m_children.push_back(child);
                //                std::cout<<"child x : "<<child.m_origin.m_x<<'\n';
                //                std::cout<<"child y : "<<child.m_origin.m_y<<'\n';
                //                std::cout<<"child z : "<<child.m_origin.m_z<<'\n';
            }
            m_children[getOctantContainingPoint(oldPoint->getData().toVec3())]->insert(oldPoint);
            m_children[getOctantContainingPoint(_point->getData().toVec3())]->insert(_point);
        }
    }
    else
    {
        int octant = getOctantContainingPoint(_point->getData().toVec3());
        m_children[octant]->insert(_point);
    }
}

void Octree::getPointsInsideBox(ngl::Vec3 &_boxMin, ngl::Vec3 &_boxMax, std::vector<OctreePoint *> &_results)
{
    if(isLeafNode())
    {
        if (m_data != 0)
        {
            const ngl::Vec3 &pos = m_data->getData().toVec3();
            if (pos.m_x > _boxMax.m_x || pos.m_y > _boxMax.m_y || pos.m_z > _boxMax.m_z) return;
            if (pos.m_x < _boxMin.m_x || pos.m_y < _boxMin.m_y || pos.m_z < _boxMin.m_z) return;
            _results.push_back(m_data);
        }
    }
    else
    {
        for(int i=0;i<8;++i)
        {
            ngl::Vec3 max = m_children[i]->m_origin + ngl::Vec3(m_children[i]->m_halfDimension, m_children[i]->m_halfDimension, m_children[i]->m_halfDimension);
            ngl::Vec3 min = m_children[i]->m_origin - ngl::Vec3(m_children[i]->m_halfDimension, m_children[i]->m_halfDimension, m_children[i]->m_halfDimension);

            if (max.m_x < _boxMin.m_x || max.m_y < _boxMin.m_y || max.m_z < _boxMin.m_z) continue;
            if (min.m_x > _boxMax.m_x || min.m_y > _boxMax.m_y || min.m_z > _boxMax.m_z) continue;

            m_children[i]->getPointsInsideBox(_boxMin, _boxMax, _results);
        }
    }
}

void Octree::clearData()
{
    if (!isLeafNode())
    {
        for(int i=0;i<8;++i)
        {
            m_children[i] = 0;
        }
    }
    m_data = 0;
}
