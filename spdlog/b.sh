cd build
pwd
rm -rf *
cmake -DCMAKE_VERBOSE_MAKEFILE=ON ..
make
./spdlog-test