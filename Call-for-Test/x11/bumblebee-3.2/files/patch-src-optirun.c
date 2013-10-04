--- src/optirun.c.orig	2013-04-23 17:29:23.000000000 +0200
+++ src/optirun.c	2013-04-24 15:37:35.000000000 +0200
@@ -457,7 +457,7 @@
   /* Initializing configuration */
   init_config();
   bbconfig_parse_opts(argc, argv, PARSE_STAGE_PRECONF);
-  GKeyFile *bbcfg = bbconfig_parse_conf();
+  __unused GKeyFile *bbcfg = bbconfig_parse_conf();
   if (bbcfg) g_key_file_free(bbcfg);
 
   /* Connect to listening daemon */
