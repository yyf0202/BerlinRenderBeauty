//0.1.1
//初次创建 (2018.05.14)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include <BerlinRenderer\Render\Camera.h>

namespace BRE {
	Camera::Camera()
	{

	}

	Camera::~Camera()
	{

	}

	void Camera::SetProjectionParams(float fov, float aspect, float nearZ, float farZ) {
		this->fov_ = fov;
		this->aspect_ = aspect;
		this->near_z_ = nearZ;
		this->far_z_ = farZ;


	}

	void Camera::SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos) {
		SetViewParams(cameraPos, lookatPos, glm::vec3(0, 1, 0));
	}

	void Camera::SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos, glm::vec3 const& upVec) {
		this->pos_ = cameraPos;
		this->target_pos_ = lookatPos;
		this->forward_ = glm::normalize(lookatPos - cameraPos);

		this->right_ = glm::cross(this->forwar_, upVec);
	}

	void Camera::SetCameraPos(glm::vec3 const& cameraPos) {

	}

	void Camera::LookAt(glm::vec3 const& lookatPos) {

	}

	float Camera::Fov() {
		return this->fov_;
	}

	float Camera::Aspect() {
		return this->aspect_;
	}

	float Camera::NearZ() {
		return this->near_z_;
	}

	float Camera::FarZ() {
		return this->far_z_;
	}
}