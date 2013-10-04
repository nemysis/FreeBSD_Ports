--- src/switch/sw_bbswitch.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/switch/sw_bbswitch.c	2013-04-24 15:17:59.000000000 +0200
@@ -85,7 +85,7 @@
  * decision whether bbswitch is usable or not
  * @return 1 if available for use for PM, 0 otherwise
  */
-int bbswitch_is_available(struct switch_info info) {
+int bbswitch_is_available(__unused struct switch_info info) {
   (void) info; /* unused parameter */
 
   /* easy one: if the path is available, bbswitch is usable */
