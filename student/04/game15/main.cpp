
/* Game15 (or puzzle 15) : Template code
 *
 * Desc:
 *  This program generates a 15 puzzle. The board is SIZE x SIZE,
 * (original was 4x4) and every round the player chooses a direction and
 * a number tile, making the given tile to be moved to the given direction.
 *  Game will end when the numbers 1-15 (1-16) are in the ascending order,
 * starting from top left and proceeding row by row.
 * Empty space is represented by the number 16 in the code (constant EMPTY)
 * and by dot when printing the game board.
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 *
 * Notes about the program and it's implementation:
 * Program starts in the main function. First it calls
 * initialie_board function from which it enters the Board class
 * based on the initilization mode that the user chooses.
 * */

#include "board.hh"
#include <string>
#include <iostream>
#include <algorithm>
#include<iterator>


//Initializes the game board with random numbers or with user input.
// User can choose between those ways to initialize the board.
// Board class pointer is taken as a parameter.
bool initialize_board(Board& g_board)
{
    std::string init_mode = "";
    while(init_mode != "y" and init_mode != "Y" and init_mode != "n" and init_mode != "N")
    {
        std::cout << "Random initialization (y/n): ";
        std::getline(std::cin, init_mode);

        if(init_mode == "y" or init_mode == "Y") // If user chooses random initialization.
        {
            std::cout << "Enter a seed value (or an empty line): ";
            std::string seed = "";
            std::getline(std::cin, seed);
            if(seed == "")
            {
                g_board.initialize_randomly(time(0)); // random_init function call without a seed value
            }
            else
            {
                g_board.initialize_randomly(stoi(seed)); // random init function call
                                                         //if user chooses to give a seed value
            }
            return true;
        }
        else if(init_mode == "n" or init_mode == "N") // this runs if user chooses to give the numbers
        {
            std::cout << "Enter the numbers 1-16 in a desired order (16 means empty):" << std::endl;
            std::vector<unsigned int> inputs;

            for(unsigned int i = 0; i < SIZE * SIZE; ++i)
            {
                unsigned int input = 0;
                std::cin >> input;
                inputs.push_back(input);
            }

              unsigned int checker = 1;
              for (unsigned int i = 0; i < 16; i++)
              {
              bool exists;
              exists = std::find(std::begin(inputs), std::end(inputs), checker) !=std::end(inputs);

                 if (exists == false)
                 {
                  std::cout << "Number " << checker << " is missing" << std::endl;
                  return false;
                 }
          checker++;
              }
          g_board.initialize(inputs);
        }
            else{
                 std::cout << "Unknown choice: " << init_mode << std::endl;
                }
    }
    return true;  // This should never be reached
}



//Main-function. Program is controllerd here. The strucure for user making
//moves and giving inputs is in the while-loop.
int main()
{
    Board game_board;
    std::string command = "";
    unsigned int number; // the number that user decides to move
    char command_direction;

    if(!initialize_board(game_board))
    {
        return EXIT_FAILURE;
    }

    //This loop checks if the game has been won at the start
    // because user has inserted the numbers in the winning order
    // for example
    if(game_board.is_game_won() == true) {
        game_board.print();
        std::cout << "You won!" << std::endl;
        return EXIT_SUCCESS;
    }


    // Here is the call for a function that checks
    // if the game is solvable.
    if (game_board.is_game_winnable() == false){
           std::cout << "Game is not solvable. What a pity." << std::endl;
            return EXIT_SUCCESS;

    } else {
        std::cout << "Game is solvable: Go ahead!" << std::endl;
    }


 while(true)  {

      game_board.print();
      std::cout << "Dir (command, number): ";
      std::cin >> command;

            if (command == "q") // user can end the program with input "q".
            {
             return EXIT_SUCCESS;
            }

            //std::cin >> number;

            if (command == "a" or command == "s" or command == "d" or command == "w")
                       {
                std::cin >> number;
                if(!std::cin) {
                std::cout << "Invalid number: " << number << std::endl;
                break;
                }
                           if (number < 17 and number > 0)
                           {
                               command_direction = command[0];
                               game_board.move(command_direction, number);
                           }
                           /*else{
                                std::cout << "Invalid number: " << number << std::endl;
                               } */
                       }

                       else{
                           std::cout << "Unknown command: " << command << std::endl;
                           }


           if(game_board.is_game_won() == true) //function call to check if the game has
           {                                    //has been won after every move
               game_board.print();
               std::cout << "You won!" << std::endl;
               return EXIT_SUCCESS;
           }

       }

   return EXIT_SUCCESS;
}


