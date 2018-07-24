#include "game.h"
#include <conio.h>
#include <windows.h>
int main()
{
    Board b;
    b.print();
   char key;
   do
   {
       key = getch();
       Board::setCursor(b.gety(),b.getx());
       cout<< ' ';
       switch(key)
       {
        case 77:b.moveRight();break;
        case 75:b.moveLeft();break;
        case 72:b.moveUpp();break;
        case 80:b.moveDown();break;
       }

      Board::setCursor(b.gety(),b.getx());
       cout<< char(1);
       Board::setCursor(0,0);
       if(b.isAtHome())
       {
           cout << "You are at home :-)\n";
       }
       if(b.isBombHere())
       {
           Board::setCursor(b.gety(),b.getx());
           cout<<(char)2;
           Board::setCursor(1,1);
           cout<<"Sorry ,you are dead";
       };
   }

   while(key!=27 && !b.isAtHome()&& !b.isBombHere());
   return 0;
}
