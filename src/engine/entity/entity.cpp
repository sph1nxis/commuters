#include "engine/entity/entity.hpp"

namespace commuters {

EntityId Entity::GetId() const {
    return id;
}

Entity::Entity(EntityId id) :
    id(id)
{}

} // namespace commuters

