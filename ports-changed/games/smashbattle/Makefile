# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD: head/games/smashbattle/Makefile 305698 2012-10-11 05:33:04Z jgh $

PORTNAME=	smashbattle
PORTVERSION=	110224
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/beta-${PORTVERSION}
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	nemysis@gmx.ch
COMMENT=	8-bit style platform battle game

WRKSRC=		${WRKDIR}/${DISTNAME}/battle/Battle

USE_ZIP=	yes
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_DOS2UNIX=	*.cpp *.h *.ini Makefile
ALL_TARGET=	battle
USE_SDL=	sdl image mixer
USE_GNOME=	desktopfileutils
MAKE_JOBS_SAFE=	yes

pre-extract:
	@${MKDIR} ${WRKDIR}/${DISTNAME}

SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/games/smashbattle/gfx/SB.png|${PORTNAME}|' \
		-e 's|/usr/local/bin/smashbattle|${PORTNAME}|' \
		${WRKSRC}/linux/*.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "gfx music sfx stage" ${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/battle ${DATADIR}/${PORTNAME}
	${LN} -sf ${DATADIR}/gfx/SB.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/linux/*.desktop ${PREFIX}/share/applications

post-install:
	@-update-desktop-database -q

.include <bsd.port.mk>
