#ifndef COMMUTERS_ENGINE_WORLD_WORLD_HPP
#define COMMUTERS_ENGINE_WORLD_WORLD_HPP

#include <cstdint>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>

#include "engine/component/component_storage.hpp"
#include "engine/component/component_storage_base.hpp"
#include "engine/entity/entity.hpp"
#include "engine/entity/entity_id.hpp"
#include "engine/entity/entity_id_hash.hpp"

namespace commuters {

class World {
public:
    Entity CreateEntity();

    bool DestroyEntity(EntityId id);

    bool HasEntity(EntityId id) const;

    template <typename T>
    bool AddComponent(EntityId id, T component) {
        if (!HasEntity(id)) {
            return false;
        }

        auto* storage = GetStorage<T>();

        if (storage == nullptr) {
            auto new_storage = std::make_unique<ComponentStorage<T>>();
            storage = new_storage.get();

            component_storages.emplace(typeid(T), std::move(new_storage));
        }

        return storage->Add(id, std::move(component));
    }

    template <typename T>
    T* GetComponent(EntityId id) {
        auto* storage = GetStorage<T>();
        if (storage == nullptr) {
            return nullptr;
        }

        return storage->Get(id);
    }

    template <typename T>
    const T* GetComponent(EntityId id) const {
        const auto* storage = GetStorage<T>();
        if (storage == nullptr) {
            return nullptr;
        }

        return storage->Get(id);
    }

    template <typename T>
    bool HasComponent(EntityId id) const {
        auto storage = GetStorage<T>();
        if (storage == nullptr) {
            return false;
        }

        return storage->Has(id);
    }

    template <typename T>
    bool RemoveComponent(EntityId id) {
        auto storage = GetStorage<T>();
        if (storage == nullptr) {
            return false;
        }
        return storage->Remove(id);
    }

private:
    std::uint64_t next_entity_id = 1;

    std::unordered_set<EntityId, EntityIdHash> entities;

    std::unordered_map<
        std::type_index,
        std::unique_ptr<IComponentStorage>
    > component_storages;

private:
    template <typename T>
    ComponentStorage<T>* GetStorage() {
        auto it = component_storages.find(typeid(T));

        if (it == component_storages.end()) {
            return nullptr;
        }

        return dynamic_cast<ComponentStorage<T>*>(it->second.get());
    }

    template <typename T>
    const ComponentStorage<T>* GetStorage() const {
        auto it = component_storages.find(typeid(T));

        if (it == component_storages.end()) {
            return nullptr;
        }

        return dynamic_cast<const ComponentStorage<T>*>(it->second.get());
    }
};

} // namespace commuters

#endif // COMMUTERS_ENGINE_WORLD_WORLD_HPP

