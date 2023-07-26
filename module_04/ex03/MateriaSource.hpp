/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:23:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/07/26 09:15:21 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <cstring>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*storage[4];
		int			storageCount;	
	
	public:
		// Constructors
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		// Operators
		MateriaSource & operator = (MateriaSource const & src);

		// Member Functions
		void	learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif
