#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b( 10 );
	Fixed	const c( 42.42f );//42.42 * 256 = 10859.52  四捨五入すると 10860 小数点以下4桁まで表示される場合、10860 / 256 ≈ 42.421875
	Fixed	const d( b );

	a = Fixed( 1234.4321f );//1234.4321 * 256 ≈ 316014.618  四捨五入すると 316015  小数点以下2桁まで表示される場合、316015 / 256 ≈ 1234.43359

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return (0);
}
