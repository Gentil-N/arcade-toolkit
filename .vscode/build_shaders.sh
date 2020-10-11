mkdir -p build/test
cd build/test
echo Begin compilation
glslc ../../code/test/triangle.vert -o triangle_vert.spv
echo -----------------
glslc ../../code/test/triangle.frag -o triangle_frag.spv
echo End compilation