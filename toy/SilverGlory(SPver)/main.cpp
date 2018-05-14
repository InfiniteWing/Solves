#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
using namespace std;
static bool event[1000]={false};//�����ƥ�O�_�F�����}�C �w�]1000��ƥ�
static int money=0;//����
static int boss_ap_map[100];//[]�̶�J�a��ID ��Ȭ��Ǫ�ID 
static int chap=0,section=0;
void add_money(int temp_money);//�W�[���� 
void lv_turnon_event(int lv);//�H���Ŷ}�Ҩƥ�(�ɯŮɦA�P�_�Y�i) 
static int change_chap[6]={1,2,3,4,5,6};
void remove_money(int temp_money);//��֪���(�n���P�_��������)
void item_turnon_event(int id);//�D��}�Ҩƥ�
class map//�a�����O
{
public:
    int map_id;
    string map;
    int map_to[5];//�����ǰe�I�|�쪺�a��ID
    int map_to_atx[5];//�����ǰe�I��X�y��
    int map_to_aty[5];//�����ǰe�I��y�y��
    string map_name;//�a�ϦW��
};
class boss
{
public:
    int lv,hp,mp,exp,ap_map,at_po,de_po;//ap_map:�X�{�a��
    string name;
    string boss_sk_name[4];//�����Ǫ��ۦ��W�� 
    int boss_skill[4];//�����[������
    int skill_temp[5];//�|�өۦ����X�۾��v �t�k�]
    int drop_money;
    int drop_item;//���������D��ID 
    bool boss_show;
    int boss_event_key;//�}��BOSS�һݪ��ƥ�
};
class saler
{
public:
    int sale_id[10];//�̦h�c��10�ؤ��P�������D��
    int at_map;//�O��NPC�Ҧb���a�� ID(�a��ID�q1�}�l)
    int at_x;//NPC��󨺱i�a�Ϫ�x�y�� 
    int at_y;//NPC��󨺱i�a�Ϫ�y�y��
    string saler_greet;//�ӤH���۩I�λy 
    string saler_name;
};
class chapter
{
public:
    int section[10];//�O���ĴX�` 
    string story[10];//�������`���� 
};
class itm //�D�����O
{
public:
    int item_category;//���~����1:�Z�� 2:���� 3:�Ĥ�(+HP) 4:�Ĥ�(+MP) 5:�Ĥ�(+HP&+MP) 6:�Ĥ�(+HP&+MP)(%) 7:�_���Ĥ� 8...�ݫإ�
    int item_eff;//���~�ĪG
    int item_price;
    string item_name;
    string item_intr;//���~����
};
class monster//�Ǫ����O
{
public:
    int lv,hp,mp,exp,ap_map[3],at_po,de_po,ap_op[3];//ap_map:�X�{�a�� ap_op:�X�{���v 
    string name;
    string mon_sk_name[2];//�����Ǫ��ۦ��W�� 
    int mon_skill[2];//�����[������
    int drop_money;
};
int money_drop_ai(int temp);
class player//���a���O(�C���X�R��)
{
public:
    int p_lv,p_hp,p_mp,p_exp,p_str,p_int,p_dex,p_luk,p_pro,p_att,p_maxhp,p_maxmp;//pro:¾�~
    void set_ab()
    {
        p_hp=(p_lv-1)*20+50;//��q
        p_mp=(p_lv-1)*10+50;//�]�O
        p_str=(p_lv-1)*3+4;//�O�q 
        p_dex=4;//�ӱ�
        p_luk=4;//���B
        p_int=4;//���O    
        p_att=(p_lv-1)*5+p_str*3+5;//�����O 
        p_maxhp=p_hp;
        p_maxmp=p_mp;
    }
    string p_name;
    int skill_known[4];//�����|���ۦ�ID
};
int search_saler(int m_id,int x,int y);//�j�M�ӤHID 
void load_map();//���J�a��
bool item_useful(int id);//�D��i�_�ϥ�
void check_npc_event();//�T�{NPC�����Ѽ� 
void check_lvup();//�P�_�O�_�ɯ� 
void draw_battle_map();//�e�X�԰�����
void clear_bat_dia();//�M���԰��e��
void clear_npc_dia();//�M��NPC��ܵe��
int boss_ai(int r1,int r2,int r3,int r4,int r5);//BOSS_AI r1:�k�]���v r2:�ۦ��@...etc
void display_bat_end_dia(string mon,string player,int key);//��ܾ԰����G 1���D����� 2���Ǫ���� 
void display_mon_battle(string s,int atp,int ai,string name);//��ܾ԰����i(�Ǫ���)�HAI�ǤJ�ȧP�_�g�X��س��i 
void display_battle(string s,int atp);//��ܾ԰����i
void draw_mon_detail(int hp,int maxhp,int mp,int maxmp);//�e�X�԰��ɩǪ�����T 
void draw_player_detail();//�e�X�԰��ɪ��a���⪺��T
void draw_battle_skill();//�e�X�԰��ɪ��ޯ��� 
void use_item(int id);//�ϥιD�� 
int mon_ai();//�Ǫ�AI  0:���q����60% 1:�]�k����30%(�ݵ��]�O�O�_�����A�i����) 2:�k�]:10% 
void init_boss_ap_map();//��l��BOSS�X�{���a�� 
static int bat_map[20][20]=//�԰������}�C(20*20)
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,0},
    {0,6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
chapter chap_list[6];//���` �� 
void talk_to_npc(int m_id,int x,int y);//�MNPC��� �ѼƶǤJ�a��ID X�� Y��
int string_to_num(char temp);//�r���ഫ���ƭ� 
static int skill[5][10];//�ޯ�[�����Ʀs��}�C
static string sk_name[5][10];//�ޯ�W��
int item[100];//�ȩw
//�`�N�G�a�Ͻs����1�}�l�A�N�Y[0][]���}�C�S���ϥ�(�H��i���ק�) 
int mon_ap_map[100][3];//�Ǫ��X�{�a�ϯ���
int mon_ap_op[100][3];//�Ǫ��X�u���v����(�p���) 
void init_mam();//��l��mon_ap_map
void b_battle(int b_id);
void draw_map(int temp[10][10]);//��l�e�� 
void gotoxy(int xpos, int ypos);//���ʮy��
int randl();//�ü� 
int bat_hap();//�O�_�o�;԰� 
int which_mon(int m);//�����Ǫ��X�{ ��Ƥ���J�a�Ͻs�� 
void draw_go(int x,int y,int thing);//���ʤ���e�� 
void draw_ab();//��ܨ������
void draw_map(int m_id);//�e�X�a�� 
void battle(int m_id);//�԰��p�� ��Ƹ̭���J�Ǫ�ID
static int myx=1,myy=1,map_id=1,who_is_play=0;//���a����(x,y)��m�A���a�Ҧb�a�ϡA���a�ϥέ������� 
static int level_up_exp[100];
static string my_name="�s���a";
bool check_money(int my,int price);
static int test[10][10];//ø�s�a��
void hp_helper();//�ɦ夤�߹�� 
void show_chap(string s);//��ܳ��` 
player player_list[6];//�إߪ��a���⪫��(�̦h���\6�ب���)
class npc//NPC ���O
{
public:
    int at_map;//�O��NPC�Ҧb���a�� ID(�a��ID�q1�}�l)
    int at_x;//NPC��󨺱i�a�Ϫ�x�y�� 
    int at_y;//NPC��󨺱i�a�Ϫ�y�y��
    int npc_event;//����NPC���ƥ�(�Ω���ܹ��) �@�}�l��0 
    string npc_name;//NPC���W�r
    string npc_dia[3];//NPC���
    int npc_event_key[3];//����NPC�i�J�U�@���q������ƥ� npc_event_key[0]�M[1]�ΨӧP�_�i�J�U�@���q [2]�ΨӧP�_�O�_����NPC��� 
    //�p�G�O�ε��ŧP�_���ܡA��Ȭ����󵥯� 
    int npc_turnon_event[3];//����NPC�U���q��ܷ|���ꪺ�ƥ�
    int npc_category;//����NPC���� 1:������� 2:�ƥ����� 3:�ƥ����(�|�v�T���`) 4:�ﶵ����(�v�T�ƥ�) 5:�S��s�b 
    bool npc_show;//�����O�_�n�X�{
    bool npc_lv_flag;//��NPC�O�HLV���ഫ���true�O,false�_
    bool npc_talk_flag;//��NPC�O�H���ܨ��ഫ���true�O,false�_ �p�G���Ȭ�true�h���ݰ�npc_check_event�P�_ 
    void next_chap()
    {
        if(npc_category==3)
        {
            if(npc_event==2)
            {
                section++;
                show_chap(chap_list[chap].story[section]);
            }
        }
    }
    void npc_check_event()//�T�{�O�_�F����NPC�һݨƥ�A�H�i�J�U�@���q������ 
    {
        if(npc_lv_flag)
        {
            if(npc_show==false)//��NPC�Q����
            {
                if(player_list[who_is_play].p_lv>=npc_event_key[2])//�F�����굥��
                {
                     npc_show=true;
                     event[npc_turnon_event[npc_event]]=true;//���}�ƥ�
                }   
            }
            else 
            {
                if(player_list[who_is_play].p_lv>=npc_event_key[npc_event])//�F�����굥��
                {
                     if(npc_event<2)//���|�W�L�}�C�W�� 
                     npc_event++;
                     event[npc_turnon_event[npc_event]]=true;//���}�ƥ�
                }
            }
        }
        else if(npc_talk_flag==false)//��NPC�O�Ψƥ���ܨƥ� 
        {
            if(npc_show==false)//��NPC�Q����
            {
                if(event[npc_event_key[2]]==true)//����NPC��ܪ��e�m�ƥ�w���� 
                {
                    npc_show=true;
                    event[npc_turnon_event[npc_event]]=true;//���}�ƥ�
                } 
            }
            else
            {
                if(event[npc_event_key[npc_event]]==true)//�i�J�U�@���q���e�m�ƥ�w����
                {
                    if(npc_event<2)//���|�W�L�}�C�W�� 
                    npc_event++;
                    event[npc_turnon_event[npc_event]]=true;//���}�ƥ�             
                } 
            }
        }
    }
    void npc_change_event()
    {
        if(npc_event==2)
        npc_event=0;
        else
        npc_event++;
    }
     
};
class itembox
{
public:
    int num;
};
//�إߦU�ت���
monster mon_map[100];//�إߩǪ�����(�w�]�}�C100) 
npc npc_list[100];//�إ�NPC���� 
map map_list[100];//�إߦa�Ϫ���
itm item_list[100];//�إ߹D�㪫��
itembox itembox_list[100];//�إߧڪ����~�c
saler saler_list[20];
boss boss_map[20];
void add_item(itm *temp,int count);//�W�[���~
void saler_dia(int id);
void show_itembox();//��ܭI�] 
int main(int argc, char *argv[])
{
    event[0]=true;
    level_up_exp[1]=10;//�]�w���Ŵ��ɪ�l 
    for(int i=2;i<100;i++)
    {
        level_up_exp[i]=level_up_exp[i-1]*1.5;
    }
    int key;//��Ȭ���
    //�H�U�O�̪쨤���l 
    player_list[0].p_lv=1;
    player_list[0].p_exp=0;
    player_list[0].p_pro=0;
    player_list[0].set_ab();
    player_list[0].p_name="���~�v";
    player_list[0].skill_known[0]=1;//�@�}�l�|���ޯ�ID
    player_list[0].skill_known[1]=2;//�@�}�l�|���ޯ�ID
    player_list[0].skill_known[2]=3;//�@�}�l�|���ޯ�ID
    player_list[0].skill_known[3]=4;//�@�}�l�|���ޯ�ID
    
    //�H�U�O�ޯ��l
    //�D���ޯ�: 
    skill[0][0]=100;//�����[��(�԰��p���)100=100% 
    sk_name[0][0]="�@��";//ID:1 �Ĥ@��
    skill[0][1]=110;//�����[��(�԰��p���)100=100% 
    sk_name[0][1]="���N";//ID:1 �ĤG�� 
    skill[0][2]=120;//�����[��(�԰��p���)100=100% 
    sk_name[0][2]="���N";//ID:1 �ĤT�� 
    skill[0][3]=130;//�����[��(�԰��p���)100=100% 
    sk_name[0][3]="�˿�";//ID:1 �ĥ|�� 
    //�H�U�O�U����ƪ�l��  
    //BOSS
    boss_map[0].boss_event_key=891;//�ݭn�ƥ�6�����~�����
    boss_map[0].boss_show=false; 
    
    boss_map[1].lv=10;
    boss_map[1].hp=199;
    boss_map[1].mp=0;
    boss_map[1].exp=3210;
    boss_map[1].ap_map=1;
    boss_map[1].at_po=50;
    boss_map[1].de_po=2;
    boss_map[1].name="���j�ƪ��V�V";
    boss_map[1].boss_sk_name[0]="�V�V��";
    boss_map[1].boss_skill[0]=100;
    boss_map[1].boss_sk_name[1]="�V�V�Y�l";
    boss_map[1].boss_skill[1]=140;
    boss_map[1].boss_sk_name[2]="�V�V���_";
    boss_map[1].boss_skill[2]=190;
    boss_map[1].boss_sk_name[3]="�V�V��MAX�I";
    boss_map[1].boss_skill[3]=300;
    boss_map[1].drop_money=1234;//��������
    boss_map[1].drop_item=99;//ID:99�D��
    boss_map[1].skill_temp[0]=5;//�k�]���v 
    boss_map[1].skill_temp[1]=30;
    boss_map[1].skill_temp[2]=60;
    boss_map[1].skill_temp[3]=90;
    boss_map[1].skill_temp[4]=100;
    boss_map[1].boss_event_key=6;//�ݭn�ƥ�7�����~�����
    boss_map[1].boss_show=false; 
     
    boss_map[2].lv=8;
    boss_map[2].hp=99;
    boss_map[2].mp=0;
    boss_map[2].exp=310;
    boss_map[2].ap_map=2;
    boss_map[2].at_po=30;
    boss_map[2].de_po=2;
    boss_map[2].name="�ܺA�p�p�V�V";
    boss_map[2].boss_sk_name[0]="�p�V�V�Q�g���K��";
    boss_map[2].boss_skill[0]=100;
    boss_map[2].boss_sk_name[1]="�p�V�V����";
    boss_map[2].boss_skill[1]=140;
    boss_map[2].boss_sk_name[2]="�p�V�V�j�q";
    boss_map[2].boss_skill[2]=190;
    boss_map[2].boss_sk_name[3]="�p�V�V��MAX";
    boss_map[2].boss_skill[3]=300;
    boss_map[2].drop_money=334;//��������
    boss_map[2].drop_item=98;//ID:98�D��
    boss_map[2].skill_temp[0]=5;//�k�]���v 
    boss_map[2].skill_temp[1]=30;
    boss_map[2].skill_temp[2]=60;
    boss_map[2].skill_temp[3]=90;
    boss_map[2].skill_temp[4]=100;
    boss_map[2].boss_event_key=5;//�ݭn�ƥ�5�����~�����
    boss_map[2].boss_show=false; 
    
    //�Ǫ���ŲNo.001 Name:�p���y LV:1 Hp:20 Mp:0 Exp:4 ap_map[0]=1 at_po=5 de_po=2
    mon_map[0].lv=1;
    mon_map[0].hp=20;
    mon_map[0].mp=0;
    mon_map[0].exp=600;
    mon_map[0].ap_map[0]=1;
    mon_map[0].at_po=5;
    mon_map[0].de_po=2;
    mon_map[0].name="�p�V�V";
    mon_map[0].ap_op[0]=40;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[0].mon_sk_name[0]="��Ǥl(��)";
    mon_map[0].mon_skill[0]=100;
    mon_map[0].mon_sk_name[1]="�V�V���K��";
    mon_map[0].mon_skill[1]=300;
    mon_map[0].drop_money=10;//��������
    
    //�Ǫ���ŲNo.002 Name:�p�۲y LV:1 Hp:20 Mp:0 Exp:4 ap_map[0]=1 at_po=2 de_po=5
    mon_map[1].lv=1;
    mon_map[1].hp=20;
    mon_map[1].mp=0;
    mon_map[1].exp=600;
    mon_map[1].ap_map[0]=1;
    mon_map[1].at_po=2;
    mon_map[1].de_po=5;
    mon_map[1].name="�p�۲y";
    mon_map[1].mon_sk_name[0]="�۲y";
    mon_map[1].mon_skill[0]=100;
    mon_map[1].mon_sk_name[1]="�ѱY�a���L�����j";
    mon_map[1].mon_skill[1]=300;
    mon_map[1].ap_op[0]=40;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[1].drop_money=10;//�������� 
    
    //�Ǫ���ŲNo.003 Name:�p�]�� LV:50 Hp:20000 Mp:2000 Exp:4444 ap_map[0]=1 at_po=2 de_po=5
    mon_map[2].lv=50;
    mon_map[2].hp=20000;
    mon_map[2].mp=2000;
    mon_map[2].exp=4444444;
    mon_map[2].ap_map[0]=1;
    mon_map[2].at_po=500;
    mon_map[2].de_po=500;
    mon_map[2].name="�p�]��";
    mon_map[2].mon_sk_name[0]="�]���H��";
    mon_map[2].mon_skill[0]=110;
    mon_map[2].mon_sk_name[1]="�]���ûR�����]����";
    mon_map[2].mon_skill[1]=5000;
    mon_map[2].ap_op[0]=20;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[2].drop_money=99999;//�������� 
    
     //�Ǫ���ŲNo.004 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[3].lv=5;
    mon_map[3].hp=400;
    mon_map[3].mp=20;
    mon_map[3].exp=100;
    mon_map[3].ap_map[0]=2;
    mon_map[3].at_po=30;
    mon_map[3].de_po=5;
    mon_map[3].name="SmallZergT";
    mon_map[3].mon_sk_name[0]="SM�s��";
    mon_map[3].mon_skill[0]=120;
    mon_map[3].mon_sk_name[1]="SM�Щx�L�v�}";
    mon_map[3].mon_skill[1]=200;
    mon_map[3].ap_op[0]=70;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[3].drop_money=160;//�������� 
    
     //�Ǫ���ŲNo.005 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[4].lv=8;
    mon_map[4].hp=600;
    mon_map[4].mp=120;
    mon_map[4].exp=400;
    mon_map[4].ap_map[0]=2;
    mon_map[4].at_po=40;
    mon_map[4].de_po=5;
    mon_map[4].name="�p��SmallZergT";
    mon_map[4].mon_sk_name[0]="�p��SM�s��";
    mon_map[4].mon_skill[0]=100;
    mon_map[4].mon_sk_name[1]="�p��SM�Щx�L�v�}";
    mon_map[4].mon_skill[1]=200;
    mon_map[4].ap_op[0]=30;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[4].drop_money=240;//�������� 
    
     //�Ǫ���ŲNo.006 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[5].lv=10;
    mon_map[5].hp=800;
    mon_map[5].mp=100;
    mon_map[5].exp=600;
    mon_map[5].ap_map[0]=3;
    mon_map[5].at_po=50;
    mon_map[5].de_po=5;
    mon_map[5].name="��a��������H";
    mon_map[5].mon_sk_name[0]="���H�����";
    mon_map[5].mon_skill[0]=150;
    mon_map[5].mon_sk_name[1]="���C������";
    mon_map[5].mon_skill[1]=250;
    mon_map[5].ap_op[0]=80;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[5].drop_money=300;//�������� 
    
     //�Ǫ���ŲNo.006 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[6].lv=20;
    mon_map[6].hp=5000;
    mon_map[6].mp=1000;
    mon_map[6].exp=1600;
    mon_map[6].ap_map[0]=3;
    mon_map[6].at_po=70;
    mon_map[6].de_po=5;
    mon_map[6].name="���c�����V�V";
    mon_map[6].mon_sk_name[0]="�V�V����~";
    mon_map[6].mon_skill[0]=200;
    mon_map[6].mon_sk_name[1]="�V�V���~";
    mon_map[6].mon_skill[1]=2000;
    mon_map[6].ap_op[0]=20;//�X�{�b�}�Cap_map[0]�a�Ϫ����v��80%
    mon_map[6].drop_money=1400;//�������� 
    //�H�U�ONPC��l
    npc_list[0].npc_name="���Ź��~�v";
    npc_list[0].at_map=1;
    npc_list[0].at_x=1;
    npc_list[0].at_y=2;
    npc_list[0].npc_event=0;
    npc_list[0].npc_show=false;
    npc_list[0].npc_dia[0]="�Q��o�ڪ��{�P�Х��m�ߨ�4���a�I";
    npc_list[0].npc_dia[1]="�I�A�p���ħA�ש�4���F�ܡHť���e��a�Ϧ��H���b���_�A�Хh��o��ܧa�I";
    npc_list[0].npc_dia[2]="�����w���ݭn�A�ڨӺ��@�I�̪�X�{�F�@���L�s���~�A�������h�������I";
    npc_list[0].npc_talk_flag=false;//��NPC�O�_�O�H��ܨӧ@�ƥ�P�_ �O���ܧY�����]�wnpc_event_key����l�� 
    npc_list[0].npc_event_key[0]=2;//�n����NPC�i�J�ĤG�ƥ��ܻݭn����event[2]
    npc_list[0].npc_event_key[1]=7;//�n����NPC�i�J�ĤT�ƥ��ܻݭn����event[3] 
    npc_list[0].npc_event_key[2]=1;//�n��ܸ�NPC�ݭn����event[1]
    npc_list[0].npc_turnon_event[1]=3;//�����ƥ�2���ᥴ�}event[3]
    npc_list[0].npc_turnon_event[2]=6;//�����ƥ�3���ᥴ�}event[6]
    npc_list[0].npc_lv_flag=false;//��NPC�O�_�O�H���ŧ@�ƥ�P�_
    
    /*
    npc_list[0].npc_talk_flag=false;//��NPC�O�_�O�H��ܨӧ@�ƥ�P�_ �O���ܧY�����]�wnpc_event_key����l�� 
    npc_list[0].npc_event_key[0]=1;//�n����NPC�i�J�ĤG�ƥ��ܻݭn����3�� 
    npc_list[0].npc_event_key[1]=4;//�n����NPC�i�J�ĤG�ƥ��ܻݭn����4�� 
    npc_list[0].npc_event_key[2]=1;//�n��ܸ�NPC�ݭn����2�� 
    npc_list[0].npc_lv_flag=false;//��NPC�O�_�O�H���ŧ@�ƥ�P�_
    npc_list[0].npc_turnon_event[2]=1;//�����ƥ�T���ᥴ�}event[1] 
    */
    npc_list[1].npc_name="���������V�V";
    npc_list[1].at_map=2;
    npc_list[1].at_x=2;
    npc_list[1].at_y=5;
    npc_list[1].npc_event=0;
    npc_list[1].npc_show=true;
    npc_list[1].npc_dia[0]="�K�K^^";
    npc_list[1].npc_dia[1]="�A�n�ݬݶܡH";
    npc_list[1].npc_dia[2]="���A�A�u�O�a�J �@�@>///<";
    npc_list[1].npc_talk_flag=true;//��NPC�O�_�O�H��ܨӧ@�ƥ�P�_ �O���ܧY�����]�wnpc_event_key����l��
    npc_list[1].npc_lv_flag=false;//��NPC�O�_�O�H���ŧ@�ƥ�P�_
    
    npc_list[2].npc_name="����";
    npc_list[2].at_map=3;
    npc_list[2].at_x=8;
    npc_list[2].at_y=8;
    npc_list[2].npc_event=0;
    npc_list[2].npc_show=false;
    npc_list[2].npc_dia[0]="���A�ڦ��F��Q�V�V�����F......";
    npc_list[2].npc_dia[1]="�����ڸѨM�X�S�b���O���V�V�I�ܦ^�ڪ��D��I";
    npc_list[2].npc_dia[2]="���§A���ڸѨM�ܺA�V�V^^";
    npc_list[2].npc_talk_flag=false;//��NPC�O�_�O�H��ܨӧ@�ƥ�P�_ �O���ܧY�����]�wnpc_event_key����l�� 
    npc_list[2].npc_event_key[0]=4;//�n����NPC�i�J�ĤG�ƥ��ܻݭn����event[2] 
    npc_list[2].npc_event_key[1]=7;//�n����NPC�i�J�ĤT�ƥ��ܻݭn����event[7] 
    npc_list[2].npc_event_key[2]=3;//�n��ܸ�NPC�ݭn����event[1]
    npc_list[2].npc_turnon_event[0]=4;//�����ƥ�@���ᥴ�}event[2]
    npc_list[2].npc_turnon_event[1]=5;//�����ƥ�2���ᥴ�}event[5]
    npc_list[2].npc_turnon_event[2]=7;//�����ƥ�2���ᥴ�}event[5]
    npc_list[2].npc_lv_flag=false;//��NPC�O�_�O�H���ŧ@�ƥ�P�_
    
    npc_list[3].npc_name="�s��ɤު�";
    npc_list[3].at_map=1;
    npc_list[3].at_x=8;
    npc_list[3].at_y=1;
    npc_list[3].npc_event=0;
    npc_list[3].npc_category=3;
    npc_list[3].npc_show=false;
    npc_list[3].npc_dia[0]="�w��Ө��T�z�����ֶ�I";
    npc_list[3].npc_dia[1]="ť�����観�@��Щx�A�Хh��L�M�D��U^^";
    npc_list[3].npc_dia[2]="���߱z�����F�o���`���D�u���ȡA�{�b�N�z�ǰe��U�@���`�a�ϡA�z�i�H�ϥήɪŤ������s�^�즹���d�i��|���}�Ѫ����å��ȡI";
    npc_list[3].npc_talk_flag=false;//��NPC�O�_�O�H��ܨӧ@�ƥ�P�_ �O���ܧY�����]�wnpc_event_key����l�� 
    npc_list[3].npc_event_key[0]=0;//�n����NPC�i�J�ĤG�ƥ��ܻݭn����event[0]
    npc_list[3].npc_event_key[1]=9;//�n����NPC�i�J�ĤT�ƥ��ܻݭn����event[3] 
    npc_list[3].npc_event_key[2]=0;//�n��ܸ�NPC�ݭn����event[1]
    npc_list[3].npc_turnon_event[1]=1;//�����ƥ�@���ᥴ�}event[1]
    npc_list[3].npc_lv_flag=false;//��NPC�O�_�O�H���ŧ@�ƥ�P�_
    //�H�U�O�a�ϸ�ƪ�l
    //MAP:1
    map_list[1].map_id=1;//ID 1���a�Ϧs��b�}�Cmap_list[1]
    map_list[1].map="";//�ǳƶ}�l�\��}�C
    map_list[1].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[1].map+="0,6,6,6,6,6,6,6,3,0,";
    map_list[1].map+="0,3,1,1,1,1,1,1,6,0,";
    map_list[1].map+="0,6,1,1,1,1,1,1,6,0,";
    map_list[1].map+="0,6,6,6,6,6,6,6,6,0,";
    map_list[1].map+="0,6,4,5,4,6,4,4,6,0,";
    map_list[1].map+="0,6,4,4,4,6,4,5,6,0,";
    map_list[1].map+="0,6,4,4,4,6,4,4,6,0,";
    map_list[1].map+="0,5,6,6,6,6,6,6,5,0,";
    map_list[1].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[1].map_to[0]=2;//��ID 2���ǰe�I
    map_list[1].map_to_atx[0]=8;//���ǰe�I��󦹦a��X�y��
    map_list[1].map_to_aty[0]=8;//���ǰe�I��󦹦a��Y�y��
    map_list[1].map_to[1]=3;//��ID 2���ǰe�I
    map_list[1].map_to_atx[1]=1;//���ǰe�I��󦹦a��X�y��
    map_list[1].map_to_aty[1]=8;//���ǰe�I��󦹦a��Y�y��
    map_list[1].map_to[2]=4;//��ID 4���ǰe�I
    map_list[1].map_to_atx[2]=3;//���ǰe�I��󦹦a��X�y��
    map_list[1].map_to_aty[2]=5;//���ǰe�I��󦹦a��Y�y��
    map_list[1].map_to[3]=5;//��ID 4���ǰe�I
    map_list[1].map_to_atx[3]=7;//���ǰe�I��󦹦a��X�y��
    map_list[1].map_to_aty[3]=6;//���ǰe�I��󦹦a��Y�y��
    map_list[1].map_name="�g�b�����e�D";
    
    //MAP:2
    map_list[2].map_id=2;//ID 1���a�Ϧs��b�}�Cmap_list[1]
    map_list[2].map="";//�ǳƶ}�l�\��}�C
    map_list[2].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[2].map+="0,6,6,6,6,6,6,6,6,0,";
    map_list[2].map+="0,6,1,1,6,6,1,1,6,0,";
    map_list[2].map+="0,6,1,1,6,6,1,1,6,0,";
    map_list[2].map+="0,6,6,6,6,6,6,6,6,0,";
    map_list[2].map+="0,6,3,1,1,1,1,1,6,0,";
    map_list[2].map+="0,6,1,1,1,1,1,1,6,0,";
    map_list[2].map+="0,6,1,1,1,1,1,1,6,0,";
    map_list[2].map+="0,5,6,6,6,6,6,6,5,0,";
    map_list[2].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[2].map_to[0]=1;//��ID 2���ǰe�I
    map_list[2].map_to_atx[0]=1;//���ǰe�I��󦹦a��X�y��
    map_list[2].map_to_aty[0]=8;//���ǰe�I��󦹦a��Y�y��
    map_list[2].map_name="�������p�D";
    
    //MAP:3
    map_list[3].map_id=3;//ID 1���a�Ϧs��b�}�Cmap_list[1]
    map_list[3].map="";//�ǳƶ}�l�\��}�C
    map_list[3].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[3].map+="0,5,1,1,1,1,1,1,1,0,";
    map_list[3].map+="0,1,2,2,2,2,2,2,1,0,";
    map_list[3].map+="0,1,1,1,1,1,1,1,1,0,";
    map_list[3].map+="0,6,6,6,6,6,6,6,6,0,";
    map_list[3].map+="0,6,1,2,2,2,2,1,6,0,";
    map_list[3].map+="0,6,1,2,2,2,2,1,6,0,";
    map_list[3].map+="0,6,1,2,2,2,2,1,6,0,";
    map_list[3].map+="0,6,6,6,6,6,6,6,3,0,";
    map_list[3].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[3].map_to[0]=1;//��MAP_ID:1���ǰe�I
    map_list[3].map_to_atx[0]=1;//���ǰe�I��󦹦a��X�y��
    map_list[3].map_to_aty[0]=1;//���ǰe�I��󦹦a��Y�y��
    map_list[3].map_name="�·t���˪L";
    
    //MAP:4
    map_list[4].map_id=4;//ID 1���a�Ϧs��b�}�Cmap_list[1]
    map_list[4].map="";//�ǳƶ}�l�\��}�C
    map_list[4].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[4].map+="0,2,2,2,2,2,2,2,2,0,";
    map_list[4].map+="0,2,7,2,6,6,2,7,2,0,";
    map_list[4].map+="0,2,6,6,6,6,6,6,2,0,";
    map_list[4].map+="0,2,6,6,6,6,6,6,2,0,";
    map_list[4].map+="0,2,6,2,6,6,2,6,2,0,";
    map_list[4].map+="0,2,6,2,6,6,2,6,2,0,";
    map_list[4].map+="0,2,8,2,6,6,2,6,2,0,";
    map_list[4].map+="0,2,2,2,6,5,2,2,2,0,";
    map_list[4].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[4].map_to[0]=1;//��MAP_ID:1���ǰe�I
    map_list[4].map_to_atx[0]=5;//���ǰe�I��󦹦a��X�y��
    map_list[4].map_to_aty[0]=8;//���ǰe�I��󦹦a��Y�y��
    map_list[4].map_name="�ɵ���";
    
    //MAP:5
    map_list[5].map_id=4;//ID 1���a�Ϧs��b�}�Cmap_list[1]
    map_list[5].map="";//�ǳƶ}�l�\��}�C
    map_list[5].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[5].map+="0,2,2,2,2,2,2,2,2,0,";
    map_list[5].map+="0,2,4,4,4,6,2,4,2,0,";
    map_list[5].map+="0,2,4,4,4,6,2,4,2,0,";
    map_list[5].map+="0,2,6,6,6,6,6,6,2,0,";
    map_list[5].map+="0,2,2,2,2,2,6,2,2,0,";
    map_list[5].map+="0,2,4,4,6,6,6,6,2,0,";
    map_list[5].map+="0,2,4,4,6,6,6,6,2,0,";
    map_list[5].map+="0,2,2,2,6,5,2,2,2,0,";
    map_list[5].map+="0,0,0,0,0,0,0,0,0,0,";
    map_list[5].map_to[0]=1;//��MAP_ID:1���ǰe�I
    map_list[5].map_to_atx[0]=5;//���ǰe�I��󦹦a��X�y��
    map_list[5].map_to_aty[0]=8;//���ǰe�I��󦹦a��Y�y��
    map_list[5].map_name="���K��a";
    
    //�إߦU��ITEM
    
    item_list[1].item_category=3;
    item_list[1].item_eff=50;
    item_list[1].item_name="���ĤY";
    item_list[1].item_intr="��_HP50�I";
    item_list[1].item_price=100;
    
    item_list[2].item_category=3;
    item_list[2].item_eff=150;
    item_list[2].item_name="���Ĥ�";
    item_list[2].item_intr="��_HP150�I";
    item_list[2].item_price=230;
    
    item_list[3].item_category=3;
    item_list[3].item_eff=300;
    item_list[3].item_name="�j�ɩ�";
    item_list[3].item_intr="��_HP300�I";
    item_list[3].item_price=400;
    
    item_list[41].item_category=8;
    item_list[41].item_eff=300;
    item_list[41].item_name="�������K��";
    item_list[41].item_intr="�ݤ��M���̭������e";
    item_list[41].item_price=9999;
    
    item_list[42].item_category=8;
    item_list[42].item_eff=300;
    item_list[42].item_name="SM�Щx���}�º��y�c";
    item_list[42].item_intr="���G�S����������";
    item_list[42].item_price=44;
    
    item_list[98].item_category=8;
    item_list[98].item_eff=300;
    item_list[98].item_name="���ѵV�V���ҩ�";
    item_list[98].item_intr="�i�c���V�V�Q���ѤF�I";
    item_list[98].item_price=44;
    
    item_list[99].item_category=8;
    item_list[99].item_eff=300;
    item_list[99].item_name="�H����";
    item_list[99].item_intr="�����۾��K�ɮ�";
    item_list[99].item_price=0;
    //�إ߰ӤH
    saler_list[0].saler_name="�g�k���X�j�j��";
    saler_list[0].saler_greet="�x�H�ڪ��ĤY�O�H";
    saler_list[0].sale_id[0]=1;//��D��ID1:���ĤY 
    saler_list[0].sale_id[1]=2;//��D��ID1:���ĤY 
    saler_list[0].sale_id[2]=3;//��D��ID1:���ĤY 
    saler_list[0].at_map=4;
    saler_list[0].at_x=2;
    saler_list[0].at_y=2;
    
    saler_list[1].saler_name="�����X���k�l";
    saler_list[1].saler_greet="�F��ۤv�ݡA���n���Z�ڡI";
    saler_list[1].sale_id[0]=41;//��D��ID1:���ĤY 
    saler_list[1].sale_id[1]=42;//��D��ID1:���ĤY 
    saler_list[1].at_map=4;
    saler_list[1].at_x=7;
    saler_list[1].at_y=2;
    
    chap_list[0].story[0]="�p���q�p�ͬ��b�¾륭�R���p��A�q�ӳ��S����Ĳ�L�{�N���ֳt�ͬ��A���@�ѡA�L�]�t�ڷ|�U�Ө�F��T�z��������...";
    chap_list[0].story[1]="���߱z���������`�i�q���w���j�A�p���l���F���Ѥ���Q�n��W�h�ӡA��O�L�i�J�F����Ǵ����Ȫ��@���n�餽�q�W�Z...";
    chap_list[1].story[0]="�p���I�p���_�ɰաI�ʹʹʡA�ʹʹʡI";
    show_chap(chap_list[chap].story[section]);
    init_mam();
    init_boss_ap_map();
    load_map();
    while(1)
    {
        if(player_list[who_is_play].p_hp<=0)
        {
            if(player_list[who_is_play].p_lv==1)
            {
                system("cls");
                break;
            }
        }
        gotoxy(myx*2+20,myy+10);
        cout<<"�I";
        gotoxy(20,25);
        key=getch();
        gotoxy(10,8);
        cout<<" �@�@�@�@�@";
        if(key==72)//�W 
        {
            if(test[myy-1][myx]==1)//�i�J��a�A�ǳƾ԰��B�� 
            { 
                draw_go(myx,myy,test[myy][myx]);//�M�X�e�@��
                myy -=1;
                if(bat_hap()==1)//���q�p�L 
                {
                    gotoxy(10,8);
                    cout<<"�o�;԰��F�I";
                    draw_battle_map();
                    battle(which_mon(map_id));
                }
                else if(bat_hap()==2)//BOSS
                {
                    if(boss_map[boss_ap_map[map_id]].boss_show==false)
                    {
                        if(event[boss_map[boss_ap_map[map_id]].boss_event_key])
                        {
                            boss_map[boss_ap_map[map_id]].boss_show=true;
                        }
                    }
                    if(boss_map[boss_ap_map[map_id]].boss_show)
                    {
                        gotoxy(10,8);
                        cout<<"�o�;԰��F�I";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy-1][myx]==6)//�ťը��D 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy -=1;
            }
            else if(test[myy-1][myx]==3)//�J��NPC 
            {
                talk_to_npc(map_id,myx,myy-1);
            }
            else if(test[myy-1][myx]==5)//�J���ǰe�I 
            {
                myy -=1;
                load_map();
            }
            else if(test[myy-1][myx]==8)//�J���_�I�̤��� 
            {
                hp_helper();
            }
            else if(test[myy-1][myx]==7)//�J���ө� 
            {
                saler_dia(search_saler(map_id,myx,myy-1));
            }
            
        }
        else if(key==80)//�U 
        {
            if(test[myy+1][myx]==1)//�i�J��a�A�ǳƾ԰��B�� 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy +=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"�o�;԰��F�I";
                    draw_battle_map();
                    battle(which_mon(map_id));
                }
                else if(bat_hap()==2)//BOSS
                {
                    if(boss_map[boss_ap_map[map_id]].boss_show==false)
                    {
                        if(event[boss_map[boss_ap_map[map_id]].boss_event_key])
                        {
                            boss_map[boss_ap_map[map_id]].boss_show=true;
                        }
                    }
                    if(boss_map[boss_ap_map[map_id]].boss_show)
                    {
                        gotoxy(10,8);
                        cout<<"�o�;԰��F�I";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy+1][myx]==6)//�ťը��D 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy +=1;
            }
            else if(test[myy+1][myx]==3)//�J��NPC 
            {
                talk_to_npc(map_id,myx,myy+1);
            }
            else if(test[myy+1][myx]==5)//�J���ǰe�I 
            {
                myy +=1;
                load_map();
            }
            else if(test[myy+1][myx]==8)//�J���_�I�̤��� 
            {
                hp_helper();
            }
            else if(test[myy+1][myx]==7)//�J���ө� 
            {
                saler_dia(search_saler(map_id,myx,myy+1));
            }
        }
        else if(key==75)//�� 
        {
            if(test[myy][myx-1]==1)//�i�J��a�A�ǳƾ԰��B�� 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx -=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"�o�;԰��F�I";
                    draw_battle_map();
                    battle(which_mon(map_id));
                }
                else if(bat_hap()==2)//BOSS
                {
                    if(boss_map[boss_ap_map[map_id]].boss_show==false)
                    {
                        if(event[boss_map[boss_ap_map[map_id]].boss_event_key])
                        {
                            boss_map[boss_ap_map[map_id]].boss_show=true;
                        }
                    }
                    if(boss_map[boss_ap_map[map_id]].boss_show)
                    {
                        gotoxy(10,8);
                        cout<<"�o�;԰��F�I";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy][myx-1]==6)//�ťը��D 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx -=1;
            }
            else if(test[myy][myx-1]==3)//�J��NPC 
            {
                talk_to_npc(map_id,myx-1,myy);
            }
            else if(test[myy][myx-1]==5)//�J���ǰe�I 
            {
                myx -=1;
                load_map();
            }
            else if(test[myy][myx-1]==8)//�J���_�I�̤��� 
            {
                hp_helper();
            }
            else if(test[myy][myx-1]==7)//�J���ө� 
            {
                saler_dia(search_saler(map_id,myx-1,myy));
            }
        }
        else if(key==77)//�k 
        {
            if(test[myy][myx+1]==1)//�i�J��a�A�ǳƾ԰��B�� 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx +=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"�o�;԰��F�I";
                    draw_battle_map();
                    battle(which_mon(map_id));
                }
                else if(bat_hap()==2)//BOSS
                {
                    if(boss_map[boss_ap_map[map_id]].boss_show==false)
                    {
                        if(event[boss_map[boss_ap_map[map_id]].boss_event_key])
                        {
                            boss_map[boss_ap_map[map_id]].boss_show=true;
                        }
                    }
                    if(boss_map[boss_ap_map[map_id]].boss_show)
                    {
                        gotoxy(10,8);
                        cout<<"�o�;԰��F�I";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy][myx+1]==6)//�ťը��D 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx +=1;
            }
            else if(test[myy][myx+1]==3)//�J��NPC 
            {
                talk_to_npc(map_id,myx+1,myy);
            }
            else if(test[myy][myx+1]==5)//�J���ǰe�I 
            {
                myx +=1;
                load_map();
            }
            else if(test[myy][myx+1]==8)//�J���_�I�̤��� 
            {
                hp_helper();
            }
            else if(test[myy][myx+1]==7)//�J���ө�
            {
                saler_dia(search_saler(map_id,myx+1,myy));
            }
        }
        else if(key==105)//itombox
        {
            show_itembox();
        }
        else if(key==97)//draw_ab()
        {
            draw_ab();
            system("cls");
            draw_map(test);
        }
    }
    gotoxy(10,5);
    cout<<"GAME OVER�I�I";
    key=getch();
    return EXIT_SUCCESS;
}
void draw_map(int temp[10][10])
{
    system("cls");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            gotoxy(j*2+20,i+10);
            if(temp[i][j]==0)
            cout<<"��";
            else if(temp[i][j]==1)
            cout<<"��";
            else if(temp[i][j]==2)
            cout<<"��";
            else if(temp[i][j]==3)
            cout<<"��";
            else if(temp[i][j]==4)
            cout<<"�f";
            else if(temp[i][j]==5)
            cout<<"��";
            else if(temp[i][j]==6)
            cout<<"�@";
            else if(temp[i][j]==7)
            cout<<"�C";
            else if(temp[i][j]==8)
            cout<<"�q";
        }
    }
}
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void draw_go(int x,int y,int thing)
{
    gotoxy(x*2+20,y+10);
    if(thing==1)
    cout<<"��";
    else if(thing==6)
    cout<<"�@";
    else if(thing==5)
    cout<<"��";
}
int randl()
{
    int a;
	a=rand()%100+1;
	return a;
}
int bat_hap()
{
    int temp;
    temp=randl();
    if(temp<=15)//�o�;԰��^��1�A�Ϥ��^��0 
    return 1;
    else if(temp<=59)//BOSS 4%���v 
    return 2;
    else
    return 0;
}
void draw_ab()
{
    int temp_key;
    gotoxy(50,10);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,10);
    cout<<"LV:"<<player_list[who_is_play].p_lv;
    gotoxy(50,12);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,12);
    cout<<"HP:"<<player_list[who_is_play].p_hp<<"/"<<player_list[who_is_play].p_maxhp;
    gotoxy(50,14);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,14);
    cout<<"MP:"<<player_list[who_is_play].p_mp<<"/"<<player_list[who_is_play].p_maxmp;
    gotoxy(50,16);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,16);
    cout<<"EXP:"<<player_list[who_is_play].p_exp<<"/"<<level_up_exp[player_list[who_is_play].p_lv];
    gotoxy(50,18);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,18);
    cout<<"�����O:"<<player_list[who_is_play].p_att;
    gotoxy(50,20);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(50,20);
    cout<<"str:"<<player_list[who_is_play].p_str<<" dex:"<<player_list[who_is_play].p_dex<<" luk:"<<player_list[who_is_play].p_luk<<" int:"<<player_list[who_is_play].p_int;
    gotoxy(50,22);
    cout<<"$"<<money;
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//���a�����UENTER 
}
void battle(int m_id)//�ǤJ�Ǫ�ID 
{
    int level_up_bool=0;
    int bat_x=18,bat_y=22,key,mon_temp_hp=mon_map[m_id].hp,mon_temp_mp=mon_map[m_id].mp;
    int temp_mon_atp,temp_ai;
    int do_att=0;//�����O�_�ϥX���� 0���_ 1���O
    int do_run=0;//�����O�_�k�] 0���_ 1���O
    int battle_end=0;//�����O�_�����԰� (�i��O�Ǫ����` �]�i��O�D�����`) 0���_ 1���D����� 2���Ǫ���� 
    string bat_dia="";
    //�H�U�e�X�԰�������T 
    gotoxy(20,4);
    cout<<"���ͪ�"<<mon_map[m_id].name<<"���X�ӤF";
    gotoxy(12,6);
    cout<<"Name:"<<mon_map[m_id].name;
    gotoxy(32,6);
    cout<<"LV:"<<mon_map[m_id].lv;
    draw_mon_detail(mon_temp_hp,mon_map[m_id].hp,mon_map[m_id].mp,mon_temp_mp);
    draw_player_detail();
    gotoxy(36,22);
    cout<<"���԰����D��";
    gotoxy(36,23);
    cout<<"�����⡷�k�]";
    while(1)
    {
    while(1)
    {
        if(do_att==1)//�w�o�ʧ��� ��w�ﶵ
        break; 
        gotoxy(bat_x*2,bat_y);
        key=getch();
        if(key==72)//�W
        {
            if(bat_y==22)
            bat_y=23;
            else
            bat_y -=1;
        }
        else if(key==80)//�U
        {
            if(bat_y==23)
            bat_y=22;
            else
            bat_y +=1;
        }
        else if(key==75)//��
        {
            if(bat_x==18)
            bat_x=21;
            else
            bat_x -=3;
        }
        else if(key==77)//�k
        {
            if(bat_x==21)
            bat_x=18;
            else
            bat_x +=3;
        }
        else if(key==13)//���Uenter
        {
            if(bat_x==18&&bat_y==22)//���U�԰��ﶵ
            {
                draw_battle_skill();
                bat_x=6;
                bat_y=22;
                while(1)
                {
                    gotoxy(bat_x*2,bat_y);
                    key=getch();
                    if(key==72)//�W
                    {
                        if(bat_y==22)
                        bat_y=23;
                        else
                        bat_y -=1;
                    }
                    else if(key==80)//�U
                    {
                        if(bat_y==23)
                        bat_y=22;
                        else
                        bat_y +=1;
                    }
                    else if(key==75)//��
                    {
                        if(bat_x==6)
                        bat_x=12;
                        else
                        bat_x -=6;
                    }
                    else if(key==77)//�k
                    {
                        if(bat_x==12)
                        bat_x=6;
                        else
                        bat_x +=6;
                    }
                    else if(key==13)//���Uenter
                    {
                        int cho_sk,atp;
                        bat_dia="";
                        if(bat_x==6&&bat_y==22)//��ܧޯ�skill_known[0]
                        {
                            cho_sk=0;
                        }
                        else if(bat_x==12&&bat_y==22)//��ܧޯ�skill_known[1]
                        {
                            cho_sk=1;
                        }
                        else if(bat_x==6&&bat_y==23)//��ܧޯ�skill_known[2]
                        {
                            cho_sk=2;
                        } 
                        else if(bat_x==12&&bat_y==23)//��ܧޯ�skill_known[3]
                        {
                            cho_sk=3;
                        }
                        atp=(player_list[who_is_play].p_att)*(skill[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1])/100;
                        bat_dia+=player_list[who_is_play].p_name;
                        bat_dia+="�ϥX�F";
                        bat_dia+=sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1];                        
                        display_battle(bat_dia,atp);
                        mon_temp_hp -=atp;
                        do_att=1;
                        bat_x=18;
                        bat_y=22;
                        break;
                        
                    }
                    else if(key==27)//���UEsc���}��� 
                    {
                        bat_x=18;
                        bat_y=22;
                        break;
                    }
                }
            }
            else if(bat_x==21&&bat_y==23)//���U�k�]�ﶵ
            {
                do_run=1; 
                break;
            }
        }
    }
    if(do_run==1)//�k�]�F
    {
        draw_map(test);
        break; 
    }
    if(mon_temp_hp<=0)
    {
        mon_temp_hp=0;
    }
    //��ܩǪ���T
    draw_mon_detail(mon_temp_hp,mon_map[m_id].hp,mon_map[m_id].mp,mon_temp_mp);
    clear_bat_dia();
    if(mon_temp_hp<=0)
    {
        int temp_money;
        mon_temp_hp=0;
        battle_end=1;//�԰����� �D�����
        display_bat_end_dia(mon_map[m_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        player_list[who_is_play].p_exp+=mon_map[m_id].exp;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"��o�F"<<mon_map[m_id].exp<<"�I�g���";
        temp_money=money_drop_ai(mon_map[m_id].drop_money);
        gotoxy(12,12);
        cout<<player_list[who_is_play].p_name<<"��o�F$"<<temp_money;
        add_money(temp_money);
        do{
            key=getch();
        }while(key!=13);//���a�����UENTER
        draw_ab();
        clear_bat_dia();
        check_lvup();
        clear_bat_dia();
        break;
    }
    //���Ǫ����� �P�_AI
    temp_ai=mon_ai(); 
    //�����O��������O���H�����Y��
    if(temp_ai==4)//�Ǫ��k�]�F�I
    {
        display_mon_battle("",0,temp_ai,mon_map[m_id].name);
        draw_map(test);
        break;//���}�j�� 
    }
    bat_dia="";
    temp_mon_atp=(mon_map[m_id].at_po)*(mon_map[m_id].mon_skill[temp_ai])/100;
    bat_dia+=mon_map[m_id].name;
    bat_dia+="�ϥX�F";
    bat_dia+=mon_map[m_id].mon_sk_name[temp_ai];
    display_mon_battle(bat_dia,temp_mon_atp,temp_ai,mon_map[m_id].name);
    player_list[who_is_play].p_hp-=temp_mon_atp;
    
    if(player_list[who_is_play].p_hp<=0)
    {
        player_list[who_is_play].p_hp=0;
    } 
    //��ܪ��a��T
    draw_player_detail();
    clear_bat_dia();
    
    //�P�_���a�O�_��q�k�s
    if(player_list[who_is_play].p_hp<=0)
    {
        battle_end=2;//�԰����� �Ǫ����
        draw_ab();
        display_bat_end_dia(mon_map[m_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        break;
    }
    else
    {
        do_att=0;//���s�o�ʧ��� 
    }
     
    }
    draw_map(test);
    gotoxy(24,8);
    cout<<map_list[map_id].map_name;
}
void b_battle(int b_id)//�ǤJBOSS ID 
{
    int level_up_bool=0;
    int bat_x=18,bat_y=22,key,boss_temp_hp=boss_map[b_id].hp,boss_temp_mp=boss_map[b_id].mp;
    int temp_boss_atp,temp_ai;
    int do_att=0;//�����O�_�ϥX���� 0���_ 1���O
    int do_run=0;//�����O�_�k�] 0���_ 1���O
    int battle_end=0;//�����O�_�����԰� (�i��O�Ǫ����` �]�i��O�D�����`) 0���_ 1���D����� 2���Ǫ���� 
    string bat_dia="";
    //�H�U�e�X�԰�������T 
    gotoxy(20,4);
    cout<<"�j�j�²r�Ӯ�^�T��"<<boss_map[b_id].name<<"���X�ӤF";
    gotoxy(12,6);
    cout<<"Name:"<<boss_map[b_id].name;
    gotoxy(32,6);
    cout<<"LV:"<<boss_map[b_id].lv;
    draw_mon_detail(boss_temp_hp,boss_map[b_id].hp,boss_map[b_id].mp,boss_temp_mp);
    draw_player_detail();
    gotoxy(36,22);
    cout<<"���԰����D��";
    gotoxy(36,23);
    cout<<"�����⡷�k�]";
    while(1)
    {
    while(1)
    {
        if(do_att==1)//�w�o�ʧ��� ��w�ﶵ
        break; 
        gotoxy(bat_x*2,bat_y);
        key=getch();
        if(key==72)//�W
        {
            if(bat_y==22)
            bat_y=23;
            else
            bat_y -=1;
        }
        else if(key==80)//�U
        {
            if(bat_y==23)
            bat_y=22;
            else
            bat_y +=1;
        }
        else if(key==75)//��
        {
            if(bat_x==18)
            bat_x=21;
            else
            bat_x -=3;
        }
        else if(key==77)//�k
        {
            if(bat_x==21)
            bat_x=18;
            else
            bat_x +=3;
        }
        else if(key==13)//���Uenter
        {
            if(bat_x==18&&bat_y==22)//���U�԰��ﶵ
            {
                draw_battle_skill();
                bat_x=6;
                bat_y=22;
                while(1)
                {
                    gotoxy(bat_x*2,bat_y);
                    key=getch();
                    if(key==72)//�W
                    {
                        if(bat_y==22)
                        bat_y=23;
                        else
                        bat_y -=1;
                    }
                    else if(key==80)//�U
                    {
                        if(bat_y==23)
                        bat_y=22;
                        else
                        bat_y +=1;
                    }
                    else if(key==75)//��
                    {
                        if(bat_x==6)
                        bat_x=12;
                        else
                        bat_x -=6;
                    }
                    else if(key==77)//�k
                    {
                        if(bat_x==12)
                        bat_x=6;
                        else
                        bat_x +=6;
                    }
                    else if(key==13)//���Uenter
                    {
                        int cho_sk,atp;
                        bat_dia="";
                        if(bat_x==6&&bat_y==22)//��ܧޯ�skill_known[0]
                        {
                            cho_sk=0;
                        }
                        else if(bat_x==12&&bat_y==22)//��ܧޯ�skill_known[1]
                        {
                            cho_sk=1;
                        }
                        else if(bat_x==6&&bat_y==23)//��ܧޯ�skill_known[2]
                        {
                            cho_sk=2;
                        } 
                        else if(bat_x==12&&bat_y==23)//��ܧޯ�skill_known[3]
                        {
                            cho_sk=3;
                        }
                        atp=(player_list[who_is_play].p_att)*(skill[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1])/100;
                        bat_dia+=player_list[who_is_play].p_name;
                        bat_dia+="�ϥX�F";
                        bat_dia+=sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1];                        
                        display_battle(bat_dia,atp);
                        boss_temp_hp -=atp;
                        do_att=1;
                        bat_x=18;
                        bat_y=22;
                        break;
                        
                    }
                    else if(key==27)//���UEsc���}��� 
                    {
                        bat_x=18;
                        bat_y=22;
                        break;
                    }
                }
            }
            else if(bat_x==21&&bat_y==23)//���U�k�]�ﶵ
            {
                do_run=1; 
                break;
            }
        }
    }
    if(do_run==1)//�k�]�F
    {
        draw_map(test);
        break; 
    }
    if(boss_temp_hp<=0)
    {
        boss_temp_hp=0;
    }
    //��ܩǪ���T
    draw_mon_detail(boss_temp_hp,boss_map[b_id].hp,boss_map[b_id].mp,boss_temp_mp);
    clear_bat_dia();
    if(boss_temp_hp<=0)
    {
        int temp_money;
        boss_temp_hp=0;
        battle_end=1;//�԰����� �D�����
        display_bat_end_dia(boss_map[b_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        player_list[who_is_play].p_exp+=boss_map[b_id].exp;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"��o�F"<<boss_map[b_id].exp<<"�I�g���";
        temp_money=money_drop_ai(boss_map[b_id].drop_money);
        gotoxy(12,12);
        cout<<player_list[who_is_play].p_name<<"��o�F$"<<temp_money;
        add_money(temp_money);
        gotoxy(12,13);
        cout<<player_list[who_is_play].p_name<<"��o�F���ȹD��G"<<item_list[boss_map[b_id].drop_item].item_name;
        itembox_list[boss_map[b_id].drop_item].num++;
        item_turnon_event(boss_map[b_id].drop_item);
        do{
            key=getch();
        }while(key!=13);//���a�����UENTER
        draw_ab();
        clear_bat_dia();
        check_lvup();
        clear_bat_dia();
        break;
    }
    //���Ǫ����� �P�_AI
    temp_ai=boss_ai(boss_map[b_id].skill_temp[0],boss_map[b_id].skill_temp[1],boss_map[b_id].skill_temp[2],boss_map[b_id].skill_temp[3],boss_map[b_id].skill_temp[4]); 
    //�����O��������O���H�����Y��
    if(temp_ai==4)//BOSS�k�]�F�I
    {
        display_mon_battle("",0,temp_ai,boss_map[b_id].name);
        draw_map(test);
        break;//���}�j�� 
    }
    bat_dia="";
    temp_boss_atp=(boss_map[b_id].at_po)*(boss_map[b_id].boss_skill[temp_ai])/100;
    bat_dia+=boss_map[b_id].name;
    bat_dia+="�ϥX�F";
    bat_dia+=boss_map[b_id].boss_sk_name[temp_ai];
    display_mon_battle(bat_dia,temp_boss_atp,temp_ai,boss_map[b_id].name);
    player_list[who_is_play].p_hp-=temp_boss_atp;
    
    if(player_list[who_is_play].p_hp<=0)
    {
        player_list[who_is_play].p_hp=0;
    } 
    //��ܪ��a��T
    draw_player_detail();
    clear_bat_dia();
    
    //�P�_���a�O�_��q�k�s
    if(player_list[who_is_play].p_hp<=0)
    {
        battle_end=2;//�԰����� �Ǫ����
        draw_ab();
        display_bat_end_dia(boss_map[b_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        break;
    }
    else
    {
        do_att=0;//���s�o�ʧ��� 
    }
     
    }
    draw_map(test);
    gotoxy(24,8);
    cout<<map_list[map_id].map_name;
}
void init_boss_ap_map()//��l��BOSS�X�{���a�� 
{
    for(int i=0;i<20;i++)
    {
        boss_ap_map[boss_map[i].ap_map]=i;
    }
}

int which_mon(int m)//�����Ǫ��X�{ ��Ƥ���J�a�Ͻs�� 
{
    int temp;//�����ü�
    temp=randl();
    if(mon_ap_op[m][0]>=temp)
    return mon_ap_map[m][0]; 
    else if(mon_ap_op[m][1]>=temp)
    return mon_ap_map[m][1]; 
    else if(mon_ap_op[m][2]>=temp)
    return mon_ap_map[m][2]; 
    else
    return 0;//�X�{���~ ��̧ܳC���ũǪ� 
} 
void init_mam()//��l��mon_ap_map
{
    int temp=0;
    for(int i=0;i<100;i++)
    {
        if(mon_map[i].hp==0)//��ID�Ǫ����إ�
        continue;
        else
        {
            for(int j=0;j<3&&mon_map[i].ap_map[j]!=NULL;j++)
            {
                while(mon_ap_op[mon_map[i].ap_map[j]][temp]>0)
                {
                    temp++;
                }
                mon_ap_map[mon_map[i].ap_map[j]][temp]=i;//�إߦ�ID�Ǫ��a�ϯ��� 
                if(temp==0)//�Ĥ@���Ǫ�
                {
                    mon_ap_op[mon_map[i].ap_map[j]][temp]=mon_map[i].ap_op[j];
                } 
                else
                {
                    mon_ap_op[mon_map[i].ap_map[j]][temp]=mon_map[i].ap_op[j]+mon_ap_op[mon_map[i].ap_map[j]][temp-1];
                }
            }
        }
        temp=0;
    } 
} 
void draw_battle_map()//�e�X�԰����� 
{
    Sleep(1000);//���e������@�� 
    system("cls");
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            gotoxy(j*2+10,i+5);
            if(bat_map[i][j]==0)
            cout<<"��";
            else if(bat_map[i][j]==6)
            cout<<"�@";
        }
    } 
}
void draw_mon_detail(int hp,int maxhp,int mp,int maxmp)//�e�X�԰��ɩǪ�����T 
{
    gotoxy(12,7);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(12,7);
    cout<<"HP:"<<hp<<"/"<<maxhp;
    gotoxy(12,8);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(12,8);
    cout<<"MP:"<<mp<<"/"<<maxmp;
}
void draw_player_detail()//�e�X�԰��ɪ��a���⪺��T 
{
    gotoxy(12,18);
    cout<<"Name:"<<player_list[who_is_play].p_name;
    gotoxy(32,18);
    cout<<"LV:"<<player_list[who_is_play].p_lv;
    gotoxy(12,19);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(12,19);
    cout<<"HP:"<<player_list[who_is_play].p_hp<<"/"<<player_list[who_is_play].p_maxhp;
    gotoxy(12,20);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
    gotoxy(12,20);
    cout<<"MP:"<<player_list[who_is_play].p_mp<<"/"<<player_list[who_is_play].p_maxmp;
}
void draw_battle_skill()//�e�X�԰��ɪ��ޯ��� 
{
    gotoxy(12,22);
    cout<<"��";
    if(player_list[who_is_play].skill_known[0]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[0])-1];
    gotoxy(24,22);
    cout<<"��";
    if(player_list[who_is_play].skill_known[1]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[1])-1];
    gotoxy(12,23);
    cout<<"��";
    if(player_list[who_is_play].skill_known[2]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[2])-1];
    gotoxy(24,23);
    cout<<"��";
    if(player_list[who_is_play].skill_known[3]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[3])-1];
    
} 

void display_battle(string s,int atp)//��ܾ԰����i
{
    int x=7,y=11,temp_key;
    gotoxy(x*2,y);
    for(int i=0;s[i]!=NULL;i++)
    {
        if(i%32==0)
        {
            y++;
            gotoxy(x*2,y);
        }
        cout<<s[i];
    }
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//���a�����UENTER 
    gotoxy(x*2,y+1);
    cout<<"�y���F"<<atp<<"�I�ˮ`";
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//���a�����UENTER 
}

int mon_ai()//�Ǫ�AI  0:���q����60% 1:�]�k����30%(�ݵ��]�O�O�_�����A�i����) 2:�k�]:10% 
{
    int temp;
    temp=randl();
    if(temp<=10)//�k�]
    return 4;
    else if(temp<=70)//���� 
    return 0;
    else if(temp<=100)//�]��
    return 1; 
}
int boss_ai(int r1,int r2,int r3,int r4,int r5)//BOSS_AI r1:�k�]���v r2:�ۦ��@...etc
{
    int temp;
    temp=randl();
    if(temp<=r1)//�k�]
    return 4;
    else if(temp<=r2)//���� 
    return 0;
    else if(temp<=r3)//�]��
    return 1;
    else if(temp<=r4)//���� 
    return 2;
    else
    return 3;
}  
void display_mon_battle(string s,int atp,int ai,string name)//��ܾ԰����i(�Ǫ���)�HAI�ǤJ�ȧP�_�g�X��س��i
{
    int x=7,y=11,temp_key;
    gotoxy(x*2,y);
    if(ai==0)//���q����
    {
        cout<<name<<"��ܼ���I�I";
        y++;
    }
    else if(ai==1)//�]�k����
    {
        cout<<name<<"�����@�ݡI�I";
        y++;
    }
    else if(ai==4)//�k�]
    {
        cout<<name<<"���ۧ��ڰk�]�F�C";
    }
    else if(ai==2)//���q����
    {
        cout<<name<<"��ܼ���I�I";
        y++;
    }
    else if(ai==3)//�]�k����
    {
        cout<<name<<"�����@�ݡI�I";
        y++;
    }
    do{
        temp_key=getch();
    }while(temp_key!=13);//���a�����UENTER
    if(ai!=4)
    { 
        gotoxy(x*2,y);
        for(int i=0;s[i]!=NULL;i++)
        {
            if(i%32==0)
            {
                y++;
                gotoxy(x*2,y);
            }
            cout<<s[i];
        }
        gotoxy(x*2,y+1);
        cout<<"�y���F"<<atp<<"�I�ˮ`";
        do{
            temp_key=getch();
        }while(temp_key!=13);//���a�����UENTER
    }
} 
void clear_bat_dia()//�M���e��
{
    for(int y=10;y<17;y++)
    {
        gotoxy(12,y);
        cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
    } 
} 
void display_bat_end_dia(string mon,string player,int key)//��ܾ԰����G 1���D����� 2���Ǫ���� 
{
    int temp_key;
    string s="";
    if(key==1)//�D�����      
    {
        s+=player;
        s+="�Q��~��A";
        s+=mon;
        s+="���˦b�a�A�Q���ѤF�I";
    }
    else if(key==2)//�Ǫ����
    {
        s+=mon;
        s+="�����j���A";
        s+=player;
        s+="���˦b�a�A�Q���ѤF�I";
    }
    int x=7,y=11;
    gotoxy(x*2,y);
    for(int i=0;s[i]!=NULL;i++)
    {
        if(i%32==0)
        {
            y++;
            gotoxy(x*2,y);
        }
        cout<<s[i];
    }
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//���a�����UENTER
    if(key==2)//�Ǫ���� 
    {
        clear_bat_dia(); 
        if(player_list[who_is_play].p_lv>1)
        {
            s="";
            s+=player_list[who_is_play].p_name;
            s+="���n�b�a�A������ʡA�s���@�n�A�G�D���šI";
            player_list[who_is_play].p_lv-=1;
            player_list[who_is_play].set_ab();            
        }
        else if(player_list[who_is_play].p_lv==1)
        {
            s="";
            s+=player_list[who_is_play].p_name;
            s+="���e�@�¡A������ʡA�f�R�ժj�A�˦a���_�I";
        }
        x=7;
        y=11;
        gotoxy(x*2,y);
        for(int i=0;s[i]!=NULL;i++)
        {
            if(i%32==0)
            {
                y++;
                gotoxy(x*2,y);
            }
            cout<<s[i];
        }
        draw_ab();
    }
} 
void check_lvup()//�P�_�O�_�ɯ�
{
    int temp_key;
    while(player_list[who_is_play].p_exp>=level_up_exp[player_list[who_is_play].p_lv])
    {
        player_list[who_is_play].p_exp-=level_up_exp[player_list[who_is_play].p_lv];
        player_list[who_is_play].p_lv++;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"�ɯŤF�I";
        player_list[who_is_play].set_ab();
        lv_turnon_event(player_list[who_is_play].p_lv);
        draw_ab();
        clear_bat_dia();
    } 
} 
void talk_to_npc(int m_id,int x,int y)//�MNPC��� �ѼƶǤJ�a��ID X�� Y��
{
    int temp_id,temp_x=10,temp_y=4,temp_key;
    for(int i=0;i<100;i++)//�}�l�j�MNPC
    {
        if(npc_list[i].at_map==m_id)//��ID��NPC�b���a��
        {
            if((npc_list[i].at_x==x)&&(npc_list[i].at_y==y))//�T�w�O��NPC
            {
                temp_id=i;
                break; 
            } 
        }
    }
    npc_list[temp_id].npc_check_event();//��NPC���ƥ�P�_
    if(npc_list[temp_id].npc_show==true)//���ɸ�NPC�i�H�Q���
    { 
        gotoxy(temp_x*2,temp_y);
        cout<<npc_list[temp_id].npc_name<<"�G";
        do{
           temp_key=getch();
        }while(temp_key!=13);//���a�����UENTER
        for(int i=0;npc_list[temp_id].npc_dia[npc_list[temp_id].npc_event][i]!=NULL;i++)//��X�P�_ 
        {
            if(i%16==0)
            {
                temp_y++;
                gotoxy(temp_x*2,temp_y);
            } 
            cout<<npc_list[temp_id].npc_dia[npc_list[temp_id].npc_event][i];
        }
        if(npc_list[temp_id].npc_talk_flag)
        {
            npc_list[temp_id].npc_change_event();
        }
        do{
           temp_key=getch();
        }while(temp_key!=13);//���a�����UENTER
        clear_npc_dia();
        npc_list[temp_id].next_chap();
        
    }
}
void clear_npc_dia()//�M��NPC��ܵe��
{
    int x=10,y=4;
    for(;y<10;y++)
    {
        gotoxy(x*2,y);
        cout<<"�@�@�@�@�@�@�@�@�@�@";
    }
}
int string_to_num(char temp)//�r���ഫ���ƭ�
{
    if(temp=='0')
    return 0;
    else if(temp=='1')
    return 1;
    else if(temp=='2')
    return 2;
    else if(temp=='3')
    return 3;
    else if(temp=='4')
    return 4;
    else if(temp=='5')
    return 5;
    else if(temp=='6')
    return 6;
    else if(temp=='7')
    return 7;
    else if(temp=='8')
    return 8;
    else if(temp=='9')
    return 9;
} 
void load_map()//���J�a��
{
    int tomap_id=map_id;//�����a�Ϫ��󤤪��}�C���ޭ�
    for(int i=0;i<5;i++)
    {
        if(map_list[map_id].map_to[i]==0)
        continue;//�٥��إ� i++ 
        if(map_list[map_id].map_to_atx[i]==myx)//X�y�ЭȬ۲�
        {
            if(map_list[map_id].map_to_aty[i]==myy)//Y�y�ЭȬ۲� �T�w�O�Ӷǰe�I 
            {
                tomap_id=map_list[map_id].map_to[i];//�����ӥؼЦa��ID
                break;//�����j�M ���X�j�� 
            }  
        } 
    }
    for(int i=0;i<5;i++)
    {
        if(map_list[tomap_id].map_to[i]==0)
        continue;
        if(map_list[tomap_id].map_to[i]==map_id)//���Ӷǰe�I�����}�C���ޭ�
        {
            myx=map_list[tomap_id].map_to_atx[i];
            myy=map_list[tomap_id].map_to_aty[i];
            break;//���� ���X�j�� 
        } 
    }
    for(int i=0,temp=0;map_list[tomap_id].map[i]!=NULL;i++)
    {
        if(map_list[tomap_id].map[i]==',')
        {
            test[temp/10][temp%10]=string_to_num(map_list[tomap_id].map[i-1]);
            temp++;
        }
    }
    draw_map(test);
    map_id=tomap_id;
    gotoxy(24,8);
    cout<<map_list[map_id].map_name;
}
void hp_helper()//�ɦ夤�߹�� 
{
    int temp_key;
    string s="";
    gotoxy(42,8);
    cout<<"�_�I�̤���:";
    gotoxy(42,9);
    cout<<"�аݻݭn�A�ȶܡH(Y/N)";
    temp_key=getch();
    gotoxy(42,9);
    cout<<"�@�@�@�@�@�@�@�@�@�@�@ ";
    if(temp_key==121||temp_key==13)//���UY
    { 
        gotoxy(42,9);
        cout<<"��~��~�������I";
        do{
            temp_key=getch(); 
        }while(temp_key!=13);//���a�����UENTER 
        for(int i=0;i<6;i++)//�^�_HP/MP 
        {
            player_list[i].p_hp=player_list[i].p_maxhp;
            player_list[i].p_mp=player_list[i].p_maxmp;
            }
        gotoxy(42,10);
        cout<<"HP/MP���w�g��_�A���z�C���r�֡I";
    }
    else
    {
        gotoxy(42,9);
        cout<<"�w��A�ץ��{�I";
    }
    do{
            temp_key=getch(); 
        }while(temp_key!=13);//���a�����UENTER
    draw_map(test);
}
void add_money(int temp_money)//�W�[���� 
{
    money +=temp_money;//�����Ҽ{������D 
}
void remove_money(int temp_money)//��֪���(�n���P�_��������) 
{
    money -=temp_money;//�����Ҽ{������D 
}
void add_item(int id,int count)
{
    itembox_list[id].num+=count;
}
bool check_money(int my,int price)
{
    if(my>=price)
    return true;
    else
    return false;
}
void saler_dia(int id)
{
    int x=21,y=9,temp_key,count=0;
    gotoxy(42,8);
    cout<<saler_list[id].saler_name<<":";
    for(int i=0;saler_list[id].sale_id[i]>0;i++)//�P�_����D�� 
    {
        gotoxy(x*2,y);
        cout<<item_list[saler_list[id].sale_id[i]].item_name<<":$"<<item_list[saler_list[id].sale_id[y-9]].item_price;
        y++;
        count++;
    }
    y=9;
    while(1)
    {
        gotoxy(42,6);
        cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
        gotoxy(42,6);
        cout<<item_list[saler_list[id].sale_id[y-9]].item_intr;
        gotoxy(x*2,y);
        temp_key=getch();
        //72:�W 80:�U
        if(temp_key==72)
        {
            if(y>9)
            {
                y--;
            }
        }
        else if(temp_key==80)
        {
            if(y-8!=count)
            {
                y++;
            }
        }
        else if(temp_key==13)//ENTER
        {
            gotoxy(42,6);
            cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
            if(check_money(money,item_list[saler_list[id].sale_id[y-9]].item_price))
            {
                remove_money(item_list[saler_list[id].sale_id[y-9]].item_price);
                add_item(saler_list[id].sale_id[y-9],1);
                gotoxy(42,6);
                cout<<"�ʶR�����I";
            }
            else
            {
                gotoxy(42,6);
                cout<<"�l�B����";
            }
            do{
                temp_key=getch(); 
            }while(temp_key!=13);//���a�����UENTER
            gotoxy(42,6);
                cout<<"�@�@�@�@�@";
        }
        else if(temp_key==27)//ESC 
        {
            break;
        }
    }
    system("cls");
    draw_map(test);
}
int money_drop_ai(int temp)//�������� 
{
    int sum;
    sum=temp+(temp*randl()/100);
    return sum;
}
int search_saler(int m_id,int x,int y)//�j�M�ӤHID
{
    int temp_id;
    for(int i=0;i<20;i++)//�}�l�j�MNPC
    {
        if(saler_list[i].at_map==m_id)//��ID��NPC�b���a��
        {
            if((saler_list[i].at_x==x)&&(saler_list[i].at_y==y))//�T�w�O��NPC
            {
                temp_id=i;
                break; 
            } 
        }
    }
    return temp_id;
} 
bool item_useful(int id)//�D��i�_�ϥ�
{
    if(item_list[id].item_category==3)
    return true;
    else
    return false;
}
void use_item(int id)
{
    if(item_list[id].item_category==3)
    {
        player_list[who_is_play].p_hp+=item_list[id].item_eff;
        if(player_list[who_is_play].p_hp>player_list[who_is_play].p_maxhp)
        {
            player_list[who_is_play].p_hp=player_list[who_is_play].p_maxhp;
        }
        gotoxy(42,6);
        cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
        gotoxy(42,6);
        cout<<"�ϥΧ����I";
    }
}
void show_itembox()//��ܭI�] 
{
    int temp_list[100],temp=0,x=21,y=9,temp_key;
    for(int i=0;i<100;i++)
    {
        if(itembox_list[i].num>0)
        {
            temp_list[temp]=i;
            temp++;
        }
    }
    for(int i=0;i<temp;i++)
    {
        gotoxy(x*2,y);
        cout<<item_list[temp_list[i]].item_name<<":"<<itembox_list[temp_list[i]].num;
        y++;
    }
    y=9;
    while(temp>0)
    {
        gotoxy(42,7);
        cout<<"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
        gotoxy(42,7);
        cout<<item_list[temp_list[y-9]].item_intr;
        gotoxy(x*2,y);
        temp_key=getch();
        //72:�W 80:�U
        if(temp_key==72)
        {
            if(y>9)
            {
                y--;
            }
        }
        else if(temp_key==80)
        {
            if(y-8!=temp)
            {
                y++;
            }
        }
        else if(temp_key==13)//ENTER
        {
            if(item_useful(temp_list[y-9]))//�D��i�H�ϥ� 
            {
                use_item(temp_list[y-9]);
                do{
                    temp_key=getch(); 
                }while(temp_key!=13);//���a�����UENTER
                itembox_list[temp_list[y-9]].num-=1;
                break;
            }
            else
            {
                
            }
        }
        else if(temp_key==27)//ESC 
        {
            break;
        }
    }
    system("cls");
    draw_map(test);
} 
void show_chap(string s)//��ܳ��` 
{
    int x=10,y=9,temp_key;
    system("cls");
    for(int i=0;s[i]!=NULL;i++)
    {
        if(i%32==0)
        {
            y++;
            gotoxy(x*2,y);
        }
        cout<<s[i];
    }
    do{
                    temp_key=getch(); 
    }while(temp_key!=13);//���a�����UENTER
    draw_map(test);
    if(section==change_chap[chap])
    {
        chap++;
        section=0;
        show_chap(chap_list[chap].story[section]);
    }
}
void lv_turnon_event(int lv)//�H���Ŷ}�Ҩƥ�(�ɯŮɦA�P�_�Y�i) 
{
    if(lv>=4)
    event[2]=true;//4�� 
} 

void item_turnon_event(int id)//�D��}�Ҩƥ�
{
    if(id==99)
    {event[9]=true;}
    if(id==98)
    {event[7]=true;}
}
