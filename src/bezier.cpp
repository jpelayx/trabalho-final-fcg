#include <glm/vec3.hpp>
#include <cmath>

glm::vec3 bezier(float time, float period, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4) {
    float t = (time/period) - floor(time/period);
    return (1-t)*(1-t)*(1-t)*p1 +
            3*t*(1-t)*(1-t)*p2 +
            3*t*t*(1-t)*p3 +
            t*t*t*p4;
}