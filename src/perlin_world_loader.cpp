#include "perlin_world_loader.h"
#include "perlin.h"

namespace Graphics {
    PerlinWorldLoader::PerlinWorldLoader(int x_axis_max, int z_axis_max):
        x_axis_max(x_axis_max),
        z_axis_max(z_axis_max) {}

	std::vector<CubeData> PerlinWorldLoader::run() const {
		std::vector<CubeData> cube_data;


        for(unsigned int x = 0; x < x_axis_max; x+= 1)
            for(unsigned int z = 0; z < z_axis_max; z+= 1) {
                int cube_count = perlin2d(x, z, 0.1, 4) * 10;
                for(unsigned int  y_axis = 0; y_axis < cube_count ; y_axis += 1)
                    cube_data.push_back(CubeData(x, y_axis, z, Factory::TextureFactory::Type::Container));
            }

        return cube_data;
	}
}
