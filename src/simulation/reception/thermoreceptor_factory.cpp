#include "thermoreceptor_factory.hpp"
#include "thermoreceptor.hpp"

ThermoreceptorFactory::ThermoreceptorFactory() {
    configMap[ThermoreceptorType::WARMTH_RECEPTOR]  = {35.f, 3.f, -0.5f, 38.f};
    configMap[ThermoreceptorType::COLD_RECEPTOR]    = {40.f, 1.5f, 0.5f, 32.f};
    configMap[ThermoreceptorType::HEAT_NOCICEPTOR]  = {80.f, 0.8f, -1.5f, 43.f};
    configMap[ThermoreceptorType::COLD_NOCICEPTOR]  = {70.f, 1.f, 1.f, 15.f};
}

std::unique_ptr<Thermoreceptor> ThermoreceptorFactory::create(ThermoreceptorType type, const glm::vec3& position) const {
    auto it = configMap.find(type);

    if (it != configMap.end()) {
        return std::make_unique<Thermoreceptor>(position, it->second);
    }

    return nullptr;
}
