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

		this->UpdateViewProjMatri();
	}

	void Camera::SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos) {
		SetViewParams(cameraPos, lookatPos, glm::vec3(0, 1, 0));
	}

	void Camera::SetViewParams(glm::vec3 const& cameraPos, glm::vec3 const& lookatPos, glm::vec3 const& upVec) {
		this->pos_ = cameraPos;
		this->target_pos_ = lookatPos;
		this->forward_ = glm::normalize(lookatPos - cameraPos);
		this->right_ = glm::normalize(glm::cross(this->forward_, upVec));
		this->up_ = glm::normalize(glm::cross(this->right_, this->up_));

		this->UpdateViewProjMatri();
	}

	void Camera::UpdateViewProjMatri() {
		this->view_matrix_ = glm::lookAt(this->pos_, this->pos_ + this->forward_, this->up_);
		this->project_matrix_ = glm::perspective(glm::radians(this->fov_), this->aspect_, this->near_z_, this->far_z_);
	}

	void Camera::SetCameraPos(glm::vec3 const& cameraPos) {
		this->pos_ = cameraPos;
		this->target_pos_ = cameraPos + this->forward_;
		this->UpdateViewProjMatri();
	}

	void Camera::LookAt(glm::vec3 const& lookatPos) {
		this->target_pos_ = lookatPos;
		this->forward_ = glm::normalize(lookatPos - this->pos_);
		this->right_ = glm::normalize(glm::cross(this->forward_, glm::vec3(0, 1, 0)));
		this->up_ = glm::normalize(glm::cross(this->right_, this->up_));
		this->UpdateViewProjMatri();
	}

	glm::mat4 const&  Camera::GetViewMatrix() {
		return this->view_matrix_;
	}

	glm::mat4 const& Camera::GetProjectionMatrix() {
		return this->project_matrix_;
	}

	glm::vec3 const& Camera::cameraPos() {
		return this->pos_;
	}

	glm::vec3 const& Camera::Forward() {
		return this->forward_;
	}

	glm::vec3 const& Camera::Right() {
		return this->right_;
	}

	glm::vec3 const& Camera::Up() {
		this->up_;
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