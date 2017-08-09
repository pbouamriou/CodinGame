#include <iostream>
#include <sstream>
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
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);

    istringstream iss(temps);
    int goodTemp = 0;
    for( int i=0; i < n; ++i) {
        int temp;
        iss >> temp;
        cerr << "Temp: " << temp << endl;
        if( i == 0 ) goodTemp = temp;
        else {
            if( abs(temp) < abs(goodTemp) ) goodTemp = temp;
            else if(abs(temp) == abs(goodTemp) && goodTemp < 0) goodTemp = temp;
        }
    }

    cout << goodTemp << endl;
}
