//
// Created by Charlie Lakis on 1/20/24.
//
#include <iostream>
#include <cmath>
#include "pieces.h"
using namespace std;

//default constructor declaration
int ChessPeice::getX() const {
    return x;
}
int ChessPeice::getY() const {
    return y;
}

bool ChessPeice::withinBounds(int newX, int newY) {
    //checks 10x10 cartesian board boundaries
    if(newX<0 || newX>10 || newY<0 || newY>=10)
    {
        cout << "Invalid Move..." << endl;
        return false;
    }
    return(true);
}

bool ChessPeice::isCollision(int newX, int newY, const Pawn &p, const Knight &n, const Rook &r, const King &k) {
    if((p.getX()==newX) && (p.getY()==newY) || (r.getX()==newX) && (r.getY()==newY) || (k.getX()==newX) && (k.getY()==newY) || (n.getX()==newX) || (n.getY()==newY))
    {
        cout << "Invalid Move..." << endl;
        return false;
    }
    return(true);
}

Knight::Knight()
{
    x = 3;
    y = 0;
}

bool Knight::Move(int newX, int newY)
{
    //move validator for knight
    if((abs(newX-x) == 2 && abs(newY-y) == 1))
    {
        x = newX;
        y = newY;
        return true;
    }
    else
    {
        cout << "Invalid Knight Move..." << endl;
        return false;
    }
}

//default constructor declaration
Pawn::Pawn()
{
    x = 4;
    y = 0;
}

bool Pawn::Move(int newX, int newY)
{
    //starting move allows 2 spaces up
    if (x==4 && y==0)
    {
        if((newX==4) && ((newY-y) == 2 || (newY-y) == 1))
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid Pawn Move..." << endl;
            return false;
        }
    }
    else if(x==4 && y!=0)
    {
        if((newX==4) && (newY-y) == 1)
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid Pawn Move..." << endl;
            return false;
        }
    }
}

//default constructor declaration
Rook::Rook()
{
    x = 5;
    y = 0;
}

bool Rook::Move(int newX, int newY)
{
    if(newX==x && newY==y)
    {
        cout << "Invalid Rook Move..." << endl;
        return false;
    }
    //for x movement
    else if(abs(newX-x)<=9 && abs(newX-x)>=0 && newY==y)
    {
        x = newX;
        return true;
    }
    //for y movement
    else if(abs(newY-y)<=9 && abs(newY-y)>=0 && newX==x)
    {
        y = newY;
        return true;
    }
    else
    {

        cout << "Invalid Rook Move..." << endl;
        return false;
    }
}

//default constructor declaration
King::King()
{
    x = 6;
    y = 0;
}

bool King::Move(int newX, int newY)
{
    //wont move peice to same square
    if(newX==x && newY==y)
    {
        cout << "Invalid King Move..." << endl;
        return false;
    }
    //strictly x movement
    else if((newX!=x) && newY==y)
    {
        if(abs(newX-x)==1)
        {
            x = newX;
            return true;
        }
        else
        {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }
    //strictly y movement
    else if((newX==x) && (newY!=y))
    {
        if(abs(newY-y)==1)
        {
            y = newY;
            return true;
        }
        else {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }

    //diagonal movement
    else if((newX!=x) && (newY!=y))
    {
        if((abs(newX-x)==1) && (abs(newY-y)==1))
        {
            x = newX;
            y = newY;
            return true;
        }
        else
        {
            cout << "Invalid King Move..." << endl;
            return false;
        }
    }
}


