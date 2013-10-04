--- src/bbconfig.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/bbconfig.c	2013-04-24 15:12:10.000000000 +0200
@@ -488,7 +488,7 @@
  * @param argv Argument values
  * @param runmode The running mode of the program
  */
-void init_early_config(char **argv, int runmode) {
+void init_early_config(__unused int argc, char **argv, int runmode) {
   /* clear existing configuration and reset pointers */
   memset(&bb_status, 0, sizeof bb_status);
   set_string_value(&bb_status.errors, ""); //we start without errors, yay!
@@ -505,7 +505,7 @@
 /**
  * Parse configuration file and command line arguments
  */
-void init_config(void) {
+void init_config(__unused int argc, __unused char **argv) {
   /* clear pointers and settings */
   memset(&bb_config, 0, sizeof bb_config);
   /* set defaults if not set already */
