/**********************************************************

	Tic_Tac_Toe in c++
	version 1.3
	simple AI - easy to moderate difficulty
	minimal gameplay
	v1.3 changes:
				Difficulty improved
	
	made by RAKSHIT N PRABHU

/**********************************************************/
#include<bits/stdc++.h>
#include<unistd.h>			//sleep function 
using namespace std;


int i,j,co1,co2,upper=2,lower=0,ch;
char arr[3][3];
char x='X',o='O';
char temp='?',f='f';


int draw()
{
	int count=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(arr[i][j]!='?'){
				count++;
			}
		}
	}
	if(count==9){
		cout<<"\nits a draw!\n";
		return 1;
	}
}


void player(int m)
{
	cout<<"enter the position at which you want to place X (0-1-2) : ";
	cin>>co1>>co2;
	if(arr[co1][co2]=='?' && m%2==0)
		{arr[co1][co2]=x;}
	else if(arr[co1][co2]=='?' && m%2!=0)
		{arr[co1][co2]=o;}
	else
		{cout<<"\nwrong position\n";
		 player(m);
		}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<arr[i][j]<<"	";
		}
		cout<<"\n\n";
	}
}


int checkplayer(int m)
{
	for(int k=0;k<3;k++){
		if(((arr[k][0]=='X' && arr[k][1]=='X' && arr[k][2]=='X' )||( arr[0][k]=='X' && arr[1][k]=='X' && arr[2][k]=='X')||(arr[k][k]=='X' && arr[k+1][k+1]=='X' && arr[k+2][k+2]=='X' )||( arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X'))){
			if(m%2==0){cout<<"\nPlayer1 Won The Game\n";}
			else{cout<<"\nCPU2 Won The Game\n";}
			return 1;
		}
	}			
}


int checkcpu(int m)
{
	for(int k=0;k<3;k++){
		if(((arr[k][0]=='O' && arr[k][1]=='O' && arr[k][2]=='O' )||(arr[0][k]=='O' && arr[1][k]=='O' && arr[2][k]=='O' )||(arr[0][0]=='O'&& arr[1][1]=='O' && arr[2][2]=='O')||(arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O'))){
			if(m%2==0){cout<<"\nCpu1 Won The Game\n";}
			else {cout<<"\nPlayer2 Won The Game\n";}
			return 1;
		}
	}		
}


void posfinder(int m)			//to find position for cpu
{
	//srand(time(0));
	int posx = (rand()%(upper - lower + 1)) + lower;		//cpu position x generator
	int posy = (rand()%(upper - lower + 1)) + lower;		//cpu position y generator
	if(arr[posx][posy]=='?' && m%2!=0)
		{arr[posx][posy]=o;}
	else if(arr[posx][posy]=='?' && m%2==0)
		{arr[posx][posy]=x;}
	else
		{posfinder(m);}
}


void cpu(int m)
{
	posfinder(m);
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
				srand(time(0));
				cout<<"You are X and the cpu is O\n\n";
				sleep(2);
				for(int m=2;m<11;m++){
					if(m%2==0){
						player(m);
							if(checkplayer(m)==1){return 0;}
						cout<<"_____________________________\n";
					}
					else{
						cpu(m);
							if(checkcpu(m)==1){return 0;}
						cout<<"_____________________________\n";
					}
				}
				if(draw()==1){return 0;}
			}
			
			
			case 2:{
				srand(time(0));
				cout<<"Player1 is X and Player2 is O\n\n";
				sleep(2);
				for(int m=0;m<9;m++){
					player(m);
						if(checkplayer(m)==1){return 0;}
						else if(checkcpu(m)==1){return 0;}
						else {;}
					cout<<"_____________________________\n";
				}
				if(draw()==1){return 0;}
			}
			
			
			case 3:{
				srand(time(0));
				cout<<"Player1 is X and Player2 is O\n\n";
				sleep(2);
				for(int m=0;m<9;m++){
						cpu(m);
							if(checkcpu(m)==1){return 0;}
							else if(checkplayer(m)==1){return 0;}
							else {;}
						cout<<"_____________________________\n";
				}
				if(draw()==1){return 0;}
			}
	}
			
}
