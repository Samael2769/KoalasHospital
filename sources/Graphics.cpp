/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 09:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-09-19 11:05:36
 * @ Description:
 */

#include "Graphics.hpp"
#include <unistd.h>
#include <cmath>

Graphics::Graphics()
{
    _window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Koalas Hospital");
}

Graphics::~Graphics()
{
}

void Graphics::run()
{
    while (_window->isOpen()) {
        while (_window->pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window->close();
        }
        _window->clear(sf::Color::Black);
        draw(*_window);
        _window->display();
    }
}

void Graphics::draw(sf::RenderWindow &window)
{
    // Get the screen size
    sf::Vector2u screenSize = window.getSize();

    // Calculate the number of rows and columns based on the number of rooms
    int numRooms = _rooms.size();
    int numRows = 1; // Default to 1 row
    int numCols = numRooms; // Default to the number of rooms

    if (numRooms == 2) {
        // If there are 2 rooms, split the screen vertically
        numRows = 2;
        numCols = 1;
    } else if (numRooms > 2) {
        // If there are 3 or more rooms, calculate the number of rows and columns
        int sqrtNumRooms = static_cast<int>(std::sqrt(numRooms));
        numRows = sqrtNumRooms;
        numCols = sqrtNumRooms;

        // Adjust for remaining rooms
        while (numRows * numCols < numRooms) {
            if (numRows < numCols) {
                numRows++;
            } else {
                numCols++;
            }
        }
    }

    // Calculate room size based on the number of rows and columns
    int roomSizeX = screenSize.x / numCols;
    int roomSizeY = screenSize.y / numRows;

    for (int i = 0; i < numRooms; i++) {
        // Set the scale of the room sprite to fit the roomSize
        _rooms[i].sprite->setScale(static_cast<float>(roomSizeX) / _rooms[i].texture->getSize().x, static_cast<float>(roomSizeY) / _rooms[i].texture->getSize().y);

        // Calculate the row and column based on the index
        int row = i / numCols;
        int col = i % numCols;

        // Change the position of the room
        _rooms[i].sprite->setPosition(col * roomSizeX, row * roomSizeY);

        // Draw the room sprite and text
        window.draw(*_rooms[i].sprite);
        window.draw(*_rooms[i].text);
    }

    // You may want to adjust the position and scaling of _peoples as well.
    for (int i = 0; i < _peoples.size(); i++) {
        // Adjust the position and scaling of _peoples[i] here
        // window.draw(*_peoples[i].sprite);
        // window.draw(*_peoples[i].text);
    }
}



void Graphics::createRoom(std::string name, int x, int y)
{
    room_t room;
    room.name = name;
    room.x = x;
    room.y = y;
    room.font = new sf::Font();
    room.font->loadFromFile("Assets/OpenSans-Regular.ttf");
    room.text = new sf::Text();
    room.text->setFont(*room.font);
    room.text->setString(room.name);
    room.text->setCharacterSize(24);
    room.text->setFillColor(sf::Color::White);
    room.text->setPosition(room.x, room.y);
    room.texture = new sf::Texture();
    room.texture->loadFromFile("Assets/room.jpg");
    room.sprite = new sf::Sprite();
    room.sprite->setTexture(*room.texture);
    room.sprite->setPosition(room.x, room.y);
    _rooms.push_back(room);
}