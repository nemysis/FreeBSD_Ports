--- libavdevice/oss_audio.c.orig	2013-07-06 15:14:38.000000000 +0200
+++ libavdevice/oss_audio.c	2013-08-08 13:46:53.000000000 +0200
@@ -19,6 +19,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char  u_char;
+typedef unsigned short u_short;
+typedef unsigned int   u_int;
+typedef unsigned long  u_long;
+
 #include "config.h"
 #include <stdlib.h>
 #include <stdio.h>
