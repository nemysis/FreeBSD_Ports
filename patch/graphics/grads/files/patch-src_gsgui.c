$FreeBSD: head/graphics/grads/files/patch-src_gsgui.c 300896 2012-07-14 13:54:48Z beat $

--- src/gsgui.c.orig	Fri Mar 25 15:21:29 2005
+++ src/gsgui.c	Fri Mar 25 15:21:42 2005
@@ -28,8 +28,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#include "libsx.h"
-#include "freq.h"
+#include "X11/libsx/libsx.h"
+#include "X11/libsx/freq.h"
 #include "gagui.h"
 
 /* Supported widget types */
