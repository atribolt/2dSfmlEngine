#include <fstream>
#include <optional>

#include "Common.h"
#include "Resources/ResourceManager.h"

/*
 * Схема хранения ресурсов
 * 
 * [stx]
 *   <blk-size>[nul]   ==> integer    [2           bytes] nuber in LE
 *   <type>[nul]       ==> integer    [1           bytes] number in LE
 *   <data-size>[nul]  ==> integer    [4           bytes] number in LE
 *   <id>[nul]         ==> string     [N           bytes] ascii text
 *   <data>            ==> bytes data [<data-size> bytes] any data
 * [etx]
*/

ResourceManager::ResourceManager()
{
}

namespace {
  std::istream& operator>>(std::istream& is, Resource& res) {
    if (is.get() == STX) {
      uint16_t blk_size = 0;
      
      // TODO: realize read resource
      
    }
    else
      is.setstate(std::ios::failbit);
    
    return is;
  }
  
  std::ostream& operator<<(std::ostream& os, Resource const& res) {
    
    // TODO: realize dump resource
    return os;
  }
}

bool ResourceManager::dumpToFile(std::string_view dstFile) {
  LocalObject out( std::ifstream(std::string(dstFile), std::ios::binary)
                 , &std::ifstream::close);
  
  if (!out)
    return false;
  
  for (Resource const& res : _resources) {
    
  }
  
  return true;
}
