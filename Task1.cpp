#include<iostream>
#include<cstdlib>
#include<ctime>

#define RESET "\033[0m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_PURPLE  "\033[96m"
#define BRIGHT_WHITE    "\033[97m"
#define BRIGHT_PINK         "\033[95m"
int main()
{
std::srand(std::time(nullptr));

int secretnumber=1+(std::rand()%100);

int guess=0;
int attempts=0;

std::cout<<BRIGHT_PURPLE<<"=======================NUMBER GUESSING GAME=========================\n"<<RESET;
std::cout<<BRIGHT_BLUE<<"Welcome To The Game\n"<<RESET;
std::cout<<BRIGHT_MAGENTA<<"Now,I'm thinking of a number between 1 and 100.\n"<<RESET;
std::cout<<BRIGHT_YELLOW<<"Can you guess what it is?\n"<<RESET;

while(guess!=secretnumber)
{
    std::cout<<BRIGHT_WHITE<<"Please enter your Guess:\n"<<RESET;
    std::cin>>guess;
    attempts++;
    if(guess<secretnumber)
    {
        std::cout<<BRIGHT_RED<<"OOPS!TOO LOW.\n"<<RESET;
        std::cout<<BRIGHT_GREEN<<"Try again.\n"<<RESET;
    }
    else if(guess>secretnumber)
    {
        std::cout<<BRIGHT_RED<<"OOPS!TOO HIGH.\n"<<RESET;
        std::cout<<BRIGHT_GREEN<<"Please Try again.\n"<<RESET;
    }
    else
    {
        std::cout<<BRIGHT_PINK<<"CONGRATULATIONS!\n"<<RESET;
        std::cout<<BRIGHT_RED<<"You guessed the number in "<<attempts<<" attempts!"<<RESET<<"\n";
    }
}

return 0;
}