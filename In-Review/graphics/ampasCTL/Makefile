# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/ampasCTL/Makefile 328197 2013-09-24 21:28:32Z nemysis $

PORTNAME=	ampasCTL
PORTVERSION=	1.5
CATEGORIES=	graphics devel
#DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

LIB_DEPENDS=	libImath.so:${PORTSDIR}/graphics/ilmbase

#WRKSRC=		${WRKDIR}/ampas-CTL-${GH_COMMIT}/Nuke_CTL

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9cb69b8

USES=		cmake pkgconfig
#USES=		cmake pathfix pkgconfig
#PATHFIX_MAKEFILEIN=	 Makefile.am
#GNU_CONFIGURE=	yes
#USE_AUTOTOOLS=	aclocal libtool
USE_LDCONFIG=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS CHANGELOG README.md

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	CtlManual.pdf CtlManual.doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

#pre-configure:
#	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap)

post-patch:
	@${REINPLACE_CMD} -e 's|#include <alloca.h>||' \
		${WRKSRC}/lib/dpx/dpx_util.cc ${WRKSRC}/lib/IlmCtl/CtlExc.cpp \
		${WRKSRC}/lib/IlmCtl/CtlTypeStorage.cpp ${WRKSRC}/ctlrender/tiff_file.cc
#	@${REINPLACE_CMD} -e 's|CtlManual.pdf CtlManual.doc||' \
#		${WRKSRC}/doc/Makefile.am

#test check:	build
#	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

#.if defined(PACKAGE_BUILDING)
#pre-install:	test
#.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
.endif

.include <bsd.port.mk>
