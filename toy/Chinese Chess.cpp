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
void DirectionSet(int x,int y)//�e�� 
{
     if(RecordUnit32[y-1][x-1]!=0)
     {
          switch (RecordUnit32[y-1][x-1])
          {
          case 1:
               {
               cout<<"�L";
               break;}
          case 2: 
               {
               cout<<"��";
               break;}
          case 3: 
               {
               cout<<"��";
               break;}
          case 4: 
               {
               cout<<"�X";
               break;}
          case 5: 
               {
               cout<<"��";
               break;}
          case 6: 
               {
               cout<<"�K";
               break;}
          case 7: 
               {
               cout<<"��";
               break;}
          case 11: 
               {
               cout<<"��";
               break;}
          case 12: 
               {
               cout<<"�]";
               break;}
          case 13: 
               {
               cout<<"��";
               break;}
          case 14: 
               {
               cout<<"��";
               break;}   
          case 15: 
               {
               cout<<"�H";
               break;}
          case 16: 
               {
               cout<<"�h";
               break;}
          case 17: 
               {
               cout<<"�N";
               break;}  
          }
     }
     else
     {     
         if (x==1&&y%5==1){cout<<"�z";}
         else if(x==9&&y%5==1){cout<<"�{";}
         else if(x==1&&y%5==0){cout<<"�|";}
         else if(x==9&&y%5==0){cout<<"�}";}
         else if(x==1){cout<<"�u";}
         else if(y%5==1){cout<<"�s";}
         else if(x==9){cout<<"�t";}
         else if(y%5==0){cout<<"�r";} 
         else {cout<<"�q";}
     }
}
int CheckSetIsCorrect(int x1,int y1,int x2,int y2)//�P�_���ʬO�_�X�k�A�X�k�Ǧ^1�A���X�k�Ǧ^0 
{
    int Player=0,CorrectRecord=0;
    if (RecordUnit32[y1-1][x1-1]-10<0)//����Ѥl 
    {Player=1;}//��������ƭȬ�1
    else
    {Player=2;}//�¤�����ƭȬ�2
    if (RecordUnit32[y1-1][x1-1]%10==1)//���L�Ψ� 
    {
         if(Player==1)//����L�A�L��Y�y�Хu���֡A�B�bY�y��=5���e�L�k���k���� 
         {
               if(y1>5&&x2-x1!=0)//�L���e�~�ɫe�����~���� 
               {return 0;}
               else if(y1>5&&x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�L���e�~�ɫe�����T���� 
               {return 1;}
               else if(y1<=5)//�L���e�~�ɫ�
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
         else if(Player==2)//�¤��A��Y�y�Хu��W�[�A�B�bY�y��=6���e�L�k���k���� 
         {
               if(y1<6&&x2-x1!=0)//�L���e�~�ɫe�����~���� 
               {return 0;}
               else if(y1<6&&x2-x1==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�L���e�~�ɫe�����T���� 
               {return 1;}
               else if(y1>=6)//�L���e�~�ɫ�
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
         else//���~ 
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==2)//�¥]�ά��� 
    {
         if(Player==1)//���]�C1.���V�L�@�T�Ѥl�A�åB�ؼЬO�¤���2.�����Ϋ������ʡA���i��V��� 
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//�D���u����
             {return 0;}
             else if (x1-x2!=0)//��������
             {
                  if(x2>x1)//�V�k����
                  {
                      for (int i=x1+1;i<x2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//���|�����@���Ѥl�A�åB�ؼЦa���¤�Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(x1>x2)//�V������
                  {
                      for (int i=x1-1;i>x2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//���|�����@���Ѥl�A�åB�ؼЦa���¤�Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//��������
             {
                  if(y2>y1)//�V�U����
                  {
                      for (int i=y1+1;i<y2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//���|�����@���Ѥl�A�åB�ؼЦa���¤�Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(y1>y2)//�V�W����
                  {
                      for (int i=y1-1;i>y2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)>0)//���|�����@���Ѥl�A�åB�ؼЦa���¤�Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
             } 
         }
         else if(Player==2)//�¥]�C1.���V�L�@�T�Ѥl�A�åB�ؼЬO������2.�����Ϋ������ʡA���i��V��� 
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//�D���u����
             {return 0;}
             else if (x1-x2!=0)//��������
             {
                  if(x2>x1)//�V�k����
                  {
                      for (int i=x1+1;i<x2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//���|�����@���Ѥl�A�åB�ؼЦa������Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(x1>x2)//�V������
                  {
                      for (int i=x1-1;i>x2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//���|�����@���Ѥl�A�åB�ؼЦa������Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//��������
             {
                  if(y2>y1)//�V�U����
                  {
                      for (int i=y1+1;i<y2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//���|�����@���Ѥl�A�åB�ؼЦa������Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(y1>y2)//�V�W����
                  {
                      for (int i=y1-1;i>y2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&RecordUnit32[y2-1][x2-1]==0)//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else if(CorrectRecord==1&&(RecordUnit32[y2-1][x2-1]-10)<0)//���|�����@���Ѥl�A�åB�ؼЦa������Ѥl
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
             } 
         }
    }
    else if(RecordUnit32[y1-1][x1-1]%10==3)//�¨��ά���
    {
         if(Player==1)
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//�D���u����
             {return 0;}
             else if (x1-x2!=0)//��������
             {
                  if(x2>x1)//�V�k����
                  {
                      for (int i=x1+1;i<x2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl�άO���¤�Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(x1>x2)//�V������
                  {
                      for (int i=x1-1;i>x2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//��������
             {
                  if(y2>y1)//�V�U����
                  {
                      for (int i=y1+1;i<y2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(y1>y2)//�V�W����
                  {
                      for (int i=y1-1;i>y2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
             }
         }
         else if(Player==2)
         {
             if ((x1-x2)!=0&&(y1-y2)!=0)//�D���u����
             {return 0;}
             else if (x1-x2!=0)//��������
             {
                  if(x2>x1)//�V�k����
                  {
                      for (int i=x1+1;i<x2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl�άO������Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(x1>x2)//�V������
                  {
                      for (int i=x1-1;i>x2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[y1-1][i-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl�άO������Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;}
                  }
                  else
                  {return 0;} 
             }
             else if (y1-y2!=0)//��������
             {
                  if(y2>y1)//�V�U����
                  {
                      for (int i=y1+1;i<y2;i++)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl�άO������Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
                  else if(y1>y2)//�V�W����
                  {
                      for (int i=y1-1;i>y2;i--)//�Q�ΰj��P�_���|���O�_����L�Ѥl 
                      {
                          if (RecordUnit32[i-1][x1-1]!=0)
                          {CorrectRecord +=1;}
                      }
                      if(CorrectRecord==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���|���S����L�Ѥl�A�åB�ؼЦa�L�Ѥl�άO������Ѥl 
                      {return 1;}
                      else//��L�Ҥ��X�k 
                      {return 0;} 
                  }
             }
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==4)//�°��ά��X
    {
         if(Player==1)//���� 
         {
             if(x1-x2==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���W�� 
             {return 1;}
             else if(x2-x1==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�W�� 
             {return 1;}
             else if(x1-x2==2&&y1-y2==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���W��� 
             {return 1;}
             else if(x2-x1==2&&y1-y2==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�W��� 
             {return 1;}
             else if(x1-x2==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���U�� 
             {return 1;}
             else if(x2-x1==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�U�� 
             {return 1;}
             else if(x1-x2==2&&y2-y1==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���U��� 
             {return 1;}
             else if(x2-x1==2&&y2-y1==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�U��� 
             {return 1;}
             else
             {return 0;}
         }
         else if(Player==2)//�¤� 
         {
             if(x1-x2==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���W�� 
             {return 1;}
             else if(x2-x1==1&&y1-y2==2&&RecordUnit32[y1-2][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�W�� 
             {return 1;}
             else if(x1-x2==2&&y1-y2==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���W��� 
             {return 1;}
             else if(x2-x1==2&&y1-y2==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�W��� 
             {return 1;}
             else if(x1-x2==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���U�� 
             {return 1;}
             else if(x2-x1==1&&y2-y1==2&&RecordUnit32[y1][x1-1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�U�� 
             {return 1;}
             else if(x1-x2==2&&y2-y1==1&&RecordUnit32[y1-1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���U��� 
             {return 1;}
             else if(x2-x1==2&&y2-y1==1&&RecordUnit32[y1-1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�U��� 
             {return 1;}
             else
             {return 0;}
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==5)//�¶H�ά���
    {
         if(Player==1)//���� 
         {
             if(y2<6)//�V�L���e�~��
             {return 0;}
             else if(x1-x2==2&&y1-y2==2&&RecordUnit32[y1-2][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���W��
             {return 1;}
             else if(x2-x1==2&&y1-y2==2&&RecordUnit32[y1-2][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�W�� 
             {return 1;}
             else if(x1-x2==2&&y2-y1==2&&RecordUnit32[y1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���U�� 
             {return 1;}
             else if(x2-x1==2&&y2-y1==2&&RecordUnit32[y1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�U�� 
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//�¤� 
         {
             if(y2>5)//�V�L���e�~��
             {return 0;}
             else if(x1-x2==2&&y1-y2==2&&RecordUnit32[y1-2][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���W��
             {return 1;}
             else if(x2-x1==2&&y1-y2==2&&RecordUnit32[y1-2][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�W�� 
             {return 1;}
             else if(x1-x2==2&&y2-y1==2&&RecordUnit32[y1][x1-2]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���U�� 
             {return 1;}
             else if(x2-x1==2&&y2-y1==2&&RecordUnit32[y1][x1]==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�U�� 
             {return 1;} 
             else 
             {return 0;}
         }
         else
         {return 0;}
    } 
    else if(RecordUnit32[y1-1][x1-1]%10==6)//�¤h�ά��K 
    {
         if(Player==1)//���� 
         {
             if (y2<8)//�V�L�Цr�d�� 
             {return 0;}
             else if (x2>6||x2<4)//�V�L�Цr�d�� 
             {return 0;}
             else if (x1-x2==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���W 
             {return 1;}
             else if (x2-x1==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�W
             {return 1;} 
             else if (x1-x2==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//���U 
             {return 1;}
             else if (x2-x1==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k�U
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//�¤� 
         {
             if (y2>3)//�V�L�Цr�d�� 
             {return 0;}
             else if (x2>6||x2<4)//�V�L�Цr�d�� 
             {return 0;}
             else if (x1-x2==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���W 
             {return 1;}
             else if (x2-x1==1&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�W
             {return 1;} 
             else if (x1-x2==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//���U 
             {return 1;}
             else if (x2-x1==1&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k�U
             {return 1;} 
             else 
             {return 0;}
         }
         else
         {return 0;}
    }
    else if(RecordUnit32[y1-1][x1-1]%10==7)//�±N�ά��� 
    {
         if(Player==1)//���� 
         {
             if (y2<8)//�V�L�Цr�d�� 
             {return 0;}
             else if (x2>6||x2<4)//�V�L�Цr�d�� 
             {return 0;}
             else if (x1-x2==1&&y1-y2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�� 
             {return 1;}
             else if (x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�W
             {return 1;} 
             else if (x1-x2==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�U 
             {return 1;}
             else if (x2-x1==1&&y2-y1==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10>0))//�k
             {return 1;} 
             else 
             {return 0;}
         }
         else if(Player==2)//�¤� 
         {
             if (y2>3)//�V�L�Цr�d�� 
             {return 0;}
             else if (x2>6||x2<4)//�V�L�Цr�d�� 
             {return 0;}
             else if (x1-x2==1&&y1-y2==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�� 
             {return 1;}
             else if (x2-x1==0&&y1-y2==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�W
             {return 1;} 
             else if (x1-x2==0&&y2-y1==1&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�U 
             {return 1;}
             else if (x2-x1==1&&y2-y1==0&&(RecordUnit32[y2-1][x2-1]==0||RecordUnit32[y2-1][x2-1]-10<0))//�k
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
    if(RedAlive==1&&BlackAlive==1)//���ӱN���s���A�C���~�� 
    {return 0;}
    else if(BlackAlive==0)//����ӧQ
    {return 1;} 
    else if(RedAlive==0)//�¤�ӧQ
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
    while(1)//�C���|�����X�ӭt�Y�~��A�P�_��k��CheckEndGame()�A��0�~��A��1������ӡA��2�¤���� 
    {
    do{
    Xset=5;
    Yset=10;//�_�l�y�бq����Ӷ}�l 
    PlayerDownSet=0;//���a�O�_�����U�Ѫ��P�_��
    gotoxy(22,5);
    cout<<"��(��)��I"; 
    while(1)//�P�_�W�U���k 
    {
        gotoxy(Xset*2,Yset);
        Key=getch();
        if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
        else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
        else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
        else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
        else if (Key==13)//���a���UEnter�n��ܴѤl 
        {
             if(RecordUnit32[Yset-1][Xset-1]-10<0&&RecordUnit32[Yset-1][Xset-1]!=0)//��ܪ��O����Ѥl 
             {
                  FirstX=Xset;
                  FirstY=Yset;//�N�n���ʪ��Ѥl��l�y�Ь���
                  while(1)
                  {
                       gotoxy(Xset*2,Yset);
                       Key=getch();
                       if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
                       else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
                       else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
                       else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
                       else if (Key==13&&(Yset!=FirstY||Xset!=FirstX))//���a���UEnter�T�w�n���ʪ���m
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
        if (PlayerDownSet==1)//����O�_�����U��
        {break;}
    }
    }while(PlayerDownSet!=1);
    if(CheckEndGame()!=0)//�T�{�O�_���X�ӭt 
    {break;}
    do{ 
    Xset=5;
    Yset=1;//�_�l�y�бq�¤�N�}�l 
    PlayerDownSet=0;//���a�O�_�����U�Ѫ��P�_�� 
    gotoxy(22,5);
    cout<<"��(�N)��I";
    while(1)//�P�_�W�U���k 
    {
        gotoxy(Xset*2,Yset);
        Key=getch();
        if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
        else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
        else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
        else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
        else if (Key==13)//���a���UEnter�n��ܴѤl 
        {
             if(RecordUnit32[Yset-1][Xset-1]-10>0&&RecordUnit32[Yset-1][Xset-1]!=0)//��ܪ��O�¤�Ѥl 
             {
                  FirstX=Xset;
                  FirstY=Yset;//�N�n���ʪ��Ѥl��l�y�Ь���
                  while(1)
                  {
                       gotoxy(Xset*2,Yset);
                       Key=getch();
                       if (Key==72) {if(Yset<=1){Yset=10;}else{Yset -=1;}}
                       else if (Key==80) {if(Yset>=10){Yset=1;}else{Yset +=1;}}
                       else if (Key==75) {if(Xset<=1){Xset=9;}else{Xset -=1;}}
                       else if (Key==77) {if(Xset>=9){Xset=1;}else{Xset +=1;}}
                       else if (Key==13&&(Yset!=FirstY||Xset!=FirstX))//���a���UEnter�T�w�n���ʪ���m
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
                       else if (Key==27)//���UEsc���s��ܴѤl 
                       {
                            break;
                       } 
                          
                  }
                  break;
             }
             else
             {break;}
        }
        if (PlayerDownSet==1)//�¤�O�_�����U��
        {break;}
    }
    }while(PlayerDownSet!=1);
    if(CheckEndGame()!=0)//�T�{�O�_���X�ӭt 
    {break;}
    } 
    gotoxy(22,5);
    if(CheckEndGame()==1)
    {cout<<"����(��)��ӡI";}
    else
    {cout<<"�¤�(�N)��ӡI";}
    gotoxy(0,12);
    system("PAUSE");
    return 0;
}
