#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file;
    file.open("text.txt");
    cout << "Hello, world!" << endl; 
    return 0;
}
