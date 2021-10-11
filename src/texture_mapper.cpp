#include "texture_mapper.h"

namespace Graphics {
    TextureMapper::TextureMapper() {
        mapper.insert(std::pair<char, std::string>('A', "../textures/container.jpg"));
        mapper.insert(std::pair<char, std::string>('B', "../textures/bricks2.jpg"));
    }

    std::string TextureMapper::map(const char texture_type) const  {
        //@TODO: Need to add error checking.
        
        for(auto& texture_data : mapper)
            if(texture_data.first == texture_type)
                return texture_data.second;
    }
}
