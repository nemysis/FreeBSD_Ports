# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/tuxfighter/Makefile 310871 2013-01-23 15:00:18Z makc $

PORTNAME=	tuxfighter
PORTVERSION=	54
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	SF/pygamebook/TuxFighter/TuxFighter${PORTVERSION}_source/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	TuxFighter${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Little Asteroids-like Shooter game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}

FETCH_ARGS?=	-Fpr
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	readme_TuxFighter54.txt

INSTALLS_ICONS=	yes
ICON_SIZES=	48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="TuxFighter" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}

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

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
