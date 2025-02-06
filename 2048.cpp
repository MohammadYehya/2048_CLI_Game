#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
void title();//To print 2048
void credits();//To print credits
void checkupdate(int n);//To maintain and update info about the board
int checkisfull();//To check if the board is full
void printboard();//To print the board
int keystroke();//To check and update after a key is pressed
int menu();//To print and maintain the menu
int diff();//To print and maintain the difficulty menu
void inst();//To print the instructions
int excheck(int n);//To check if the user really wants to exit
int GameOver();//To check is the game is over
int GameWon();//To check if the game is won
int bombexplode();//To check if the bomb has exploded
int conv(char p[]);//To convert a char to an integer
void delay(int ms);//To put a delay likke sleep function
int readtimesettings();//To read a file containing the timer settings
void displaytimer();//To print and display the timer
void settings();//To configure a file containing settings of the user

int board[4][4] = {0},added[4][4] = {0};
int emptycheck[16] = {0};
int b,c,z,second ,msecond , fsecond, tcolor;
char space[100] = ""; //for centering the program
char temp[10];
FILE *f = fopen("Test.txt" ,"r+");
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	fseek(f , 39 , SEEK_SET);
	fscanf(f , "%s" , temp);
	tcolor = conv(temp);
	srand(time(NULL));//For true Randomness
	getch();
	title();
	credits();
	printf("\n%s",space);
	printf("\t\t\t\t\t\t\t\tPress any key to continue...\n");
	getch();
	Back:
	readtimesettings();
	system("CLS");//To clear screen
	for (int i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			board[i][j] = 0;
		}
	}
	z = menu();
	if (z == 0)
	{
		z = diff();
		if (z == 0)
		{
			//Normal Mode
			z = 1;
			while (true)
			{
				title();
				if (z == 1)
				{
					checkupdate(14);
				}
				printboard();
				z = 0;
				z = GameWon();
				if (z == 1)
				{
					printf("\n\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\bYou Won!");
					printf("\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
					do 
					{
						z = getch();	
					}
					while (z != 13);
					system("CLS");
					goto Back;
				}
				b = 0;
				b = GameOver();
				if (b == 1 && checkisfull() == 1)
				{
					printf("\n\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\bGame Over!");
					printf("\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
					do 
					{
						z = getch();	
					}
					while (z != 13);
					system("CLS");
					goto Back;
				}
				z = keystroke();
				if (z == 88)
				{
					goto Back;
				}
				system("CLS");
			}
		}
		else if (z == 1)
		{
			//Hard Mode
			z = 1;
			while (true)
			{
				title();
				if (z == 1)
				{
					checkupdate(29);
				}
				printboard();
				z = GameWon();
				if (z == 1)
				{
					printf("\n\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\bYou Won!");
					printf("\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
					do 
					{
						z = getch();	
					}
					while (z != 13);
					system("CLS");
					goto Back;
				}
				z = 0;
				z = GameOver();
				b = 0;
				b = bombexplode();
				if ((z == 1 && checkisfull() == 1 )|| (b == 1))
				{
					printf("\n\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\bGame Over!");
					if (b == 1)
					{
						printf("\n%s",space);
						printf("\t\t\t\t\t\t\t\t\t\bBomb has Exploded!");
					}
					printf("\n");
					printf("%s",space);
					printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
					do 
					{
						z = getch();	
					}
					while (z != 13);
					system("CLS");
					goto Back;
				}
				z = keystroke();
				if (z == 88)
				{
					goto Back;
				}
				system("CLS");
			}
		}
		else if (z == 2)
		{
			//Expert Mode
			z = 1;
			fsecond = readtimesettings();
			second = fsecond;
			msecond = 1000;
			while (true)
			{
				c = 0;
				title();
				if (z == 1)
				{
					second = fsecond;
					msecond = 1000;
					checkupdate(29);
				}
				printboard();
				while(!kbhit() && second >= 0)//kbhit() is the function to check whether the keyboard was hit or not
				{
					system("CLS");
					title();
					printboard();
					msecond -= 50;
					displaytimer();
					delay(50);
					if (msecond <= 0)
					{
						second--;
						msecond = 1000;
					}
					if (second == -1)
	        		{
	        			c = 1;
					}
					z = GameWon();
					if (z == 1)
					{
						printf("\n\n");
						printf("%s",space);
						printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\bYou Won!");
						printf("\n");
						printf("%s",space);
						printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
						do 
						{
							z = getch();	
						}
						while (z != 13);
						system("CLS");
						goto Back;
					}
					z = 0;
					z = GameOver();
					b = 0;
					b = bombexplode();
					if ((z == 1 && checkisfull() == 1 ) || (b == 1) || (c == 1))
					{
						printf("\n\n");
						printf("%s",space);
						printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\b\bGame  Over!");
						if (b == 1)
						{
							printf("\n%s",space);
							printf("\t\t\t\t\t\t\t\t\t\bBomb has Exploded!");
						}
						if (c == 1)
						{
							printf("\n%s",space);
							printf("\t\t\t\t\t\t\t\t\t\t\b\b\b\b\bTime is Up!");
						}
						printf("\n");
						printf("%s",space);
						printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
						do 
						{
							z = getch();	
						}
						while (z != 13);
						system("CLS");
						goto Back;
					}
        		}
				z = keystroke();
				if (z == 88)
				{
					goto Back;
				}
				system("CLS");
			}
		}
		else if (z == 3)
		{
			//Back;
			goto Back;
		}
	}
	else if (z == 1)
	{
		//Instructions
		inst();
		goto Back;
	}
	else if (z == 2)
	{
		//Settings
		settings();
		goto Back;
	}
	else if (z == 3)
	{
		//Credits
		title();
		credits();
		printf("\n%s",space);
		printf("\t\t\t\t\t\t\t\t\b\b\bPress Enter to go Back to the Main Menu");
		do 
		{
			z = getch();	
		}
		while (z != 13);
		system("CLS");
		goto Back;
	}
	else if (z == 3)
	{
		//Exit
		excheck(0);
		goto Back;
	}
	return 0;
}

int menu()
{
	int b = 0,i,z;
	char menu [5][50] = {"Play" , "Instructions" , "Settings" , "Credits" , "Exit"};
	do
	{
		title();
		for (i = 0 ; i < 5 ; i++)
		{
			if (b == i)
			{
				SetConsoleTextAttribute(color, 4);
				printf("\n%s",space);
				printf("\t\t\t\t\t\t\t\t\t%s\n",menu[i]);
				SetConsoleTextAttribute(color, 15);
			}
			else
			{
				printf("\n%s",space);
				printf("\t\t\t\t\t\t\t\t\t%s\n",menu[i]);
			}
		}
		z = getch();
		if (z == 27)
		{
			excheck(0);
		}
		if (z == 224)
		{
			z = getch();
			if (z == 72)
			{
				if (b > 0)
				{
					b--;
				}
			}
			else if(z == 80)
			{
				if (b < 4)
				{
					b++;
				}
			}
		}
		system("CLS");
	}
	while (z != 13);
	return b;
}
int diff()
{
	char diff[3][50] = {"Normal Mode" , "Hard Mode" , "Expert Mode"};
	int a,i,z;
	do
	{
		title();
		printf("\n%s",space);
		printf("\t\t\t\t\t\t\t\t\tSelect Dificulty\n\n\t\t\t\t\t\t");
		printf("%s",space);
		for (i = 0 ; i < 3 ; i++)
		{
			if (a == i)
			{
				SetConsoleTextAttribute(color, 4);
				printf("%s \t\t   ",diff[i]);
				SetConsoleTextAttribute(color, 15);
			}
			else
			{
				printf("%s \t\t   ",diff[i]);
			}
		}
		if (a == 3)
		{
			SetConsoleTextAttribute(color, 4);
			printf("\n%s",space);
			printf("\t\t\t\t\t\t\t\t\t\t\b\b\bBack");
			SetConsoleTextAttribute(color, 15);
		}
		else
		{
			printf("\n%s",space);
			printf("\t\t\t\t\t\t\t\t\t\t\b\b\bBack");
		}
		z = getch();
		if (z == 27)
		{
			excheck(0);
		}
		if (z == 224)
		{
			z = getch();
			if (z == 75)
			{
				if (a > 0)
				{
					a--;
				}
			}
			else if(z == 77)
			{
				if (a < 3)
				{
					a++;
				}
			}
			else if (z == 80)
			{
				a = 3;
			}
			else if (z == 72)
			{
				a = 1;
			}
		}
		system("CLS");
	}
	while (z != 13);
	return a;
}
void inst()
{
	int z;
	do
	{
		system("CLS");
		title();
		SetConsoleTextAttribute(color, 3);
		printf("\n%s",space);
		printf("Normal Mode");
		SetConsoleTextAttribute(color, 15);
		printf("\n%s",space);
		printf("The aim of the game is simple. You have to get the number form the number 2048.");
		printf("\n%s",space);
		printf("You can only add same numbers, for example 2 can only add with 2 and 4 can only add with 4.");
		printf("\n%s",space);
		printf("If there are no more numbers that can be added on the board then it is Game over!");
		SetConsoleTextAttribute(color, 6);
		printf("\n%s",space);
		printf("Hard Mode");
		SetConsoleTextAttribute(color, 15);
		printf("\n%s",space);
		printf("This mode was created for the masters of the normal game.");
		printf("\n%s",space);
		printf("Hard mode follows all the rules of Normal Mode except that there is chance that a bomb randomly generates.");
		printf("\n%s",space);
		printf("If there are no more numbers that can be added on the board or you join two bombs it is Game over!");
		SetConsoleTextAttribute(color, 4);
		printf("\n%s",space);
		printf("Expert Mode");
		SetConsoleTextAttribute(color, 15);
		printf("\n%s",space);
		printf("This mode was created for those who are born for this game and crave a challenge.");
		printf("\n%s",space);
		printf("It follows all the rules of Hard mode except that there is a timer.");
		printf("\n%s",space);
		printf("If there are no more numbers that can be added on the board or you join two bombs or the timer runs out it is Game over!");
		printf("\n\n\n\n%s",space);
		printf("\t\t\t\t\t\t\t\t\tPress Enter to go Back");
		z = getch();
		if (z == 27)
		{
			excheck(0);
		}
	}
	while (z != 13);
	system("CLS");
}
int excheck(int n)
{
	int a = 0 , i;
	char ex[2][50] = {"N" , "Y"};
	char exn[2][100]={"\t\t\t\t\t\t\t\tAre you sure you want to exit?" ,
					 "\t\t\t\t\t\t\t\tYou Will Lose all your Progress"};
	do
	{
		system("CLS");
		title();
		printf("\n\n");
		for (i = 0 ; i <= n ; i++)
		{
			printf("\n%s",space);
			printf("%s",exn[i]);
		}
		printf("\n\n\t\t\t\t\t\t\t\t\t");
		printf("%s",space);
		for (i = 0 ; i < 2 ; i++)
			{
				if (a == i)
				{
					SetConsoleTextAttribute(color, 4);
					printf("%s\t\t",ex[i]);
					SetConsoleTextAttribute(color, 15);
				}
				else
				{
					printf("%s\t\t",ex[i]);
				}
			}
			z = getch();
		if (z == 224)
			{
				z = getch();
				if (z == 75)
				{
					if (a > 0)
					{
						a--;
					}
				}
				else if(z == 77)
				{
					if (a < 1)
					{
						a++;
					}
				}
			}
	}
	while (z != 13);
	system("CLS");
	if (n == 0)
	{
		if (a == 1)
		{
			exit(0);
		}
	}
	else if (n == 1)
	{
		if (a == 1)
		{
			return 1;
		}
	}
}




void checkupdate(int n)
{
	int numbers[29] = {2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,88};
	int i,j,k=0,temp;
	for (i = 0 ; i < 4 ; i++)
	{
		for (j = 0 ; j < 4 ; j++)
		{
			if (board[i][j] == 0)
			{
				emptycheck[k] = 1;
			}
			else
			{
				emptycheck[k] = 0;
			}
			k++;
		}
	}
		if (checkisfull() == 0)
		{
			do
			{
				temp = rand()%16;
			}
			while (emptycheck[temp] != 1);
		}
	k = 0;
	if (checkisfull() == 0)
	{
		for (i = 0 ; i < 4 ; i++)
		{
			for (j = 0 ; j < 4 ; j++)
			{
				if (k == temp)
				{
					board[i][j] = numbers[rand()%n];
					emptycheck[temp] = 0;
				}
				k = k + 1;
			}
		}
	}
}
int checkisfull()
{
	int flag,b;
	flag = 0;
	for (b = 0 ; b <16 ; b++)
	{
		if (emptycheck[b] == 1)
		{
			flag++;
		}
	}
	if (flag == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void printboard()
{
	int i,j;
	printf("\n\n");
	for (i = 0 ; i < 4 ; i++)
		{
			printf("\t\t\t\t\t\t\t\t\t");
			printf("%s",space);
			for (int j = 0 ; j < 4 ; j++)
			{
				switch(board[i][j])
				{
					// color = foreground + 16 * background
					case 0:
						SetConsoleTextAttribute(color, 255);
						break;
					case 2:
						SetConsoleTextAttribute(color, 224);
						break;
					case 4:
						SetConsoleTextAttribute(color, 96);
						break;
					case 8:
						SetConsoleTextAttribute(color, 192);
						break;
					case 16:
						SetConsoleTextAttribute(color, 64);
						break;
					case 32:
						SetConsoleTextAttribute(color, 208);
						break;
					case 64:
						SetConsoleTextAttribute(color, 80);
						break;
					case 88://Bomb
						SetConsoleTextAttribute(color, 4);
						break;
					case 128:
						SetConsoleTextAttribute(color, 159);
						break;
					case 176://BombExplode
						SetConsoleTextAttribute(color, 68);
						break;
					case 256:
						SetConsoleTextAttribute(color, 31);
						break;
					case 512:
						SetConsoleTextAttribute(color, 175);
						break;
					case 1024:
						SetConsoleTextAttribute(color, 47);
						break;
					case 2048:
						SetConsoleTextAttribute(color, 52);
						break;
				}
				if (board[i][j] == 88)
				{
					printf("%4c",board[i][j]);
				}
				else
				{
					printf("%4d",board[i][j]);
				}
				SetConsoleTextAttribute(color, 15);
			}
			printf("\n\n");
		}
}

int keystroke()
{
	int z,i,j,k,a;
	z = getch();
	if (z == 27)
	{
		z = excheck(1);
		if (z == 1)
		{
			return 88;
		}
		title();
		printboard();
	}
	if (z == 65)//CHEAT MODE
	{
		board[3][3] = 1024;
		return 1;
	}
	switch(z)
	{
		case 72:
			a = 0;
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 1 ; j < 4 ; j++)
				{
					a = j;
					for (k = j ; k > 0 ; k--)
					{
						if (board[k-1][i] == 0)
						{
							board[k-1][i] = board[a][i];
							board[a][i] = 0;
							a--;
						}
						else if(board[k-1][i] != board[a][i])
						{
							break;
						}
						else if (board[k-1][i] == board[a][i] && (added[k-1][i] == 0 && added[a][i] == 0))
						{
							board[k-1][i] *= 2;
							board[a][i] = 0;
							added[k-1][i] = 1;
						}	
					}
				}
			}
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 0 ; j < 4 ; j++)
				{
					added[i][j] = 0;
				}
			}
			return 1;
			break;
		case 80:
			a = 0;
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 2 ; j >= 0 ; j--)
				{
					a = j;
					for (k = j ; k < 3 ; k++)
					{
						if (board[k+1][i] == 0)
						{
							board[k+1][i] = board[a][i];
							board[a][i] = 0;
							a++;
						}
						else if(board[k+1][i] != board[a][i])
						{
							break;
						}
						else if (board[k+1][i] == board[a][i] && (added[k+1][i] == 0 && added[a][i] == 0))
						{
							board[k+1][i] *= 2;
							board[a][i] = 0;
							added[k+1][i] = 1;
						}
					}
				}
			}
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 0 ; j < 4 ; j++)
				{
					added[i][j] = 0;
				}
			}
			return 1;
			break;
		case 75:
			a = 0;
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 1 ; j < 4 ; j++)
				{
					a = j;
					for (k = j ; k > 0 ; k--)
					{
						if (board[i][k-1] == 0)
						{
							board[i][k-1] = board[i][a];
							board[i][a] = 0;
							a--;
						}
						else if(board[i][k-1] != board[i][a])
						{
							break;
						}
						else if (board[i][k-1] == board[i][a] && (added[i][k-1] == 0 && added[i][a] == 0))
						{
							board[i][k-1] *= 2;
							board[i][a] = 0;
							added[i][k-1] = 1;
						}
					}
				}
			}
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 0 ; j < 4 ; j++)
				{
					added[i][j] = 0;
				}
			}
			return 1;
			break;
		case 77:
			a = 0;
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 2 ; j >= 0 ; j--)
				{
					a = j;
					for (k = j ; k < 3 ; k++)
					{
						if (board[i][k+1] == 0)
						{
							board[i][k+1] = board[i][a];
							board[i][a] = 0;
							a++;
						}
						else if(board[i][k+1] != board[i][a])
						{
							break;
						}
						else if (board[i][k+1] == board[i][a] && (added[i][k+1] == 0 && added[i][a] == 0))
						{
							board[i][k+1] *= 2;
							board[i][a] = 0;
							added[i][k+1] = 1;
						}
					}
				}
			}
			for (i = 0 ; i < 4 ; i++)
			{
				for (j = 0 ; j < 4 ; j++)
				{
					added[i][j] = 0;
				}
			}
			return 1;
			break;
	}
	return 0;
}
int GameOver()
{
	int i,j,flag = 1;
	for (i = 0 ; i < 4 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			if (board[i][j] == board[i][j+1])
			{
				flag = 0;
				return flag;
			}
		}
	}
	for (i = 0 ; i < 4 ; i++)
	{
		for (j = 0 ; j < 3 ; j++)
		{
			if (board[j][i] == board[j+1][i])
			{
				flag = 0;
				return flag;
			}
		}
	}
	return flag;
}
int GameWon()
{
	int i,j,flag = 0;
	for (i = 0 ; i < 4 ; i++)
	{
		for (j = 0 ; j < 4 ; j++)
		{
			if (board[i][j] == 2048)
			{
				flag = 1;
				return flag;
			}
		}
	}
	return flag;
}
int bombexplode()
{
	int i,j,flag=0;
	for (i = 0 ; i < 4 ; i++)
	{
		for (j = 0 ; j < 4 ; j++)
		{
			if (board[i][j] == 176)
			{
				flag = 1;
				return flag;
			}
		}
	}
	return flag;
}
void credits()
{
	SetConsoleTextAttribute(color, 12);
	char arr[5][100] = {"\t\t\t\t\t\t\t\t\bMade By  : Mohammad Yehya Hayati" ,
						"\t\t\t\t\t\t\t\t\t\b\b\b\bStudent ID  : 21K-3309" ,
						"\t\t\t\t\t\t\t\t\t\b\bSection : BCS - 1G" ,
						"\t\t\t\t\t\t\t\t\bTeam Member : Asad Noor 21K-4678" ,
						"\t\t\t\t\t\t\t\t\b\b\bTeam Member : Deepak Chawla 21K-3955"};
	int i,j,k;
		for (i = 0 ; i < 5 ; i++)
		{
			printf("\n%s",space);
			for (j = 0 ; j < strlen(arr[i]) ; j++)
			{
				printf("%c",arr[i][j]);
				delay(50);
				if (kbhit() == 1)
				{
					goto endcr;
				}
			}
			delay (2000);
			printf("\n");
		}
		endcr:
		SetConsoleTextAttribute(color, 15);
}
void delay(int ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock());
}
void displaytimer()
{
	printf("\n%s",space);
	printf("\t\t\t\t\t\t\t\t\t\t\b\bTIMER");
	printf("\n%s",space);
	printf("\t\t\t\t\t\t\t\t\t\t\b\b%d : %d" , second , msecond);
}
int conv(char p[])
{
	int i , n = 1 , sum = 0;
	for (i = strlen(p) - 1; i >= 0 ; i--)
	{
		sum += (p[i] - 48) * n;
		n *= 10;
	}
	return sum;
}
int readtimesettings()
{
	fseek(f, 24 , SEEK_SET);
	fscanf(f , "%s" , temp);
	fsecond = conv(temp);
	printf("%d",fsecond);
	return fsecond;
}
void settings()
{
	int a = 0 , g[3] = {0} , i , j , t;
	char setting[][20] = {" Timer Selection" , "    Title Color"};
	char scale[2][3][20] = {{"1" , "2" , "3"} , {"GREEN" , " RED" , "BLUE"}};
	do
	{
		title();
		for (i = 0 ; i < 2 ; i++)
		{
			if (a == i)
			{
				SetConsoleTextAttribute(color, 4);
			}
			printf("\n%s",space);
			printf("\t\t\t\t\t\t\t\t\t");
			printf("%s\n",setting[i]);
			printf("\t\t\t\t\t\t\t\t\t");
			SetConsoleTextAttribute(color, 15);
			for (j = 0 ; j < 3 ; j++)
			{
				printf("%s",space);
				SetConsoleTextAttribute(color, 8);
				if (a == i)
				{
					if (g[a] == j)
					{
						SetConsoleTextAttribute(color, 4);
					}
					printf("%s\t",scale[i][j]);
				}
				else
				{
					printf("%s\t",scale[i][j]);
				}
			}
			SetConsoleTextAttribute(color, 15);
	 }
		printf("\n\n\t\t\t\t\t\t\t\t  Press Enter to Confirm Settings");
		z = getch();
		if (z == 77)
		{
			if (g[a] < 2)
			{
				g[a]++;
			}
		}
		else if (z == 75)
		{
			if (g[a] > 0)
			{
				g[a]--;
			}
		}
		else if (z == 72)
		{
			if (a > 0)
			{
				a--;
			}
		}
		else if (z == 80)
		{
			if (a < 1)
			{
				a++;
			}
		}
		system("CLS");
	}
	while (z != 13);
	fseek(f, 24 , SEEK_SET);
	fprintf(f , "%d" , g[0]);
	fseek(f, 15 , SEEK_CUR);
	t = g[1]==0?2:(g[1]==1?4:(g[1]==2?1:0));
	fprintf(f , "%d" , t);
	tcolor = t;
}


void title()
{
	SetConsoleTextAttribute(color, tcolor);
	printf("%s",space);
	printf("\t\t                   @@@@@@@@@@@             @@@@@@@@@@                     @@@@           @@@@@@@@@@@@\n");
	printf("%s",space);
	printf("\t\t                 @@@@@@@@@@@@@@@         @@@@@@@@@@@@@@                 @@@@@@         @@@@@@@@@@@@@@@@\n");
	printf("%s",space);
	printf("\t\t                  @@@@      @@@@@       @@@@@      @@@@@               @@@@@@@        @@@@@        @@@@@\n");
	printf("%s",space);
	printf("\t\t                             @@@@      @@@@@        @@@@@             @@@@@@@@        @@@@@        @@@@@\n");
	printf("%s",space);
	printf("\t\t                            @@@@@      @@@@@        @@@@@           @@@@   @@@         @@@@        @@@@\n");
	printf("%s",space);
	printf("\t\t                            @@@@       @@@@          @@@@          @@@@    @@@          @@@@@@  @@@@@@\n");
	printf("%s",space);
	printf("\t\t                          @@@@@        @@@@          @@@@        @@@@@     @@@            @@@@@@@@@@\n");
	printf("%s",space);
	printf("\t\t                         @@@@@         @@@@          @@@@       @@@@       @@@          @@@@@@  @@@@@@\n");
	printf("%s",space);
	printf("\t\t                       @@@@@           @@@@          @@@@      @@@@        @@@         @@@@        @@@@\n");
	printf("%s",space);
	printf("\t\t                     @@@@@             @@@@@        @@@@@     @@@@        @@@@@       @@@@@        @@@@@\n");
	printf("%s",space);
	printf("\t\t                   @@@@@                @@@@        @@@@      @@@@@@@@@@@@@@@@@@@@    @@@@@        @@@@@\n");
	printf("%s",space);
	printf("\t\t                 @@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@                    @@@         @@@@@@@@@@@@@@@@\n");
	printf("%s",space);
	printf("\t\t                 @@@@@@@@@@@@@@@@@@        @@@@@@@@@@                      @@@           @@@@@@@@@@@@\n");
	SetConsoleTextAttribute(color, 15);
}
