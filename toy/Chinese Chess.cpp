#include <cstdlib>
#include <iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
int WhichPlayerSet[22][22]={0};
int RecordUnit32[10][9]=
{
{13,14,15,16,17,16,15,14,13},
{0,0,0,0,0,0,0,0,0},
{0,12,0,0,0,0,0,12,0},
{11,0,11,0,11,0,11,0,11},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{1,0,1,0,1,0,1,0,1},
{0,2,0,0,0,0,0,2,0},
{0,0,0,0,0,0,0,0,0},
{3,4,5,6,7,6,5,4,3},
};

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void DirectionSet(int x,int y)//畫圖 
{
     if(RecordUnit32[y-1][x-1]!=0)
     {
          switch (RecordUnit32[y-1][x-1])
          {
          case 1:
               {
               cout<<"兵";
               break;}
          case 2: 
               {
               cout<<"炮";
               break;}
          case 3: 
               {
               cout<<"硨";
               break;}
          case 4: 
               {
               cout<<"碼";
               break;}
          case 5: 
               {
               cout<<"相";
               break;}
          case 6: 
               {
               cout<<"仕";
               break;}
          case 7: 
               {
               cout<<"帥";
               break;}
          case 11: 
               {
               cout<<"卒";
               break;}
          case 12: 
               {
               cout<<"包";
               break;}
          case 13: 
               {
               cout<<"車";
               break;}
          case 14: 
               {
               cout<<"馬";
               break;}   
          case 15: 
               {
               cout<<"象";
               break;}
          case 16: 
               {
               cout<<"士";
               break;}
          case 17: 
               {
               cout<<"將";
               break;}  
          }
     }
     else
     {     
         if (x==1&&y%5==1){cout<<"┌";}
         else if(x==9&&y%5==1){cout<<"┐";}
         else if(x==1&&y%5==0){cout<<"└";}
         else if(x==9&&y%5==0){cout<<"┘";}
         else if(x==1){cout<<"├";}
         else if(y%5==1){cout<<"┬";}
         else if(x==9){cout<<"┤";}
         else if(y%5==0){cout<<"┴";} 
         else {cout<<"┼";}
     }
}
int CheckSetIsCorrect(int x1,int y1,int x2,int y2)//判斷移動是否合法，合法傳回1，不合法傳回0 
{
    int Player=0,CorrectRecord=0;
    if (RecordUnit32[y1-1][x1-1]-10<0)//紅方棋子 
    {Player=1;}//紅方紀錄數值為1
    else
    {Player=2;}//黑方紀錄數值為2
    if (RecordUnit32[y1-1][x1-1]%10==1)//為兵或卒 
    {
         if(Player==1)//紅方兵，兵的Y座標只能減少，且在Y座標=5之前無法左右移動 
         {
               if(y1>5&&x2-x1!=0)//過楚河漢界前的錯誤移動 
               {return 0;}
               else if(y1>5&&x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//過楚河漢界前的正確移動 
               {return 1;}
               else if(y1<=5)//過楚河漢界後
               {
                    if(y1-y2==1&&x1-x2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))
                    {return 1;}
                    else if (y1-y2==0&&x1-x2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))
                    {return 1;}
                    else if (y1-y2==0&&x1-x2==-1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))
                    {return 1;}
                    else
                    {return 0;}
               }
               else
               {
                   return 0;
               } 
         } 
         else if(Player==2)//黑方卒，卒的Y座標只能增加，且在Y座標=6之前無法左右移動 
         {
               if(y1<6&&x2-x1!=0)//過楚河漢界前的錯誤移動 
               {return 0;}
               else if(y1<6&&x2-x1==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//過楚河漢界前的正確移動 
               {return 1;}
               else if(y1>=6)//過楚河漢界後
               {
                    if(y2-y1==1&&x1-x2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))
                    {return 1;}
                    else if (y1-y2==0&&x1-x2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))
                    {return 1;}
                    else if (y1-y2==0&&x1-x2==-1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))
                    {return 1;}
                    else
                    {return 0;}
               }
               else
               {
                   return 0;
               } 
         }
         else//錯誤 
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==2)//黑包或紅炮 
    {
         if(Player==1)//紅包。1.須越過一枚棋子，並且目標是黑方單位2.水平或垂直移動，不可穿越單位 
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//非直線移動
             {return 0;}
             else if (x1-x2!=0)//水平移動
             {
                  if(x2>x1)//向右移動
                  {
                      for (int i=x1+1;i<x2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//路徑中有一顆棋子，並且目標地為黑方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(x1>x2)//向左移動
                  {
                      for (int i=x1-1;i>x2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//路徑中有一顆棋子，並且目標地為黑方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//垂直移動
             {
                  if(y2>y1)//向下移動
                  {
                      for (int i=y1+1;i<y2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//路徑中有一顆棋子，並且目標地為黑方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(y1>y2)//向上移動
                  {
                      for (int i=y1-1;i>y2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//路徑中有一顆棋子，並且目標地為黑方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
             } 
         }
         else if(Player==2)//黑包。1.須越過一枚棋子，並且目標是紅方單位2.水平或垂直移動，不可穿越單位 
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//非直線移動
             {return 0;}
             else if (x1-x2!=0)//水平移動
             {
                  if(x2>x1)//向右移動
                  {
                      for (int i=x1+1;i<x2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//路徑中有一顆棋子，並且目標地為紅方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(x1>x2)//向左移動
                  {
                      for (int i=x1-1;i>x2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//路徑中有一顆棋子，並且目標地為紅方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//垂直移動
             {
                  if(y2>y1)//向下移動
                  {
                      for (int i=y1+1;i<y2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//路徑中有一顆棋子，並且目標地為紅方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(y1>y2)//向上移動
                  {
                      for (int i=y1-1;i>y2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//路徑中有一顆棋子，並且目標地為紅方棋子
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
             } 
         }
    }
    else if(RecordUnit32[y1-1][x1-1]%10==3)//黑車或紅硨
    {
         if(Player==1)
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//非直線移動
             {return 0;}
             else if (x1-x2!=0)//水平移動
             {
                  if(x2>x1)//向右移動
                  {
                      for (int i=x1+1;i<x2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//路徑中沒有其他棋子，並且目標地無棋子或是有黑方棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(x1>x2)//向左移動
                  {
                      for (int i=x1-1;i>x2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//垂直移動
             {
                  if(y2>y1)//向下移動
                  {
                      for (int i=y1+1;i<y2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(y1>y2)//向上移動
                  {
                      for (int i=y1-1;i>y2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//路徑中沒有其他棋子，並且目標地無棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
             }
         }
         else if(Player==2)
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//非直線移動
             {return 0;}
             else if (x1-x2!=0)//水平移動
             {
                  if(x2>x1)//向右移動
                  {
                      for (int i=x1+1;i<x2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//路徑中沒有其他棋子，並且目標地無棋子或是有紅方棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(x1>x2)//向左移動
                  {
                      for (int i=x1-1;i>x2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//路徑中沒有其他棋子，並且目標地無棋子或是有紅方棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//垂直移動
             {
                  if(y2>y1)//向下移動
                  {
                      for (int i=y1+1;i<y2;i++)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//路徑中沒有其他棋子，並且目標地無棋子或是有紅方棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
                  else if(y1>y2)//向上移動
                  {
                      for (int i=y1-1;i>y2;i--)//利用迴圈判斷路徑中是否有其他棋子 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//路徑中沒有其他棋子，並且目標地無棋子或是有紅方棋子 
                      {return 1;}
                      else//其他皆不合法 
                      {return 0;} 
                  }
             }
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==4)//黑馬或紅碼
    {
         if(Player==1)//紅方 
         {
             if(x1-x2==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左上日 
             {return 1;}
             else if(x2-x1==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右上日 
             {return 1;}
             else if(x1-x2==2&&y1-y2==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左上橫日 
             {return 1;}
             else if(x2-x1==2&&y1-y2==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右上橫日 
             {return 1;}
             else if(x1-x2==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左下日 
             {return 1;}
             else if(x2-x1==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右下日 
             {return 1;}
             else if(x1-x2==2&&y2-y1==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左下橫日 
             {return 1;}
             else if(x2-x1==2&&y2-y1==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右下橫日 
             {return 1;}
             else
             {return 0;}
         }
         else if(Player==2)//黑方 
         {
             if(x1-x2==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左上日 
             {return 1;}
             else if(x2-x1==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右上日 
             {return 1;}
             else if(x1-x2==2&&y1-y2==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左上橫日 
             {return 1;}
             else if(x2-x1==2&&y1-y2==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右上橫日 
             {return 1;}
             else if(x1-x2==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左下日 
             {return 1;}
             else if(x2-x1==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右下日 
             {return 1;}
             else if(x1-x2==2&&y2-y1==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左下橫日 
             {return 1;}
             else if(x2-x1==2&&y2-y1==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右下橫日 
             {return 1;}
             else
             {return 0;}
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==5)//黑象或紅相
    {
         if(Player==1)//紅方 
         {
             if(y2<6)//越過楚河漢界
             {return 0;}
             else if(x1-x2==2&&y1-y2==2&&RecordUnit32[y1-2][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左上田
             {return 1;}
             else if(x2-x1==2&&y1-y2==2&&RecordUnit32[y1-2][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右上田 
             {return 1;}
             else if(x1-x2==2&&y2-y1==2&&RecordUnit32[y1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左下田 
             {return 1;}
             else if(x2-x1==2&&y2-y1==2&&RecordUnit32[y1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右下田 
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//黑方 
         {
             if(y2>5)//越過楚河漢界
             {return 0;}
             else if(x1-x2==2&&y1-y2==2&&RecordUnit32[y1-2][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左上田
             {return 1;}
             else if(x2-x1==2&&y1-y2==2&&RecordUnit32[y1-2][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右上田 
             {return 1;}
             else if(x1-x2==2&&y2-y1==2&&RecordUnit32[y1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左下田 
             {return 1;}
             else if(x2-x1==2&&y2-y1==2&&RecordUnit32[y1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右下田 
             {return 1;} 
             else 
             {return 0;}
         }
         else
         {return 0;}
    } 
    else if(RecordUnit32[y1-1][x1-1]%10==6)//黑士或紅仕 
    {
         if(Player==1)//紅方 
         {
             if (y2<8)//越過田字範圍 
             {return 0;}
             else if (x2>6||x2<4)//越過田字範圍 
             {return 0;}
             else if (x1-x2==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左上 
             {return 1;}
             else if (x2-x1==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右上
             {return 1;} 
             else if (x1-x2==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左下 
             {return 1;}
             else if (x2-x1==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右下
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//黑方 
         {
             if (y2>3)//越過田字範圍 
             {return 0;}
             else if (x2>6||x2<4)//越過田字範圍 
             {return 0;}
             else if (x1-x2==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左上 
             {return 1;}
             else if (x2-x1==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右上
             {return 1;} 
             else if (x1-x2==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左下 
             {return 1;}
             else if (x2-x1==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右下
             {return 1;} 
             else 
             {return 0;}
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==7)//黑將或紅帥 
    {
         if(Player==1)//紅方 
         {
             if (y2<8)//越過田字範圍 
             {return 0;}
             else if (x2>6||x2<4)//越過田字範圍 
             {return 0;}
             else if (x1-x2==1&&y1-y2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//左 
             {return 1;}
             else if (x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//上
             {return 1;} 
             else if (x1-x2==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//下 
             {return 1;}
             else if (x2-x1==1&&y2-y1==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//右
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//黑方 
         {
             if (y2>3)//越過田字範圍 
             {return 0;}
             else if (x2>6||x2<4)//越過田字範圍 
             {return 0;}
             else if (x1-x2==1&&y1-y2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//左 
             {return 1;}
             else if (x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//上
             {return 1;} 
             else if (x1-x2==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//下 
             {return 1;}
             else if (x2-x1==1&&y2-y1==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//右
             {return 1;} 
             else 
             {return 0;}
         }
         else
         {return 0;}
    } 
}
int CheckEndGame()
{
    int BlackAlive=0,RedAlive=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<9;j++)
        {
            if(RecordUnit32[i][j]==7)
            {RedAlive=1;}
            else if(RecordUnit32[i][j]==17)
            {BlackAlive=1;}
            else
            {}
        }
    }
    if(RedAlive==1&&BlackAlive==1)//兩方帥將都存活，遊戲繼續 
    {return 0;}
    else if(BlackAlive==0)//紅方勝利
    {return 1;} 
    else if(RedAlive==0)//黑方勝利
    {return 2;} 
    else
    {return 0;}
}
int main()
{
    int Key,Xset=5,Yset=10,EndGame=0,WhoToPlay=1,PlayerDownSet=0;
    int FirstX,FirstY;
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<11;j++)
        {
            gotoxy(i*2,j);
            DirectionSet(i,j);
            //cout<<RecordUnit[j-1][i-1];
        }
    }
    while(1)//遊戲尚未分出勝負即繼續，判斷方法為CheckEndGame()，值0繼續，值1紅方獲勝，值2黑方獲勝 
    {
    do{
    Xset=5;
    Yset=10;//起始座標從紅方帥開始 
    PlayerDownSet=0;//玩家是否完成下棋的判斷值
    gotoxy(22,5);
    cout<<"紅(帥)攻！"; 
    while(1)//判斷上下左右 
    {
        gotoxy(Xset*2,Yset);
        Key=getch();
        if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
        else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
        else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
        else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
        else if (Key==13)//玩家按下Enter要選擇棋子 
        {
             if(RecordUnit32[Yset-1][Xset-1]-10<0&&RecordUnit32[Yset-1][Xset-1]!=0)//選擇的是紅方棋子 
             {
                  FirstX=Xset;
                  FirstY=Yset;//將要移動的棋子初始座標紀錄
                  while(1)
                  {
                       gotoxy(Xset*2,Yset);
                       Key=getch();
                       if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
                       else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
                       else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
                       else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
                       else if (Key==13&&(Yset!=FirstY||Xset!=FirstX))//玩家按下Enter確定要移動的位置
                       {
                            if(CheckSetIsCorrect(FirstX,FirstY,Xset,Yset)==1)
                            {
                            RecordUnit32[Yset-1][Xset-1]=RecordUnit32[FirstY-1][FirstX-1];
                            RecordUnit32[FirstY-1][FirstX-1]=0;
                            gotoxy(FirstX*2,FirstY);
                            DirectionSet(FirstX,FirstY);
                            gotoxy(Xset*2,Yset);
                            DirectionSet(Xset,Yset);
                            PlayerDownSet=1;
                            break;
                            }
                            else
                            {
                            }
                       }
                       else if (Key==27)
                       {
                            break;
                       } 
                          
                  }
                  break;
             }
             else
             {break;}
        }
        if (PlayerDownSet==1)//紅方是否完成下棋
        {break;}
    }
    }while(PlayerDownSet!=1);
    if(CheckEndGame()!=0)//確認是否分出勝負 
    {break;}
    do{ 
    Xset=5;
    Yset=1;//起始座標從黑方將開始 
    PlayerDownSet=0;//玩家是否完成下棋的判斷值 
    gotoxy(22,5);
    cout<<"黑(將)攻！";
    while(1)//判斷上下左右 
    {
        gotoxy(Xset*2,Yset);
        Key=getch();
        if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
        else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
        else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
        else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
        else if (Key==13)//玩家按下Enter要選擇棋子 
        {
             if(RecordUnit32[Yset-1][Xset-1]-10>0&&RecordUnit32[Yset-1][Xset-1]!=0)//選擇的是黑方棋子 
             {
                  FirstX=Xset;
                  FirstY=Yset;//將要移動的棋子初始座標紀錄
                  while(1)
                  {
                       gotoxy(Xset*2,Yset);
                       Key=getch();
                       if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
                       else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
                       else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
                       else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
                       else if (Key==13&&(Yset!=FirstY||Xset!=FirstX))//玩家按下Enter確定要移動的位置
                       {
                            if(CheckSetIsCorrect(FirstX,FirstY,Xset,Yset)==1)
                            {
                            RecordUnit32[Yset-1][Xset-1]=RecordUnit32[FirstY-1][FirstX-1];
                            RecordUnit32[FirstY-1][FirstX-1]=0;
                            gotoxy(FirstX*2,FirstY);
                            DirectionSet(FirstX,FirstY);
                            gotoxy(Xset*2,Yset);
                            DirectionSet(Xset,Yset);
                            PlayerDownSet=1;
                            break;
                            }
                            else
                            {
                            }
                       }
                       else if (Key==27)//按下Esc重新選擇棋子 
                       {
                            break;
                       } 
                          
                  }
                  break;
             }
             else
             {break;}
        }
        if (PlayerDownSet==1)//黑方是否完成下棋
        {break;}
    }
    }while(PlayerDownSet!=1);
    if(CheckEndGame()!=0)//確認是否分出勝負 
    {break;}
    } 
    gotoxy(22,5);
    if(CheckEndGame()==1)
    {cout<<"紅方(帥)獲勝！";}
    else
    {cout<<"黑方(將)獲勝！";}
    gotoxy(0,12);
    system("PAUSE");
    return 0;
}
