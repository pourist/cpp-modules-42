#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): 
    AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target): 
    AForm("ShrubberyCreationForm", 145, 137), target(_target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
    AForm("ShrubberyCreationForm", 145, 137), target(src.getTarget())
{
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    (void)src;
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return(this->target);
}

void ShrubberyCreationForm::executeConcrete() const
{
    std::fstream    fs;
    fs.open((this->target + "_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
    // :trunc clears the file
    if (!fs.is_open())
        throw std::runtime_error("Error: Could not create shrubbery file.");
    std::cout << "Shrubbery executed successfully\n";
    fs << 
    "         /\\\n"
    "        /**\\\n"
    "       /****\\\n"
    "      /******\\\n"
    "     /********\\\n"
    "    /**********\\\n"
    "   /************\\\n"
    "  /**************\\\n"
    " /****************\\\n"
    "/******************\\\n"
    "        |||\n"
    "        |||\n"
    "        |||\n"
	"/\\/>.######.\\/\\/\\/\\/\\\n";
    fs.close();
}