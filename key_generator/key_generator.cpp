#include "key_generator.h"

std::vector<double> key_generator::mlab_colon(double start,double step,double end)
{
	//implements matlabs 1:1:4 notation
	std::vector<double> to_build;
	double current = start;
	while(current <= end)
	{
		to_build.push_back(current);
		current = current + step;
	}
	//std::cout << "ran";
	return to_build;
}

std::vector<double> key_generator::dynamic_w(double start,std::vector<double> user_array,double end)
{
        //Tries to figure out the step size the user used.
        std::vector<double> to_build;
        double step = (end - start)/(user_array.size() - 1); //this could cause some weird stuff with edge cases
	//std::cout << "step: " <<step << "\n";
	//std::cout << "diff: " << (end-start) << "\n";
	//std::cout << "size: " << user_array.size() << "\n";
	to_build = mlab_colon(start,step,end);
        return to_build;
}



std::vector<double> key_generator::freq_resp_me(std::vector<double> b,std::vector<double> w)
{
	std::vector<double> h_return;
	std::vector<double> k_array = key_generator::mlab_colon(0,1,size(b)-1);
	std::vector<double> value = key_generator::mlab_colon(0,1,size(w)-1);
	for (int w_index:value)
	{
		double sum_real = 0;
		double sum_imag = 0;
		double sum = 0;
		for (int k_index:k_array)
		{
			sum_real = sum_real + (b[k_index] * std::cos(w[w_index] * k_index));
			sum_imag = sum_imag + (b[k_index] * std::sin(w[w_index] * k_index));
		}
		sum = std::sqrt(std::pow(sum_real,2) + std::pow(sum_imag,2));
		h_return.push_back(sum);
	}
	return h_return;
}

bool key_generator::comp_arrays_with_error(std::vector<double> a,std::vector<double> b)
{
        bool to_return = true;
	if(size(a) != size(b))
	{
		//std::cout << "Array sizes do not match\n";
		//std::cout << "size 1 = "<< size(a) << "\n";
		//std::cout << "size 2 = " << size(b) << "\n";
		return false;
	}
	double max_error = 0;
        for (int index:key_generator::mlab_colon(0,1,size(a)-1)) //1:1:size(a)
        {
		if(std::abs(a[index] - b[index]) > max_error)
		{
			max_error = std::abs(a[index] - b[index]);
		}
		if(max_error > 0.001)
		{
			to_return = false;
		}
                
        }
	//std::cout << "The max error for this check is: " << max_error;
        return to_return;
}
size_t key_generator::get_freq_index(std::vector<double> a,double freq_to_check)
{
	size_t index = 0;
	for (double value:a)
	{
		if(freq_to_check < value)
		{
			index++;
		}
	}
	return index;
}
