#pragma once

#include "thermoreceptor.hpp"
#include <memory>
#include <unordered_map>

class ThermoreceptorFactory {
private:
    std::unordered_map<ThermoreceptorType, ThermoreceptorConfig> configMap;

public:
    ThermoreceptorFactory();

    std::unique_ptr<Thermoreceptor> create(ThermoreceptorType type, const glm::vec3& position) const;
};
