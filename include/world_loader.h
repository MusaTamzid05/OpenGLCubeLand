#ifndef WORLD_LOADER_H
#define WORLD_LOADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>


namespace Graphics {

	struct CubeData {
		CubeData(int x_axis, int y_axis,  int z_axis, char texture_type):
            x_axis(x_axis),
            y_axis(y_axis),
            z_axis(z_axis),
            texture_type(texture_type)
        {}


		int x_axis;
		int y_axis;
		int z_axis;
        char texture_type;
	};

	std::ostream& operator<<(std::ostream& os, const CubeData& cube_data);

	struct WorldLoader {
		virtual std::vector<CubeData> run() const = 0;
	};



}

#endif
