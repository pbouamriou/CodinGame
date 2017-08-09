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
    string MESSAGE;
    getline(cin, MESSAGE);

    char* tableEncode[2][2] = {{ " 00 0", " 0 0" }, { "00 0", "0 0" }};

    auto getBit = [](char character, int index) {
        return (character >> index) & 0x01;
    };

    auto encodeNewBit = [&tableEncode](int first, int bit) {
        return tableEncode[first][bit];
    };

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int previous = 0xFF; // force different
    for( auto character : MESSAGE) {
        for(int i = 6; i >= 0; --i) {
            int bit = getBit(character, i);
            cout << (previous != bit ? encodeNewBit(previous == 0xFF, bit) : "0");
            previous = bit;
        }
    }
    cout << endl;
}
