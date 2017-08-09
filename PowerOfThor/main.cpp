#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    struct { int x; int y ; void move(int dx, int dy) {x+=dx;y+=dy;}} currentPosition = { initialTX, initialTY };
    auto delta = [](int t1, int t2) { return (t1>t2) - (t1<t2) ;}; // T1 > T2 ==> 1 ; T2 > T1 ==> -1 ; T2 == T1 ==> 0
    char* xOrder[] = { "W", "", "E" };
    char* yOrder[] = { "N", "", "S" };

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        int dX = delta(lightX, currentPosition.x);
        int dY = delta(lightY, currentPosition.y);
        currentPosition.move(dX, dY);
        cout << yOrder[dY+1] << xOrder[dX+1] << endl;
    }
}
