# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD: head/multimedia/gavl/Makefile 315474 2013-03-28 15:51:16Z eadler $

PORTNAME=	gavl
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for handling uncompressed video and audio data

LICENSE=	GPLv3

USES=		pathfix
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen

PORTDOCS=	README

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS PNG
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS PNG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-libpng
.endif

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} \
	-e 's|-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math||g' \
		${WRKSRC}/configure
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
