
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Direction.hpp"

using namespace std;

#define V Direction::Vertical
#define H Direction::Horizontal

namespace ariel
{
    class Board
    {
        public:

            vector<vector<char>> ch;
            unsigned int x,y;

            Board();
            void post(unsigned int, unsigned int, Direction, string);
            string read(unsigned int, unsigned int, Direction, unsigned int);
            void show();
    
    };
}


#endif