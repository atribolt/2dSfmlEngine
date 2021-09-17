#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <SFML/Graphics/Transformable.hpp>

#include "Common.h"

class Entity : public sf::Transformable
{
public:
  Entity(EntityTypes type);
  
  EntityTypes type() const;
  
private:
  EntityTypes _type;
};

#endif // ENTITY_H
