# Created by: nork@FreeBSD.org
# $FreeBSD: head/graphics/OpenEXR/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	OpenEXR
PORTVERSION=	1.7.1
CATEGORIES=	graphics devel
MASTER_SITES=	http://cloud.github.com/downloads/openexr/openexr/
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		pathfix pkgconfig
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--enable-imfexamples

# must be explicitely linked with -l{thr|pthread}
LDFLAGS+=	${PTHREAD_LIBS}

DOCSDIR=	${PREFIX}/share/doc/OpenEXR-${PORTVERSION}
EXAMPLESDIR=	${PREFIX}/share/examples/OpenEXR-${PORTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=		LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependant large stack optimizations

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLARGE_STACK}
CONFIGURE_ARGS+=--enable-large-stack
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|examplesdir = $$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@/examples|examplesdir = $$(prefix)/share/examples/OpenEXR-@OPENEXR_VERSION@|' \
		${WRKSRC}/IlmImfExamples/Makefile.in

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' '/EXTRA_DIST =/,/MultiViewOpenEXR.pdf/s/^/#/' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|install-data-am: install-docDATA|install-data-am: |' \
		${WRKSRC}/doc/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' '/imfexamples_SOURCES =/,/lowLevelIoExamples.h previewImageExamples.h/s/^/#/' \
		${WRKSRC}/IlmImfExamples/Makefile.in
	@${REINPLACE_CMD} -e 's|install-data-am: install-examplesDATA|install-data-am: |' \
		${WRKSRC}/IlmImfExamples/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
.endif

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
