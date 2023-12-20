#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form defaultform;
	Form form1("Form A", 60, 60);
	Form form2("Form B", 60, 60);
	// Form form3("Form C", -1, 60); // will fail
	// Form form4("Form D", 60, -1); // will fail
	// Form form5("Form E", 1000, 59); // will fail

	Bureaucrat burea1("Burea 1", 1);
	Bureaucrat burea2("Burea 2", 75);

	std::cout << std::endl << "Buraeucrats: " << std::endl;
	std::cout << burea1 << std::endl;
	std::cout << burea2 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl << "Forms" << std::endl;
	std::cout << defaultform << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << std::endl;

	burea1.signForm(form1);
	burea1.signForm(form1);

	burea2.signForm(form2); 

	std::cout << std::endl << "Forms" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << std::endl;
}