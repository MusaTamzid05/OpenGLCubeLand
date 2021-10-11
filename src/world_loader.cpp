#include "world_loader.h"

namespace Graphics {

	std::ostream& operator<<(std::ostream& os, const Position& pos) {
		os << "x_axis : " << pos.x_axis << " z_axis : " <<  pos.z_axis;
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

	std::vector<Position> WorldLoader::run() const {
		int z_axis = 0;
		std::vector<Position> positions;

		for(unsigned int z_axis = 0;  z_axis < lines.size(); z_axis += 1) {
			std::string line = lines[z_axis];
			for(unsigned int x_axis  = 0; x_axis < line.size(); x_axis  += 1) {
				if(line[x_axis] == ' ')
					continue;
				positions.push_back(Position(x_axis, z_axis));

			}
		}

		return positions;
	}

}
