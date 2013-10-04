# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/netwalk/Makefile 327730 2013-09-20 17:36:33Z bapt $

PORTNAME=	netwalk
PORTVERSION=	0.4.10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GH \
		GOOGLE_CODE:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		screenshot-0.4.8.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Game where the object is to connect every terminal to the main server

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	blynn
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	b5e0346

USES=		gmake iconv
USE_SDL=	sdl ttf
USE_XORG=	x11 xau xdmcp
ALL_TARGET=

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/netwalk/Vera.ttf \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/netwalk

PORTDOCS=	README

DESKTOP_ENTRIES="NetWalk" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" "false"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
	-e 's|CC = gcc|CC = ${CC}|' \
	-e 's|CFLAGS=-Wall -O2 -fomit-frame-pointer|CFLAGS+= -fomit-frame-pointer|' \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|PREFIX = /usr|PREFIX = ${PREFIX}|' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${_DISTDIR}/screenshot-0.4.8.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
