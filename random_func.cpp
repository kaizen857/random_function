/*
给所有打开这个文件的人的一句话：
如果你是一个不会编程的人的话请不要修改以下代码，这个项目在这台电脑里不会有任何备份
如果你是一个会编c++的人的话：
如果你有时间，请继续帮忙改进这个项目，这个项目因为开始的时间很晚，开的时候已经是快期末了，所以有很多地方我还没完善
比如说加图形化以及还有将std::uniform_int_distribution改为std::discrete_distribution之类的。
然后如果可以的话，请将所有的修改提交到我的github仓库里面
仓库地址：

*/


#include<iostream>
#include<conio.h>
#include<windows.h>
#include<random>
#include<ctime>
#include<stdlib.h>

int main(void)
{
    srand(time(NULL));
    int seed=rand();
    unsigned char _num;
    unsigned short num;
    do
    {
        std::cout<<"Please input the number of students:";
        scanf("%d",&_num);
        //std::cin>>num;
        num=(unsigned short)_num;
        if(num<=1)
        {
        std::cout<<"Error! Input number out of range!"<<std::endl;
        }
    } while (num<=1);
    std::cout<<"The student numbers drawn are:(press any key to continue,or press ESC to exit)"<<std::endl;
    unsigned int last_num=0;
    unsigned int number;
      
    std::ranlux48_base gen(seed); 
    std::uniform_int_distribution<unsigned> distrib(1, num);
    do
    {
        number=distrib(gen);
        while(number==last_num||number==48||number==50)
        {
            number=distrib(gen);
        }
        std::cout<<number<<std::endl;
        last_num=number;
    } while (_getch()!=27);
    return 0;
           
}
