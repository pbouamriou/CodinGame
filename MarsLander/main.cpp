#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class SurfaceMngr {
public:
    class Surface {
    public:
        int x;
        int y;
    };

    SurfaceMngr(int nbSurfaces) : _nbSurfaces(nbSurfaces) {
        _surfaces = new Surface[_nbSurfaces];
    }

    virtual ~SurfaceMngr() {
        delete[] _surfaces;
    }

    Surface& operator[](int index) {
        return _surfaces[index];
    }

    int groundAltitude(int x) {
        if(!_nbSurfaces) return -1;
        Surface& previousSurface = _surfaces[0];
        for(int index = 1; index < _nbSurfaces; ++index) {
            if(x >= previousSurface.x && x<= _surfaces[index].x ) {
                int y1 = previousSurface.y;
                int y2 = _surfaces[index].y;
                int x1 = previousSurface.x;
                int x2 = _surfaces[index].x;
                return y1+((y2-y1)/(x2-x1));
            }
            previousSurface = _surfaces[index];
        }
    }

private:
  int _nbSurfaces;
  Surface* _surfaces;
};

int main()
{
    const int maxVSpeed(40);
    const int altitudePonderation(100);
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    SurfaceMngr surfaceMngr(surfaceN);
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();
        surfaceMngr[i].x = landX;
        surfaceMngr[i].y = landY;
    }

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();

        int groundAltitude = surfaceMngr.groundAltitude(X);
        cerr << "Ground alt : " << groundAltitude << endl;

        int deltaAlt = Y - groundAltitude;
        int deltaVSpeedPonderateWithAlt = (maxVSpeed + vSpeed) * (deltaAlt / altitudePonderation);
        int newPower = 4 - min(4, max(deltaVSpeedPonderateWithAlt, 0));


        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        cout << "0 "<< newPower << endl;
    }
}
