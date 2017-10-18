cd /var/jenkins_home/workspace/Plant/
mkdir build
cd build

export GTEST=/usr/src/googletest-release-1.8.0
export GTLIB=${GTEST}/build/gtest
export GMLIB=${GTEST}/build/googlemock

echo "################################################################################"
echo "## build lib"
echo "################################################################################"
g++ -std=c++11 -O2 -fno-exceptions -W -Wall -c ../MainLib/*.cpp \
    -DLINUX -fprofile-arcs -ftest-coverage
ar r libstatic.a *.o

echo "################################################################################"
echo "## build test"
echo "################################################################################"
g++ -std=c++11 -O2 -fno-exceptions -W -Wall ../UnitTest/*.cpp \
    -DLINUX -fprofile-arcs -ftest-coverage -I../MainLib libstatic.a \
    -I${GTEST}/googletest/include -I${GTEST}/googlemock/include \
    ${GMLIB}/gtest/libgtest.a ${GMLIB}/gtest/libgtest_main.a \
    ${GMLIB}/libgmock.a ${GMLIB}/libgmock_main.a \
    -lpthread -o test

echo "################################################################################"
echo "## test"
echo "################################################################################"
./test --gtest_output=xml:testresult.xml
gcovr -r ~/workspace/Plant/MainLib -e ../UnitTest/ --xml --output=Coverage.xml .

cd ..

echo "################################################################################"
echo "## cppcheck"
echo "################################################################################"
cppcheck --enable=all --inconclusive --xml --xml-version=2 MainLib 2> build/cppcheck.xml

echo "################################################################################"
echo "## doxygen"
echo "################################################################################"
doxygen

