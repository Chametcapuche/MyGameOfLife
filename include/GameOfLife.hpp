/*
** EPITECH PROJECT, 2021
** GameOfLife
** File description:
** GameOfLife
*/

#ifndef GAMEOFLIFE_HPP_
#define GAMEOFLIFE_HPP_

#include <string>
#include <vector>

#include "Graphics.hpp"
#include "CoreLogic.hpp"

class GameOfLife {
    public:
        GameOfLife(const std::pair<unsigned int, unsigned int> size, const bool circular,
        const std::vector<uint8_t> surviveRule, const std::vector<uint8_t> bornRule);
        ~GameOfLife() = default;
        void run();

    protected:
    private:
        Graphics _graphLib;
        CoreLogic _corelogic;

        const std::pair<unsigned int, unsigned int> _size;
};

#endif /* !GAMEOFLIFE_HPP_ */