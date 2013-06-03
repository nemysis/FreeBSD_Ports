# Created by: Richard Neese
# $FreeBSD: head/audio/sphinx3/Makefile 315807 2013-04-15 19:28:45Z bdrewery $

PORTNAME=	sphinx3
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxbase:${PORTSDIR}/audio/sphinxbase

USES=		pathfix
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=libtool
USE_CSTD=	gnu99
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include #-I${LOCALBASE}/include/sphinxbase
CXXFLAGS+=	-I${LOCALBASE}/include #-I${LOCALBASE}/include/sphinxbase
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|heap_t h|heap_t* h|' \
		${WRKSRC}/src/libs3decoder/libsearch/vithist.c

.include <bsd.port.mk>
