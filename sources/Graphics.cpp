/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 09:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-09-22 07:58:40
 * @ Description:
 */

#include "Graphics.hpp"
#include <unistd.h>
#include <cmath>
#include <iostream>

Graphics::Graphics()
{
    _window = new sf::RenderWindow(sf::VideoMode(1000, 700), "Koalas Hospital");
    _dt = 0;
    score = 0;
    died = 0;
    _score.font = new sf::Font();
    _score.font->loadFromFile("Assets/OpenSans-Regular.ttf");
    _score.text = new sf::Text();
    _score.text->setFont(*_score.font);
    _score.text->setString("Score: " + std::to_string(score));
    _score.text->setCharacterSize(24);
    _score.text->setFillColor(sf::Color::Black);
    //set position on the middle of the screen
    _score.text->setPosition(_window->getSize().x / 2 - _score.text->getGlobalBounds().width / 2, 0);
    _died.font = new sf::Font();
    _died.font->loadFromFile("Assets/OpenSans-Regular.ttf");
    _died.text = new sf::Text();
    _died.text->setFont(*_died.font);
    _died.text->setString("Died: " + std::to_string(died));
    _died.text->setCharacterSize(24);
    _died.text->setFillColor(sf::Color::Black);
    _died.text->setPosition(_window->getSize().x / 2 - _died.text->getGlobalBounds().width / 2, 30);
}

Graphics::~Graphics()
{
}

void Graphics::run()
{
    _clock.restart();
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
        _rooms[i].text->setPosition(col * roomSizeX, row * roomSizeY);
        _rooms[i].x = col * roomSizeX;
        _rooms[i].y = row * roomSizeY;
        if (_rooms[i].message->messages.size() > 0) {
            if (_dt > 10000000000) {
                _rooms[i].message->text->setString(_rooms[i].message->messages[0]);
                _rooms[i].message->messages.erase(_rooms[i].message->messages.begin());
                _dt = 0;
            }
        }
        _rooms[i].message->text->setPosition(col * roomSizeX, row * roomSizeY + 100);


        // Draw the room sprite and text
        window.draw(*_rooms[i].sprite);
        window.draw(*_rooms[i].text);
        window.draw(*_rooms[i].message->text);
        _score.text->setString("Score: " + std::to_string(score));
        window.draw(*_score.text);
        _died.text->setString("Died: " + std::to_string(died));
        window.draw(*_died.text);
        _dt += _clock.getElapsedTime().asMicroseconds();
    }

    // You may want to adjust the position and scaling of _peoples as well.
    for (int i = 0; i < _peoples.size(); i++) {
        //set pos and scale of people to fit in room
        for (int j = 0; j < _rooms.size(); j++) {
            if (_peoples[i].room == _rooms[j].name) {
                int offset = 0;
                if (_peoples[i].status == "Doctor")
                    offset = 10;
                else if (_peoples[i].status == "Nurse")
                    offset = 200 + (i * 50);
                else if (_peoples[i].status == "Patient")
                    offset = 500 + (i * 20);
                if (_rooms.size() > 2)
                    offset /= 2;
                _peoples[i].x = _rooms[j].x + offset;
                _peoples[i].y = _rooms[j].y + 150;
            }
        }
        //scale depends on number of rooms
        _peoples[i].sprite->setScale(roomSizeX / 1500.0, roomSizeY / 800.0);
        _peoples[i].sprite->setPosition(_peoples[i].x, _peoples[i].y);
        _peoples[i].text->setPosition(_peoples[i].x + _peoples[i].sprite->getGlobalBounds().width / 2 - _peoples[i].text->getGlobalBounds().width / 2, _peoples[i].y);
        window.draw(*_peoples[i].sprite);
        window.draw(*_peoples[i].text);
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
    room.message = new text_t();
    room.message->font = new sf::Font();
    room.message->font->loadFromFile("Assets/OpenSans-Regular.ttf");
    room.message->text = new sf::Text();
    room.message->text->setFont(*room.message->font);
    room.message->text->setString("Start");
    room.message->text->setCharacterSize(24);
    room.message->text->setFillColor(sf::Color::Black);
    room.message->text->setPosition(room.x, room.y + 100);
    _rooms.push_back(room);
}

void Graphics::createPeople(std::string name, std::string status, std::string room, int x, int y)
{
    people_t people;
    people.name = name;
    people.status = status;
    people.room = room;
    people.x = x;
    people.y = y;
    people.font = new sf::Font();
    people.font->loadFromFile("Assets/OpenSans-Regular.ttf");
    people.text = new sf::Text();
    people.text->setFont(*people.font);
    people.text->setString(people.name);
    people.text->setCharacterSize(24);
    people.text->setFillColor(sf::Color::Black);
    people.text->setPosition(people.x, people.y);
    people.texture = new sf::Texture();
    if (status == "Patient")
        people.texture->loadFromFile("Assets/koalaPatient.png");
    else if (status == "Doctor")
        people.texture->loadFromFile("Assets/koalaDoctor.png");
    else if (status == "Nurse")
        people.texture->loadFromFile("Assets/koalaNurse.png");
    people.sprite = new sf::Sprite();
    people.sprite->setTexture(*people.texture);
    people.sprite->setPosition(people.x, people.y);
    _peoples.push_back(people);
}

void Graphics::deletePeople(std::string name, std::string status, std::string room)
{
    for (int i = 0; i < _peoples.size(); i++) {
        if (_peoples[i].name == name && _peoples[i].status == status && _peoples[i].room == room) {
            _peoples.erase(_peoples.begin() + i);
            return;
        }
    }
}

void Graphics::addText(std::string text, std::string room)
{
    // if in text "vaccinated or cured" add 1 to score
    if (text.find("vaccinated") != std::string::npos || text.find("cured") != std::string::npos)
        score++;
    if (text.find("died") != std::string::npos)
        died++;
    for (int i = 0; i < _rooms.size(); i++) {
        if (_rooms[i].name == room) {
            _rooms[i].message->messages.push_back(text);
            return;
        }
    }
}