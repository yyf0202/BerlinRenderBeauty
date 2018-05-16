//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////
#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H
#pragma once
#include "Mesh.h"
#include <SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace BRE {

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();
		vector<Mesh> LoadMesh(string path);

	private:
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
		int GetLoadedTexture(aiString path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		GLint TextureFromFile(const char* path);
		vector<Mesh> meshes;
		vector<Texture> textures_loaded;
		string directory;
	};
}
#endif