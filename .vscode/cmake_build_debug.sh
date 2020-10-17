mkdir -p build/debug
cd build/debug
cmake ../.. -DCMAKE_BUILD_TYPE=Debug -DATK_MOD_ORION=ON -DATK_MOD_ASSET=ON -DATK_MOD_DESKTOP=ON -DATK_MOD_MATH=ON
make -j4