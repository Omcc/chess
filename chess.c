#include <stdio.h>
#include "chess.h"
#include <string.h>

struct Piece createPiece(enum Type type,enum Color color,char* name)
{
    struct Piece piece;
    piece.type=type;
    piece.color=color;
    piece.name=(char*)malloc(sizeof(char)*3);
    strcpy(piece.name,name);
    return piece;
}

void displayBoard(struct Piece board[][8])
{
    int ch=97;
    printf("\n");
    for(int i=7;i>=0;i--)
    {
        printf("%d",i+1);
        
        for(int j=0;j<8;j++)
        {
            printf("|");
            
            
            printf("%s",board[i][j].name);
            
        }
        if(i==0)
        continue;
        printf("\n");
        printf("---------------------------------");
        printf("|");
        printf("\n");
        
    }
    printf("|");
    printf("\n");
    for (int i=0;i<8;i++)
    {
        printf("---");
        printf("%c",ch);
        ch++;
    }

    printf("\n\n\n");
}

void move(struct Piece board[][8],char c,char source[],char destination[],int* whiteFlag){
    int* src  = parseMove(source);
    int* dest= parseMove(destination);
    int playerFlag;
    struct Piece srcPiece = board[src[1]][src[0]];
    playerFlag=c=='w'?1:0;

    printf("%d %d",*whiteFlag,playerFlag);
    if(playerFlag!=*whiteFlag){
        printf("\n Wrong!!! it is the turn of other player\n");
        return;
    }

    if(isSourceEmpty(board,src))
    {
        printf("\n-------------------------------------------");
        printf("\n !!!!!There is no peace at position %s %s  \n",source,destination);
        printf("---------------------------------------------\n");
        return;
    }

    if(board[src[1]][src[0]].color!=playerFlag)
    {
        printf("\n That piece does not belong to current player!!!\n");
        return;
    }

    if(board[dest[1]][dest[0]].type!=NONE && board[dest[1]][dest[0]].color==playerFlag)
    {
        printf("\n !!! You can not move on your own piece\n");
    }

    

    
    if(srcPiece.type==PAWN)
    {
        pawnMove(board,src,dest,whiteFlag);
    }
    else if(srcPiece.type==ROOK)
    {
        rookMove(board,src,dest,whiteFlag);
    }
    else if(srcPiece.type==BISHOP)
    {
        bishopMove(board,src,dest,whiteFlag);
    }
    
    

    
    free(src);
    free(dest);
}

void pawnMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag)
{
    int x1=source[1];
    int x2=dest[1];
    int y1=source[0];
    int y2=dest[0];

    printf("x2 x1 %d %d",x2,x1);
    int moveDirection = *whiteFlag?1:-1;
    int yMov=y2-y1;
    printf("yMov %d moveDirection %d",yMov,moveDirection);
    int xMov=x2-x1;

    if(xMov!=moveDirection)
    {
        printf("\n Pawn can only go forward with one step\n");
        return;
    }
    

    if((y2-y1)!=0)
    {
        printf("helloo");
        if(Board[x2][y2].type!=NONE)
        {
            Board[x2][y2]=Board[x1][y1];
            Board[x1][y1].type=NONE;
            Board[x1][y1].name="   ";
            *whiteFlag=*whiteFlag?0:1;
            return;
        }
        else
        {
            printf("\n Pawn can go only horizental if it does not eat enemy piece\n");
            return;
        }
    }
    
    printf("\n\n\n%d x2:%d y2:%d",Board[x2][y2].type,x2,y2);
    if(Board[x2][y2].type!=NONE)
    {
        printf("\n Pawn is blocked. There is another piece on the way\n");
        return;
    }

    Board[x2][y2]=Board[x1][y1];
    Board[x1][y1].type=NONE;
    Board[x1][y1].name="   ";
    *whiteFlag=*whiteFlag?0:1;




    

    


}

void rookMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag)
{
    int x1=source[1];
    int x2=dest[1];
    int y1=source[0];
    int y2=dest[0];

    int xMov=x2-x1;
    int yMove=y2-y1;

    if(xMov && yMove)
    {
        printf("\n!!! Rook can move only one directional \n");
        return;
    }

    if(xMov > 0)
    {
        for(int i=x1+1;i<x2;i++)
    {
        if(Board[i][y2].type=!NONE)
        {
            printf("\n !!! There are other pieces on the way\n Rook can not jump over like knight\n");
            return;

        }
        i++;
    }
    }
    else if(xMov<0)
    {
        printf(" exactly this is");
        printf("\n %d %d",x1,x2);
        for(int i=x1-1;i>x2;i--)
    {
        printf("%d i ",i);
        if(Board[i][y2].type=!NONE)
        {
            printf(" type %d",Board[i][y2].type);
            printf("\n !!! There are other pieces on the way\n Rook can not jump over like knight\n");
            return;

        }
        i++;
    }
    }

    else if(yMove>0)
    {
        for(int i=y1+1;i<y2;i++)
    {
        if(Board[x1][i].type=!NONE)
        {
            printf("\n !!! There are other pieces on the way\n Rook can not jump over like knight\n");
            return;

        }
        i++;
    }
    }
    else
    {
         for(int i=y2-1;i>y1+1;i--)
    {
        if(Board[x1][i].type=!NONE)
        {
            printf("\n !!! There are other pieces on the way\n Rook can not jump over like knight\n");
            return;

        }
        i++;
    }
    }

    Board[x2][y2]=Board[x1][y1];
    Board[x1][y1].type=NONE;
    Board[x1][y1].name="   ";
    *whiteFlag=*whiteFlag?0:1;

    

    
    

}

void bishopMove(struct Piece Board[][8],int* source,int* dest,int *whiteFlag)
{

    int x1=source[1];
    int x2=dest[1];
    int y1=source[0];
    int y2=dest[0];

    int xMov=x2-x1;
    int yMov=y2-y1;

    if(!xMov || !yMov)
    {
        printf("\n !!! Bishop can not go straight\n");
        return ;
    }

    if(xMov!=yMov)
    {
        printf("\n !!! Bishop can only go cross \n");
        return;
    }

    Board[x2][y2]=Board[x1][y1];
    Board[x1][y1].type=NONE;
    Board[x1][y1].name="   ";
    *whiteFlag=*whiteFlag?0:1;


}

void knightMove()
{

}

void queenMove()
{

}

void kingMove()
{

}



int isSourceEmpty(struct Piece board[][8],int* source)
{
    if(board[source[1]][source[0]].type==NONE)
    {
        return 1;
    }
    else
        return 0;
}




// utility functions

int* parseMove(char point[])
{
    int index1=point[0]-97;
    int index2=point[1]-49;
    
    int* indexArr;

    indexArr= (int *)malloc(sizeof(int)*2);

    indexArr[0]=index1;
    indexArr[1]=index2;
    return indexArr;

}