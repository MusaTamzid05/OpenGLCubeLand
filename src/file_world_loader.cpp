#include "file_world_loader.h"

namespace Graphics {

	FileWorldLoader::FileWorldLoader(const std::string& path) {
		read_from(path);

	}

	void FileWorldLoader::read_from(const std::string& path) {
		std::string line;
		std::ifstream input_file(path);

		if(!input_file.is_open()) {
			std::cerr << path << "could not open.\n";
			return;
		}

		while(std::getline(input_file, line))
			lines.push_back(line);

	}

	std::vector<CubeData> FileWorldLoader::run() const {
		int z_axis = 0;
		std::vector<CubeData> cube_data;

		for(unsigned int z_axis = 0;  z_axis < lines.size(); z_axis += 1) {
			std::string line = lines[z_axis];
            int x_axis = 0;
			for(unsigned int col = 0; col < line.size(); col += 2) {
                if(line[col] == ' ') {
                    x_axis += 1;
					continue;
                }

                int cube_count = line[col] - '0';
                for(unsigned int i = 0; i < cube_count; i += 1) 
                    cube_data.push_back(CubeData(x_axis, i,  z_axis, line[col+ 1]));

                x_axis += 1;

			}
		}

		return cube_data;
	}

}


