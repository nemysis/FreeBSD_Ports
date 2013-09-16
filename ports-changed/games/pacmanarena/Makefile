# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/pacmanarena/Makefile 303544 2012-09-02 11:37:46Z ak $

PORTNAME=	pacmanarena
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v0.0/ \
		SF/nemysisfreebsdp/${PORTNAME}/ \
		SF/nemysisfreebsdp/${PORTNAME}/:icons
DISTFILES=	${DISTNAME:S/na/n-a/}.tar.bz2 \
		${PORTNAME:S/arena/-data/}-0.0.zip \
		${PORTNAME}_icons.tar.bz2:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Pacman clone in full 3D with a few surprises

LICENSE=	GPLv2

EXTRACT_DEPENDS=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${PORTNAME:S/arena//}

GNU_CONFIGURE=	yes
USE_SDL=	mixer net sdl

PORTDOCS=	README

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

DESKTOP_ENTRIES="Pacman Arena" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|@prefix@|${DATADIR}|' \
	-e 's|@datadir@/pacman|${DATADIR}|' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/arena//} ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC}/../ && ${COPYTREE_SHARE} "gfx sfx" ${DATADIR})

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
