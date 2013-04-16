# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	lxmed
PORTVERSION=	20120515
CATEGORIES=	x11-wm java
MASTER_SITES=	SF/${PORTNAME}/
DIST_SUBDIR=	java

MAINTAINER=	nemysis@gmx.ch
COMMENT=	LXDE Main Menu Editor

LICENSE=	GPLv3

RUN_DEPENDS=	gksu:${PORTSDIR}/sysutils/gksu

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}-root.desktop \
		share/applications/${PORTNAME}.desktop \
		${DATADIR}/LXMenuEditor.jar \
		${DATADIR}/pc-su \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRS=	%%DATADIR%%
PLIST_DIRSTRY=	share/applications

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

SUB_FILES=	${PORTNAME}.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/lxmed/${PORTNAME}.png|${PREFIX}/share/pixmaps/${PORTNAME}.png|' \
		-e 's|Main Menu Editor|${COMMENT}|g' \
		${WRKSRC}/content/${PORTNAME}.desktop
	@(cd ${WRKSRC}/content/ && ${CP} -a ${PORTNAME}.desktop ${PORTNAME}-root.desktop)
	@${REINPLACE_CMD} -e 's|Exec=lxmed|Exec=${DATADIR}/pc-su ${PORTNAME}|' \
		-e 's|${COMMENT}|${COMMENT} (as root)|g' \
		${WRKSRC}/content/${PORTNAME}-root.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}
	${CP} -a ${FILESDIR}/pc-su ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/LXMenuEditor.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/content/${PORTNAME}.png ${PREFIX}/share/pixmaps
	${MKDIR} ${PREFIX}/share/applications
.for i in ${PORTNAME}.desktop ${PORTNAME}-root.desktop
	${INSTALL_DATA} ${WRKSRC}/content/${i} ${PREFIX}/share/applications
.endfor

.include <bsd.port.mk>
