#include <iostream>

// Write here a function counting the mean value

int main()
{
    int lukujen_maara;
    double summa = 0;
    int viimeisin_luku;
    std::cout << "From how many integer numbers you want to count the mean value? ";
    std::cin >> lukujen_maara;
    if (lukujen_maara == 0 || lukujen_maara < 0)
    {
        std::cout <<  "Cannot count mean value from 0 numbers" << std::endl;
    }
    else {
        for (int i = 1; i <= lukujen_maara; ++i)
        {
           std::cout << "Input " << i << "." << " number: ";
           std::cin >> viimeisin_luku;
           summa = summa + viimeisin_luku;
        }
    std::cout << "Mean value of the given numbers is " << summa / lukujen_maara << std::endl;

    }
}
