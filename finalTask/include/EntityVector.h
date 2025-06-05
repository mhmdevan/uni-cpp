#ifndef ENTITY_VECTOR_H
#define ENTITY_VECTOR_H

#include <vector>
#include <string>
#include "Entity.h"

/**
 * @class EntityVector
 * @brief Manages a one-to-many relationship of entities
 */
class EntityVector {
private:
    std::vector<Entity*> entities; // Collection of entity pointers

public:
    /**
     * @brief Default constructor
     */
    EntityVector() = default;
    
    /**
     * @brief Destructor - does not delete entities
     */
    ~EntityVector() = default;
    
    /**
     * @brief Add an entity to the collection
     * @param entity Pointer to the entity to add
     */
    void addEntity(Entity* entity);
    
    /**
     * @brief Remove an entity with the given ID
     * @param id ID of the entity to remove
     * @return true if entity was found and removed, false otherwise
     */
    bool removeEntity(const std::string& id);
    
    /**
     * @brief Find an entity by ID
     * @param id ID of the entity to find
     * @return Pointer to the found entity, or nullptr if not found
     */
    Entity* getEntity(const std::string& id);
    
    /**
     * @brief Get all entities
     * @return Reference to the vector of entity pointers
     */
    std::vector<Entity*>& getAllEntities();
};

#endif // ENTITY_VECTOR_H 