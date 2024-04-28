#include <iostream>
#include "pieces.h"

using namespace std;

int main()
{
Knight knight;
Pawn pawn;
Rook rook;
King king;

int newX, newY;
char response;
bool working = true;

while(working) {
    //welcome message with quit option
    cout << "Welcome to my Chess Game!" << endl;

    //prompt user to move knight
    cout << "Current Knight Pos: (" << knight.getX() << "," << knight.getY() << ")" << endl;
    cout << "Move Knight:  " << endl;
    cin >> newX >> newY;
    cin.ignore();

    if(knight.withinBounds(newX, newY) && knight.isCollision(newX, newY, pawn, knight, rook, king) && knight.Move(newX, newY))
    {
        cout << "Knight Move: " << endl;
        cout << "(" << knight.getX() << "," << knight.getY() << ")" << endl;
    }
        //prompt user to move rook
        cout << "Current Rook Pos: (" << rook.getX() << "," << rook.getY() << ")" << endl;
        cout << "Move Rook:  " << endl;
        cin >> newX >> newY;
        cin.ignore();

        if(rook.withinBounds(newX, newY) && rook.isCollision(newX, newY, pawn, knight, rook, king) && rook.Move(newX, newY))
        {
            cout << "Rook Move: " << endl;
            cout << "(" << rook.getX() << "," << rook.getY() << ")" << endl;
        }

        //prompt user to move pawn
        cout << "Current Pawn Pos: (" << pawn.getX() << "," << pawn.getY() << ")" << endl;
        cout << "Move Pawn:  " << endl;
        cin >> newX >> newY;
        cin.ignore();

        if((pawn.withinBounds(newX, newY)) && pawn.isCollision(newX, newY, pawn, knight, rook, king) && (pawn.Move(newX, newY)))
        {
            cout << "Pawn Move: " << endl;
            cout << "(" << pawn.getX() << "," << pawn.getY() << ")" << endl;
        }

        //prompt user to move king
        cout << "Current King Pos: (" << king.getX() << "," << king.getY() << ")" << endl;
        cout << "Move King:  " << endl;
        cin >> newX >> newY;
        cin.ignore();

        if((king.withinBounds(newX, newY)) && king.isCollision(newX, newY, pawn, knight, rook, king) && (king.Move(newX, newY)))
        {
            cout << "King Move: " << endl;
            cout << "(" << king.getX() << "," << king.getY() << ")" << endl;
        }

        //quit prompt
        cout << "Would you like to continue playing? (y/n)" << endl;
        cin >> response;
        if(response=='n')
            working = false;

    }

    cout << "Thank you for playing!" << endl;

    //end game
    return 0;
}