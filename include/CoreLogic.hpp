#ifndef CORELOGIC_HPP_
#define CORELOGIC_HPP_

#include <string>
#include <vector>

class CoreLogic {
    public:
        CoreLogic(const std::pair<unsigned int, unsigned int> size, const bool circular,
        const std::vector<uint8_t> surviveRule, const std::vector<uint8_t> bornRule);
        ~CoreLogic() = default;
        void getInput(const std::pair<std::pair<int, int>, std::pair<int, int>> input);
        void update(unsigned int n);
        const std::vector<uint8_t> &getMap() const;

    protected:
    private:


        std::vector<uint8_t> _map;

        const std::pair<unsigned int, unsigned int> _size;
        const bool _circular;
        const std::vector<uint8_t> _surviveRule;
        const std::vector<uint8_t> _bornRule;
};

#endif /* !CORELOGIC_HPP_ */
