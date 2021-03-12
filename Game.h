//
// Created by Sebastian Whyte on 2/16/21.
//

#ifndef SFML_EXAMPLE_GAME_H
#define SFML_EXAMPLE_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//using namespace std;
//using namespace sf;


class Game {

    public:
                 Game();
            void  run();

    private:


        // Game functions
        void processEvents();
        void update(sf::Time deltaTime);
        void render();

        // Sprites, Backgrounds & Textures Functions
        void initSprites();
        void initBackground();
        void renderSprites();



        // Game Logic Variables
        static const float PLAYER_SPEED;
        static const sf::Time TIME_PER_FRAME;
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
        bool Attack;

    private:
        // Classes
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::CircleShape mPlayer;
        sf::Texture texture;
        sf::Texture attack_texture;
        sf::Sprite sprite;
        sf::Sprite forest_bg;

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};


#endif //SFML_EXAMPLE_GAME_H
