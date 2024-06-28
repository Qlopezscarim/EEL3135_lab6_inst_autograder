#include "jparse.h"
#include "questions/questions.h"
#include <cstdlib>

int main(int argc, char* argv[])
{
	//Which question is the autograder grading: determined by command line argument
	int index = std::stoi(argv[1]);


	std::vector<bool> github_automation;

	jparse autograder = jparse("variables.json");
	questions gen_questions = questions();
	
	//Part a
	std::vector<double> first_question = gen_questions.question1(10); //checking for l = 10
	bool first_grade = autograder.freq_response(first_question);
	github_automation.push_back(first_grade);

	//part b
	std::vector<double> second_question = gen_questions.question2(10); //checking for l = 10
        bool second_grade = autograder.freq_response(second_question);
	github_automation.push_back(second_grade);


	second_question = gen_questions.question2(100); //checking for l = 100
        second_grade = autograder.freq_response(second_question);
	github_automation.push_back(second_grade);



	//part c
        std::vector<double> third_question = gen_questions.question3(10); //checking for l = 10
        bool third_grade = autograder.freq_response(third_question);
	github_automation.push_back(third_grade);


	third_question = gen_questions.question3(100); //checking for l = 100
        third_grade = autograder.freq_response(third_question);
	github_automation.push_back(third_grade);


	//part d
        std::vector<double> fourth_question = gen_questions.question4(10); //checking for l = 10
        bool fourth_grade = autograder.freq_response(fourth_question);
	github_automation.push_back(fourth_grade);


	fourth_question = gen_questions.question4(100); //checking for l = 100
        fourth_grade = autograder.freq_response(fourth_question);
	github_automation.push_back(fourth_grade);


	//part e
        std::vector<double> five_question = gen_questions.question5(10);
        bool five_grade = autograder.freq_response(five_question);
	github_automation.push_back(five_grade);


	five_question = gen_questions.question5(100);
        five_grade = autograder.freq_response(five_question);
	github_automation.push_back(five_grade);

	//filtered audio
	double filtered_frequency = gen_questions.question6();
	bool six_grade = autograder.check_freq(filtered_frequency,0.5);
	github_automation.push_back(six_grade);

	std::cout << github_automation[index];

	return 0;
}
