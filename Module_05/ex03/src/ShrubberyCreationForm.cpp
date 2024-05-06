/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhovhann <vhovhann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:04:38 by vhovhann          #+#    #+#             */
/*   Updated: 2024/04/07 17:04:53 by vhovhann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("nil", ShrubberyCreationForm::MaxGradeExec, ShrubberyCreationForm::MaxGradeSidned),target("nil")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm(target, ShrubberyCreationForm::MaxGradeExec,ShrubberyCreationForm::MaxGradeSidned),target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other):AForm(other.target, MaxGradeExec, MaxGradeSidned),target(other.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm & other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    this->checkExec(executor);
    this->checkSign();

    std::ofstream drawFile;
    
    drawFile.open((this->getName() + "_shrubbery").c_str(),  std::ios::trunc);

     if (!drawFile)
        throw std::runtime_error("Cannot open file\n");

    drawFile << "                  v .   ._, |_  .," << std::endl;
    drawFile << "           `-._\\/  .  \\ /    |/_" << std::endl;
    drawFile << "               \\  _\\, y | \\//" << std::endl;
    drawFile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
    drawFile << "           `7-,--.`._||  / / ," << std::endl;
    drawFile << "           /'     `-. `./ / |/_.'" << std::endl;
    drawFile << "                     |    |//" << std::endl;
    drawFile << "                     |_    /" << std::endl;
    drawFile << "                     |-   |" << std::endl;
    drawFile << "                     |   =|" << std::endl;
    drawFile << "                     |    |" << std::endl;
    drawFile << "--------------------/ ,  . \\--------._" << std::endl;

    drawFile.close();
}