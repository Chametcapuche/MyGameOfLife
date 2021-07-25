#include "CoreLogic.hpp"
#include <iostream>

CoreLogic::CoreLogic(const std::pair<unsigned int, unsigned int> size, const bool circular,
const std::vector<uint8_t> surviveRule, const std::vector<uint8_t> bornRule) :
_size(size), _circular(circular), _surviveRule(surviveRule), _bornRule(bornRule)
{
    for (unsigned int i = 0; i < (_size.first + 1) * (_size.second + 1); i++) {
        _map.push_back(0);
    }
}

void CoreLogic::update(unsigned int n)
{
    std::vector<uint8_t> copy;
    for (unsigned int i = 0; i < (_size.first + 1) * (_size.second + 1); i++) {
        unsigned int x = i % (_size.first + 1);
        unsigned int y = i / (_size.first + 1);
        copy.push_back(0);
        if (x > 0 && x < _size.first && y > 0 && y < _size.first) {
            uint8_t result = _map[i-1] + _map[i+1] + _map[i-(_size.first + 1)]
            + _map[i+(_size.first + 1)] + _map[i-1-(_size.first + 1)]
            + _map[i+1-(_size.first + 1)] + _map[i-1+(_size.first + 1)]
            + _map[i+1+(_size.first + 1)];
            if (_map[i]) {
                for (auto &j : _surviveRule) {
                    if (result == j) {
                        copy[i] = 1;
                        break;
                    }
                }
            } else {
                for (auto &j : _bornRule) {
                    if (result == j) {
                        copy[i] = 1;
                        break;
                    }
                }
            }
        }
    }
    _map = copy;
    if (n > 0)
        update(n - 1);
}

const std::vector<uint8_t> &CoreLogic::getMap() const
{
    return (_map);
}

void CoreLogic::getInput(const std::pair<std::pair<int, int>, std::pair<int, int>> input)
{
    std::pair<int, int> left = input.first;
    std::pair<int, int> right = input.second;
    if (left.first > 0 && left.second > 0)
        _map[left.first + (left.second * (_size.first + 1))] = 1;
    if (right.first > 0 && right.second > 0)
        _map[right.first + (right.second * (_size.first + 1))] = 0;
}