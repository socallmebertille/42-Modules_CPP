/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainWithComments.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:01:25 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 17:33:08 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	std::cout << "\033[38;5;220m" << "Notion de fixed-point : " << "\033[0m" << std::endl << std::endl;

	std::cout << "En binaire on ecrit un nombre a virgule sur 32 bits tel que :" << std::endl;
	std::cout << "\033[35m" << "s" << "\033[32m" << " " << "eeeeeeeeeeeeeeeeeeeeeee" << "\033[31m" << " " << "mmmmmmmm" << "\033[0m" << std::endl;
	std::cout << "s = signe du nb ; e = exposant = partie entiere ; m = mantissa = partie fractionnaire" << std::endl << std::endl;
	
	std::cout << "Dans ce cas precis on a un fixed-point tel que fixed<32, 8>" << std::endl;
	std::cout << "c'est-a-dire que sur 32 bits on accorde les 8 derniers bits a ce qui est derrire la virgule (= la partie fractionnaire)" << std::endl << std::endl;
	
	std::cout << "Ex : on veut travailler avec pi = 3.14159" << std::endl << std::endl;
	
	std::cout << "Ici on veut une precision tel que nos chiffres apres la vigule seront composes de 8 bits" << std::endl;
	std::cout << "Donc on va d'abord multiplie notre pi par 2^8 = 256 et l'arrondir avec roundf" << std::endl;
	std::cout << "Pourquoi on fait cela ?" << std::endl;
	std::cout << "Car pi * 2^8 = 804,24704 donc roundf(pi * 2^8) = 805 soit un entier (=int) convertissable en binaire" << std::endl << std::endl;
	std::cout << "\033[38;5;220m" << "Initialisation de pi : " << "\033[0m" << std::endl << std::endl;

	Fixed const pi(3.14156f);
	std::cout << std::endl;
	
	std::cout << "\033[38;5;220m" << "Conversion en int : " << "\033[0m" << std::endl << std::endl;
	std::cout << "A partir de 805, on va pouvoir recuperer sa valeur entiere avec toInt()" << std::endl;
	std::cout << "Etant donne que nos 8 bits de la fin sont consacres a la partie fractionnaire" << std::endl;
	std::cout << "on va donc passe redecaler notre mantisse de 8 bits vers la gauche en faisant : " << std::endl;
	std::cout << "	_rawBits >> 8" << std::endl << std::endl;

	std::cout << pi.toInt() << std::endl;
	
	std::cout << std::endl << "\033[38;5;220m" << "Conversion en float : " << "\033[0m" << std::endl << std::endl;
	std::cout << "A partir de 805, on peut egalement recuperer la partie fractionnaire avec toFloat()" << std::endl;
	std::cout << "Etant donne que nos 8 bits de la fin sont consacres a la partie fractionnaire" << std::endl;
	std::cout << "on va renvoye le resultat de la divison entre 805 et 256 pour recuperer la partie fracionnaire" << std::endl;
	std::cout << "(car a la base on les avait multiplie) " << std::endl;
	std::cout << "qui plus est dans un float (pour supporter les chiffres apres la virgules)" << std::endl;
	std::cout << "	static_cast<float>(_rawBits) / (1 << 8)" << std::endl<< std::endl;

	std::cout << pi.toFloat() << std::endl << std::endl;
	return (0);
}
