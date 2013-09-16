# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	OpenEXR2
PORTVERSION=	2.0.0
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	openexr-${DISTVERSION}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	High dynamic-range (HDR) image file format

LICENSE=	BSD

LIB_DEPENDS=	Imath:${PORTSDIR}/graphics/ilmbase2

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		pkgconfig
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/${PORTNAME} --disable-ilmbasetest --enable-imfexamples
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS ChangeLog NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.pdf

BIN=		exrenvmap exrheader exrmakepreview exrmaketiled exrmultipart exrmultiview exrstdattr

OPTIONS_DEFINE=		LARGE_STACK
LARGE_STACK_DESC=	Enable sys-dependant large stack optimizations

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLARGE_STACK}
CONFIGURE_ARGS+=--enable-large-stack
.endif

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'Makefile.am'| ${XARGS} \
		${REINPLACE_CMD} -i '' 's|$$(includedir)/OpenEXR|$$(includedir)/${PORTNAME}|g'

	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@/examples|$$(prefix)/share/examples/${PORTNAME}|' \
		${WRKSRC}/IlmImfExamples/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/OpenEXR-@OPENEXR_VERSION@|$$(datadir)/doc/${PORTNAME}|' \
		-e 's|doc_DATA = $$(EXTRA_DIST)|doc_DATA =|' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in

.for e in ${BIN}
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(bindir)|/tmp/${PORTNAME}/bin|' \
		${WRKSRC}/${e}/Makefile.in
.endfor

	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		-e 's|OpenEXR.pc|${PORTNAME}.pc|' \
		-e 's|openexr.m4|openexr2.m4|' \
		${WRKSRC}/Makefile.am
	@(cd ${WRKSRC} ; ${CP} -a openexr.m4 openexr2.m4)

	@${REINPLACE_CMD} -e 's|OpenEXR|${PORTNAME}|g' \
		-e 's|IlmBase|IlmBase2|' \
		${WRKSRC}/OpenEXR.pc.in
	@(cd ${WRKSRC} ; ${CP} -a OpenEXR.pc.in ${PORTNAME}.pc.in)

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|$$(datadir)/doc/${PORTNAME}||' \
		${WRKSRC}/doc/Makefile.am ${WRKSRC}/doc/Makefile.in
.endif

.if ! ${PORT_OPTIONS:MEXAMPLES}
EXTRA_PATCHES+=${FILESDIR}/extra-patch-IlmImfExamples-Makefile.in
.endif

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-install:
	@(${MKDIR} /tmp/${PORTNAME}/bin)
.for e in ${BIN}
	${INSTALL_PROGRAM} /tmp/${PORTNAME}/bin/${e} ${PREFIX}/bin/${e}2
.endfor
	@(${RM} -fr /tmp/${PORTNAME})

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
