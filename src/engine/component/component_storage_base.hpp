#ifndef COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_BASE_HPP
#define COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_BASE_HPP

#include "engine/entity/entity_id.hpp"

namespace commuters {

class IComponentStorage {
public:
    virtual ~IComponentStorage() = default;
    virtual bool Remove(EntityId id) = 0;
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_BASE_HPP

