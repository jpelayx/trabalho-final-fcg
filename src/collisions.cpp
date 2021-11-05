#include <glm/vec3.hpp>
#include <cmath>
//https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
bool collisionCubeCube(glm::vec3 bb1min, glm::vec3 bb1max, glm::vec3 bb2min, glm::vec3 bb2max) {
    bool colx = bb1min.x <= bb2max.x && bb1max.x >= bb2min.x;
    bool coly = bb1min.y <= bb2max.y && bb1max.y >= bb2min.y;
    bool colz = bb1min.z <= bb2max.z && bb1max.z >= bb2min.z;
    return colx && coly && colz;
}

bool collisionCubeSphere(glm::vec3 bbcubemin, glm::vec3 bbcubemax, glm::vec3 bbspheremin, glm::vec3 bbspheremax) {
    glm::vec3 temp = (bbspheremax - bbspheremin) * 0.5f;
    glm::vec3 sphereCenter = bbspheremin + temp;
    float radius = temp.y;
    float x = std::max(bbcubemin.x, std::min(sphereCenter.x, bbcubemax.x));
    float y = std::max(bbcubemin.y, std::min(sphereCenter.y, bbcubemax.y));
    float z = std::max(bbcubemin.z, std::min(sphereCenter.z, bbcubemax.z));
    float distance = sqrt((x - sphereCenter.x) * (x-sphereCenter.x) + 
                          (y - sphereCenter.y) * (y-sphereCenter.y) + 
                          (z - sphereCenter.z) * (z-sphereCenter.z));
    return distance <= radius;
}

bool collisionSphereSphere(glm::vec3 bb1min, glm::vec3 bb1max, glm::vec3 bb2min, glm::vec3 bb2max) {
    glm::vec3 temp1 = (bb1max - bb1min) * 0.5f;
    glm::vec3 sphereCenter1 = bb1min + temp1;
    float radius1 = temp1.y;

    glm::vec3 temp2 = (bb2max - bb2min) * 0.5f;
    glm::vec3 sphereCenter2 = bb2min + temp2;
    float radius2 = temp2.y;

    float distance = sqrt((sphereCenter2.x - sphereCenter1.x) * (sphereCenter2.x - sphereCenter1.x) + 
                          (sphereCenter2.y - sphereCenter1.y) * (sphereCenter2.y - sphereCenter1.y) + 
                          (sphereCenter2.z - sphereCenter1.z) * (sphereCenter2.z - sphereCenter1.z));
    return distance <= radius1 + radius2;
}
