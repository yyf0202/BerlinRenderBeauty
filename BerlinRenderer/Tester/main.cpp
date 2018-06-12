
#include <stdio.h>

#include "ShapeRenderTester.h"
#include "TextureRenderTester.h"
#include "ThreadPoolTester.h"

#pragma comment(lib, "BerlinRenderer.lib")
#pragma comment(lib, "OpenGL32.lib")

int main()
{
	tester::ShapeRenderTester::Run();
	//tester::TextureRenderTester::Run();
	//tester::ThreadPoolTester::Run();
	
	getchar();

	return 0;
}





