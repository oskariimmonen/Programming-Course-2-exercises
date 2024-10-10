
/* Game15 (or puzzle 15) : Template code
 *
 * Class: Board
 * Functions declared in board.hh file found here. Contains every
 * function in Board class. Check more specific information about
 * the functions from the header-file board.hh.
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 *
 * Notes:
 *
 * */

#include "board.hh"
#include <iostream>
#include <iomanip>
#include <random>

const int EMPTY = 16;
const unsigned int PRINT_WIDTH = 5;

Board::Board()
{

}


void Board::initialize_randomly(int seed)
{
    //numbers needed in this game stored in a vector
    std::vector<unsigned int> numbers = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        shuffle(numbers, seed); //shuffles the numbers to random order
        initialize(numbers); // initialize board with shuffled numbers
}


void Board::initialize(const std::vector<unsigned int> &numbers)
{
    std::vector<unsigned int> values = numbers; //let us call the vector "values" to avoid confusion

    int values_index = 0;
       for(int i = 0;i < SIZE;i++)
          {
              std::vector<unsigned int> assistant_vector; // assistant vector assists the program to push
              for(int j = 0;j < SIZE;j++)                 // numbers to constant vector "grid"
              {
                  assistant_vector.push_back(values.at(values_index));
                  ++ values_index;

              }
              grid_.push_back(assistant_vector);
          }

}


void Board::print()
{
    for(unsigned int x = 0; x < SIZE; ++x)
    {
        std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
        for(unsigned int y = 0; y < SIZE; ++y)
        {
            std::cout << "|" << std::setw(PRINT_WIDTH - 1);
            if(grid_.at(x).at(y) != EMPTY)
            {
                std::cout << grid_.at(x).at(y);
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
}


void Board::shuffle(std::vector<unsigned int> &numbers, int seed)
{
    std::default_random_engine randomEng(seed);
    std::uniform_int_distribution<int> distr(0, numbers.size() - 1);
    for(unsigned int i = 0; i < numbers.size(); ++i)
    {
        unsigned int random_index = distr(randomEng);
        unsigned int temp = numbers.at(i);
        numbers.at(i) = numbers.at(random_index);
        numbers.at(random_index) = temp;
    }
}


void Board::move(char direction, unsigned int moving_piece)
{
    // Finding the piece that the user wants to move from the 2-dimensional vector.
    int row = 0, column = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid_.at(i).at(j) == moving_piece)
            {
                row = i;
                column = j;
                i = SIZE;
                break;
            }
        }
    }

    // Changing the places of the hole and piece that is moving.
    int moving_to_row = row, moving_to_column = column;
    bool is_possible = false;
    if (direction == 'a'){
        if (grid_[row][column - 1] == 16){
            --moving_to_column;
            is_possible = true;
        }
    }
    if (direction == 'd'){
        if (grid_[row][column + 1] == 16){
            ++moving_to_column;
            is_possible = true;
        }

    }
    if (direction == 's' and row != SIZE - 1){
         if(grid_[row + 1][column] == 16){
            ++moving_to_row;
             is_possible = true;
         }
    }
    if (direction == 'w' and row != 0){
        if(grid_[row - 1][column] == 16) {
            --moving_to_row;
            is_possible = true;
        }
    }

    if (is_possible){
        grid_[moving_to_row][moving_to_column] = moving_piece;
        grid_[row][column] = 16;
    }
    else{
        std::cout << "Impossible direction: " << direction << std::endl;
    }
}


bool Board::is_game_won()
{
    unsigned int checker = 1;
    for (int i = 0; i < SIZE; ++i)
    {
           for (int j = 0; j < SIZE; ++j)
           {
               if (grid_[i][j] != checker)               {
                return false;
               }
               checker++;
           }
    }
    return true;
}


bool Board::is_game_winnable()
{
    // Finding the 'hole' from the gmame board
    int row = 0, column = 0, moving_row;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (grid_[i][j] == 16) {
                row = i;
                column = j;
                i = SIZE;
                break; }
        }
    }

    // Moving the 'hole' to the bottom row
    for (moving_row = row + 1; moving_row < SIZE; ++moving_row){
        Board::move('w', grid_[moving_row][column]);
    }

    // Calculating the number of inversions
    unsigned int checking, against, inversions = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            checking = grid_[i][j];
            if (checking != 16)
            {


                // First checking rest of the row where the current number is located
                for (int m = j + 1; m < SIZE; ++m){
                    against = grid_[i][m];
                    // cout << against << endl;     Test print
                    if (checking > against){
                        ++inversions;
                    }
                }

                // Second checking all remaining rows for inversions
                for (int k = i + 1; k < SIZE; ++k)
                {
                    for (int l = 0; l < SIZE; ++l)
                    {
                        against = grid_[k][l];

                        if (checking > against){
                            ++inversions;  }
                    }
                }
            }
        }
    }

    // Moving the hole back to it's original location
    --moving_row;
    while (moving_row != row){
        --moving_row;
        Board::move('s', grid_[moving_row][column]);
    }

    // Calculating whether there are an odd or even number of inversions and returning a corresponding value
    if (inversions % 2 == 0){
        return true;
    }
    else{
        return false;
    }
 }
