add_library(cmixer STATIC src/cmixer.c src/cmixer.h)
target_include_directories(cmixer PUBLIC ./src)
target_compile_definitions(cmixer PRIVATE CM_USE_STB_VORBIS)
target_link_libraries(cmixer PRIVATE stb stb_vorbis)
target_compile_features(cmixer PRIVATE cxx_std_14)
