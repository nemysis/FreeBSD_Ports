--- aspell/rclaspell.cpp.orig	2012-10-26 10:25:54.000000000 +0200
+++ aspell/rclaspell.cpp	2013-09-21 20:45:01.000000000 +0200
@@ -25,8 +25,6 @@
 #include <dlfcn.h>
 #include <stdlib.h>
 
-using namespace std;
-
 #include ASPELL_INCLUDE
 
 #include "pathut.h"
@@ -36,6 +34,8 @@
 #include "unacpp.h"
 #include "ptmutex.h"
 
+using namespace std;
+
 // Just a place where we keep the Aspell library entry points together
 class AspellApi {
 public:
