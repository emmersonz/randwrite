#include <iostream>
#include <fstream>

using namespace std;

int main() {
  std::ifstream source ("harrypotter.txt", std::ifstream::binary);
  if(source){
    // get length of the file:
    source.seekg(0, source.end);
    int length = source.tellg();
    source.seekg (0, source.beg);
    cout << length << endl;
  } 
}
