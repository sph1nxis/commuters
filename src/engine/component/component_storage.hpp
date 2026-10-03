#ifndef COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_HPP
#define COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_HPP

#include <unordered_map>

#include "engine/component/component_storage_base.hpp"
#include "engine/entity/entity_id.hpp"
#include "engine/entity/entity_id_hash.hpp"

namespace commuters {

template <typename T>
class ComponentStorage : public IComponentStorage {
public:
    bool Has(EntityId id) const {
        return entity_ids.contains(id);
    }

    bool Remove(EntityId id) override {
        return entity_ids.erase(id) != 0;
    }

    T* Get(EntityId id) {
        auto it = entity_ids.find(id);
        if (it == entity_ids.end()) {
            return nullptr;
        }

        return &it->second;
    }

    const T* Get(EntityId id) const {
        auto it = entity_ids.find(id);
        if (it == entity_ids.end()) {
            return nullptr;
        }

        return &it->second;
    }
    bool Add(EntityId id, T component) {
        return entity_ids.emplace(id, std::move(component)).second;
    }

private:
    std::unordered_map<EntityId, T, EntityIdHash> entity_ids;
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_COMPONENT_COMPONENT_STORAGE_HPP

