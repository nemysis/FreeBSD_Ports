# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	ilmbase2
PORTVERSION=	2.0.0
CATEGORIES=	graphics devel
MASTER_SITES=	SAVANNAH/openexr/
DISTNAME=	ilmbase-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath, and Iex

LICENSE=	BSD

CONFLICTS=	OpenEXR-1.[0-4].*

USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/${PORTNAME}
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		THREAD
OPTIONS_DEFAULT=	THREAD
THREAD_DESC=		Enable multithreaded file I/O support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTHREAD}
CONFIGURE_ARGS+=--enable-threading
CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
.else
CONFIGURE_ARGS+=--disable-threading
.endif

PLIST_SUB=	MAJORVER=2_0

regression-test regression test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

post-patch:
	@${FIND} ${WRKSRC} -name 'Makefile.in' -or -name 'Makefile.am'| ${XARGS} \
		${REINPLACE_CMD} -i '' 's|$$(includedir)/OpenEXR|$$(includedir)/OpenEXR2|g'

	@${REINPLACE_CMD} -e 's|@prefix@|${PREFIX}|' \
		-e 's|@exec_prefix@|$${prefix}|' \
		-e 's|@libdir@|$${exec_prefix}/lib/${PORTNAME}|' \
		-e 's|@includedir@|$${prefix}/include|' \
		-e 's|$${prefix}/include/OpenEXR|$${prefix}/include/OpenEXR2|' \
		-e 's|Name: IlmBase|Name: IlmBase2|' \
		-e 's|@ILMBASE_VERSION@|${PORTVERSION}|' \
		-e 's| @PTHREAD_LIBS@||' \
		-e 's| @PTHREAD_CFLAGS@||' \
		${WRKSRC}/IlmBase.pc.in
	@(cd ${WRKSRC} ; ${CP} -a IlmBase.pc.in IlmBase2.pc)

	@${REINPLACE_CMD} -e 's|pkgconfig_DATA = IlmBase.pc|pkgconfig_DATA = IlmBase2.pc|' \
		${WRKSRC}/Makefile.am

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
