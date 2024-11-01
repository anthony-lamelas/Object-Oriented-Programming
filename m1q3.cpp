#include <iostream>
using namespace std;

class Thing {
public:
    Thing(double x = 0) : x(x) {}
    void display() const{
        cout << x;
    }
private:
    double x;
};

int main() {
    const Thing* th = new Thing;
    th->display();
    delete th;
    return 0;
}
