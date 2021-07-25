/*
** EPITECH PROJECT, 2021
** Graphics
** File description:
** Graphics
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <utility>

class Graphics {
    public:
        Graphics(const std::pair<unsigned int, unsigned int> size);
        ~Graphics() = default;
        const bool isRunning();
        void processEvents();
        const std::pair<std::pair<int, int>, std::pair<int, int>> getMouseInput();
        bool isPaused() {return (_pause);};
        bool updateTime();
        void update(const std::vector<uint8_t> &map);
        void display();

    protected:
    private:
        const std::pair<unsigned int, unsigned int> _size;
        bool _running;
        bool _pause;

        std::vector<sf::RectangleShape> _sprites;
        std::map<std::string, sf::Texture> _textures;
        sf::RenderWindow _window;
        std::pair<int, int> _mouseLeftInput;
        std::pair<int, int> _mouseRightInput;
        sf::Clock _framerate;
        bool _mouseClick;
};

#endif /* !GRAPHICS_HPP_ */