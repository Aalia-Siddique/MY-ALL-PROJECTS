#include<iostream>
using namespace std;
enum PlayerTurn{FIRST_PLAYER=1,SECOND_PLAYER=2};
enum GameStatus{DRAW,WIN,IN_PROGRESS};
class GameBoard{
	private:
		char data[3][3];
		GameStatus  gameStatus=IN_PROGRESS;
		int validCountMoves=0;
		bool checkRowEqual(char(*p)[3],int rowIndex,char ch,char ch2)
		{
			int count=0,count1=0;
			for(int i=0;i<3;i++)
			{
     			if(p[rowIndex][i]==ch)
     			{
     			count=count+1;
				}
				if(p[rowIndex][i]==ch2)
     			{
     				count1=count1+1;
	 			}
	 		}
	 		if(count==3&&count1==3)
 			{
  				return true;
  			}
  			else
  			{
  				return false;
			}
		}
		bool checkColEqual(char(*p)[3],int colIndex,char ch,char ch2)
		{

			int count=0,count1=0;
			for(int i=0;i<3;i++)
			{
     			if(p[i][colIndex]==ch)
     			{
     				count=count+1;
				 }
	 			if(p[i][colIndex]==ch2)
    			 {
     				count1=count1+1;
				 }
	
  			}
  			 if(count==3&&count1==3)
  			{
  				return true;
  			}
  			else 
  			{
  				return false;
  			}	
	
  		}
  		
		bool checkLefttDiagnol(char(*p)[3],char ch,char ch2)
		{

			int count=0,count1=0,j;
			for(int i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
	 			{
	  				if(i==j)
	  				{
           				if(p[i][j]==ch)
           				{
     	    				count=count+1;
	    				}
	       				if(p[i][j]==ch2)
           				{
        					count1=count1+1;
	       				}
	   				}
   				}
   			}
   			if(count==3&&count1==3)
  			{
  				return true;
  			}
  			else 
  			{
  				return false;
  			}
		}
		bool checkRightDiagnol(char(*p)[3],char ch,char ch2)
		{

			int count=0,count1=0,j;
			for(int i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
	 			{
	  				if((i+j)%2==0)
	  				{
           				if(p[i][j]==ch)
           				{
     	    				count=count+1;
	    				}
	       				if(p[i][j]==ch2)
           				{
        					count1=count1+1;
	       				}
	   				}
   				}
   			}
   			if(count==3&&count1==3)
  			{
  				return true;
  			}
  			else 
  			{
  				return false;
  			}
		}

		public:
			GameBoard()
			{
				int k=0;
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						data[i][j]=k;
						k++;
					}
				}
			}
			void displayBoard()
			{
				for(int i=0;i<3;i++)
				{
					for(int j=0;j<3;j++)
					{
						cout<<data[i][j];
					}
				}
			}
			void makeBoard(char pos,char playerSymbol)
			{
				if((isValidPosition(pos))&&(!isAlreadyMarked(pos)))
				{
					data[0][pos-1]= playerSymbol;
					validCountMoves++;
					
				}
			}
			bool isValidPosition(char pos)
			{
				if(pos>='1'&&pos<='9')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			bool isAlreadyMarked(char pos)
			{
				if(pos=='X'||pos=='Y')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			int getValidMovesCount()
			{
				return  validCountMoves;
			}
			GameStatus getGamesStatus()
			{
				for(int i=0;i<3;i++)
				{
					if(checkRowEqual(data,i,'X','Y')||checkColEqual(data,i,'X','Y')||checkLefttDiagnol(data,'X','Y')||checkRightDiagnol(data,'X','Y'))
					{
						gameStatus=WIN;
					}
					if(gameStatus==WIN)
					{
						return gameStatus;
					}	
				
				}
				gameStatus=DRAW;
				return gameStatus;
				
			}
};
int main()
{
	
}
