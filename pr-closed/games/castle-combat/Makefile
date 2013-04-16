# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	castle-combat
PORTVERSION=	0.8.1
CATEGORIES=	games
#MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MASTER_SITES=	http://cdn.bitbucket.org/karlb/castle-combat/downloads/
DISTNAME=	karlb-castle-combat-dd7f77e56c66

MAINTAINER=	nemysis@gmx.ch
COMMENT=	It is a clone of the old arcade game Rampart

LICENSE=	GPLv2

RUN_DEPENDS=	${PYGAME}

USE_ZIP=	yes
FETCH_ARGS?=	-Fpr
USE_TWISTED=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}  \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/applications

PORTDATA=	*
PORTDOCS=	README TODO

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/${PORTNAME}.py
	@${REINPLACE_CMD} -e 's|'DefaultFancy.ttf'), 20.5)|'DefaultFancy.ttf'), 205)|' \
		${WRKSRC}/src/common.py
	@(cd ${WRKSRC}/src && ${REINPLACE_CMD} -e 's|UInt8|uint8|g' common.py widget.py)
#	@(cd ${WRKSRC}/src && ${REINPLACE_CMD} -e 's|Numeric|numpy|g' ai.py battleplayer.py buildplayer.py \
#		common.py field.py game.py gamephases.py map.py placeplayer.py player.py selectplayer.py widget.py)
#	@(cd ${WRKSRC}/src && ${RM} *.py.bak)
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/castle-combat.py ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.py ${DATADIR}

	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "data src" ${DATADIR})

	${INSTALL_DATA} ${WRKSRC}/data/gfx/castle.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
