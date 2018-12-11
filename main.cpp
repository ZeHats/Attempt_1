 	/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 1st, 2018, 11:27 AM
 * Purpose:  Randomly choose from a file
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>      //for srand and rand
#include <ctime>        //For time
#include <cstring>
#include <fstream>
using namespace std;

//Function Prototypes Here
string Card();
string Card(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the random number function
    srand(static_cast<unsigned int>(time(0)));
    //cards
    string card1,card2;
    int nHands=100;
    //Choose Cards
    for(int hand=1;hand<=nHands;hand++){
        card1=Card(rand()%52+1);
        do{
            card2=Card(rand()%52+1);
        }while(card1==card2);
    }
    //Output the 5 unique cards
    cout<<card1<<" "<<card2<<" "<<endl;
//Exit
    return 0;
}

string Card(){
    //Declare variables
    fstream in;
    string card;
    int nLines;
    //Initialize variables
    in.open ("CARDS.dat");
    nLines=rand()%52+1;//Possible 52 cards in the file
    //Look through file to find the random color
    for(int line;line<=nLines;line++){
        in>>card;
    }
    //Close file
    in.close();
    //Return the random color
    return card;
}

