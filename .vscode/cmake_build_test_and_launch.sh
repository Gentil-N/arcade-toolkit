mkdir -p build/test
cd build/test
cmake ../.. -DATK_TEST=ON -DATK_TRIANGLE_DEMO=OFF -DATK_CUBE_DEMO=OFF -DATK_INSTANCE_RENDERING_DEMO=OFF -DATK_CUBE_TEXTURED_DEMO=ON
make -j4
echo
echo -------------------------------------------
echo
./atk