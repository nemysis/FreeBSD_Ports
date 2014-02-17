--- ./src/nv-freebsd.h.orig	2014-01-09 03:43:19.000000000 +0100
+++ ./src/nv-freebsd.h	2014-02-17 15:25:46.000000000 +0100
@@ -21,12 +21,6 @@
 
 #include <sys/param.h>
 
-#if __FreeBSD_version >= 1000000
-#error This driver does not support FreeBSD 10.x/-CURRENT!
-#endif
-#if __FreeBSD_version >= 900000 && __FreeBSD_version < 900044
-#error This driver requires FreeBSD 9.0 or later!
-#endif
 #if __FreeBSD_version >= 800000 && __FreeBSD_version < 800107
 #error This driver requires FreeBSD 8.0 or later!
 #endif
@@ -77,6 +71,7 @@
 #include <vm/vm_object.h>
 #include <vm/pmap.h>
 #include <vm/vm_map.h>
+#include <sys/rwlock.h>
 #include <vm/vm_pager.h>
 #include <vm/uma.h>
 
@@ -123,7 +118,7 @@
  * can safely unset this flag.
  */
 
-#define NV_SUPPORT_LINUX_COMPAT
+#undef NV_SUPPORT_LINUX_COMPAT
 
 /*
  * Enable/Disable support for ACPI method (_DOD, _ROM, etc.) invocation
