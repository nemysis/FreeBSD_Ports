--- setuptools/command/easy_install.py.orig	2013-02-16 08:07:37.000000000 +0100
+++ setuptools/command/easy_install.py	2013-06-16 17:44:03.000000000 +0200
@@ -704,7 +704,7 @@
             return True
         if not dist.has_metadata('zip-safe'):
             return True
-        return True
+        return False
 
     def maybe_move(self, spec, dist_filename, setup_base):
         dst = os.path.join(self.build_directory, spec.key)
