bool CreateWriteFile(std::string& fileName, std::string& mode, void* buffer, size_t fileSize)
{
	FILE* file = NULL;
	fopen_s(&file, fileName.c_str(), mode.c_str());
	if (file)
	{
		fwrite(buffer, sizeof(char), fileSize, file);
		fclose(file);
		return true;
	}
	return false;
}
