#pragma once

#include <BerlinRenderer/BerlinRenderer.h>

USE_RENDER;

namespace tester
{
	class ShapeRenderTester
	{
	private:
		class _TestApp : public App
		{
		public:
			_TestApp() : App(string_t("ShapeRenderTester")) {}
			virtual void Startup() override
			{
				auto obj = new SceneObject();
				obj->SetRender(new RectRender());
				auto& material = Material::GetDefaultMaterial();
				obj->GetRenderer()->SetMaterial(&material);

				Context::GetInstance().SceneManagerInstance().AddSceneObject(shared_ptr_t<SceneObject>(obj));
			}
		};

	public:
		static bool Run()
		{
			auto app = new _TestApp();
			app->Run();

			return true;
		}
	};
}