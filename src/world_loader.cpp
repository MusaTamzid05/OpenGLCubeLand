#include "world_loader.h"

namespace Graphics {

	std::ostream& operator<<(std::ostream& os, const CubeData& cube_data) {
        
		os << "Texture type : " << cube_data.texture_type << " x_axis : " << cube_data.x_axis <<  " y_axis : " << cube_data.y_axis <<  " z_axis : " <<  cube_data.z_axis;
		return os;
	}

	WorldLoader::WorldLoader(const std::string& path) {
		read_from(path);

	}

	void WorldLoader::read_from(const std::string& path) {
		std::string line;
		std::ifstream input_file(path);

		if(!input_file.is_open()) {
			std::cerr << path << "could not open.\n";
			return;
		}

		while(std::getline(input_file, line))
			lines.push_back(line);

	}

	std::vector<CubeData> WorldLoader::run() const {
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
