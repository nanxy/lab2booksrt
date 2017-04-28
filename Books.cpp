//============================================================================
// Name        : Books.cpp
// Author      :Nancy Zhou
// Version     :2.0
// Copyright   :4/27/17
// Description :Opens file and creates a Book structure vector. User is
//              prompted to choose sorting method. The algorithm sort
//              function uses a bool function that compares the specified type,
//              and the print function formats and prints the results.
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
        }//if the getbooks worked, create vector ONCE and sort by user input
        else
        {
            cout<<endl<<"Error opening database file, would you like to try again?"<< endl;
            cout<<"Type any key to try again, enter '#' to quit.";
            cin>> again;
            cout<<endl;
        }//if the file was not found
    }
    while (again!='#');
    cout <<"Thank you for using this program"<<endl;//end program

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
Your database was successfully read! How would you like to sort the books?
Type 't' for sort by title,
Type 'a' for sort by author,
Type 'g' for sort by genre,
Type 'y' for sort by year.
t
Sorted by Title:
Title                                   Author              Genre                    Year
-----------------------------------------------------------------------------------------------------
1984                                     Geroge Orwell       poli-fiction             1949
_____________________________________________________________________________________________________
Another                                  Yukito Ayatsuju     horror                   2009
_____________________________________________________________________________________________________
Bleach                                   Tite Kubo           supernatural             2001
_____________________________________________________________________________________________________
Divergent                                Veronica Roth       dystopian fiction        2011
_____________________________________________________________________________________________________
Fall of Giants                           Ken Follett         historical fiction       2010
_____________________________________________________________________________________________________
Friday Night Lights                      H.G.Bissinger       nonfiction               1990
_____________________________________________________________________________________________________
Harry Potter : Sorcerer's Stone          JK Rowling          fiction                  1997
_____________________________________________________________________________________________________
Harry Potter and the Goblet of Fire      JK Rowling          fantasy                  2000
_____________________________________________________________________________________________________
Harry Potter and the Half Blood Prince   JK Rowling          fiction                  2009
_____________________________________________________________________________________________________
I Thought It Was Just me                 Brene Brown         self help                2007
_____________________________________________________________________________________________________
Lord of the flies                        William Golding     fiction                  1954
_____________________________________________________________________________________________________
Oh the Places We'll Go                   Dr. Suess           children's picture book  1990
_____________________________________________________________________________________________________
Out of Control                           Kevin Kelly         computer science         1994
_____________________________________________________________________________________________________
Replay                                   Ken Grimwood        fantasy                  1986
_____________________________________________________________________________________________________
Sophie's World                           Jostein Gaarder     philosophical fiction    1991
_____________________________________________________________________________________________________
The Book Thief                           Markus Zusak        historical fiction       2005
_____________________________________________________________________________________________________
The Book of Unknown Americans            Cristina Henriquez  fiction                  2014
_____________________________________________________________________________________________________
The Girl with the Dragon Tatoo           Stieg Larsson       crime                    2005
_____________________________________________________________________________________________________
The Great Gatsby                         Scott Fitzgerald    historical fiction       1925
_____________________________________________________________________________________________________
The Perks of Being a Wallflower          Stephen Chbosky     fiction                  1999
_____________________________________________________________________________________________________
The Three-Body Problem                   Liu Cixin           science fiction          2006
_____________________________________________________________________________________________________

Would you like to sort again?
Type any key to sort again, enter '#' to quit.;

Your database was successfully read! How would you like to sort the books?
Type 't' for sort by title,
Type 'a' for sort by author,
Type 'g' for sort by genre,
Type 'y' for sort by year.
a
Sorted by Author:
Title                                   Author              Genre                    Year
-----------------------------------------------------------------------------------------------------
I Thought It Was Just me                 Brene Brown         self help                2007
_____________________________________________________________________________________________________
The Book of Unknown Americans            Cristina Henriquez  fiction                  2014
_____________________________________________________________________________________________________
Oh the Places We'll Go                   Dr. Suess           children's picture book  1990
_____________________________________________________________________________________________________
1984                                     Geroge Orwell       poli-fiction             1949
_____________________________________________________________________________________________________
Friday Night Lights                      H.G.Bissinger       nonfiction               1990
_____________________________________________________________________________________________________
Harry Potter : Sorcerer's Stone          JK Rowling          fiction                  1997
_____________________________________________________________________________________________________
Harry Potter and the Goblet of Fire      JK Rowling          fantasy                  2000
_____________________________________________________________________________________________________
Harry Potter and the Half Blood Prince   JK Rowling          fiction                  2009
_____________________________________________________________________________________________________
Sophie's World                           Jostein Gaarder     philosophical fiction    1991
_____________________________________________________________________________________________________
Fall of Giants                           Ken Follett         historical fiction       2010
_____________________________________________________________________________________________________
Replay                                   Ken Grimwood        fantasy                  1986
_____________________________________________________________________________________________________
Out of Control                           Kevin Kelly         computer science         1994
_____________________________________________________________________________________________________
The Three-Body Problem                   Liu Cixin           science fiction          2006
_____________________________________________________________________________________________________
The Book Thief                           Markus Zusak        historical fiction       2005
_____________________________________________________________________________________________________
The Great Gatsby                         Scott Fitzgerald    historical fiction       1925
_____________________________________________________________________________________________________
The Perks of Being a Wallflower          Stephen Chbosky     fiction                  1999
_____________________________________________________________________________________________________
The Girl with the Dragon Tatoo           Stieg Larsson       crime                    2005
_____________________________________________________________________________________________________
Bleach                                   Tite Kubo           supernatural             2001
_____________________________________________________________________________________________________
Divergent                                Veronica Roth       dystopian fiction        2011
_____________________________________________________________________________________________________
Lord of the flies                        William Golding     fiction                  1954
_____________________________________________________________________________________________________
Another                                  Yukito Ayatsuju     horror                   2009
_____________________________________________________________________________________________________

Would you like to sort again?
Type any key to sort again, enter '#' to quit.;

Your database was successfully read! How would you like to sort the books?
Type 't' for sort by title,
Type 'a' for sort by author,
Type 'g' for sort by genre,
Type 'y' for sort by year.
g
Sorted by Genre:
Title                                   Author              Genre                    Year
-----------------------------------------------------------------------------------------------------
Oh the Places We'll Go                   Dr. Suess           children's picture book  1990
_____________________________________________________________________________________________________
Out of Control                           Kevin Kelly         computer science         1994
_____________________________________________________________________________________________________
The Girl with the Dragon Tatoo           Stieg Larsson       crime                    2005
_____________________________________________________________________________________________________
Divergent                                Veronica Roth       dystopian fiction        2011
_____________________________________________________________________________________________________
Harry Potter and the Goblet of Fire      JK Rowling          fantasy                  2000
_____________________________________________________________________________________________________
Replay                                   Ken Grimwood        fantasy                  1986
_____________________________________________________________________________________________________
The Book of Unknown Americans            Cristina Henriquez  fiction                  2014
_____________________________________________________________________________________________________
Lord of the flies                        William Golding     fiction                  1954
_____________________________________________________________________________________________________
The Perks of Being a Wallflower          Stephen Chbosky     fiction                  1999
_____________________________________________________________________________________________________
Harry Potter and the Half Blood Prince   JK Rowling          fiction                  2009
_____________________________________________________________________________________________________
Harry Potter : Sorcerer's Stone          JK Rowling          fiction                  1997
_____________________________________________________________________________________________________
Fall of Giants                           Ken Follett         historical fiction       2010
_____________________________________________________________________________________________________
The Book Thief                           Markus Zusak        historical fiction       2005
_____________________________________________________________________________________________________
The Great Gatsby                         Scott Fitzgerald    historical fiction       1925
_____________________________________________________________________________________________________
Another                                  Yukito Ayatsuju     horror                   2009
_____________________________________________________________________________________________________
Friday Night Lights                      H.G.Bissinger       nonfiction               1990
_____________________________________________________________________________________________________
Sophie's World                           Jostein Gaarder     philosophical fiction    1991
_____________________________________________________________________________________________________
1984                                     Geroge Orwell       poli-fiction             1949
_____________________________________________________________________________________________________
The Three-Body Problem                   Liu Cixin           science fiction          2006
_____________________________________________________________________________________________________
I Thought It Was Just me                 Brene Brown         self help                2007
_____________________________________________________________________________________________________
Bleach                                   Tite Kubo           supernatural             2001
_____________________________________________________________________________________________________

Would you like to sort again?
Type any key to sort again, enter '#' to quit.;

Your database was successfully read! How would you like to sort the books?
Type 't' for sort by title,
Type 'a' for sort by author,
Type 'g' for sort by genre,
Type 'y' for sort by year.
y
Sorted by Year:
Title                                   Author              Genre                    Year
-----------------------------------------------------------------------------------------------------
The Great Gatsby                         Scott Fitzgerald    historical fiction       1925
_____________________________________________________________________________________________________
1984                                     Geroge Orwell       poli-fiction             1949
_____________________________________________________________________________________________________
Lord of the flies                        William Golding     fiction                  1954
_____________________________________________________________________________________________________
Replay                                   Ken Grimwood        fantasy                  1986
_____________________________________________________________________________________________________
Friday Night Lights                      H.G.Bissinger       nonfiction               1990
_____________________________________________________________________________________________________
Oh the Places We'll Go                   Dr. Suess           children's picture book  1990
_____________________________________________________________________________________________________
Sophie's World                           Jostein Gaarder     philosophical fiction    1991
_____________________________________________________________________________________________________
Out of Control                           Kevin Kelly         computer science         1994
_____________________________________________________________________________________________________
Harry Potter : Sorcerer's Stone          JK Rowling          fiction                  1997
_____________________________________________________________________________________________________
The Perks of Being a Wallflower          Stephen Chbosky     fiction                  1999
_____________________________________________________________________________________________________
Harry Potter and the Goblet of Fire      JK Rowling          fantasy                  2000
_____________________________________________________________________________________________________
Bleach                                   Tite Kubo           supernatural             2001
_____________________________________________________________________________________________________
The Book Thief                           Markus Zusak        historical fiction       2005
_____________________________________________________________________________________________________
The Girl with the Dragon Tatoo           Stieg Larsson       crime                    2005
_____________________________________________________________________________________________________
The Three-Body Problem                   Liu Cixin           science fiction          2006
_____________________________________________________________________________________________________
I Thought It Was Just me                 Brene Brown         self help                2007
_____________________________________________________________________________________________________
Harry Potter and the Half Blood Prince   JK Rowling          fiction                  2009
_____________________________________________________________________________________________________
Another                                  Yukito Ayatsuju     horror                   2009
_____________________________________________________________________________________________________
Fall of Giants                           Ken Follett         historical fiction       2010
_____________________________________________________________________________________________________
Divergent                                Veronica Roth       dystopian fiction        2011
_____________________________________________________________________________________________________
The Book of Unknown Americans            Cristina Henriquez  fiction                  2014
_____________________________________________________________________________________________________

Would you like to sort again?
Type any key to sort again, enter '#' to quit.#

Thank you for using this program

Process returned 0 (0x0)   execution time : 12.584 s
Press any key to continue.


-------------------------------------------------------------------------------------------------------*/
