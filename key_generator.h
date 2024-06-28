#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
class key_generator
{
public:
static std::vector<double> mlab_colon(double start,double step,double end);
static std::vector<double> dynamic_w(double start,std::vector<double> user_array,double end);
static std::vector<double> freq_resp_me(std::vector<double> coefficients,std::vector<double> w);
static bool comp_arrays_with_error(std::vector<double> a,std::vector<double> b);
static size_t get_freq_index(std::vector<double> a,double freq_to_check);



};
