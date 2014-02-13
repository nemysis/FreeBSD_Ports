--- ./src/plugins/plugins_i18n.py.orig	2014-02-06 00:08:06.000000000 +0100
+++ ./src/plugins/plugins_i18n.py	2014-02-06 00:08:06.000000000 +0100
@@ -29,7 +29,6 @@
 
 if os.name != 'nt':
     locale.setlocale(locale.LC_ALL, '')
-    locale.bindtextdomain(APP, plugins_locale_dir)
     gettext.bindtextdomain(APP, plugins_locale_dir)
     gettext.textdomain(APP)
 
