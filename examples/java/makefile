JAVA_PATH=c:\Program Files\Java\jdk1.8.0_111
NUM2A_PATH=w:\c\num2a
linux:
	gcc  -fPIC -I"$(NUM2A_PATH)/src" -I"$(JAVA_PATH)/include" -I"$(JAVA_PATH)/include/linux" -L"$(NUM2A_PATH)/build"  -shared -o libjnum2a.so JavaNum2aExample.c -lnum2a
mingw:
	gcc -Wl,--add-stdcall-alias -I"$(NUM2A_PATH)\src" -I"$(JAVA_PATH)\include" -I"$(JAVA_PATH)\include\win32" -L"$(NUM2A_PATH)\build"  -shared -o jnum2a.dll JavaNum2aExample.c -lnum2a
