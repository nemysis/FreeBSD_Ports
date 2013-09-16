--- libavdevice/bktr.c.orig	2013-07-06 15:14:38.000000000 +0200
+++ libavdevice/bktr.c	2013-08-08 13:32:19.000000000 +0200
@@ -24,6 +24,11 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+typedef unsigned char  u_char;
+typedef unsigned short u_short;
+typedef unsigned int   u_int;
+typedef unsigned long  u_long;
+
 #include "libavformat/avformat.h"
 #include "libavformat/internal.h"
 #include "libavutil/log.h"
