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
echo -----------------
glslc instance_rendering.vert -o instance_rendering_vert.spv
echo -----------------
glslc instance_rendering.frag -o instance_rendering_frag.spv
echo -----------------
glslc cube_textured.vert -o cube_textured_vert.spv
echo -----------------
glslc cube_textured.frag -o cube_textured_frag.spv
echo End compilation