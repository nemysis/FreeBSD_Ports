# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD: head/misc/explosions/Makefile 300896 2012-07-14 13:54:48Z beat $

PORTNAME=	explosions
PORTVERSION=	0.2005.07.31
PORTREVISION=	13
CATEGORIES=	misc games graphics
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/explosions/ \
		ftp://ftp.billsgames.com/unix/x/explosions/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION:S/^0.//}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION:S/^0.//}${EXTRACT_SUFX}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	3D objects flying around resembling explosions with various effects

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/^0.//}

USE_SDL=	sdl image
USE_GMAKE=	yes

PORTDOCS=	BUGS.txt CHANGES.txt README.txt

DESKTOP_ENTRIES="Explosions" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Application;Game;Graphics;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|CFLAGS=-Wall -O2|CFLAGS=-Wall|' \
	-e 's|sdl-config|${SDL_CONFIG}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|spark%d.png|${DATADIR}/spark%d.png|' \
		${WRKSRC}/explosions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.png ${DATADIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
