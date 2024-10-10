#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string input_file = "";
    cout << "Input file: ";
    getline(cin, input_file);

    string nimi;



    ifstream tiedosto(input_file);
    if (not tiedosto) {
                      cout << "Error! The file " << input_file << " cannot be opened." << endl;
                     return EXIT_FAILURE;
                      }
         else {
             map<string, int> pistemaarat;
             while (getline(tiedosto, nimi))
             {
                 string pelaaja = nimi.substr(0, nimi.find(":"));
                 string numerosana = nimi.substr(nimi.find(":")+1, nimi.length() - nimi.find(":")+1);

            if (pistemaarat.find(pelaaja) != pistemaarat.end() ) {
            pistemaarat.at(pelaaja) = pistemaarat.at(pelaaja) + std::stoi(numerosana);
            }
            else {
                pistemaarat.insert({nimi.substr(0, nimi.find(":")), std::stoi(numerosana)});
            }

             }
          map<string, int>::iterator iter;
          iter = pistemaarat.begin();
          cout << "Final scores:" << endl;
          while (iter != pistemaarat.end() )
          {
              cout << iter->first << ":" << " " << iter->second << endl;
              ++iter;
          }

tiedosto.close();
    }
    }
