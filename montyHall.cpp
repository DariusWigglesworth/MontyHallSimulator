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
    doors[carDoor] = true;
    
    int chosenDoor = rand() % 3;

    int hostDoor = rand() % 3;
    while(hostDoor == chosenDoor){
        hostDoor = rand() % 3;
    }
    if((hostDoor == 0 and chosenDoor == 1) or (hostDoor == 1 and chosenDoor == 0)){
        chosenDoor = 2;
    }
    else if((hostDoor == 0 and chosenDoor == 2) or (hostDoor == 2 and chosenDoor == 0)){
        chosenDoor = 1;
    }
    else{
        chosenDoor = 0;
    }

    if(chosenDoor == carDoor){
        return 1;
    }
    else{
        return 0;
    }
}

int main (int argc, char** argv){

    srand(time(NULL));
    int correctDoor = 0;
    
    if(argc != 2){
        cout << "Please run the program with how many times it should simulate" << endl;
        return -1;
    }

    int iterations = atoi(argv[1]);
    
    for(int i = 0; i < iterations; i++){
        if(simulation()){
            correctDoor++;
        }
    }
    cout << "The correct door was picked " << 100.0 * correctDoor/iterations << "% of the time" << endl;
    return 0;
}