--- python/lib/lng.py.orig	2013-03-31 23:12:23.000000000 +0200
+++ python/lib/lng.py	2013-04-25 21:15:55.000000000 +0200
@@ -15,13 +15,13 @@
         if(os.environ["DEBIAN_PACKAGE"] == "TRUE"):
             languages = os.listdir('/usr/share/locale')
         else:
-            languages = os.listdir(Variables.playonlinux_env+'/lang/locale')
+            languages = os.listdir('%%PREFIX%%/share/locale')
 
         langid = wx.LANGUAGE_DEFAULT
         if(os.environ["DEBIAN_PACKAGE"] == "TRUE"):
             localedir = "/usr/share/locale"
         else:
-            localedir = os.path.join(Variables.playonlinux_env, "lang/locale")
+            localedir = "%%PREFIX%%/share/locale"
 
         domain = "pol"
         mylocale = wx.Locale(langid)
