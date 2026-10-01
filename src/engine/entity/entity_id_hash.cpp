#include "engine/entity/entity_id_hash.hpp"

#include <functional>

namespace commuters {

std::size_t EntityIdHash::operator()(const EntityId& id) const noexcept {
    return std::hash<EntityId::ValueType>{}(id.GetValue());
}
} // namespace commuters

