#include<iostream>
#include<iomanip>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
#include<ctype.h>
#include <windows.h>
#include <process.h>
#include<string>
#include<MMsystem.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;

//********TOTAL FUNCTIONS USED IN SNAKE GAME***************
int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate{
    int x;
    int y;
    int direction;
};
 
typedef struct coordinate coordinate;
 
coordinate head, bend[500],food,body[30];
//*********************************************************

class tictac //******class for tictactoe game********
   {
	 char mat[3][3];
public:
	void instruct(void);
	void design(void); //this function helps to design the tictactoe geometry;
	void disp(void);  //****Function for displaying tictactoe graph***;
	void inp1(void);	//this function takes input from user //(i.e Two player input);
};
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void tictac :: instruct(void)
{
	cout<<"Press any key to continue\n";
	getch();
	system("CLS");
	cout<<"Games Instruction\n";
	cout<<"1.There are 9 slots in total.\n";
	cout<<"2.Player1='X' and Player2='O'\n";
	cout<<"3.Each player will get the alternate chance\n";
	cout<<"4.First player to reach the winning move wins\n";
	cout<<"Press any key to continue\n";
	getch();
	system("CLS");
		cout<<"\n\n\n\n";
	cout<<setw(200)<<"LOADING\n";
	cout<<"";
	cout<<setw(50);
	for(int i=0;i<=25;i++)
	{
		
    cout<<"*";
    
    Sleep(200); 
    
    
}
cout<<"\n\n\n";
cout<<"Press any key to continue\n";
getch();
system("CLS");
}
//********DESIGN CODE********

void tictac :: design(void)
{
	cout<<"*****WELCOME TO TICTACTOE GAME******* \n"<<"\n";
	cout<<"Player 1==(x) and Player 2==(0)\n"<<"\n";
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
//****Code for displaying tictactoe format******
void tictac :: disp(void)
{
   char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			
			cout <<"\t"<< mat[i][j]<<"  |"<<"  ";
		}
		cout<<"\n";
		cout<<"\t"<<"______________________"<<"\n";
	}	
}
//----------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
//****Code for taking input from user**** //And the main coding is done here;
void tictac :: inp1(void)
{
	char first[10];
	char second[10];
	cout<<"Enter Player1 name:\n";
	scanf("%s",&first);
	fflush(stdin);
		cout<<"Enter Player2 name:\n";
scanf("%s",&second);
	fflush(stdin);
	cout<<"******************************************\n";
	char mat[3][3]={'1','2','3','4','5','6','7','8','9'};
	char temp; char a;
	char dummy1[3][3]={'X','X','X','X','X','X','X','X','X'}; //dummies matrix are made for swapping character from matrix;
	char dummy2[3][3]={'0','0','0','0','0','0','0','0','0'}; //same as above for different player;
	
	for(int loop=1;loop<=5;loop++)
	{
	cout<<first<<" turn";
	cin>>a;                   
                                 	
	for(int i=0;i<3;i++)             
	{
		temp=0;
		for(int j=0;j<3;j++)
		{
			if(a==mat[i][j])
			{
				temp=mat[i][j];
				mat[i][j]=dummy1[i][j];
				dummy1[i][j]=temp;	
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			
			cout <<"\t"<< mat[i][j]<<"  |"<<"  ";
		}
		cout<<"\n";
		cout<<"\t"<<"______________________"<<"\n";
}
 
 //if and else if statement are for checking whether the player won the game or not;
 
 if(mat[0][0]=='X' && mat[0][1]=='X' && mat[0][2]=='X')
 	{
	 cout<<first<<" won\n";
	 break;}
 else if(mat[1][0]=='X' && mat[1][1]=='X' && mat[1][2]=='X')
 	{
	 cout<<first<<" won\n";
 	break;}
 else if(mat[2][0]=='X' && mat[2][1]=='X' && mat[2][2]=='X')	
 {
 cout<<first<<" won\n";
 break;}
 else if(mat[0][0]=='X' && mat[1][0]=='X' && mat[2][0]=='X')
 		{
		 cout<<first<<" won\n";
 		break;}
 else if(mat[0][1]=='X' && mat[1][1]=='X' && mat[2][1]=='X')
 	{
	 cout<<first<<" won\n";
 	break;}
 else if(mat[0][2]=='X' && mat[1][2]=='X' && mat[2][2]=='X')
 	{
	 cout<<first<<" won\n";
 	break;}
 else if(mat[0][0]=='X' && mat[1][1]=='X' && mat[2][2]=='X')
 	{
	 cout<<first<<" won\n";
 	break;}
 else if(mat[0][2]=='X' && mat[1][1]=='X' && mat[2][0]=='X')
 	{
	 cout<<first<<" won\n";
    break;}

	char ch;
	char garbage;	
	cout<<second<<" turn\n";
	cin>>ch;
	for(int i=0;i<3;i++)
	{
		garbage=0;
		for(int j=0;j<3;j++)
		{
			if(ch==mat[i][j])
			{
				garbage=mat[i][j];
				mat[i][j]=dummy2[i][j];
				dummy2[i][j]=garbage;	
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			
			cout <<"\t"<< mat[i][j]<<"  |"<<"  ";
		}
		cout<<"\n";
		cout<<"\t"<<"______________________"<<"\n";
	}
		
	 if(mat[0][0]=='0' && mat[0][1]=='0' && mat[0][2]=='0')
 	{
	 cout<<second<<" won\n";
	 break;}
 else if(mat[1][0]=='0' && mat[1][1]=='0' && mat[1][2]=='0')
 	{
	  cout<<second<<" won\n";
 	break;}
 else if(mat[2][0]=='0' && mat[2][1]=='0' && mat[2][2]=='0')	
 {
  cout<<second<<" won\n";
 break;}
 else if(mat[0][0]=='0' && mat[1][0]=='0' && mat[2][0]=='0')
 		{
		 cout<<second<<" won\n";
 		break;}
 else if(mat[0][1]=='0' && mat[1][1]=='0' && mat[2][1]=='0')
 	{
	  cout<<second<<" won\n";
 	break;}
 else if(mat[0][2]=='0' && mat[1][2]=='0' && mat[2][2]=='0')
 	{
	  cout<<second<<" won\n";
 	break;}
 else if(mat[0][0]=='0' && mat[1][1]=='0' && mat[2][2]=='0')
 	{
	  cout<<second<<" won\n";
 	break;}
 else if(mat[0][2]=='0' && mat[1][1]=='0' && mat[2][0]=='0')
 	{
	  cout<<second<<" won\n";
    break;}
}
}
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
class kbc
{
	int var;
	char name[10];
	public:
		void instruct(void);
		void layout(void);
		void input(void);
		void question(void);	
		void sound(void);	
		void applaud(void);
		void buzzer(void);
		void congratulation(void);
};
void kbc :: instruct(void)
{
	
	cout<<"Press any key continue\n";
	getch();
	system("CLS");
	cout<<"Game Instructions for Who wants to be millionaire\n";
	cout<<"1.There are three lifeline present in the game.\n";
	cout<<"2.For each question you will asked to input the lifeline\n";
	cout<<"3.Note that the lifeline you used previously cannot be used\n";
	cout<<"4.For each correct answer you will rewarded with the cash\n";
	cout<<"5.Note that for each wrong answer your cash wont be decrease\n";
	cout<<"Press Enter to cotinue\n";
	getch();
	system("CLS");
	cout<<"\n\n\n\n";
//	cout<<"\n\n\n\n";
	cout<<setw(200)<<"LOADING\n";
	cout<<"";
	cout<<setw(50);
	for(int i=0;i<=25;i++)
	{		
   cout<<"*";
    
    Sleep(100); 
    
    
}
cout<<"\n\n\n";
cout<<"Press any key to continue\n";
getch();
system("CLS");
}
void kbc :: layout(void)
{
	cout<<"\n\n\n";
	cout<<"\t\t\t"<<"**********WHO WANTS TO BE A MILLIONAIRE***********\n\n\n";
    cout<<"\t\t"<<setw(100)<<"****LIFE_LINE******\n";
	cout<<"\t\t"<<setw(100)<<"1)50/50        \n";
	cout<<"\t\t"<<setw(100)<<"2)Audience poll\n";
	cout<<"\t\t"<<setw(100)<<"3)Double Dip  \n";
	//cout<<"\t\t"<<setw(100)<<"\n";

}
void kbc :: input(void)
{
	cout<<"\n";
	cout<<"Enter player name:\n";
	scanf("%s",&name);
	//fflush(stdin);
	cout<<name<<", lets see your knowledge:\n";
}
void kbc :: applaud(void)
{
	PlaySound(TEXT("C:\\Users\\Own\\Desktop\\final\\applaud2.wav"),NULL,SND_SYNC);
}
void kbc :: sound(void)
{
	PlaySound(TEXT("C:\\Users\\Own\\Desktop\\final\\kbc.wav"),NULL,SND_SYNC);
}
void kbc :: buzzer(void)
{
	PlaySound(TEXT("C:\\Users\\Own\\Desktop\\final\\buzzer.wav"),NULL,SND_SYNC);
}
void kbc :: congratulation(void)
{
	PlaySound(TEXT("C:\\Users\\Own\\Desktop\\final\\congrats.wav"),NULL,SND_ASYNC);
}
void kbc :: question(void)
{
	int flag,flag2,flag3,flag4,flag5,flag6,flag7,flag8; //These variables are for checking 50/50 lifeline;
	int flag_1,flag_2,flag_3,flag_4,flag_5,flag_6,flag_7,flag_8; //These variable are for checking audience poll; 
    int flag_a,flag_b,flag_c,flag_d,flag_e,flag_f,flag_g,flag_h; //These variable are for checking double take;
	int count=0;
	char select;string life;
	int selectlife;
	cout<<"\n\n";
	cout<<" 1) What is the national game  of Nepal?\n";
	cout<<"\t"<<"_________________________"<<endl;
	cout<<"\t"<<" A)Volleyball| C)Kabbadi "<<endl;
	cout<<"\t"<<"_____________|___________"<<endl;
	cout<<"\t"<<" B)Dandi Biyo| D)Cricket "<<endl;
	cout<<"\t"<<"_____________|___________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life;
	if(life=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife;
		if(selectlife==1)
		{
	flag=1;
    cout<<"\t"<<"_________________________"<<endl;
	cout<<"\t"<<" A)Volleyball|           "<<endl;
	cout<<"\t"<<"_____________|____________"<<endl;
	cout<<"\t"<<" B)Dandi Biyo|            "<<endl;
	cout<<"\t"<<"_____________|____________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select;
		if(select=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
		}
		else{
		cout<<"Thats the wrong answer:\n";
	buzzer();	
	}
		}
		else if(selectlife==2)
		{
			flag_1=1;
    cout<<"\t"<<" |\n";
	cout<<"\t"<<" |\n";
	cout<<"\t"<<" |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | | |\n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select;
		if(select=='a')
		{	
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
		}
		else if(selectlife==3)
		{
			flag_a=1;
			char A,B;
			char dummy;
			dummy='a';
			cout<<"Select two options:\n";
			cin>>A>>B;
			if(A==dummy || B==dummy)
			{
			cout<<"'A' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else
			{
			cout<<"You selected the wrong answer:\n";
			buzzer();
		}
		}	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select;
		if(select=='a')
		{
		applaud();
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		count++;
		}
		else
		{
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
	
	//*************************************************************
	cout<<"\n";
	cout<<"Press any key for the second question\n";
	getch();
//	system("CLS");
	char select2;string life2;
	int selectlife2;
	cout<<"\n\n";
	cout<<" 2) Which of the following does not have a chemical element named after him?\n";
	cout<<"\t"<<"___________________________________"<<endl;
	cout<<"\t"<<"  A)Albert Einstein| C)Neil Bohr   "<<endl;
	cout<<"\t"<<"___________________|_______________"<<endl;
	cout<<"\t"<<"  B)Isaac Newton   | D)Enrico Fermi"<<endl;
	cout<<"\t"<<"___________________|_______________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life2;
	if(life2=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife2;
		if(selectlife2==1)
		{
			
			if(flag!=1)
			{
			flag2=2;
    cout<<"\t"<<"_______________________________"<<endl;
	cout<<"\t"<<"                |              "<<endl;
	cout<<"\t"<<"________________|______________"<<endl;
	cout<<"\t"<<"  B)Isaac Newton|D)Enrico Fermi"<<endl;
	cout<<"\t"<<"________________|______________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else
		{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
		}
		else 
		{
			cout<<"The life line is already used\n";
		cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else
		{
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	}
	}
		else if(selectlife2==2)
		{
			if(flag_1!=1)
			{
			flag_2=2;
    cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | | |\n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{	
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
		cout<<"The lifeline is Already used\n";
		cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
		}
	}
		else if(selectlife2==3)
		{
			if(flag_a!=1)
			{
			flag_b=2;
			char A2,B2;
			char dummy2;
			dummy2='b';
			cout<<"Select two options:\n";
			cin>>A2>>B2;
			if(A2==dummy2 || B2==dummy2)
			{			
			cout<<"'B' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
		}
			else{
			
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
			cout<<"The lifeline is already used\n";
				cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select2;
		if(select2=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	}
	cout<<"Press any key for the third question\n";
	getch();
	char select3;string life3;
	int selectlife3;
	cout<<"\n\n";
	cout<<" 3) Who won Golden boot on 2002 worldcup?\n";
	cout<<"\t"<<"____________________________________________"<<endl;
	cout<<"\t"<<"  A)Miroslav Klose | C)Salvatore Schillaci  "<<endl;
	cout<<"\t"<<"___________________|________________________"<<endl;
	cout<<"\t"<<"  B)Ronaldo        | D)Thomas Muller        "<<endl;
	cout<<"\t"<<"___________________|________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life2;
	if(life2=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife3;
		if(selectlife3==1)
		{
			
			if(flag!=1 && flag2!=2)
			{
			flag3=3;
    cout<<"\t"<<"_________________________________"<<endl;
	cout<<"\t"<<"  A)Miroslav Klose|              "<<endl;
	cout<<"\t"<<"__________________|______________"<<endl;
	cout<<"\t"<<"  B)Ronaldo       |              "<<endl;
	cout<<"\t"<<"__________________|______________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select3;
		if(select3=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else 
		{
			cout<<"The life line is already used\n";
			cout<<"Select option:\n";
		    cin>>select3;
	     	if(select3=='b')
	     	{		 
		   cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		   applaud();
		   count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife3==2)
		{
			if(flag_1!=1 && flag_2!=2)
			{
			flag_3=3;
    cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   |   \n";
	cout<<"\t"<<"   | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | |\n";
	cout<<"\t"<<" | | | |\n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select3;
		if(select3=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select3;
		if(select3=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife3==3)
		{
			if(flag_a!=1 && flag_b!=2)
			{
			flag_c=3;
			char A3,B3;
			char dummy3;
			dummy3='b';
			cout<<"Select two options:\n";
			cin>>A3>>B3;
			if(A3==dummy3 || B3==dummy3)
			{
			cout<<"'B' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;;
			applaud();
			count++;
		}
			else{
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select3;
		if(select3=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select3;
		if(select3=='b')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	}
	cout<<"Press any key for the fourth question\n";
	getch();
	char select4;string life4;
	int selectlife4;
	cout<<"\n\n";
	cout<<" 4)What is the name of the present king of Saudi-Arabia?\n";
	cout<<"\t"<<"__________________________________________________"<<endl;
	cout<<"\t"<<"  A)King hussain seikh | C)king sabah al javed    "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"\t"<<"  B)king abdullah ahmad| D)king salman            "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life;
	if(life=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife4;
		if(selectlife4==1)
		{
             if(flag!=1 && flag2!=2 && flag3!=3)
			 {
				 flag4=4;	
    cout<<"\t"<<"_____________________________________"<<endl;
	cout<<"\t"<<"             |C)King Sabah al javed "<<endl;
	cout<<"\t"<<"_____________|_______________________"<<endl;
	cout<<"\t"<<"             |D)king salman          "<<endl;
	cout<<"\t"<<"_____________|_______________________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	 }
	 else
	 {
	 	cout<<"The lifeline is already used\n";
	 	cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	 }
}
		else if(selectlife4==2)
		{
			if(flag_1!=1 && flag_2!=2 && flag_3!=3)
			{
			flag_4=4;
    cout<<"\t"<<"       |   \n";
	cout<<"\t"<<"       |   \n";
	cout<<"\t"<<"       |   \n";
	cout<<"\t"<<"   | | |   \n";
	cout<<"\t"<<"   | | |   \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{		
		cout<<"Thats the wrong answer:\n";
		buzzer();
		}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife4==3)
		{
			if(flag_a!=1 && flag_b!=2 && flag_c!=3)
			{
				flag_d=4;
			char A4,B4;
			char dummy4;
			dummy4='d';
			cout<<"Select two options:\n";
			cin>>A4>>B4;
			if(A4==dummy4 || B4==dummy4)
			{
			cout<<"'D' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else{
		
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
		cout<<"The lifeline is already used\n";
		cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d')
		{
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select4;
		if(select4=='d'){
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
	
	//************************FIFTH QUESTION
	
	char select5;string life5;
	int selectlife5;
	cout<<"\n\n";
	cout<<"5)What is the name of the present educational minister of nepal?\n";
	cout<<"\t"<<"__________________________________________________"<<endl;
	cout<<"\t"<<"  A)Chitra Lekha Yadav | C)Giriraj Mani Pokharel  "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"\t"<<"  B)Dhaniram Poudel    | D)None of the above      "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life5;
	if(life5=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife5;
		if(selectlife5==1)
		{
             if(flag!=1 && flag2!=2 && flag3!=3 && flag4!=4)
			 {
				 flag5=5;	
    cout<<"\t"<<"________________________________________________"<<endl;
	cout<<"\t"<<"  A)Chitra Lekha Yadav|C)Giriraj Mani Pokharel  "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\t"<<"                      |                         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	 }
	 else
	 {
	 	cout<<"The lifeline is already used\n";
	 	cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	 }
}
		else if(selectlife5==2)
		{
			if(flag_1!=1 && flag_2!=2 && flag_3!=3 && flag_4!=4)
			{
			flag_5=5;
    cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"   | |     \n";
	cout<<"\t"<<"   | |     \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife5==3)
		{
			if(flag_a!=1 && flag_b!=2 && flag_c!=3,flag_d!=4)
			{
				flag_e=5;
			char A5,B5;
			char dummy5;
			dummy5='c';
			cout<<"Select two options:\n";
			cin>>A5>>B5;
			if(A5==dummy5 || B5==dummy5)
			{
			cout<<"'C' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else{
		
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
		cout<<"The lifeline is already used\n";
		cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c')
		{
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select5;
		if(select5=='c'){
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
	
	//SIXTH QUESTION*****************************
	
	char select6;string life6;
	int selectlife6;
	cout<<"\n\n";
	cout<<"6)Who is the CEO of TWITTER?\n";
	cout<<"\t"<<"__________________________________________________"<<endl;
	cout<<"\t"<<"  A)Jack Dorsey        | C)Biz Stone              "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"\t"<<"  B)Larry Page         | D)Evan Williams          "<<endl;
	cout<<"\t"<<"_______________________|__________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life6;
	if(life6=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife6;
		if(selectlife6==1)
		{
             if(flag!=1 && flag2!=2 && flag3!=3 && flag4!=4 && flag5!=5)
			 {
				 flag6=6;	
    cout<<"\t"<<"________________________________________________"<<endl;
	cout<<"\t"<<"  A)Jack Dorsey       |                         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\t"<<"                      | D)Evan Williams         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	 }
	 else
	 {
	 	cout<<"The lifeline is already used\n";
	 	cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	 }
}
		else if(selectlife6==2)
		{
			if(flag_1!=1 && flag_2!=2 && flag_3!=3 && flag_4!=4 && flag_5!=5)
			{
			flag_6=6;
    cout<<"\t"<<"          \n";
	cout<<"\t"<<" |         \n";
	cout<<"\t"<<" |         \n";
	cout<<"\t"<<" | |      \n";
	cout<<"\t"<<" | | |     \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife6==3)
		{
			if(flag_a!=1 && flag_b!=2 && flag_c!=3,flag_d!=4 && flag_e!=5)
			{
				flag_f=6;
			char A6,B6;
			char dummy6;
			dummy6='a';
			cout<<"Select two options:\n";
			cin>>A6>>B6;
			if(A6==dummy6 || B6==dummy6)
			{
			cout<<"'A' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else{
		
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
		cout<<"The lifeline is already used\n";
		cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a')
		{
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select6;
		if(select6=='a'){
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
	
	//SEVENTH QUESTION********************************************
	
	char select7;string life7;
	int selectlife7;
	cout<<"\n\n";
	cout<<"7)Who wrote the book called 'SETO BAGH'?\n";
	cout<<"\t"<<"________________________________________________________________"<<endl;
	cout<<"\t"<<"  A)Chandra Shekhar Upadhayay        | C)Diamond Shumsher Rana  "<<endl;
	cout<<"\t"<<"_____________________________________|__________________________"<<endl;
	cout<<"\t"<<"  B)Amar Neupane                     | D)Manjushree Thapa       "<<endl;
	cout<<"\t"<<"_____________________________________|__________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life7;
	if(life7=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife7;
		if(selectlife7==1)
		{
             if(flag!=1 && flag2!=2 && flag3!=3 && flag4!=4 && flag5!=5 && flag6!=6)
			 {
				 flag7=7;	
    cout<<"\t"<<"________________________________________________"<<endl;
	cout<<"\t"<<"                      | C)Diamond Shumsher Rana "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\t"<<" B)Amar Neupane       |                         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	 }
	 else
	 {
	 	cout<<"The lifeline is already used\n";
	 	cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	 }
}
		else if(selectlife7==2)
		{
			if(flag_1!=1 && flag_2!=2 && flag_3!=3 && flag_4!=4 && flag_5!=5 && flag_6!=6)
			{
			flag_7=7;
    cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"     |     \n";
	cout<<"\t"<<"     |    \n";
	cout<<"\t"<<"   | |     \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<" | | | |   \n";
	cout<<"\t"<<"_|_|_|_|___\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife7==3)
		{
			if(flag_a!=1 && flag_b!=2 && flag_c!=3,flag_d!=4 && flag_e!=5 && flag_f!=6)
			{
				flag_g=7;
			char A7,B7;
			char dummy7;
			dummy7='c';
			cout<<"Select two options:\n";
			cin>>A7>>B7;
			if(A7==dummy7 || B7==dummy7)
			{
			cout<<"'C' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else{
		
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
		cout<<"The lifeline is already used\n";
		cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c')
		{
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select7;
		if(select7=='c'){
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
	
	//FINAL QUESTION
	
	char select8;string life8;
	int selectlife8;
	cout<<"\n\n";
	cout<<"8)When was Oracle Company founded?\n";
	cout<<"\t"<<"________________________________________________________________"<<endl;
	cout<<"\t"<<"  A)June 16,1977                     | C)October 28,1998        "<<endl;
	cout<<"\t"<<"_____________________________________|__________________________"<<endl;
	cout<<"\t"<<"  B)feb 28,2000                      | D)June 20,1987           "<<endl;
	cout<<"\t"<<"_____________________________________|__________________________"<<endl;
	cout<<"Do you want to you use Life line(yes/no)?\n";
	cin>>life8;
	if(life8=="yes")
	{
		cout<<"\n";
		cout<<"Which life line do you wanna use?\n";
		cin>>selectlife8;
		if(selectlife8==1)
		{
             if(flag!=1 && flag2!=2 && flag3!=3 && flag4!=4 && flag5!=5 && flag6!=6 && flag7!=7)
			 {
				 flag8=8;	
    cout<<"\t"<<"________________________________________________"<<endl;
	cout<<"\t"<<" A)June 16,1977       |                         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\t"<<" B)Feb 28,2000        |                         "<<endl;
	cout<<"\t"<<"______________________|_________________________"<<endl;
	cout<<"\n";
	
		cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
	 }
	 else
	 {
	 	cout<<"The lifeline is already used\n";
	 	cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	 }
}
		else if(selectlife8==2)
		{
			if(flag_1!=1 && flag_2!=2 && flag_3!=3 && flag_4!=4 && flag_5!=5 && flag_6!=6 && flag_7!=7)
			{
			flag_8=8;
    cout<<"\t"<<" | |       \n";
	cout<<"\t"<<" | |       \n";
	cout<<"\t"<<" | | |    \n";
	cout<<"\t"<<" | | |    \n";
	cout<<"\t"<<" | | |    \n";
	cout<<"\t"<<" | | | |  \n";
	cout<<"\t"<<" | | | |  \n";
	cout<<"\t"<<"_|_|_|_|__\n";
	cout<<"\t"<<" A B C D\n";
	cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
		else{
			cout<<"The lifeline is already used\n";
			cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a')
		{
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
		else if(selectlife8==3)
		{
			if(flag_a!=1 && flag_b!=2 && flag_c!=3,flag_d!=4 && flag_e!=5 && flag_f!=6 && flag_g!=7)
			{
				flag_h=8;
			char A8,B8;
			char dummy8;
			dummy8='a';
			cout<<"Select two options:\n";
			cin>>A8>>B8;
			if(A8==dummy8 || B8==dummy8)
			{
			cout<<"'A' IS CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
			applaud();
			count++;
		}
			else{
		
			cout<<"You selected the wrong answer:\n";
			buzzer();}
		}
		else
		{
		cout<<"The lifeline is already used\n";
		cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a')
		{
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();}
		}
	}
	
	}
	else
	{
		cout<<"Select option:\n";
		cin>>select8;
		if(select8=='a'){
		
		cout<<"CORRECT ANSWER "<<"YOU WON "<<"Rs 125,000"<<endl;
		applaud();
		count++;
	}
		else{
		
		cout<<"Thats the wrong answer:\n";
		buzzer();
	}
	}
if(count==8)
{
	cout<<"YOU HAVE WON .....CONGRATULATIONS\n";
	congratulation();
}
else if(count==7)
{
	cout<<"You earned 875,000....BETTER LUCK NEXT TIME\n";
}
else if(count==6)
{
	cout<<"You earned 750,000....BETTER LUCK NEXT TIME\n";
}
else if(count==5)
{
	cout<<"You earned 625,000....BETTER LUCK NEXT TIME\n";
}
else if(count==4)
{
	cout<<"You earned 500,000....BETTER LUCK NEXT TIME\n";
}
else if(count==3)
{
	cout<<"You earned 375,000....BETTER LUCK NEXT TIME\n";
}
else if(count==2)
{
	cout<<"You earned 250,000....BETTER LUCK NEXT TIME\n";
}
else if(count==1)
{
	cout<<"You earned 125,000....BETTER LUCK NEXT TIME\n";
}
else
{
	cout<<"SORRY...YOU EARNED NULL.\n";
}
cout<<"Press any key to exit the game\n";
getch();
system("CLS");
cout<<"THANKYOU FOR PLAYING OUR GAME\n";
}

int main()
{
     	cout<<"\n\n\n\n";
	cout<<setw(200)<<"LOADING\n";
	cout<<"";
	cout<<setw(50);
	for(int i=0;i<=25;i++)
	{		
    cout<<"*";
    Sleep(100);   
}
cout<<"\n\n\n";
cout<<"Press any key to continue\n";
getch();
system("CLS");

	tictac obj;
	int option;
	cout<<"\n";
	cout<<setw(50)<<"***WELCOME TO THE MINICLIP CONSOLE******\n";
	cout<<"\n\n";
	cout<<"PLEASE SELECT THE GAME YOU WANT TO PLAY\n\n";
	cout<<"1)WHO WANTS TO BE A MILLIONAIRE\n2)TICTACTOE\n3)SNAKE\n";
	cin>>option;
	
	switch(option)
	{
		case 3:
		//-----------------------------------------------	
	    char key;
    Print();
    system("cls");
    load();
    length=5;
    head.x=25;
    head.y=20;
    head.direction=RIGHT;
    Boarder();
    Food(); //to generate food coordinates initially
    life=3; //number of extra lives
    bend[0]=head;
    Move();   //initialing initial bend coordinate
    break;
    //-----------------------------------------------
    case 2:
    obj.instruct();
    obj.design();
	obj.disp();
	obj.inp1();
	break;
	case 1:
	kbc obj;
	obj.instruct();
	obj.layout();
	obj.sound();
	obj.input();
//	obj.sound();
	obj.question();
    	break;
    default:
    	cout<<"invalid input\n";
	}
			
	}
//****DEFINING ALL THE FUNCTIONS USED IN SNAKE GAME*****	
	
	void Move()
{
    int a,i;
 
    do{
 
        Food();
        fflush(stdin);
 
        len=0;
 
        for(i=0;i<30;i++)
 
        {
 
            body[i].x=0;
 
            body[i].y=0;
 
            if(i==length)
 
            break;
 
        }
 
        Delay(length);
 
        Boarder();
 
        if(head.direction==RIGHT)
 
            Right();
 
        else if(head.direction==LEFT)
 
            Left();
 
        else if(head.direction==DOWN)
 
            Down();
 
        else if(head.direction==UP)
 
            Up();
 
        ExitGame();
 
    }while(!kbhit());
 
    a=getch();
 
    if(a==27)
 
    {
 
        system("cls");
 
        exit(0);
 
    }
    key=getch();
 
    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))
 
    {
 
        bend_no++;
 
        bend[bend_no]=head;
 
        head.direction=key;
 
        if(key==UP)
 
            head.y--;
 
        if(key==DOWN)
 
            head.y++;
 
        if(key==RIGHT)
 
            head.x++;
 
        if(key==LEFT)
 
            head.x--;
 
        Move();
 
    }
 
    else if(key==27)
 
    {
 
        system("cls");
 
        exit(0);
 
    }
 
    else
 
    {
 
        printf("\a");
 
        Move();
 
    }
}
 
void gotoxy(int x, int y)
{
 
 COORD coord;
 
 coord.X = x;
 
 coord.Y = y;
 
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
 }
void load(){
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}
void Down()
{
    int i;
    for(i=0;i<=(head.y-bend[bend_no].y)&&len<length;i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0;i<=(10000000);i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4;i<length;i++)   //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            exit(0);
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
 
            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0;i<=(bend[bend_no].x-head.x)&&len<length;i++)
    {
        GotoXY((head.x+i),head.y);
       {
                if(len==0)
                    printf("<");
                else
                    printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;
 
}
void Right()
{
    int i;
    for(i=0;i<=(head.x-bend[bend_no].x)&&len<length;i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no;i>=0&&len<length;i--)
    {
            if(bend[i].x==bend[i-1].x)
            {
                diff=bend[i].y-bend[i-1].y;
                if(diff<0)
                    for(j=1;j<=(-diff);j++)
                    {
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y+j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
                else if(diff>0)
                    for(j=1;j<=diff;j++)
                    {
                        /*GotoXY(bend[i].x,(bend[i].y-j));
                        printf("*");*/
                        body[len].x=bend[i].x;
                        body[len].y=bend[i].y-j;
                        GotoXY(body[len].x,body[len].y);
                        printf("*");
                        len++;
                        if(len==length)
                            break;
                    }
            }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1;j<=(-diff)&&len<length;j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                        printf("*");
                   len++;
                   if(len==length)
                           break;
               }
           else if(diff>0)
               for(j=1;j<=diff&&len<length;j++)
               {
                   /*GotoXY((bend[i].x-j),bend[i].y);
                   printf("*");*/
                   body[len].x=bend[i].x-j;
                   body[len].y=bend[i].y;
                   GotoXY(body[len].x,body[len].y);
                       printf("*");
                   len++;
                   if(len==length)
                       break;
               }
       }
   }
}
void Boarder()
{
   system("cls");
   int i;
   GotoXY(food.x,food.y);   /*displaying food*/
       printf("*");
   for(i=10;i<71;i++)
   {
       GotoXY(i,10);
           printf("!");
       GotoXY(i,30);
           printf("!");
   }
   for(i=10;i<31;i++)
   {
       GotoXY(10,i);
           printf("!");
       GotoXY(70,i);
       printf("!");
   }
}
void Print()
{
   //GotoXY(10,12);
   printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
  getch();
   system("cls");
   printf("\tGame instructions:\n");
   printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
   printf("\n\nPress any key to play game...");
   if(getch()==27)
   exit(0);
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j,px;
   FILE *info;
   info=fopen("record.txt","a+");
   getch();
   system("cls");
   printf("Enter your name\n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //to convert the first letter after space to capital
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tPlayers List\n");
   fprintf(info,"Player Name :%s\n",nplname);
    //for date and time
 
   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
     fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
     //fprintf(info,"\nLevel:%d\n",10);//call level to display level
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("wanna see past records press 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("record.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
}
int Score()
{
   int score;
   GotoXY(20,8);
   score=length-5;
   printf("SCORE : %d",(length-5));
   score=length-5;
   GotoXY(50,8);
   printf("Life : %d",life);
   return score;
}
int Scoreonly()
{
int score=Score();
system("cls");
return score;
}
void Up()
{
   int i;
   for(i=0;i<=(bend[bend_no].y-head.y)&&len<length;i++)
   {
       GotoXY(head.x,head.y+i);
       {
           if(len==0)
               printf("^");
           else
               printf("*");
       }
       body[len].x=head.x;
       body[len].y=head.y+i;
       len++;
   }
   Bend();
   if(!kbhit())
       head.y--;
}
//***********************************************************************************************
