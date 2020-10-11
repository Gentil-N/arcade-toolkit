mkdir -p build/release
cd build/release
cmake ../.. -DCMAKE_BUILD_TYPE=Release -DATK_MOD_ORION=ON -DATK_MOD_ASSET=ON -DATK_MOD_DESKTOP=ON
make -j4