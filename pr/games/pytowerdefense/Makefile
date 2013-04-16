# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	pytowerdefense
PORTVERSION=	0.5
CATEGORIES=	games python
MASTER_SITES=	SF/${PORTNAME}/PyTowerDefense0.5/Source%20%28Python%202.5%20or%202.6%20and%20Pygame%29/
DISTNAME=	${PORTNAME}${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Tower Defense Game

LICENSE=	GPLv3

RUN_DEPENDS=	${PYGAME}

USE_ZIP=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

PORTDOCS=	README modding.txt

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="PyTowerDefense" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "audio images" ${DATADIR})
	${LN} -sf ${DATADIR}/images/tower_square.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
