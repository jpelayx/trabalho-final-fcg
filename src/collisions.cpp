#include <glm/vec4.hpp>
#include <cmath>
#include <iostream>
#include "matrices.h"

using namespace std;

//https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
bool collisionCubeCube(glm::vec4 bb1min, glm::vec4 bb1max, glm::vec4 bb2min, glm::vec4 bb2max) {
    // std::cout << " bb1min " <<bb1min.x <<" " << bb1min.y << " " << bb1min.z << " bb1max " << bb1max.x << " " << bb1max.y << " " << bb1max.z << std::endl;
    std::cout << " bb2min " <<bb2min.x <<" " << bb2min.y << " " << bb2min.z << " bb2max " << bb2max.x << " " << bb2max.y << " " << bb2max.z << std::endl;
    //bool colx = min(bb1min.x, bb1max.x) <= max(bb2min.x, bb2max.x) && max(bb1min.x, bb1max.x) >= min(bb2min.x, bb2max.x);
    //bool coly = min(bb1min.y, bb1max.y) <= max(bb2min.y, bb2max.y) && max(bb1min.y, bb1max.y) >= min(bb2min.y, bb2max.y);
    //bool colz = min(bb1min.z, bb1max.z) <= max(bb2min.z, bb2max.z) && max(bb1min.z, bb1max.z) >= min(bb2min.z, bb2max.z);
    bool colx = bb1min.x <= bb2max.x && bb1max.x >= bb2min.x;
    bool coly = bb1min.y <= bb2max.y && bb1max.y >= bb2min.y;
    bool colz = bb1min.z <= bb2max.z && bb1max.z >= bb2min.z;
    // std::cout << "COLISAO" << (colx && coly && colz) << std::endl;
    return colx && coly && colz;
}

//http://www.miguelcasillas.com/?p=43
bool collisionCubePlane(glm::vec4 bbcmin, glm::vec4 bbcmax, glm::vec4 bbpmin, glm::vec4 bbpmax) {
    // glm::vec4 vec1 = bbpmin - bbcmin;
    // glm::vec4 vec2 = bbpmin - bbcmax;
    return false;
}

bool collisionCubeSphere(glm::vec4 bbcubemin, glm::vec4 bbcubemax, glm::vec4 bbspheremin, glm::vec4 bbspheremax) {
    glm::vec4 temp = (bbspheremax - bbspheremin) * 0.5f;
    glm::vec4 sphereCenter = bbspheremin + temp;

    float radius = (sqrt((bbspheremin.x - sphereCenter.x) * (bbspheremin.x-sphereCenter.x) +
                         (bbspheremin.y - sphereCenter.y) * (bbspheremin.y-sphereCenter.y) +
                         (bbspheremin.z - sphereCenter.z) * (bbspheremin.z-sphereCenter.z)))/1.7320;
    float x = (fabs(bbcubemin.x - sphereCenter.x) < fabs(bbcubemax.x - sphereCenter.x))? bbcubemin.x: bbcubemax.x;
    float y = (fabs(bbcubemin.y - sphereCenter.y) < fabs(bbcubemax.y - sphereCenter.y))? bbcubemin.y: bbcubemax.y;
    float z = (fabs(bbcubemin.z - sphereCenter.z) < fabs(bbcubemax.z - sphereCenter.z))? bbcubemin.z: bbcubemax.z;
    float distance = sqrt((x - sphereCenter.x) * (x-sphereCenter.x) +
                          (y - sphereCenter.y) * (y-sphereCenter.y) +
                          (z - sphereCenter.z) * (z-sphereCenter.z));

    return distance <= radius;
}

bool collisionSphereSphere(glm::vec4 bb1min, glm::vec4 bb1max, glm::vec4 bb2min, glm::vec4 bb2max) {
    glm::vec4 temp1 = (bb1max - bb1min) * 0.5f;
    glm::vec4 sphereCenter1 = bb1min + temp1;
    float radius1 = (sqrt((bb1min.x - sphereCenter1.x) * (bb1min.x-sphereCenter1.x) +
                         (bb1min.y - sphereCenter1.y) * (bb1min.y-sphereCenter1.y) +
                         (bb1min.z - sphereCenter1.z) * (bb1min.z-sphereCenter1.z)))/1.7320;

    glm::vec4 temp2 = (bb2max - bb2min) * 0.5f;
    glm::vec4 sphereCenter2 = bb2min + temp2;
    float radius2 = (sqrt((bb2min.x - sphereCenter2.x) * (bb2min.x-sphereCenter2.x) +
                         (bb2min.y - sphereCenter2.y) * (bb2min.y-sphereCenter2.y) +
                         (bb2min.z - sphereCenter2.z) * (bb2min.z-sphereCenter2.z)))/1.7320;

    float distance = sqrt((sphereCenter2.x - sphereCenter1.x) * (sphereCenter2.x - sphereCenter1.x) +
                          (sphereCenter2.y - sphereCenter1.y) * (sphereCenter2.y - sphereCenter1.y) +
                          (sphereCenter2.z - sphereCenter1.z) * (sphereCenter2.z - sphereCenter1.z));
    return distance <= radius1 + radius2;
}
