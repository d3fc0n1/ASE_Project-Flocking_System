#include "Octree.h"
#include <math.h>
#include <iostream>

Octree::Octree(glm::vec3 _origin, float _halfDimension, int _height)
{
    m_origin = _origin;
    m_halfDimension = _halfDimension;
    m_children.clear();
    m_height = _height;
    m_data = nullptr;
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

int Octree::getOctantContainingPoint(glm::vec3 _data)
{
    int octant = 0;
    if(_data.x >= m_origin.x) octant |= 4;//bitwise in
    if(_data.y >= m_origin.y) octant |= 2;
    if(_data.z >= m_origin.z) octant |= 1;
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
                glm::vec3 newOrigin = m_origin;
                newOrigin.x += m_halfDimension * (i&4 ? 0.5f : -0.5f);
                newOrigin.y += m_halfDimension * (i&2 ? 0.5f : -0.5f);
                newOrigin.z += m_halfDimension * (i&1 ? 0.5f : -0.5f);
                Octree * child  = new Octree (newOrigin, m_halfDimension * 0.5f, m_height - 1);
                m_children.push_back(child);
            }
            m_children[getOctantContainingPoint(glm::vec3(oldPoint->getData()))]->insert(oldPoint);
            m_children[getOctantContainingPoint(glm::vec3(_point->getData()))]->insert(_point);
        }
    }
    else
    {
        int octant = getOctantContainingPoint(glm::vec3(_point->getData()));
        m_children[octant]->insert(_point);
    }
}

void Octree::getPointsInsideBox(glm::vec3 &_boxMin, glm::vec3 &_boxMax, std::vector<OctreePoint *> &_results)
{
    if(isLeafNode())
    {
        if (m_data != 0)
        {
            const glm::vec3 &pos = glm::vec3(m_data->getData());
            if (pos.x > _boxMax.x || pos.y > _boxMax.y || pos.z > _boxMax.z) return;
            if (pos.x < _boxMin.x || pos.y < _boxMin.y || pos.z < _boxMin.z) return;
            _results.push_back(m_data);
        }
    }
    else
    {
        for(int i=0;i<8;++i)
        {
            glm::vec3 max = m_children[i]->m_origin + glm::vec3(m_children[i]->m_halfDimension, m_children[i]->m_halfDimension, m_children[i]->m_halfDimension);
            glm::vec3 min = m_children[i]->m_origin - glm::vec3(m_children[i]->m_halfDimension, m_children[i]->m_halfDimension, m_children[i]->m_halfDimension);

            if (max.x < _boxMin.x || max.y < _boxMin.y || max.z < _boxMin.z) continue;
            if (min.x > _boxMax.x || min.y > _boxMax.y || min.z > _boxMax.z) continue;

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
