
#include "RectRender.h"
#include <BerlinRenderer/Resources/Material/Material.h>

NS_RENDER_BEGIN

void RectRender::Draw()
{
	GetMaterial()->Use();

	glColor3b(0, 0, 0);
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	glFlush();
}

NS_RENDER_END