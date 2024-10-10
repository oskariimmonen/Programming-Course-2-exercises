#include <iostream>

using namespace std;

int main()
{
   int number;
   cout << "Enter a number: ";
   std::cin >> number;

   int cube = number*number*number;

   if (number == 0) {
       cout << "The cube of " << number << " is " << number << "." << endl;
       return EXIT_SUCCESS;
   }

   if (cube < 0)
   {
   std::cout << "Error! The cube of " << number << " is not " << cube <<"." << endl;

   } else if (cube/(number*number) != number) {

   std::cout << "Error! The cube of " << number << " is not " << cube <<"." << endl;
   }
  else {
   std::cout << "The cube of " << number << " is " << cube <<"." << endl;
   }




}
