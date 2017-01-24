#ifndef OCTREE_H
#define OCTREE_H

#include <ngl/Vec3.h>
#include <ngl/Vec4.h>
#include <OctreePoint.h>
#include <vector>

class Octree
{
public:
    Octree(ngl::Vec3 _origin, float _halfDimension, int _height);
    Octree(const Octree &_octree);
    ~Octree();

    bool isLeafNode();
    int getOctantContainingPoint(const ngl::Vec3 _data);
    void insert(OctreePoint * _point);
    void getPointsInsideBox(ngl::Vec3 &_boxMin, ngl::Vec3 &_boxMax, std::vector<OctreePoint *> &_results);
    void clearData();
    OctreePoint *m_data;
    std::vector<Octree *> m_children; //pointer to child octants
private:
    ngl::Vec3 m_origin; //center of the current node
    float m_halfDimension; //half the dimensions of the node
    //bool m_isLeaf;
    int m_height;
};

#endif // OCTREE_H
