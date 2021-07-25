#include "GameOfLife.hpp"
#include "Args.hpp"
#include "Exception.hpp"

int main(const int ac, const char **av)
{
    try {
        Args args(ac, av);
        GameOfLife gol(args.getSize(), args.getCircular(), args.getSurviveRule(), args.getBornRule());
        gol.run();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}