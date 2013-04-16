# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	popstar
PORTVERSION=	0.0.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/popstar/ \
		ftp://ftp.billsgames.com/unix/x/popstar/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simple puzzle game involving floating stars

LICENSE=	GPLv2 CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE_CCbyNCSA3=${WRKSRC}/docs/COPYING-CC-Attrib30.txt
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

USE_GMAKE=	yes
USE_SDL=	image mixer sdl
USE_GNOME=	desktopfileutils

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

INSTALLS_ICONS=	yes

DESKTOP_ENTRIES="Pop Star" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images music sounds" ${DATADIR})
	${LN} -sf ${WRKSRC}/data/images/title.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
