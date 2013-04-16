# Created by: Richard Neese
# $FreeBSD: head/audio/sphinx3/Makefile 308911 2012-12-14 17:09:21Z eadler $

PORTNAME=	sphinx3
PORTVERSION=	0.8
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxbase:${PORTSDIR}/audio/sphinxbase

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
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		 ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|heap_t h|heap_t* h|' \
		${WRKSRC}/src/libs3decoder/libsearch/vithist.c

.include <bsd.port.mk>
