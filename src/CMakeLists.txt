
add_library(stardust
	"Dust.cpp"
)
set_property(TARGET stardust PROPERTY CXX_STANDARD 14)
target_include_directories(stardust
	PUBLIC "./"
)

# Stardust compiler
add_executable(stardust-c
	"stardust-c.cpp"
)
set_property(TARGET stardust-c PROPERTY CXX_STANDARD 14)
target_include_directories(stardust-c
	PUBLIC "./"
)
target_link_libraries(stardust-c
	stardust
	json-parser
)
