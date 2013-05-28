# Created by: thierry@pompo.net
# $FreeBSD: ports/games/monsterz/Makefile,v 1.11 2012/06/01 05:19:03 dinoex Exp $

PORTNAME=	monsterz
PORTVERSION=	0.7.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://sam.zoy.org/monsterz/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Monsterz - arcade puzzle game

LICENSE=	WTFPL
LICENSE_NAME=	Do What The [expletive] You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

RUN_DEPENDS=	o${PYGAME}

USE_PYTHON=	yes

PORTDOCS=	AUTHORS README TODO

SCOREDIR=	/var/games

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Monsterz" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

#do-build:
#	@${PYTHON_CMD} -m compileall ${WRKSRC}
#	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}

.  for d in graphics sound
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor

	${LN} -sf ${DATADIR}/graphics/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
