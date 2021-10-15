#include "world_loader.h"

namespace Graphics {

	std::ostream& operator<<(std::ostream& os, const CubeData& cube_data) {
        
		os << "Texture type : " << cube_data.texture_type << " x_axis : " << cube_data.x_axis <<  " y_axis : " << cube_data.y_axis <<  " z_axis : " <<  cube_data.z_axis;
		return os;
	}


}
