path=`pwd`
echo $path
cd /workspaces/codeforce/library/Timer
g++ ./Clock.cpp -I Clock.h  -fPIC -shared -o libtime.so

cd /workspaces/codeforce/library/Algorithm
g++ ./DataStructure.cpp -I DataStructure.h  -fPIC -shared -o libalgorithm.so

