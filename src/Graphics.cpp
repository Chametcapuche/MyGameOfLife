#include "Graphics.hpp"

Graphics::Graphics(const std::pair<unsigned int, unsigned int> size) :
_size(size), _window(sf::VideoMode(1000, 1000), "Game Of Life : Paul Marliere")
{
    _running = true;
    _pause = true;
    _mouseClick = false;
    _window.setFramerateLimit(60);
}

const bool Graphics::isRunning()
{
    if (!_window.isOpen() || !_running)
        return false;
    return true;
}

bool Graphics::updateTime()
{
    if (_framerate.getElapsedTime().asMilliseconds() > 1000/60) {
        _framerate.restart();
        return true;
    }
    return false;
}

void Graphics::processEvents()
{
    sf::Event event;
    unsigned int xMul = 1000/(_size.first + 1);
    unsigned int yMul = 1000/(_size.second + 1);
    while (_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            _window.close();
            _running = false;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                _pause = !_pause;
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            _mouseClick = true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i temp = sf::Mouse::getPosition(_window);
                _mouseLeftInput = {temp.x /xMul , temp.y / yMul};
            } else
                _mouseLeftInput = {-1, -1};
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                sf::Vector2i temp = sf::Mouse::getPosition(_window);
                _mouseRightInput = {temp.x /xMul , temp.y / yMul};
            } else
                _mouseRightInput = {-1, -1};
        }
        else if (event.type == sf::Event::MouseMoved && _mouseClick) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i temp = sf::Mouse::getPosition(_window);
                _mouseLeftInput = {temp.x /xMul , temp.y / yMul};
            } else
                _mouseLeftInput = {-1, -1};
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                sf::Vector2i temp = sf::Mouse::getPosition(_window);
                _mouseRightInput = {temp.x /xMul , temp.y / yMul};
            } else
                _mouseRightInput = {-1, -1};
        } else {
            _mouseLeftInput = {-1, -1};
            _mouseRightInput = {-1, -1};
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            _mouseClick = false;
        }
    }
}

const std::pair<std::pair<int, int>, std::pair<int, int>> Graphics::getMouseInput()
{
    std::pair<std::pair<int, int>, std::pair<int, int>> temp = {_mouseLeftInput, _mouseRightInput};
    return (temp);
}

void Graphics::update(const std::vector<uint8_t> &map)
{
    _sprites.clear();
    unsigned int xMul = 1000/(_size.first + 1);
    unsigned int yMul = 1000/(_size.second + 1);
    for (unsigned int i = 0; i < map.size(); i++) {
        if (map[i]) {
            sf::RectangleShape temp({1000/(_size.first + 1), 1000/(_size.first + 1)});
            temp.setFillColor(sf::Color::White);
            temp.setPosition(
                i % (_size.first + 1) * xMul,
                i / (_size.first + 1) * yMul);
            _sprites.push_back(temp);
        }
    }
}

void Graphics::display()
{
    _window.clear();
    for (auto &i : _sprites)
        _window.draw(i);
    _window.display();
}