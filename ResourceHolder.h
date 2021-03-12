//
// Created by Sebastian Whyte on 3/11/21.
//

#ifndef SFML_EXAMPLE_RESOURCEHOLDER_H
#define SFML_EXAMPLE_RESOURCEHOLDER_H

#include "ResourceHolder.inl"
#endif //SFML_EXAMPLE_RESOURCEHOLDER_H


#include <map>
#include <string>
#include <memory>
#include <iostream>


//"H"/HEADER FILES ARE FOR INTERFACE (DEFINING VARIABLES & METHODS)

template <class Resource, class Identifier>
    class ResourceHolder {

        public:

            void loadResource(Identifier id, const std::string& filename);

            template <class Parameter>
                //Overload "loadResource" function by ADDING an ADDITIONAL ARGUMENT "secondParam" with REFERENCE to PARAMETER
                void loadResource(Identifier id, const std::string& filename, const Parameter& secondParam);

            Resource& get(Identifier id);

            const Resource& get(Identifier ID) const;


        private:
            void insertResource(Identifier id, std::unique_ptr<Resource> resource);


        private:
            std::map<Identifier, std::unique_ptr<Resource>> resourceMap;

};

//#include "ResourceHolder.inl"
//#endif //SFML_EXAMPLE_RESOURCEHOLDER_H