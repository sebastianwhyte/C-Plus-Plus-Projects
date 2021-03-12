//
// Created by Sebastian Whyte on 3/9/21.
//

#include "TextureHolder.h"


TextureHolder::TextureHolder() {
    // Make a "TextureHolder" object, then call "loadTexture" function & give it parameters
    TextureHolder textures;
    textures.loadTexture(Textures::Landscape, "../Images/Backgrounds/dark-forest-background.png");
}


void TextureHolder::loadTexture(Textures::ID id, const std::string& filename) {

    // "unique_ptr" is a SMART POINTER that helps DELETE objects AUTOMATICALLY to FREE UP MEMORY when its NO LONGER REQUIRED
    // Here the unique_ptr has variable named "texture", that is a NEW TEXTURE OBJECT
    std::unique_ptr<sf::Texture>texture(new sf::Texture());


    // Checks to see if file can be loaded successfully. If not, then it will THROW a RUNTIME ERROR, & give error message
    // thats in the QUOTES
    if(!texture->loadFromFile(filename)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    }


    // "Auto" KEYWORD will AUTOMATICALLY FIND/DETERMINE the DATA TYPE of a VARIABLE, the VARIABLE is NAMED "inserted"
    // "inserted" will INSERT a NEW KEY-VALUE PAIR (by using "make_pair" ) INTO the TEXTURE MAP
    // "Assert" is USED for DEBUGGING. It TAKES a BOOLEAN VALUE. If BOOLEAN is TRUE, NOTHING HAPPENS. If BOOL is FALSE, PROGRAM CRASHES.
    auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);


    //texture->loadFromFile(filename);

    //textureMap.insert(std::make_pair(id, std::move(texture)));
}


//Looks into map to find CORRESPONDING TEXTURE ENTRY for the PASSED KEY. "find()" METHOD will RETURN ITERATOR(found) to the FOUND ELEMENT, or "end()" if NOTHING is FOUND
//The ITERATOR (found) will POINT to "std::pair<const Textures::ID, std::unique_ptr<sf::Texture>>", & we have to ACCESS its SECOND MEMBER to GET UNIQUE POINTER
sf::Texture& TextureHolder::get(Textures::ID id) {
    auto found = textureMap.find(id);
    assert(found != textureMap.end());
    return *found->second;
}