/*
Jaxon Coward
jsc3536
4/30/2020
Wrote terrain generation code for defender game
*/

#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 640

int main(void) {
    int last = 3;
    int length = 0;
    int slope;
    for(int i = 0; i < SIZE; i++){
        if(length == 0) {
            length = (rand() % 5) + 5;
            slope = rand() % 10;
        }

        int el = last;

        if(slope >= 6 && el < 20){
            el = last + 1;
            last = el;
        }else if(el > 3){
            el = last - 1;
            last = el;
            slope = 0;
        }

        length--;

        //if(i != SIZE - 1)
            //cout << el <<", ";
        //else
            cout << el;
        //if(i % 20 == 0 && i != 0){
            cout << endl;
        //}
    }
}
