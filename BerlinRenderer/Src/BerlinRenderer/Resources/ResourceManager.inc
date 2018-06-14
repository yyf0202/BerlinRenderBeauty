

template<typename _Ty>
_Ty* ResourceManager::Load(string_t path)
{
	auto fd = resources_.find(path);
	if (fd != resources_.end()) return (_Ty*)fd->second;

	_Ty* res = new _Ty();
	res->Load(path);

	resources_[path] = res;

	return res;
}

template<typename _Ty>
_Ty* ResourceManager::LoadAsync(string_t path, function_t<void(_Ty*)> loaded)
{
	auto fd = resources_.find(path);
	loaded((_Ty*)fd->second);
	if (fd != resources_.end()) return (_Ty*)fd->second;

	auto res = new _Ty();
	res->BeginLoad(path, loaded);

	resources_[path] = res;

	return res;
}