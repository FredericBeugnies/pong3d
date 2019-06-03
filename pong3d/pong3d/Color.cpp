
#include "Color.h"


Color::Color( unsigned char red, unsigned char green, unsigned char blue ):
	m_red( red ), m_green( green ), m_blue( blue )
{
}

Color::~Color()
{
}

unsigned char Color::red() const
{
	return m_red;
}

unsigned char Color::green() const
{
	return m_green;
}

unsigned char Color::blue() const
{
	return m_blue;
}
