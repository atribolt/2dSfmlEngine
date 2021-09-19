#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <variant>

#include "Resource.h"

class ResourceManager
{
public:
  ResourceManager();
  
  bool dumpToFile(std::string_view dstFile);
  bool loadFromFile(std::string_view srcFile);
  bool addNewResource(std::string_view id, Resource const& res);
  bool removeResource(std::string_view id);
  
  Resource& resource(std::string_view id);
  
private:
  std::string _resFile;
  std::vector<Resource> _resources;
};

#endif // RESOURCEMANAGER_H
