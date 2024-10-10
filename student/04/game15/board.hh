/* Game15 (or puzzle 15) : Template code
 *
 * Class: Board
 *  Header file for the class "Board". Function declarations and comments
 * are found here. Constant size for game grid is also declared here with
 * constant vector "grid" in which we store the numbers needed in the game
 * in specific order
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

#ifndef BOARD_HH
#define BOARD_HH
#include <vector>

const int SIZE = 4;

class Board
{
public:
    // Constructor
    Board();

    //This is the function for random initialization.
    // Stores numbers needed in a vector and then calls
    //my_shuffle function to shuffle them in random order
    //After shuffles calls initalization with shuffled
    //vector as a parameter
    //User gives a seed value which is taken as
    // a parameter in this function
    void initialize_randomly(int seed);


    // Initialized the grid with the values of numbers vector (parameter)
    // The vector (numbers 1-16) is either shuffled by computer
    //or given by a user as a user input
    void initialize(const std::vector<unsigned int>& numbers);

    // Prints the game boar with values and order from
    // the vector "grid_"
    void print();

    // This function moves the a number that user wants to move
    //(if it is a legal move). Direction and the number to be
    // moved are taken as a parameter from user input
    void move(char direction, unsigned int moving_piece);

    //This function checks if the game has been won.
    //Game is won if numbers are in ascending order with
    //empty space in bottom right corner
    //Returns true if won, false if not.
    bool is_game_won();

    //This function checks if the game is solvable (=winnable)
    // at the beginning of the game. Returns true if it is and
    //false if the game is not solvable
    bool is_game_winnable();

private:    
    // Shuffles the numbers vector by using seed param as a seed value
    // if user does not give a seed value then it is randomly
    // chosen by computer clock
    void shuffle(std::vector<unsigned int>& numbers, int seed);

    // Game grid for the 15 puzzle. The numbers on the game board
    // are stored in this vector by user inputted numbers or random numbers
    // from the computer (1-16)
    std::vector<std::vector<unsigned int>> grid_;
};

#endif // BOARD_HH
