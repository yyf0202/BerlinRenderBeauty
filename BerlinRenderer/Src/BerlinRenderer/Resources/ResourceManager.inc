

template<typename _Ty>
_Ty* ResourceManager::Load(string_t path)
{
	auto fd = resources_.find(path);
	if (fd != resources_.end()) return (_Ty*)fd->second;

	_Ty* res = _Ty::Loader::Load(path);
	if (res == nullptr) return res;

	resources_[path] = res;

	return res;
}

template<typename _Ty>
void ResourceManager::LoadAsync(string_t path, function_t<void(_Ty*)> loaded)
{
	auto loader = new typename _Ty::Loader(path, loaded);
	Context::GetInstance().TaskManagerInstance().AddTask(loader);
}