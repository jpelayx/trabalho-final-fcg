#include <glm/vec4.hpp>
#include <cmath>
#include <iostream>
#include "matrices.h"

using namespace std;

//https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection

bool collisionCubeCube(glm::vec4 bb1min, glm::vec4 bb1max, glm::vec4 bb2min, glm::vec4 bb2max) {
    for(int i = 0; i<3; i++) {
        if ((bb1min[i] < bb2min[i] &&  bb1min[i] < bb2max[i] && bb1max[i] < bb2min[i] &&  bb1max[i] < bb2max[i])
            ||
            (bb2min[i] < bb1min[i] &&  bb2min[i] < bb1max[i] && bb2max[i] < bb1min[i] &&  bb2max[i] < bb1max[i]))
            return false;
    }
    return true;
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
