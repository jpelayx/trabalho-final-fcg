#include <glm/vec4.hpp>
#include <cmath>
#include <iostream>

//https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
bool collisionCubeCube(glm::vec4 bb1min, glm::vec4 bb1max, glm::vec4 bb2min, glm::vec4 bb2max) {
    bool colx = bb1min.x <= bb2max.x && bb1max.x >= bb2min.x;
    bool coly = bb1min.y <= bb2max.y && bb1max.y >= bb2min.y;
    bool colz = bb1min.z <= bb2max.z && bb1max.z >= bb2min.z;
    return colx && coly && colz;
}

bool collisionCubeSphere(glm::vec4 bbcubemin, glm::vec4 bbcubemax, glm::vec4 bbspheremin, glm::vec4 bbspheremax) {
    glm::vec4 temp = (bbspheremax - bbspheremin) * 0.5f;
    glm::vec4 sphereCenter = bbspheremin + temp;
    
    float radius = (sqrt((bbspheremin.x - sphereCenter.x) * (bbspheremin.x-sphereCenter.x) + 
                         (bbspheremin.y - sphereCenter.y) * (bbspheremin.y-sphereCenter.y) + 
                         (bbspheremin.z - sphereCenter.z) * (bbspheremin.z-sphereCenter.z)));
    float x = std::max(bbcubemin.x, std::min(sphereCenter.x, bbcubemax.x));
    float y = std::max(bbcubemin.y, std::min(sphereCenter.y, bbcubemax.y));
    float z = std::max(bbcubemin.z, std::min(sphereCenter.z, bbcubemax.z));
    float distance = sqrt((x - sphereCenter.x) * (x-sphereCenter.x) + 
                          (y - sphereCenter.y) * (y-sphereCenter.y) + 
                          (z - sphereCenter.z) * (z-sphereCenter.z));

    std::cout << radius << " JFIUEAHFIA " << (distance <= radius) << std::endl;                
    return distance <= radius;
}

bool collisionSphereSphere(glm::vec4 bb1min, glm::vec4 bb1max, glm::vec4 bb2min, glm::vec4 bb2max) {
    glm::vec4 temp1 = (bb1max - bb1min) * 0.5f;
    glm::vec4 sphereCenter1 = bb1min + temp1;
    float radius1 = temp1.y;

    glm::vec4 temp2 = (bb2max - bb2min) * 0.5f;
    glm::vec4 sphereCenter2 = bb2min + temp2;
    float radius2 = temp2.y;

    float distance = sqrt((sphereCenter2.x - sphereCenter1.x) * (sphereCenter2.x - sphereCenter1.x) + 
                          (sphereCenter2.y - sphereCenter1.y) * (sphereCenter2.y - sphereCenter1.y) + 
                          (sphereCenter2.z - sphereCenter1.z) * (sphereCenter2.z - sphereCenter1.z));
    return distance <= radius1 + radius2;
}
