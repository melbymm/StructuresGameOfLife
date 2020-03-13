#include "board.h"
  board :: ~board(){

    delete myBoard;
  }
 char** board :: makeboard(int checker){

   if(checker == 1){
     //makws board based off of user dimensions
     cout << "What height do you want?: " << endl;
     cin >> heightToI;
     cout << "What length do you want?: " << endl;
     cin >> widthToI;
     height = stoi(heightToI);
     width = stoi(widthToI);
     cout << "What frequency of life would you like?: " << endl;
     cin >> freqToI;
     frequency = stof(freqToI);


  //initialize board
     myBoard = new char* [height];
     for (int i = 0; i < height; ++i){
       myBoard[i] = new char [width];
       for(int j =0; j<width; ++j){
         myBoard[i][j]='-';
       }
     }
     //initialize board to test for duplicates
     twoBoard = new char* [height];
     for (int i = 0; i < height; ++i){
       twoBoard[i] = new char [width];
       for(int j =0; j<width; ++j){
         twoBoard[i][j]='-';
       }
     }
     //initialize board to test for oscillations
     threeBoard = new char* [height];
     for (int i = 0; i < height; ++i){
       threeBoard[i] = new char [width];
       for(int j =0; j<width; ++j){
         threeBoard[i][j]='-';
       }
     }
     totalspots = width * height;

     life = totalspots * frequency;
     totalInt = life;
     for (int i = 0; i < height; ++i){
       for(int j =0; j<width; ++j){
         float genProb = (float) rand()/(RAND_MAX);
//inputs x or - to board based on ramdon genertaion
         if(frequency >= genProb)
          myBoard[i][j]='x';
       }
     }
   }
   else if (checker == 2){
//prompts user to enter a file name, which will contain a board
   cout << "Enter file name: " << endl;
   cin >> filename;
   ifs.open(filename);
//open file
    if(ifs.is_open()){
      cout << "Open! " << endl;
}

    while(!ifs.eof()){
      ifs >> userBoard;
      all = all + userBoard;

//set height and width


}

    heightToI = all.at(0);
    widthToI = all.at(1);

    height = stoi(heightToI);
    width = stoi(widthToI);
    linecounter++;

    myBoard = new char* [height];
    for (int i = 0; i < height; ++i){
      myBoard[i] = new char [width];
      for(int j =0; j<width; ++j){
        myBoard[i][j]='-';
      }
    }
//set array equal to board from file
    for (int i = 0; i < height; ++i){
      for(int j =0; j<width; ++j){
          myBoard[i][j] = all.at((i*width)+j + heightToI.length() + widthToI.length());
        }

      }

  ifs.close();
//initialize board

      //initialize copy tester
      twoBoard = new char* [height];
      for (int i = 0; i < height; ++i){
        twoBoard[i] = new char [width];
        for(int j =0; j<width; ++j){
          twoBoard[i][j]='-';

        }

      }
      //initialize oscillation tester
      threeBoard = new char* [height];
      for (int i = 0; i < height; ++i){
        threeBoard[i] = new char [width];
        for(int j =0; j<width; ++j){
          threeBoard[i][j]='-';

        }
      }
   }
   else{
     cout << "Exiting program, invalid." << endl;
     exit(0);
   }
   return myBoard;
   for (int i = 0; i < height; ++i){
  //set copy tester equal to board
     for(int j =0; j<width; ++j){
       twoBoard[i][j]=myBoard[i][j];

     }

   }
   //set oscillation tester equal to board
   for (int i = 0; i < height; ++i){
     for(int j =0; j<width; ++j){
       threeBoard[i][j]=myBoard[i][j];

     }

   }

 }
 /*void board :: printboard(){
   for (int i = 0; i < height; ++i){

     for(int j =0; j< width; ++j){//need second loop
       cout << myBoard[i][j];
       if(j == (width -1)){
         cout << endl;
       }

     }

   }
 }*/
 board :: board(){

 }
 char** board :: getBoard(){
   return myBoard;
 }
 int board :: getHeight(){
   return height;
 }
 int board :: getWidth(){
   return width;
 }
