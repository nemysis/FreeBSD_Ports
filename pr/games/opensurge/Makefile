# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	opensurge
PORTVERSION=	0.2.0${SVN_REV}
CATEGORIES=	games
MASTER_SITES=	http://www.ime.usp.br/~alemart/opensurge_nightly/
DISTNAME=	${PORTNAME}-src-build${SVN_REV}
DIST_SUBDIR=	opensurge

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game based on the Sonic the Hedgehog universe

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}

SVN_REV=	752

USES=		cmake
USE_OPENAL=	soft
#CMAKE_ENV+=	OPENSNC_ALLEGRO_LIBS="`allegro-config --libs`" OPENSNC_ALLEGRO_VERSION="`allegro-config --version`"

CFLAGS+=	-I${LOCALBASE}/include
#CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/allegro5
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS+=	alfont:${PORTSDIR}/x11-fonts/alfont \
		${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro-devel \
		alpng:${PORTSDIR}/graphics/alpng \
		alureplay:${PORTSDIR}/audio/alure
RUN_DEPENDS+=	${LOCALBASE}/lib/libaldmb.a:${PORTSDIR}/audio/dumb-allegro-devel \
		alpng:${PORTSDIR}/graphics/alpng
LIB_DEPENDS+=	alleg.4:${PORTSDIR}/devel/allegro-devel \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis

DESKTOP_ENTRIES="Open Surge" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -i '' '/FIND_LIBRARY(LDL/,/ENDIF(NOT LDL)/s/^/#/' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|g' \
		${WRKSRC}/src/core/global.h
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/src/misc/${PORTNAME}

.include <bsd.port.post.mk>
