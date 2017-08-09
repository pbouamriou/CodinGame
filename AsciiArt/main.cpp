#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    vector<string> ROWS(H);
    for (int i = 0; i < H; i++) {
        getline(cin, ROWS[i]);
    }

    cerr << "L = " << L << ", H = " << H << endl;
    cerr << "T = '" << T << "'" << endl;

    for (int i = 0; i < H; i++) {
        const string& str = ROWS[i];
        for( auto character : T) {
            int position = toupper(character) - 'A';
            if( position < 0 || position > 25) position = 26;
            cout << str.substr(position*L, L);
        }
        cout << endl;
    }
}
