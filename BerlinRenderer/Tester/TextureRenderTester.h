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
			virtual bool_t Startup() override
			{
				auto obj = new SceneObject();
				auto textRender = new TextureRender();
				obj->SetRender(textRender);
				auto material = new Material();
				material->SetShaderPath("./Resources/Shaders/texture");
				obj->GetRenderer()->SetMaterial(material);
				auto text = new Texture2D();
				text->SetFormat(GL_RGB);
				text->Load("./Resources/Textures/test.png");
				textRender->SetTexture(text);


				Context::GetInstance().SceneManagerInstance().AddSceneObject(shared_ptr_t<SceneObject>(obj));

				return true;
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