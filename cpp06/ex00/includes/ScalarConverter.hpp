/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:08:56 by saberton          #+#    #+#             */
/*   Updated: 2025/04/18 18:40:45 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/*Colors*/
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define GREEN "\e[1;92m"
# define BLUE "\e[1;94m"
# define YELLOW "\e[1;93m"
# define MAGENTA "\e[1;95m"
# define CYAN "\e[1;96m"
# define WHITE "\e[1;97m"
# define BLACK "\e[1;90m"
# define GRAY "\e[1;37m"

# include <iostream>
# include <sstream>

class ScalarConverter
{
//   private:
  public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	ScalarConverter& operator=(const ScalarConverter& cpy);
	~ScalarConverter();
//   public:
	static void convert(std::string input);
};

#endif