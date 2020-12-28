#include <stdio.h>
#include "chess.h"

int main()
{
    int whiteFlag=1;
    struct Piece board[8][8];
    char player;
    char destination[3];
    char source[3];
    
    for(int i=0;i<8;i++)
    {
        board[1][i]=createPiece(PAWN,WHITE,"WPW");
        board[6][i]=createPiece(PAWN,BLACK,"BPW");
        
    }

    for(int i=2;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j]=createPiece(NONE,VOID,"   ");
        }
    }
    board[0][0]=createPiece(ROOK,WHITE,"WRK");
    board[0][7]=createPiece(ROOK,WHITE,"WRK");
    board[0][1]=createPiece(KNIGHT,WHITE,"WKN");
    board[0][6]=createPiece(KNIGHT,WHITE,"WKN");
    board[0][2]=createPiece(BISHOP,WHITE,"WBI");
    board[0][5]=createPiece(BISHOP,WHITE,"WBI");
    board[0][3]=createPiece(QUEEN,WHITE,"WQU");
    board[0][4]=createPiece(KING,WHITE,"WKI");

    board[7][0]=createPiece(ROOK,BLACK,"BRK");
    board[7][7]=createPiece(ROOK,BLACK,"BRK");
    board[7][1]=createPiece(KNIGHT,BLACK,"BKN");
    board[7][6]=createPiece(KNIGHT,BLACK,"BKN");
    board[7][2]=createPiece(BISHOP,BLACK,"BBI");
    board[7][5]=createPiece(BISHOP,BLACK,"BBI");
    board[7][3]=createPiece(QUEEN,BLACK,"BQU");
    board[7][4]=createPiece(KING,BLACK,"BKI");

    displayBoard(board);
    printf("\nEnter your move\n");
        
    scanf("%c %s %s", &player, source, destination);
    printf( "\nYou entered: >>>%c<<<>>>%s<<<>>>%s<<<", player, source,destination);
    
    while(1)
    {
        
        
        move(board,player,source,destination,&whiteFlag);
        displayBoard(board);
        printf("\nEnter your move\n");
        scanf("%c");
        scanf("%c %s %s", &player, source, destination);
        printf( "\nYou entered: >>>%c<<<>>>%s<<<>>>%s<<<", player, source,destination);
    }
    

    

    
}