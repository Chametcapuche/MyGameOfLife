#ifndef ARGS_HPP_
#define ARGS_HPP_

#include <vector>
#include <cstdint>

class Args {
    public:
        Args(const int ac, const char **av);
        ~Args() = default;
        const std::pair<unsigned int, unsigned int> getSize() const;
        const bool getCircular() const;
        const std::vector<uint8_t> getSurviveRule() const;
        const std::vector<uint8_t> getBornRule() const;


    protected:
    private:
        std::pair<unsigned int, unsigned int> _size;
        bool _circular;
        std::vector<uint8_t> _surviveRule;
        std::vector<uint8_t> _bornRule;
};

#endif /* !ARGS_HPP_ */