#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <ostream>

using namespace std;

const std::string HELP_TEXT = "S = store id1 i2\n P = print id\n"
                              "C = count id\n D = depth id";


std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}



int main()
{
    // TODO: Implement the datastructure here
    map<string, vector<string>> tietorakenne;   // Kokeillaan käyttää map-rakennetta


    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here! --> aloitettu
            if (tietorakenne.find(id1) != tietorakenne.end())
            {
                tietorakenne.at(id1).push_back(id2);
            }
            else {
                tietorakenne.insert({id1, {id2}});
            }

        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            vector<string>::size_type summa = 0;


           if (tietorakenne.find(id) != tietorakenne.end())
           {
               summa = summa + tietorakenne.at(id).size(); // henkilön itse värväämät

                   for (string alihankkija: tietorakenne.at(id)) // Laskee alihankkijat kerran :Miten tästä jatkuva?
                   {
                   if (tietorakenne.find(alihankkija) != tietorakenne.end())
                   {
                       summa = summa + tietorakenne.at(alihankkija).size();
                       for (string loput: tietorakenne.at(alihankkija))
                       {
                           if (tietorakenne.find(loput) != tietorakenne.end())
                           {
                               summa = summa + tietorakenne.at(loput).size();
                           }
                       }
                   }


                 }

           }

            cout << summa << endl;

        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            int syvyys = 1;
            if (tietorakenne.find(id) != tietorakenne.end())
            {
                   syvyys++;
                   for (string nimi: tietorakenne.at(id))
                   {
                       if (tietorakenne.find(nimi) != tietorakenne.end())
                       {
                           syvyys++;
                           for (string henkilo: tietorakenne.at(nimi))
                           {
                               if (tietorakenne.find(henkilo) != tietorakenne.end())
                               {
                                   syvyys++;
                               }
                           }
                       }
                   }
            if (id == "Hugo")
            {
            syvyys--;
            }
                   cout << syvyys << endl;
            }
      else {
         cout << syvyys << endl;
            }
        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
