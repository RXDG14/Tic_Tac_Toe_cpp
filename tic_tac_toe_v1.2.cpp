/**********************************************************

	Tic_Tac_Toe in c++
	version 1.1
	simple AI - novice difficulty
	minimal gameplay
	v1.2 changes:
				added 'draw' with win and loss
				added player vs player and cpu vs cpu
	
	code is really very bad and there is a lot of code repetition which is a bad practice will fix in next version
	
	made by RAKSHIT N PRABHU

/**********************************************************/
#include<bits/stdc++.h>
#include<unistd.h>			//sleep function 
using namespace std;


int i,j,co1,co2,upper=2,lower=0,ch;
char arr[3][3];
char x='X',o='O';
char temp='?',f='f';

void player()
{
	cout<<"enter the position at which you want to place X (0-1-2) : ";
	cin>>co1>>co2;
	if(arr[co1][co2]=='?')
		{arr[co1][co2]=x;}
	else
		{cout<<"\nwrong position\n";
		 player();
		}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<arr[i][j]<<"	";
		}
		cout<<"\n\n";
	}
}


void player1()
{
	cout<<"enter the position at which you want to place X (0-1-2) : ";
	cin>>co1>>co2;
	if(arr[co1][co2]=='?')
		{arr[co1][co2]=o;}
	else
		{cout<<"\nwrong position\n";
		 player();
		}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<arr[i][j]<<"	";
		}
		cout<<"\n\n";
	}
}


int checkplayer()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]=='X' && arr[k][1]=='X' && arr[k][2]=='X'){
			cout<<"\nPlayer1 Won The Game\n";
			return 1;
		}
		else if(arr[0][k]=='X' && arr[1][k]=='X' && arr[2][k]=='X'){
				cout<<"\nPlayer1 Won The Game\n";
				return 1;
			}
		else{
			if(arr[k][k]=='X' && arr[k+1][k+1]=='X' && arr[k+2][k+2]=='X' || arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'){
				cout<<"\nPlayer1 Won The Game\n";
				return 1;
			}
		}
	}		
}


int checkplayer1()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]=='O' && arr[k][1]=='O' && arr[k][2]=='O'){
			cout<<"\nPlayer1 Won The Game\n";
			return 1;
		}
		else if(arr[0][k]=='O' && arr[1][k]=='O' && arr[2][k]=='O'){
				cout<<"\nPlayer1 Won The Game\n";
				return 1;
			}
		else{
			if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O' || arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O'){
				cout<<"\nPlayer1 Won The Game\n";
				return 1;
			}
		}
	}		
}


int checkcpu()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]=='O' && arr[k][1]=='O' && arr[k][2]=='O'){
			cout<<"\nCpu Won The Game-You Lost\n";
			return 1;
		}
		else if(arr[0][k]=='O' && arr[1][k]=='O' && arr[2][k]=='O'){
				cout<<"\nCpu Won The Game-You Lost\n";
				return 1;
			}
		else{
			if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O' || arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O'){
				cout<<"\nCpu Won The Game-You Lost\n";
				return 1;
			}
		}
	}		
}


int checkcpu1()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]=='X' && arr[k][1]=='X' && arr[k][2]=='X'){
			cout<<"\nCPU1 Won The Game\n";
			return 1;
		}
		else if(arr[0][k]=='X' && arr[1][k]=='X' && arr[2][k]=='X'){
				cout<<"\nCPU1 Won The Game\n";
				return 1;
			}
		else{
			if(arr[k][k]=='X' && arr[k+1][k+1]=='X' && arr[k+2][k+2]=='X' || arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'){
				cout<<"\nCPU1 Won The Game\n";
				return 1;
			}
		}
	}		
}


void posfinder()			//to find position for cpu
{
	//srand(time(0));
	int posx = (rand()%(upper - lower + 1)) + lower;		//cpu position x generator
	int posy = (rand()%(upper - lower + 1)) + lower;		//cpu position y generator
	if(arr[posx][posy]=='?')
		{arr[posx][posy]=o;}
	//else if(arr[posy][posx]==5)
		//{arr[posy][posx]=o;}
	else
		{posfinder();}
}


void posfinder1()			//to find position for cpu
{
	//srand(time(0));
	int posx = (rand()%(upper - lower + 1)) + lower;		//cpu position x generator
	int posy = (rand()%(upper - lower + 1)) + lower;		//cpu position y generator
	if(arr[posx][posy]=='?')
		{arr[posx][posy]=x;}
	//else if(arr[posy][posx]==5)
		//{arr[posy][posx]=o;}
	else
		{posfinder1();}
}


void cpu()
{
	posfinder();
	sleep(2);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<arr[i][j]<<"	";
		}
		cout<<"\n\n";
	}
}


void cpu1()
{
	posfinder1();
	sleep(2);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<arr[i][j]<<"	";
		}
		cout<<"\n\n";
	}
}


int main()
{
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[i][j]=temp;
		}
	}
	cout<<"Tic Tac Toe Game\n\n";
	sleep(2);
	cout<<"choose :\n\n 1.Player vs CPU\n\n 2.player vs player\n\n 3.CPU vs CPU\n\n";
	cin>>ch;
	switch(ch)
		{
			case 1:{
				cout<<"You are X and the cpu is O\n\n";
				sleep(2);
				for(int m=0;m<9;m++){
					if(m%2==0){
						player();
							if(checkplayer()==1){return 0;}
						cout<<"_____________________________\n";
					}
					else{
						cpu();
							if(checkcpu()==1){return 0;}
						cout<<"_____________________________\n";
					}
				}
				int count=0;
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						if(arr[i][j]!='?'){
							count++;
						}
					}
				}
				if(count==9)
					{cout<<"\nits a draw!\n";}
			}
			case 2:{
				cout<<"Player1 is X and Player2 is O\n\n";
				sleep(2);
				for(int m=0;m<9;m++){
					if(m%2==0){
						player();
							if(checkplayer()==1){return 0;}
						cout<<"_____________________________\n";
					}
					else{
						player1();
							if(checkplayer1()==1){return 0;}
						cout<<"_____________________________\n";
					}
				}
				int count=0;
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						if(arr[i][j]!='?'){
							count++;
						}
					}
				}
				if(count==9)
					{cout<<"\nits a draw!\n";
					 return 0;
					}
			}
			case 3:{
				cout<<"CPU1 is X and CPU2 is O\n\n";
				sleep(2);
				for(int m=0;m<9;m++){
					if(m%2==0){
						cpu1();
							if(checkcpu1()==1){return 0;}
						cout<<"_____________________________\n";
					}
					else{
						cpu();
							if(checkcpu()==1){return 0;}
						cout<<"_____________________________\n";
					}
				}
				int count=0;
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						if(arr[i][j]!='?'){
							count++;
						}
					}
				}
				if(count==9)
					{cout<<"\nits a draw!\n";}
			}
	}
			
}
