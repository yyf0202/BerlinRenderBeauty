//0.1.1
//初次创建 (2018.05.14)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Camera.h"

namespace BRE {
	Camera::Camera()
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::SetProjectionParams(float fov, float aspect, float nearZ, float farZ) {
		this->fov = fov;
		this->aspect = aspect;
		this->near_z_ = nearZ;
		this->far_z_ = farZ;


	}
	void Camera::SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos) {
		this->pos_ = cameraPos;
		this->target_pos_ = lookatPos;
		this->forward_ = glm::normalize(lookatPos - cameraPos);
	}
	void SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos, glm::vec3 const& upVec);

	void SetCameraPos(glm::vec3 const& cameraPos);
	void LookAt(glm::vec3 const& lookatPos);

	float Fov();
	float Aspect();
	float NearZ();
	float FarZ();
}