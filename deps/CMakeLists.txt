
# json-parser
add_library(json-parser
	"json-parser/json.c"
)
target_include_directories(json-parser
	PUBLIC "json-parser/"
)
target_compile_definitions(json-parser
	PUBLIC JSON_TRACK_SOURCE
)
