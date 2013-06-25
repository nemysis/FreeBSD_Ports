# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	arkanoidsb
PORTVERSION=	1.3.2.10
CATEGORIES=	games
MASTER_SITES=	http://www.wegroup.org/downloads/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Arkanoid and space game

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LINUX=	yes

SUB_FILES=	${PORTNAME}.sh

PORTDOCS=	README

OPTIONS_DEFINE=	DOC

DESKTOP_ENTRIES="Arkanoid: Space Ball" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} res ${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
