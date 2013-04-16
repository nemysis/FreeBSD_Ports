# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD: head/games/icebreaker/Makefile 310542 2013-01-17 08:40:07Z mva $

PORTNAME=	icebreaker
PORTVERSION=	1.9.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mattdm.org/icebreaker/1.9.x/ \
		SF/nemysisfreebsdp/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game similar to Jezzball or Barrack

LICENSE=	GPLv2

USE_SDL=	mixer sdl
USE_GMAKE=	yes

PORTDOCS=	ChangeLog README README.SDL README.ifyoumakechanges README.themes TODO

MAN6=		${PORTNAME}.6

DESKTOP_ENTRIES="IceBreaker" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|CC=gcc|CC?=g++|' \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|prefix=/usr/local|prefix=${PREFIX}|' \
	-e 's|mandir=$$(prefix)/share/man|mandir=$$(prefix)/man|' \
	-e 's|highscoredir=/var/local/lib/games|highscoredir=/var/games|' \
	-e 's|CFLAGS=|CFLAGS+=|' \
	-e 's|OPTIMIZE=-O3|OPTIMIZE=|' \
	-e 's|*.ico *.desktop *.man.in|*.ico *.man.in|' \
	-e 's|$$(CC) $$(CFLAGS) $$^ -o icebreaker $$(SDL_LIB)|$$(CC) $$(LDFLAGS) $$(CFLAGS) $$^ -o icebreaker $$(SDL_LIB)|' \
	-e 's|install -s -g games -m 2755 icebreaker $(bindir)|install -g games -m 2755 icebreaker $(bindir)|' \
	-e 's|install -s -m 755 icebreaker $(bindir)|install -m 755 icebreaker $(bindir)|' \
	-e 's|chown -f games:games|chown -f root:games|' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
