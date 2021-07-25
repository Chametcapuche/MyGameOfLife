#include "Args.hpp"

Args::Args(const int ac, const char **av)
{
    this->_circular = true;
    this->_size = {50, 50};
    this->_surviveRule.push_back(2);
    this->_surviveRule.push_back(3);
    this->_bornRule.push_back(3);
}

const std::pair<unsigned int, unsigned int> Args::getSize() const
{
    return (_size);
}

const bool Args::getCircular() const
{
    return (_circular);
}

const std::vector<uint8_t> Args::getSurviveRule() const
{
    return (_surviveRule);
}

const std::vector<uint8_t> Args::getBornRule() const
{
    return (_bornRule);
}