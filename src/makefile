main: main.cpp libtime.so
	g++ -o main.exe main.cpp -L. libtime.so libalgorithm.so
	sudo rm -f /usr/lib/libtime.so /usr/lib/libalgorithm.so # Find 。so while Running 
	sudo ln -sv /workspaces/codeforce/src/libtime.so  /usr/lib/libtime.so
	sudo ln -sv /workspaces/codeforce/src/libalgorithm.so  /usr/lib/liblibalgorithm.so

libtime.so: 
	sh ./Compile.sh
	cp ../library/Timer/libtime.so ./
	cp ../library/Timer/libalgorithm.so ./

clean:
	rm -f main