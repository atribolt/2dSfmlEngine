#include "Resources/Resource.h"

Resource::Resource() 
  : data(nullptr)
  , name("")
{  
}

Resource::Resource(std::string_view name, const Data& data) 
  : data(data)
  , name(name)
{
}

bool Resource::isValid() const {
  return !name.empty() && (type() != ResourceTypes::Unknown);
}

ResourceTypes Resource::type() const {
  return ResourceTypes(data.index());
}
