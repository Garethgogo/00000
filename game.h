#ifndef GAME_H_
#define GAME_H_
#include <iostream>
#include<windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;
class Board
{
private:
    static const int size=100;
    int posx;
    int posy;
    int homex;
    int homey;
    bool bombs[size][size];
public:
    Board();//construct
    ~Board();//destructor
    void print() const;//method
    void moveRight();
    void moveLeft();
    void moveUpp();
    void moveDown();
    static void setCursor(int x,int y);
    int getx(){return posx;}
    int gety(){return posy;}
    bool isAtHome() const;
    bool isBombHere() const;
};

Board::Board()
{
    posx = posy = (size/2)-1;
    homex = homey = size -2;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {

          bombs[i][j]=!(rand()%50);
        }
    }
    //cout << "The board is created!\n";
}
Board::~Board()
{

    //cout << "The board is deleted!\n";
}
 void Board::print() const
 {

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==0||j==0||i==size-1||j==size-1)
            {
                cout<<(char)219;
            }
            else if(i==posx && j ==posy)
            {
                cout<<(char)1;
            }
            else if(i==homex&&j==homey)
            {
                cout<<char(200);
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
 }
 void Board::moveRight()
 {
     if(posy<size-2)
     posy++;
     else
     posy=1;


 }
 void Board::moveLeft()
 {
     if(posy>1)
     posy--;
     else
        posy=size-2;

 }
 void Board::moveUpp()
 {
     if(posx>1)
     posx--;
     else
        posx=size-2;

 }
 void Board::moveDown()
 {
     if(posx<size-2)
     posx++;
     else
        posx=1;

 }
 void Board::setCursor(int x ,int y)
 {

     COORD c;
     c.X= x;
     c.Y =y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


 bool Board::isAtHome() const
 {
     return posx == homex && posy == homey;
 }

 bool Board::isBombHere() const
 {

     return bombs[posx][posy];
 }
#endif // GAME_H_
