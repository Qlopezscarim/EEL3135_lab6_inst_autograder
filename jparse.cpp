#include "jparse.h"
#include "key_generator.h"

//Shoutout chatgpt for this function
std::vector<std::string> extractstrings(const std::string& input) {
    std::string result;
    std::vector<std::string> to_return;
    size_t pos = 0;

    while (pos < input.length()) {
        // Find the opening quote
        size_t start = input.find('"', pos);
        if (start == std::string::npos)
            break;

        // Find the closing quote
        size_t end = input.find('"', start + 1);
        if (end == std::string::npos)
            break;

        // Extract the quoted substring
        std::string quoted = input.substr(start + 1, end - start - 1);
        to_return.push_back(quoted);

        // Move to the next position after the closing quote
        pos = end + 1;
    }
    return to_return;
}

jparse::jparse(std::string json_file)
{
	number_of_pairs = 0; //setup for tracking how many next vars
	array_index = 0;
	
	std::string buffer;
	std::ifstream read_me(json_file);
	//while(getline(read_me,buffer))
	//{
	//buffer
	//}
	getline(read_me,buffer); //it should be a single line hence only one function call
	name_dtype = extractstrings(buffer);
	for (std::string value:name_dtype)
	{
	//std::cout << value << "\n";
	number_of_pairs++;
	}
}

bool jparse::next_var() //literally just compares files. Not that deep
{
	bool to_return = false;
	number_of_pairs--; //tracking how many files to compare
	number_of_pairs--;
	
	std::string file_to_check = name_dtype[array_index];
	std::string file_to_compare = name_dtype[array_index] + "_key";
	array_index++; //move to data type
	
	std::string datatype = name_dtype[array_index++]; //postinc - next name
	
	
	//open file here
	std::ifstream to_check(file_to_check);
	std::ifstream to_compare(file_to_compare);
	
	std::vector<double> double_array;
	std::vector<double> double_array_2;
	//std::vector<string> string_array;
	if(datatype == "double")
	{
		double buffer;
		while(to_check >> buffer)
		{
			//std::cout << "good";
			//std::cout << buffer;
			double_array.push_back(buffer);
		}
		while(to_compare >> buffer)
		{
			double_array_2.push_back(buffer);
		}
		if(double_array_2 == double_array)
		{
			to_return = true;
		}
	}

	//for (double value: double_array)
	//{
	//	std::cout << value << "\n";
	//}

	return to_return;
}
bool jparse::freq_response(std::vector<double> b_k) //literally just compares files. Not that deep
{
	double me_pi = 3.141592653589793; //This is actually what matlab uses unless you use format long
	bool to_return = false;
        number_of_pairs--; //tracking how many files to compare
        number_of_pairs--;

        std::string file_to_check = name_dtype[array_index];
        array_index++; //move to data type

        std::string datatype = name_dtype[array_index++]; //postinc - next name


        //open file here
        std::ifstream to_check(file_to_check);

        std::vector<double> user_array;
        //std::vector<string> string_array;
        if(datatype == "double")
        {
                double buffer;
                while(to_check >> buffer)
                {
                        user_array.push_back(buffer);
                }
        }
	std::vector<double> autograder_array = key_generator::dynamic_w(-me_pi,user_array,me_pi);
	//std::cout << "Testing " << me_pi << "\n";
	autograder_array = key_generator::freq_resp_me(b_k,autograder_array);
	/*for(double my_value:autograder_array)
	{
		std::cout << my_value << "\n";
	}*/ //usefull for debugging

        return key_generator::comp_arrays_with_error(user_array,autograder_array);
}

bool jparse::check_freq(double freq_to_check,double error) //literally just compares files. Not that deep
{
        double me_pi = 3.141592653589793; //This is actually what matlab uses unless you use format long
        number_of_pairs--; //tracking how many files to compare
        number_of_pairs--;

        std::string file_to_check = name_dtype[array_index];
        array_index++; //move to data type

        std::string datatype = name_dtype[array_index++]; //postinc - next name


        //open file here
        std::ifstream to_check(file_to_check);

        std::vector<double> user_array;
        //std::vector<string> string_array;
        if(datatype == "double")
        {
                double buffer;
                while(to_check >> buffer)
                {
                        user_array.push_back(buffer);
                }
        }
        std::vector<double> freq_user = key_generator::dynamic_w(-me_pi,user_array,me_pi);
	size_t index_to_check = key_generator::get_freq_index(freq_user,freq_to_check);
	bool to_return = false;
	if(user_array[index_to_check-1] < 0+error)
		{to_return = true;}
	if(user_array[index_to_check] < 0+error)
                {to_return = true;}
	if(user_array[index_to_check+1] < 0+error)
                {to_return = true;}

	//Want to verify they used a sufficient W array
	if(freq_user.size() < 2000)
	{
		to_return = false;
		std::cout << "The autograder has detected that you have not used a sufficiently small step size for this part.";
	}

        return to_return;
}
