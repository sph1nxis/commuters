#ifndef COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HPP
#define COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HPP

#include <cstdint>

namespace commuters {

class EntityId {
public:
    using ValueType = std::uint64_t;

    explicit EntityId(ValueType value);

    ValueType GetValue() const;

    bool operator==(const EntityId& other) const = default;
    bool operator!=(const EntityId& other) const = default;

    static EntityId invalid();
    bool IsValid() const;

private:
    static constexpr ValueType kNullId = 0;

    ValueType value = kNullId;
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_ENTITY_ENTITY_ID_HPP

