--- libavutil/common.h.orig	2013-07-06 15:14:38.000000000 +0200
+++ libavutil/common.h	2013-08-08 15:10:45.000000000 +0200
@@ -39,6 +39,10 @@
 #include "version.h"
 #include "libavutil/avconfig.h"
 
+#ifndef UINT64_C
+#define UINT64_C(c) (c ## UL)
+#endif
+
 #if AV_HAVE_BIGENDIAN
 #   define AV_NE(be, le) (be)
 #else
