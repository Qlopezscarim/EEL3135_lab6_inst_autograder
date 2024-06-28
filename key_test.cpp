#include "key_generator.h"

void print_vector(std::vector<double> to_print)
{
	for (double value:to_print)
	{
		std::cout << value << "\n";
	}

}


int main()
{
	std::vector<double> test = key_generator::mlab_colon(1,2,3);
	print_vector(test);
	std::cout << "Testing array comparison\n";
	std::vector<double> test1 = {0.00001,0.000003,0};
	std::vector<double> test2 = {0,0,0};
	std::cout << key_generator::comp_arrays_with_error(test1,test2);
	return 0;
}
