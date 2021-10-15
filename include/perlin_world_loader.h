#ifndef PERLIN_WORLD_LOADER_H
#define PERLIN_WORLD_LOADER_H

#include "world_loader.h"
#include "const.h"

namespace Graphics {
    struct PerlinWorldLoader : public WorldLoader { 
        PerlinWorldLoader(int x_axis_max = 8 , int z_axis_max =  8);
		virtual std::vector<CubeData> run() const;

        int x_axis_max;
        int z_axis_max;
    };

};

#endif
