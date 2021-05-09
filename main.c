#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define M 40
#define N 20


int x,y,Arr[M][N],head,Gy,game,fruits,a,b,var,tail,dir,choice=1,choiceend=49;
void displaymenu()
{
    printf("==================================================\n");
    printf("=                                                =\n");
    printf("=                  SELECT MODE                   =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=------------------1. MODE 1---------------------=\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=------------------2. MODE 2---------------------=\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=           PRESS 1 OR 2 TO PLAY GAME            =\n");
    printf("=                                                =\n");
    printf("==================================================\n");

}
void displayend()
{
    printf("==================================================\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                 1. PLAY AGAIN                  =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                 2. EXIT                        =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("==================================================\n");

}
void makefruis()
{
    srand(time(0));
    a=rand()%40;
    b=rand()%20;
    if(Arr[a][b]==0&&fruits==0)
    {
        Arr[a][b]=-1;
        fruits=-1;
    }
}
void makesnake()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            Arr[i][j]=0;
        }
    }
    x=M/2;y=N/2;head=0;game=0;fruits=0;tail=1;dir='d';choice=1;
    for(int i=1;i<=5;i++)
    {
        Arr[x][y]=i;
        y++;
        head++;
    }

}
void ResetScreenPosition(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut,Position);
}

void displaygame()
{
    for(int i=0;i<=M+1;i++)
    {
        if(i==0) printf("%c",178);
        else if(i>=1&&i<=M) printf("%c",178);
        else if(i==M+1) printf("%c\n",178);
    }
    for(int j=0;j<N;j++)
    {
        printf("%c",178);
        for(int i=0;i<M;i++)
        {
            if(Arr[i][j]>0&&Arr[i][j]!=head) printf("%c",176);
            if(Arr[i][j]==head) printf("%c",178);
            if(Arr[i][j]==0) printf(" ");
            if(Arr[i][j]==-1) printf("%c",'0');

        }
        printf("%c\n",178);
    }
    for(int i=0;i<=M+1;i++)
    {
        if(i==0) printf("%c",178);
        else if(i>=1&&i<=M) printf("%c",178);
        else if(i==M+1) printf("%c\n",178 );
    }
}

int scankey()
{
    if(kbhit())
        return getch();
    else
        return 1;
}

void move1()
{

    var=scankey();
    var=tolower(var);
    if(((var=='d'||var=='a')||(var=='w'||var=='s'))
       &&(abs(dir-var)>5)) dir = var;
    if(dir=='d')
        {
        x++;
        if(x==M) x=0;
        if(Arr[x][y]>0) game=0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='a')
        {
        x--;
        if(x==-1) x=M-1;
        if(Arr[x][y]>0) game=0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='w')
        {
        y--;
        if(y==-1)y=N-1;
        if(Arr[x][y]>0) game=0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='s')
        {
        y++;
        if(y==N) y=0;
        if(Arr[x][y]>0) game =0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }

}
void move2()
{

    var=scankey();
    tolower(var);
    if(((var=='d'||var=='a')||(var=='w'||var=='s'))
       &&(abs(dir-var)>5)) dir = var;
    if(dir=='d')
        {
        x++;
        if(x==M) game=0;
        if(Arr[x][y]>0) game =0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='a')
        {
        x--;
        if(x==-1) game=0;
        if(Arr[x][y]>0) game =0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='w')
        {
        y--;
        if(y==-1) game=0;
        if(Arr[x][y]>0) game =0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }
    if(dir=='s')
        {
        y++;
        if(y==N) game=0;
        if(Arr[x][y]>0) game =0;
        if(Arr[x][y]==-1)
        {
            tail=tail-1;
            fruits=0;
        }
        head++;
        Arr[x][y]=head;
        }

}


void tailremove()
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(Arr[i][j]==tail)
            Arr[i][j]=0;
        }
    }
    tail++;
}
void choiceendbutton()
{

    choiceend=scankey();
    displayend();
    ResetScreenPosition();
}
void choicebutton()
{
    while(choice==1)
    {
        choice=scankey();
        displaymenu();
        Sleep(100);
        ResetScreenPosition();
        if(choice==49)
        {
            system("cls");
            game=1;
        }
        if(choice==50)
        {
            system("cls");
            game =2;
        }
    }
}
void displaybye()
{
    int i=5;
    while(i>=0)
    {
    printf("==================================================\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=-----------COUNTDOWN TO EXIT GAME: %d------------=\n",i);
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("=                                                =\n");
    printf("==================================================\n");
    i--;
    Sleep(1000);
    ResetScreenPosition();
    }
}
int main()
{
    while(choiceend==49)
    {
    makesnake();
    choicebutton();
    while(game==1)
    {
    makefruis();
    move1();
    tailremove();
    ResetScreenPosition();
    displaygame();
    Sleep(100);
    }
    while(game==2)
    {
    makefruis();
    move2();
    tailremove();
    ResetScreenPosition();
    displaygame();
    Sleep(100);
    }
    system("cls");
    while(1)
    {
    choiceendbutton();
    if(choiceend==49)
    {
        system("cls");
        break;
    }
    if(choiceend==50)
    {
        system("cls");
        break;
    }
    }
    }
    displaybye();
}
