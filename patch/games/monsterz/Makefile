# New ports collection makefile for:	monsterz
# Date created:		2005-04-29
# Whom:			thierry@pompo.net
#
# $FreeBSD: ports/games/monsterz/Makefile,v 1.11 2012/06/01 05:19:03 dinoex Exp $
#

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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>=0:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes

PORTDOCS=	AUTHORS README TODO

SCOREDIR=	/var/games

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Monsterz" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ${FALSE}

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${DATADIR}

.  for d in graphics sound
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor

	${INSTALL_DATA} ${WRKSRC}/graphics/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

post-install:
	@(if [ ! -e ${SCOREDIR} ] ; then ${MKDIR} -m 775 ${SCOREDIR} ; fi)
	@(if [ ! -e ${SCOREDIR}/monsterz ] ; then ${TOUCH} ${SCOREDIR}/monsterz && ${CHMOD} g+w ${SCOREDIR}/monsterz ; fi)

.include <bsd.port.mk>
