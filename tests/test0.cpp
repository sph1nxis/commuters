#include <cassert>

#include "engine/world/world.hpp"

int main() {
    using namespace commuters;

    World world;

    auto first = world.CreateEntity();
    auto second = world.CreateEntity();

    assert(first.GetId() != second.GetId());

    assert(world.HasEntity(first.GetId()));
    assert(world.HasEntity(second.GetId()));

    world.DestroyEntity(first.GetId());

    assert(!world.HasEntity(first.GetId()));
    assert(world.HasEntity(second.GetId()));
}

