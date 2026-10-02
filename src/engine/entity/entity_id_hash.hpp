#ifndef COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HASH_HPP
#define COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HASH_HPP

#include <cstddef>
#include <functional>

#include "engine/entity/entity_id.hpp"


namespace commuters {

struct EntityIdHash {
    std::size_t operator()(const EntityId& id) const noexcept {
        return std::hash<EntityId::ValueType>{}(id.GetValue());
    }
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HASH_HPP

