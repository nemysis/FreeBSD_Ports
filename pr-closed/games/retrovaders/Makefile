# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	retrovaders
PORTVERSION=	1.33
CATEGORIES=	games
MASTER_SITES=	http://homepage.ntlworld.com/danny.offer/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Our take on the old classic Space Invaders

LICENSE=	GPLv2

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	readme.txt

DESKTOP_ENTRIES="RetroVaders" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
