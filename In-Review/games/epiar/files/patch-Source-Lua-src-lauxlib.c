--- Source/Lua/src/lauxlib.c.orig	2012-10-27 10:18:51.000000000 +0200
+++ Source/Lua/src/lauxlib.c	2013-09-14 20:20:41.000000000 +0200
@@ -575,7 +575,7 @@
     lf.f = fopen(filename, "rb");  /* reopen in binary mode */
     if (lf.f == NULL) return errfile(L, "reopen", fnameindex);
     /* skip eventual `#!...' */
-   while ((c = getc(lf.f)) != EOF && c != LUA_SIGNATURE[0]) ;
+   while ((c = getc(lf.f)) != EOF && c != LUA_SIGNATURE[0])
     lf.extraline = 0;
   }
   ungetc(c, lf.f);
