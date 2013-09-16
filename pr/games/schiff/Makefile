# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	schiff
PORTVERSION=	16
CATEGORIES=	games
MASTER_SITES=	SF/pygamebook/${PORTNAME:S/s/S/}/${PORTNAME}${PORTVERSION}.py/ \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}${DISTVERSION}.py \
		${PORTNAME}_icons.tar.gz:icons
DIST_SUBDIR=	python
EXTRACT_ONLY=	${PORTNAME}_icons.tar.gz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Steer your ship(s) with the keyboard

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

USE_PYTHON=	yes
NO_BUILD=	yes

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Schiff" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${_DISTDIR}/schiff16.py ${DATADIR}/${PORTNAME}.py

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
