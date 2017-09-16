#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
using namespace std;

int map[10][10]={0};
void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}
int randl()
{
	int a;
	a=rand()%100;
	return a;
}
int setmap(int x,int y)
{
    int a=0;
    if(x>=0&&x<10&&y>=0&&y<=10)
    {
        if(map[x][y]==10)
        a=1;
    }
    return a;
}
void set()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			map[i][j]=0;
		}
	}
	int a,b,t=0;
	while(t<=5)
	{
		a=randl();
		b=a%10;
		a=a/10;
		while(map[a][b]==10)
		{
			a=randl();
			b=a%10;
			a=a/10;
		}
		map[a][b]=10;
		t++;
	}
	int temp;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
            temp=0;
			if(map[i][j]!=10)
			{
                temp+=setmap(i,j+1);//上     
                temp+=setmap(i,j-1);//下 
                temp+=setmap(i-1,j);//左 
                temp+=setmap(i+1,j);//右 
                temp+=setmap(i-1,j+1);//左上 
                temp+=setmap(i+1,j+1);//右上 
                temp+=setmap(i-1,j-1);//左下 
                temp+=setmap(i+1,j-1);//右下 
                map[i][j]=temp;
		    }   
		}
	}
}
void printmap(int x,int y)
{
    gotoxy(x*2+2,y+1);
    char* num[10]={"　","１","２","３","４","５","６","７","８","９"};
    if(map[x][y]==0)
    cout<<"－";
    else if(map[x][y]==10)
    cout<<"＊";
    else if(map[x][y]==-1)
    ;
    else
    cout<<num[map[x][y]];
}
void check_win()
{
    int temp=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(map[i][j]>=0)
            temp++;
        }
    }
    if(temp==6)
    {
        gotoxy(40,20);
        cout<<"U win!!"<<endl;
    }
}
void show(int x,int y)
{
    if(map[x][y]==0)
    {
        printmap(x,y);
        map[x][y]=-1;
        if(x>0)
        show(x-1,y);
        if(x>0&&y>0)
        show(x-1,y-1);
        if(y>0)
        show(x,y-1);
        if(y>0&&x<9)
        show(x+1,y-1);
        if(x<9)
        show(x+1,y);
        if(x<9&&y<9)
        show(x+1,y+1);
        if(y<9)
        show(x,y+1);
        if(y<9&&x>0)
        show(x-1,y+1);
    }
    else if(map[x][y]!=10)
    {
        printmap(x,y);
        map[x][y]=-1;
    }
    else
    {
        gotoxy(40,20);
        cout<<"U lose!"<<endl;
    }
}
int main()
{
    int endgame=0,key,x,y;
    set();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            gotoxy(i*2+2,j+1);
            cout<<"口";
        }
    }
    while(1)
    {
        x=1;y=1;
        while(1)
        {
            gotoxy(x*2,y);
            key=getch();
            if (key==72) {if(y<=1){y=10;}else{y -=1;}}
            else if (key==80) {if(y>=10){y=1;}else{y +=1;}}
            else if (key==75) {if(x<=1){x=10;}else{x -=1;}}
            else if (key==77) {if(x>=10){x=1;}else{x +=1;}}
            else if (key==13)//玩家按下Enter要選擇棋子
            {
                if(map[x-1][y-1]==10)
                {
                    printmap(x-1,y-1);
                    gotoxy(40,20);
                    cout<<"U lose!"<<endl;
                }
                else if(map[x-1][y-1]!=0)
                {
                    printmap(x-1,y-1);
                    map[x-1][y-1]=-1;
                }
                else
                show(x-1,y-1);
                check_win();
            }
            
        }
        
    }
	system("pause");
	return 0;
}
