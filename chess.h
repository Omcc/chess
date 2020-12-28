#ifndef CHESS
#define CHESS

enum Type {
    NONE=0,
    PAWN=1,
    ROOK=2,
    BISHOP=3,
    KNIGHT=4,
    QUEEN=5,
    KING=6
};

enum Color {
   
    BLACK=0,
    WHITE=1,
    VOID=3
    
};

struct Piece {
    enum Type type;
    enum Color color;
    char* name;
};

struct Piece createPiece(enum Type type,enum Color color,char* name);
void displayBoard(struct Piece board[][8]);
void move(struct Piece board[][8],char c,char source[],char destination[],int* whiteFlag);

int* parseMove(char point[]);
void pawnMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
void rookMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
void bishopMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
void knightMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
void queenMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
void kingMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag);
int isSourceEmpty(struct Piece board[][8],int* source);


int* parseMove(char point[]);

#endif