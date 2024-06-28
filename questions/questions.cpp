#include "questions.h"
    
questions::questions()
{
}

std::vector<double> questions::question1(int l)
{
	std::vector<double> to_return;
	int step = 3;
	int time = 0;
	while(l > 0)
	{
		if(time != step)
		{to_return.push_back(0);} //zero unless step function
		else
		{to_return.push_back(1);} //one when step function
		time = time + 1;
		l = l - 1;
	}
	return to_return;
}

std::vector<double> questions::question2(int l)
{
	std::vector<double> to_return;
        int time = 0;
        while(l > 0)
        {
                to_return.push_back(std::pow((8.0/9.0),time)); //remember not to do something like 8/9, do not want int division, good ol' AP CSA review
		time = time + 1;
		l = l - 1;
        }
	return to_return;

}

std::vector<double> questions::question3(int l)
{
	std::vector<double> to_return;
        int time = 0;
        while(l > 0)
        {
                to_return.push_back(std::pow((-8.0/9.0),time));
                time = time + 1;
		l = l - 1;
        }
	return to_return;
}

std::vector<double> questions::question4(int l)
{
	std::vector<double> to_return;
        int end_unit = 5;
        int time = 0;
        while(l > 0)
        {
                if(time < end_unit)
                {to_return.push_back(1);} //zero unless step function
                else
                {to_return.push_back(0);} //one when step function
                time = time + 1;
		l = l - 1;
        }
	return to_return;
}

std::vector<double> questions::question5(int l)
{
	double me_pi = 3.141592653589793;
	std::vector<double> to_return;
        int time = 0;
        while(l > 0)
        {
                to_return.push_back(std::cos( (me_pi/4) * time) ); //one when step function
                time = time + 1;
                l = l - 1;
        }
	return to_return;

}
double questions::question6()
{
	return 1.42314;
}
