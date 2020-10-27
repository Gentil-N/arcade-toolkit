cd code/test/shaders
echo Begin compilation
echo -----------------
glslc triangle.vert -o triangle_vert.spv
echo -----------------
glslc triangle.frag -o triangle_frag.spv
echo -----------------
glslc cube.vert -o cube_vert.spv
echo -----------------
glslc cube.frag -o cube_frag.spv
echo End compilation