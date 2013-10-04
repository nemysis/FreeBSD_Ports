# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pymunk
PORTVERSION=	4.0.0
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Easy-to-use pythonic 2d physics library built on Chipmunk-Physics

LICENSE=	MIT

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${LOCALBASE}/lib/libchipmunk.so:${PORTSDIR}/devel/ChipmunkPhysics \
		${PYTHON_PKGNAMEPREFIX}pyglet>=0:${PORTSDIR}/graphics/py-pyglet

USE_ZIP=	yes
USE_GL=		yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt THANKS.txt

OPTIONS_DEFINE=		DEVHELP DOCS EPUB EXAMPLES HTMLHELP JSON LATEXPDF PICKLE \
			QTHELP SINGLEHTML TEXINFO

OPTIONS_DEFAULT=	SINGLEHTML

DEVHELP_DESC=		HTML files via Devhelp project
EPUB_DESC=		Pub
HTMLHELP_DESC=		HTML files via HTML help project
JSON_DESC=		JSON files
LATEXPDF_DESC=		LaTeX files via through pdflatex
PICKLE_DESC=		Pickle files
QTHELP_DESC=		HTML files via QT help project
SINGLEHTML_DESC=	Single large HTML file
TEXINFO_DESC=		Texinfo files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLATEXPDF}
USES=		gmake
.endif

post-patch:
#	@${REINPLACE_CMD} -e '/libchipmunk.so/,/libchipmunk64.so/ d' \
#		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|, 'FreeBSD'||" \
		${WRKSRC}/pymunk/libload.py
#		-e "s|'Darwin'|('Darwin', 'FreeBSD')|" \
#		-e 's|pymunk/libchipmunk64.so,||' \

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/pymunk_logo_googlecode.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@cd ${WRKSRC}/docs/src && ${MAKE} man
	${INSTALL_MAN} ${WRKSRC}/docs/src/build/man/pymunk.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}

	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.if ${PORT_OPTIONS:MDEVHELP}
	@cd ${WRKSRC}/docs/src && ${MAKE} devhelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} devhelp ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEPUB}
	@cd ${WRKSRC}/docs/src && ${MAKE} epub
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} epub ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MHTMLHELP}
	@cd ${WRKSRC}/docs/src && ${MAKE} htmlhelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} htmlhelp ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MJSON}
	@cd ${WRKSRC}/docs/src && ${MAKE} json
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} json ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MLATEXPDF}
	@cd ${WRKSRC}/docs/src && ${GMAKE} latexpdf
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} latex ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MPICKLE}
	@cd ${WRKSRC}/docs/src && ${MAKE} pickle
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} pickle ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MQTHELP}
	@cd ${WRKSRC}/docs/src && ${MAKE} qthelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} qthelp ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MSINGLEHTML}
	@cd ${WRKSRC}/docs/src && ${MAKE} singlehtml
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} singlehtml ${STAGEDIR}${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MTEXINFO}
	@cd ${WRKSRC}/docs/src && ${MAKE} texinfo
	@cd ${WRKSRC}/docs/src/build/texinfo && ${GMAKE}
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} texinfo ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
