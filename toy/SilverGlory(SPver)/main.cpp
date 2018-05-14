#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include<conio.h>
using namespace std;
static bool event[1000]={false};//紀錄事件是否達成的陣列 預設1000件事件
static int money=0;//金錢
static int boss_ap_map[100];//[]裡填入地圖ID 其值為怪物ID 
static int chap=0,section=0;
void add_money(int temp_money);//增加金錢 
void lv_turnon_event(int lv);//以等級開啟事件(升級時再判斷即可) 
static int change_chap[6]={1,2,3,4,5,6};
void remove_money(int temp_money);//減少金錢(要先判斷錢夠不夠)
void item_turnon_event(int id);//道具開啟事件
class map//地圖類別
{
public:
    int map_id;
    string map;
    int map_to[5];//紀錄傳送點會到的地圖ID
    int map_to_atx[5];//紀錄傳送點的X座標
    int map_to_aty[5];//紀錄傳送點的y座標
    string map_name;//地圖名稱
};
class boss
{
public:
    int lv,hp,mp,exp,ap_map,at_po,de_po;//ap_map:出現地圖
    string name;
    string boss_sk_name[4];//紀錄怪物招式名稱 
    int boss_skill[4];//紀錄加乘倍數
    int skill_temp[5];//四個招式的出招機率 含逃跑
    int drop_money;
    int drop_item;//紀錄掉落道具ID 
    bool boss_show;
    int boss_event_key;//開啟BOSS所需的事件
};
class saler
{
public:
    int sale_id[10];//最多販賣10種不同類型的道具
    int at_map;//記錄NPC所在的地圖 ID(地圖ID從1開始)
    int at_x;//NPC位於那張地圖的x座標 
    int at_y;//NPC位於那張地圖的y座標
    string saler_greet;//商人的招呼用語 
    string saler_name;
};
class chapter
{
public:
    int section[10];//記錄第幾節 
    string story[10];//紀錄章節說明 
};
class itm //道具類別
{
public:
    int item_category;//物品種類1:武器 2:防具 3:藥水(+HP) 4:藥水(+MP) 5:藥水(+HP&+MP) 6:藥水(+HP&+MP)(%) 7:復活藥水 8...待建立
    int item_eff;//物品效果
    int item_price;
    string item_name;
    string item_intr;//物品介紹
};
class monster//怪物類別
{
public:
    int lv,hp,mp,exp,ap_map[3],at_po,de_po,ap_op[3];//ap_map:出現地圖 ap_op:出現機率 
    string name;
    string mon_sk_name[2];//紀錄怪物招式名稱 
    int mon_skill[2];//紀錄加乘倍數
    int drop_money;
};
int money_drop_ai(int temp);
class player//玩家類別(遊戲擴充用)
{
public:
    int p_lv,p_hp,p_mp,p_exp,p_str,p_int,p_dex,p_luk,p_pro,p_att,p_maxhp,p_maxmp;//pro:職業
    void set_ab()
    {
        p_hp=(p_lv-1)*20+50;//血量
        p_mp=(p_lv-1)*10+50;//魔力
        p_str=(p_lv-1)*3+4;//力量 
        p_dex=4;//敏捷
        p_luk=4;//幸運
        p_int=4;//智力    
        p_att=(p_lv-1)*5+p_str*3+5;//攻擊力 
        p_maxhp=p_hp;
        p_maxmp=p_mp;
    }
    string p_name;
    int skill_known[4];//紀錄會的招式ID
};
int search_saler(int m_id,int x,int y);//搜尋商人ID 
void load_map();//載入地圖
bool item_useful(int id);//道具可否使用
void check_npc_event();//確認NPC相關參數 
void check_lvup();//判斷是否升級 
void draw_battle_map();//畫出戰鬥介面
void clear_bat_dia();//清除戰鬥畫面
void clear_npc_dia();//清除NPC對話畫面
int boss_ai(int r1,int r2,int r3,int r4,int r5);//BOSS_AI r1:逃跑機率 r2:招式一...etc
void display_bat_end_dia(string mon,string player,int key);//顯示戰鬥結果 1為主角獲勝 2為怪物獲勝 
void display_mon_battle(string s,int atp,int ai,string name);//顯示戰鬥報告(怪物用)以AI傳入值判斷寫出何種報告 
void display_battle(string s,int atp);//顯示戰鬥報告
void draw_mon_detail(int hp,int maxhp,int mp,int maxmp);//畫出戰鬥時怪物的資訊 
void draw_player_detail();//畫出戰鬥時玩家角色的資訊
void draw_battle_skill();//畫出戰鬥時的技能選擇 
void use_item(int id);//使用道具 
int mon_ai();//怪物AI  0:普通攻擊60% 1:魔法攻擊30%(需視魔力是否足夠，進階用) 2:逃跑:10% 
void init_boss_ap_map();//初始化BOSS出現的地圖 
static int bat_map[20][20]=//戰鬥介面陣列(20*20)
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
chapter chap_list[6];//章節 章 
void talk_to_npc(int m_id,int x,int y);//和NPC對話 參數傳入地圖ID X值 Y值
int string_to_num(char temp);//字串轉換成數值 
static int skill[5][10];//技能加成倍數存放陣列
static string sk_name[5][10];//技能名稱
int item[100];//暫定
//注意：地圖編號由1開始，意即[0][]的陣列沒有使用(以後可做修改) 
int mon_ap_map[100][3];//怪物出現地圖索引
int mon_ap_op[100][3];//怪物出線機率索引(計算用) 
void init_mam();//初始化mon_ap_map
void b_battle(int b_id);
void draw_map(int temp[10][10]);//初始畫圖 
void gotoxy(int xpos, int ypos);//移動座標
int randl();//亂數 
int bat_hap();//是否發生戰鬥 
int which_mon(int m);//哪隻怪物出現 函數內輸入地圖編號 
void draw_go(int x,int y,int thing);//移動之後畫圖 
void draw_ab();//顯示角色素質
void draw_map(int m_id);//畫出地圖 
void battle(int m_id);//戰鬥計算 函數裡面輸入怪物ID
static int myx=1,myy=1,map_id=1,who_is_play=0;//玩家角色(x,y)位置，玩家所在地圖，玩家使用哪隻角色 
static int level_up_exp[100];
static string my_name="新玩家";
bool check_money(int my,int price);
static int test[10][10];//繪製地圖
void hp_helper();//補血中心對話 
void show_chap(string s);//顯示章節 
player player_list[6];//建立玩家角色物件(最多允許6種角色)
class npc//NPC 類別
{
public:
    int at_map;//記錄NPC所在的地圖 ID(地圖ID從1開始)
    int at_x;//NPC位於那張地圖的x座標 
    int at_y;//NPC位於那張地圖的y座標
    int npc_event;//紀錄NPC的事件(用於顯示對話) 一開始為0 
    string npc_name;//NPC的名字
    string npc_dia[3];//NPC對話
    int npc_event_key[3];//紀錄NPC進入下一階段的關鍵事件 npc_event_key[0]和[1]用來判斷進入下一階段 [2]用來判斷是否讓該NPC顯示 
    //如果是用等級判斷的話，其值為條件等級 
    int npc_turnon_event[3];//紀錄NPC各階段對話會解鎖的事件
    int npc_category;//紀錄NPC種類 1:對話轉變 2:事件轉變 3:事件改變(會影響章節) 4:選項改變(影響事件) 5:特殊存在 
    bool npc_show;//紀錄是否要出現
    bool npc_lv_flag;//該NPC是以LV來轉換對話true是,false否
    bool npc_talk_flag;//該NPC是以講話來轉換對話true是,false否 如果此值為true則不需做npc_check_event判斷 
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
    void npc_check_event()//確認是否達成該NPC所需事件，以進入下一階段的任務 
    {
        if(npc_lv_flag)
        {
            if(npc_show==false)//該NPC被封鎖
            {
                if(player_list[who_is_play].p_lv>=npc_event_key[2])//達成解鎖等級
                {
                     npc_show=true;
                     event[npc_turnon_event[npc_event]]=true;//打開事件
                }   
            }
            else 
            {
                if(player_list[who_is_play].p_lv>=npc_event_key[npc_event])//達成解鎖等級
                {
                     if(npc_event<2)//不會超過陣列上限 
                     npc_event++;
                     event[npc_turnon_event[npc_event]]=true;//打開事件
                }
            }
        }
        else if(npc_talk_flag==false)//該NPC是用事件改變事件 
        {
            if(npc_show==false)//該NPC被封鎖
            {
                if(event[npc_event_key[2]]==true)//讓該NPC顯示的前置事件已滿足 
                {
                    npc_show=true;
                    event[npc_turnon_event[npc_event]]=true;//打開事件
                } 
            }
            else
            {
                if(event[npc_event_key[npc_event]]==true)//進入下一階段的前置事件已滿足
                {
                    if(npc_event<2)//不會超過陣列上限 
                    npc_event++;
                    event[npc_turnon_event[npc_event]]=true;//打開事件             
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
//建立各種物件
monster mon_map[100];//建立怪物物件(預設陣列100) 
npc npc_list[100];//建立NPC物件 
map map_list[100];//建立地圖物件
itm item_list[100];//建立道具物件
itembox itembox_list[100];//建立我的物品箱
saler saler_list[20];
boss boss_map[20];
void add_item(itm *temp,int count);//增加物品
void saler_dia(int id);
void show_itembox();//顯示背包 
int main(int argc, char *argv[])
{
    event[0]=true;
    level_up_exp[1]=10;//設定等級提升初始 
    for(int i=2;i<100;i++)
    {
        level_up_exp[i]=level_up_exp[i-1]*1.5;
    }
    int key;//鍵值紀錄
    //以下是最初角色初始 
    player_list[0].p_lv=1;
    player_list[0].p_exp=0;
    player_list[0].p_pro=0;
    player_list[0].set_ab();
    player_list[0].p_name="馴獸師";
    player_list[0].skill_known[0]=1;//一開始會的技能ID
    player_list[0].skill_known[1]=2;//一開始會的技能ID
    player_list[0].skill_known[2]=3;//一開始會的技能ID
    player_list[0].skill_known[3]=4;//一開始會的技能ID
    
    //以下是技能初始
    //主角技能: 
    skill[0][0]=100;//攻擊加成(戰鬥計算用)100=100% 
    sk_name[0][0]="鞭打";//ID:1 第一招
    skill[0][1]=110;//攻擊加成(戰鬥計算用)100=100% 
    sk_name[0][1]="火烤";//ID:1 第二招 
    skill[0][2]=120;//攻擊加成(戰鬥計算用)100=100% 
    sk_name[0][2]="水煮";//ID:1 第三招 
    skill[0][3]=130;//攻擊加成(戰鬥計算用)100=100% 
    sk_name[0][3]="親親";//ID:1 第四招 
    //以下是各式函數初始化  
    //BOSS
    boss_map[0].boss_event_key=891;//需要事件6完成才能顯示
    boss_map[0].boss_show=false; 
    
    boss_map[1].lv=10;
    boss_map[1].hp=199;
    boss_map[1].mp=0;
    boss_map[1].exp=3210;
    boss_map[1].ap_map=1;
    boss_map[1].at_po=50;
    boss_map[1].de_po=2;
    boss_map[1].name="巨大化的猩猩";
    boss_map[1].boss_sk_name[0]="猩猩放屁";
    boss_map[1].boss_skill[0]=100;
    boss_map[1].boss_sk_name[1]="猩猩頭槌";
    boss_map[1].boss_skill[1]=140;
    boss_map[1].boss_sk_name[2]="猩猩哭泣";
    boss_map[1].boss_skill[2]=190;
    boss_map[1].boss_sk_name[3]="猩猩放屁MAX！";
    boss_map[1].boss_skill[3]=300;
    boss_map[1].drop_money=1234;//掉落金錢
    boss_map[1].drop_item=99;//ID:99道具
    boss_map[1].skill_temp[0]=5;//逃跑機率 
    boss_map[1].skill_temp[1]=30;
    boss_map[1].skill_temp[2]=60;
    boss_map[1].skill_temp[3]=90;
    boss_map[1].skill_temp[4]=100;
    boss_map[1].boss_event_key=6;//需要事件7完成才能顯示
    boss_map[1].boss_show=false; 
     
    boss_map[2].lv=8;
    boss_map[2].hp=99;
    boss_map[2].mp=0;
    boss_map[2].exp=310;
    boss_map[2].ap_map=2;
    boss_map[2].at_po=30;
    boss_map[2].de_po=2;
    boss_map[2].name="變態小小猩猩";
    boss_map[2].boss_sk_name[0]="小猩猩噴射火焰屁";
    boss_map[2].boss_skill[0]=100;
    boss_map[2].boss_sk_name[1]="小猩猩飛撲";
    boss_map[2].boss_skill[1]=140;
    boss_map[2].boss_sk_name[2]="小猩猩大吼";
    boss_map[2].boss_skill[2]=190;
    boss_map[2].boss_sk_name[3]="小猩猩放屁MAX";
    boss_map[2].boss_skill[3]=300;
    boss_map[2].drop_money=334;//掉落金錢
    boss_map[2].drop_item=98;//ID:98道具
    boss_map[2].skill_temp[0]=5;//逃跑機率 
    boss_map[2].skill_temp[1]=30;
    boss_map[2].skill_temp[2]=60;
    boss_map[2].skill_temp[3]=90;
    boss_map[2].skill_temp[4]=100;
    boss_map[2].boss_event_key=5;//需要事件5完成才能顯示
    boss_map[2].boss_show=false; 
    
    //怪物圖鑑No.001 Name:小火球 LV:1 Hp:20 Mp:0 Exp:4 ap_map[0]=1 at_po=5 de_po=2
    mon_map[0].lv=1;
    mon_map[0].hp=20;
    mon_map[0].mp=0;
    mon_map[0].exp=600;
    mon_map[0].ap_map[0]=1;
    mon_map[0].at_po=5;
    mon_map[0].de_po=2;
    mon_map[0].name="小猩猩";
    mon_map[0].ap_op[0]=40;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[0].mon_sk_name[0]="脫褲子(羞)";
    mon_map[0].mon_skill[0]=100;
    mon_map[0].mon_sk_name[1]="猩猩之鐵拳";
    mon_map[0].mon_skill[1]=300;
    mon_map[0].drop_money=10;//掉落金錢
    
    //怪物圖鑑No.002 Name:小石球 LV:1 Hp:20 Mp:0 Exp:4 ap_map[0]=1 at_po=2 de_po=5
    mon_map[1].lv=1;
    mon_map[1].hp=20;
    mon_map[1].mp=0;
    mon_map[1].exp=600;
    mon_map[1].ap_map[0]=1;
    mon_map[1].at_po=2;
    mon_map[1].de_po=5;
    mon_map[1].name="小石球";
    mon_map[1].mon_sk_name[0]="石球";
    mon_map[1].mon_skill[0]=100;
    mon_map[1].mon_sk_name[1]="天崩地裂無限輪迴";
    mon_map[1].mon_skill[1]=300;
    mon_map[1].ap_op[0]=40;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[1].drop_money=10;//掉落金錢 
    
    //怪物圖鑑No.003 Name:小魔王 LV:50 Hp:20000 Mp:2000 Exp:4444 ap_map[0]=1 at_po=2 de_po=5
    mon_map[2].lv=50;
    mon_map[2].hp=20000;
    mon_map[2].mp=2000;
    mon_map[2].exp=4444444;
    mon_map[2].ap_map[0]=1;
    mon_map[2].at_po=500;
    mon_map[2].de_po=500;
    mon_map[2].name="小魔王";
    mon_map[2].mon_sk_name[0]="魔王咆哮";
    mon_map[2].mon_skill[0]=110;
    mon_map[2].mon_sk_name[1]="魔王亂舞之天魔解體";
    mon_map[2].mon_skill[1]=5000;
    mon_map[2].ap_op[0]=20;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[2].drop_money=99999;//掉落金錢 
    
     //怪物圖鑑No.004 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[3].lv=5;
    mon_map[3].hp=400;
    mon_map[3].mp=20;
    mon_map[3].exp=100;
    mon_map[3].ap_map[0]=2;
    mon_map[3].at_po=30;
    mon_map[3].de_po=5;
    mon_map[3].name="SmallZergT";
    mon_map[3].mon_sk_name[0]="SM哀號";
    mon_map[3].mon_skill[0]=120;
    mon_map[3].mon_sk_name[1]="SM教官無影腳";
    mon_map[3].mon_skill[1]=200;
    mon_map[3].ap_op[0]=70;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[3].drop_money=160;//掉落金錢 
    
     //怪物圖鑑No.005 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[4].lv=8;
    mon_map[4].hp=600;
    mon_map[4].mp=120;
    mon_map[4].exp=400;
    mon_map[4].ap_map[0]=2;
    mon_map[4].at_po=40;
    mon_map[4].de_po=5;
    mon_map[4].name="鑽石SmallZergT";
    mon_map[4].mon_sk_name[0]="鑽石SM哀號";
    mon_map[4].mon_skill[0]=100;
    mon_map[4].mon_sk_name[1]="鑽石SM教官無影腳";
    mon_map[4].mon_skill[1]=200;
    mon_map[4].ap_op[0]=30;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[4].drop_money=240;//掉落金錢 
    
     //怪物圖鑑No.006 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[5].lv=10;
    mon_map[5].hp=800;
    mon_map[5].mp=100;
    mon_map[5].exp=600;
    mon_map[5].ap_map[0]=3;
    mon_map[5].at_po=50;
    mon_map[5].de_po=5;
    mon_map[5].name="衣冠整齊的浪人";
    mon_map[5].mon_sk_name[0]="浪人丟砂鍋";
    mon_map[5].mon_skill[0]=150;
    mon_map[5].mon_sk_name[1]="神劍闖江湖";
    mon_map[5].mon_skill[1]=250;
    mon_map[5].ap_op[0]=80;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[5].drop_money=300;//掉落金錢 
    
     //怪物圖鑑No.006 Name:SmallZergT LV:5 Hp:200 Mp:20 Exp:100 ap_map[0]=2 at_po=30 de_po=5
    mon_map[6].lv=20;
    mon_map[6].hp=5000;
    mon_map[6].mp=1000;
    mon_map[6].exp=1600;
    mon_map[6].ap_map[0]=3;
    mon_map[6].at_po=70;
    mon_map[6].de_po=5;
    mon_map[6].name="邪惡的脫衣猩猩";
    mon_map[6].mon_sk_name[0]="猩猩飛撲~";
    mon_map[6].mon_skill[0]=200;
    mon_map[6].mon_sk_name[1]="猩猩脫衣~";
    mon_map[6].mon_skill[1]=2000;
    mon_map[6].ap_op[0]=20;//出現在陣列ap_map[0]地圖的機率為80%
    mon_map[6].drop_money=1400;//掉落金錢 
    //以下是NPC初始
    npc_list[0].npc_name="高級馴獸師";
    npc_list[0].at_map=1;
    npc_list[0].at_x=1;
    npc_list[0].at_y=2;
    npc_list[0].npc_event=0;
    npc_list[0].npc_show=false;
    npc_list[0].npc_dia[0]="想獲得我的認同請先練習到4等吧！";
    npc_list[0].npc_dia[1]="呼，小屁孩你終於4等了嗎？聽說前方地圖有人正在哭泣，請去找她對話吧！";
    npc_list[0].npc_dia[2]="網路安全需要你我來維護！最近出現了一隻俠盜怪獸，請幫忙去消滅它！";
    npc_list[0].npc_talk_flag=false;//該NPC是否是以對話來作事件判斷 是的話即不須設定npc_event_key的初始值 
    npc_list[0].npc_event_key[0]=2;//要讓該NPC進入第二事件對話需要完成event[2]
    npc_list[0].npc_event_key[1]=7;//要讓該NPC進入第三事件對話需要完成event[3] 
    npc_list[0].npc_event_key[2]=1;//要顯示該NPC需要完成event[1]
    npc_list[0].npc_turnon_event[1]=3;//完成事件2之後打開event[3]
    npc_list[0].npc_turnon_event[2]=6;//完成事件3之後打開event[6]
    npc_list[0].npc_lv_flag=false;//該NPC是否是以等級作事件判斷
    
    /*
    npc_list[0].npc_talk_flag=false;//該NPC是否是以對話來作事件判斷 是的話即不須設定npc_event_key的初始值 
    npc_list[0].npc_event_key[0]=1;//要讓該NPC進入第二事件對話需要角色3等 
    npc_list[0].npc_event_key[1]=4;//要讓該NPC進入第二事件對話需要角色4等 
    npc_list[0].npc_event_key[2]=1;//要顯示該NPC需要角色2等 
    npc_list[0].npc_lv_flag=false;//該NPC是否是以等級作事件判斷
    npc_list[0].npc_turnon_event[2]=1;//完成事件三之後打開event[1] 
    */
    npc_list[1].npc_name="鬼祟的脫衣猩猩";
    npc_list[1].at_map=2;
    npc_list[1].at_x=2;
    npc_list[1].at_y=5;
    npc_list[1].npc_event=0;
    npc_list[1].npc_show=true;
    npc_list[1].npc_dia[0]="嘿嘿^^";
    npc_list[1].npc_dia[1]="你要看看嗎？";
    npc_list[1].npc_dia[2]="嗚嗚，你真是壞蛋 　　>///<";
    npc_list[1].npc_talk_flag=true;//該NPC是否是以對話來作事件判斷 是的話即不須設定npc_event_key的初始值
    npc_list[1].npc_lv_flag=false;//該NPC是否是以等級作事件判斷
    
    npc_list[2].npc_name="瑪雅";
    npc_list[2].at_map=3;
    npc_list[2].at_x=8;
    npc_list[2].at_y=8;
    npc_list[2].npc_event=0;
    npc_list[2].npc_show=false;
    npc_list[2].npc_dia[0]="嗚嗚，我有東西被猩猩偷走了......";
    npc_list[2].npc_dia[1]="請幫我解決出沒在草叢的猩猩！奪回我的道具！";
    npc_list[2].npc_dia[2]="謝謝你幫我解決變態猩猩^^";
    npc_list[2].npc_talk_flag=false;//該NPC是否是以對話來作事件判斷 是的話即不須設定npc_event_key的初始值 
    npc_list[2].npc_event_key[0]=4;//要讓該NPC進入第二事件對話需要完成event[2] 
    npc_list[2].npc_event_key[1]=7;//要讓該NPC進入第三事件對話需要完成event[7] 
    npc_list[2].npc_event_key[2]=3;//要顯示該NPC需要完成event[1]
    npc_list[2].npc_turnon_event[0]=4;//完成事件一之後打開event[2]
    npc_list[2].npc_turnon_event[1]=5;//完成事件2之後打開event[5]
    npc_list[2].npc_turnon_event[2]=7;//完成事件2之後打開event[5]
    npc_list[2].npc_lv_flag=false;//該NPC是否是以等級作事件判斷
    
    npc_list[3].npc_name="新手導引者";
    npc_list[3].at_map=1;
    npc_list[3].at_x=8;
    npc_list[3].at_y=1;
    npc_list[3].npc_event=0;
    npc_list[3].npc_category=3;
    npc_list[3].npc_show=false;
    npc_list[3].npc_dia[0]="歡迎來到資訊爆炸的樂園！";
    npc_list[3].npc_dia[1]="聽說左方有一位教官，請去找他尋求協助^^";
    npc_list[3].npc_dia[2]="恭喜您完成了這章節的主線任務，現在將您傳送到下一章節地圖，您可以使用時空之門重新回到此關卡進行尚未破解的隱藏任務！";
    npc_list[3].npc_talk_flag=false;//該NPC是否是以對話來作事件判斷 是的話即不須設定npc_event_key的初始值 
    npc_list[3].npc_event_key[0]=0;//要讓該NPC進入第二事件對話需要完成event[0]
    npc_list[3].npc_event_key[1]=9;//要讓該NPC進入第三事件對話需要完成event[3] 
    npc_list[3].npc_event_key[2]=0;//要顯示該NPC需要完成event[1]
    npc_list[3].npc_turnon_event[1]=1;//完成事件一之後打開event[1]
    npc_list[3].npc_lv_flag=false;//該NPC是否是以等級作事件判斷
    //以下是地圖資料初始
    //MAP:1
    map_list[1].map_id=1;//ID 1的地圖存放在陣列map_list[1]
    map_list[1].map="";//準備開始擺放陣列
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
    map_list[1].map_to[0]=2;//到ID 2的傳送點
    map_list[1].map_to_atx[0]=8;//此傳送點位於此地圖X座標
    map_list[1].map_to_aty[0]=8;//此傳送點位於此地圖Y座標
    map_list[1].map_to[1]=3;//到ID 2的傳送點
    map_list[1].map_to_atx[1]=1;//此傳送點位於此地圖X座標
    map_list[1].map_to_aty[1]=8;//此傳送點位於此地圖Y座標
    map_list[1].map_to[2]=4;//到ID 4的傳送點
    map_list[1].map_to_atx[2]=3;//此傳送點位於此地圖X座標
    map_list[1].map_to_aty[2]=5;//此傳送點位於此地圖Y座標
    map_list[1].map_to[3]=5;//到ID 4的傳送點
    map_list[1].map_to_atx[3]=7;//此傳送點位於此地圖X座標
    map_list[1].map_to_aty[3]=6;//此傳送點位於此地圖Y座標
    map_list[1].map_name="迷惑的分叉道";
    
    //MAP:2
    map_list[2].map_id=2;//ID 1的地圖存放在陣列map_list[1]
    map_list[2].map="";//準備開始擺放陣列
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
    map_list[2].map_to[0]=1;//到ID 2的傳送點
    map_list[2].map_to_atx[0]=1;//此傳送點位於此地圖X座標
    map_list[2].map_to_aty[0]=8;//此傳送點位於此地圖Y座標
    map_list[2].map_name="神秘的小道";
    
    //MAP:3
    map_list[3].map_id=3;//ID 1的地圖存放在陣列map_list[1]
    map_list[3].map="";//準備開始擺放陣列
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
    map_list[3].map_to[0]=1;//到MAP_ID:1的傳送點
    map_list[3].map_to_atx[0]=1;//此傳送點位於此地圖X座標
    map_list[3].map_to_aty[0]=1;//此傳送點位於此地圖Y座標
    map_list[3].map_name="黑暗的森林";
    
    //MAP:4
    map_list[4].map_id=4;//ID 1的地圖存放在陣列map_list[1]
    map_list[4].map="";//準備開始擺放陣列
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
    map_list[4].map_to[0]=1;//到MAP_ID:1的傳送點
    map_list[4].map_to_atx[0]=5;//此傳送點位於此地圖X座標
    map_list[4].map_to_aty[0]=8;//此傳送點位於此地圖Y座標
    map_list[4].map_name="補給站";
    
    //MAP:5
    map_list[5].map_id=4;//ID 1的地圖存放在陣列map_list[1]
    map_list[5].map="";//準備開始擺放陣列
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
    map_list[5].map_to[0]=1;//到MAP_ID:1的傳送點
    map_list[5].map_to_atx[0]=5;//此傳送點位於此地圖X座標
    map_list[5].map_to_aty[0]=8;//此傳送點位於此地圖Y座標
    map_list[5].map_name="秘密基地";
    
    //建立各式ITEM
    
    item_list[1].item_category=3;
    item_list[1].item_eff=50;
    item_list[1].item_name="紅藥丸";
    item_list[1].item_intr="恢復HP50點";
    item_list[1].item_price=100;
    
    item_list[2].item_category=3;
    item_list[2].item_eff=150;
    item_list[2].item_name="紅藥水";
    item_list[2].item_intr="恢復HP150點";
    item_list[2].item_price=230;
    
    item_list[3].item_category=3;
    item_list[3].item_eff=300;
    item_list[3].item_name="大補帖";
    item_list[3].item_intr="恢復HP300點";
    item_list[3].item_price=400;
    
    item_list[41].item_category=8;
    item_list[41].item_eff=300;
    item_list[41].item_name="神秘的鐵盒";
    item_list[41].item_intr="看不清楚裡面的內容";
    item_list[41].item_price=9999;
    
    item_list[42].item_category=8;
    item_list[42].item_eff=300;
    item_list[42].item_name="SM教官的破舊綠色球鞋";
    item_list[42].item_intr="似乎沒有紀念價值";
    item_list[42].item_price=44;
    
    item_list[98].item_category=8;
    item_list[98].item_eff=300;
    item_list[98].item_name="打敗猩猩的證明";
    item_list[98].item_intr="可惡的猩猩被打敗了！";
    item_list[98].item_price=44;
    
    item_list[99].item_category=8;
    item_list[99].item_eff=300;
    item_list[99].item_name="隨身碟";
    item_list[99].item_intr="紀錄著機密檔案";
    item_list[99].item_price=0;
    //建立商人
    saler_list[0].saler_name="迷糊的蒙古大夫";
    saler_list[0].saler_greet="咦？我的藥丸呢？";
    saler_list[0].sale_id[0]=1;//賣道具ID1:紅藥丸 
    saler_list[0].sale_id[1]=2;//賣道具ID1:紅藥丸 
    saler_list[0].sale_id[2]=3;//賣道具ID1:紅藥丸 
    saler_list[0].at_map=4;
    saler_list[0].at_x=2;
    saler_list[0].at_y=2;
    
    saler_list[1].saler_name="神秘蒙面男子";
    saler_list[1].saler_greet="東西自己看，不要打擾我！";
    saler_list[1].sale_id[0]=41;//賣道具ID1:紅藥丸 
    saler_list[1].sale_id[1]=42;//賣道具ID1:紅藥丸 
    saler_list[1].at_map=4;
    saler_list[1].at_x=7;
    saler_list[1].at_y=2;
    
    chap_list[0].story[0]="小明從小生活在純樸平靜的小鎮，從來都沒有接觸過現代的快速生活，有一天，他因緣際會下來到了資訊爆炸的城市...";
    chap_list[0].story[1]="恭喜您完成本章節【電腦安全】，小明吸收了知識之後想要更上層樓，於是他進入了伊索匹斯內亞的一間軟體公司上班...";
    chap_list[1].story[0]="小明！小明起床啦！嘟嘟嘟，嘟嘟嘟！";
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
        cout<<"＠";
        gotoxy(20,25);
        key=getch();
        gotoxy(10,8);
        cout<<" 　　　　　";
        if(key==72)//上 
        {
            if(test[myy-1][myx]==1)//進入草地，準備戰鬥運算 
            { 
                draw_go(myx,myy,test[myy][myx]);//清出前一格
                myy -=1;
                if(bat_hap()==1)//普通小兵 
                {
                    gotoxy(10,8);
                    cout<<"發生戰鬥了！";
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
                        cout<<"發生戰鬥了！";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy-1][myx]==6)//空白走道 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy -=1;
            }
            else if(test[myy-1][myx]==3)//遇見NPC 
            {
                talk_to_npc(map_id,myx,myy-1);
            }
            else if(test[myy-1][myx]==5)//遇見傳送點 
            {
                myy -=1;
                load_map();
            }
            else if(test[myy-1][myx]==8)//遇見冒險者中心 
            {
                hp_helper();
            }
            else if(test[myy-1][myx]==7)//遇見商店 
            {
                saler_dia(search_saler(map_id,myx,myy-1));
            }
            
        }
        else if(key==80)//下 
        {
            if(test[myy+1][myx]==1)//進入草地，準備戰鬥運算 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy +=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"發生戰鬥了！";
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
                        cout<<"發生戰鬥了！";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy+1][myx]==6)//空白走道 
            {
                draw_go(myx,myy,test[myy][myx]);
                myy +=1;
            }
            else if(test[myy+1][myx]==3)//遇見NPC 
            {
                talk_to_npc(map_id,myx,myy+1);
            }
            else if(test[myy+1][myx]==5)//遇見傳送點 
            {
                myy +=1;
                load_map();
            }
            else if(test[myy+1][myx]==8)//遇見冒險者中心 
            {
                hp_helper();
            }
            else if(test[myy+1][myx]==7)//遇見商店 
            {
                saler_dia(search_saler(map_id,myx,myy+1));
            }
        }
        else if(key==75)//左 
        {
            if(test[myy][myx-1]==1)//進入草地，準備戰鬥運算 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx -=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"發生戰鬥了！";
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
                        cout<<"發生戰鬥了！";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy][myx-1]==6)//空白走道 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx -=1;
            }
            else if(test[myy][myx-1]==3)//遇見NPC 
            {
                talk_to_npc(map_id,myx-1,myy);
            }
            else if(test[myy][myx-1]==5)//遇見傳送點 
            {
                myx -=1;
                load_map();
            }
            else if(test[myy][myx-1]==8)//遇見冒險者中心 
            {
                hp_helper();
            }
            else if(test[myy][myx-1]==7)//遇見商店 
            {
                saler_dia(search_saler(map_id,myx-1,myy));
            }
        }
        else if(key==77)//右 
        {
            if(test[myy][myx+1]==1)//進入草地，準備戰鬥運算 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx +=1;
                if(bat_hap()==1)
                {
                    gotoxy(10,8);
                    cout<<"發生戰鬥了！";
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
                        cout<<"發生戰鬥了！";
                        draw_battle_map();
                        b_battle(boss_ap_map[map_id]);
                    }
                }
            }
            else if(test[myy][myx+1]==6)//空白走道 
            {
                draw_go(myx,myy,test[myy][myx]);
                myx +=1;
            }
            else if(test[myy][myx+1]==3)//遇見NPC 
            {
                talk_to_npc(map_id,myx+1,myy);
            }
            else if(test[myy][myx+1]==5)//遇見傳送點 
            {
                myx +=1;
                load_map();
            }
            else if(test[myy][myx+1]==8)//遇見冒險者中心 
            {
                hp_helper();
            }
            else if(test[myy][myx+1]==7)//遇見商店
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
    cout<<"GAME OVER！！";
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
            cout<<"˙";
            else if(temp[i][j]==1)
            cout<<"＊";
            else if(temp[i][j]==2)
            cout<<"●";
            else if(temp[i][j]==3)
            cout<<"※";
            else if(temp[i][j]==4)
            cout<<"口";
            else if(temp[i][j]==5)
            cout<<"◎";
            else if(temp[i][j]==6)
            cout<<"　";
            else if(temp[i][j]==7)
            cout<<"＄";
            else if(temp[i][j]==8)
            cout<<"┼";
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
    cout<<"＊";
    else if(thing==6)
    cout<<"　";
    else if(thing==5)
    cout<<"◎";
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
    if(temp<=15)//發生戰鬥回傳1，反之回傳0 
    return 1;
    else if(temp<=59)//BOSS 4%機率 
    return 2;
    else
    return 0;
}
void draw_ab()
{
    int temp_key;
    gotoxy(50,10);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,10);
    cout<<"LV:"<<player_list[who_is_play].p_lv;
    gotoxy(50,12);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,12);
    cout<<"HP:"<<player_list[who_is_play].p_hp<<"/"<<player_list[who_is_play].p_maxhp;
    gotoxy(50,14);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,14);
    cout<<"MP:"<<player_list[who_is_play].p_mp<<"/"<<player_list[who_is_play].p_maxmp;
    gotoxy(50,16);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,16);
    cout<<"EXP:"<<player_list[who_is_play].p_exp<<"/"<<level_up_exp[player_list[who_is_play].p_lv];
    gotoxy(50,18);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,18);
    cout<<"攻擊力:"<<player_list[who_is_play].p_att;
    gotoxy(50,20);
    cout<<"　　　　　　　　　　　　";
    gotoxy(50,20);
    cout<<"str:"<<player_list[who_is_play].p_str<<" dex:"<<player_list[who_is_play].p_dex<<" luk:"<<player_list[who_is_play].p_luk<<" int:"<<player_list[who_is_play].p_int;
    gotoxy(50,22);
    cout<<"$"<<money;
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//玩家未按下ENTER 
}
void battle(int m_id)//傳入怪物ID 
{
    int level_up_bool=0;
    int bat_x=18,bat_y=22,key,mon_temp_hp=mon_map[m_id].hp,mon_temp_mp=mon_map[m_id].mp;
    int temp_mon_atp,temp_ai;
    int do_att=0;//紀錄是否使出攻擊 0為否 1為是
    int do_run=0;//紀錄是否逃跑 0為否 1為是
    int battle_end=0;//紀錄是否結束戰鬥 (可能是怪物死亡 也可能是主角死亡) 0為否 1為主角獲勝 2為怪物獲勝 
    string bat_dia="";
    //以下畫出戰鬥相關資訊 
    gotoxy(20,4);
    cout<<"野生的"<<mon_map[m_id].name<<"跳出來了";
    gotoxy(12,6);
    cout<<"Name:"<<mon_map[m_id].name;
    gotoxy(32,6);
    cout<<"LV:"<<mon_map[m_id].lv;
    draw_mon_detail(mon_temp_hp,mon_map[m_id].hp,mon_map[m_id].mp,mon_temp_mp);
    draw_player_detail();
    gotoxy(36,22);
    cout<<"◎戰鬥◎道具";
    gotoxy(36,23);
    cout<<"◎角色◎逃跑";
    while(1)
    {
    while(1)
    {
        if(do_att==1)//已發動攻擊 鎖定選項
        break; 
        gotoxy(bat_x*2,bat_y);
        key=getch();
        if(key==72)//上
        {
            if(bat_y==22)
            bat_y=23;
            else
            bat_y -=1;
        }
        else if(key==80)//下
        {
            if(bat_y==23)
            bat_y=22;
            else
            bat_y +=1;
        }
        else if(key==75)//左
        {
            if(bat_x==18)
            bat_x=21;
            else
            bat_x -=3;
        }
        else if(key==77)//右
        {
            if(bat_x==21)
            bat_x=18;
            else
            bat_x +=3;
        }
        else if(key==13)//按下enter
        {
            if(bat_x==18&&bat_y==22)//按下戰鬥選項
            {
                draw_battle_skill();
                bat_x=6;
                bat_y=22;
                while(1)
                {
                    gotoxy(bat_x*2,bat_y);
                    key=getch();
                    if(key==72)//上
                    {
                        if(bat_y==22)
                        bat_y=23;
                        else
                        bat_y -=1;
                    }
                    else if(key==80)//下
                    {
                        if(bat_y==23)
                        bat_y=22;
                        else
                        bat_y +=1;
                    }
                    else if(key==75)//左
                    {
                        if(bat_x==6)
                        bat_x=12;
                        else
                        bat_x -=6;
                    }
                    else if(key==77)//右
                    {
                        if(bat_x==12)
                        bat_x=6;
                        else
                        bat_x +=6;
                    }
                    else if(key==13)//按下enter
                    {
                        int cho_sk,atp;
                        bat_dia="";
                        if(bat_x==6&&bat_y==22)//選擇技能skill_known[0]
                        {
                            cho_sk=0;
                        }
                        else if(bat_x==12&&bat_y==22)//選擇技能skill_known[1]
                        {
                            cho_sk=1;
                        }
                        else if(bat_x==6&&bat_y==23)//選擇技能skill_known[2]
                        {
                            cho_sk=2;
                        } 
                        else if(bat_x==12&&bat_y==23)//選擇技能skill_known[3]
                        {
                            cho_sk=3;
                        }
                        atp=(player_list[who_is_play].p_att)*(skill[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1])/100;
                        bat_dia+=player_list[who_is_play].p_name;
                        bat_dia+="使出了";
                        bat_dia+=sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1];                        
                        display_battle(bat_dia,atp);
                        mon_temp_hp -=atp;
                        do_att=1;
                        bat_x=18;
                        bat_y=22;
                        break;
                        
                    }
                    else if(key==27)//按下Esc離開選擇 
                    {
                        bat_x=18;
                        bat_y=22;
                        break;
                    }
                }
            }
            else if(bat_x==21&&bat_y==23)//按下逃跑選項
            {
                do_run=1; 
                break;
            }
        }
    }
    if(do_run==1)//逃跑了
    {
        draw_map(test);
        break; 
    }
    if(mon_temp_hp<=0)
    {
        mon_temp_hp=0;
    }
    //顯示怪物資訊
    draw_mon_detail(mon_temp_hp,mon_map[m_id].hp,mon_map[m_id].mp,mon_temp_mp);
    clear_bat_dia();
    if(mon_temp_hp<=0)
    {
        int temp_money;
        mon_temp_hp=0;
        battle_end=1;//戰鬥結束 主角獲勝
        display_bat_end_dia(mon_map[m_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        player_list[who_is_play].p_exp+=mon_map[m_id].exp;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"獲得了"<<mon_map[m_id].exp<<"點經驗值";
        temp_money=money_drop_ai(mon_map[m_id].drop_money);
        gotoxy(12,12);
        cout<<player_list[who_is_play].p_name<<"獲得了$"<<temp_money;
        add_money(temp_money);
        do{
            key=getch();
        }while(key!=13);//玩家未按下ENTER
        draw_ab();
        clear_bat_dia();
        check_lvup();
        clear_bat_dia();
        break;
    }
    //換怪物攻擊 判斷AI
    temp_ai=mon_ai(); 
    //攻擊力等於攻擊力乘以攻擊係數
    if(temp_ai==4)//怪物逃跑了！
    {
        display_mon_battle("",0,temp_ai,mon_map[m_id].name);
        draw_map(test);
        break;//離開迴圈 
    }
    bat_dia="";
    temp_mon_atp=(mon_map[m_id].at_po)*(mon_map[m_id].mon_skill[temp_ai])/100;
    bat_dia+=mon_map[m_id].name;
    bat_dia+="使出了";
    bat_dia+=mon_map[m_id].mon_sk_name[temp_ai];
    display_mon_battle(bat_dia,temp_mon_atp,temp_ai,mon_map[m_id].name);
    player_list[who_is_play].p_hp-=temp_mon_atp;
    
    if(player_list[who_is_play].p_hp<=0)
    {
        player_list[who_is_play].p_hp=0;
    } 
    //顯示玩家資訊
    draw_player_detail();
    clear_bat_dia();
    
    //判斷玩家是否血量歸零
    if(player_list[who_is_play].p_hp<=0)
    {
        battle_end=2;//戰鬥結束 怪物獲勝
        draw_ab();
        display_bat_end_dia(mon_map[m_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        break;
    }
    else
    {
        do_att=0;//重新發動攻擊 
    }
     
    }
    draw_map(test);
    gotoxy(24,8);
    cout<<map_list[map_id].map_name;
}
void b_battle(int b_id)//傳入BOSS ID 
{
    int level_up_bool=0;
    int bat_x=18,bat_y=22,key,boss_temp_hp=boss_map[b_id].hp,boss_temp_mp=boss_map[b_id].mp;
    int temp_boss_atp,temp_ai;
    int do_att=0;//紀錄是否使出攻擊 0為否 1為是
    int do_run=0;//紀錄是否逃跑 0為否 1為是
    int battle_end=0;//紀錄是否結束戰鬥 (可能是怪物死亡 也可能是主角死亡) 0為否 1為主角獲勝 2為怪物獲勝 
    string bat_dia="";
    //以下畫出戰鬥相關資訊 
    gotoxy(20,4);
    cout<<"強大威猛帥氣英俊的"<<boss_map[b_id].name<<"跳出來了";
    gotoxy(12,6);
    cout<<"Name:"<<boss_map[b_id].name;
    gotoxy(32,6);
    cout<<"LV:"<<boss_map[b_id].lv;
    draw_mon_detail(boss_temp_hp,boss_map[b_id].hp,boss_map[b_id].mp,boss_temp_mp);
    draw_player_detail();
    gotoxy(36,22);
    cout<<"◎戰鬥◎道具";
    gotoxy(36,23);
    cout<<"◎角色◎逃跑";
    while(1)
    {
    while(1)
    {
        if(do_att==1)//已發動攻擊 鎖定選項
        break; 
        gotoxy(bat_x*2,bat_y);
        key=getch();
        if(key==72)//上
        {
            if(bat_y==22)
            bat_y=23;
            else
            bat_y -=1;
        }
        else if(key==80)//下
        {
            if(bat_y==23)
            bat_y=22;
            else
            bat_y +=1;
        }
        else if(key==75)//左
        {
            if(bat_x==18)
            bat_x=21;
            else
            bat_x -=3;
        }
        else if(key==77)//右
        {
            if(bat_x==21)
            bat_x=18;
            else
            bat_x +=3;
        }
        else if(key==13)//按下enter
        {
            if(bat_x==18&&bat_y==22)//按下戰鬥選項
            {
                draw_battle_skill();
                bat_x=6;
                bat_y=22;
                while(1)
                {
                    gotoxy(bat_x*2,bat_y);
                    key=getch();
                    if(key==72)//上
                    {
                        if(bat_y==22)
                        bat_y=23;
                        else
                        bat_y -=1;
                    }
                    else if(key==80)//下
                    {
                        if(bat_y==23)
                        bat_y=22;
                        else
                        bat_y +=1;
                    }
                    else if(key==75)//左
                    {
                        if(bat_x==6)
                        bat_x=12;
                        else
                        bat_x -=6;
                    }
                    else if(key==77)//右
                    {
                        if(bat_x==12)
                        bat_x=6;
                        else
                        bat_x +=6;
                    }
                    else if(key==13)//按下enter
                    {
                        int cho_sk,atp;
                        bat_dia="";
                        if(bat_x==6&&bat_y==22)//選擇技能skill_known[0]
                        {
                            cho_sk=0;
                        }
                        else if(bat_x==12&&bat_y==22)//選擇技能skill_known[1]
                        {
                            cho_sk=1;
                        }
                        else if(bat_x==6&&bat_y==23)//選擇技能skill_known[2]
                        {
                            cho_sk=2;
                        } 
                        else if(bat_x==12&&bat_y==23)//選擇技能skill_known[3]
                        {
                            cho_sk=3;
                        }
                        atp=(player_list[who_is_play].p_att)*(skill[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1])/100;
                        bat_dia+=player_list[who_is_play].p_name;
                        bat_dia+="使出了";
                        bat_dia+=sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[cho_sk])-1];                        
                        display_battle(bat_dia,atp);
                        boss_temp_hp -=atp;
                        do_att=1;
                        bat_x=18;
                        bat_y=22;
                        break;
                        
                    }
                    else if(key==27)//按下Esc離開選擇 
                    {
                        bat_x=18;
                        bat_y=22;
                        break;
                    }
                }
            }
            else if(bat_x==21&&bat_y==23)//按下逃跑選項
            {
                do_run=1; 
                break;
            }
        }
    }
    if(do_run==1)//逃跑了
    {
        draw_map(test);
        break; 
    }
    if(boss_temp_hp<=0)
    {
        boss_temp_hp=0;
    }
    //顯示怪物資訊
    draw_mon_detail(boss_temp_hp,boss_map[b_id].hp,boss_map[b_id].mp,boss_temp_mp);
    clear_bat_dia();
    if(boss_temp_hp<=0)
    {
        int temp_money;
        boss_temp_hp=0;
        battle_end=1;//戰鬥結束 主角獲勝
        display_bat_end_dia(boss_map[b_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        player_list[who_is_play].p_exp+=boss_map[b_id].exp;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"獲得了"<<boss_map[b_id].exp<<"點經驗值";
        temp_money=money_drop_ai(boss_map[b_id].drop_money);
        gotoxy(12,12);
        cout<<player_list[who_is_play].p_name<<"獲得了$"<<temp_money;
        add_money(temp_money);
        gotoxy(12,13);
        cout<<player_list[who_is_play].p_name<<"獲得了任務道具："<<item_list[boss_map[b_id].drop_item].item_name;
        itembox_list[boss_map[b_id].drop_item].num++;
        item_turnon_event(boss_map[b_id].drop_item);
        do{
            key=getch();
        }while(key!=13);//玩家未按下ENTER
        draw_ab();
        clear_bat_dia();
        check_lvup();
        clear_bat_dia();
        break;
    }
    //換怪物攻擊 判斷AI
    temp_ai=boss_ai(boss_map[b_id].skill_temp[0],boss_map[b_id].skill_temp[1],boss_map[b_id].skill_temp[2],boss_map[b_id].skill_temp[3],boss_map[b_id].skill_temp[4]); 
    //攻擊力等於攻擊力乘以攻擊係數
    if(temp_ai==4)//BOSS逃跑了！
    {
        display_mon_battle("",0,temp_ai,boss_map[b_id].name);
        draw_map(test);
        break;//離開迴圈 
    }
    bat_dia="";
    temp_boss_atp=(boss_map[b_id].at_po)*(boss_map[b_id].boss_skill[temp_ai])/100;
    bat_dia+=boss_map[b_id].name;
    bat_dia+="使出了";
    bat_dia+=boss_map[b_id].boss_sk_name[temp_ai];
    display_mon_battle(bat_dia,temp_boss_atp,temp_ai,boss_map[b_id].name);
    player_list[who_is_play].p_hp-=temp_boss_atp;
    
    if(player_list[who_is_play].p_hp<=0)
    {
        player_list[who_is_play].p_hp=0;
    } 
    //顯示玩家資訊
    draw_player_detail();
    clear_bat_dia();
    
    //判斷玩家是否血量歸零
    if(player_list[who_is_play].p_hp<=0)
    {
        battle_end=2;//戰鬥結束 怪物獲勝
        draw_ab();
        display_bat_end_dia(boss_map[b_id].name,player_list[who_is_play].p_name,battle_end);
        clear_bat_dia();
        break;
    }
    else
    {
        do_att=0;//重新發動攻擊 
    }
     
    }
    draw_map(test);
    gotoxy(24,8);
    cout<<map_list[map_id].map_name;
}
void init_boss_ap_map()//初始化BOSS出現的地圖 
{
    for(int i=0;i<20;i++)
    {
        boss_ap_map[boss_map[i].ap_map]=i;
    }
}

int which_mon(int m)//哪隻怪物出現 函數內輸入地圖編號 
{
    int temp;//紀錄亂數
    temp=randl();
    if(mon_ap_op[m][0]>=temp)
    return mon_ap_map[m][0]; 
    else if(mon_ap_op[m][1]>=temp)
    return mon_ap_map[m][1]; 
    else if(mon_ap_op[m][2]>=temp)
    return mon_ap_map[m][2]; 
    else
    return 0;//出現錯誤 顯示最低等級怪物 
} 
void init_mam()//初始化mon_ap_map
{
    int temp=0;
    for(int i=0;i<100;i++)
    {
        if(mon_map[i].hp==0)//該ID怪物未建立
        continue;
        else
        {
            for(int j=0;j<3&&mon_map[i].ap_map[j]!=NULL;j++)
            {
                while(mon_ap_op[mon_map[i].ap_map[j]][temp]>0)
                {
                    temp++;
                }
                mon_ap_map[mon_map[i].ap_map[j]][temp]=i;//建立此ID怪物地圖索引 
                if(temp==0)//第一隻怪物
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
void draw_battle_map()//畫出戰鬥介面 
{
    Sleep(1000);//讓畫面延遲一秒 
    system("cls");
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            gotoxy(j*2+10,i+5);
            if(bat_map[i][j]==0)
            cout<<"˙";
            else if(bat_map[i][j]==6)
            cout<<"　";
        }
    } 
}
void draw_mon_detail(int hp,int maxhp,int mp,int maxmp)//畫出戰鬥時怪物的資訊 
{
    gotoxy(12,7);
    cout<<"　　　　　　　　　　　　　　　　　　";
    gotoxy(12,7);
    cout<<"HP:"<<hp<<"/"<<maxhp;
    gotoxy(12,8);
    cout<<"　　　　　　　　　　　　　　　　　　";
    gotoxy(12,8);
    cout<<"MP:"<<mp<<"/"<<maxmp;
}
void draw_player_detail()//畫出戰鬥時玩家角色的資訊 
{
    gotoxy(12,18);
    cout<<"Name:"<<player_list[who_is_play].p_name;
    gotoxy(32,18);
    cout<<"LV:"<<player_list[who_is_play].p_lv;
    gotoxy(12,19);
    cout<<"　　　　　　　　　　　　　　　　　　";
    gotoxy(12,19);
    cout<<"HP:"<<player_list[who_is_play].p_hp<<"/"<<player_list[who_is_play].p_maxhp;
    gotoxy(12,20);
    cout<<"　　　　　　　　　　　　　　　　　　";
    gotoxy(12,20);
    cout<<"MP:"<<player_list[who_is_play].p_mp<<"/"<<player_list[who_is_play].p_maxmp;
}
void draw_battle_skill()//畫出戰鬥時的技能選擇 
{
    gotoxy(12,22);
    cout<<"◎";
    if(player_list[who_is_play].skill_known[0]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[0])-1];
    gotoxy(24,22);
    cout<<"◎";
    if(player_list[who_is_play].skill_known[1]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[1])-1];
    gotoxy(12,23);
    cout<<"◎";
    if(player_list[who_is_play].skill_known[2]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[2])-1];
    gotoxy(24,23);
    cout<<"◎";
    if(player_list[who_is_play].skill_known[3]>0)
    cout<<sk_name[player_list[who_is_play].p_pro][(player_list[who_is_play].skill_known[3])-1];
    
} 

void display_battle(string s,int atp)//顯示戰鬥報告
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
    }while(temp_key!=13);//玩家未按下ENTER 
    gotoxy(x*2,y+1);
    cout<<"造成了"<<atp<<"點傷害";
    do{
        temp_key=getch(); 
    }while(temp_key!=13);//玩家未按下ENTER 
}

int mon_ai()//怪物AI  0:普通攻擊60% 1:魔法攻擊30%(需視魔力是否足夠，進階用) 2:逃跑:10% 
{
    int temp;
    temp=randl();
    if(temp<=10)//逃跑
    return 4;
    else if(temp<=70)//普攻 
    return 0;
    else if(temp<=100)//魔攻
    return 1; 
}
int boss_ai(int r1,int r2,int r3,int r4,int r5)//BOSS_AI r1:逃跑機率 r2:招式一...etc
{
    int temp;
    temp=randl();
    if(temp<=r1)//逃跑
    return 4;
    else if(temp<=r2)//普攻 
    return 0;
    else if(temp<=r3)//魔攻
    return 1;
    else if(temp<=r4)//普攻 
    return 2;
    else
    return 3;
}  
void display_mon_battle(string s,int atp,int ai,string name)//顯示戰鬥報告(怪物用)以AI傳入值判斷寫出何種報告
{
    int x=7,y=11,temp_key;
    gotoxy(x*2,y);
    if(ai==0)//普通攻擊
    {
        cout<<name<<"表示憤怒！！";
        y++;
    }
    else if(ai==1)//魔法攻擊
    {
        cout<<name<<"全身一抖！！";
        y++;
    }
    else if(ai==4)//逃跑
    {
        cout<<name<<"夾著尾巴逃跑了。";
    }
    else if(ai==2)//普通攻擊
    {
        cout<<name<<"表示憤怒！！";
        y++;
    }
    else if(ai==3)//魔法攻擊
    {
        cout<<name<<"全身一抖！！";
        y++;
    }
    do{
        temp_key=getch();
    }while(temp_key!=13);//玩家未按下ENTER
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
        cout<<"造成了"<<atp<<"點傷害";
        do{
            temp_key=getch();
        }while(temp_key!=13);//玩家未按下ENTER
    }
} 
void clear_bat_dia()//清除畫面
{
    for(int y=10;y<17;y++)
    {
        gotoxy(12,y);
        cout<<"　　　　　　　　　　　　　　　　　　";
    } 
} 
void display_bat_end_dia(string mon,string player,int key)//顯示戰鬥結果 1為主角獲勝 2為怪物獲勝 
{
    int temp_key;
    string s="";
    if(key==1)//主角獲勝      
    {
        s+=player;
        s+="霸氣外放，";
        s+=mon;
        s+="跪倒在地，被擊敗了！";
    }
    else if(key==2)//怪物獲勝
    {
        s+=mon;
        s+="哈哈大笑，";
        s+=player;
        s+="跪倒在地，被擊敗了！";
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
    }while(temp_key!=13);//玩家未按下ENTER
    if(key==2)//怪物獲勝 
    {
        clear_bat_dia(); 
        if(player_list[who_is_play].p_lv>1)
        {
            s="";
            s+=player_list[who_is_play].p_name;
            s+="癱軟在地，全身抽動，哀號一聲，慘遭降級！";
            player_list[who_is_play].p_lv-=1;
            player_list[who_is_play].set_ab();            
        }
        else if(player_list[who_is_play].p_lv==1)
        {
            s="";
            s+=player_list[who_is_play].p_name;
            s+="眼前一黑，全身抽動，口吐白沫，倒地不起！";
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
void check_lvup()//判斷是否升級
{
    int temp_key;
    while(player_list[who_is_play].p_exp>=level_up_exp[player_list[who_is_play].p_lv])
    {
        player_list[who_is_play].p_exp-=level_up_exp[player_list[who_is_play].p_lv];
        player_list[who_is_play].p_lv++;
        gotoxy(12,11);
        cout<<player_list[who_is_play].p_name<<"升級了！";
        player_list[who_is_play].set_ab();
        lv_turnon_event(player_list[who_is_play].p_lv);
        draw_ab();
        clear_bat_dia();
    } 
} 
void talk_to_npc(int m_id,int x,int y)//和NPC對話 參數傳入地圖ID X值 Y值
{
    int temp_id,temp_x=10,temp_y=4,temp_key;
    for(int i=0;i<100;i++)//開始搜尋NPC
    {
        if(npc_list[i].at_map==m_id)//此ID之NPC在此地圖
        {
            if((npc_list[i].at_x==x)&&(npc_list[i].at_y==y))//確定是此NPC
            {
                temp_id=i;
                break; 
            } 
        }
    }
    npc_list[temp_id].npc_check_event();//為NPC做事件判斷
    if(npc_list[temp_id].npc_show==true)//此時該NPC可以被選擇
    { 
        gotoxy(temp_x*2,temp_y);
        cout<<npc_list[temp_id].npc_name<<"：";
        do{
           temp_key=getch();
        }while(temp_key!=13);//玩家未按下ENTER
        for(int i=0;npc_list[temp_id].npc_dia[npc_list[temp_id].npc_event][i]!=NULL;i++)//輸出判斷 
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
        }while(temp_key!=13);//玩家未按下ENTER
        clear_npc_dia();
        npc_list[temp_id].next_chap();
        
    }
}
void clear_npc_dia()//清除NPC對話畫面
{
    int x=10,y=4;
    for(;y<10;y++)
    {
        gotoxy(x*2,y);
        cout<<"　　　　　　　　　　";
    }
}
int string_to_num(char temp)//字串轉換成數值
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
void load_map()//載入地圖
{
    int tomap_id=map_id;//紀錄地圖物件中的陣列索引值
    for(int i=0;i<5;i++)
    {
        if(map_list[map_id].map_to[i]==0)
        continue;//還未建立 i++ 
        if(map_list[map_id].map_to_atx[i]==myx)//X座標值相符
        {
            if(map_list[map_id].map_to_aty[i]==myy)//Y座標值相符 確定是該傳送點 
            {
                tomap_id=map_list[map_id].map_to[i];//紀錄該目標地圖ID
                break;//完成搜尋 跳出迴圈 
            }  
        } 
    }
    for(int i=0;i<5;i++)
    {
        if(map_list[tomap_id].map_to[i]==0)
        continue;
        if(map_list[tomap_id].map_to[i]==map_id)//為該傳送點對應陣列索引值
        {
            myx=map_list[tomap_id].map_to_atx[i];
            myy=map_list[tomap_id].map_to_aty[i];
            break;//完成 跳出迴圈 
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
void hp_helper()//補血中心對話 
{
    int temp_key;
    string s="";
    gotoxy(42,8);
    cout<<"冒險者中心:";
    gotoxy(42,9);
    cout<<"請問需要服務嗎？(Y/N)";
    temp_key=getch();
    gotoxy(42,9);
    cout<<"　　　　　　　　　　　 ";
    if(temp_key==121||temp_key==13)//按下Y
    { 
        gotoxy(42,9);
        cout<<"噹~噹~噹噹噹！";
        do{
            temp_key=getch(); 
        }while(temp_key!=13);//玩家未按下ENTER 
        for(int i=0;i<6;i++)//回復HP/MP 
        {
            player_list[i].p_hp=player_list[i].p_maxhp;
            player_list[i].p_mp=player_list[i].p_maxmp;
            }
        gotoxy(42,10);
        cout<<"HP/MP都已經恢復，祝您遊戲愉快！";
    }
    else
    {
        gotoxy(42,9);
        cout<<"歡迎再度光臨！";
    }
    do{
            temp_key=getch(); 
        }while(temp_key!=13);//玩家未按下ENTER
    draw_map(test);
}
void add_money(int temp_money)//增加金錢 
{
    money +=temp_money;//先不考慮溢位問題 
}
void remove_money(int temp_money)//減少金錢(要先判斷錢夠不夠) 
{
    money -=temp_money;//先不考慮溢位問題 
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
    for(int i=0;saler_list[id].sale_id[i]>0;i++)//判斷有賣道具 
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
        cout<<"　　　　　　　　　　　　　　　　";
        gotoxy(42,6);
        cout<<item_list[saler_list[id].sale_id[y-9]].item_intr;
        gotoxy(x*2,y);
        temp_key=getch();
        //72:上 80:下
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
            cout<<"　　　　　　　　　　　　　　　　";
            if(check_money(money,item_list[saler_list[id].sale_id[y-9]].item_price))
            {
                remove_money(item_list[saler_list[id].sale_id[y-9]].item_price);
                add_item(saler_list[id].sale_id[y-9],1);
                gotoxy(42,6);
                cout<<"購買完成！";
            }
            else
            {
                gotoxy(42,6);
                cout<<"餘額不足";
            }
            do{
                temp_key=getch(); 
            }while(temp_key!=13);//玩家未按下ENTER
            gotoxy(42,6);
                cout<<"　　　　　";
        }
        else if(temp_key==27)//ESC 
        {
            break;
        }
    }
    system("cls");
    draw_map(test);
}
int money_drop_ai(int temp)//掉落金錢 
{
    int sum;
    sum=temp+(temp*randl()/100);
    return sum;
}
int search_saler(int m_id,int x,int y)//搜尋商人ID
{
    int temp_id;
    for(int i=0;i<20;i++)//開始搜尋NPC
    {
        if(saler_list[i].at_map==m_id)//此ID之NPC在此地圖
        {
            if((saler_list[i].at_x==x)&&(saler_list[i].at_y==y))//確定是此NPC
            {
                temp_id=i;
                break; 
            } 
        }
    }
    return temp_id;
} 
bool item_useful(int id)//道具可否使用
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
        cout<<"　　　　　　　　　　　　　　　";
        gotoxy(42,6);
        cout<<"使用完成！";
    }
}
void show_itembox()//顯示背包 
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
        cout<<"　　　　　　　　　　　　　　　　";
        gotoxy(42,7);
        cout<<item_list[temp_list[y-9]].item_intr;
        gotoxy(x*2,y);
        temp_key=getch();
        //72:上 80:下
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
            if(item_useful(temp_list[y-9]))//道具可以使用 
            {
                use_item(temp_list[y-9]);
                do{
                    temp_key=getch(); 
                }while(temp_key!=13);//玩家未按下ENTER
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
void show_chap(string s)//顯示章節 
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
    }while(temp_key!=13);//玩家未按下ENTER
    draw_map(test);
    if(section==change_chap[chap])
    {
        chap++;
        section=0;
        show_chap(chap_list[chap].story[section]);
    }
}
void lv_turnon_event(int lv)//以等級開啟事件(升級時再判斷即可) 
{
    if(lv>=4)
    event[2]=true;//4等 
} 

void item_turnon_event(int id)//道具開啟事件
{
    if(id==99)
    {event[9]=true;}
    if(id==98)
    {event[7]=true;}
}
