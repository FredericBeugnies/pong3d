
#include "glHelpers.h"

#include <GL/glut.h>


void glColor( const Color& color )
{
	glColor3ub( color.red(), color.green(), color.blue() );
}
