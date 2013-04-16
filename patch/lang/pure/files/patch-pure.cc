--- pure.cc.orig	2013-02-14 15:03:12.000000000 +0100
+++ pure.cc	2013-04-05 04:54:33.000000000 +0200
@@ -362,14 +362,14 @@
 
 static char *my_command_input2(const char *prompt)
 {
-#ifdef HAVE_READLINE_HISTORY
+#if 0
   HISTORY_STATE *save_hist = history_get_history_state();
   int histmax = unstifle_history();
   history_set_history_state(my_hist);
   stifle_history(600);
 #endif
   char *s = readline(prompt);
-#ifdef HAVE_READLINE_HISTORY
+#if 0
   if (s && *s) add_history(s);
   free(my_hist);
   my_hist = history_get_history_state();
