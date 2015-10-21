
add_library(stardust
	"Dust.cpp"
)
set_property(TARGET stardust PROPERTY CXX_STANDARD 14)
target_include_directories(stardust
	PUBLIC "./"
)

# Stardust compiler
add_executable(nova
	"nova.cpp"
)
set_property(TARGET nova PROPERTY CXX_STANDARD 14)
target_include_directories(nova
	PUBLIC "./"
)
target_link_libraries(nova
	stardust
	json-parser
)
