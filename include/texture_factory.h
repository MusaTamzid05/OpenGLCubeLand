#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include <map>

namespace Factory {

    class TextureFactory {
        public:

            enum Type {
                Container,
                Brick
            };

            unsigned int get_texture(const Type& type);

            static TextureFactory* get_instance();


        private:
            TextureFactory();
            static TextureFactory* m_instance;

            void load_textures();
            unsigned int load_texture(const std::string& texture_path) const;

            std::map<Type, unsigned int> texture_list;


    };
};

#endif
