#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

pair<int,int> findBest(int board[][3]);

////////////////////////////  delay ////////////////////////////////////////////
void delay(int x)
{
	for(int i=0;i<x;i++)
	{

	}
}
///////////////////////////////////////////////////////////////////////////////

////////////////////////////// Check if matrix is full /////////////////////////

bool isFull(int board[][3])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==-1)	return false;
		}
	}
	return true;
}
//////////////////////////////////////////////////////////////////////////////


///////////////////////// initialize  /////////////////////////////////////////

void initialize(int board[][3],string& player1,string& player2,int *p1,int *p2)
{
	cout<<"\n\tLoading.....";
	cout<<"\n\t";
	for(int i=0;i<50;i++)
	{
		cout<<"|";
		delay(20000000);
	}
	system("cls");
	cout<<"\n\t\t******************Lets play*********************\n"<<endl;
	cout<<"\n\tEnter name of player \t";
	cin>>player1;
	cout<<"\n\t"<<player1<<" choose your sign\n\t\t 1- *\n\t\t 0- O\t\t\t"<<endl;
	int ch;
	cin>>ch;
	*p1=ch;
	player2 = "Computer";

	if(*p1=='*')	*p2='O';
	else	*p2='*';

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=-1;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////


//////////////////////////////// print /////////////////////////////////////////
void print(int board[][3],int p1,int p2)
{
	char ch1,ch2;
	if(p1==1)
	{
		ch1='*';
		ch2='O';
	}
	else
	{
		ch1='O';
		ch2='*';
	}

	cout<<endl<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<"\t\t";
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==1)	cout<<ch1;
			else if(board[i][j]==2)	cout<<ch2;
			else	cout<<" ";
			if(j<2)	cout<<"|";
		}
		cout<<endl<<"\t\t-----"<<endl;

	}

}

////////////////////////////////////////////////////////////////////////////////



///////////////////////////////// check if wining condition  ///////////////////


////////// horizontal
bool checkhorizontal(int board[][3],int x)
{
	bool flag;
	for(int i=0;i<3;i++)	// check all 3 rows if any row contain all cells x return true
	{
		flag=true;
		for(int j=0;j<3;j++)	//check each cell
		{
			if(board[i][j]!=x)
			{
				flag=false;
				break;
			}
		}
		if(flag)	return true;
	}
	return false;
}

///////  vertical

bool checkvertical(int board[][3],int x)
{
	bool flag;
	for(int i=0;i<3;i++)	// check all 3 column if any row contain all cells x return true
	{
		flag=true;
		for(int j=0;j<3;j++)	// check each cell
		{
			if(board[j][i]!=x)
			{
				flag=false;
				break;
			}
		}
		if(flag)	return true;
	}

	return false;
}

/////////  diagonal
bool checkdiagonal(int board[][3],int x)
{
	bool flag=true;
	int i,j;
	for(i=0,j=0;i<3;i++,j++)
	{
		if(board[i][j]!=x)
		{
			flag=false;
			break;
		}
	}
	if(flag)	return true;

	flag=true;
	for(i=0,j=2;i<3;i++,j--)
	{
		if(board[i][j]!=x)
		{
			flag=false;
			break;
		}
	}
	if(flag)	return true;

	return false;
}

//// check all

bool checkwin(int board[][3],int x)
{
	if(checkhorizontal(board,x))	return true;
	if(checkvertical(board,x))	return true;
	if(checkdiagonal(board,x))	return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////////

int re(int board[][3])
{
	if(checkwin(board,2))	return 10;
	if(checkwin(board,1))	return -10;

	return 0;
}

/////////////////////// is move valid /////////////////////////////////////////
bool isValid(int board[][3],int x,int y)
{
	if(x>2 or x<0 or y>2 or y<0)
	{
		cout<<"\n\n\t\t\t-------> Select coordinate within limits "<<endl;
		return false;
	}
	if(board[x][y]==-1)	return true;

	cout<<"\n\t\t-------> Already filled"<<endl;
		return false;
}
///////////////////////////////////////////////////////////////////////////////


////////////////////////////////// toss ////////////////////////////////////////
bool toss(string player1)
{
	char t;
	while(1)
	{
		cout<<"\n\t\t**********Toss**********\n\n"<<endl;
		cout<<player1<<" select H or T"<<endl;
		cin>>t;
		if(t=='H' or t=='h')	break;
		else if(t=='T' or t=='t')	break;
		else
		{
			cout<<"\n\n\t\t*****Invalid Input*****"<<endl;
			system("cls");
		}
	}
	srand(time(0));
	int x = rand();
	x%=2;
	if(x==0 and (t=='H' or t=='h'))	return true;
	else if(x==1 and (t=='T' or t=='t'))	return true;
	return false;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// move players ////////////////////////////////

void move(int board[][3],string& player1,string& player2,int* p1,int* p2)
{
//////////////////////////////   TOSS   ///////////////////////////////////////
	bool flag;
	system("cls");
	cout<<"\n\n\t\t\tToss time"<<endl<<endl;

	if(toss(player1))
	{
		cout<<"\n\t\t"<< player1<<" will move first "<<endl;
		flag=true;
	}
	else
	{
		cout<<"\n\t\t"<< player2<<" will move first "<<endl;
		flag=false;
	}
	delay(300000000);
	system("cls");
////////////  TOSS   //////////////

	for(int i=0;i<9;i++)
	{
		if(flag)
		{
			int x,y;
			while(1)
			{
				cout<<"\n\t"<<player1<<" enter the cordinates you want to play ";
				cin>>x>>y;
				x--;
				y--;
				if(isValid(board,x,y))
				{
					board[x][y]=1;
					break;
				}

			}
			print(board,*p1,*p2);
			if(checkwin(board,1))
			{
				cout<<"\n\t\t\tGame End\n " ;
				cout<<"\n\n\t\tYeahhh!!!"<<  player1<<" win "<<endl;
				break;
			}
			flag=!flag;
		}

		else
		{
			int x,y;
			while(1)
			{
				pair<int,int> cell = findBest(board);
				x=cell.first;
				y=cell.second;
				if(isValid(board,x,y))
				{
					board[x][y]=2;
					break;
				}
			}

			cout<<"\n\n\t Computer's turn\n\n";
			print(board,*p1,*p2);
			if(checkwin(board,2))
			{
				cout<<"\n\t\t\tGame End\n " ;
				cout<<"\n\n\t\tYeahhh!!!"<<  player2<<" win "<<endl;
				break;
			}
			flag=!flag;

		}

		if(i==8)	cout<<"\n\n\t\t ***** Tie *****\n\n"<<endl;

	}

}
////////////////////////////////////////////////////////////////////////////////


//////////////////////////// MiniMax ///////////////////////////////////////////

int minimax(int board[][3], int depth,bool isMaxi)
{
	int score=re(board);
	if(score==10 or score== -10)	return score;

	if(isFull(board))	return 0;

	if(isMaxi)
	{
		int best_move=-INT_MAX;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j]==-1)
				{
					board[i][j]=2;
					best_move=max(best_move,minimax(board,depth+1,false));
					board[i][j]=-1;
				}
			}
		}

		return best_move;
	}
	else
	{
		int best_move=INT_MAX;

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j]==-1)
				{
					board[i][j]=1;
					best_move=min(best_move,minimax(board,depth+1,true));
					board[i][j]=-1;
				}
			}
		}
		return best_move;
	}
}
////////////////////////////////////////////////////////////////////////////////



/////////////////////////////// find best Move /////////////////////////////////

pair<int,int> findBest(int board[][3])
{
	int bestMove=-1000;
	pair<int,int> cell;

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j] == -1)
			{
				board[i][j]=2;
				int val=minimax(board,0,false);
				board[i][j]=-1;

				if(val>bestMove)
				{
					bestMove=val;
					cell.first=i;
					cell.second=j;
				}
			}
		}
	}

	return cell;
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////// Main ////////////////////////////////////////
int main()
{
	int board[3][3];
	string player1,player2;
	int p1,p2;
	int ch;

	do
	{
		system("cls");
		initialize(board,player1,player2,&p1,&p2);
		move(board,player1,player2,&p1,&p2);

		delay(200);

		cout<<"\n\n\n\t\t********** Thanks for playing the game *************"<<endl;
		cout<<"\n\n\t\t Do you want to play again \n\t\t1 - Yes \n\t\t0 - No \n\t\t";
		cin>>ch;
	}while(ch);

	return 0;
}

/////////////////////////////////////////// Made by - Diwakar Singh ////////////
