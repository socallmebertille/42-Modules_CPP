/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainWithComments.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saberton <saberton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:56:02 by saberton          #+#    #+#             */
/*   Updated: 2025/03/28 18:30:52 by saberton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
    std::cout << "\033[38;5;220m" << "Implementation d'operateurs : " << "\033[0m" << std::endl << std::endl;

    std::cout << "On rappel qu'en binaire on ecrit un nombre a virgule sur 32 bits tel que :" << std::endl;
	std::cout << "\033[35m" << "s" << "\033[32m" << " " << "eeeeeeeeeeeeeeeeeeeeeee" << "\033[31m" << " " << "mmmmmmmm" << "\033[0m" << std::endl;
	std::cout << "s = signe du nb ; e = exposant = partie entiere ; m = mantissa = partie fractionnaire" << std::endl;
    std::cout << "Soit un fixed-point tel que fixed<32, 8>" << std::endl << std::endl;

    std::cout << "\033[38;5;220m" << "Les operateurs de calculs : " << "\033[0m" << std::endl << std::endl;

    std::cout << "Ex : 5,05 + 2 & 5,05 - 2" << std::endl << std::endl;
    std::cout << "On additione simplement les valeurs de bits ensemble" << std::endl;
    std::cout << "puis l'operateur << renvoie la version du nbgrace a toFloat()" << std::endl;
    std::cout << "L'operateur de soustraction utilise la meme methode" << std::endl;
    Fixed const add( Fixed( 5.05f ) + Fixed( 2 ) );
    std::cout << std::endl << "++++++++++++ addition : " << add << std::endl;
    std::cout << "------------ soustraction : " << Fixed(5.05f - 2) << std::endl << std::endl;
	
    std::cout << "Ex : 5,05 * 2 & 5,05 / 2" << std::endl << std::endl;
    std::cout << "On multiplie simplement les valeurs de bits ensemble comme avec + ou -" << std::endl;
    std::cout << "Or ici, on va " << std::endl;
    std::cout << "puis l'operateur << renvoie la version du nbgrace a toFloat()" << std::endl;
    std::cout << "L'operateur de soustraction utilise la meme methode" << std::endl << std::endl;
    Fixed const mult( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "*********** multiplication : " << mult << std::endl << std::endl;
    Fixed const sous( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << "///////////// division : " << Fixed(5.05f / 2) << std::endl << std::endl;

    std::cout << "\033[38;5;220m" << "Les 4 opérateurs d'incrémentation/décrémentation : " << "\033[0m" << std::endl;
    std::cout << "(pré-incrémentation et post-incrémentation, pré-décrémentation et post-décrément)" << std::endl << std::endl;
    
    std::cout << "Quand on fait int a(0) puis qu'on affiche ++a on verra 0 mais a aura bien pris +1" << std::endl;
    std::cout << "alors que si on fait a++ on verra 1 directement a l'affichage" << std::endl;
    std::cout << "Pour les operateurs c'est pareil : " << std::endl;
    std::cout << "Fixed &Fixed::operator++ => renvoie une valeur temporaire avant l'incrementation (pre)" << std::endl;
    std::cout << "Fixed Fixed::operator++(int) => renvoie le pointeur incrementer (post)" << std::endl;
    std::cout << "Le comportement est le meme avec l'ope --" << std::endl << std::endl;
    Fixed pre_post(5.05f);
    std::cout << "init : " << pre_post << std::endl;
    std::cout << std::endl << ++pre_post << std::endl;
    pre_post--;
    std::cout << std::endl << pre_post++ << std::endl << std::endl;
    
    std::cout << "\033[38;5;220m" << "Les operateurs de comparaisons : " << "\033[0m" << std::endl << std::endl;

	std::cout << Fixed::min( pre_post, 2 ) << std::endl << std::endl;
	std::cout << Fixed::max( pre_post, 2 ) << std::endl;

    std::cout << "" << std::endl;
	return (0);
}
