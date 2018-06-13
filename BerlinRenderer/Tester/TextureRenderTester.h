#pragma once

namespace tester
{
	class TextureRenderTester
	{
	private:
		class _TestApp : public App
		{
		public:
			_TestApp() : App(string_t("TextureRenderTester")) {}
			virtual void Startup() override
			{
				auto obj = new SceneObject();
				auto textRender = new TextureRender();
				obj->SetRender(textRender);
				auto material = new Material();
				material->SetShaderPath("./Resources/Shaders/diffuse");
				obj->GetRenderer()->SetMaterial(material);
				auto text = new Texture2D();
				text->SetSize(100, 100);
				text->SetFormat(GL_RGBA);
				text->Load("./Resources/Textures/test.png");
				textRender->SetTexture(text);


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