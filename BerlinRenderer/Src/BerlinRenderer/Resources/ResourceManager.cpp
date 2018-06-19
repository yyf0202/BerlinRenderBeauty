//0.1.1
//初次创建 (2018.05.09)
//
// 修改记录
///////////////////////////////////////////////////////////////////

#include "ResourceManager.h"
#include <BerlinRenderer/IO/LoggerManager.h>
#include "Material.h"

NS_RENDER_BEGIN

ResourceManager::ResourceManager()
{

}


ResourceManager::~ResourceManager()
{
}

bool_t ResourceManager::Init()
{
	auto path = "./Resources/Shaders/default";

	defaultMaterial_ = new Material();
	defaultMaterial_->SetShaderPath(path);

	return true;
}

#pragma region Load Mesh
error_t ResourceManager::LoadMesh(string_t path, vector_t<Mesh>& meshed)
{
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		LOG_ERROR("ERROR::ASSIMP:: %s", importer.GetErrorString());
		return -1;
	}

	directory = path.substr(0, path.find_last_of('/'));
	ProcessNode(*scene->mRootNode, *scene);

	// TODO:
	return 0;
}

void ResourceManager::ProcessNode(aiNode& node, const aiScene& scene)
{
	for (uint32_t i = 0; i < node.mNumMeshes; i++)
	{
		aiMesh* mesh = scene.mMeshes[node.mMeshes[i]];
		if (mesh == nullptr)
		{
			// TODO: error?
			continue;
		}

		Mesh ms;
		// TODO: error
		ProcessMesh(*mesh, scene, ms);

		meshes.push_back(ms);
	}
	// After we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (uint32_t i = 0; i < node.mNumChildren; i++)
	{
		if (node.mChildren[i] == nullptr)
		{
			// TODO:
			continue;
		}
		ProcessNode(*node.mChildren[i], scene);
	}
}

error_t ResourceManager::ProcessMesh(aiMesh& mesh, const aiScene& scene, Mesh& ms)
{
	// Data to fill
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture2D> textures;

	// Walk through each of the mesh's vertices
	for (GLuint i = 0; i < mesh.mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector;

		vector.x = mesh.mVertices[i].x;
		vector.y = mesh.mVertices[i].y;
		vector.z = mesh.mVertices[i].z;
		vertex.Position = vector;

		vector.x = mesh.mNormals[i].x;
		vector.y = mesh.mNormals[i].y;
		vector.z = mesh.mNormals[i].z;
		vertex.Normal = vector;

		// Texture Coordinates
		if (mesh.mTextureCoords[0])
		{
			glm::vec2 vec;
			// A vertex can contain up to 8 different texture coordinates. We thus make the assumption that we won't 
			// use models where a vertex can have multiple texture coordinates so we always take the first set (0).
			vec.x = mesh.mTextureCoords[0][i].x;
			vec.y = mesh.mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		vertices.push_back(vertex);
	}
	// Now wak through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (GLuint i = 0; i < mesh.mNumFaces; i++)
	{
		aiFace face = mesh.mFaces[i];
		// Retrieve all indices of the face and store them in the indices vector
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// Process materials
	if (mesh.mMaterialIndex >= 0)
	{
		aiMaterial* material = scene.mMaterials[mesh.mMaterialIndex];
		if (material == nullptr)
		{
			//TODO: error
			return -1;
		}
		// We assume a convention for sampler names in the shaders. Each diffuse texture should be named
		// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER. 
		// Same applies to other texture as the following list summarizes:
		// Diffuse: texture_diffuseN
		// Specular: texture_specularN
		// Normal: texture_normalN

		// 1. Diffuse maps
		vector<Texture2D> diffuseMaps;
		LoadMaterialTextures(*material, aiTextureType_DIFFUSE, "texture_diffuse", diffuseMaps);
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

		// 2. Specular maps
		vector<Texture2D> specularMaps;
		LoadMaterialTextures(*material, aiTextureType_SPECULAR, "texture_specular", specularMaps);
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	}

	// Return a mesh object created from the extracted mesh data
	ms = Mesh(vertices, indices, textures);

	// TODO: error-success
	return 0;
}

#pragma endregion

#pragma region Load Texture
error_t ResourceManager::LoadMaterialTextures(aiMaterial& mat, aiTextureType type, string_t typeName, vector_t<Texture2D>& texs)
{
	vector<Texture2D> textures;
	for (uint32_t i = 0; i < mat.GetTextureCount(type); i++)
	{
		aiString str;
		mat.GetTexture(type, i, &str);
		int32_t index = GetLoadedTexture(str);
		if (index >= 0)
			textures.push_back(textures_loaded[index]);
		else
		{
			Texture2D texture;
			// TODO:
			//texture.id = TextureFromFile(str.C_Str());
			//texture.type = typeName;
			//texture.path = str.C_Str();
			textures.push_back(texture);
			textures_loaded.push_back(texture);
		}
	}

	// TODO:
	return 0;
}

int32_t ResourceManager::GetLoadedTexture(aiString str)
{
	for (uint32_t j = 0; j < textures_loaded.size(); j++)
	{

	}
	return -1;
}
GLint ResourceManager::TextureFromFile(string_t path)
{
	//Generate texture ID and load texture data 
	string_t filename = directory + '/' + path;
	GLuint textureID;
	glGenTextures(1, &textureID);
	int width, height;
	// TODO:
	//byte_t* image = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, textureID);
	// TODO:
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, textureID);
	// TODO:
	//SOIL_free_image_data(image);
	return textureID;
}
#pragma endregion

NS_RENDER_END