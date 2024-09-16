#include <iostream>
#include <string>
using namespace std;

class Rectange {
    void stename(const string& iname) { name = iname; }
    void setwidth(int iwidth) { width = iwidth; }
    void setheight(int iheight) { height = iheight;}

    private:
        string name;
        int width;
        int height;
};