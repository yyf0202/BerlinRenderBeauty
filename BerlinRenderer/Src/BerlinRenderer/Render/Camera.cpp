//0.1.1
//初次创建 (2018.05.14)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "Camera.h"
#include <BerlinRenderer/Scene Manager/SceneManager.h>
#include <BerlinRenderer/Action/SeqActionManager.h>

NS_RENDER_BEGIN

Camera::Camera()
{
	actionManager_ = new SeqActionManager();
}

Camera::~Camera()
{
}

void Camera::SetProjectionParams(float_t fov, float_t aspect, float_t nearZ, float_t farZ)
{
	this->fov_ = fov;
	this->aspect_ = aspect;
	this->near_z_ = nearZ;
	this->far_z_ = farZ;

	this->UpdateViewProjMatri();
}

void Camera::SetViewParams(vec3_t const& cameraPos, vec3_t const& lookatPos)
{
	SetViewParams(cameraPos, lookatPos, vec3_t(0, 1, 0));
}

void Camera::SetViewParams(vec3_t const& cameraPos, vec3_t const& lookatPos, vec3_t const& upVec)
{
	this->pos_ = cameraPos;
	this->target_pos_ = lookatPos;
	this->forward_ = glm::normalize(lookatPos - cameraPos);
	this->right_ = glm::normalize(glm::cross(this->forward_, upVec));
	this->up_ = glm::normalize(glm::cross(this->right_, this->forward_));

	this->UpdateViewProjMatri();
}

void Camera::UpdateViewProjMatri()
{
	this->view_matrix_ = glm::lookAt(this->pos_, this->pos_ + this->forward_, this->up_);
	this->project_matrix_ = glm::perspective(glm::radians(this->fov_), this->aspect_, this->near_z_, this->far_z_);
}

void Camera::SetCameraPos(vec3_t const& cameraPos)
{
	this->pos_ = cameraPos;
	this->target_pos_ = cameraPos + this->forward_;
	this->UpdateViewProjMatri();
}

void Camera::LookAt(vec3_t const& lookatPos)
{
	this->UpdateViewProjMatri();
}

void Camera::AddToSceneManager()
{
	SceneMgr().AddCamera(this);
}

void Camera::DelFromSceneManager()
{
	SceneMgr().DelCamera(this);
}

NS_RENDER_END