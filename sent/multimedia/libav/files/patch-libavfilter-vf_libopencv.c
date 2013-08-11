--- libavfilter/vf_libopencv.c.orig	2013-07-06 15:14:38.000000000 +0200
+++ libavfilter/vf_libopencv.c	2013-08-08 14:04:32.000000000 +0200
@@ -25,8 +25,7 @@
 
 /* #define DEBUG */
 
-#include <opencv/cv.h>
-#include <opencv/cxcore.h>
+#include <opencv2/imgproc/imgproc_c.h>
 #include "libavutil/avstring.h"
 #include "libavutil/common.h"
 #include "libavutil/file.h"
