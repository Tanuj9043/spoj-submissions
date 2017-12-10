#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    int i, N, hom, het, v;
    map< int, int > mymap;
    char s[ 100000 ];
    char ins[ 15 ] = "insert", del[ 15 ] = "delete";
    cin >> N;
    hom = het = 0;
    for ( i = 0; i < N; ++i ) {
        cin >> s >> v;

        if ( strcmp( s, ins ) == 0 )
        {
            mymap[ v ] += 1;

            if ( mymap[ v ] == 2 ) hom++;
            else if ( mymap[ v ] == 1 ) het++;
        }
        else
        {
            if ( mymap[ v ] > 0 )
            {
                mymap[ v ] -= 1;

                if ( mymap[ v ] == 1 ) hom--;
                else if ( mymap[ v ] == 0 ) het--;
            }
        }

        if ( hom >= 1 && het >= 2 ) cout << "both\n";
        else if ( hom >= 1 ) cout << "homo\n";
        else if ( het >= 2 ) cout << "hetero\n";
        else cout << "neither\n";
    }
    return 0;
}

