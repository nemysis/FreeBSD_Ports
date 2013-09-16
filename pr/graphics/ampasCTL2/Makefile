# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ampasCTL2
PORTVERSION=	1.4.1
CATEGORIES=	graphics devel
MASTER_SITES=	GH
DISTNAME=	ctl-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Color Transformation Language interpreter

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase2

WRKSRC=		${WRKDIR}/ampas-CTL-${GH_COMMIT}/CTL

USE_GITHUB=	yes
GH_ACCOUNT=	ampas
GH_PROJECT=	CTL
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ca179ca

USES=		pathfix pkgconfig
PATHFIX_MAKEFILEIN=	 Makefile.am
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/ilmbase2
USE_AUTOTOOLS=	aclocal libtool
USE_LDCONFIG=	${PREFIX}/lib/ilmbase2

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	CtlManual.pdf CtlManual.doc

.include <bsd.port.options.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|CTL.pc|CTL2.pc|' \
		${WRKSRC}/configure.ac

	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./bootstrap)

	@${REINPLACE_CMD} -e 's|IlmBase`|IlmBase2`|g' \
		${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's|CTL.pc.in|CTL2.pc.in|' \
		-e 's|CONFIG_CLEAN_FILES = CTL.pc|CONFIG_CLEAN_FILES = CTL2.pc|' \
		${WRKSRC}/Makefile.in

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'Makefile.am'| ${XARGS} \
		${REINPLACE_CMD} -i '' 's|$$(includedir)/CTL|$$(includedir)/CTL2|g'

	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|' \
		-e 's|@exec_prefix@|$${prefix}|' \
		-e 's|@libdir@|$${exec_prefix}/lib/ilmbase2|' \
		-e 's|@includedir@|$${prefix}/include|' \
		-e 's|CTL_includedir|CTL2_includedir|' \
		-e 's|${prefix}/include/CTL|${prefix}/include/CTL2|' \
		-e 's|Name: CTL|Name: CTL2|' \
		-e 's|@CTL_VERSION@|${PORTVERSION}|' \
		${WRKSRC}/CTL.pc.in
	@(cd ${WRKSRC} ; ${CP} -a CTL.pc.in CTL2.pc.in)

	@${REINPLACE_CMD} -e 's|pkgconfig_DATA = CTL.pc|pkgconfig_DATA = CTL2.pc|' \
		${WRKSRC}/Makefile.am

	@${REINPLACE_CMD} -e 's|CtlManual.pdf CtlManual.doc||' \
		${WRKSRC}/doc/Makefile.am

test check:	build
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
