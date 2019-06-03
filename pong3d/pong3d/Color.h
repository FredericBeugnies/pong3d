
#ifndef PONG3D_Color_H
#define PONG3D_Color_H

class Color
{
public:
	Color( unsigned char red, unsigned char green, unsigned char blue );
	~Color();

	unsigned char red() const;
	unsigned char green() const;
	unsigned char blue() const;

private:
	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
};

#endif
