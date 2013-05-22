# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	entombed
PORTVERSION=	2007.07.04
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/entombed/ \
		ftp://ftp.billsgames.com/unix/x/entombed/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	One- or two-player maze game based on the Entombed

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	image mixer sdl
USES=		desktop-file-utils

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

DESKTOP_ENTRIES="Entombed" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;ArcadeGame;" false

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.for d in embedded images images_halfsize music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

	${LN} -sf ${WRKSRC}/data/images/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
