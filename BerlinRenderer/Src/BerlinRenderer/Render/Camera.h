//0.1.1
//初次创建 (2018.05.14)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer\Base\PreDeclare.h>

namespace BRE {
	class Camera
	{
	public:
		Camera();
		~Camera();
		void SetProjectionParams(float fov, float aspect, float nearZ, float farZ);
		void SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos);
		void SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos, glm::vec3 const& upVec);

		void SetCameraPos(glm::vec3 const& cameraPos);
		void LookAt(glm::vec3 const& lookatPos);

		float Fov();
		float Aspect();
		float NearZ();
		float FarZ();
		glm::vec3 const& cameraPos();
		glm::vec3 const& Forward();
		glm::vec3 const& Right();
		glm::vec3 const& Up();

	private:
		glm::vec3 pos_;
		glm::vec3 target_pos_;
		glm::vec3 forward_;
		glm::vec3 right_;
		glm::vec3 up_;
		glm::vec3 up_vec_;
		glm::mat4 view_matrix_;
		glm::mat4 project_matrix_;
		float aspect_;
		float fov_;
		float near_z_;
		float far_z_;
	};
}