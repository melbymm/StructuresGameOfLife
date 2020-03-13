#include "classic.h"
//Constructor
classic :: classic(board *b){
  cBoard = new char* [b->height];
  for (int i = 0; i < b->height; ++i){
    cBoard[i] = new char [bCol];
    for(int j =0; j<b->width; ++j){
      cBoard[i][j] = b->myBoard[i][j];
    }
  }
//setting height
  bRow = b->getHeight();
  bCol = b->getWidth();
  //
  //initialize duplicate checking board
  dBoard = new char* [bRow];
  for (int i = 0; i < bRow; ++i){
    dBoard[i] = new char [bCol];
    for(int j =0; j<bCol; ++j){
      dBoard[i][j] = b->twoBoard[i][j];
    }
  }
  //initialize oscillation checker board
  bBoard = new char* [bRow];
  for (int i = 0; i < bRow; ++i){
    bBoard[i] = new char [bCol];
    for(int j =0; j<bCol; ++j){
      bBoard[i][j] = b->threeBoard[i][j];
    }
  }
//Account for uppercase input
  for(int i = 0; i < bRow; ++i){
    for(int j = 0; j < bCol; ++j){
      if(cBoard[i][j] == 'X'){
        cBoard[i][j] = 'x';
      }
    }
  }
  runGame();
}
classic :: ~classic(){
  delete cBoard;
  delete bBoard;
  delete dBoard;
}
//print grid method
void classic :: printg(){
  for (int i = 0; i < bRow; ++i){
    for(int j =0; j< bCol; ++j){
      cout << cBoard[i][j];
      if(j == (bCol -1)){
        cout << endl;
      }
    }
  }
}
//check if char is on the side or in the corner
void classic :: checkSide(){
  cout << endl;
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
//check neighbors count for middle characters
void classic :: checkNeighborMid(int t, int s){

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
//check neighbors for characters on the left
void classic :: checkNeighborLeft(int t, int s){
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
  tempkill(neighborCount, t, s);
}
//check neighbors for characters on the right
void classic :: checkNeighborRight(int t, int s){
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
    tempkill(neighborCount, t, s);
}
//check neighbors for characters on the bottom
void classic :: checkNeighborBottom(int t, int s){
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
  tempkill(neighborCount, t, s);
}
//check neighbors for characters on the top
void classic :: checkNeighborTop(int t, int s){
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
  tempkill(neighborCount, t, s);
}
//check neighbors for characters in top right corner
void classic :: checkNeighborTopRight(int t, int s){
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
  tempkill(neighborCount, t, s);

}
//check neighbors for characters in top left corner
void classic :: checkNeighborTopLeft(int t, int s){
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
  tempkill(neighborCount, t, s);
}
//check neighbors for characters in bottom left corner
void classic :: checkNeighborBottomLeft(int t, int s){
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
  tempkill(neighborCount, t, s);
}//check neighbors for characters in bottom right corner
void classic :: checkNeighborBottomRight(int t, int s){
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

  tempkill(neighborCount, t, s);
}
//notes which characters are killed
void classic :: tempkill(int n, int a, int b){

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
//permanently performs revival and killing of cells between generations
void classic :: kill(){

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
//checks if any game ending conditions are true
bool classic :: checkOver(){

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
//runs the game
void classic :: runGame(){
  cout << "Do you want to (1) pause between generations" << endl;
  cout <<  "(2) press enter between generations" << endl;
  cout << "or (3) output the results to a file" << endl;
  cin >> pick;
  cout << "What you like to set at the max amount of generations?: " << endl;
  cin >> loopnum;
  loopMax = stoi(loopnum);
//clears last input from file, opens for appending
  if(pick == "3"){
    cout << "What is the name of the file?: " << endl;
    cin >> nameofFile;
    ofs.open(nameofFile);
    ofs.close();
    ofs.open(nameofFile, std::ios_base::app);
  }
//loop while the game has looped less times than the user inputted max
  while (loopnumber < loopMax){
    cout <<  "Gen: " << loopnumber + 1 << endl;
//sets oscillation board equal to duplicate board
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        bBoard[i][j] = dBoard[i][j];
      }
    }
    //sets duplicate board equal to board
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        dBoard[i][j] = cBoard[i][j];
      }
    }
    //pause
    if(pick == "1"){
      //cplusplus.com
      std :: this_thread :: sleep_for(std :: chrono :: milliseconds(400));
      //calling methods
      printg();
      checkSide();

      kill();
      checkOver();
    }
    //user calls next round
    else if(pick == "2"){

      cout << "Press enter to continue: " << endl;
      cin.get();
      /*if(pressEnter == "end" ){
          exit(0);
        }
      }*/
      printg();
      checkSide();

      kill();
      checkOver();
    }
// outputting to user's file
    else if(pick == "3"){
      ofs << "Gen: " << loopnumber + 1 << endl;
      for (int i = 0; i < bRow; ++i){

        for(int j =0; j< bCol; ++j){

           ofs << cBoard[i][j];
          if(j == (bCol -1)){
            ofs << endl;
          }
        }
      }
      checkSide();

      kill();
      checkOver();
    }
    else{
      cout << "invalid input. Exiting game. " << endl;
      exit(0);
    }
//checks numberss generated from checkover method
    xCount = 0;
    for(int i = 0; i < bRow ; ++i){
      for(int j = 0; j < bCol; ++j){
        if(cBoard[i][j] == 'x' || cBoard[i][j] == 'X'){
          ++xCount;
        }
      }
    }

    ++loopcount;
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
    loopnumber++;
  }
  ofs.close();


}
