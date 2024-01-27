#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)// : _value(i << _fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_fract_bits;
}//まず２進数にしてからシフトする。10 << 8 = 2560

Fixed::Fixed(const float f)// : _value((int)roundf(f * (1 << _fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << this->_fract_bits));
}//roundfは、浮動小数点数を最も近い整数に四捨五入するC標準ライブラリの関数です。キャスト不要
// 1 << 8 は 256 です。これは、固定小数点数において小数部の表現に使用される係数です
// 浮動小数点数 3.14 が固定小数点数 803.84 に変換されます。この変換により、小数部が整数に変換されて、固定小数点数が得られます。このような変換を通じて、浮動小数点数から整数部と小数部を分離し、整数として表現することが可能となります。

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBIts member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBIts member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_value) / (1 << this->_fract_bits));
}
//それぞれ逆のことをする
int	Fixed::toInt( void ) const
{
	return (this->_value >> this->_fract_bits);
	// return ((int)(roundf((float)this->_value / (1 << this->_fract_bits))));
	// return ((int)this->toFloat());
	// return (static_cast<float>());
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed )
{
	os << fixed.toFloat();
	return (os);
}
