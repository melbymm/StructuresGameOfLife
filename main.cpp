//#include "classic.h"
//#include "board.h"
#include "mirror.h"
int main(int argc, char **argv){
  string in = "";

  board *board2 = new board();
  board *board3 = new board();
  int check = 0;
//  int boardcheck;
  cout << "Would you like to (1) Use a random board, or (2) enter your own board?: " << endl;

  cin >> check;

  board2 -> makeboard(check);
//  board3 -> makeboard(check);
  cout << "Select Mode: " << endl;
  cout << "1: Classic" << endl;
  cout << "2: Donut" << endl;
  cout << "3: Mirror" << endl;
  cin >> in;
  if(in == "1"){
    classic *newClassic = new classic(board2);
    newClassic -> ~classic();
  }
  else if(in == "2"){
    donut *newdonut = new donut(board2);
    newdonut -> ~donut();
  }
  else if(in == "3"){
    mirror *newmirror = new mirror(board2);
    newmirror -> ~mirror();
  }
  board2 -> ~board();

  //newboard -> printboard();
  //classic *newClassic = new classic(board2);







}
