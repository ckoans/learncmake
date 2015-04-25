add_library(MathFunctions custom.cpp)
install(TARGETS MathFunctions DESTINATION bin)
install(FILES custom.h DESTINATION include)
