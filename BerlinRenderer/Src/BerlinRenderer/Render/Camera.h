//0.1.1
//初次创建 (2018.05.14)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#pragma once
#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Base/Context.h>

NS_RENDER_BEGIN

class IActionManager;

class RENDER_API Camera : Noncopyable, public std::enable_shared_from_this<Camera>
{
public:
	Camera();
	~Camera();
	void SetProjectionParams(float_t fov, float_t aspect, float_t nearZ, float_t farZ);
	void SetViewParams(vec3_t const& cameraPos, vec3_t const& lookatPos);
	void SetViewParams(vec3_t const& cameraPos, vec3_t const& lookatPos, vec3_t const& upVec);
	void SetCameraPos(vec3_t const& cameraPos);
	const vec3_t GetCameraPos() { return pos_; }
	void LookAt(vec3_t const& lookatPos);

	void AddToSceneManager();
	void DelFromSceneManager();

	inline mat4_t const& GetViewMatrix() { return view_matrix_;	}
	inline mat4_t const& GetProjectionMatrix() { return project_matrix_; }
	inline float_t Fov() { return fov_; }
	inline float_t Aspect() { return aspect_; }
	inline float_t NearZ() { return near_z_; }
	inline float_t FarZ() { return far_z_; }
	inline vec3_t const& cameraPos() { return pos_; }
	inline vec3_t const& Forward() { return forward_; }
	inline vec3_t const& Right() { return right_; }
	inline vec3_t const& Up() { return up_; }

	inline IActionManager& GetActionManager() { return *actionManager_; }

private:
	vec3_t pos_;
	vec3_t target_pos_;
	vec3_t forward_;
	vec3_t right_;
	vec3_t up_;
	vec3_t up_vec_;
	mat4_t view_matrix_;
	mat4_t project_matrix_;
	float_t aspect_;
	float_t fov_;
	float_t near_z_;
	float_t far_z_;

	IActionManager* actionManager_ = nullptr;

	void UpdateViewProjMatri();
};
typedef shared_ptr_t<Camera> CameraPtr;
NS_RENDER_END