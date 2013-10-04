--- sphinx/writers/manpage.py.orig	2011-11-01 08:38:44.000000000 +0100
+++ sphinx/writers/manpage.py	2013-06-28 13:27:48.000000000 +0200
@@ -72,6 +72,11 @@
         # since self.append_header() is never called, need to do this here
         self.body.append(MACRO_DEF)
 
+        # Overwrite admonition label translations with our own
+        for label, translation in admonitionlabels.items():
+            self.language.labels[label] = self.deunicode(translation)
+
+
     # overwritten -- added quotes around all .TH arguments
     def header(self):
         tmpl = (".TH \"%(title_upper)s\" \"%(manual_section)s\""
@@ -193,12 +198,6 @@
     def depart_seealso(self, node):
         self.depart_admonition(node)
 
-    # overwritten -- use our own label translations
-    def visit_admonition(self, node, name=None):
-        if name:
-            self.body.append('.IP %s\n' %
-                             self.deunicode(admonitionlabels.get(name, name)))
-
     def visit_productionlist(self, node):
         self.ensure_eol()
         names = []
