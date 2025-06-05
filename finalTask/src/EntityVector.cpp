#include "../include/EntityVector.h"
#include <algorithm>

void EntityVector::addEntity(Entity* entity) {
    if (entity != nullptr) {
        entities.push_back(entity);
    }
}

bool EntityVector::removeEntity(const std::string& id) {
    auto it = std::find_if(entities.begin(), entities.end(), 
        [&id](const Entity* entity) { return entity->getId() == id; });
    
    if (it != entities.end()) {
        entities.erase(it);
        return true;
    }
    
    return false;
}

Entity* EntityVector::getEntity(const std::string& id) {
    auto it = std::find_if(entities.begin(), entities.end(), 
        [&id](const Entity* entity) { return entity->getId() == id; });
    
    if (it != entities.end()) {
        return *it;
    }
    
    return nullptr;
}

std::vector<Entity*>& EntityVector::getAllEntities() {
    return entities;
} 