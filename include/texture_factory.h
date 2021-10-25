#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include <map>
#include "factory_type.h"

namespace Factory {

    class TextureFactory {
        public:


            unsigned int get_texture(const TextureType& type);

            static TextureFactory* get_instance();


        private:
            TextureFactory();
            static TextureFactory* m_instance;

            void load_textures();
            unsigned int load_texture(const std::string& texture_path) const;

            std::map<TextureType, unsigned int> texture_list;


    };
};

#endif
