//
// Created by Charlie Lakis on 1/20/24.
//

#ifndef P1_PIECES_H
#define P1_PIECES_H

class Knight;
class Pawn;
class Rook;
class King;

//abstract ChessPeice class
class ChessPeice {
public:
    int x, y;

    //pure virtual move function to implement inheritance
    virtual bool Move(int newX, int newY) = 0;

    virtual bool withinBounds(int newX, int newY);

    virtual bool isCollision(int newX, int newY, const Pawn& p, const Knight& n, const Rook& r, const King& k);

    virtual int getX() const;
    virtual int getY() const;

    virtual ~ChessPeice() = default;
};

class Knight : public ChessPeice {
public:
    //default constructor to set location at start
    Knight();
    //setter for location
    bool Move(int newX, int newY) override;
};

class Pawn : public ChessPeice {
public:
    //default constructor to set location at start
    Pawn();
    //setter for location
    bool Move(int newX, int newY) override;
};

class Rook : public ChessPeice {
public:
    //default constructor to set location at start
    Rook();
    //setter for location
    bool Move(int newX, int newY) override;
};

class King : public ChessPeice {
public:
    //default constructor to set location at start
    King();
    //setter for location
    bool Move(int newX, int newY) override;
};


#endif //P1_PIECES_H