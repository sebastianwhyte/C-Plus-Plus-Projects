//
// Created by Sebastian Whyte on 3/11/21.
//

#ifndef SFML_EXAMPLE_RESOURCEHOLDER_INL
#define SFML_EXAMPLE_RESOURCEHOLDER_INL

#endif //SFML_EXAMPLE_RESOURCEHOLDER_INL

#include "ResourceHolder.h"


// TEMPLATE FUNCTION FOR RESOURCE HOLDER. TEMPLATES are SIMPLE IDEA is to PASS DATA TYPE as PARAMETER, SO that WE DONT
// NEED to WRITE SAME CODE for DIFF DATA TYPES.

// There are 2 NEW KEYWORDS to SUPPORT TEMPLATES: ‘template’ and ‘typename’. The SECOND KEYWORD CAN always BE
// REPLACED by KEYWORD "CLASS".


template <class Resource, class Identifier>
void ResourceHolder<Resource, Identifier>::loadResource(Identifier id, const std::string& filename)

{     // Create & Load resource
      std::unique_ptr<Resource> resource(new Resource());
      if (!resource->loadFromFile(filename))
          throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

      // If loading successful, call insert resource function & insert into map
      insertResource(id, std::move(resource));

}


//Overload Function, to support
template<class Resource, class Identifier>
template <class Parameter>
    void ResourceHolder<Resource, Identifier>::loadResource(Identifier id, const std::string& filename, const Parameter& secondParam)
{
        // Create & Load resource
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename, secondParam))
            throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

        // If loading successful, call insert resource function & insert into map
        insertResource(id, std::move(resource));


}


// Resource& get function
template <class Resource, class Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = resourceMap.find(id);
    assert(found != resourceMap.end());

    return *found->second;
}


template <class Resource, class Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    // Find resouce within the map & return its id. Then if resource(found) is NOT in map, assign it to POINTER "*found" then to "second"
    // "map.end()" will RETURN an ITERATOR pointing PAST the LAST ELEMENT in a map
    auto found = resourceMap.find(id);
    assert(found != resourceMap.end());

    return *found->second;
}


template <class Resource, class Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
    // Insert resource into game & check for success, by using assert
    auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}


