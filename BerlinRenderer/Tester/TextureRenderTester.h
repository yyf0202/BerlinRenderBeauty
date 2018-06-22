#pragma once

USE_RENDER;

namespace tester
{
	class TextureRenderTester
	{
	private:
		class MoveObjAction : public Action
		{
		public:
			MoveObjAction(SceneObject& obj, vec3_t& to, float_t time)
				: obj_(obj)
				, to_(to)
				, duration_(0)
				, time_(time)
			{
			}
			virtual void OnStart() override
			{
				start_ = obj_.GetPostion();
			}
			virtual void OnUpdate() override
			{
				//glm::lerp(start_, to_, duration_/time_);
				duration_ += (float)Context::GetInstance().GetDeltaTime()/1000;
				if (duration_ >= time_) return;
				auto delta = duration_ / time_;
				vec3_t vec(start_.x + (to_.x - start_.x)*delta, start_.y + (to_.y - start_.y)*delta, start_.z + (to_.z - start_.z)*delta);
				obj_.SetPosition(vec);
			}

		private:
			vec3_t to_;
			vec3_t start_;
			SceneObject& obj_;
			float_t duration_;
			float_t time_;
		};
		class MoveCameraAction : public Action
		{
		public:
			MoveCameraAction(Camera& camera, vec3_t& to, float_t time)
				: camera_(camera)
				, to_(to)
				, duration_(0)
				, time_(time)
			{
			}
			virtual void OnStart() override
			{
				start_ = camera_.GetCameraPos();
			}
			virtual void OnUpdate() override
			{
				//glm::lerp(start_, to_, duration_/time_);
				duration_ += (float)Context::GetInstance().GetDeltaTime() / 1000;
				auto delta = duration_ / time_;
				vec3_t vec(start_.x + (to_.x - start_.x)*delta, start_.y + (to_.y - start_.y)*delta, start_.z + (to_.z - start_.z)*delta);
				camera_.SetCameraPos(vec);
			}

		private:
			vec3_t to_;
			vec3_t start_;
			Camera& camera_;
			float_t duration_;
			float_t time_;
		};
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

				auto camera = new Camera();
				camera->SetViewParams(vec3_t(0, 0, -10), vec3_t(0, 0, 1));
				camera->SetProjectionParams(45.0f, 1, 1, 100);

				//vec3_t to(5, 0, -10);
				//auto action = new MoveCameraAction(*camera, to, 10);
				//camera->GetActionManager().Add(action);

				vec3_t to(0.1, 0, 0);
				auto action = new MoveObjAction(*obj, to, 30);
				obj->GetActionManager().Add(action);

				SceneMgr().AddCamera(camera);
				SceneMgr().AddSceneObject(shared_ptr_t<SceneObject>(obj));

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