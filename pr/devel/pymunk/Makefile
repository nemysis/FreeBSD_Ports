# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pymunk
PORTVERSION=	3.0.0
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Easy-to-use pythonic 2d physics library built on Chipmunk-Physics

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}pyglet-devel>=1.2:${PORTSDIR}/graphics/py-pyglet-devel
BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

USE_ZIP=	yes
USE_GL=		yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt THANKS.txt

OPTIONS_DEFINE=		SINGLEHTML PICKLE JSON HTMLHELP QTHELP DEVHELP EPUB LATEXPDF MANPAGES TEXINFO

OPTIONS_DEFAULT=	SINGLEHTML MANPAGES

SINGLEHTML_DESC=	A single large HTML file
PICKLE_DESC=		Make Pickle files
JSON_DESC=		Make JSON files
HTMLHELP_DESC=		HTML files and a HTML help project
QTHELP_DESC=		HTML files and a qthelp project
DEVHELP_DESC=		HTML files and a Devhelp project
EPUB_DESC=		Make an ePub
LATEXPDF_DESC=		LaTeX files and run them through pdflatex
TEXINFO_DESC=		Texinfo files

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=		pymunk.1
.endif

post-install:

.if ${PORT_OPTIONS:MSINGLEHTML}
	@cd ${WRKSRC}/docs/src && make singlehtml
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} singlehtml ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MPICKLE}
	@cd ${WRKSRC}/docs/src && make pickle
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} pickle ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MJSON}
	@cd ${WRKSRC}/docs/src && make json
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} json ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MHTMLHELP}
	@cd ${WRKSRC}/docs/src && make htmlhelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} htmlhelp ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MQTHELP}
	@cd ${WRKSRC}/docs/src && make qthelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} qthelp ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MDEVHELP}
	@cd ${WRKSRC}/docs/src && make devhelp
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} devhelp ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEPUB}
	@cd ${WRKSRC}/docs/src && make epub
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} epub ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MLATEXPDF}
	@cd ${WRKSRC}/docs/src && ${GMAKE} latexpdf
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} latex ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs/src && make man
	${INSTALL_MAN} ${WRKSRC}/docs/src/build/man/pymunk.1 ${MAN1PREFIX}/man/man1
.endif

.if ${PORT_OPTIONS:MTEXINFO}
	@cd ${WRKSRC}/docs/src && make texinfo
	@cd ${WRKSRC}/docs/src/build/texinfo && ${GMAKE}
	@(cd ${WRKSRC}/docs/src/build && ${COPYTREE_SHARE} texinfo ${DOCSDIR})
.endif

	${INSTALL_DATA} ${WRKSRC}/docs/pymunk_logo_googlecode.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
