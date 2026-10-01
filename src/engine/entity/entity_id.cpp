#include "engine/entity/entity_id.hpp"

namespace commuters {

EntityId::EntityId(ValueType value) :
    value(value)
{}

EntityId::ValueType EntityId::GetValue() const {
    return value;
}


EntityId EntityId::invalid() {
    return EntityId{ kNullId };
}

bool EntityId::IsValid() const {
    return value != kNullId;
}

} // namespace commuters

