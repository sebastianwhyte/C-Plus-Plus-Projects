//
// Created by Sebastian Whyte on 3/9/21.
//

#ifndef SFML_EXAMPLE_TEXTUREHOLDER_H
#define SFML_EXAMPLE_TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <iterator>
#include <map>

#include "Game.h"


//Our enum is named ID, and holds 3 Texture identifiers (Landscape, Sprite, & Missile)
//They key type is our enumeration & value type is sf::Texture
namespace Textures {
    enum ID {
        Landscape, Sprite, Missile
    };
}


class TextureHolder {


    public:
        TextureHolder();

        // Keep an eye on this if you get error message
        // Creates a map, which has key-value pairs, just like Python dictionaries

        sf::Texture& get(Textures::ID id);

        const sf::Texture& get(Textures::ID id) const;


        // Functions
        void loadTexture(Textures::ID id, const std::string& filename);



    private:

        // Loads Resource, has 2 parameters: for an identifier (id) & for filename
        // The "ID" will be the key

        std::map<Textures::ID, std::unique_ptr<sf::Texture>> textureMap;
};


#endif //SFML_EXAMPLE_TEXTUREHOLDER_H
