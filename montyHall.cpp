#include <iostream>

using namespace std;

int simulation(){

}

int main (int argc, char** argv){
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