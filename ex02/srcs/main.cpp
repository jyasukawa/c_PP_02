#include "Fixed.hpp"

int	main(void)
{
	Fixed				a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;// 1 / 256 = 0.00390625
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;// 2 / 256 = 0.0078125

	std::cout << b << std::endl;// 5.05 * 256 = 1292.8 = 1293 1293 / 256 * 2 = 10.1015625 = 10.1016
	
	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
