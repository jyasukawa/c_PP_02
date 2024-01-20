#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &fixed);
		Fixed	&operator=(const Fixed &fixed);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float toFloat( void ) const;
		int 	toInt( void ) const;

	private:
		int								_value;
		static const int	_fract_bits = 8;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed );

#endif
