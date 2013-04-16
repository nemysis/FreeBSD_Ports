# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	cargocarrier
PORTVERSION=	20110917
CATEGORIES=	games python
MASTER_SITES=	http://www.bglz.net/files/python/projects/
DISTNAME=	${PORTNAME:S/c/C/g}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Collect cargo crates and warp to more difficult zones

RUN_DEPENDS=	${PYGAME}

WRKSRC=		${WRKDIR}/${PORTNAME:S/c/C/g}

USE_ZIP=	yes
USE_PYTHON=	yes
INSTALLS_ICONS=	yes
NO_BUILD=	yes

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Cargo Carrier" "${COMMENT} "${PORTNAME}. \
		"${PORTNAME}" "Game;ArcadeGame;" false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py* ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})
	${LN} -sf ${DATADIR}/data/falcon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
