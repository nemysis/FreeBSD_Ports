--- IlmImf/ImfAutoArray.h.orig	2013-04-09 19:08:02.000000000 +0200
+++ IlmImf/ImfAutoArray.h	2013-06-08 18:33:25.000000000 +0200
@@ -47,6 +47,10 @@
 #include "ImfNamespace.h"
 #include <string.h>
 
+#if !defined (HAVE_LARGE_STACK)
+#include <cstring>
+#endif
+
 OPENEXR_IMF_INTERNAL_NAMESPACE_HEADER_ENTER
 
 
@@ -58,7 +62,7 @@
     {
       public:
 
-	 AutoArray (): _data (new T [size]) { memset(_data, 0, size*sizeof(T)); }
+	 AutoArray (): _data (new T [size]) {::std::memset(_data, 0, size * sizeof(T));}
 	~AutoArray () {delete [] _data;}
 
 	operator T * ()			{return _data;}
