#include <iostream>
#include "board.h"
#include <chrono>
#include <thread>
using namespace std;

class classic{
  public:
    int neighborCount = 0;
    int t = 0;
    int s = 0;
    ~classic();
    void kill();
    void tempkill(int n, int a, int b);
    void checkNeighborMid(int t,int s);
    void checkNeighborLeft(int t, int s);
    void checkNeighborRight(int t, int s);
    void checkNeighborTop(int t, int s);
    void checkNeighborBottom(int t, int s);
    void checkNeighborTopLeft(int t, int s);
    void checkNeighborTopRight(int t, int s);
    void checkNeighborBottomLeft(int t, int s);
    void checkNeighborBottomRight(int t, int s);
    void runGame();
    classic(board *b);
    string side = "";
    string corner = "";
    void checkSide();
    board getCBoard();
    board newestboard;
    void game();
    char** cBoard;
    char** dBoard;
    string** sBoard;
    board *board1 = new board();
    void printg();
    int bRow = 0;
    int bCol = 0;
    int n = 0;
    int a = 0;
    int b = 0;
    string thisString = "";
    int xCount = 0;
    int loopcount = 0;
    int duplicateCount = 0;
    bool checkOver();
    char** bBoard;
    void pause();
    string pick = "";
    int osCount = 0;
    string toString(char** array2d);
    string getString = "";
    string dstring = "";
    string bstring = "";
    string pressEnter ="";
    int counter = 0;
    ofstream ofs;
    string nameofFile = "";
    string loopnum = "";
    int loopnumber = 0;
    int loopMax = 0;





};
