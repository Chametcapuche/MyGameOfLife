#include "GameOfLife.hpp"

GameOfLife::GameOfLife(const std::pair<unsigned int, unsigned int> size, const bool circular,
const std::vector<uint8_t> surviveRule, const std::vector<uint8_t> bornRule) : _size(size),
_corelogic(size, circular, surviveRule, bornRule), _graphLib(size)
{}

void GameOfLife::run()
{
    while (_graphLib.isRunning()) {
        _graphLib.processEvents();
        if (!_graphLib.isPaused() && _graphLib.updateTime()) {
            _corelogic.update(0);
        } else {
            _corelogic.getInput(_graphLib.getMouseInput());
        }
        _graphLib.update(_corelogic.getMap());
        _graphLib.display();
    }
}