#ifndef OCTREE_H
#define OCTREE_H

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <OctreePoint.h>
#include <vector>

class Octree
{
public:
    Octree(glm::vec3 _origin, float _halfDimension, int _height);
    Octree(const Octree &_octree);
    ~Octree();

    bool isLeafNode();
    int getOctantContainingPoint(const glm::vec3 _data);
    void insert(OctreePoint * _point);
    void getPointsInsideBox(glm::vec3 &_boxMin, glm::vec3 &_boxMax, std::vector<OctreePoint *> &_results);
    void clearData();
    OctreePoint *m_data;
    std::vector<Octree *> m_children; //pointer to child octants
private:
    glm::vec3 m_origin; //center of the current node
    float m_halfDimension; //half the dimensions of the node
    //bool m_isLeaf;
    int m_height;
};

#endif // OCTREE_H
