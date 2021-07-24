char* ReadFile(std::string& fileName, std::string& mode, size_t& outFileSize)
{
	FILE* file = NULL;
	char* buffer = NULL;
	fopen_s(&file, fileName.c_str(), mode.c_str());
	if (file)
	{
		fseek(file, 0, SEEK_END);
		size_t size = ftell(file);
		buffer = new char[size];
		rewind(file);
		fread(buffer, sizeof(char), size, file);
		outFileSize = size;
		fclose(file);
	}
	return buffer;
}
