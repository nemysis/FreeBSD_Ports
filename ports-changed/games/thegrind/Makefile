# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/thegrind/Makefile 316343 2013-04-23 10:47:02Z bapt $

PORTNAME=	thegrind
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/radius-engine/ld21/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple game about escaping from work

LICENSE=	GPLv2

LIB_DEPENDS=	radius:${PORTSDIR}/graphics/radius-engine \
		lua-5.1:${PORTSDIR}/lang/lua \
		png15:${PORTSDIR}/graphics/png \
		physfs.1:${PORTSDIR}/devel/physfs
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_SDL=	sdl sound
USE_GL=		glu
USES=		pkgconfig 
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.zip
PLIST_DIRS=	%%DATADIR%%
PLIST_DIRSTRY=	share/applications

PORTDOCS=	ChangeLog

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
