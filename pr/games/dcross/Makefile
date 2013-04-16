# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	dcross
PORTVERSION=	2.7
CATEGORIES=	games python
MASTER_SITES=	GOOGLE_CODE \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Blocks fall from the top and fly in from the side settling in a area

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
PROJECTHOST=	double-cross

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Double Cross" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR})

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
