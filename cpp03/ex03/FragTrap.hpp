#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{
  private:
	/* data */
  public:
	FragTrap();
	FragTrap(/* args */);
	FragTrap(const FragTrap& cpy);
	FragTrap &operator=(const FragTrap& cpy);
	~FragTrap();
};

#endif