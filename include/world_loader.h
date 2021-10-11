#ifndef WORLD_LOADER_H
#define WORLD_LOADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>


namespace Graphics {

	struct Position {
		Position(int x_axis, int z_axis):x_axis(x_axis),z_axis(z_axis) {}
		int x_axis;
		int z_axis;
	};

	std::ostream& operator<<(std::ostream& os, const Position& pos);

	struct WorldLoader {
		WorldLoader(const std::string& path);
		void read_from(const std::string& path);

		std::vector<Position> run() const;

		std::vector<std::string> lines;

	};



}

#endif
