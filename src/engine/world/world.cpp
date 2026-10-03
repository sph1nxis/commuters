#include "engine/world/world.hpp"

namespace commuters {

Entity World::CreateEntity() {
    EntityId id { next_entity_id++ };
    entities.insert(id);
    return Entity(id);
}

bool World::DestroyEntity(EntityId id) {
    if (!HasEntity(id)) {
        return false;
    }

    for (auto& [_, storage] : component_storages) {
        storage->Remove(id);
    }

    entities.erase(id);
    return true;
}

bool World::HasEntity(EntityId id) const {
    return entities.contains(id);
}

} // namespace commuters

