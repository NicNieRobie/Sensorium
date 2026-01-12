#include "thermoreceptor.hpp"
#include <algorithm>

Thermoreceptor::Thermoreceptor(glm::vec3 position, const ThermoreceptorConfig& config)
    : position(position), config(config) {}

float Thermoreceptor::activation(float temperature) const {
    return 1.f / (1.f + std::exp(config.sigmSlope * (temperature - config.sigmMidpoint)));
}

float Thermoreceptor::update(float temperature, float dt) {
    float act = activation(temperature);

    adaptedActivation += (act - adaptedActivation) * (dt / config.tau);
    adaptedActivation = std::clamp(adaptedActivation, 0.0f, 1.0f);

    return config.maxRate * adaptedActivation;
}
