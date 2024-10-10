#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;


int main()
{
    string tiedosto ="";
    cout << "Input file: ";
    getline(cin, tiedosto);
    ifstream tiedosto_olio(tiedosto);

    if ( not tiedosto_olio ){
        cout << "Error! The file " << tiedosto << " cannot be opened."<<endl;
        return EXIT_FAILURE;
        }
    else{
        string rivi ="";
        set<string> varasto = {};
        map<string, int> mappi = {};
        map<string, string> mappi2 = {};
        string zzz ="";
        vector<string> rivivektori = {};
        int rivinro = 0;
        while ( getline(tiedosto_olio, rivi) ){
            rivivektori.push_back(rivi);

                }

        for ( string vektorin_alkio : rivivektori ) {
            set<string> setti = { };
            rivinro = rivinro + 1;
            zzz = to_string(rivinro);
            string solu = "";
            std::stringstream iss( vektorin_alkio );

            while ( iss >> solu ){

                setti.insert( solu );}
            for (string alkio : setti){
                if (varasto.find(alkio) == varasto.end()){
                    varasto.insert(alkio);
                    mappi.insert({alkio, 1});
                    mappi2.insert({alkio, zzz});
                }
                else{
                    mappi.at(alkio) = mappi.at(alkio) + 1;
                    mappi2.at(alkio) = mappi2.at(alkio) +", "+ zzz;
                }

            }
        }
        int i = 0;
        string alakio ="";
        for ( auto tietopari : mappi ) {
                alakio = tietopari.first;
                cout << tietopari.first << " "
                     << tietopari.second << ": " <<mappi2.at(alakio) <<endl;
        i = i + 1;}

        return EXIT_SUCCESS;}


    tiedosto_olio.close();
}
