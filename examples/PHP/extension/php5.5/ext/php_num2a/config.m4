PHP_ARG_ENABLE(num2a, whether to enable MyExtension support, [ --enable-num2a   Enable num2a support])

if test "$PHP_NUM2A" = "yes"; then

  LIBOTHERLIB_LIBS=`pkg-config --libs glib-2.0`
  LIBOTHERLIB_INC=`pkg-config --cflags glib-2.0`
  PHP_EVAL_INCLINE($LIBOTHERLIB_INC)
  PHP_EVAL_LIBLINE($LIBOTHERLIB_LIBS)			


  PHP_ADD_LIBRARY(glib-2.0,1,PHP_NUM2A_SHARED_LIBADD)
  PHP_ADD_LIBRARY(num2a,1,PHP_NUM2A_SHARED_LIBADD)
  PHP_ADD_INCLUDE($LIBOTHERLIB_INC)  
  PHP_NEW_EXTENSION(php_num2a, php_num2a.c, $ext_shared)
  PHP_SUBST(PHP_NUM2A_SHARED_LIBADD)
fi
