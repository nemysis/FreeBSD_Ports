# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: ports/games/cretan-hubris/Makefile,v 1.3 2012/08/29 02:14:30 avilla Exp $

PORTNAME=	cretan-hubris
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/egp/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Maze on the Isle of Crete

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/License.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/include/radius.h:${PORTSDIR}/graphics/radius-engine
LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
ALL_TARGET=	${PORTNAME}
USE_SDL=	sdl sound
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.zip
PLIST_DIRS=	%%DATADIR%%
PLIST_DIRSTRY=	share/applications

.include <bsd.port.mk>
