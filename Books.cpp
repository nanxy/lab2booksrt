//============================================================================
// Name        : Books.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book
{
    string title;
    string author;
    string genre;
    string year;
};

bool getBooks (vector<Book> &books);

// Reads the books from a textfile into a vector
bool getBooks (vector<Book> &books)
{
    ifstream inputFile;
    string line;
    Book b;

    inputFile.open("Books.txt");
    if (inputFile.fail())
        return false;
    else
    {
        while (getline(inputFile, line))   // reads a line from the file
        {
            stringstream lineStream(line);   // transforms the line into a string stream

            // get fields from the string stream; fields are separated by comma in the input file
            getline(lineStream, b.title, ',');
            getline(lineStream, b.author, ',');
            getline(lineStream, b.genre, ',');
            getline(lineStream, b.year, ',');

            books.push_back(b); // add book to the vector

        }
        inputFile.close();
    }
    return true;
}
/**************************************************************************************************
            PROTOTYPES
**************************************************************************************************/
bool titleSort(Book b1, Book b2);//sort by title
bool authorSort(Book b1, Book b2);//sort by author
bool genreSort(Book b1, Book b2);//sort by genre
bool yearSort(Book b1, Book b2);//sort by year*/
void printBooks(vector<Book>bookDatabase);

/**************************************************************************************************
           MAIN
**************************************************************************************************/


int main()
{
    vector<Book> bookDatabase;
    char sortBy;
    char again;
    bool bookstatus =getBooks(bookDatabase);//to only get books once,
    do
    {
        if (bookstatus)
        {
            cout<< "Your database was successfully read! How would you like to sort the books?"<<endl;
            cout<< "Type 't' for sort by title,"<<endl<< "Type 'a' for sort by author,"<<endl;
            cout<< "Type 'g' for sort by genre,"<<endl<<"Type 'y' for sort by year."<<endl;

            cin>>sortBy;

            switch(sortBy)
            {
            case 't' :
                cout << "Sorted by Title:" << endl;
                sort (bookDatabase.begin(), bookDatabase.end(), titleSort);
                printBooks(bookDatabase);
                break;
            case 'a' :
                  cout << "Sorted by Author:" << endl;
                sort (bookDatabase.begin(), bookDatabase.end(), authorSort);
                 printBooks(bookDatabase);
                break;
            case 'g' :
                   cout << "Sorted by Genre:" << endl;
                sort (bookDatabase.begin(), bookDatabase.end(), genreSort);
                printBooks(bookDatabase);
                break;
            case 'y' :
                cout << "Sorted by Year:" << endl;
                sort (bookDatabase.begin(), bookDatabase.end(), yearSort);
                printBooks(bookDatabase);
                break;
            default :
                cout << "Input not recognized." << endl;
            }

            cout << endl<<"Would you like to sort again?" <<endl<<"Type any key to sort again, enter '#' to quit.";
            cin>>again;
            cout<<endl;
        }
        else
        {
            cout<<endl<<"Error opening database file, would you like to try again?"<< endl;
            cout<<"Type any key to try again, enter '#' to quit.";
            cin>> again;
            cout<<endl;
        }
    }
    while (again!='#');
    cout <<"Thank you for using this program"<<endl;

    return 0;
}
/**************************************************************************************************
           Sort by TITLE
************************************************************************************************
bool titleSort(vector<Book>bData)
*/
bool titleSort(Book b1, Book b2)
{
     return (b1.title < b2.title);
}

/**************************************************************************************************
           Sort by AUTHOR
**************************************************************************************************/
bool authorSort(Book b1, Book b2)
{
    return (b1.author < b2.author);
}

/**************************************************************************************************
           Sort by GENRE
**************************************************************************************************/
bool genreSort(Book b1, Book b2)
{
    return (b1.genre < b2.genre);
}

/**************************************************************************************************
           Sort by YEAR
*************************************************************************************************/
bool yearSort(Book b1, Book b2)
{
    return (b1.year < b2.year);
}

/**************************************************************************************************
           Print book data
*************************************************************************************************/
void printBooks(vector<Book>bookDatabase)
{
    //cout<<bookDatabase.size<<endl;//to check if vector is exponentially increasing in the program
    cout.width(40);
    cout<<left<< "Title";
    cout.width(20);
    cout<<"Author"<<left;
    cout.width(25);
    cout<<"Genre"<<left;
    cout.width(5);
    cout<<"Year"<<left<<endl;
    cout<< "-----------------------------------------------------------------------------------------------------"<<endl;
    for (Book val:bookDatabase)
                {
                    cout.width(40);
                    cout<<left<< val.title;
                    cout.width(20);
                    cout<<val.author<<left;
                    cout.width(25);
                    cout<<val.genre<<left;
                    cout.width(10);
                    cout<<val.year<<left<<endl;
                    cout<<"_____________________________________________________________________________________________________"<<endl;
                }
}

/*================================================================================================
           OUTPUT
/*================================================================================================


-------------------------------------------------------------------------------------------------------*/
