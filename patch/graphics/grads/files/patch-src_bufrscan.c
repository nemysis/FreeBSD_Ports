$FreeBSD: head/graphics/grads/files/patch-src_bufrscan.c 300896 2012-07-14 13:54:48Z beat $

--- src/bufrscan.c.orig	2009-01-20 21:16:09.000000000 -0800
+++ src/bufrscan.c	2009-01-20 21:16:20.000000000 -0800
@@ -5,6 +5,7 @@
 
 /* bufrscan.c written by Joe Wielgosz */
 
+#include <sys/types.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
