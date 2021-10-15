#ifndef FILE_WORLD_LOADER_H
#define FILE_WORLD_LOADER_H

#include "world_loader.h"

namespace Graphics {

	struct FileWorldLoader : public WorldLoader {
		FileWorldLoader(const std::string& path);
		void read_from(const std::string& path);

		std::vector<CubeData> run() const;
		std::vector<std::string> lines;

	};


}
#endif
