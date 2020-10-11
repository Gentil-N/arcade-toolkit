mkdir -p build/test
cd build/test
cmake ../.. -DATK_TEST=ON -DATK_TRIANGLE_DEMO=ON
make -j4
echo
echo -------------------------------------------
echo
./atk