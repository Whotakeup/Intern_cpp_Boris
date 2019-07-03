#include <iostream>
#include "cache.h"
using namespace std;

int main() {
   string test;
    while (test != "exit"){
        cin >> test;
        cout << getElement(test) <<endl;
    }
}
