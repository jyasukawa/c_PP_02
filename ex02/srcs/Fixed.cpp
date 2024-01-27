#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)// : _value(i << _fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = i << this->_fract_bits;
}

Fixed::Fixed(const float f)// : _value((int)roundf(f * (1 << _fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << this->_fract_bits));
}

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

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_value > fixed._value);
	// return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_value < fixed._value);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_value >= fixed._value);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_value <= fixed._value);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_value == fixed._value);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_value != fixed._value);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
	// Fixed res;
	// res._value = this->_value + fixed._value;
	// return res;
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

// Fixed   Fixed::operator*(const Fixed &other) const
// {
//     Fixed res;

//     res._value = (this->_value * other._value) / (1 << this->_fract_bits);
//     return res;
// }

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	++(this->_value);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	// Fixed res = *this;
	// _value++;
	// return (res);

	// Fixed prev(*this);
	// ++*this;
	// return prev;

	Fixed tmp = *this;
	(*this)._value++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	--(this->_value);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	// Fixed res = *this;
	// _value--;
	// return (res);

	// Fixed prev(*this);
	// --*this;
	// return prev;

	Fixed tmp = *this;
	(*this)._value--;
	return tmp;
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

int	Fixed::toInt( void ) const
{
	return (this->_value >> this->_fract_bits);
	// return ((int)(roundf((float)this->_value / (1 << this->_fract_bits))));
	// return ((int)this->toFloat());
	// return (static_cast<float>());
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	// return a <= b ? a : b;
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	// return a >= b ? a : b;
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed )
{
	os << fixed.toFloat();
	return (os);
}
