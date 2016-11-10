mkdir build
pushd build
cl /W4 /DSTATIC /c ..\src\utils.c ..\src\num2a.c
lib /OUT:num2a.lib utils.obj num2a.obj
popd