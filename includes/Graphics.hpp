/**
 * @ Author: Samael
 * @ Create Time: 1970-01-01 09:00:00
 * @ Modified by: Samael
 * @ Modified time: 2023-09-22 06:32:48
 * @ Description:
 */

#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Graphics {
    public:
        Graphics();
        ~Graphics();
        void run();
        void draw(sf::RenderWindow &window);
        void createRoom(std::string name, int x, int y);
        void createPeople(std::string name, std::string status, std::string room, int x, int y);
        void deletePeople(std::string name, std::string type, std::string room);
        void addText(std::string room, std::string text);
        typedef struct text_s {
            sf::Text *text;
            sf::Font *font;
            std::vector<std::string> messages;
            int x;
            int y;
        } text_t;
        typedef struct room_s {
            sf::Texture *texture;
            sf::Sprite *sprite;
            sf::Text *text;
            sf::Font *font;
            std::string name;
            text_t *message;
            int x;
            int y;
        } room_t;
        typedef struct people_s {
            sf::Texture *texture;
            sf::Sprite *sprite;
            sf::Text *text;
            sf::Font *font;
            std::string name;
            std::string status;
            std::string room;
            int x;
            int y;
        } people_t;
    private:
        sf::RenderWindow *_window;
        std::vector<room_t> _rooms;
        std::vector<people_t> _peoples;
        sf::Event _event;
        sf::Clock _clock;
        sf::Time _time;
        //delta time
        float _dt;
};