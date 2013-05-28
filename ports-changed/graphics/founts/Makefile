# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/graphics/founts/Makefile 303114 2012-08-25 06:08:48Z jgh $

PORTNAME=	founts
PORTVERSION=	12
PORTREVISION=	1
CATEGORIES=	graphics games
MASTER_SITES=	http://www.linuxmotors.com/founts/downloads/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.tgz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Demo/program inspired by Erics cascade

LICENSE=	GPLv2

USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	Changelog README

DESKTOP_ENTRIES="Founts" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;Game;" false

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-lm `${SDL_CONFIG} --cflags --libs` ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
