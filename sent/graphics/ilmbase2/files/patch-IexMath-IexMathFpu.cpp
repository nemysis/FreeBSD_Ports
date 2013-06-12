--- IexMath/IexMathFpu.cpp.orig	2013-03-07 00:18:50.000000000 +0100
+++ IexMath/IexMathFpu.cpp	2013-06-08 00:53:10.000000000 +0200
@@ -53,7 +53,7 @@
 #endif
 
 
-#ifdef HAVE_UCONTEXT_H
+#if defined(HAVE_UCONTEXT_H) && (defined(x86_64) || defined(i386_))
 
 
 #include <ucontext.h>
