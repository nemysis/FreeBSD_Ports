# Created by:	nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	agendaroids
PORTVERSION=	2002.03.07
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/agenda/agendaroids/src/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Vector-based rock-shooting game similar to the Asteroids

LICENSE=	GPLv2

USE_XORG=	x11
USE_GNOME=	desktopfileutils
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDOCS=	CHANGES.txt README.txt TODO.txt

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Agendaroids" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|/usr/include|/usr/local/include|' \
	-e 's|agendaroids.host|agendaroids|g' \
	-e 's|/usr/X11R6/lib|/usr/local/lib|' \
		${WRKSRC}/Makefile

do-build:
	@cd ${WRKSRC} && ${GMAKE} host

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
