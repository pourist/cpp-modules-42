#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define MIN_GRADE	150
# define MAX_GRADE	1

class   Bureaucrat
{
	private:
		const std::string	Name;
		int	grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(std::string _Name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat	&operator=(const Bureaucrat& src);

		std::string	getName() const;
		int	        getGrade() const;

        void	increment(int inc_num = 1);
		void	decrement(int dec_num = 1);

		class	GradeTooHighException: public std::exception
		{
				const char	*what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
				const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B);

#endif