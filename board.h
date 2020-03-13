#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class board{

  public:
    //initialize variables
    char** myBoard;
    char** twoBoard;
    char** threeBoard;
    char** makeboard(int checker);
    board();
    ~board();
    int width = 0;
    int height = 0;
    string heightToI = "";
    string widthToI = "";
    string freqToI = "";

    float frequency = 0;
    float totalspots = 0;
    int totalInt = 0;
    float life = 0;
    float genProb = 0.0;
    int genspots(int a, float c);
    string userBoard = "";
    string nospace = "";
    string tempString = "";
    stringstream streamer;
    string row = "";
    ifstream ifs;
    string all = "";
    void printboard();
    int getWidth();
    int getHeight();
    int linecounter = 0;

    char** getBoard();

  private:
    string filename = "";


  };
