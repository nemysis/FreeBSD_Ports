# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	visualspell
PORTVERSION=	1.0.0
CATEGORIES=	games java
MASTER_SITES=	http://www.athenasoft.net/visualspell/:game \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${RESTRICTED_FILES}:game \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${RESTRICTED_FILES}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Challenges players to use reasoning skills to match a word

RESTRICTED=	License does not allow redistribution
RESTRICTED_FILES=	${PORTNAME}demo-${DISTVERSION}${EXTRACT_SUFX}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
INSTALLS_ICONS=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}demo-${PORTVERSION}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="Visual Spell" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "lib *.jar" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

post-install:

.include <bsd.port.mk>
