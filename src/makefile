main: main.cpp libtime.so
	g++ -o main.exe main.cpp -L. libtime.so
	sudo rm -f /usr/lib/libtime.so # Find 。so while Running 
	sudo ln -sv /workspaces/codeforce/src/libtime.so  /usr/lib/libtime.so
libtime.so: 
	sh ./Compile.sh
	cp ../library/Timer/libtime.so ./
clean:
	rm -f main