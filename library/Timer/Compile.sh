path=`pwd`
echo $path
cd /workspaces/codeforce/library/Timer
g++ ./Clock.cpp -I Clock.h  -fPIC -shared -o libtime.so