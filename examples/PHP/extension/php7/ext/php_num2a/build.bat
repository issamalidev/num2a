SET PHP_SOURCE_PATH=c:\php-sdk\phpdev\vc14\x86\php-7.0.12-src
SET GLIB2_INCLUDE_PATH=c:\php-sdk\phpdev\vc14\x86\deps\include\glib-2.0
SET PHP_LIB_PATH=c:\xampp\php\dev\
SET NUM2A_LIB_PATH=C:\Users\issam\Documents\MyCodes\num2a\build
SET WIN_DEP_LIB_PATH=C:\php-sdk\phpdev\vc14\x86\deps\lib\\


mkdir modules
pushd modules
cl /W3 /c /I"%PHP_SOURCE_PATH%\main" /I"%PHP_SOURCE_PATH%\Zend" /I"%PHP_SOURCE_PATH%\TSRM" /I"%PHP_SOURCE_PATH%" /I"%GLIB2_INCLUDE_PATH%" /nologo /WX- /O2 /Oi /Oy- /GL /D WIN32 /D NDEBUG /D _WINDOWS /D _USRDLL  /D MYEXT2_EXPORTS /D ZEND_DEBUG=0 /D ZTS=1 /D ZEND_WIN32 /D PHP_WIN32 /D _WINDLL /D _MBCS /GF /Gm- /EHsc /MT /GS /Gy /fp:precise /Zc:wchar_t /Zc:forScope ../php_num2a.c
link /OUT:php_num2a.dll /INCREMENTAL:NO /NOLOGO /LIBPATH:%PHP_LIB_PATH% /LIBPATH:%NUM2A_LIB_PATH% /LIBPATH:"%WIN_DEP_LIB_PATH%" php7ts.lib num2a.lib "glib-2.0.lib" kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /LTCG /TLBID:1 /DYNAMICBASE /NXCOMPAT /MACHINE:X86 /SAFESEH /DLL php_num2a.obj  
popd
