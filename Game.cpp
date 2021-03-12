//
// Created by Sebastian Whyte on 2/16/21.
//

#include "Game.h"

// FIX THIS SO YOU USE POINTERS LIKE "ADVENTURE GAME" FILE !!!


const float Game::PLAYER_SPEED = 240.f;
const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f);


// Initialize Variables & Functions
Game::Game() {

    this->videoMode.height = 1050;
    this->videoMode.width = 1680;
    this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "SFML App");

    this->initSprites();
    //this->initBackground();
}



    //mPlayer.setRadius(40.f); mPlayer.setPosition(100.f, 100.f); mPlayer.setFillColor(sf::Color::Cyan);

    /*
     if (!texture.loadFromFile("../Images/Sprites/Player/idle-1.png")) {
        std::cout << "Error loading file" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(4, 4);
    sprite.setPosition(100.f, 100.f);
    */


// Initialize Sprites
void Game::initSprites() {
    if (!this->texture.loadFromFile("../Images/Sprites/Player/idle-1.png")) {
        std::cout << "Error loading file" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(4, 4);
    sprite.setPosition(100.f, 100.f);
}


void Game::initBackground() {

    //if (!this->texture.loadFromFile("../Images/Backgrounds/dark-forest-background.png")) {
        std::cout << "Error loading file" << std::endl;
    //}
}


// Renders & Draws Sprites
void Game::renderSprites() {
    this->window->draw(sprite);
}


// Run Function
void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;  // Set "timeSinceLastUpdate" to ZERO

    //This USES the "FIXED TIME STEPS" TECHNIQUE. This GUARANTEES to give the SAME DELTA TIME, NO MATTER the CIRCUMSTANCES
    while (window->isOpen()) {
        //sf::Time deltaTime = clock.restart();
        processEvents();
        timeSinceLastUpdate += clock.restart();

        //If we are OVER the REQUIRED AMOUNT of TIME for ONE FRAME, we SUBTRACT the DESIRED LENGTH of THIS FRAME ("TIME_FOR_FRAME"), as we SEE with timeSinceLastUpdate -= TIME_PER_FRAME, THEN UPDATES the FRAME
        while (timeSinceLastUpdate > TIME_PER_FRAME) {

            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(TIME_PER_FRAME);
        }
            render();
    }
}


// Checks and reads player input/key presses
 void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {   // The boolean "isPressed" will be TRUE when KEY is PRESSED and FALSE if KEY is RELEASED
    if (key == sf::Keyboard::Up)
        mIsMovingUp = isPressed;

    else if (key == sf::Keyboard::Down)
        mIsMovingDown = isPressed;

    else if (key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;

    else if (key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;

    //else if (key == sf::Keyboard::Space)
        //Attack = isPressed;

    else if (key == sf::Keyboard::Escape)
        this->window->close();

}


// Process Events & Key Presses
void Game::processEvents()
{
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                window->close();
                break;

            //case sf::Keyboard::Escape:
                //window.close();
        }
    }
}


// Update function within Game class
void Game::update(sf::Time deltaTime)   // Using "deltaTime" or "dt" to keep MOVEMENT CONSISTENT across various platforms/computers/devices
{
    // Vectors are HELPFUL with POSITIONING AND MOVEMENT. "Vector2f" will TAKE 2 FLOATS (why theres an "f" AFTER NUMBER) for its "x" and "y" values
    // Here, the CIRCLE WILL have its ORIGIN at x: 0, y: 0
    sf::Vector2f movement (0.f, 0.f);
    if (mIsMovingUp)
        movement.y -= PLAYER_SPEED;     // MAYBE REPLACE PLAYER_SPEED WITH +=1.f LIKE BEFORE TO STOP SPRITE FROM MOVING ON ITS OWN
        //movement.y -= 1.f;
    if (mIsMovingDown)
        movement.y += PLAYER_SPEED;
        //movement.y += 1.f;
    if (mIsMovingLeft)
        movement.x -= PLAYER_SPEED;
        //movement.x -= 1.f;
    if (mIsMovingRight)
        movement.x += PLAYER_SPEED;
        //movement.x += 1.f;


    sprite.move(movement * deltaTime.asSeconds());
}


// Renders game objects and displays them on screen
void Game::render()
{
    window->clear();
    //window.draw(mPlayer);
    this->renderSprites();
    window->display();
}