#include <glm/vec3.hpp>
#include <cmath>

glm::vec3 bezier(float time, float period, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4) {
    float t = (time/period) - floor(time/period);
    return (1-t)*(1-t)*(1-t)*p1 +
            3*t*(1-t)*(1-t)*p2 +
            3*t*t*(1-t)*p3 +
            t*t*t*p4;
}

vector<glm::vec3> randomCubicBezier(glm::vec3 min, glm::vec3 max)
{
    vector<glm::vec3> pts;

    // primeiro ponto, obrigatório começar no chão 
    glm::vec3 p0 = glm::vec3( (max.x - min.x)*(rand()/RAND_MAX) + min.x,
                              0.0f, 
                              (max.z - min.z)*(rand()/RAND_MAX) + min.z );
    // segundo ponto em diante, nenhuma outra restrição
    glm::vec3 p1 = glm::vec3( (max.x - min.x)*(rand()/RAND_MAX) + min.x,
                              (max.y - min.y)*(rand()/RAND_MAX) + min.y, 
                              (max.z - min.z)*(rand()/RAND_MAX) + min.z );
    glm::vec3 p2 = glm::vec3( (max.x - min.x)*(rand()/RAND_MAX) + min.x,
                              (max.y - min.y)*(rand()/RAND_MAX) + min.y, 
                              (max.z - min.z)*(rand()/RAND_MAX) + min.z );
    glm::vec3 p3 = glm::vec3( (max.x - min.x)*(rand()/RAND_MAX) + min.x,
                              (max.y - min.y)*(rand()/RAND_MAX) + min.y, 
                              (max.z - min.z)*(rand()/RAND_MAX) + min.z );
    
    cout << rand()/RAND_MAX << endl;
    
    pts.push_back(p0);
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);

    return pts;
}