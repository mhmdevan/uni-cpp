#ifndef ENTITY_H
#define ENTITY_H

#include <string>

/**
 * @class Entity
 * @brief Abstract base class for all entities in the system
 */
class Entity {
protected:
    std::string id; // Unique identifier

public:
    /**
     * @brief Constructor with ID parameter
     * @param id The unique identifier for the entity
     */
    Entity(const std::string& id);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Entity() = default;
    
    /**
     * @brief Get the entity's ID
     * @return The entity's ID as a string
     */
    virtual std::string getId() const = 0; // Pure virtual method
};

#endif // ENTITY_H 