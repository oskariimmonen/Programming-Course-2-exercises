
/* Library : Template code
 *
 * Desc:
 * This program works as an information system for
 * a library. The data comes from an external file.
 * Program opens the file and stores the data into a map format
 * User is able to use search algorithms such as loanable books,
 * specific authros books in a specific library and so on. All the commands
 * can be found in the main() function. Programs runs until user types the command
 * "quit".
 *
 * Program author
 * Name: Oskari Immonen
 * Student number: 291868
 * UserID: pvosim
 * E-Mail: oskari.j.immonen@tuni.fi
 * */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

const string SPACE = " ";
const char QUOTATIONMARK = '"';
const int MAX_RESERVATIONS = 100;
const vector<string>::size_type RESERVABLE_PARAMS = 2;

//struct contains information about a book
//books are stored in vector of sctructs vector<Book>
// inside a map
struct Book {
    string title;
    string author;
    int reservations;
};

using Database = map<string, vector<Book>>;


// split a given string(parameter) by given delimeter(parameter).
//returns the splitted string in a vector.
vector<string> split(const string& s, const char delimiter, bool ignore_empty = false){
    vector<std::string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
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


//sorts books alphabetically by the author of the book.
//Takes two Book references as parameters that the function compares.
//returns bool value based on the alphabetic order
// true if first_book is in a correct place compared to second.
//false if not
bool sort_by_author(const Book &first_book, const Book &second_book)
{
    return first_book.author < second_book.author;
}


//sorts books alphabetically by the title of the book.
//Takes two Book references as parameters that the function compares.
//returns bool value t based on the alphabetic order
// true if first_book is in a correct place compared to second.
//false if not
bool sort_by_book_name(const Book&first_book, const Book &second_book)
{
    return first_book.title < second_book.title;
}


//sorts books alphabetically by their titles.
//Compares the book names  that are given as parameters and
//returns boolean value true if they are in correct order and false if not
bool sort_book_names(string first_book_name, string second_book_name) {
    return first_book_name < second_book_name;
}


//stores the data into the database map<string, vector<Book>>.
// Takes the database,library name and book to be added to database
// as parameters. Returns true either way. Fail is handled in main().
bool store_to_database(Database& books, string location, Book book) {
    Database::iterator iter = books.find(location);

    //if the given library name is not found
    if (iter == books.end()) {
        books.insert({location, {book}});
    } else {
       books.at(location).push_back(book);
    }
    return true;
}


//reads the file that user defines. Prints error messages
// if the reading fails. At success calls store_to_database
//with read info about the book.Takes database as param and
//returns true if reading is ok, false if it fails
bool read_file(Database& books) {
    string library = "";
       string author = "";
       string title = "";
       Book temp;
       string input_file = "";
       cout << "Input file: ";
       getline(cin, input_file);

       ifstream file(input_file);
       if (not file)
       {
           cout << "Error: the input file cannot be opened" << endl;
            return false;
       }

       string row = "";
       vector<Book> book_data;
       while (getline(file, row)) {
           vector<string> parts = split(row, ';', true);

          if (parts.size() != 4) { //if != 4, the data is incorrect
          cout << "Error: empty field" <<endl;
          return false;
          } else {
              library = parts.at(0);
              author = parts.at(1);
              title = parts.at(2);
              int reservations;
              if (parts.at(3) == "on-the-shelf") {
                  reservations = 0;
                  //cout << reserved << endl;
              } else {
                  istringstream(parts.at(3)) >> reservations; //converts data type to int
              }
              temp = {title, author, reservations};
              book_data.push_back(temp);
               store_to_database(books, library, temp);
          }

        }


   return true;


}


//prints the libraries found in the datafile
//takes the database as parameter
void print_libraries(Database& books) {
    map<string, vector<Book>>::iterator iter;
        iter = books.begin();
        while ( iter != books.end() ) {
            cout << iter->first << " "
                << endl;
            ++iter;
        }
}


//prints the books found in given library (parameter)
// Also takes the database as parameter
void print_material(Database& books, string library_name) {
    vector<Book> temp = books.at(library_name);
    bool book_exists = false;
    map<string, vector<string>> book_data;
       sort(temp.begin(), temp.end(),sort_by_author); //sorts books by author
       vector<Book>::size_type size = 0;
       size = temp.size();
       Book book;

       //this loop is for storing books to print in a map
       // this is to avoid duplicates
       for (vector<Book>::size_type i = 0; i < size; i++) {
           book = temp.at(i);

           if (book_data.find(book.author) != book_data.end()) {
              for (auto c : book_data.at(book.author)) {
                  if (c == book.title) {
                      book_exists = true;
                  }
              }
              if (!book_exists) {
                  book_data.at(book.author).push_back(book.title);
              }
           } else {
               book_data.insert({book.author, {book.title}});
           }
       }



       //prints out the map of books in a library

       vector<string> temporary;

       for(auto iter = begin(book_data); iter != end(book_data); ++iter)
       {
           temporary = iter->second;
           sort(temporary.begin(), temporary.end(), sort_book_names);
           for(auto c : temporary)
           {
               std::cout << iter->first << ": ";
               std::cout << c << endl;
           }
       }
}


//Iterates through the whole database (param) to check if given
//library(param) is already there. Returns true if it is and
// false if not
bool check_library_existence(Database& books, string building){

    map<string, vector<Book>>::iterator iter;
        iter = books.begin();
        while ( iter != books.end() ) {
            if(iter->first == building) {
                return true;
            }
       ++iter;
        }
        return false;
}


// Iterates through the database (param) to check if the given
// author (param) is already there. Returns true if it is
// and false if not
bool check_author_existence(Database& books, string author){
    map<string, vector<Book>>::iterator pointer;
        pointer = books.begin();
        vector<Book> temporary;
        for(auto mapIt = begin(books); mapIt != end(books); ++mapIt)
        {
            temporary = mapIt->second;
            for(auto c : temporary)
            {
                vector<string>test = {};
                test.push_back(mapIt->first);
                if (c.author == author) {
                    return true;

            }
        }
}
   return false;
}


// This prints specific authors(param) books in specific library(param)
// This runs if user uses the command books correctly. Iterates through
//database and prints the book info when needed.
void print_authors_books(Database& books, string library, string author_parameter) {


    vector<Book> temp = books.at(library);
    sort(temp.begin(), temp.end(),sort_by_book_name); //sorts books by title
    vector<Book>::size_type size = 0;
    size = temp.size();
    Book book;

    for (vector<Book>::size_type i = 0; i < size; i++) {
        book = temp.at(i);
        if (book.author == author_parameter) {
            cout << book.title << " --- ";
            if (book.reservations == 0) {
                cout << "on the shelf" << endl;
            } else {
                cout << book.reservations << " reservations" << endl;
            }
        }
    }
}


//This is run when user uses the command reservable correctly
//iterates through database(param) and checks for reservable
// book(param). Stores reservable books in other map and then prints
// the map
void print_reservation_line(Database& books, string reservable){
    bool book_is_found = false;
    map<int, vector<string>> reservables; //map mentioned in function desc
    map<string, vector<Book>>::iterator pointer;
        pointer = books.begin();
        vector<Book> temporary;

        for(auto mapIt = begin(books); mapIt != end(books); ++mapIt)
        {
            temporary = mapIt->second;
            for(auto c : temporary)
            {
                vector<string>book_names = {};
                if (c.title == reservable) {
                    book_is_found = true;
                    book_names.push_back(mapIt->first);
                    if (reservables.find(c.reservations) != reservables.end()) {

                        reservables.at(c.reservations).push_back(mapIt->first);

                    } else {
                        reservables.insert({c.reservations, {book_names}});
                    }           
                }
            }

        }

            if(book_is_found == false) {
                cout << "Book is not a library book." << endl;
            } else {                
                vector<string> temp;

                for(auto mapIt = begin(reservables); mapIt == begin(reservables); ++mapIt)
                {
                temp = mapIt->second;
                if (mapIt->first == 0) {
                    cout << "on the shelf" << endl;
                    for (auto s : temp) { //prints libraries with book on the shelf
                        cout << "--- " << s << endl;
                    }
                    break;
                }

                if (mapIt->first >= 100) {
                    cout << "The book is not reservable from any library." << endl;
                } else {

                    cout << mapIt->first << " reservations" << endl;
                    for(auto c : temp)
                    {
                    std::cout << "--- " << c << endl;                
                    }
                }
                }
            }
}


// This is run when user uses comman loanable. Prints
// books that have less than 100 reservations. Store loanables
// in other map and print the map after iterations
void print_loanable_books(Database& books) {
    map<string, vector<string>> loanable_books = {};
    map<string, vector<Book>>::iterator iter;
    Book book;
    vector<Book> temp;
    vector<Book>::size_type size = 0;    
    string library_name = "";
    string author = "";

    iter = books.begin();
    while ( iter != books.end() ) {
        library_name = iter->first;
        temp = books.at(library_name);
        size = temp.size();

        for (vector<Book>::size_type i = 0; i < size; i++) {
            book = temp.at(i);
            author = book.author;
            if (book.reservations == 0) {

                if (loanable_books.find(author) != loanable_books.end()) {

                    for (string name : loanable_books.at(author)) {

                        if (name == book.title) {
                            continue;
                        } else {
                            loanable_books.at(author).push_back(book.title);
                        }
                    }
                    }
                else {
                   vector<string>test = {book.title};
                    loanable_books.insert({book.author, test});
                }
            }
        }

      ++iter;        
    }

        //printing the created map of loanable books
        map<string, vector<string>>::iterator pointer;
            pointer = loanable_books.begin();
            vector<string> temporary;
            for(auto mapIt = begin(loanable_books); mapIt != end(loanable_books); ++mapIt)
            {
                temporary = mapIt->second;
                sort(temporary.begin(), temporary.end(), sort_book_names);
                for(auto c : temporary)
                {
                    std::cout << mapIt->first << ": ";
                    std::cout << c << endl;
                }
            }


}


//this runs when user types incorrect parameters
//prints error message
void print_parameter_error() {
    cout << "Error: error in command books" << endl;
}


// Program initilization. Calls the reading of the file
//and storing to database. Basics of UI found inside while-loop
int main()
{
    Database books;

    // if reading fails program stops running
    if(!read_file(books)) {
        return EXIT_FAILURE;
    }

    string command = "";
    string command_line = "";
    string reservable_book= "";
    vector<string> splitted_command = {};
    string library_command = "";
    string author_command = "";
    string book_name = "";
    vector<string>::size_type size = 0;
    string::size_type string_sice = 0;

    //Loops until user types "quit"
    while (true) {
        cout << "> ";
        getline(cin, command_line);
        string::size_type checker = 0;
        checker = command_line.find(SPACE);

        if(checker != string::npos) {
        splitted_command = split(command_line, ' ');
        command = splitted_command.at(0);
        library_command = splitted_command.at(1);
        } else {
            command = command_line;
        }

        if (command_line == "quit") {
            return EXIT_SUCCESS;
        }
        else if (command_line == "libraries") {
            print_libraries(books);
        }
        else if (command_line == "loanable") {
            print_loanable_books(books);
        }
        else if (command == "material") {

            if(!check_library_existence(books,library_command)) {
            cout << "Error: unknown library name" << endl;
            } else {
                print_material(books, library_command);
            }
            } else if (command == "books") {
                if (splitted_command.size() < 3)
                {
                    print_parameter_error();
                } else {
                    author_command = splitted_command.at(2);
                    if(!check_library_existence(books, library_command)){
                            cout << "Error: unknown library name" << endl;
                } else if(!check_author_existence(books,author_command)) {
                        cout << "Error: unknown author" << endl;
                    } else {

                    author_command = splitted_command.at(2);
                    print_authors_books(books, library_command, author_command);
                    }
                }

            } else if (command == "reservable") {
                splitted_command.erase(splitted_command.begin());
                size = splitted_command.size();

                for (vector<string>::size_type i = 0; i < size; i++) {
                    reservable_book += splitted_command.at(i);
                    reservable_book += " "; // name of the book

                }
                reservable_book.pop_back(); // Deletes last space created by for-loop
                string_sice = reservable_book.find(QUOTATIONMARK);

                if(string_sice != string::npos) {
                splitted_command = split(reservable_book, QUOTATIONMARK);
                reservable_book = splitted_command.at(1);
                print_reservation_line(books, reservable_book);
                reservable_book = "";
                } else {
                    print_reservation_line(books, reservable_book);
                    reservable_book = "";
                }       
        } else {
            cout << "Error: Unknown command: " << command << endl;
        }
    }
    return EXIT_SUCCESS;
}
