#include<iostream>

#include "connect4.h"

using namespace std;

char place[6][7];//available for whole program

int main(){
	for(int i =0;i <= 5; i++){		//fill place with whitespace
		for(int j = 0; j<=6; j++)
			place[i][j] = ' ';		
	}								
	display();//Displays board
	int hold;//user row choice
	int hold2 = 0;// drop value
	int charsPlaced = 0;//Number of peices dropped 
	bool gamewon = false;
	char player = 50;//start as player 2 will change back 2 player 1
	while(!gamewon){
		if(hold2 != -1){//check if there was a error in the last drop
			if(player == 50){//if player 2 lasted dropped a piece so its player 1s turn
				cout<<"player 1 drop where?";
				player = 49;//char of players piece
			}
			else if (player==49){
				cout<<"player 2 drop where?";
				player = 50;//char of player piece
			}
		}
		while(true){//will run untill 'break;'
			if(charsPlaced == 42) break;//if draw
			cin>>hold;//get user input
			hold--;//take off 1 to account for arrays starting at 0 not 1
			if(hold <=6 && hold>= 0) break;//if within valid range stop loop
			else cout<< "\nplease enter a value between 1 and 7 :";//ask for input and loop again
			if (cin.fail())	//catch a non number
			{						//
				cin.clear();		//Stops cin trying to put its value in to hold
				char c;			//Try entering a non number without this, 2 see what this does
				cin>>c;			//
			}						//Catch a non number

		}
		if(charsPlaced == 42) break;//if draw
		hold2 = drop(hold,player);//drop the player store the row in hold2
		if(hold2 == -1)	cout<<"Colom is full\nPlease enter anothor number between 1 and 7:";//if error -1 row is full
		else{
			gamewon = check(hold2,hold);//check if game is run
			charsPlaced ++;//another character has been succesfully placed
			display();//displayed updated board
		}
	}
	if(charsPlaced == 42){//if draw
		cout<<"No winner, Game was draw\n";
		return 0;
	}
	if(player == 50)//if won by player 2
		cout<<"gamewon by : player 2\n";
	else if (player == 49)
	cout<<"gamewon by : player 1\n";//Else won by player 1
	return 0;//Exit application
}
void display(){
	cout<<" 1   2   3   4   5   6   7\n";
	for(int i = 0; i<= 5; i++)
	{
		for(int j =0; j <= 6; j++) cout<< "[" <<place[i][j]<< "]" <<" ";
		cout<<'\n';
	}
}
bool check(int a, int b){
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = place[a][b];
	int i;//vertical
	int j;//horizontal
	//check for vertical(|)
	for(i = a +1;place[i][b] == player && i <= 5;i++,vertical++);//Check down
	for(i = a -1;place[i][b] == player && i >= 0;i--,vertical++);//Check up
	if(vertical >= 4)return true;
	//check for horizontal(-)
	for(j = b -1;place[a][j] == player && j >= 0;j--,horizontal++);//Check left
	for(j = b +1;place[a][j] == player && j <= 6;j++,horizontal++);//Check right
	if(horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for(i = a -1, j= b -1;place[i][j] == player && i>=0 && j >=0; diagonal1 ++, i --, j --);//up and left
	for(i = a +1, j = b+1;place[i][j] == player && i<=5 && j <=6;diagonal1 ++, i ++, j ++);//down and right
	if(diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for(i = a -1, j= b +1;place[i][j] == player && i>=0 && j <= 6; diagonal2 ++, i --, j ++);//up and right
	for(i = a +1, j= b -1;place[i][j] == player && i<=5 && j >=0; diagonal2 ++, i ++, j --);//up and left
	if(diagonal2 >= 4) return true;
	return false;
}
int drop(int b, char player){
	if(b >=0 && b<= 6)
	{
		if(place[0][b] == ' '){
			int i;
			for(i = 0;place[i][b] == ' ';i++)
				if(i == 5){place[i][b] = player;
			return i;}
			i--;
			place[i][b] =player;
			return i;

		}
		else{
			return -1;
		}

	}
	else{
		return -1;
	}

}


