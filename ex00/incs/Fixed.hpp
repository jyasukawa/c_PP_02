#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &fixed);
		Fixed	&operator=(const Fixed &fixed);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int								_value;
		static const int	_fract_bits = 8;
};

#endif

//static const int _fract_bits;：これは _fract_bits という名前の静的定数メンバー変数で、小数部のビット数を表します。このメンバー変数は static 修飾子を持ち、全ての Fixed インスタンスで共有される定数となります。指定された要件により、この値は常に整数リテラル 8 であるため、const int として宣言されています。