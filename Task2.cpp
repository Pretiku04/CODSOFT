#include<iostream>
using namespace std;

#define RESET "\033[0m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_PURPLE "\033[96m"
int main()
{
    double num1,num2,result;
    int choice;

    cout<<BRIGHT_PURPLE<<"===========SIMPLE CALCULATOR==========\n"<<RESET;
    cout<<BRIGHT_RED<<"Enter First Number:\n"<<RESET;
    cin>>num1;
    cout<<BRIGHT_RED<<"Enter Second Number:\n"<<RESET;
    cin>>num2;
    cout<<BRIGHT_MAGENTA<<"\nOPERATION\n"<<RESET;
    cout<<BRIGHT_GREEN<<"1.ADDITION(+)\n"<<RESET;
    cout<<BRIGHT_GREEN<<"2.SUBTRACTION(-)\n"<<RESET;
    cout<<BRIGHT_GREEN<<"3.MULTIPLICATION(*)\n"<<RESET;
    cout<<BRIGHT_GREEN<<"4.DIVISON(/)\n"<<RESET;
    cout<<BRIGHT_MAGENTA<<"Now Choose your option\n"<<RESET;
    cin>>choice;

    switch(choice)
    {
        case 1:
            result=num1+num2;
            cout<<BRIGHT_YELLOW<<"RESULTS=\n"<<result<<RESET;
            break;
        case 2:
            result=num1-num2;
            cout<<BRIGHT_BLUE<<"RESULTS=\n"<<result<<RESET;
            break;
        case 3:
            result=num1*num2;
            cout<<BRIGHT_YELLOW<<"RESULTS=\n"<<result<<RESET;
            break;
        case 4:
            if (num2 !=0)
            {
                result=num1/num2;
            }
            else
            {
                cout<<BRIGHT_MAGENTA<<"Error!Divison by 0 is not allowed"<<RESET;
                return 1;
            }
            cout<<BRIGHT_BLUE<<"RESULTS=\n"<<result<<RESET;
            break;
        default:
                cout<<BRIGHT_MAGENTA<<"Invalid Option"<<RESET;
                break;

    }
    return 0;

}