#include "Donut.h"
//constructor
donut :: donut(board *b){
  cBoard = new char* [b->height];
  for (int i = 0; i < b->height; ++i){
    cBoard[i] = new char [bCol];
    for(int j =0; j<b->width; ++j){
      cBoard[i][j] = b->myBoard[i][j];
    }
  }
  //set variables
  dstring = b-> all;
  bRow = b->getHeight();
  bCol = b->getWidth();
  //initialize copy test board
  dBoard = new char* [bRow];
  for (int i = 0; i < bRow; ++i){
    dBoard[i] = new char [bCol];
    for(int j =0; j<bCol; ++j){
      dBoard[i][j] = b->twoBoard[i][j];
    }
  }
  //initialize oscillation test board
  bBoard = new char* [bRow];
  for (int i = 0; i < bRow; ++i){
    bBoard[i] = new char [bCol];
    for(int j =0; j<bCol; ++j){
      bBoard[i][j] = b->threeBoard[i][j];
    }
  }
//to lower
  for(int i = 0; i < bRow; ++i){
    for(int j = 0; j < bCol; ++j){
      if(cBoard[i][j] == 'X'){
        cBoard[i][j] = 'x';

      }
    }
  }
  runGame();


}
donut :: ~donut(){
  delete cBoard;
  delete bBoard;
  delete dBoard;
}
//print in grid format method
void donut :: printg(){
  for (int i = 0; i < bRow; ++i){
    for(int j =0; j< bCol; ++j){
      cout << cBoard[i][j];
      if(j == (bCol -1)){
        cout << endl;
      }
    }
  }
}
//checks if char is on the side or corner
void donut :: checkSide(){

  cout<< endl;

  for (int i = 0; i < bRow; ++i){
    for(int j =0; j< bCol; ++j){

      if(i == 0){
        side = "top";
        if(j == 0){
          corner = "top left";
          checkNeighborTopLeft(i,j);
        }
        else if(j == bCol -1){
          corner = "top right";
          checkNeighborTopRight(i,j);
        }
        else {
          checkNeighborTop(i,j);
        }
      }
      else if(i == bRow - 1){
        side  = "bottom";
        if(j == 0){
          corner = "bottom left";
          checkNeighborBottomLeft(i,j);
        }
        else if(j == bCol -1){
          corner = "bottom right";
          checkNeighborBottomRight(i,j);
        }
        else{
          checkNeighborBottom(i, j);
        }
      }
      else if(j == 0){
        side = "left";
        checkNeighborLeft(i,j);
      }
      else if(j == bCol - 1){
        side = "right";
        checkNeighborRight(i,j);
      }
      else{
        side = "middle";
        checkNeighborMid(i,j);
      }
    }
  }
}
//neighbor counter for chars in middle
void donut :: checkNeighborMid(int t, int s){

  neighborCount = 0;
  if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }
  tempkill(neighborCount, t, s);


}

//neighbor counter for chars on left side
void donut :: checkNeighborLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][bCol-1] == 'x' || cBoard[t][bCol-1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t-1][bCol-1] == 'x' || cBoard[t-1][bCol-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][bCol-1] == 'x' || cBoard[t+1][bCol-1] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for chars on right side
void donut :: checkNeighborRight(int t, int s){
  neighborCount = 0;
    if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
      neighborCount +=1;
    }

    if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
      neighborCount +=1;
    }

    if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t][0] == 'x' || cBoard[t][0] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t-1][0] == 'x' || cBoard[t-1][0] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t+1][0] == 'x' || cBoard[t+1][0] == 'o'){
      neighborCount +=1;
    }

    tempkill(neighborCount, t, s);
}
//neighbor counter for chars on the bottom
void donut :: checkNeighborBottom(int t, int s){
  neighborCount = 0;
  if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[0][s] == 'x' || cBoard[0][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[0][s-1] == 'x' || cBoard[0][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[0][s+1] == 'x' || cBoard[0][s+1] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//neighbor counter for chars on top
void donut :: checkNeighborTop(int t, int s){
  neighborCount = 0;
  if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[bRow-1][s+1] == 'x' || cBoard[bRow-1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[bRow-1][s] == 'x' || cBoard[bRow-1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[bRow-1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
// neighbor counter for char on top right corner
void donut :: checkNeighborTopRight(int t, int s){
  neighborCount = 0;
  if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow-1][0] == 'x' || cBoard[bRow-1][0] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow-1][bCol -1] == 'x' || cBoard[bRow-1][bCol -1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t][0] == 'x' || cBoard[t][0] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t+1][0] == 'x' || cBoard[t+1][0] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow-1][s-1] == 'x' || cBoard[bRow-1][s-1]  == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);

}
// neighbor counter for top left corner
void donut :: checkNeighborTopLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow-1][s] == 'x' || cBoard[bRow-1][s] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t][bCol -1] == 'x' || cBoard[t][bCol -1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow - 1][bCol - 1] == 'x' || cBoard[bRow -1][bCol - 1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t+1][bCol - 1] == 'x' || cBoard[t+1][bCol - 1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[bRow-1][s+1] == 'x' || cBoard[bRow-1][s+1]  == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//neighbor checker for bottom left
void donut :: checkNeighborBottomLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][s] == 'x' || cBoard[0][s] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][bCol -1] == 'x' || cBoard[0][bCol -1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t][bCol -1] == 'x' || cBoard[t][bCol -1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t-1][bCol -1] == 'x' || cBoard[t-1][bCol -1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][s+1] == 'x' || cBoard[0][s+1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t-1][bCol-1] == 'x' || cBoard[t-1][bCol-1]  == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//neighbor counter for bottom right corner
void donut :: checkNeighborBottomRight(int t, int s){
  neighborCount = 0;
  if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
    neighborCount +=1;

  }
  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][s] == 'x' || cBoard[0][s] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][0] == 'x' || cBoard[0][0] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t][0] == 'x' || cBoard[t][0] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[0][s-1] == 'x' || cBoard[0][s-1] == 'o'){
    neighborCount +=1;
  }
  if(cBoard[t-1][0] == 'x' || cBoard[t-1][0]  == 'o'){
    neighborCount +=1;
  }


  tempkill(neighborCount, t, s);
}
//notes which cells are to die before next generation
void donut :: tempkill(int n, int a, int b){
  if(n == 3){
    if(cBoard[a][b] == '-'){
      cBoard[a][b] = 't';
    }
  }
  if(n <= 1){
    if(cBoard[a][b] == 'x'){
      cBoard[a][b] = 'o';
  }
  }
  if(n >= 4){
    if(cBoard[a][b] == 'x'){
      cBoard[a][b] = 'o';
    }
  }
}
//kills cell or bring cell back
void donut :: kill(){
  for (int i = 0; i < bRow; ++i){
    for(int j = 0; j < bCol; ++j){
      if(cBoard[i][j] == 't'){
        cBoard[i][j] = 'x';
      }
      else if(cBoard[i][j] == 'o'){
        cBoard[i][j] = '-';
      }
    }
  }

}
//counts vaariables which could cause game to end
bool donut :: checkOver(){
  ++loopcount;
  ++duplicateCount;
  for(int i = 0; i < bRow; ++i){
    for(int j = 0; j < bCol; ++j){
      if(cBoard[i][j] != dBoard[i][j]){

        duplicateCount = 0;
      }
}
}
  osCount ++;
  for(int i = 0; i < bRow; ++i){
    for(int j = 0; j < bCol; ++j){

      if(cBoard[i][j] != bBoard[i][j]){

        osCount = 0;
      }

}
}

}
//runs game
void donut :: runGame(){
  //prompt for user input before calling methods
  cout << "Do you want to (1) pause between generations" << endl;
  cout <<  "(2) press enter between generations" << endl;
  cout << "or (3) output the results to a file" << endl;
  cin >> pick;
  cout << "What you like to set at the max amount of generations?: " << endl;
  cin >> loopnum;
  loopMax = stoi(loopnum);
  if(pick == "3"){
    cout << "What is the name of the file?: " << endl;
    cin >> nameofFile;
    ofs.open(nameofFile);
    ofs.close();
    ofs.open(nameofFile, std::ios_base::app);
  }
//loops while the loop counter is less than the max loops set by user
  while (loopnumber < loopMax){
    cout <<  "Gen: " << loopnumber + 1 << endl;
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        bBoard[i][j] = dBoard[i][j];
      }
    }
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        dBoard[i][j] = cBoard[i][j];
      }
    }
    if(pick == "1"){
      //cplusplus.com
      std :: this_thread :: sleep_for(std :: chrono :: milliseconds(400));
      //calls methods
      printg();
      checkSide();

      kill();
      checkOver();
    }
    else if(pick == "2"){

      cout << "Press enter to continue: " << endl;
      cin.get();
      /*if(pressEnter == "end" ){
          exit(0);
        }
      }*/
      //calling methods
      printg();
      checkSide();

      kill();
      checkOver();
    }
//outputs to file
    else if(pick == "3"){
      ofs << endl;
      ofs << "Gen: " << loopnumber + 1  << endl;
      for (int i = 0; i < bRow; ++i){

        for(int j =0; j< bCol; ++j){
           ofs << cBoard[i][j];
          if(j == (bCol -1)){
            ofs << endl;
          }
        }
      }
      //calls methods
      checkSide();

      kill();
      checkOver();
    }
    else{
      cout << "invalid input. Exiting game. " << endl;
      exit(0);
    }
    //counts x's on board
    xCount = 0;
    for(int i = 0; i < bRow ; ++i){
      for(int j = 0; j < bCol; ++j){
        if(cBoard[i][j] == 'x'){
          ++xCount;

        }
      }
    }

//game ending checkers
    if(xCount < 1){
      cout << " No Life remaining. " << endl;
      if(ofs.is_open()){
        ofs << "No remaining cells. Ending game. " << endl;
      }
      exit(0);
    }
    if(osCount >= 10){
      cout << "5 straight oscillations, ending game. " << endl;
      if(ofs.is_open()){
        ofs << "5 straight oscillations. Ending game. " << endl;
      }
      exit(0);
    }
    if(duplicateCount >= 5){
      cout << "5 straight duplicate boards, ending game.  " << endl;
      if(ofs.is_open()){
        ofs << "10 straight duplicate boards. Ending game. " << endl;
      }
      exit(0);
    }
    //iterate loop counter
    loopnumber++;
  }
  ofs.close();

}
