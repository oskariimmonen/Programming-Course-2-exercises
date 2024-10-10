#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
string input_file = "";
cout << "Input file: ";
getline(cin, input_file);
int i = 1;

string output_file = "";
cout << "Output file: ";
getline(cin, output_file);
string line = "";
ifstream tiedosto(input_file);
if (not tiedosto) {
    cout << "Error! The file " << input_file << " cannot be opened.";
     return EXIT_FAILURE;
}
else {
ofstream ulos(output_file);

    while (getline(tiedosto, line) )
    {

        ulos << i <<" "<< line << endl;
        ++i;
    }
ulos.close();
tiedosto.close();
}

}
