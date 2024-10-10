#include <iostream>

using namespace std;

int main()
{
    long int total;
    long int drawn;
    long int a;
    long int b;
    long int c;
    long int prob;

    cout << "Enter the total number of lottery balls:" << " " ;
    cin >> total;
    cout << "Enter the number of drawn balls:" << " ";
    cin >> drawn;

    if (drawn < 0 || total < 0)
    {
        cout << "The number of balls must be a positive number." << endl;
        return 0;
    }



    if (drawn > total)
    {
        cout << "The maximum number of drawn balls is the total amount of balls." << endl;
        return 0;
    }
   a = 1;
   for (int i = 1; i <= total; ++i)
   {
       a = a*i;
   }
       b = 1;
       for (int s = 1; s <= drawn; ++s)
       {
       b = b*s;
       }
     c = 1;
     for (int d = 1; d <= (total - drawn); ++d)
     {
     c = c*d;
     }
  prob = a/(c*b);
  if (total == 0)
  {
  prob = 1;
  }
    cout << "The probability of guessing all " << drawn << " balls correctly is " << "1/"<< prob << endl;

}
