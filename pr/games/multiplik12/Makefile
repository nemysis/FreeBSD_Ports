# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	multiplik12
PORTVERSION=	1.0.0
CATEGORIES=	games java
MASTER_SITES=	http://www.athenasoft.net/multiplik12/ \
		http://www.athenasoft.net/assets/images/multiplik12/:icons
DISTFILES=	${RESTRICTED_FILES} \
		icon48x48.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${RESTRICTED_FILES}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Educational game for learning and practicing the multiplication tables

RESTRICTED=	License does not allow redistribution
RESTRICTED_FILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
INSTALLS_ICONS=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}

DESKTOP_ENTRIES="MultipliK12" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "lib *.jar" ${DATADIR})
	${INSTALL_DATA} ${_DISTDIR}/icon48x48.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
