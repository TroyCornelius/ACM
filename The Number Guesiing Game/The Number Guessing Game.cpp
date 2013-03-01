#include <iostream>
#include <string>
using namespace std;

int _num, n;
char s[6][10]={"first","second","third","forth","fifth","sixth"};
string tmp;

void play()
{
     printf("Game starts!!\n\n");
     n = rand() % 99;
     for (int i=0; i<5; i++)   //here you can edit the guessing times
       {
          printf("This is your %s chance to guess.\n", s[i]);
          printf("Please input one num: ");
          cin >>_num;
          if (_num > n) printf("I'm sorry that the number you guess is bigger than the target!!\n\n");
          else 
          if (_num < n) printf("I'm sorry that the number you guess is smaller than the target!!\n\n");
          else
            {printf("Wow, congratulation to you! You guess the number!!\n\n");return;}
       }
     printf("I'm sorry you failed the Game! The number we set is %d.\n", n);
     
     }
int main()
{
    srand(time(NULL));
	printf("Welcome to play the Guessing Number Game\n");
	printf("You have only five chances to guess the number we set (0~99).\n");
	
	while (true)
	  {
          printf("Are you ready to play now? Please input Yes or No!\n");
          cin >>tmp;
          if (tmp == "Yes" || tmp == "YES" || tmp=="yes") play();
          else break;          
       printf("---------------------------------------------------------\n");
      }

    return 0;
    }
