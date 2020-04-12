#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
using namespace std;

int simulation(){
    bool doors[3];
    for(int i = 0; i < 3; i++){
        doors[i] = false;
    }
    int carDoor = rand() % 3;
    doors[cardDoor] = true;
    
    int chosenDoor = rand() % 3;

    int hostDoor = rand() % 3;
    while(hostDoor == chosenDoor){
        hostDoor = rand() % 3;
    }
}

int main (int argc, char** argv){

    srand(time(NULL));
    int correctDoor = 0;
    
    if(argc != 2){
        cout << "Please run the program with how many times it should simulate" << endl;
        return -1;
    }

    int iterations = atoi(argv[1])
    
    for(int i = 0; i < iterations; i++){
        if(simulation()){
            correctDoor++;
        }
    }
    cout << "The correct door was picked " << correctDoor/iterations << " times" << endl;
    return 0;
}