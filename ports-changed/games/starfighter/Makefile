# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD: head/games/starfighter/Makefile 316654 2013-04-27 08:50:46Z mva $

PORTNAME=	starfighter
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/pr-${PORTNAME}/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Liberate the universe from the evil company WEAPCO

LICENSE=	GPLv2

USES=		iconv
USE_XORG=	x11 xau xdmcp
USE_SDL=	image mixer
WITH_ZLIB=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png \
		%%DATADIR%%/${PORTNAME}.pak
PLIST_DIRS=	%%DATADIR%%

PORTDOCS=	*

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Project Starfighter" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's| -O2 -Wall|${CXXFLAGS}|' \
	-e 's|docs/\*|docs/index.html|' \
	-e 's|/usr|${LOCALBASE}|' \
	-e 's|$$(PREFIX)/games/|$$(PREFIX)/bin/|' \
	-e 's|/share/games/parallelrealities/|/share/starfighter/|' \
		${WRKSRC}/makefile

.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|docs/index.html|docs/index.html ChangeLog|' ${WRKSRC}/makefile
.endif

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -i '' -e '/$$(DESTDIR)$$(DOCDIR)/d' ${WRKSRC}/makefile
.endif

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
