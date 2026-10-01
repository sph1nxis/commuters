#include "engine/world/world.hpp"

namespace commuters {

Entity World::CreateEntity() {
    EntityId id { next_entity_id++ };
    entities.insert(id);
    return Entity(id);
}

bool World::DestroyEntity(EntityId id) {
    // erased 0 entites = failure; else success
    return static_cast<bool>(entities.erase(id));
}

bool World::HasEntity(EntityId id) const {
    return entities.contains(id);
}

} // namespace commuters

