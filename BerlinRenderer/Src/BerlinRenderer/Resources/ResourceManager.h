//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#pragma once

#include <BerlinRenderer/Base/Config.h>
#include <BerlinRenderer/Resources/Mesh.h>
#include <SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

NS_RENDER_BEGIN

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	error_t LoadMesh(string_t path, vector_t<Mesh>& meshes);

private:
	error_t ProcessMesh(aiMesh& mesh, const aiScene& scene, Mesh& ms);
	error_t LoadMaterialTextures(aiMaterial& mat, aiTextureType type, string_t typeName, vector_t<Texture2D>& texs);
	int32_t GetLoadedTexture(aiString path);
	void ProcessNode(aiNode& node, const aiScene& scene);
	GLint TextureFromFile(string_t path);
	vector_t<Mesh> meshes;
	vector_t<Texture2D> textures_loaded;
	string_t directory;
};

NS_RENDER_END