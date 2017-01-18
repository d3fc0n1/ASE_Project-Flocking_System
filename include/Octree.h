#ifndef OCTREE_H
#define OCTREE_H

#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <vector>

class Octree
{
public:
    Octree(ngl::Vec3 _origin, ngl::Vec3 _halfDimension);
    Octree(const Octree &_octree);
    ~Octree();

    bool isLeafNode();
    int getOctantContainingPoint(const ngl::Vec3 _data);
    void insert(ngl::Vec4 _data);
    void getPointsInsideBox(ngl::Vec3 &_boxMin, ngl::Vec3 &_boxMax, std::vector<ngl::Vec4> &_results);
    void clearData();
    std::vector<ngl::Vec4> m_data;

private:
    ngl::Vec3 m_origin;
    ngl::Vec3 m_halfDimension;
    std::vector<Octree> m_children;
    bool m_isLeaf;
};

#endif // OCTREE_H
