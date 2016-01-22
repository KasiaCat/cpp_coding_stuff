#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <string.h>
#include <windows.h>

//#include <cdir> // plik naglokowy
//#include <dir.h>

using namespace std;

//kopiowanie zawartosci jednego pliku do drugiego

int main( int argc, char * args[] ) //argc - arguments counter //args - arguments strings
{
    //wyprowadzam informacje, ile jest parametrow programu
    //cout << endl << "Ile parametrow: " << argc;
    //cout << args[0];

   // for ( int i = 0; i < argc; i++ )
        //cout << endl << arg[i];


    FILE * fin; //plik wejsciowy
    FILE * fout; // plik wyjsciowy
    char inName [ MAX_PATH ];
    char outName [ MAX_PATH ];

    /*if ( --argc == 2 )
    {
        strcpy ( inName = args [1] );
        strcpy ( outName = args [2] );
    }*/

    cout << endl << "Podaj nazwe pliku wejsciowego: ";
    cin >> inName;

    cout << endl << "Podaj nazwe pliku wyjsciowego: ";
    cin >> outName;


    if (  ( fin = fopen( inName, "rb") ) != 0 )
    {

        if (  ( fout = fopen( outName, "wb") ) != 0 ) // przechodzimy na try binarny, by nie zachodzila
            //konwersja znakow licznikow konca linii  - czyli nie liczy enterow
        {
            int znak;
            unsigned long int licznik = 0;
            cout << endl << "Kopiowanie....";

            while ( ( znak  = fgetc( fin ) ) != EOF )
            {

                fputc( znak, fout );
                licznik++;
            }

            cout << endl << "Koniec kopiowania" << endl << "ilosc znakow: " << licznik << endl;
            fclose(fout);

        } else {
            cout << "Blad pliku wyjsciowego!";
        }

        fclose(fin);


    } else
        cout << "Plik nie istnieje!";

    cin.ignore();
    cin.get();
    return EXIT_SUCCESS;
}
