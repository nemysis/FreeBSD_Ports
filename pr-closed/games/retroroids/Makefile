# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	retroroids
PORTVERSION=	1.21
CATEGORIES=	games
MASTER_SITES=	http://homepage.ntlworld.com/danny.offer/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}_${PORTVERSION:S/./_/}_linux${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}_${PORTVERSION:S/./_/}_linux${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Another retro arcade classic: Asteroids

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	readme.txt

DESKTOP_ENTRIES="RetroRoids" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/RetroRoids ${PREFIX}/bin/${PORTNAME}

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
