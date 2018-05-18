
#include <stdio.h>

#include <BerlinRenderer/Render/RenderEngine.h>

#pragma comment(lib, "BerlinRenderer.lib")

int main()
{
	auto t = new NS_RENDER RenderEngine();
	t->Test();

	getchar();

	return 0;
}