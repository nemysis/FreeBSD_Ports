# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD: head/audio/dumb/Makefile 322840 2013-07-12 15:01:45Z amdmi3 $

PORTNAME=	dumb
PORTVERSION=	0.9.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	IT, XM, S3M, and MOD player library

USES=	gmake

OPTIONS_RADIO=	ALLEGRO
OPTIONS_RADIO_ALLEGRO=	ALLEGRO ALLEGRO_DEVEL

OPTIONS_DEFAULT=	ALLEGRO_DEVEL

OPTIONS_SUB=	yes

ALLEGRO_DESC=	Enable allegro support
ALLEGRO_DEVEL_DESC=	Enable allegro development version

ALLEGRO_LIB_DEPENDS=		alleg:${PORTSDIR}/devel/allegro
ALLEGRO_DEVEL_LIB_DEPENDS=	liballegro.so:${PORTSDIR}/devel/allegro-devel

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALLEGRO}
SET_ALLEGRO=	yes
PKGNAMESUFFIX=	-allegro
CONFLICTS=	dumb-[0-9]*
.else
CONFLICTS=	dumb-allegro-[0-9]*
.endif

.if ${PORT_OPTIONS:MALLEGRO_DEVEL}
SET_ALLEGRO=	yes
PKGNAMESUFFIX=	-allegro-devel
CONFLICTS=	dumb-[0-9]*
.else
CONFLICTS=	dumb-allegro-devel-[0-9]*
.endif

.if defined(SET_ALLEGRO)
MAKE_ARGS+=	_PORT_ALLEGRO_CFLAGS="`allegro-config --cflags`"
.else
MAKE_ARGS+=	_PORT_ALLEGRO_CFLAGS=
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
.endif

post-patch:
	${CP} ${FILESDIR}/config.txt ${WRKSRC}/make
	${REINPLACE_CMD} -e 's|@LOCALBASE@|${PREFIX}|' ${WRKSRC}/make/config.txt

.if defined(SET_ALLEGRO)
	${REINPLACE_CMD} -e 's|@ALLEGRO@ ||' ${WRKSRC}/make/config.txt
.else
	${REINPLACE_CMD} -e 's|@ALLEGRO@ |#|' ${WRKSRC}/make/config.txt
.endif

.include <bsd.port.mk>
