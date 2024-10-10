#include <cstdlib>
#include <iostream>
#include <vector>


void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        // TODO: Implement your solution here --> Valmis.
        ints.push_back(new_integer);

    }
}

// TODO: Implement your solution here
bool same_values(std::vector<int>& ints)
{
int koko = ints.size();
bool totuusarvo;
for (int i = 0; i < koko-1; ++i)
   {
    if (ints.at(i) == ints.at(i+1))
    {
        totuusarvo = true;
    }
    else {
        return false;
        break;
    }

   }
   return totuusarvo;
}

bool is_ordered_non_strict_ascending(std::vector<int>& ints)
{
int koko = ints.size();
bool totuusarvo;

   for (int i = 0; i < koko-1; ++i)
   {
    if (ints.at(i) > ints.at(i+1))
    {
     return false;
    }
    else{
        totuusarvo = true;
    }

   }

return totuusarvo;
}

bool is_arithmetic_series(std::vector<int> ints)
{
int koko = ints.size();
int erotus = ints.at(1) - (ints.at(0));
bool totuusarvo;
for (int i = 0; i < koko-1; ++i)
{
    if (ints.at(i+1) - ints.at(i) == erotus)
    {
     totuusarvo = true;
    }
    else {
        return false;
    }

}
return totuusarvo;
}

bool is_geometric_series(std::vector<int> ints)
{
int koko = ints.size();
bool totuusarvo;
if (ints.at(0) == 0) {
    return false;
}
int osamaara = ints.at(1) / ints.at(0);
  for (int i = 0; i < koko-1; ++i)
   {
    if (ints.at(i+1) / ints.at(i) == osamaara)
    {
      totuusarvo = true;
    }
    else {
        return false;
    }
  }
return totuusarvo;
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
