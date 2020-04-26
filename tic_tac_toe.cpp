/**********************************************************

	Tic_Tac_Toe in c++
	version 1.0
	simple AI - novice difficulty
	minimal gameplay
	
	made by RAKSHIT PRABHU

/**********************************************************/
#include<bits/stdc++.h>
#include<unistd.h>			//sleep function 
using namespace std;


int i,j,co1,co2,x=1,o=0,temp=5,upper=2,lower=0;
int arr[3][3];


void player()
{
	cout<<"enter the position at which you want to place X (0-1-2) : ";
	cin>>co1>>co2;
	arr[co1][co2]=x;
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
		if(arr[k][0]+arr[k][1]+arr[k][2]==3){
			cout<<"\nYou Won The Game\n";
			return 1;
		}
		else if(arr[0][k]+arr[1][k]+arr[2][k]==3){
				cout<<"\nYou Won The Game\n";
				return 1;
			}
		else{
			if(arr[k][k]+arr[k+1][k+1]+arr[k+2][k+2]==3||arr[0][2]+arr[1][1]+arr[2][0]==3){
				cout<<"\nYou Won The Game\n";
				return 1;
			}
		}
	}		
}


int checkcpu()
{
	for(int k=0;k<3;k++){
		if(arr[k][0]+arr[k][1]+arr[k][2]==0){
			cout<<"\nCpu Won The Game-You Lost\n";
			return 1;
		}
		else if(arr[0][k]+arr[1][k]+arr[2][k]==0){
				cout<<"\nCpu Won The Game-You Lost\n";
				return 1;
			}
		else{
			if(arr[k][k]+arr[k+1][k+1]+arr[k+2][k+2]==0||arr[0][2]+arr[1][1]+arr[2][0]==0){
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
	if(arr[posx][posy]==5)
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
	cout<<"You are 1 and the cpu is 0\n\n";
	sleep(2);
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
