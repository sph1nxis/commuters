#ifndef COMMUTERS_ENGINE_ENTITY_HPP
#define COMMUTERS_ENGINE_ENTITY_HPP

#include "engine/entity/entity_id.hpp"

namespace commuters {

class Entity {
public:
    EntityId GetId() const;

private:
    friend class World;

    explicit Entity(EntityId id);

    EntityId id;
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_ENTITY_HPP

