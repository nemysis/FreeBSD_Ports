--- IlmCtl/CtlInterpreter.cpp.orig	2012-10-19 18:39:14.000000000 +0200
+++ IlmCtl/CtlInterpreter.cpp	2013-10-03 10:48:09.000000000 +0200
@@ -71,6 +71,8 @@
     #include <stdlib.h>
 #endif
 
+# include <unistd.h>
+
 using namespace std;
 using namespace Iex;
 using namespace IlmThread;
