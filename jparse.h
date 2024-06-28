#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class jparse
{
	public:
	std::vector<std::string> name_dtype;
	int number_of_pairs;
	int array_index;

	jparse(std::string json_file);      //constructor to initialize
	bool next_var();
	bool freq_response(std::vector<double> b_k);
	bool check_freq(double freq_to_check, double error); 
};
