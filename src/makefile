main: main.cpp libtime.so
	export LD_LIBRARY_PATH=LD_LIBRARY_PATH:/workspaces/codeforce/src
	g++ -o main.exe main.cpp -L. libtime.so
	sudo rm -f /usr/lib/libtime.so
	sudo ln -sv /workspaces/codeforce/src/libtime.so  /usr/lib/libtime.so
libtime.so: 
	sh ../library/Timer/Compile.sh
	cp ../library/Timer/libtime.so ./
clean:
	rm -f main