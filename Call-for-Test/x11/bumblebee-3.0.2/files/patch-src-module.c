--- src/module.c.orig	2012-09-06 17:54:25.000000000 +0200
+++ src/module.c	2013-04-24 22:09:28.000000000 +0200
@@ -71,7 +71,7 @@
     /* the module has not loaded yet, try to load it */
     bb_log(LOG_INFO, "Loading driver %s (module %s)\n", driver, module_name);
     char *mod_argv[] = {
-      "modprobe",
+      "kldload",
       module_name,
       NULL
     };
@@ -95,7 +95,7 @@
   if (module_is_loaded(driver) == 1) {
     bb_log(LOG_INFO, "Unloading %s driver\n", driver);
     char *mod_argv[] = {
-      "rmmod",
+      "kldunload",
       "--wait",
       driver,
       NULL
@@ -117,10 +117,10 @@
  */
 int module_is_available(char *module_name) {
   /* HACK to support call from optirun */
-  char *modinfo_bin = "/sbin/modinfo";
+  char *modinfo_bin = "/sbin/kldstat";
   if (access(modinfo_bin, X_OK)) {
-    /* if /sbin/modinfo is not found, pray that PATH contains it*/
-    modinfo_bin = "modinfo";
+    /* if /sbin/kldstat is not found, pray that PATH contains it*/
+    modinfo_bin = "kldstat";
   }
   char *mod_argv[] = {
     modinfo_bin,
