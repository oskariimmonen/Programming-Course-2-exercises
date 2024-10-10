#include <iostream>


int main()
{
    int lukujen_maara;
    std::cout << "How many numbers would you like to have? ";
    std::cin >> lukujen_maara;

    for (int i = 1; i <= lukujen_maara; ++i)
    {

     if (i % 3 == 0 && i % 7 == 0)
     {
         std::cout << "zip boing"  << std::endl;

     }


     else if (i % 3 == 0)
     {
     std::cout << "zip" << std::endl;
     }

     else if (i % 7 == 0)
     {
     std::cout << "boing" << std::endl;
     }

     else
     {
         std::cout << i << std::endl;
     }

}
}
