mkdir build
pushd build
cl /W4 /DBUILD_DLL /c ..\src\utils.c ..\src\num2a.c 
link /DLL /OUT:num2a.dll utils.obj num2a.obj
popd