#ifndef COMMUTERS_ENGINE_WORLD_WORLD_HPP
#define COMMUTERS_ENGINE_WORLD_WORLD_HPP

#include <cstdint>
#include <unordered_set>

#include "engine/entity/entity.hpp"
#include "engine/entity/entity_id.hpp"
#include "engine/entity/entity_id_hash.hpp"

namespace commuters {

class World {
public:
    Entity CreateEntity();

    bool DestroyEntity(EntityId id);

    bool HasEntity(EntityId id) const;

private:
    std::uint64_t next_entity_id = 1;

    std::unordered_set<EntityId, EntityIdHash> entities;
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_WORLD_WORLD_HPP

