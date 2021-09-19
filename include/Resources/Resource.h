#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <variant>
#include <vector>

enum class ResourceTypes {
  Unknown = 0,
  String,
  RawFile,
  RealNumber,
  Integer
};

class Resource
{
public:
  using Data = std::variant<
    std::nullptr_t,
    std::string,
    std::vector<uint8_t>,
    double,
    ssize_t
  >;
  
public:
  Resource();
  Resource(std::string_view name,
           Data const& data);
  
  Data data;
  std::string name;
  
  bool isValid() const;
  ResourceTypes type() const;
};

#endif
