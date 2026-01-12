#pragma once

#include <glm/glm.hpp>

enum class ThermoreceptorType {
    WARMTH_RECEPTOR,
    COLD_RECEPTOR,
    HEAT_NOCICEPTOR,
    COLD_NOCICEPTOR
};

struct ThermoreceptorConfig {
    float maxRate;
    float tau;
    float sigmSlope;
    float sigmMidpoint;
};

class Thermoreceptor {
protected:
    glm::vec3 position;
    
    float adaptedActivation = 0.0f;

    const ThermoreceptorConfig& config;

public:
    Thermoreceptor(glm::vec3 position, const ThermoreceptorConfig& config);

    virtual ~Thermoreceptor() = default;

    glm::vec3 getPosition() { return position; }

    float activation(float temperature) const;
    float update(float temperature, float dt);
};
