#ifndef TEXTURE_MAPPER_H
#define TEXTURE_MAPPER_H

#include <string>
#include <map>


namespace Graphics {

    struct TextureMapper {
        TextureMapper();
        std::string map(const char texture_type) const;

        std::map<char, std::string> mapper;

    };

}

#endif
