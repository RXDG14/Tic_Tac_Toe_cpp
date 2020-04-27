/**********************************************************

	Tic_Tac_Toe in c++
	version 1.1
	simple AI - novice difficulty
	minimal gameplay
	v1.1 changes:
				replaced all 1 and 0 with X and O
				fixed wrong position error
	
	made by RAKSHIT N PRABHU

/**********************************************************/
#include<bits/stdc++.h>
#include<unistd.h>			//sleep function 
using namespace std;


int i,j,co1,co2,upper=2,lower=0;
char arr[3][3];
char x='X',o='O';
char temp='?';

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


int checkplayer()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]=='X' && arr[k][1]=='X' && arr[k][2]=='X'){
			cout<<"\nYou Won The Game\n";
			return 1;
		}
		else if(arr[0][k]=='X' && arr[1][k]=='X' && arr[2][k]=='X'){
				cout<<"\nYou Won The Game\n";
				return 1;
			}
		else{
			if(arr[k][k]=='X' && arr[k+1][k+1]=='X' && arr[k+2][k+2]=='X' || arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'){
				cout<<"\nYou Won The Game\n";
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


int main()
{
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			arr[i][j]=temp;
		}
	}
	cout<<"Tic Tac Toe Game\n\n";
	sleep(2);
	cout<<"You are X and the cpu is O\n\n";
	sleep(2);
	player();
	cout<<"_____________________________\n";
	cpu();
	cout<<"_____________________________\n";
	player();
	cout<<"_____________________________\n";
	cpu();
	cout<<"_____________________________\n";
	player();
		if(checkplayer()==1){return 0;}
	cout<<"_____________________________\n";
	cpu();
		if(checkcpu()==1){return 0;}
	cout<<"_____________________________\n";
	player();
		if(checkplayer()==1){return 0;}
	cout<<"_____________________________\n";
	cpu();
		if(checkcpu()==1){return 0;}
	cout<<"_____________________________\n";
	player();
		if(checkplayer()==1){return 0;}
	cout<<"_____________________________\n";
}
