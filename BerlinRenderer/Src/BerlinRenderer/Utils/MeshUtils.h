#pragma once
#include <BerlinRenderer/Base/Config.h>
#include <SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <BerlinRenderer\Scene Manager\SceneObject.h>

NS_RENDER_BEGIN

class MeshUtils
{
public:
	MeshUtils();
	~MeshUtils();
	SceneObjectPtr LoadAndAddtoScene(string_t path);
	void ProcessNode(aiNode& node, const aiScene& scene,SceneObject* parent);
	
private:
	string_t directory;
};

NS_RENDER_END