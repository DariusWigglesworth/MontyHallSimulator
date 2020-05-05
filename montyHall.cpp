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

    
    //for(int i = 0; i < 3; i++){
    //    cout << "Door is " << doors[i] << endl;
    //}

    int chosenDoor = rand() % 3;
    //cout << "Chose door is " << chosenDoor << endl;

    int hostDoor = -1;
    if((chosenDoor == 0 and carDoor == 1) or (chosenDoor == 1 and carDoor == 0)){
        hostDoor = 2;
    }

    else if((chosenDoor == 0 and carDoor == 2) or (chosenDoor == 2 and carDoor == 0)){
        hostDoor = 1;
    }

    else{
        hostDoor = 0;
    }

    //cout << "Host door is " << hostDoor << endl;

    if((hostDoor == 0 and chosenDoor == 1) or (hostDoor == 1 and chosenDoor == 0)){
        chosenDoor = 2;
    }
    else if((hostDoor == 0 and chosenDoor == 2) or (hostDoor == 2 and chosenDoor == 0)){
        chosenDoor = 1;
    }
    else{
        chosenDoor = 0;
    }
    
    //cout << "Chosen Door changed to " << chosenDoor << endl;
    
    if(chosenDoor == carDoor){
        //cout << "correct door was chosen\n\n" << endl;
        return 1;
    }
    else{
        //cout << "correct door was NOT chosen\n\n" << endl;
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