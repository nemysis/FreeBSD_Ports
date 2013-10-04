--- src/bbrun.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/bbrun.c	2013-04-24 12:58:55.000000000 +0200
@@ -26,7 +26,8 @@
 /* for strchrnul */
 #define _GNU_SOURCE
 
-#include <linux/limits.h> /* for PATH_MAX */
+#include <sys/cdefs.h>
+#include <sys/syslimits.h> /* for PATH_MAX */
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
