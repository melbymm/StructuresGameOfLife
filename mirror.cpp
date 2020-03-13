#include "mirror.h"
//constructor
mirror :: mirror(board *b){
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
mirror :: ~mirror(){
  delete cBoard;
  delete bBoard;
  delete dBoard;
}
//print in grid format method
void mirror :: printg(){
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
void mirror :: checkSide(){

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
void mirror :: checkNeighborMid(int t, int s){

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
void mirror :: checkNeighborLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for chars on right side
void mirror :: checkNeighborRight(int t, int s){
  neighborCount = 0;
    if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
      neighborCount +=2;
    }
    if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
      neighborCount +=1;
    }

    if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
      neighborCount +=1;
    }

    if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
      neighborCount +=2;
    }
    if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
      neighborCount +=1;
    }
    if (cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
      neighborCount +=1;
    }

    tempkill(neighborCount, t, s);
}
//counts neighbors for chars on bottom side
void mirror :: checkNeighborBottom(int t, int s){
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
    neighborCount +=2;
  }
  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for top row
void mirror :: checkNeighborTop(int t, int s){
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
    neighborCount +=2;
  }
  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for top right corner
void mirror :: checkNeighborTopRight(int t, int s){
  neighborCount = 0;
  if (cBoard[t+1][s-1] == 'x' || cBoard[t+1][s-1] == 'o'){
    neighborCount +=1;
  }
  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=2;
  }

  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=2;
  }
  if(cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=3;
  }

  tempkill(neighborCount, t, s);

}
//counts neighbors for the top left corner
void mirror :: checkNeighborTopLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t+1][s] == 'x' || cBoard[t+1][s] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t+1][s+1] == 'x' || cBoard[t+1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=2;
  }
  if(cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=3;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for bottom left corner
void mirror :: checkNeighborBottomLeft(int t, int s){
  neighborCount = 0;

  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=2;
  }
  if (cBoard[t-1][s+1] == 'x' || cBoard[t-1][s+1] == 'o'){
    neighborCount +=1;
  }

  if (cBoard[t][s+1] == 'x' || cBoard[t][s+1] == 'o'){
    neighborCount +=2;
  }
  if(cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=3;
  }

  tempkill(neighborCount, t, s);
}
//counts neighbors for bottom right corner
void mirror :: checkNeighborBottomRight(int t, int s){
  neighborCount = 0;
  if (cBoard[t-1][s-1] == 'x' || cBoard[t-1][s-1] == 'o'){
    neighborCount +=1;

  }
  if (cBoard[t-1][s] == 'x' || cBoard[t-1][s] == 'o'){
    neighborCount +=2;
  }

  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=2;
  }
  if(cBoard[t][s] == 'x' || cBoard[t][s] == 'o'){
    neighborCount +=3;
  }
  if (cBoard[t][s-1] == 'x' || cBoard[t][s-1] == 'o'){
    neighborCount +=1;
  }

  tempkill(neighborCount, t, s);
}
//notes the chars that need to be killed
void mirror :: tempkill(int n, int a, int b){
  if(n == 3){
    if(cBoard[a][b] == '-'){
      cBoard[a][b] = 't';
    }
  }
  if(n <= 1){
    if(cBoard[a][b] == 'x'){
      cBoard[a][b] = 'o';

  }
    else if(cBoard[a][b] == '-'){
      cBoard[a][b] = '-';
    }
  }
  if(n >= 4){
    if(cBoard[a][b] == 'x'){
      cBoard[a][b] = 'o';
    }
  }

}
//kills/revives chars
void mirror :: kill(){
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
//counters that could be game ending
bool mirror :: checkOver(){
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
// runs the game
void mirror :: runGame(){
  cout << "Do you want to (1) pause between generations" << endl;
  cout <<  "(2) press enter between generations" << endl;
  cout << "or (3) output the results to a file" << endl;
  cin >> pick;
  cout << "What you like to set at the max amount of generations?: " << endl;
  cin >> loopnum;
  loopMax = stoi(loopnum);
  //clears file , then opens for appending
  if(pick == "3"){
    cout << "What is the name of the file?: " << endl;
    cin >> nameofFile;
    ofs.open(nameofFile);
    ofs.close();
    ofs.open(nameofFile, std::ios_base::app);
  }
//runs while loop counter is less than the user designated max set by user
  while (loopnumber < loopMax){
    cout <<  "Gen: " << loopnumber + 1 << endl;
//sets osscillation checker equal to duplicatte counter board
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        bBoard[i][j] = dBoard[i][j];
      }
    }
//sets duplicaate checker board equal to board
    for(int i = 0; i < bRow; ++i){
      for(int j = 0; j < bCol; ++j){
        dBoard[i][j] = cBoard[i][j];
      }
    }
//pause
    if(pick == "1"){
      //cplusplus.com
      std :: this_thread :: sleep_for(std :: chrono :: milliseconds(400));
      printg();
      checkSide();

      kill();
      checkOver();
    }

    //enter to continue
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
//output to file
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

    xCount = 0;
    //checks xcount
    for(int i = 0; i < bRow ; ++i){
      for(int j = 0; j < bCol; ++j){
        if(cBoard[i][j] == 'x'){
          ++xCount;
        }
      }
    }
    ++loopcount;
//potential game enders
    if(xCount == 0){
      if(ofs.is_open()){
        ofs << "No lives remaining" << endl;
        exit(0);
      }
      cout << "No lives remaining" << endl;
      exit(0);

    }
    if(osCount >= 10){
      if(ofs.is_open()){
        ofs << "5 straight oscillations, ending game. " << endl;
        exit(0);
    }
      else{
        cout << "5 straight oscillations, ending game. " << endl;
        exit(0);
      }
    }
    if(duplicateCount >= 5){
      if(ofs.is_open()){
        ofs << "5 straight duplicates, ending game. " << endl;
        exit(0);
    }
      else{
        cout << "5 straight duplicates, ending game. " << endl;
        exit(0);
      }
    }
    //iterate loop counter
    loopnumber++;
    }
    ofs.close();
  }
