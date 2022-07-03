#include<iostream>
#include<conio.h>
#include<random>
#include<ctime>

int main(void)
{
    srand(time(NULL));
    int seed=rand();
    int num;
    do
    {
        std::cout<<"Please input the number of students:";
        scanf("%d",&num);
        if(num<=1)
        {
            std::cout<<"Error! Input number out of range!"<<std::endl;
        }
    } while (num<=1);
    std::cout<<"The student numbers drawn are:(press any key to continue,or press ESC to exit)"<<std::endl;
    unsigned int last_num=0;
    unsigned int number;
      
    std::mt19937 gen(seed); 
    std::uniform_int_distribution<unsigned> distrib(1, num);
    do
    {
        number=distrib(gen);
        while(number==last_num)
        {
            number=distrib(gen);
        }
        std::cout<<number<<std::endl;
        last_num=number;
    } while (_getch()!=27);
    return 0;
           
}