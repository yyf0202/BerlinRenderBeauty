#include "MeshUtils.h"
#include <stdio.h>
#include <BerlinRenderer\IO\LoggerManager.h>

NS_RENDER_BEGIN

MeshUtils::MeshUtils()
{

}


MeshUtils::~MeshUtils()
{

}

SceneObjectPtr MeshUtils::LoadAndAddtoScene(string_t path)
{
	do {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

		if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
		{
			LOG_ERROR("ERROR::ASSIMP::{} ", importer.GetErrorString());
			break;
		}

		directory = path.substr(0, path.find_last_of('/'));

	} while (false);

	return NULL;

}
NS_RENDER_END